# The Flutter tooling requires that developers have CMake 3.10 or later
# installed. You should not increase this version, as doing so will cause
# the plugin to fail to compile for some customers of the plugin.
cmake_minimum_required(VERSION 3.10)

project(flutter_pdfium_macos_library VERSION 0.0.1 LANGUAGES C)

add_library(flutter_pdfium_macos SHARED
  "flutter_pdfium_macos.c"
)

set_target_properties(flutter_pdfium_macos PROPERTIES
  PUBLIC_HEADER flutter_pdfium_macos.h
  OUTPUT_NAME "flutter_pdfium_macos"
)

target_compile_definitions(flutter_pdfium_macos PUBLIC DART_SHARED_LIB)
