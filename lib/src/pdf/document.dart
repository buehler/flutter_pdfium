import 'dart:async';
import 'dart:ffi' as ffi;
import 'dart:typed_data';

import 'package:ffi/ffi.dart';
import 'package:flutter_pdfium/src/pdf/pdf_worker.dart';

import '../bindings/pdfium.dart';
import '../utils/lazy.dart';
import 'errors.dart';
import 'native_lib.dart';
import 'page.dart';

final class Document {
  final FPDF_DOCUMENT _pointer;
  final List<AsyncLazy<Page>> _pages;

  Document._(this._pointer)
      : _pages = List.generate(
          pdfium().GetPageCount(_pointer),
          (index) => AsyncLazy(() => loadPage(_pointer, index), closePage),
          growable: false,
        );

  /// Load a (pdf) document from memory [data] with an optional [password].
  /// Note that documents MUST BE CLOSED with [close] when they are
  /// no longer needed to prevent memory leaks.
  static Future<Document> fromMemory(Uint8List data, [String? password]) =>
      pdfWorker.compute(() {
        final dataPointer = malloc<ffi.Uint8>(data.length);
        for (var i = 0; i < data.length; i++) {
          dataPointer[i] = data[i];
        }

        final voidPointer = dataPointer.cast<ffi.Void>();

        final document = pdfium().LoadMemDocument(voidPointer, data.length,
            (password ?? '').toNativeUtf8().cast<ffi.Char>());
        if (document == ffi.nullptr) {
          throw getLastLibraryError();
        }

        return Document._(document);
      });

  /// Load a (pdf) document from a file [path] with an optional [password].
  /// Note that documents MUST BE CLOSED with [close] when they are
  /// no longer needed to prevent memory leaks.
  static Future<Document> fromPath(String path, [String? password]) =>
      pdfWorker.compute(() {
        final document = pdfium().LoadDocument(
          path.toNativeUtf8().cast<ffi.Char>(),
          (password ?? '').toNativeUtf8().cast<ffi.Char>(),
        );
        if (document == ffi.nullptr) {
          throw getLastLibraryError();
        }

        return Document._(document);
      });

  int get pageCount => _pages.length;

  Future<Page> operator [](int index) async => _pages[index]();

  Stream<Page> get pages async* {
    for (final page in _pages) {
      yield await page();
    }
  }

  Stream<Bookmark> get bookmarks async* {
    Stream<(FPDF_BOOKMARK, int level)> iterateChildren(
        FPDF_BOOKMARK anchor, int level) async* {
      var child = await pdfWorker
          .compute(() => pdfium().Bookmark_GetFirstChild(_pointer, anchor));
      while (child != ffi.nullptr) {
        yield (child, level);
        yield* iterateChildren(child, level + 1);

        child = await pdfWorker
            .compute(() => pdfium().Bookmark_GetNextSibling(_pointer, child));
      }
    }

    await for (final (bookmarkPointer, level)
        in iterateChildren(ffi.nullptr, 0)) {
      yield await pdfWorker.compute(() {
        final titleLength =
            pdfium().Bookmark_GetTitle(bookmarkPointer, ffi.nullptr, 0);
        final dataBuffer = malloc<ffi.Uint16>(titleLength);
        pdfium().Bookmark_GetTitle(
            bookmarkPointer, dataBuffer.cast<ffi.Void>(), titleLength);
        final title = dataBuffer.cast<Utf16>().toDartString();
        malloc.free(dataBuffer);

        final dest = pdfium().Bookmark_GetDest(_pointer, bookmarkPointer);

        return Bookmark._(
          title: title,
          pageIndex: pdfium().Dest_GetDestPageIndex(_pointer, dest),
          depth: level,
        );
      });

      // () get pos {
      //   final dest = fpdf().BookmarkGetDest(_document, _bookmark);
      //   fpdf().DestinationGetLocationInPage(dest, hasXVal, hasYVal, hasZoomVal, x, y, zoom)
      // }
    }
  }

  // vertical page offset?
  double pageOffset(int index) => 0;
  // take(index + 1).fold<double>(0, (a, b) => a + b.size.height);

  /// Close the document and release all resources.
  void close() {
    for (final page in _pages) {
      page.dispose();
    }
    pdfium().CloseDocument(_pointer);
  }

  @override
  String toString() => 'Document{pageCount: $pageCount}';
}

final class Bookmark {
  final String title;
  final int pageIndex;
  final int depth;

  const Bookmark._({
    required this.title,
    required this.pageIndex,
    required this.depth,
  });
}
