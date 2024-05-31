import 'dart:ui' as ui;

import 'package:flutter/widgets.dart';

import '../../pdf.dart' as pdf;

class PageRenderer extends StatefulWidget {
  final pdf.Page page;

  const PageRenderer(this.page, {super.key});

  @override
  State<PageRenderer> createState() => _PageRendererState();
}

class _PageRendererState extends State<PageRenderer> {
  ui.Image? _image;

  @override
  void initState() {
    widget.page.renderImage().then((image) => setState(() => _image = image));
    super.initState();
  }

  @override
  void dispose() {
    _image?.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) => _image == null
      ? SizedBox.fromSize(size: widget.page.pixelSize)
      : RawImage(image: _image!);
}
