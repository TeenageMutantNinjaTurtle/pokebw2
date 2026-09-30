#ifndef POKEBW2_APP_MB_PARENT_H
#define POKEBW2_APP_MB_PARENT_H

#include "types.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// The parent of a DS Download Play session (ov181, mb_parent_sys.c), which the start menu's unnamed item starts, and
// the Poké Transfer Lab for Poké Transfer
typedef struct {
    // 1 from the start menu, 0 from the Poké Transfer Lab
    u8 unk0;
    // Set by the Poké Transfer Lab
    GameData *gameData;
} MBParentParam;

extern const GameProcFunctions MB_PARENT_PROC_FUNCTIONS;

#endif // POKEBW2_APP_MB_PARENT_H
