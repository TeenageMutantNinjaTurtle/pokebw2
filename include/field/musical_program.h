#ifndef POKEBW2_FIELD_MUSICAL_PROGRAM_H
#define POKEBW2_FIELD_MUSICAL_PROGRAM_H

// Overlay 12's musical_program.c: the program of a show, which decides the points of each kind of prop and the
// Pokémon of the other performers

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

MusicalProgram *func_ov012_021522d8(HeapID heapId, Ov210Work *ov210, u16 shots);
void func_ov012_0215241c(MusicalProgram *program);
void func_ov012_02152424(HeapID heapId, MusicalProgram *program, MusicalStageParam *stage);
u8 func_ov012_0215250c(MusicalProgram *program, u8 kind);
u32 func_ov012_02152510(MusicalProgram *program);
void func_ov012_02152528(MusicalProgram *program, u32 value);
u32 func_ov012_02152548(MusicalProgram *program);
void func_ov012_02152558(MusicalProgram *program, u32 value);
u8 func_ov012_02152570(MusicalProgram *program);
void func_ov012_02152594(MusicalProgram *program, MusicalStageParam *stage, u8 pos, u8 cpu, HeapID heapId);
u8 func_ov012_02152614(MusicalProgram *program);
u8 func_ov012_0215261c(MusicalProgram *program);
u8 func_ov012_02152624(MusicalProgram *program, u8 cpu);
u8 func_ov012_02152634(MusicalProgram *program, u8 cpu);
u8 func_ov012_02152644(MusicalProgram *program, u8 kind);

#endif // POKEBW2_FIELD_MUSICAL_PROGRAM_H
