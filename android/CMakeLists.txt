# The Flutter tooling requires that developers have a version of Visual Studio
# installed that includes CMake 3.14 or later. You should not increase this
# version, as doing so will cause the plugin to fail to compile for some
# customers of the plugin.
cmake_minimum_required(VERSION 3.14)

# Project-level configuration.
set(PROJECT_NAME "flutter_pdfium")
project(${PROJECT_NAME} LANGUAGES CXX)

# Invoke the build for native code shared with the other target platforms.
# This can be changed to accommodate different builds.
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../src" "${CMAKE_CURRENT_BINARY_DIR}/shared")

# Explicitly opt in to modern CMake behaviors to avoid warnings with recent
# versions of CMake.
cmake_policy(VERSION 3.14...3.25)

set(PDFIUM_RELEASE chromium%2F6406)
set(PDFIUM_DIR ${CMAKE_BINARY_DIR}/pdfium/${ANDROID_ABI})

file(MAKE_DIRECTORY ${PDFIUM_DIR})

set(PDFIUM_LIB_FILENAME "libpdfium.so")

set(PDFIUM_ABI2SUF_arm64-v8a "android-arm64")
set(PDFIUM_ABI2SUF_armeabi-v7a "android-arm")
set(PDFIUM_ABI2SUF_x86 "android-x86")
set(PDFIUM_ABI2SUF_x86_64 "android-x64")

SET(PDFIUM_JNI_DIR ${CMAKE_SOURCE_DIR}/jni/${ANDROID_ABI})
file(MAKE_DIRECTORY ${PDFIUM_JNI_DIR})
SET(PDFIUM_JNI_LIB ${CMAKE_SOURCE_DIR}/jni/${ANDROID_ABI}/${PDFIUM_LIB_FILENAME})

set(PDFIUM_ARCHIVE_NAME pdfium-${PDFIUM_ABI2SUF_${ANDROID_ABI}})
set(PDFIUM_LIB_FILENAME ${PDFIUM_DIR}/lib/${PDFIUM_LIB_FILENAME})

if(NOT EXISTS ${PDFIUM_LIB_FILENAME})
    message(STATUS "Download precompiled pdfium...")
    file(DOWNLOAD https://github.com/bblanchon/pdfium-binaries/releases/download/${PDFIUM_RELEASE}/${PDFIUM_ARCHIVE_NAME}.tgz ${PDFIUM_DIR}/${PDFIUM_ARCHIVE_NAME}.tgz)
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E tar zxf ${PDFIUM_DIR}/${PDFIUM_ARCHIVE_NAME}.tgz
        WORKING_DIRECTORY ${PDFIUM_DIR}
        ERROR_QUIET
    )
    if(STATUS AND NOT STATUS EQUAL 0)
        message(FATAL_ERROR "Could not obtain pdfium binary for ${ANDROID_ABI}")
    endif()
else()
    message(STATUS "Use existing precompiled pdfium." )
endif()

file(REMOVE ${PDFIUM_JNI_LIB})
file(CREATE_LINK ${PDFIUM_LIB_FILENAME} ${PDFIUM_JNI_LIB} SYMBOLIC)

find_library(libc++ libc++_static.a)

# List of absolute paths to libraries that should be bundled with the plugin.
# This list could contain prebuilt libraries, or libraries created by an
# external build triggered from this build file.
set(flutter_pdfium_bundled_libraries
  # Defined in ../src/CMakeLists.txt.
  # This can be changed to accommodate different builds.
  $<TARGET_FILE:flutter_pdfium>
  ${PDFIUM_LIB_FILENAME}
  PARENT_SCOPE
)

target_link_libraries(flutter_pdfium PRIVATE ${PDFIUM_LIB_FILENAME} ${libc++})
