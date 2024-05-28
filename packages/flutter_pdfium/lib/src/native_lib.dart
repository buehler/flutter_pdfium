import 'dart:ffi' as ffi;
import 'dart:io';

import 'package:ffi/ffi.dart';

import 'bindings/fpdf.dart';
import 'utils/lazy.dart';

FPDF initLibrary() {
  final lookup = switch (Platform.operatingSystem) {
    'windows' => ffi.DynamicLibrary.open('pdfium.dll').lookup,
    'ios' => ffi.DynamicLibrary.process().lookup,
    // 'ios' => ffi.DynamicLibrary.open('pdfium').lookup,
    _ => throw Exception(
        'Platform ${Platform.operatingSystem} is not yet supported.'),
  };

  final fpdf = FPDF.fromLookup(lookup);

  final configPointer = malloc<FPDF_LIBRARY_CONFIG>();
  configPointer.ref.version = 2;
  configPointer.ref.m_pUserFontPaths = ffi.nullptr;
  configPointer.ref.m_pIsolate = ffi.nullptr;
  configPointer.ref.m_v8EmbedderSlot = 0;

  fpdf.InitLibraryWithConfig(configPointer);

  malloc.free(configPointer);

  return fpdf;

  // if (Platform.isAndroid) {
  //   lookup = ffi.DynamicLibrary.open('libpdfium.cr.so');
  //   return FPDF.fromLookup(library.lookup);
  // }

  // if (Platform.isWindows) {
  //   library = ffi.DynamicLibrary.open('pdfium.dll');
  //   return PDFiumLibrary._(library.lookup);
  // }

  // if (Platform.isLinux) {
  //   library = ffi.DynamicLibrary.open('libpdfium.so');
  //   return PDFiumLibrary._(library.lookup);
  // }

  // if (Platform.isIOS) {
  //   library = ffi.DynamicLibrary.process();
  //   ffi.Pointer<T> load<T extends ffi.NativeType>(String symbolName) =>
  //       library!.lookup('IOS_$symbolName');
  //   return PDFiumLibrary._(load);
  // }

  // if (Platform.isMacOS) {
  //   library = ffi.DynamicLibrary.process();
  //   ffi.Pointer<T> load<T extends ffi.NativeType>(String symbolName) =>
  //       library!.lookup('MACOS_$symbolName');
  //   return PDFiumLibrary._(load);
  // }
}

void disposeLibrary(FPDF fpdf) {
  fpdf.DestroyLibrary();
}

const fpdf = Lazy(initLibrary, disposeLibrary);
