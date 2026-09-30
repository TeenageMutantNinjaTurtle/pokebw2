#ifndef POKEBW2_GFL_TCB_H
#define POKEBW2_GFL_TCB_H

#include "types.h"
#include "gfl/heap.h"

// Tasks that run every frame or every VBlank. Names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

typedef struct TCB TCB;
typedef struct TCBManager TCBManager;
typedef struct TCBExManager TCBExManager;

typedef void (*TCBFunc)(TCB *tcb, void *data);

TCB *GFL_VBlankTCBAdd(TCBFunc func, void *data, u32 priority);
BOOL GFL_TCBRemove(TCB *tcb);
TCBManager *GFL_VBlankGetTCBMgr(void);

TCBExManager *GFL_TCBExMgrCreate(HeapID heapId, u16 a1, u16 a2, u32 a3);
void GFL_TCBExMgrFree(TCBExManager *manager);
void GFL_TCBExMgrUpdate(TCBExManager *manager);

#endif // POKEBW2_GFL_TCB_H
