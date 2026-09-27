# Pokémon Black 2 and White 2

A work-in-progress decompilation of Pokémon Black 2 and White 2 (NDS, DSi-enhanced). The long-term goal is a PC port.

It builds the following ROMs:

| Version | File | SHA1 |
| --- | --- | --- |
| Black 2, USA/Europe (NDSi Enhanced) | `build/pokeblack2_us.nds` | `e51e6dfb8678a3d19dcd2a10691b96a569ca0abb` |
| White 2, USA/Europe (NDSi Enhanced) | `build/pokewhite2_us.nds` | `b5d7490be7b415b8f1e672a53e978a9cc667e56a` |

## Status

Both ROMs rebuild byte for byte from the same source tree. Overlay 4 is decompiled to C, and everything else is still
delinked code.

- 41,423 functions found by [dsd](https://github.com/AetiasHax/ds-decomp) in the ARM9, its 344 overlays, ITCM, DTCM, and the two TWL autoloads.
- 8,152 functions and 573 data symbols have real names, imported from [swan](#names).
- The DSi-only ARM9i/ARM7i programs are extracted (decrypted) and rebuilt, but not analyzed yet.

## Setup

1. Build dsd with DSi hybrid ROM support. Until the changes are upstreamed, it comes from these forks, both on the
   `dsi-hybrid` branch:
   - `ds-rom`: DSi header, digests, modcrypt, TWL autoloads and DSi banners.
   - `ds-decomp`: TWL entrypoint, DS Protect and Thumb jump table fixes. Its `Cargo.toml` patches in `../ds-rom/lib`.

   ```sh
   cd ../ds-decomp && cargo build --release && cp target/release/dsd ../pokebw2/tools/dsd
   ```

2. Place your own dumps at `orig/baserom_b2_us.nds` and/or `orig/baserom_w2_us.nds`. They must match the SHA1s above.
   They are not included and will not be provided. `tools/scripts/verify_dsi_rom.py` checks a dump against the
   digests in its own header.

3. Configure and build. `configure.py` downloads [wibo](https://github.com/decompals/wibo) and the Metrowerks
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
- The DSi-only "LTD main" code in ARM9i is loaded to `0x02700000` at runtime, and ARM9 main calls into it.

## Known gaps

- LTD main (`0x02700000`–`0x0276aee0`) is not a dsd module yet, so 5 calls from ARM9 main into it and 6 calls through
  veneers have no relocation. Matching is unaffected, but these calls would break if code moved.
- 4 local calls lead to functions dsd did not discover. They got placeholder symbols.

## Compiler

The game was built with CodeWarrior for DSi, a version between `dsi/1.1` and `dsi/1.3p1`:

- `dsi/1.6sp1` and `dsi/1.6sp2` do not match overlay 4's switch statement.
- `dsi/1.1` through `dsi/1.3p1` produce identical code for every game function and synthetic test tried so far.
  `configure.py` uses `dsi/1.1`, the version used for Pokémon Black.

`tools/scripts/compiler_probe.py` compiles a C file with every version and compares each function against the
game, ignoring relocated bytes. For example:

```sh
.venv/bin/python tools/scripts/compiler_probe.py tools/compiler_tests/main_loops.c
```

It needs `pyelftools`, `capstone` and `pyyaml`. To look at a function's disassembly, run `dsd dis` into
`build/asm`, then use `tools/scripts/show_func.py`.

## Versions

Black 2 is the primary version. White 2 is the same program: of its 41,423 functions, 41,311 are byte-identical to
Black 2's apart from relocations, and 112 differ. Every White 2 symbol with a Black 2 counterpart uses the Black 2 name,
so source files are shared, and code that differs uses the `BLACK2` and `WHITE2` defines. Symbols only found in White 2
get a `_w2_us` suffix.

`tools/scripts/version_map.py` pairs the functions of two versions by their bytes, and pairs other symbols through
relocations and section offsets.

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

## Regenerating configs

The configs were generated with the following command, once per version:

```sh
tools/dsd init --rom-config extract/b2_us/config.yaml --output-path config/b2_us --build-path build/b2_us \
    --allow-unknown-function-calls
```

Regenerating overwrites any symbol names and delinks added by hand, so the names must be imported again afterwards.

## License

This project is licensed under the GNU General Public License v3.0, see [LICENSE](LICENSE). The symbol names imported
from swan are also GPL-3.0.

The repository contains no game code or assets. Building it requires your own dump of the game.
