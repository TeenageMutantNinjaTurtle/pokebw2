#ifndef POKEBW2_FIELD_MUSICAL_DRESSUP_SYS_H
#define POKEBW2_FIELD_MUSICAL_DRESSUP_SYS_H

// Overlay 12's musical_dressup_sys.c: the proc that runs overlay 208's dressing room

#include "types.h"
#include "gfl/heap.h"
#include "gfl/proc.h"
#include "struct_decls.h"

typedef struct {
    // Overlay 211's communication work, or NULL
    void *comm;
    MusicalPoke *poke;
    MusicalSave *save;
} MusicalDressUpParam;

MusicalDressUpParam *func_ov012_02151f5c(HeapID heapId, MusicalPoke *poke, SaveControl *save);
void func_ov012_02151f88(MusicalDressUpParam *param);

extern GameProcFunctions data_ov012_0216dfc4;

// Overlay 208, the dressing room, which gets a copy of the parameter
void *func_ov208_021998c0(MusicalDressUpParam *param, HeapID heapId);
void func_ov208_02199a54(void *work);
void *func_ov208_02199b7c(void *work);

#endif // POKEBW2_FIELD_MUSICAL_DRESSUP_SYS_H
