# The Flutter tooling requires that developers have CMake 3.10 or later
# installed. You should not increase this version, as doing so will cause
# the plugin to fail to compile for some customers of the plugin.
cmake_minimum_required(VERSION 3.10)

project(flutter_pdfium_library VERSION 0.0.1 LANGUAGES C)

add_library(flutter_pdfium SHARED
        "flutter_pdfium.c"
)

set_target_properties(flutter_pdfium PROPERTIES
        PUBLIC_HEADER flutter_pdfium.h
        OUTPUT_NAME "flutter_pdfium"
)

target_compile_definitions(flutter_pdfium PUBLIC DART_SHARED_LIB)

if (ANDROID)
    if (COMMAND target_link_options)
        target_link_options(flutter_pdfium PRIVATE "-Wl,-z,max-page-size=16384")
    else ()
        set(CMAKE_SHARED_LINKER_FLAGS
                "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,max-page-size=16384")
    endif ()
endif ()