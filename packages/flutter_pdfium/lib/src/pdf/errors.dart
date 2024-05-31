import '../bindings/fpdf.dart';
import 'native_lib.dart';

/// Defines error codes that the library may return.
/// If a call is successful
enum PDFiumError {
  /// No error.
  success(FPDF_ERR_SUCCESS, 'No error'),

  /// Unkown error.
  unknown(FPDF_ERR_UNKNOWN, 'Unknown error'),

  /// File not found or could not be opened.
  file(FPDF_ERR_FILE, 'File not found or could not be opened'),

  /// File is not a PDF or corrupted.
  format(FPDF_ERR_FORMAT, 'File is not a PDF or corrupted'),

  /// Password required or incorrect password provided.
  password(
      FPDF_ERR_PASSWORD, 'Password required or incorrect password provided'),

  /// Unsupported security scheme.
  security(FPDF_ERR_SECURITY, 'Unsupported security scheme'),

  /// Page not found or content error.
  page(FPDF_ERR_PAGE, 'Page not found or content error'),

  /// No SDK call was made that could error.
  undefined(-1, 'Undefined error / no SDK call was made that could error');

  final int code;
  final String description;

  const PDFiumError(this.code, this.description);

  static PDFiumError fromLibraryError(int libraryError) =>
      switch (libraryError) {
        FPDF_ERR_SUCCESS => PDFiumError.success,
        FPDF_ERR_UNKNOWN => PDFiumError.unknown,
        FPDF_ERR_FILE => PDFiumError.file,
        FPDF_ERR_FORMAT => PDFiumError.format,
        FPDF_ERR_PASSWORD => PDFiumError.password,
        FPDF_ERR_SECURITY => PDFiumError.security,
        FPDF_ERR_PAGE => PDFiumError.page,
        _ => PDFiumError.undefined,
      };
}

class PDFiumException implements Exception {
  final PDFiumError libraryError;

  const PDFiumException(this.libraryError);

  PDFiumException.fromLibraryError(int libraryError)
      : libraryError = PDFiumError.fromLibraryError(libraryError);

  @override
  String toString() => 'PDFiumException: ${libraryError.description}';
}

PDFiumException getLastLibraryError() =>
    PDFiumException.fromLibraryError(fpdf().GetLastError());
