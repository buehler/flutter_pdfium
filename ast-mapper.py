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
#include "flutter_pdfium.h"

"""


functions = {}

for file in [f for f in os.listdir("./.tmp/ast") if f.endswith(".json")]:
    with open(os.path.join("./.tmp/ast", file), "r") as f:
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

with open(os.path.join("./", "src", "flutter_pdfium.h"), "w") as out:
    out.write(prelim_header)
    for file, funcs in functions.items():
        out.write(f'#include "pdfium/{file}"\n')
        for name, type, params in funcs:
            out.write(
                f"FFI_PLUGIN_EXPORT {type} PDFIUM_{name}({','.join(map(lambda p : f"{p[1]} {p[0]}", params))});\n"
            )

with open(os.path.join("./", "src", "flutter_pdfium.c"), "w") as out:
    out.write(prelim_impl)
    for file, funcs in functions.items():
        for name, type, params in funcs:
            out.writelines(
                [
                    f"FFI_PLUGIN_EXPORT {type} PDFIUM_{name}({','.join(map(lambda p : f"{p[1]} {p[0]}", params))}){{\n",
                    f"return {name}({','.join(map(lambda p : p[0], params))});\n" "}\n",
                ]
            )
