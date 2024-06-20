# Flutter PDFium Bindings

This project is a Flutter plugin that provides bindings for the [PDFium](https://pdfium.googlesource.com/pdfium/) library. PDFium is an open-source PDF rendering engine that is used by the Chromium web browser. This FFI plugin delivers the native bindings for the library to Flutter and enables dynamic loading of the library for each platform. Further, the lib is not included in the package, but downloaded during the build process.

> Note: MacOS and iOS will download the library files upon `pod install`, while the other platforms will download the respective libraries during the build process with `cmake`.

All public functions of the PDFium headers are remapped in this library. This allows the library to only bind the required structs and elements that are really needed by the library.

## Usage

First of all, you need to install the package in your flutter project: `flutter pub add flutter_pdfium`. After that, you can use the library in your project. The binary will be
downloaded during the build process (can be reviewed in the respective CMakeList.txt or podspec files).

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

## Development

To clone and build this repository (and the example that it contains), the headers and sources must be generated locally. For the deployed package, the headers are already generated and included in the package (during the github actions step).

You need the following tools:

- clang
- [just](https://just.systems)
- python 3 (at least 3.12)
- curl

When the repository is cloned, you can just run `just configure`. This will download the PDFium version, creates the AST for the bindings and then generates the respective headers that are required. Then, FFIGEN will run to generate the dart bindings. After this step is done, you can run the example project with `flutter run`. As with the deployed package, the effective library will be downloaded during the build process.
