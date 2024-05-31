# The Flutter tooling requires that developers have CMake 3.10 or later
# installed. You should not increase this version, as doing so will cause
# the plugin to fail to compile for some customers of the plugin.
cmake_minimum_required(VERSION 3.10)

project(flutter_pdfium_linux_library VERSION 0.0.1 LANGUAGES C)

add_library(flutter_pdfium_linux SHARED
  "flutter_pdfium_linux.c"
)

set_target_properties(flutter_pdfium_linux PROPERTIES
  PUBLIC_HEADER flutter_pdfium_linux.h
  OUTPUT_NAME "flutter_pdfium_linux"
)

target_compile_definitions(flutter_pdfium_linux PUBLIC DART_SHARED_LIB)
