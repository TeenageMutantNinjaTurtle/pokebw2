#ifndef POKEBW2_APP_WIFIBATTLEMATCH_H
#define POKEBW2_APP_WIFIBATTLEMATCH_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

#define OVERLAY_WIFIBATTLEMATCH OVERLAY_ID(290)

typedef struct {
    GameData *gameData;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
} WifiBattleMatchParam;

extern const GameProcFunctions WIFIBATTLEMATCH_PROC_FUNCTIONS;

#endif // POKEBW2_APP_WIFIBATTLEMATCH_H
