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
