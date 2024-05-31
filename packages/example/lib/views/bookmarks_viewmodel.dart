import 'dart:async';

import 'package:fluorflow/fluorflow.dart';
import 'package:flutter/services.dart';
import 'package:flutter/widgets.dart';
import 'package:flutter_pdfium/pdf.dart';

final class BookmarksViewModel extends DataViewModel<Document?> {
  final ScrollController pdfScrollController = ScrollController();

  BookmarksViewModel() : super(null);

  @override
  FutureOr<void> initialize() async {
    await loadDocument();
    return super.initialize();
  }

  Future loadDocument() async {
    final byteData = await rootBundle.load('assets/sample.pdf');
    data = Document.fromMemory(byteData.buffer.asUint8List());
  }

  void scrollTo(Bookmark bookmark) {}

  @override
  void dispose() {
    data?.close();
    super.dispose();
  }
}
