# Nonmatching functions

This tracks every function currently implemented in C whose compiled code does not match the original ROM, plus functions with an attempted C translation that remains in the original assembly. Assembly that has not yet been translated is outside this list. Addresses below are for Black 2 unless both versions are shown.

## C implementations that do not match

| Overlay | Function | Source | Black 2 / White 2 | Current difference |
| --- | --- | --- | --- | --- |
| 33 | `EventFieldTrade_CreatePkm` | `src/ov033/event_field_trade_pkm.c` | `0x0217a590` / `0x0217a5d0` | The C translation matches the original size and all instructions after the first two setup calls, but CodeWarrior schedules their argument loads and stores differently (40 nonrelocated bytes). The file is marked incomplete, so the ROM retains the original assembly. |
| 59 | `func_ov059_021e6630` | `src/ov059/scrcmd_resort.c` | `0x021e6630` / `0x021e6670` | Four nonrelocated bytes with DSi 1.1p1. The original keeps zero in `r5` for the last stack argument and return; the current C emits `movs r0, #0` twice. DSi 1.1–1.3 and many zero-local and expression variants retain the mismatch; DSi 1.6 is worse. |
| 59 | `func_ov059_021e6fc8` | `src/ov059/scrcmd_resort.c` | `0x021e6fc8` / `0x021e7008` | The current C compiles to `0x460` bytes with DSi 1.1–1.2, while the original is `0x464`. The large message selection switch has a different branch and jump table layout. Inverting or rewriting its final comparison as a ternary does not fix the size. |
| 284 | `ShinkaDemoPieces_Move` | `src/ov284/shinka_demo_view.c` | `0x021e69c4` / `0x021e6a04` | Eleven nonrelocated bytes with DSi 1.1p1. Differences include stack slot assignment within the large state switch and two Thumb instruction sequences. |

These source files lack `complete` in both versions' `delinks.txt`. `compiler_probe.py` reproduces the differences for both versions. The full ROMs still rebuild byte for byte because the linker retains the original bytes for these functions.

## C translations attempted, still in assembly

| Overlay | Function | Black 2 / White 2 | Current obstacle |
| --- | --- | --- | --- |
| 12 | `TrimPartyTo3Members` | `0x02150460` / `0x021504a0` | Natural loop forms compile to `0x20` bytes; the original is `0x22` and copies the party argument into `r7` before removal. Tested DSi 1.1 through 1.6 and 2.0 variants, declaration and loop changes, and decomp-permuter variants without a match. |
| 12 | `ProcessMapMatrix` | `0x02154c00` / `0x02154c40` | The closest C translation is `0x74` bytes, while the original is `0x78`. Const and nonconst input, field reload, and local count variants did not match. The surrounding matrix helpers match; this function remains in assembly. |
| 33 | `EntreeForest_SpawnPkmActor` | `0x02176b00` / `0x02176b40` | The current unlinked translation has the original `0xa4` byte size but differs in ten nonrelocated bytes from instruction scheduling around the table index and actor ID. Declaration order, table expressions, parameter widths and compiler versions have not resolved it. |
| 33 | `s00C8_CallDiving` | `0x02178570` / `0x021785b0` | The natural C translation has the original `0x54` byte size, but CodeWarrior assigns `vm` and the script work to the opposite callee saved registers. A stack saved environment pointer reduces the mismatch to four nonrelocated bytes. The preceding five field move script functions match in C; this function remains in assembly. |
| 33 | `EventFieldFishing_Create` | `0x0217928c` / `0x021792cc` | The closest DSi 1.1 C translation is `0x128` bytes versus the original `0x12c`. It swaps the field and game system registers and branches differently around terrain flags. The candidate remains in assembly. |
| 36 | `FieldDispControl_ReqSetAlphaA` | `0x021c80a8` / `0x021c80e0` | Natural C field assignments compile to `0x10` bytes versus the original `0x14`; the original saves `r4` and loads the fifth argument after a two-register push. DSi 1.1 through 1.6 retain the shorter form. |
| 36 | `FieldDispControl_ReqSetAllA` | `0x021c80bc` / `0x021c80f4` | Natural C field assignments compile to `0x14` bytes versus the original `0x18`; stack argument and constant scheduling differ. DSi 1.1 through 1.6 retain the shorter form. |
| 36 | `FieldDispControl_ReqSetAlphaB` | `0x021c80e0` / `0x021c8118` | Natural C field assignments compile to `0x10` bytes versus the original `0x14`, with the same saved register and fifth-argument scheduling difference as `ReqSetAlphaA`. |
| 36 | `FieldPalaceSys_InitPostFX` | `0x021c8248` / `0x021c8280` | An unlinked translation has the original `0x7c` byte size; the closest DSi 1.1p1 probe still differs in 13 instruction bytes, mainly the order of parameter spills and the final five-argument call. The adjacent create/free/accessor functions match. |
| 36 | `FieldLensFlareData_BytesToEntryCount` | `0x021c8860` / `0x021c8898` | The C division matches both standalone compiler probes, but linking it creates a Black 2 runtime thunk that shifts ARM9 main and many overlay relocations. The original assembly remains linked; adjacent lens flare helpers match when linked separately. |
| 167 | `GetIllusionDisguise` | `0x0219cc58` / `0x0219cc98` | The natural C translation differs by five nonrelocated bytes because CodeWarrior assigns the loop count and index to opposite registers. The neighboring switch mode functions match; this function remains in assembly. |
| 167 | `GetSideFromMonID` | `0x0219d31c` / `0x0219d35c` | A direct C translation has the original `0x10` byte size, but its branch layout differs. The adjacent `IsAllyMonID` and `GetSideFromOpposingMonID` now match in C; this function remains in assembly. |
| 167 | `ActionOrder_SearchByMoveID` | `0x021a0544` / `0x021a0584` | A typed entry array loop compiles to `0x4c` bytes versus the original `0x68` because CodeWarrior stages the stack and loop address differently. The attempt remains in assembly. |
| 167 | `BattleHandler_AbilityPopupAdd` | `0x021ac7fc` / `0x021ac83c` | The C source matches both standalone compiler probes, but linking it causes a duplicate ARM/Thumb cross-overlay thunk at `0x021ac84c` and changes overlay 167. The original assembly remains linked; `BattleHandler_AbilityPopupRemove` matches when linked separately. |
| 167 | `BattleHandler_EffectAtPos` | `0x021ae214` / `0x021ae254` | The current unlinked translation has the original `0x3c` byte size, but ten instruction bytes differ because CodeWarrior loads and stores call arguments in a different order before `ServerControl_ViewEffect`. |
| 167 | `BattleHandler_ForceSwitch` | `0x021ade58` / `0x021ade98` | The current unlinked DSi 1.1p1 translation compiles to `0x5a` bytes versus the original `0x56`; stack argument evaluation and nibble extraction differ. |
| 167 | `BattleHandler_UpdateMove` | `0x021ada4c` / `0x021ada8c` | A size-correct DSi 1.1p1 translation differs in 21 instruction bytes from argument loads and stores around two calls with five or more arguments. |

## Keeping this list current

After changing a source file, run `compiler_probe.py` for both `b2_us` and `w2_us`. Add or update a row for each function the probe reports as a mismatch. A file should receive `complete` in both versions' `delinks.txt` only when all its functions match. The Black 2 build report at `build/b2_us/report.json` helps find candidates, but a `fuzzy_match_percent` below 100 is not sufficient by itself: `BSubwayCmd_Tool` and `ShinkaDemo_Main` have lower fuzzy scores because of relocations, while the compiler probe and linked ROMs match. Remove rows when the functions match and the complete ROM builds pass.
