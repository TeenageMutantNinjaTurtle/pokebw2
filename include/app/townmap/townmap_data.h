#ifndef POKEBW2_APP_TOWNMAP_TOWNMAP_DATA_H
#define POKEBW2_APP_TOWNMAP_TOWNMAP_DATA_H

#include "types.h"
#include "gfl/heap.h"

// townmap_data.c: the town map's table of places, archive 85, which townmap.c reads and overlays 298 (the Pokédex's
// habitat map), 303 and 308 (a beacon's details) load too. The ROM doesn't name the file; the name is a guess. The
// function names are ours

#define TOWNMAP_PLACE_COUNT 85
// What TownMapData_GetPlaceByZone returns for a zone that is no place on the map
#define TOWNMAP_PLACE_NONE 0xffff

// A place's parameters, as TownMapData_GetParam reads them
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
    // Each place is this many u16s
    TOWNMAP_PARAM_COUNT
};

#define TOWNMAP_PLACE_TYPE_TOWN 4
#define TOWNMAP_NO_FLAG 0xffff

// Reads the table of places, and frees it
void *TownMapData_Load(HeapID heapId);
void TownMapData_Free(void *data);
// A TOWNMAP_PARAM_* of a place
u16 TownMapData_GetParam(void *data, u16 place, u16 param);
// The place whose TOWNMAP_PARAM_ZONE is zone, or TOWNMAP_PLACE_NONE
u16 TownMapData_GetPlaceByZone(void *data, u16 zone);

#endif // POKEBW2_APP_TOWNMAP_TOWNMAP_DATA_H
