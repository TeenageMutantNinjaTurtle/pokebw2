#ifndef POKEBW2_FIELD_MUSICAL_STAGE_SYS_H
#define POKEBW2_FIELD_MUSICAL_STAGE_SYS_H

// Overlay 12's musical_stage_sys.c: the proc that runs overlay 209's stage, and the Pokémon on it

#include "types.h"
#include "gfl/heap.h"
#include "gfl/proc.h"
#include "struct_decls.h"

struct MusicalStageParam {
    // Overlay 211's communication work
    void *comm;
    MusicalPoke *pokes[4];
    MusicalProgram *program;
    Ov210Work *ov210;
    u32 unk1C;
};

MusicalStageParam *func_ov012_02152218(HeapID heapId, void *comm);
void func_ov012_02152248(MusicalStageParam *param);
// Puts a Pokémon on the stage
void func_ov012_02152274(MusicalStageParam *param, u8 pos, MusicalPoke *poke);
void func_ov012_02152280(MusicalStageParam *param, u8 pos, u16 species, u8 form, u32 personality, u16 a5,
                         HeapID heapId);
void func_ov012_021522b0(MusicalStageParam *param, u8 pos, MusicalPoke *poke);
void func_ov012_021522bc(MusicalStageParam *param, u8 pos, u8 slot, u16 itemId, s16 a4, u8 a5);

extern GameProcFunctions data_ov012_0216dfe8;

// Overlay 209's stage (sta_acting.c), whose main function returns TRUE once the show has faded out
StaActing *StaActing_Init(MusicalStageParam *param, HeapID heapId);
void StaActing_Term(StaActing *stage);
BOOL StaActing_Main(StaActing *stage);

#endif // POKEBW2_FIELD_MUSICAL_STAGE_SYS_H
