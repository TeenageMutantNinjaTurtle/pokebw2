#ifndef POKEBW2_APP_BOX_SEARCH_H
#define POKEBW2_APP_BOX_SEARCH_H

#include "types.h"
#include "app/box2.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// The PC box's Pokémon search, a sub proc of the box in the same overlay. The ROM doesn't name its file;
// box_search.c is named after its box_search_graphic.c

typedef struct {
    u32 unk0;
    Box2SysWork *syswk;
    Box2Param *param;
} BoxSearchParam;

extern const GameProcFunctions BOX_SEARCH_PROC_FUNCTIONS;

#endif // POKEBW2_APP_BOX_SEARCH_H
