#ifndef POKEBW2_APP_MB_PARENT_H
#define POKEBW2_APP_MB_PARENT_H

#include "types.h"
#include "gfl/proc.h"

// The parent of a DS Download Play session (ov181, mb_parent_sys.c), which the start menu's unnamed item starts
typedef struct {
    u8 unk0;
    u8 unk1[7];
} MBParentParam;

extern const GameProcFunctions MB_PARENT_PROC_FUNCTIONS;

#endif // POKEBW2_APP_MB_PARENT_H
