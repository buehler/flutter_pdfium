import 'dart:ffi' as ffi;
import 'dart:typed_data';

import 'package:ffi/ffi.dart';

import 'bindings/fpdf.dart';
import 'errors.dart';
import 'native_lib.dart';
import 'page.dart';
import 'utils/lazy.dart';

final class Document {
  final FPDF_DOCUMENT _pointer;
  final List<Lazy<Page>> _pages;

  Document._(this._pointer)
      : _pages = List.generate(
          fpdf().GetPageCount(_pointer),
          (index) => Lazy(() => loadPage(_pointer, index), closePage),
          growable: false,
        );

  int get pageCount => _pages.length;

  Page operator [](int index) => _pages[index]();

  Iterator<Page> get pages => _pages.map((lazy) => lazy()).iterator;

  void _dispose() {
    for (final page in _pages) {
      page.dispose();
    }
  }
}

/// Load a (pdf) document from memory [data] with an optional [password].
/// Note that documents MUST BE CLOSED with [closeDocument] when they are
/// no longer needed to prevent memory leaks.
Document loadDocument(Uint8List data, [String? password]) {
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

/// Close the [document] and free all resources.
void closeDocument(Document document) {
  document._dispose();
  fpdf().CloseDocument(document._pointer);
}
