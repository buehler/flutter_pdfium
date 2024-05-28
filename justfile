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

@setup-ios:
    mkdir -p ./packages/flutter_pdfium_ios/ios
    rm -rf ./packages/flutter_pdfium_ios/ios/pdfium.xcframework
    cp -r ./.tmp/pdfium-ios/release/pdfium.xcframework ./packages/flutter_pdfium_ios/ios
    echo "Setup pdfium framework for iOS"
