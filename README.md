# Pokémon Black 2 and White 2

A work-in-progress decompilation of Pokémon Black 2 and White 2 (NDS, DSi-enhanced). The long-term goal is a PC port.

It builds the following ROMs:

| Version | File | SHA1 |
| --- | --- | --- |
| Black 2, USA/Europe (NDSi Enhanced) | `build/pokeblack2_us.nds` | `e51e6dfb8678a3d19dcd2a10691b96a569ca0abb` |
| White 2, USA/Europe (NDSi Enhanced) | `build/pokewhite2_us.nds` | `b5d7490be7b415b8f1e672a53e978a9cc667e56a` |

## Status

Both ROMs rebuild byte for byte from the same source tree. 14 source files match, including the script VM and the
trainer AI, and everything else is still delinked code. The trainer AI scripts are built from source, see
[Scripts](#scripts).

- 41,423 functions found by [dsd](https://github.com/AetiasHax/ds-decomp) in the ARM9, its 344 overlays, ITCM, DTCM, and the two TWL autoloads.
- 8,152 functions and 573 data symbols have real names, imported from [swan](#names).
- The DSi-only LTD module in ARM9i is decompressed, analyzed and linked like the other modules. The ARM7i program is
  only extracted (decrypted) and rebuilt.

## Setup

1. Build dsd with DSi hybrid ROM support. Until the changes are upstreamed, it comes from these forks, both on the
   `dsi-hybrid` branch:
   - `ds-rom`: DSi header, digests, modcrypt, TWL autoloads and DSi banners.
   - `ds-decomp`: TWL entrypoint, DS Protect and Thumb jump table fixes. Its `Cargo.toml` patches in `../ds-rom/lib`.

   ```sh
   cd ../ds-decomp && cargo build --release && cp target/release/dsd ../pokebw2/tools/dsd
   ```

2. Install LLVM, whose `llvm-mc` and `llvm-objcopy` assemble the scripts and must be on the `PATH`.

3. Place your own dumps at `orig/baserom_b2_us.nds` and/or `orig/baserom_w2_us.nds`. They must match the SHA1s above.
   They are not included and will not be provided. `tools/scripts/verify_dsi_rom.py` checks a dump against the
   digests in its own header.

4. Configure and build. `configure.py` downloads [wibo](https://github.com/decompals/wibo) and the Metrowerks
   CodeWarrior tools on first run.

   ```sh
   python3 configure.py
   ninja
   ```

   `ninja` extracts each base ROM, delinks the code, links it with `mwldarm`, rebuilds the ROM and checks its SHA1.
   `configure.py` builds every version that has a base ROM, or the versions given as arguments.

## Layout

| Path | Contents |
| --- | --- |
| `config/<version>/` | dsd configs: sections (`delinks.txt`), symbols and relocations for every module |
| `config/names.txt`, `config/fixes.txt` | Our own names and fixes to dsd's analysis, applied again after regenerating the configs |
| `src/<module>/` | Decompiled C, one directory per module, such as `src/ov035/event_mapchange.c` |
| `include/` | Headers shared by the C code, see [Code organization](#code-organization) |
| `data/` | Scripts assembled into the ROM's files, see [Scripts](#scripts) |
| `include/asm/` | Macros for the scripts |
| `tools/scripts/` | Helper scripts, such as `romdiff.py` to compare two ROMs region by region |
| `extract/`, `build/` | Generated, never committed |

## DSi specifics

Black 2 is an NDS/DSi hybrid built with the TWL-SDK, which differs from DS-only games in ways the tooling had to learn:

- The ARM9 has no footer. Its autoload list has four words per entry, including a `.sinit` address.
- The ROM has a DSi region with ARM9i/ARM7i programs. The first 0x4000 bytes of ARM9i are encrypted with modcrypt
  (AES-CTR). Extraction decrypts it, and the build re-encrypts it.
- Every 0x400-byte sector of the ROM is covered by a SHA1-HMAC digest, and the header holds SHA1-HMACs of each
  program. The build recomputes all of these.
- The digests of the ARM9 secure area are computed over its encrypted form. Without an ARM7 BIOS the build reuses
  the original values, which stay valid as long as the secure area is unchanged.
- The DSi-only LTD ("limited") module is compressed inside ARM9i and loaded to `0x02700000` in DSi mode. ARM9 main
  calls into it. Extraction splits ARM9i into this module (`dsi/ltd_autoload_0.bin`), and the build links, recompresses
  and reinserts it.

## Known gaps

- dsd only finds 253 functions in the LTD module's 437 KB. Its layout, with code after the static initializers,
  does not fit dsd's section heuristics yet.
- 8 calls lead to functions dsd did not discover, and got placeholder symbols (`func_..._unk`).

## Compiler

The game code was built with CodeWarrior for DSi, a version between `dsi/1.1p1` and `dsi/1.3p1`, and
`configure.py` uses `dsi/1.1p1` (build 1024, `mwcc_40_1024` on decomp.me):

- `dsi/1.6sp1` and `dsi/1.6sp2` do not match overlay 4's switch statement.
- `dsi/1.1` differs from the later builds in one way: after a store to a field, it reuses the stored register where
  the game reloads the field (`strb r0, [r4, r7]; ldrb r0, [r4, r7]`). That reload is the compiler, not `volatile`.
- `dsi/1.1p1` through `dsi/1.3p1` produce identical code for every game function tried so far.

The ROM was not necessarily built with one compiler. The Pokémon Black decomp by Goldoire found library code in Black
built with other versions (`2.0/sp2p2` and `1.2`), so try `compiler_probe.py --compilers all` on library code that
doesn't match. `configure.py` extracts only the `dsi` compilers; the others are in `build/mwccarm.zip`, and `1.2`
rejects `-ipa file`.

`tools/scripts/compiler_probe.py` compiles a C file with every version and compares each function against the
game, ignoring relocated bytes. For example:

```sh
.venv/bin/python tools/scripts/compiler_probe.py tools/compiler_tests/main_loops.c
```

It needs `pyelftools`, `capstone` and `pyyaml`. To look at a function's disassembly, run `dsd dis` into
`build/asm`, then use `tools/scripts/show_func.py`.

## Decompiling

Matching is checked per function with [objdiff](https://github.com/encounter/objdiff). A default `ninja` also writes
`objdiff.json` for the first configured version, Black 2 by default, which the objdiff GUI opens from this directory.

1. Move a range of functions into a source file by adding it to the module's `delinks.txt`, as `src/ov004/event_worldtrade.c`
   is in `config/b2_us/arm9/overlays/ov004/delinks.txt`. Mark it `complete` once all its functions match. Add the
   same entry to `config/w2_us` with White 2's addresses, which `build/version_map.tsv` lists.
2. Write the C code. objdiff rebuilds the object with ninja whenever a source file changes, and diffs every function
   against the original.
3. objdiff can also create a decomp.me scratch for a function. The scratch uses compiler `mwcc_40_1024` (dsi/1.1p1),
   and a context file preprocessed from the source.

`ninja progress` prints how much of the game matches, from the report at `build/b2_us/report.json`.

`tools/scripts/add_source_file.py` adds a source file to both versions' `delinks.txt`, with White 2's ranges taken
from the version map. `tools/scripts/compiler_probe.py src/... --compilers 1.1 --show-diff 1.1` compiles a file and
diffs every function in it against the original.

Things that affect whether MWCC output matches:

- Register allocation follows the declaration order of locals, so try reordering declarations when registers are
  swapped.
- Loads through a pointer are not moved above stores unless the pointee is `const`. A load that the original
  schedules early, such as an argument loaded before the stack arguments are stored, points to a `const` parameter.
- The same rule moves a call's stack argument stores. When loads through a pointer that is not `const` follow the
  call, the stack arguments are stored before the register arguments are set up. If the original stores them last,
  the pointer is `const`.
- Float arithmetic calls MWCC's runtime helpers, such as `_fadd` and `_ffix`, which swan names `__aeabi_*`. When a
  complete file fails to link on one of them, rename it to the MWCC name with `rename_symbol.py`.
- Structs passed by value go in registers and on the stack. Code that copies a struct to the stack and passes its
  address takes a pointer to a local copy.
- Static data and stack locals are laid out in reverse declaration order.
- Overlay IDs are linker symbols, written `OVERLAY_ID(279)` from `gfl/overlay.h`, which gives the literal pool entry
  a relocation. Mark the literal in the config with `tools/scripts/config_fixes.py overlay-id`.
- A switch case that ends in the same code as another case is merged into it, so its end moves.
- Switch cases are laid out in source order, not by value, so the layout shows the order the cases were written in.
- Identical statements in different branches are merged, so a branch that jumps into the middle of another block had
  the same code in the source. For example, `if (a) { x = 3; y = 19; } else { x = 0; y = 19; }` compiles differently
  from `x = a ? 3 : 0; y = 19;`.
- `static const` data goes in `.rodata`, so a table that the original has in `.data` is not `const`. The module
  check fails if a table ends up in the wrong section, even when every function matches.
- `a == 4 || a == 5` becomes a range check. Separate comparisons that jump to the same code come from separate
  branches with the same body.
- The types of locals and of the values they hold change how spilled values are scheduled. The trainer AI's speed
  comparison only matches with the speed function returning `u16` into `u16` locals: a spilled `u16` is reloaded after
  the call's stack argument is stored, while a spilled `u32` is reloaded before it.
- Masks written with `~` clear bits with `bic`. The game's `and` with a constant such as `0xef` is `x &= (u8)~FLAG`.
- `arr[count++] = x` and `arr[count] = x; count++;` allocate registers differently, as do `count = 1; arr[0] = x;` and
  the reverse order.
- When comparing a call's result, `v = f(); if (v == x)` and `if (f() == x)` put the operands of `cmp` in opposite
  orders.
- When the order of instructions differs and no source change moves it, try `tools/scripts/permuter_setup.py`, which
  prepares a function for [decomp-permuter](https://github.com/simonlindholm/decomp-permuter).

## Scripts

The script VM in `src/main/vm.c` runs four sets of commands: field events, the trainer AI, battle move animations and
musicals. Scripts are files in the ROM's NARC archives. Each command is a 16-bit ID followed by its arguments.

The trainer AI scripts are built from source. Archive `a/1/6/9` holds 14 scripts, one per AI flag, which run in turn
for each flag the trainer has. They are written in `data/tr_ai/tr_ai_NN.s` with the macros in
`include/asm/tr_ai.inc`. Each macro is one command of `src/ov170/tr_ai.c`, named for what the command does. Its
arguments are 32-bit. Jump, list and table arguments are labels, which the macros encode relative to the end of the
argument. Lists of values end with `list_end`.

`ninja` assembles each script with `llvm-mc`, converts it to a binary with `llvm-objcopy`, packs the binaries with
`tools/scripts/narc.py` into `build/<version>/files/a/1/6/9`, and checks the archive against the extracted one. The
ROM is built from `build/<version>/files`, which `tools/scripts/files_tree.py` fills with links to the extracted files,
except for the files built from source. `ARCHIVES` in `configure.py` lists them.

`tools/scripts/tr_ai_script.py` disassembled the scripts, and can regenerate them and the macros:

```sh
python3 tools/scripts/tr_ai_script.py disasm extract/b2_us/files/a/1/6/9 data/tr_ai
python3 tools/scripts/tr_ai_script.py inc include/asm/tr_ai.inc
```

The disassembler follows the jumps from the start of each script. Bytes it does not reach are decoded as commands
where they are valid, then as lists, and otherwise kept as `.byte`. Script 12 does not decode with this game's
commands. Its first command, 62, reads no arguments here, and the bytes after it are kept as they are.

## Versions

Black 2 is the primary version. White 2 is the same program: of its 41,423 functions, 41,311 are byte-identical to
Black 2's apart from relocations, and 112 differ. Every White 2 symbol with a Black 2 counterpart uses the Black 2 name,
so source files are shared, and code that differs uses the `BLACK2` and `WHITE2` defines. Symbols only found in White 2
get a `_w2_us` suffix.

`tools/scripts/version_map.py` pairs the functions of two versions by their bytes, and pairs other symbols through
relocations and section offsets. Functions that differ are marked `different` in `build/version_map.tsv`. Check them
with `compiler_probe.py --version w2_us`, which compiles with the `WHITE2` define, before marking a file complete.

## Names

Names come from the [swan](https://github.com/ds-pokemon-hacking/swan) symbol databases (GPL-3.0) by the
ds-pokemon-hacking community, revision `4324f73` (2025-07-03). `tools/scripts/import_swan.py` applies them:

- IDA-generated names are skipped.
- A name is only applied if a symbol starts exactly at its address.
- Names are carried between versions through the version map.
- Only default `func_`/`data_` names are replaced.

```sh
.venv/bin/python tools/scripts/version_map.py b2_us w2_us -o build/map_b2_w2.tsv --symbols-output build/map_b2_w2_symbols.tsv
.venv/bin/python tools/scripts/import_swan.py path/to/swan --map build/map_b2_w2.tsv --symbols-map build/map_b2_w2_symbols.tsv
```

Names that swan lacks are ours, and are recorded in `config/names.txt` by module and Black 2 address.
`tools/scripts/rename_symbol.py` renames a symbol in both versions, updates the source files and records the name:

```sh
.venv/bin/python tools/scripts/rename_symbol.py func_ov035_0217ed70 ElScoreboard_Create
```

### Code organization

- `struct_decls.h` declares every struct type once. The header of the module that owns a struct defines its layout
  when that is known, and other code only uses pointers to it.
- Headers are grouped like the game's code: `system/` (game system, game data, events), `field/`, `save/`, `gfl/`
  (Game Freak's library), `pml/` (Pokémon data), `battle/`, `demo/`, `nitro/` (NitroSDK), `dsprot/` and `constants/`.
- Each proc that an event starts has a header in `app/` with its parameter struct, proc table and overlay ID, such as
  `app/worldtrade.h`. Each event has a header in `field/` with its create functions, such as
  `field/event_worldtrade.h`.
- A struct that only one file uses, such as an event's work, is defined in that file. Functions only called within
  their file are declared at the top of it, since `-requireprotos` requires a prototype for every function.
- Event callbacks take `void *data`, as `GameEventCallback` does, and cast it to their work.
- Names, layouts and constants from swan are marked as such. swan's headers are generated for hacking tools, so
  they are a reference rather than copied as they are.

`ninja format` formats `src/` and `include/` with clang-format, using `.clang-format`. `compile_flags.txt` makes
clangd check the code as 32-bit ARM.

### Fixing the configs

dsd sometimes cannot tell which overlay a relocation points to, because many overlays share addresses. It then lists
every candidate, such as `module:overlays(36,214)`, and the build links to the first one, which gives the right bytes
but the wrong symbol. `tools/scripts/config_fixes.py` fixes such relocations and other mistakes in both versions, and
records them in `config/fixes.txt`:

```sh
.venv/bin/python tools/scripts/config_fixes.py reloc-module overlays/ov004 'overlay(214)' 0x0214f6c0
.venv/bin/python tools/scripts/config_fixes.py overlay-id overlays/ov004 214 0x0214f6bc
```

It also removes relocations and symbols that are not real (`remove-reloc`, `remove-symbol`).

## Regenerating configs

After improving dsd's analysis, regenerate the configs of both versions and import the names again:

```sh
.venv/bin/python tools/scripts/regenerate_configs.py path/to/swan
```

This keeps the source files listed in each `delinks.txt`, but loses any other manual changes to the configs. It runs
the following command once per version:

```sh
tools/dsd init --rom-config extract/b2_us/config.yaml --output-path config/b2_us --build-path build/b2_us \
    --allow-unknown-function-calls
```

The fixes in `config/fixes.txt` and the names from swan and `config/names.txt` are applied again afterwards, so only
changes made to the configs by hand are lost.

## License

This project is licensed under the GNU General Public License v3.0, see [LICENSE](LICENSE). The symbol names imported
from swan are also GPL-3.0.

The repository contains no game code or assets. Building it requires your own dump of the game.
