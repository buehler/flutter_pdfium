import 'dart:ffi' as ffi;

import 'package:ffi/ffi.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_pdfium/flutter_pdfium.dart';

void main() async {
  runApp(const ExampleApp());
}

class ExampleApp extends StatelessWidget {
  const ExampleApp({super.key});

  @override
  Widget build(BuildContext context) => MaterialApp(
        title: 'PDFium Example',
        theme: ThemeData(
          colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepOrange),
          useMaterial3: true,
        ),
        home: const Home(),
      );
}

class Home extends StatefulWidget {
  const Home({super.key});

  @override
  State<Home> createState() => _HomeState();
}

class _HomeState extends State<Home> {
  late Pdfium pdfium;
  FPDF_DOCUMENT? document;

  @override
  void initState() {
    pdfium = createInitializedLibrary();
    super.initState();
  }

  @override
  void dispose() {
    pdfium.DestroyLibrary();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) => Scaffold(
        appBar: AppBar(
          title: const Text('Flutter PDFium Example App'),
        ),
        body: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Center(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.start,
              children: [
                const Icon(Icons.picture_as_pdf, color: Colors.deepOrange),
                const Text('Load PDF from memory'),
                if (document == null)
                  ElevatedButton(
                      onPressed: loadPdf, child: const Text('Load PDF')),
                if (document != null) ...[
                  ElevatedButton(
                      onPressed: unloadPdf, child: const Text('Unload PDF')),
                  Text(
                      'Document with ${pdfium.GetPageCount(document!)} pages.'),
                  Text('First page has size: ${getPageSize()}')
                ],
              ],
            ),
          ),
        ),
      );

  Future loadPdf() async {
    if (document != null) {
      return;
    }

    final bytes =
        (await rootBundle.load('assets/sample.pdf')).buffer.asUint8List();
    final newDoc = using((arena) {
      final dataPointer = arena<ffi.Uint8>(bytes.length);
      for (var i = 0; i < bytes.length; i++) {
        dataPointer[i] = bytes[i];
      }

      final voidPointer = dataPointer.cast<ffi.Void>();

      return pdfium.LoadMemDocument(
          voidPointer, bytes.length, ''.toNativeUtf8().cast<ffi.Char>());
    }, malloc);

    setState(() {
      document = newDoc;
    });
  }

  void unloadPdf() {
    if (document == null) {
      return;
    }

    pdfium.CloseDocument(document!);
    setState(() {
      document = null;
    });
  }

  Size getPageSize() {
    if (document == null) {
      return Size.zero;
    }

    final page = pdfium.LoadPage(document!, 0);
    final size = using((arena) {
      final sizePointer = arena<FS_SIZEF_>();
      pdfium.GetPageSizeByIndexF(document!, 0, sizePointer);

      return Size(sizePointer.ref.width, sizePointer.ref.height);
    }, malloc);
    pdfium.ClosePage(page);

    return size;
  }
}
