#ifndef POKEBW2_GFL_PROC_H
#define POKEBW2_GFL_PROC_H

// Names, layouts and constants from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

typedef BOOL (*GameProcFunc)(GameProc *proc, u32 *state, void *param, void *work);

struct GameProcFunctions {
    GameProcFunc init;
    GameProcFunc main;
    GameProcFunc exit;
};

GameProcManager *CreateGameProcManager(HeapID heapId);
void FreeGameProcManager(GameProcManager *manager);
BOOL GFL_ProcMgrUpdate(GameProcManager *manager);
void QueueGameProc(GameProcManager *manager, s32 overlayId, const GameProcFunctions *functions, void *param);

#endif // POKEBW2_GFL_PROC_H
