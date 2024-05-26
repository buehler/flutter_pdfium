import 'dart:ffi' as ffi;

import 'package:flutter/painting.dart';
import 'package:flutter/rendering.dart';

import 'bindings/fpdf.dart';
import 'bitmap.dart';
import 'errors.dart';
import 'native_lib.dart';

/// The default rendering flags.
const int _renderDefaultFlags = FPDF_LCD_TEXT | FPDF_REVERSE_BYTE_ORDER;
const _dpi = 96.0;

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
  final Size pixelSize;

  Page._(this._pointer)
      : size = Size(
          fpdf().GetPageWidthF(_pointer),
          fpdf().GetPageHeightF(_pointer),
        ),
        pixelSize = Size(
              fpdf().GetPageWidthF(_pointer),
              fpdf().GetPageHeightF(_pointer),
            ) /
            72 *
            _dpi;

  /// Render the page as a bitmap image.
  MemoryImage renderBitmap(
      {Color backgroundColor = const Color.fromARGB(255, 255, 255, 255),
      bool grayscale = false,
      bool renderAnnotations = false,
      PageRenderRotation rotation = PageRenderRotation.rotate0,
      double scale = 1.0}) {
    assert(scale > 0.0, 'Scale must be greater than 0.0');

    var flags = _renderDefaultFlags;
    if (grayscale) {
      flags = flags | FPDF_GRAYSCALE;
    }
    if (renderAnnotations) {
      flags = flags | FPDF_ANNOT;
    }

    final scaledSize = pixelSize * scale;

    final bitmapPointer = fpdf()
        .Bitmap_Create(scaledSize.width.round(), scaledSize.height.round(), 1);

    fpdf().Bitmap_FillRect(bitmapPointer, 0, 0, scaledSize.width.round(),
        scaledSize.height.round(), backgroundColor.value);
    fpdf().RenderPageBitmap(
        bitmapPointer,
        _pointer,
        0,
        0,
        scaledSize.width.round(),
        scaledSize.height.round(),
        rotation.index,
        flags);
    final stride = fpdf().Bitmap_GetStride(bitmapPointer);
    final bitmapData = fpdf()
        .Bitmap_GetBuffer(bitmapPointer)
        .cast<ffi.Uint8>()
        .asTypedList(scaledSize.height.round() * stride);
    final image = buildBitmap(scaledSize, bitmapData);
    fpdf().Bitmap_Destroy(bitmapPointer);

    return MemoryImage(image);
  }
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
