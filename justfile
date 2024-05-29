bblanchon_version := "chromium%2F6281"
paulo_version := "6276"

@default:
    just -l

@configure: melos-bootstrap download-archives setup-headers setup-windows setup-ios setup-macos

@melos-bootstrap:
    dart run melos bootstrap

@ffigen:
    dart run melos run ffigen
    echo "Generated FFI bindings"

@download-archives:
    mkdir -p ./.tmp

    curl -L -o ./.tmp/pdfium-win-x64.tgz https://github.com/bblanchon/pdfium-binaries/releases/download/{{bblanchon_version}}/pdfium-win-x64.tgz
    mkdir -p ./.tmp/pdfium-win-x64
    tar -xzf ./.tmp/pdfium-win-x64.tgz -C ./.tmp/pdfium-win-x64

    curl -L -o ./.tmp/pdfium-ios.tgz https://github.com/paulocoutinhox/pdfium-lib/releases/download/{{paulo_version}}/ios.tgz
    mkdir -p ./.tmp/pdfium-ios
    tar -xzf ./.tmp/pdfium-ios.tgz -C ./.tmp/pdfium-ios

    curl -L -o ./.tmp/pdfium-macos.tgz https://github.com/paulocoutinhox/pdfium-lib/releases/download/{{paulo_version}}/macos.tgz
    mkdir -p ./.tmp/pdfium-macos
    tar -xzf ./.tmp/pdfium-macos.tgz -C ./.tmp/pdfium-macos

    curl -L -o ./.tmp/pdfium-android.tgz https://github.com/paulocoutinhox/pdfium-lib/releases/download/{{paulo_version}}/android.tgz
    mkdir -p ./.tmp/pdfium-android
    tar -xzf ./.tmp/pdfium-android.tgz -C ./.tmp/pdfium-android

@clear:
    rm -rf ./.tmp

@setup-headers: && ffigen
    mkdir -p ./packages/flutter_pdfium/pdfium
    cp -r ./.tmp/pdfium-ios/release/include ./packages/flutter_pdfium/pdfium
    echo "Setup pdfium headers for FFIGEN"

@setup-windows:
    mkdir -p ./packages/flutter_pdfium_windows/pdfium
    cp ./.tmp/pdfium-win-x64/bin/pdfium.dll ./packages/flutter_pdfium_windows/pdfium
    echo "Setup pdfium.dll for Windows"

@setup-ios: && (_create-apple-lib-bindings "macos" "IOS_")
    mkdir -p ./packages/flutter_pdfium_ios/ios
    rm -rf ./packages/flutter_pdfium_ios/ios/pdfium.xcframework
    rm -rf ./packages/flutter_pdfium_ios/src/pdfium
    cp -r ./.tmp/pdfium-ios/release/pdfium.xcframework ./packages/flutter_pdfium_ios/ios
    cp -r ./.tmp/pdfium-ios/release/include ./packages/flutter_pdfium_ios/src/pdfium
    echo "Setup pdfium framework for iOS"

@setup-macos: && (_create-apple-lib-bindings "macos" "MAC_")
    rm -rf ./packages/flutter_pdfium_macos/macos/Frameworks
    mkdir -p ./packages/flutter_pdfium_macos/macos/Frameworks
    cp -r ./.tmp/pdfium-macos/release/lib/libpdfium.a ./packages/flutter_pdfium_macos/macos/Frameworks
    cp -r ./.tmp/pdfium-macos/release/include ./packages/flutter_pdfium_macos/src/pdfium
    echo "Setup pdfium library for macOS"

@_create-apple-lib-bindings platform prefix:
    #! /bin/sh
    rm -rf ./.tmp/ast
    mkdir -p ./.tmp/ast
    for header in $(find ./.tmp/pdfium-ios/release/include -name "*.h" -maxdepth 1 -type f); do
        echo "Create AST for $header"
        clang -Xclang -ast-dump=json -fsyntax-only $header > ./.tmp/ast/$(basename $header).json
    done
    echo "Created AST for all headers"
    python ./tools/ast-mapper.py --prefix {{prefix}} ./.tmp/ast flutter_pdfium_{{platform}}
    echo "Created AST mapping for {{platform}}"
