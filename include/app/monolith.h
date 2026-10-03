#ifndef POKEBW2_APP_MONOLITH_H
#define POKEBW2_APP_MONOLITH_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// Overlay 143, whose file is monolith_tool.c
#define OVERLAY_MONOLITH OVERLAY_ID(143)

typedef struct {
    GameSystem *gsys;
    u8 unk04[0x28];
    // Read from the Entralink's save, then byte 2 set
    u8 unk2C[4];
    u8 unk30;
    u8 unk31;
} MonolithParam;

extern const GameProcFunctions data_ov143_0219fe70;

#endif // POKEBW2_APP_MONOLITH_H
