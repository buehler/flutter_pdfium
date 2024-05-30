import 'dart:typed_data';
import 'dart:ui';

Uint8List buildBitmap(Size size, Uint8List data) {
  final bitmapSize =
      (size.width * size.height * RGBA32BitmapHeader.pixelLength).round();
  final header =
      RGBA32BitmapHeader(bitmapSize, size.width.round(), size.height.round());
  header.applyContent(data);
  return header.headerIntList;
}

// Copied from https://github.com/bluefireteam/bitmap/blob/main/lib/src/bitmap.dart
class RGBA32BitmapHeader {
  static const int pixelLength = 4;
  // ignore: constant_identifier_names
  static const int RGBA32HeaderSize = 122;

  RGBA32BitmapHeader(this.contentSize, int width, int height) {
    headerIntList = Uint8List(fileLength);

    final ByteData bd = headerIntList.buffer.asByteData();
    bd.setUint8(0x0, 0x42);
    bd.setUint8(0x1, 0x4d);
    bd.setInt32(0x2, fileLength, Endian.little);
    bd.setInt32(0xa, RGBA32HeaderSize, Endian.little);
    bd.setUint32(0xe, 108, Endian.little);
    bd.setUint32(0x12, width, Endian.little);
    bd.setUint32(0x16, -height, Endian.little);
    bd.setUint16(0x1a, 1, Endian.little);
    bd.setUint32(0x1c, 32, Endian.little); // pixel size
    bd.setUint32(0x1e, 3, Endian.little); //BI_BITFIELDS
    bd.setUint32(0x22, contentSize, Endian.little);
    bd.setUint32(0x36, 0x000000ff, Endian.little);
    bd.setUint32(0x3a, 0x0000ff00, Endian.little);
    bd.setUint32(0x3e, 0x00ff0000, Endian.little);
    bd.setUint32(0x42, 0xff000000, Endian.little);
  }

  int contentSize;

  void applyContent(Uint8List contentIntList) {
    headerIntList.setRange(
      RGBA32HeaderSize,
      fileLength,
      contentIntList,
    );
  }

  late Uint8List headerIntList;

  int get fileLength => contentSize + RGBA32HeaderSize;
}
