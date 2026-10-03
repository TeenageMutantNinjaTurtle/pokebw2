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

Review of the 29 overlays changed since `142e443` continues against the
earlier process and subsystem boundaries, including owning headers, private
struct layouts, original data placement, and exact B2/W2 ROM hashes. Unmatched
functions remain tracked in [nonmatching-functions.md](nonmatching-functions.md).

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

The follow-up review found mixed process code in overlay 12's menu, event
data, and zone/Pokédex sources; overlay 103's badge gate sources; and three
battle ability sources in overlay 167. Their process boundaries were restored.
Overlay 33's final Battle Subway helper and trade debug stub and overlay 36's
prop-holder release now sit with adjacent helpers from the same feature.
File-private work layouts in overlays 103, 104, and 146 were moved to their
owning C files. These changes were checked against both original ROMs.
Later matches closed gaps in overlay 12's zone positioning, overlay 33's Trial
House setup and Battle Subway score handling, overlay 36's prop sound check,
and overlay 167's Damp and Truant handlers. Their newly continuous ranges
were combined within their owning features. Attempted translations for
remaining assembly gaps are tracked in
[nonmatching-functions.md](nonmatching-functions.md).
