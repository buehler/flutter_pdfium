import 'dart:ffi' as ffi;
import 'dart:typed_data';

import 'package:ffi/ffi.dart';

import '../bindings/pdfium.dart';
import '../utils/lazy.dart';
import 'errors.dart';
import 'native_lib.dart';
import 'page.dart';

final class Document with Iterable<Page> {
  final FPDF_DOCUMENT _pointer;
  final List<Lazy<Page>> _pages;

  Document._(this._pointer)
      : _pages = List.generate(
          pdfium().GetPageCount(_pointer),
          (index) => Lazy(() => loadPage(_pointer, index), closePage),
          growable: false,
        );

  /// Load a (pdf) document from memory [data] with an optional [password].
  /// Note that documents MUST BE CLOSED with [close] when they are
  /// no longer needed to prevent memory leaks.
  factory Document.fromMemory(Uint8List data, [String? password]) {
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
  }

  /// Load a (pdf) document from a file [path] with an optional [password].
  /// Note that documents MUST BE CLOSED with [close] when they are
  /// no longer needed to prevent memory leaks.
  factory Document.fromPath(String path, [String? password]) {
    final document = pdfium().LoadDocument(
      path.toNativeUtf8().cast<ffi.Char>(),
      (password ?? '').toNativeUtf8().cast<ffi.Char>(),
    );
    if (document == ffi.nullptr) {
      throw getLastLibraryError();
    }

    return Document._(document);
  }

  int get pageCount => _pages.length;

  Page operator [](int index) => _pages[index]();

  @override
  Iterator<Page> get iterator => _pages.map((lazy) => lazy()).iterator;

  Iterable<Bookmark> get bookmarks sync* {
    Iterable<(FPDF_BOOKMARK, int)> iterateChildren(
        FPDF_BOOKMARK anchor, int level) sync* {
      var child = pdfium().Bookmark_GetFirstChild(_pointer, anchor);
      while (child != ffi.nullptr) {
        yield (child, level);
        yield* iterateChildren(child, level + 1);

        child = pdfium().Bookmark_GetNextSibling(_pointer, child);
      }
    }

    yield* iterateChildren(ffi.nullptr, 0)
        .map((b) => Bookmark._(_pointer, b.$1, b.$2));
  }

  // vertical page offset?
  double pageOffset(int index) =>
      take(index + 1).fold<double>(0, (a, b) => a + b.size.height);

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
  final FPDF_DOCUMENT _document;
  final FPDF_BOOKMARK _bookmark;

  final int depth;

  const Bookmark._(this._document, this._bookmark, this.depth);

  String get title {
    final titleLength = pdfium().Bookmark_GetTitle(_bookmark, ffi.nullptr, 0);
    final dataBuffer = malloc<ffi.Uint16>(titleLength);
    pdfium()
        .Bookmark_GetTitle(_bookmark, dataBuffer.cast<ffi.Void>(), titleLength);
    final title = dataBuffer.cast<Utf16>().toDartString();
    malloc.free(dataBuffer);

    return title;
  }

  int get pageIndex {
    final dest = pdfium().Bookmark_GetDest(_document, _bookmark);
    if (dest == ffi.nullptr) {
      return -1;
    }

    return pdfium().Dest_GetDestPageIndex(_document, dest);
  }

  // () get pos {
  //   final dest = fpdf().BookmarkGetDest(_document, _bookmark);
  //   fpdf().DestinationGetLocationInPage(dest, hasXVal, hasYVal, hasZoomVal, x, y, zoom)
  // }
}
