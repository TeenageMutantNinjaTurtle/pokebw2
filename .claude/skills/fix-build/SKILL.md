---
name: fix-build
description: Diagnose a pokebw2 build failure after a C or config change. Covers link errors, a section range that doesn't contain its last symbol, a module check or SHA1 failing in one module or one version, undefined runtime helpers, redeclarations, and a probe that matches while ninja fails. Use whenever `ninja` fails or a ROM no longer matches.
---

# Fix the build

Read only the end of the output: `ninja 2>&1 | tail -30`. `ninja` checks, per version, the archives built from source,
every module (`dsd check modules`) and the ROM's SHA1, so the failing check names the module and the version.

| Symptom | Cause and fix |
| --- | --- |
| `Last symbol 'X' ... not contained within the file's section range` | A `.data`/`.rodata`/`.bss` range in `delinks.txt` ends before the file's last object. Extend the range to the end of that object. If the object is the next file's, the boundary is wrong. When an object nothing references sits between files, `config_fixes.py add-data` gives it a symbol. Fix both versions. |
| `Check ... overlay N: checksum failed` in one module the change didn't touch | (1) A function made `static` that this module calls links to address 0 through a veneer. Make it global again, and use `mark_complete.py`, which checks for this. (2) A header type change altered a caller's code in another file. `git diff include/` and probe the files that include it. (3) An ambiguous relocation now resolves to another overlay's symbol (see below). (4) A literal in that module that dsd took for a pointer into the data just made complete, such as ov011's MD5 constant `0x021ac7f4` that fell inside overlay 298's rodata in White 2: the same value in both versions while the data moved shows it is not a pointer. `config_fixes.py remove-reloc` it. |
| Fails in one version only | White 2: functions marked `different` in `build/version_map.tsv` need `#ifdef WHITE2` code. Probe with `--version w2_us`. Data that differs (message IDs, tables) can also break only one version. Compare the configs of both versions for the file. |
| Probe matches every function but the module check fails | The probe skips relocated bytes: a call to the wrong function, a wrong addend (an index folded into a literal pool address), the wrong runtime helper (`_s32_div_f` against `_u32_div_f`), data placed in the wrong section (`const` or not), or wrong data contents. Run `.venv/bin/python tools/scripts/romdiff.py extract/... build/...` for the region, or compare the built overlay in `build/<version>/build` with the original. |
| `undefined: __aeabi_*` or a float helper when a file goes complete | MWCC calls `_fadd`, `_ffix` and the like by their own names. Rename swan's `__aeabi_*` with `rename_symbol.py`, or `config_fixes.py add-label` a second name onto the one copy (`_ll_mul` on `_ull_mul`, `_fflt` on `__aeabi_i2f`, `_ll_udiv` on `__aeabi_uldivmod`, `_ffixu` on `__aeabi_f2uiz`). |
| An ambiguous relocation (`module:overlays(36,214)`) | dsd couldn't tell which overlay is meant, and the build links to the first. `config_fixes.py reloc-module overlays/ovNNN 'overlay(M)' ADDR`. This only links while the symbol is global. When you make a function static, check `relocs.txt` of both versions for relocations to it with several candidates; `mark_complete.py` doesn't catch these. The veneer the linker adds grows the calling overlay's `.text` by 0x10, which moves every overlay placed `AFTER` it and main's pointers into them, so most modules fail at once: ov011's call to ov189's `0x021a303c`, `overlays(165,189)`, broke everything when `status_rcv.c` made its function there static. Find the overlay whose `*_TEXT_END` in `build/<version>/arm9.o.xMAP` is past its `delinks.txt` end. |
| A literal that is an overlay ID | `OVERLAY_ID(n)` in the C, and `config_fixes.py overlay-id overlays/ovNNN n ADDR`. |
| A field referenced through its own symbol | dsd made a symbol inside a struct or table. Retarget its relocations in both versions' `relocs.txt` to the base plus an addend (`to:0x<base> add:0xN`), and remove the inner symbol (`config_fixes.py remove-symbol`). No `config_fixes.py` command does the retargeting yet, so a regeneration loses it; say so in the commit, or add the command. |
| `redeclared` or `conflicting types` | One declaration per function, in the owner's header. Make the parameter types match the asm and update the callers. NitroSDK/NNS types live in `lib/nitro/include/nitro` and `lib/nnsys/include/nnsys`. |
| The probe calls a function "unknown" | The static's symbol still has its `func_` name. Rename it to its C name. |
| A first build in a new worktree fails on the lcf or extract | Link `orig/`, `tools/dsd`, `tools/objdiff-cli` and `tools/wibo`, then run `ninja extract/b2_us/config.yaml` (and `w2_us`) before `ninja`. |
| `ninja: warning: premature end of file` | Another session is writing `.ninja_log`. Harmless. |

After a fix, run `ninja` again until both versions pass, then go back to `finish-file`. When a failure teaches
something new, add it to this table (see `record-lesson`).
