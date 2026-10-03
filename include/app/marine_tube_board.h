#ifndef POKEBW2_APP_MARINE_TUBE_BOARD_H
#define POKEBW2_APP_MARINE_TUBE_BOARD_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// The Marine Tube's board, overlay 318 (marine_tube_board_graphic.c)
#define OVERLAY_MARINE_TUBE_BOARD OVERLAY_ID(318)

typedef struct {
    GameSystem *gsys;
    u16 unk04;
} MarineTubeBoardParam;

extern const GameProcFunctions data_ov318_0219d550;

#endif // POKEBW2_APP_MARINE_TUBE_BOARD_H
