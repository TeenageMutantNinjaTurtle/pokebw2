#ifndef POKEBW2_FIELD_FIELD_PALACE_H
#define POKEBW2_FIELD_FIELD_PALACE_H

#include "types.h"
#include "gfl/heap.h"

typedef struct FieldPalaceSys {
    u32 unk00;
    u32 unk04;
    void *luminanceTable;
} FieldPalaceSys;

extern const char data_ov036_021d56fc[];

FieldPalaceSys *FieldPalaceSys_Create(HeapID heapId, u32 a1, u32 a2, u32 a3);
void FieldPalaceSys_InitPostFX(FieldPalaceSys *sys, u32 a1, HeapID heapId);
void FieldPalaceSys_Free(FieldPalaceSys *sys);
void *FieldPalaceSys_GetLuminanceTable(FieldPalaceSys *sys);

#endif // POKEBW2_FIELD_FIELD_PALACE_H
