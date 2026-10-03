#ifndef POKEBW2_APP_SUBWAY_MAP_H
#define POKEBW2_APP_SUBWAY_MAP_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// The subway map, overlay 317 (subway_map_graphic.c)
#define OVERLAY_SUBWAY_MAP OVERLAY_ID(317)

typedef struct {
    PlayerInfo *playerInfo;
} SubwayMapParam;

extern const GameProcFunctions data_ov317_0219d4c8;

#endif // POKEBW2_APP_SUBWAY_MAP_H
