# Pokémon Black 2

A work-in-progress decompilation of Pokémon Black 2 (NDS, DSi-enhanced). The long-term goal is a PC port.

It builds the following ROM:

| Version | File | SHA1 |
| --- | --- | --- |
| USA/Europe (NDSi Enhanced) | `build/pokeblack2_us.nds` | `e51e6dfb8678a3d19dcd2a10691b96a569ca0abb` |

## Status

The ROM rebuilds byte for byte from delinked code. No code has been decompiled to C yet.

- 41,423 functions found by [dsd](https://github.com/AetiasHax/ds-decomp) in the ARM9, its 344 overlays, ITCM, DTCM, and the two TWL autoloads.
- The DSi-only ARM9i/ARM7i programs are extracted (decrypted) and rebuilt, but not analyzed yet.

## Setup

1. Build dsd with DSi hybrid ROM support. Until the changes are upstreamed, it comes from these forks, both on the
   `dsi-hybrid` branch:
   - `ds-rom`: DSi header, digests, modcrypt, TWL autoloads and DSi banners.
   - `ds-decomp`: TWL entrypoint, DS Protect and Thumb jump table fixes. Its `Cargo.toml` patches in `../ds-rom/lib`.

   ```sh
   cd ../ds-decomp && cargo build --release && cp target/release/dsd ../pokebw2/tools/dsd
   ```

2. Place your own dump of the game at `orig/baserom_b2_us.nds`. It must match the SHA1 above. It is not included and
   will not be provided.

3. Configure and build. `configure.py` downloads [wibo](https://github.com/decompals/wibo) and the Metrowerks
   CodeWarrior tools on first run.

   ```sh
   python3 configure.py
   ninja
   ```

   `ninja` extracts the base ROM, delinks the code, links it with `mwldarm`, rebuilds the ROM and checks its SHA1.

## Layout

| Path | Contents |
| --- | --- |
| `config/b2_us/` | dsd configs: sections (`delinks.txt`), symbols and relocations for every module |
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
- The compiler version for decompiled code is not verified yet. `configure.py` assumes `dsi/1.1`, the version
  used for Pokémon Black.

## Regenerating configs

The configs were generated with:

```sh
tools/dsd init --rom-config extract/b2_us/config.yaml --output-path config/b2_us --build-path build/b2_us \
    --allow-unknown-function-calls
```

Regenerating overwrites any symbol names and delinks added by hand.
