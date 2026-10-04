#ifndef POKEBW2_APP_ZUKAN_DETAIL_H
#define POKEBW2_APP_ZUKAN_DETAIL_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The Pokédex's detail screens, overlay 298: a Pokémon's info, its habitat map, its cry and its forms, with the bars
// at the top and bottom of the screens to switch between them

typedef struct ZukanDetailProcSys ZukanDetailProcSys;
typedef struct ZukanDetailCommon ZukanDetailCommon;

// zukan_detail_procsys.c: runs one of the pages

typedef BOOL (*ZukanDetailProcFunc)(ZukanDetailProcSys *sys, int *seq, void *param, void *work,
                                    ZukanDetailCommon *common);
typedef void (*ZukanDetailProcCommandFunc)(ZukanDetailProcSys *sys, int *seq, void *param, void *work,
                                           ZukanDetailCommon *common, int command);
typedef void (*ZukanDetailProcDrawFunc)(ZukanDetailProcSys *sys, int *seq, void *param, void *work,
                                        ZukanDetailCommon *common);

typedef struct {
    ZukanDetailProcFunc init;
    ZukanDetailProcFunc main;
    ZukanDetailProcFunc exit;
    // Called every frame with the touch bar's command
    ZukanDetailProcCommandFunc command;
    ZukanDetailProcDrawFunc draw;
} ZukanDetailProcFuncs;

struct ZukanDetailProcSys {
    const ZukanDetailProcFuncs *funcs;
    int seq;
    int subSeq;
    void *param;
    void *work;
};

ZukanDetailProcSys *ZukanDetailProcSys_Create(const ZukanDetailProcFuncs *funcs, void *param, HeapID heapId);
void ZukanDetailProcSys_Free(ZukanDetailProcSys *sys);
// Returns TRUE once the page has exited
BOOL ZukanDetailProcSys_Main(ZukanDetailProcSys *sys, ZukanDetailCommon *common);
void ZukanDetailProcSys_Command(ZukanDetailProcSys *sys, ZukanDetailCommon *common, int command);
void ZukanDetailProcSys_Draw(ZukanDetailProcSys *sys, ZukanDetailCommon *common);
void *ZukanDetailProcSys_AllocWork(ZukanDetailProcSys *sys, u32 size, HeapID heapId);
void ZukanDetailProcSys_FreeWork(ZukanDetailProcSys *sys);

#endif // POKEBW2_APP_ZUKAN_DETAIL_H
