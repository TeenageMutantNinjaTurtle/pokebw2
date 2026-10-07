#ifndef POKEBW2_APP_TOWNMAP_H
#define POKEBW2_APP_TOWNMAP_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/overlay.h"
#include "struct_decls.h"

// Overlay 144, the town map's data: a table of the places on the map, archive 85, which the Pokédex's habitat map loads
// too. None of its functions has a name yet

#define OVERLAY_TOWNMAP OVERLAY_ID(144)

#define TOWNMAP_PLACE_COUNT 85
// What func_ov144_0219f73c returns for a zone that is no place on the map
#define TOWNMAP_PLACE_NONE 0xffff

// A place's parameters, as func_ov144_0219f730 reads them
enum {
    TOWNMAP_PARAM_ZONE = 0,
    // Where it is
    TOWNMAP_PARAM_X = 2,
    TOWNMAP_PARAM_Y = 3,
    // Where the cursor points at it
    TOWNMAP_PARAM_CURSOR_X = 4,
    TOWNMAP_PARAM_CURSOR_Y = 5,
    // The capsule that a touch hits it in: a segment and its radius
    TOWNMAP_PARAM_HIT_START_X = 6,
    TOWNMAP_PARAM_HIT_START_Y = 7,
    TOWNMAP_PARAM_HIT_END_X = 8,
    TOWNMAP_PARAM_HIT_END_Y = 9,
    TOWNMAP_PARAM_HIT_RADIUS = 10,
    // TOWNMAP_PLACE_TYPE_*
    TOWNMAP_PARAM_TYPE = 11,
    // The event flag that shows it, or TOWNMAP_NO_FLAG
    TOWNMAP_PARAM_FLAG = 16,
    // Its area's animation and position on the Pokédex's map
    TOWNMAP_PARAM_AREA_ANIM = 24,
    TOWNMAP_PARAM_AREA_X = 25,
    TOWNMAP_PARAM_AREA_Y = 26,
};

#define TOWNMAP_PLACE_TYPE_TOWN 4
#define TOWNMAP_NO_FLAG 0xffff

// Loads the town map's data, and frees it
void *func_ov144_0219f718(HeapID heapId);
void func_ov144_0219f728(void *data);
// A TOWNMAP_PARAM_* of a place
u16 func_ov144_0219f730(void *data, u16 place, u16 param);
// The place of a zone, or TOWNMAP_PLACE_NONE
u16 func_ov144_0219f73c(void *data, u16 zone);

// From overlay 12, the field's: the zone a zone shows on the town map as, and whether the player has been to a place
// with the event flag of its TOWNMAP_PARAM_FLAG
u16 func_ov012_02160eb4(GameData *gameData, u16 zone);
BOOL func_ov012_02160f74(GameData *gameData, u16 flag);

#endif // POKEBW2_APP_TOWNMAP_H
