import 'dart:ffi' as ffi;
import 'dart:typed_data';

import 'package:ffi/ffi.dart';

import 'bindings/fpdf.dart';
import 'errors.dart';
import 'native_lib.dart';
import 'page.dart';
import 'utils/lazy.dart';

final class Document with Iterable<Page> {
  final FPDF_DOCUMENT _pointer;
  final List<Lazy<Page>> _pages;

  Document._(this._pointer)
      : _pages = List.generate(
          fpdf().GetPageCount(_pointer),
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

    final document = fpdf().LoadMemDocument(voidPointer, data.length,
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
    final document = fpdf().LoadDocument(
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

  /// Close the document and release all resources.
  void close() {
    for (final page in _pages) {
      page.dispose();
    }
    fpdf().CloseDocument(_pointer);
  }

  @override
  String toString() => 'Document{pageCount: $pageCount}';
}
