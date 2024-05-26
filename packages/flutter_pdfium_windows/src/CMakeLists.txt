# The Flutter tooling requires that developers have CMake 3.10 or later
# installed. You should not increase this version, as doing so will cause
# the plugin to fail to compile for some customers of the plugin.
cmake_minimum_required(VERSION 3.10)

project(flutter_pdfium_windows_library VERSION 0.0.1 LANGUAGES C)

add_library(flutter_pdfium_windows SHARED
  "flutter_pdfium_windows.c"
)

set_target_properties(flutter_pdfium_windows PROPERTIES
  PUBLIC_HEADER flutter_pdfium_windows.h
  OUTPUT_NAME "flutter_pdfium_windows"
)

target_compile_definitions(flutter_pdfium_windows PUBLIC DART_SHARED_LIB)
