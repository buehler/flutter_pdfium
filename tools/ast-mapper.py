import argparse
import json
import os

prelim_header = """
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#if _WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <unistd.h>
#endif

#if _WIN32
#define FFI_PLUGIN_EXPORT __declspec(dllexport)
#else
#define FFI_PLUGIN_EXPORT
#endif

"""

prelim_impl = """
#include "flutter_pdfium_ios.h"

"""


def create_mappings(args: argparse.Namespace) -> None:
    functions = {}

    for file in [f for f in os.listdir(args.input) if f.endswith(".json")]:
        with open(os.path.join(args.input, file), "r") as f:
            ast = json.load(f)
            functions[file.replace(".json", "")] = [
                (
                    func.get("name"),
                    func.get("type", {}).get("qualType", "").split("(")[0].strip(),
                    [
                        (
                            p.get("name"),
                            p.get("type", {}).get("qualType", "").split("(")[0].strip(),
                        )
                        for p in func.get("inner", [])
                        if p.get("kind") == "ParmVarDecl"
                    ],
                )
                for func in ast["inner"]
                if func["kind"] == "FunctionDecl"
                and func["loc"].get("includedFrom") is None
            ]

    with open(
        os.path.join("./", "packages", args.output, "src", f"{args.output}.h"), "w"
    ) as out:
        out.write(prelim_header)
        for file, funcs in functions.items():
            out.write(f'#include "pdfium/{file}"\n')
            for name, type, params in funcs:
                out.write(
                    f"FFI_PLUGIN_EXPORT {type} {args.prefix}{name}({','.join(map(lambda p : f"{p[1]} {p[0]}", params))});\n"
                )

    with open(
        os.path.join("./", "packages", args.output, "src", f"{args.output}.c"), "w"
    ) as out:
        out.write(prelim_impl)
        for file, funcs in functions.items():
            for name, type, params in funcs:
                out.writelines(
                    [
                        f"FFI_PLUGIN_EXPORT {type} {args.prefix}{name}({','.join(map(lambda p : f"{p[1]} {p[0]}", params))}){{\n",
                        f"return {name}({','.join(map(lambda p : p[0], params))});\n"
                        "}\n",
                    ]
                )


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="AST Mapper")
    parser.add_argument(
        "input", type=str, help="Input directory containing the json ast files"
    )
    parser.add_argument(
        "output", type=str, help="Output package where the mappings will be saved"
    )
    parser.add_argument(
        "--prefix",
        type=str,
        required=True,
        help="Prefix to be added to the output mappings",
    )

    args = parser.parse_args()
    create_mappings(args)
