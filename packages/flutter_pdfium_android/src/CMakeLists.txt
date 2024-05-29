# The Flutter tooling requires that developers have CMake 3.10 or later
# installed. You should not increase this version, as doing so will cause
# the plugin to fail to compile for some customers of the plugin.
cmake_minimum_required(VERSION 3.10)

project(flutter_pdfium_android_library VERSION 0.0.1 LANGUAGES C)

add_library(flutter_pdfium_android SHARED
  "flutter_pdfium_android.c"
)

set_target_properties(flutter_pdfium_android PROPERTIES
  PUBLIC_HEADER flutter_pdfium_android.h
  OUTPUT_NAME "flutter_pdfium_android"
)

target_compile_definitions(flutter_pdfium_android PUBLIC DART_SHARED_LIB)
