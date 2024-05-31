import 'dart:ffi' as ffi;
import 'dart:ui' as ui;

import 'package:flutter/widgets.dart';

import '../bindings/fpdf.dart';
import 'errors.dart';
import 'native_lib.dart';

/// The default rendering flags.
const int _renderDefaultFlags = FPDF_LCD_TEXT | FPDF_REVERSE_BYTE_ORDER;

/// Base DPI for Flutter, based on
/// https://groups.google.com/g/flutter-dev/c/oYN_prI7sio/m/ZUk9VSHUAQAJ
const _baseDpi = 160.0;

/// Defines the rotation of the rendered bitmap image of a pdf page.
enum PageRenderRotation {
  /// The image is "normal" upfacing.
  rotate0,

  /// The image is rotated clockwise by 90 degrees.
  rotate90,

  /// The image is rotated by 180 degrees.
  rotate180,

  /// The image is rotated clockwise by 270 degrees
  /// (therefore 90 degrees counter-clockwise).
  rotate270,
}

final class Page {
  final FPDF_PAGE _pointer;
  final Size size;

  Page._(this._pointer)
      : size = Size(
          fpdf().GetPageWidthF(_pointer),
          fpdf().GetPageHeightF(_pointer),
        );

  double get _ratio =>
      WidgetsBinding.instance.platformDispatcher.views.first.devicePixelRatio;

  Size get pixelSize => (size / 72.0) * _baseDpi * _ratio;

  /// Renders the page as a raw [ui.Image]. The returned image is parsed
  /// by flutters native image codec. The received image must be disposed
  /// when it is no longer needed.
  Future<ui.Image> renderImage(
          {Color backgroundColor = const Color.fromARGB(255, 255, 255, 255),
          bool grayscale = false,
          bool renderAnnotations = false,
          PageRenderRotation rotation = PageRenderRotation.rotate0,
          double scale = 1.0}) =>
      Future(() async {
        assert(scale > 0.0, 'Scale must be greater than 0.0');

        var flags = _renderDefaultFlags;
        if (grayscale) {
          flags = flags | FPDF_GRAYSCALE;
        }
        if (renderAnnotations) {
          flags = flags | FPDF_ANNOT;
        }

        final scaledSize = pixelSize * scale;
        final scaledWidth = scaledSize.width.round();
        final scaledHeight = scaledSize.height.round();

        final bitmapPointer =
            fpdf().Bitmap_Create(scaledWidth, scaledHeight, 1);

        fpdf().Bitmap_FillRect(bitmapPointer, 0, 0, scaledWidth, scaledHeight,
            backgroundColor.value);
        fpdf().RenderPageBitmap(bitmapPointer, _pointer, 0, 0, scaledWidth,
            scaledHeight, rotation.index, flags);
        final stride = fpdf().Bitmap_GetStride(bitmapPointer);
        final bitmapData = fpdf()
            .Bitmap_GetBuffer(bitmapPointer)
            .cast<ffi.Uint8>()
            .asTypedList(scaledHeight * stride);

        final buffer = await ui.ImmutableBuffer.fromUint8List(bitmapData);
        fpdf().Bitmap_Destroy(bitmapPointer);

        final descriptor = ui.ImageDescriptor.raw(
          buffer,
          width: scaledWidth,
          height: scaledHeight,
          pixelFormat: ui.PixelFormat.bgra8888,
        );
        final codec = await descriptor.instantiateCodec();
        final frameInfo = await codec.getNextFrame();

        return frameInfo.image;
      });
}

Page loadPage(FPDF_DOCUMENT document, int index) {
  final page = fpdf().LoadPage(document, index);
  if (page == ffi.nullptr) {
    throw getLastLibraryError();
  }

  return Page._(page);
}

void closePage(Page page) {
  fpdf().ClosePage(page._pointer);
}
