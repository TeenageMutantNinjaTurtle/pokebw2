#!/usr/bin/env python3
"""Write objdiff.json for one version, with paths relative to the repository root.

dsd writes paths relative to the version's config directory, such as `config/b2_us/arm9/../../../build/...`. Normalizing
them makes them match the ninja targets that objdiff asks ninja to rebuild.
"""
import argparse
import json
import os
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def normalize(value):
    if isinstance(value, dict):
        return {key: normalize(item) for key, item in value.items()}
    if isinstance(value, list):
        return [normalize(item) for item in value]
    if isinstance(value, str) and "../" in value:
        return os.path.normpath(value)
    return value


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("version")
    parser.add_argument("--dsd", required=True)
    parser.add_argument("--compiler", required=True, help="decomp.me compiler name")
    parser.add_argument("--c-flags", required=True, help="compiler flags for decomp.me scratches")
    parser.add_argument("-o", "--output", type=Path, default=ROOT / "objdiff.json")
    args = parser.parse_args()

    result = subprocess.run(
        [args.dsd, "objdiff", "--config-path", f"config/{args.version}/arm9/config.yaml", "--stdout", "--scratch",
         "--compiler", args.compiler, "--c-flags", args.c_flags, "--custom-make", "ninja"],
        cwd=ROOT, capture_output=True, text=True, check=True,
    )
    config = normalize(json.loads(result.stdout))
    args.output.write_text(json.dumps(config, indent=2) + "\n")


if __name__ == "__main__":
    main()
