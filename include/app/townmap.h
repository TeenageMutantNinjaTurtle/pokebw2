#ifndef POKEBW2_APP_TOWNMAP_H
#define POKEBW2_APP_TOWNMAP_H

#include "types.h"
#include "gfl/overlay.h"
#include "struct_decls.h"

// Overlay 144, the town map (townmap.c, townmap_grh.c, and townmap_data.c in app/townmap/, whose table of places other
// overlays load too)

#define OVERLAY_TOWNMAP OVERLAY_ID(144)

// From overlay 12, the field's: the zone a zone shows on the town map as, and whether the player has been to a place
// with the event flag of its TOWNMAP_PARAM_FLAG
u16 func_ov012_02160eb4(GameData *gameData, u16 zone);
BOOL func_ov012_02160f74(GameData *gameData, u16 flag);

#endif // POKEBW2_APP_TOWNMAP_H
