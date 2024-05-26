import 'dart:ffi' as ffi;
import 'dart:io';

import 'package:ffi/ffi.dart';

import 'src/pdfium.dart';

export 'src/pdfium.dart';

/// Create a new instance of the Pdfium library and initialize it.
/// Be aware that this native library MUST BE DESTROYED when it is no longer needed.
/// Otherwise, you will create memory leaks.
Pdfium createInitializedLibrary() {
  final lookup = switch (Platform.operatingSystem) {
    'windows' => ffi.DynamicLibrary.open('flutter_pdfium.dll').lookup,
    'ios' || 'macos' => ffi.DynamicLibrary.process().lookup,
    'android' => ffi.DynamicLibrary.open('libflutter_pdfium.so').lookup,
    _ => throw Exception(
        'Platform ${Platform.operatingSystem} is not yet supported.'),
  };

  final lib = Pdfium.fromLookup(lookup);

  using((arena) {
    final configPointer = arena<FPDF_LIBRARY_CONFIG>();
    configPointer.ref.version = 2;
    configPointer.ref.m_pUserFontPaths = ffi.nullptr;
    configPointer.ref.m_pIsolate = ffi.nullptr;
    configPointer.ref.m_v8EmbedderSlot = 0;
    lib.InitLibraryWithConfig(configPointer);
  }, malloc);

  return lib;
}
