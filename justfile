version := "6276"

@configure: download-headers create-ast create-mapping create-binding

@download-headers:
    #! /bin/sh
    mkdir -p .tmp
    curl -L -o ./.tmp/macos.tgz https://github.com/paulocoutinhox/pdfium-lib/releases/download/{{version}}/macos.tgz
    tar -xzf ./.tmp/macos.tgz -C ./.tmp
    rm -rf ./.tmp/release/include/cpp
    cp -r ./.tmp/release/include/ ./src/pdfium/

@create-ast:
    #! /bin/sh
    rm -rf ./.tmp/ast
    mkdir -p ./.tmp/ast
    for header in $(find ./.tmp/release/include -name "*.h" -maxdepth 1 -type f); do
        echo "Create AST for $header"
        clang -Xclang -ast-dump=json -fsyntax-only -fparse-all-comments $header > ./.tmp/ast/$(basename $header).json
    done

@create-mapping:
    python ./ast-mapper.py

@create-binding:
    dart run ffigen --config ffigen.yaml

@clean:
    rm -rf ./.tmp
