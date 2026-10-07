#ifndef POKEBW2_APP_MONOLITH_H
#define POKEBW2_APP_MONOLITH_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// Overlay 143, the Entralink monolith (monolith_main.c and the files in app/monolith/)
#define OVERLAY_MONOLITH OVERLAY_ID(143)

typedef struct {
    GameSystem *gsys;
    u8 unk04[0x28];
    // Read from the Entralink's save, then byte 2 set
    u8 unk2C[4];
    u8 unk30;
    u8 unk31;
} MonolithParam;

extern const GameProcFunctions MONOLITH_PROC_FUNCTIONS;

#endif // POKEBW2_APP_MONOLITH_H
