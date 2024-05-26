import 'package:flutter/material.dart';
import 'package:flutter_pdfium/flutter_pdfium.dart';

class InMemoryPage extends StatefulWidget {
  const InMemoryPage({Key? key}) : super(key: key);

  @override
  _InMemoryPageState createState() => _InMemoryPageState();
}

class _InMemoryPageState extends State<InMemoryPage> {
  Document? _document;

  bool get _loaded => _document != null;

  @override
  void dispose() {
    super.dispose();
  }

  @override
  Widget build(BuildContext context) => Scaffold(
      appBar: AppBar(
        title: const Text('Flutter PDFium Memory Demo'),
      ),
      body: Column(
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          const Text('Press the button to load the pdf file from memory.'),
          _loaded
              ? Row(
                  children: [
                    Text('Doc Loaded, Page Count: ${_document!.pageCount}'),
                    TextButton(
                        onPressed: () => _unloadFile(),
                        child: const Text('Unload File'))
                  ],
                )
              : TextButton(
                  onPressed: () => _loadFile(), child: const Text('Load File')),
          !_loaded
              ? const Text('No PDF Content loaded.')
              : Expanded(
                  child: ListView.builder(
                  itemCount: _document?.pageCount,
                  itemBuilder: (context, index) =>
                      Image(image: _document![index].renderBitmap()),
                )),
        ],
      ));

  Future<void> _loadFile() async {
    if (_document != null) {
      return;
    }

    final byteData =
        await DefaultAssetBundle.of(context).load('assets/sample.pdf');
    final document = loadDocument(byteData.buffer.asUint8List());

    setState(() {
      _document = document;
    });
  }

  Future<void> _unloadFile() async {
    if (_document == null) {
      return;
    }

    closeDocument(_document!);

    setState(() {
      _document = null;
    });
  }
}
