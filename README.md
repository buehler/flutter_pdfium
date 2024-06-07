# Flutter PDFium Bindings

This project is a Flutter plugin that provides bindings for the [PDFium](https://pdfium.googlesource.com/pdfium/) library. PDFium is an open-source PDF rendering engine that is used by the Chromium web browser. This FFI plugin delivers the native bindings for the library to Flutter and enables dynamic loading of the library for each platform. Further, the lib is not included in the package, but downloaded during the build process.

> Note: MacOS and iOS will download the library files upon `pod install`, while the other platforms will download the respective libraries during the build process with `cmake`.

All public functions of the PDFium headers are remapped in this library. This allows the library to only bind the required structs and elements that are really needed by the library.

## Usage

To use the library, either use the `Pdfium` class directly (if you want to load the lib by yourself), or use the provided `createInitializedLibrary()` function, that determines the correct libname for the platform and loads the respective library. The library is then initialized and ready to use.

Please note that the library must be disposed after usage to free the resources.

```dart
import 'dart:ffi' as ffi;

import 'package:flutter_pdfium/flutter_pdfium.dart';

final pdfium = createInitializedLibrary();

final doc = pdfium.LoadDocument(
    'file_path'.toNativeUtf8().cast<ffi.Char>(),
    'password'.toNativeUtf8().cast<ffi.Char>(),
)

if (doc == ffi.nullptr) {
    print('Failed to load document');
    return;
}

final pageCount = pdfium.GetPageCount(doc);

pdfium.CloseDocument(doc);
pdfium.DestroyLibrary();
```
