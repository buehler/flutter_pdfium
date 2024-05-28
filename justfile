bblanchon_version := "chromium%2F6281"
paulo_version := "6276"

@default:
    just -l

@melos-bootstrap:
    dart pub run melos bootstrap

@ffigen:
    dart pub run melos run ffigen

@download-archives:
    mkdir -p ./.tmp

    curl -L -o ./.tmp/pdfium-win-x64.tgz https://github.com/bblanchon/pdfium-binaries/releases/download/{{bblanchon_version}}/pdfium-win-x64.tgz
    mkdir -p ./.tmp/pdfium-win-x64
    tar -xzf ./.tmp/pdfium-win-x64.tgz -C ./.tmp/pdfium-win-x64

    curl -L -o ./.tmp/pdfium-ios.tgz https://github.com/paulocoutinhox/pdfium-lib/releases/download/{{paulo_version}}/ios.tgz
    mkdir -p ./.tmp/pdfium-ios
    tar -xzf ./.tmp/pdfium-ios.tgz -C ./.tmp/pdfium-ios

@cleanup-download-cache:
    rm -rf ./.tmp

@setup-headers:
    mkdir -p ./packages/flutter_pdfium/pdfium
    cp -r ./.tmp/pdfium-ios/release/include ./packages/flutter_pdfium/pdfium
    echo "Setup pdfium headers for FFIGEN"

@setup-windows:
    mkdir -p ./packages/flutter_pdfium_windows/pdfium
    cp ./.tmp/pdfium-win-x64/bin/pdfium.dll ./packages/flutter_pdfium_windows/pdfium
    echo "Setup pdfium.dll for Windows"

@setup-ios: && _parse-ast
    mkdir -p ./packages/flutter_pdfium_ios/ios
    rm -rf ./packages/flutter_pdfium_ios/ios/pdfium.xcframework
    rm -rf ./packages/flutter_pdfium_ios/src/pdfium
    cp -r ./.tmp/pdfium-ios/release/pdfium.xcframework ./packages/flutter_pdfium_ios/ios
    cp -r ./.tmp/pdfium-ios/release/include ./packages/flutter_pdfium_ios/src/pdfium
    echo "Setup pdfium framework for iOS"

@_parse-ast:
    #! /bin/sh
    mkdir -p ./.tmp/ast
    for header in $(find ./.tmp/pdfium-ios/release/include -name "*.h" -maxdepth 1 -type f); do
        echo "Create AST for $header"
        clang -Xclang -ast-dump=json -fsyntax-only $header > ./.tmp/ast/$(basename $header).json
    done
    echo "Created AST for all headers"
    python ./tools/ast-mapper.py --prefix IOS_ ./.tmp/ast flutter_pdfium_ios
    echo "Created AST mapping for iOS"
