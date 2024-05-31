import 'dart:async';

import 'package:fluorflow/fluorflow.dart';
import 'package:flutter/services.dart';
import 'package:flutter/widgets.dart';
import 'package:flutter_pdfium/pdf.dart';

final class BookmarksViewModel extends DataViewModel<Document?> {
  final pdfScrollKey = GlobalKey();
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

  void scrollTo(Bookmark bookmark) async {
    if (data == null) {
      return;
    }

    final renderBox =
        pdfScrollKey.currentContext?.findRenderObject() as RenderBox?;
    final scalingFactor = (renderBox?.size.height ?? 1.0) /
        (renderBox?.constraints.maxHeight ?? 1.0);

    final offset = data!.pageOffset(bookmark.pageIndex) * scalingFactor;

    await pdfScrollController.animateTo(
      offset,
      duration: const Duration(milliseconds: 500),
      curve: Curves.easeInOut,
    );
  }

  @override
  void dispose() {
    data?.close();
    super.dispose();
  }
}
