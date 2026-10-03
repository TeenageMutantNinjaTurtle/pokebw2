# Nonmatching functions

This tracks every function currently implemented in C whose compiled code does not match the original ROM, plus functions with an attempted C translation that remains in the original assembly. Assembly that has not yet been translated is outside this list. Addresses below are for Black 2 unless both versions are shown.

## C implementations that do not match

| Overlay | Function | Source | Black 2 / White 2 | Current difference |
| --- | --- | --- | --- | --- |
| 33 | `EventFieldTrade_CreatePkm` | `src/ov033/event_field_trade_pkm.c` | `0x0217a590` / `0x0217a5d0` | The C translation matches the original size and all instructions after the first two setup calls, but CodeWarrior schedules their argument loads and stores differently (40 nonrelocated bytes). The file is marked incomplete, so the ROM retains the original assembly. |
| 59 | `func_ov059_021e6630` | `src/ov059/scrcmd_resort.c` | `0x021e6630` / `0x021e6670` | Four nonrelocated bytes with DSi 1.1p1. The original keeps zero in `r5` for the last stack argument and return; the current C emits `movs r0, #0` twice. DSi 1.1–1.3 and many zero-local and expression variants retain the mismatch; DSi 1.6 is worse. |
| 284 | `ShinkaDemoPieces_Move` | `src/ov284/shinka_demo_view.c` | `0x021e69c4` / `0x021e6a04` | Eleven nonrelocated bytes with DSi 1.1p1. Differences include stack slot assignment within the large state switch and two Thumb instruction sequences. |

These source files lack `complete` in both versions' `delinks.txt`. All other functions in those files match in the Black 2 build report. `compiler_probe.py` reproduces the differences for both versions. The full ROMs still rebuild byte for byte because the linker retains the original bytes for these functions.

## C translations attempted, still in assembly

| Overlay | Function | Black 2 / White 2 | Current obstacle |
| --- | --- | --- | --- |
| 12 | `TrimPartyTo3Members` | `0x02150460` / `0x021504a0` | Natural loop forms compile to `0x20` bytes; the original is `0x22` and copies the party argument into `r7` before removal. Tested DSi 1.1 through 1.6 and 2.0 variants, declaration and loop changes, and decomp-permuter variants without a match. |
| 33 | `s00C8_CallDiving` | `0x02178570` / `0x021785b0` | The natural C translation has the original `0x54` byte size, but CodeWarrior assigns `vm` and the script work to the opposite callee saved registers. A stack saved environment pointer reduces the mismatch to four nonrelocated bytes. The preceding five field move script functions match in C; this function remains in assembly. |
| 167 | `GetIllusionDisguise` | `0x0219cc58` / `0x0219cc98` | The natural C translation differs by five nonrelocated bytes because CodeWarrior assigns the loop count and index to opposite registers. The neighboring switch mode functions match; this function remains in assembly. |
| 167 | `GetSideFromMonID` | `0x0219d31c` / `0x0219d35c` | A direct C translation has the original `0x10` byte size, but its branch layout differs. The adjacent `IsAllyMonID` and `GetSideFromOpposingMonID` now match in C; this function remains in assembly. |

## Keeping this list current

After changing a source file, run `compiler_probe.py` for both `b2_us` and `w2_us`. Add or update a row for each function the probe reports as a mismatch. A file should receive `complete` in both versions' `delinks.txt` only when all its functions match. The Black 2 build report at `build/b2_us/report.json` helps find candidates, but a `fuzzy_match_percent` below 100 is not sufficient by itself: `BSubwayCmd_Tool` and `ShinkaDemo_Main` have lower fuzzy scores because of relocations, while the compiler probe and linked ROMs match. Remove rows when the functions match and the complete ROM builds pass.
