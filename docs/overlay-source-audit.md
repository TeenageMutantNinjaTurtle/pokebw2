# Overlay source organization audit

This audit covers every committed overlay C change after
`142e443858bae88ec7f81166778cd2969bd34805`. It checks source boundaries
against the original B2 and W2 `delinks.txt` ranges, plus the declaration rules
in [README.md](../README.md#code-organization).

| Overlays | Result |
| --- | --- |
| 012 | Contiguous field script, event, warp, party, and VM runs have been regrouped by feature. Separate features and ranges interrupted by assembly remain separate. |
| 033 | Contiguous Funfest, Mystery Gift, Chatot, PC, Dive, Subway, Trial House, money window, and other field feature runs have been regrouped. Unmatched instructions and distinct neighboring features still set source boundaries. |
| 035 | The three source files represent distinct features. Their private layouts now use named structs with declarations in `struct_decls.h`. |
| 036 | Contiguous prop, medal, and resource runs have been regrouped; remaining adjacent files serve distinct features or have assembly gaps. |
| 103–106 | Badge Gate and expansion object code has been grouped by contiguous feature range. Unmatched functions remain in assembly. |
| 167 | Contiguous battle handlers and ability families have been regrouped. Small exact wrappers separated by unmatched handlers remain separate source ranges. |
| 010, 013–018, 021, 073–074, 090, 093, 095, 126, 147, 152–153, 164 | Each changed feature already occupies a coherent source range. |
| 027 | Its five changed ranges are separated by substantial original assembly gaps. |
| 146 | Three adjacent encounter cut-in functions have been combined into one source range. |

The audit checked the existing changed C sources for source-local `extern`
declarations, anonymous struct typedefs, and named struct definitions missing
from `struct_decls.h`; none remain. The shared declarations changed during this
audit are in owning headers. A standalone compiler match is followed by a complete B2/W2 build,
because external relocations, data ranges, padding, and runtime helpers can
change the ROM even when a function's instructions match.

Unmatched translations and linker-level obstacles are tracked in
[nonmatching-functions.md](nonmatching-functions.md). The unrelated local
working files are outside this audit.
