# Overlay source organization audit

The reference for work after `142e443858bae88ec7f81166778cd2969bd34805`
is the repository's earlier source layout and its
[code organization rules](../README.md#code-organization). A source owns a
process or subsystem and its data. Adjacent `.text` ranges alone do not prove
that two functions belonged to one source file.

## Evidence from earlier commits

| Overlay | Adjacent sources retained separately before `142e443` |
| --- | --- |
| 035 | `event_mapchange.c`, `el_scoreboard.c`, `event_season_banner.c` |
| 055 | `scrcmd_wbt.c`, `wbt_system.c`, `wbt_tool.c`, `wbt_setup.c`, `wbt_party.c` |
| 137 | `resort_field.c`, `resort_people.c`, `resort_data_manager.c`, `resort_npc.c` |
| 162 | `title.c`, `startmenu.c`, `game_start.c`, `boot_screens.c`, `delete_save.c`, `save_control_intr.c` |
| 294 | Eight adjacent intro process and graphics sources |

Commit `0c453f1` explicitly split overlay 162 by process. Commit `4366e92`
introduced the five adjacent overlay 55 sources together. Overlay 35 also
shows why the distinction matters for byte matching: combining its three
sources changes palette order in `.rodata` and string and pointer order in
`.data`, despite standalone function probes matching.

## Current review

The address-only merge of 14 overlay 12 groups in `56da313` was reversed in
`02f4f26`. The uncommitted address-only merges in overlays 33, 36, and 167
were discarded. Their earlier feature-grouped sources and all independently
matched functions remain.

The review covers all 34 overlays whose source changed since `142e443`.
It checks process and subsystem boundaries, owning headers, private structs,
data placement, and exact B2/W2 ROM hashes. The table records the current
source organization; an assembly gap prevents joining C ranges until its
intervening function matches. Unmatched attempts are tracked in
[nonmatching-functions.md](nonmatching-functions.md).

| Overlay | Disposition |
| --- | --- |
| 010 | Single linked C source; no fragmented C ranges. |
| 012 | Related matrix, script-command, and zone helper ranges are grouped where continuous; `ProcessMapMatrix` and other intervening assembly still separate some ranges. |
| 013 | Single linked C source; no fragmented C ranges. |
| 014 | Single linked C source; no fragmented C ranges. |
| 015 | Single linked C source; no fragmented C ranges. |
| 016 | Single linked C source; no fragmented C ranges. |
| 017 | Single linked C source; no fragmented C ranges. |
| 018 | Single linked C source; no fragmented C ranges. |
| 021 | Single linked C source; no fragmented C ranges. |
| 027 | Survey probability, command, and popularity C ranges have four intervening assembly functions. |
| 033 | Trade, Trial House, Battle Subway, and field-event ranges preserve process boundaries; several same-process fragments still have intervening assembly. |
| 035 | Three adjacent event sources retain their separate process and data ownership; merging changes non-text section order. |
| 036 | Prop, zone, and lens-flare data C ranges are grouped within continuous owners; remaining nearby fragments have intervening assembly. Adjacent C pairs cross subsystem boundaries. |
| 059 | Adjacent Resort and medal script-command sources have separate ownership; two Resort functions still do not match. |
| 060 | Single linked C source; no fragmented C ranges. |
| 073 | Single linked C source; no fragmented C ranges. |
| 074 | Single linked C source; no fragmented C ranges. |
| 090 | Single linked C source; no fragmented C ranges. |
| 093 | Single linked C source; no fragmented C ranges. |
| 095 | Single linked C source; no fragmented C ranges. |
| 103 | Adjacent badge-check and last-gate sources represent separate event processes. |
| 104 | Gimmick core, event, list, roaming, and state C ranges have intervening assembly functions; private work layouts live with their owners. |
| 105 | Single linked C source; no fragmented C ranges. |
| 106 | Single linked C source; no fragmented C ranges. |
| 126 | Single linked C source; no fragmented C ranges. |
| 146 | Continuous encounter cut-in code is grouped; its private work layout lives in the source. |
| 147 | Single linked C source; no fragmented C ranges. |
| 152 | Single linked C source; no fragmented C ranges. |
| 153 | Single linked C source; no fragmented C ranges. |
| 162 | Six adjacent title, menu, start, boot, delete-save, and interrupt sources preserve process boundaries. |
| 164 | Single linked C source; no fragmented C ranges. |
| 167 | Battle handlers, ability handlers, and accessors preserve their owners; many related C ranges still have intervening assembly. |
| 284 | Adjacent evolution demo sources preserve graphics, view, and effect ownership; `ShinkaDemoPieces_Move` is nonmatching. |
| 294 | Eight adjacent intro process and graphics sources preserve their separate ownership. |

Overlay 33 embeds the original names `fld_trade.c`, `trial_house.c`, and
`bsubway_scr.c`. Its current trade, Trial House, and Battle Subway source
fragments are separate complete delink ranges around functions still linked
from assembly. A range without `complete` links its original assembly as a
whole, even if some functions in the corresponding C file match. dsd rejects
a second `.text` range under one source entry (`Section '.text' already
exists`); repeating the same source path produces the same object twice.
Therefore, separately linked C fragments across an assembly gap can only be
combined after the intervening function matches. As the gaps are translated,
combine adjacent fragments within their original process and keep trade,
Trial House, and Battle Subway separate. The helper at `0x0217b468` operates
on Battle Subway state and begins that process, even though the `bsubway_scr.c`
filename string is first referenced by the following function.
The remaining Trial House assembly gaps are `0x0217ad78–0x0217adbc` and
`0x0217b0b4–0x0217b2e4` in Black 2. The remaining Battle Subway gaps are
`0x0217b478–0x0217b664` and `0x0217c11c–0x0217c264`. C fragments on
either side stay separate until the intervening assembly matches.

The follow-up review found mixed process code in overlay 12's menu, event
data, and zone/Pokédex sources; overlay 103's badge gate sources; and three
battle ability sources in overlay 167. Their process boundaries were restored.
Overlay 33's final Battle Subway helper and trade debug stub and overlay 36's
prop-holder release now sit with adjacent helpers from the same feature.
File-private work layouts in overlays 103, 104, and 146 were moved to their
owning C files. These changes were checked against both original ROMs.
Later matches closed gaps in overlay 12's ScriptWork accessors, VM global
scripts, and zone positioning; overlay 33's Unity Tower visitors, Trial House
setup, and Battle Subway reward, score, and team-save handling; overlay 36's
field accessors, prop handle lookup, prop sound check, and lens-flare count; and
overlay 167's BattleCondition constructors, Damp, Truant, move-history, and
Pokémon type-pair helpers. Their newly continuous ranges were combined within
their owning features. Attempted translations for remaining assembly gaps are
tracked in
[nonmatching-functions.md](nonmatching-functions.md).
