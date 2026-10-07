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

// The link that Unova Link runs in overlay 181. None of these has a name yet
void *func_ov181_021a039c(u32 a0);
void func_ov181_021a03c8(void *work);
void func_ov181_021a03f4(void *work);
void func_ov181_021a0418(void *work, u32 a1);
BOOL func_ov181_021a0460(void *work);
void func_ov181_021a0470(void *work, StrBuf *text, StrBuf *title);
u32 func_ov181_021a0484(void *work);
void *func_ov181_021a0488(void *work);

#endif // POKEBW2_APP_MB_PARENT_H
