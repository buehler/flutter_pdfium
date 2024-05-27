
@configure: melos-bootstrap

@melos-bootstrap:
    dart pub run melos bootstrap

@ffigen:
    dart pub run melos run ffigen

@_download-archive platform version="latest":
    mkdir -p ./.tmp/pdfium-{{platform}}
    curl -L -o ./.tmp/pdfium-{{platform}}.tgz https://github.com/bblanchon/pdfium-binaries/releases/{{version}}/download/pdfium-{{platform}}.tgz
    tar -xzf ./.tmp/pdfium-{{platform}}.tgz -C ./.tmp/pdfium-{{platform}}

@_cleanup-download-cache:
    rm -rf ./.tmp

@download-headers: (_download-archive "ios-x64")
    mkdir -p ./packages/flutter_pdfium/pdfium
    cp -r ./.tmp/pdfium-ios-x64/include ./packages/flutter_pdfium/pdfium

@download-windows: (_download-archive "win-x64")
    mkdir -p ./packages/flutter_pdfium_windows/pdfium
    cp -r ./.tmp/pdfium-win-x64/bin/pdfium.dll ./packages/flutter_pdfium_windows/pdfium
    echo "Downloaded pdfium.dll for Windows"
