import 'dart:async';

import 'package:fluorflow/fluorflow.dart';
import 'package:flutter/services.dart';
import 'package:flutter_pdfium/pdf.dart';

final class BookmarksViewModel extends DataViewModel<Document?> {
  BookmarksViewModel() : super(null);

  @override
  FutureOr<void> initialize() async {
    await loadDocument();
    return super.initialize();
  }

  Future loadDocument() async {
    final byteData = await rootBundle.load('assets/sample.pdf');
    data = await Document.fromMemory(byteData.buffer.asUint8List());
  }

  @override
  void dispose() {
    data?.close();
    super.dispose();
  }
}
