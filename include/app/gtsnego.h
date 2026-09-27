#ifndef POKEBW2_APP_GTSNEGO_H
#define POKEBW2_APP_GTSNEGO_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

#define OVERLAY_GTSNEGO OVERLAY_ID(195)

#define GTSNEGO_RESULT_RETRY_LOGIN 0
#define GTSNEGO_RESULT_EXIT 1

typedef struct {
    GameData *gameData;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    // Copies of the player's info
    PlayerInfo *playerInfo;
    PlayerInfo *playerInfo2;
    u8 unk1C[0x194];
    u32 result;
} GtsNegoParam;

extern const GameProcFunctions GTSNEGO_PROC_FUNCTIONS;

#endif // POKEBW2_APP_GTSNEGO_H
