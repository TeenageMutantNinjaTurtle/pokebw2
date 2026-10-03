#ifndef POKEBW2_APP_DEMO3D_H
#define POKEBW2_APP_DEMO3D_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// The 3D demos, overlay 293 (demo3d.c, demo3d_graphic.c and demo3d_engine.c)
#define OVERLAY_DEMO3D OVERLAY_ID(293)

// What a demo is started with, which CreateSeqLoadParam fills in
typedef struct {
    GameSystem *gsys;
    u32 demoId;
    u32 unk08;
    u8 param;
    u8 hour;
    u8 minute;
    u8 season : 7;
    u8 playerSex : 1;
    u8 unk10[8];
} Demo3DParam;

extern const GameProcFunctions data_ov293_021a3d6c;

#endif // POKEBW2_APP_DEMO3D_H
