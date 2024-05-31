import 'dart:ffi' as ffi;
import 'dart:io';

import 'package:ffi/ffi.dart';

import '../bindings/pdfium.dart';
import '../utils/lazy.dart';

Pdfium initLibrary() {
  final lookup = switch (Platform.operatingSystem) {
    'windows' => ffi.DynamicLibrary.open('pdfium.dll').lookup,
    'ios' || 'macos' => ffi.DynamicLibrary.process().lookup,
    'android' => ffi.DynamicLibrary.open('libpdfium.so').lookup,
    _ => throw Exception(
        'Platform ${Platform.operatingSystem} is not yet supported.'),
  };

  final lib = Pdfium.fromLookup(lookup);

  final configPointer = malloc<FPDF_LIBRARY_CONFIG>();
  configPointer.ref.version = 2;
  configPointer.ref.m_pUserFontPaths = ffi.nullptr;
  configPointer.ref.m_pIsolate = ffi.nullptr;
  configPointer.ref.m_v8EmbedderSlot = 0;

  lib.InitLibraryWithConfig(configPointer);

  malloc.free(configPointer);

  return lib;

  // if (Platform.isLinux) {
  //   library = ffi.DynamicLibrary.open('libpdfium.so');
  //   return PDFiumLibrary._(library.lookup);
  // }
}

void disposeLibrary(Pdfium fpdf) {
  fpdf.DestroyLibrary();
}

const pdfium = Lazy(initLibrary, disposeLibrary);
