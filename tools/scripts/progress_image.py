#!/usr/bin/env python3
"""Draw the progress treemap of decomp.dev from an objdiff report, and update the progress line of the README.

Each unit of the report is a rectangle sized by its code, laid out as decomp.dev lays it out (streemap's binary layout,
in report order), and shaded as decomp.dev shades it: green when it matches, otherwise from grey to blue by how close
its code is to matching. The units with no code are left out. The image is committed, so run it after a batch of
work, from a report that `ninja progress` has brought up to date:

    ninja progress
    .venv/bin/python tools/scripts/progress_image.py

The README's progress line sits between `<!-- progress -->` and `<!-- /progress -->`, and is rewritten from the same
report.
"""
import argparse
import colorsys
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def hsl(h: float, s: float, l: float) -> tuple[float, float, float]:
    """An sRGB color from CSS-style HSL: degrees and percentages."""
    return colorsys.hls_to_rgb(h / 360, l / 100, s / 100)


def mix(c0, c1, t: float):
    return tuple(a + (b - a) * t for a, b in zip(c0, c1))


def html_color(c) -> str:
    # Truncated, as decomp.dev converts its colors
    return "#" + "".join(f"{int(x * 255):02x}" for x in c)


def binary_layout(rect, sizes: list[float]) -> list[tuple[float, float, float, float]]:
    """streemap's binary layout: split the items, in order, into two runs of about half the total each, and the
    rectangle across its longer side in their proportion, until each item has its own rectangle."""
    sums, total = [], 0.0
    for size in sizes:
        total += size
        sums.append(total)
    out = [None] * len(sizes)

    def place(rect, lo, hi, offset, value):
        if hi == lo or value == 0:
            return
        if hi - lo == 1:
            out[lo] = rect
            return
        target = value / 2 + offset
        # The first item whose running total passes the target starts the second run, but never the first item
        mid = next((i for i in range(lo, hi) if sums[i] > target), hi)
        mid = max(mid, lo + 1)
        left = sums[mid - 1] - offset
        right = value - left
        x, y, w, h = rect
        if w > h:
            xe = x + w
            xm = (x * right + xe * left) / value
            first, second = (x, y, xm - x, h), (xm, y, xe - xm, h)
        else:
            ye = y + h
            ym = (y * right + ye * left) / value
            first, second = (x, y, w, ym - y), (x, ym, w, ye - ym)
        place(first, lo, mid, offset, left)
        place(second, mid, hi, sums[mid - 1], right)

    place(rect, 0, len(sizes), 0.0, total)
    return out


def layout_units(sizes: list[float], aspect: float):
    """decomp.dev's layout: a unit square stretched to the image's aspect, in fractions of the image."""
    if aspect > 1:
        rects = binary_layout((0.0, 0.0, 1.0, 1 / aspect), sizes)
        return [(x, y * aspect, w, h * aspect) for x, y, w, h in rects]
    rects = binary_layout((0.0, 0.0, aspect, 1.0), sizes)
    return [(x / aspect, y, w / aspect, h) for x, y, w, h in rects]


def render_svg(units: list[tuple[str, float, float]], width: int, height: int) -> str:
    """The treemap as decomp.dev's SVG: units are (name, code size, fuzzy match percent)."""
    rects = layout_units([size for _, size, _ in units], width / height)
    complete0, complete1 = html_color(hsl(120, 100, 39)), html_color(hsl(120, 100, 17))
    gradients, boxes = [], []
    for i, ((name, _, pct), (x, y, w, h)) in enumerate(zip(units, rects)):
        if pct == 100:
            c0, c1 = complete0, complete1
        else:
            c0 = html_color(mix(hsl(200, 0, 21), hsl(200, 100, 35), pct / 100))
            c1 = html_color(mix(hsl(200, 0, 15), hsl(200, 100, 15), pct / 100))
        # Percentages to 3 decimals, a thousandth of a pixel at this size, keep the committed file's diffs small
        gradients.append(
            f'<radialGradient id="unit-{i}" gradientUnits="userSpaceOnUse" cx="{(x + w * 0.4) * 100:.3f}%" '
            f'cy="{(y + h * 0.4) * 100:.3f}%" fr="{(w + h) * 10:.3f}%" r="{(w + h) * 50:.3f}%">'
            f'<stop offset="0%" stop-color="{c0}"/><stop offset="100%" stop-color="{c1}"/></radialGradient>')
        boxes.append(f'<rect class="unit" width="{w * 100:.3f}%" height="{h * 100:.3f}%" x="{x * 100:.3f}%" '
                     f'y="{y * 100:.3f}%" fill="url(#unit-{i})"><title>{name}: {pct:.2f}%</title></rect>')
    return "\n".join([
        '<?xml version="1.0" encoding="utf-8"?>',
        f'<svg xmlns="http://www.w3.org/2000/svg" version="1.1" viewBox="0 0 {width} {height}" width="{width}" '
        f'height="{height}">',
        "<style>.unit { stroke: #000; stroke-width: 0.5; }</style>",
        *gradients,
        *boxes,
        "</svg>",
        "",
    ])


def progress_line(measures: dict) -> str:
    """One line for the README: code, functions and files that match."""
    code, total = int(measures.get("matched_code", 0)), int(measures.get("total_code", 0))
    funcs, total_funcs = int(measures.get("matched_functions", 0)), int(measures.get("total_functions", 0))
    files, total_files = int(measures.get("complete_units", 0)), int(measures.get("total_units", 0))
    return (f"{measures.get('matched_code_percent', 0):.2f}% of the code matches ({code:,} of {total:,} bytes), "
            f"with {funcs:,} of {total_funcs:,} functions, and {files} of {total_files} source files are complete.")


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--report", type=Path, default=ROOT / "build" / "b2_us" / "report.json")
    parser.add_argument("--output", type=Path, default=ROOT / "docs" / "progress.svg")
    parser.add_argument("--readme", type=Path, default=ROOT / "README.md")
    parser.add_argument("--width", type=int, default=950)
    parser.add_argument("--height", type=int, default=475)
    args = parser.parse_args()

    report = json.loads(args.report.read_text())
    units = []
    for unit in report["units"]:
        measures = unit.get("measures", {})
        size = int(measures.get("total_code", 0))
        if size:
            units.append((unit["name"], float(size), float(measures.get("fuzzy_match_percent", 0))))
    args.output.write_text(render_svg(units, args.width, args.height))
    print(f"{args.output.relative_to(ROOT) if args.output.is_relative_to(ROOT) else args.output}: {len(units)} units")

    line = progress_line(report["measures"])
    readme = args.readme.read_text()
    updated, count = re.subn(r"(<!-- progress -->\n)(?:.*?\n)?(<!-- /progress -->)",
                             lambda m: m.group(1) + line + "\n" + m.group(2), readme, flags=re.S)
    if count:
        args.readme.write_text(updated)
        print(f"{args.readme.name}: {line}")
    else:
        print(f"{args.readme.name} has no <!-- progress --> markers; the line would be: {line}")


if __name__ == "__main__":
    main()
