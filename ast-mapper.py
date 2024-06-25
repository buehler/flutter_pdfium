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
                    if p.get("kind") == "ParmVarDecl" and p.get("name") is not None
                ],
                [
                    "\n".join(
                        [
                            text.get("text", "")
                            for text in para.get("inner", [])
                            if text.get("kind") == "TextComment"
                        ]
                    )
                    for para in (
                        next(
                            (
                                c.get("inner", [])
                                for c in func.get("inner", [])
                                if c.get("kind") == "FullComment"
                            ),
                            [],
                        )
                    )
                ],
            )
            for func in ast["inner"]
            if func["kind"] == "FunctionDecl"
            and func["loc"].get("includedFrom") is None
            and func.get("name").startswith("FPDF")
        ]

with open(os.path.join("./", "src", "flutter_pdfium.h"), "w") as out:
    out.write(prelim_header)
    for file, funcs in functions.items():
        out.write(f'#include "pdfium/{file}"\n')
        for name, type, params, comment in funcs:
            out.writelines(
                [
                    "".join(
                        "".join(map(lambda i: f"// {i}\n", line))
                        for line in (c.split("\n") for c in comment)
                    ),
                    f"FFI_PLUGIN_EXPORT {type} PDFIUM_{name}({','.join(map(lambda p : f"{p[1]} {p[0]}", params))});\n",
                ]
            )

with open(os.path.join("./", "src", "flutter_pdfium.c"), "w") as out:
    out.write(prelim_impl)
    for file, funcs in functions.items():
        for name, type, params, _ in funcs:
            out.writelines(
                [
                    f"FFI_PLUGIN_EXPORT {type} PDFIUM_{name}({','.join(map(lambda p : f"{p[1]} {p[0]}", params))}){{\n",
                    f"return {name}({','.join(map(lambda p : p[0], params))});\n" "}\n",
                ]
            )
