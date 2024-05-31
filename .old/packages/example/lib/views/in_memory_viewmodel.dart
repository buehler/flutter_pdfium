import 'package:fluorflow/fluorflow.dart';
import 'package:flutter/services.dart';
import 'package:flutter_pdfium/pdf.dart';

final class InMemoryViewModel extends DataViewModel<Document?> {
  InMemoryViewModel() : super(null);

  void loadDocument() async {
    final byteData = await rootBundle.load('assets/sample.pdf');
    data = Document.fromMemory(byteData.buffer.asUint8List());
  }

  void unloadDocument() {
    data?.close();
    data = null;
  }

  @override
  void dispose() {
    data?.close();
    super.dispose();
  }
}
