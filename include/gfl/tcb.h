#ifndef POKEBW2_GFL_TCB_H
#define POKEBW2_GFL_TCB_H

#include "types.h"
#include "gfl/heap.h"

// Tasks that run every frame or every VBlank. Names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

typedef struct TCB TCB;
typedef struct TCBManager TCBManager;
typedef struct TCBExManager TCBExManager;

typedef void (*TCBFunc)(TCB *tcb, void *data);
typedef void (*VBlankCallback)(void *data);

TCB *GFL_VBlankTCBAdd(TCBFunc func, void *data, u32 priority);
BOOL GFL_TCBRemove(TCB *tcb);
TCB *GFL_TCBMgrAddTask(TCBManager *manager, TCBFunc func, void *data, u32 priority);
TCBManager *GFL_VBlankGetTCBMgr(void);
// A single callback that runs every VBlank, for when the tasks cannot
BOOL GFL_VBlankSetCallback(VBlankCallback callback, void *data);
void GFL_VBlankResetCallback(void);

// A manager of count tasks, in a buffer of GFL_TCBMgrCalcAllocSize(count) bytes
u32 GFL_TCBMgrCalcAllocSize(u32 count);
TCBManager *GFL_TCBMgrCreate(u32 count, void *buffer);
void GFL_TCBMgrUpdate(TCBManager *manager);
void func_0203a610(TCBManager *manager);

TCBExManager *GFL_TCBExMgrCreate(HeapID heapId, u16 a1, u16 a2, u32 a3);
void GFL_TCBExMgrFree(TCBExManager *manager);
void GFL_TCBExMgrUpdate(TCBExManager *manager);

#endif // POKEBW2_GFL_TCB_H
