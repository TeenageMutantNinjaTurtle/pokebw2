#ifndef POKEBW2_PML_PERSONAL_H
#define POKEBW2_PML_PERSONAL_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// Species data

#define PERSONAL_TYPE_1 6
#define PERSONAL_TYPE_2 7
#define PERSONAL_ABILITY_1 26
#define PERSONAL_ABILITY_2 27
#define PERSONAL_ABILITY_HIDDEN 28
#define PERSONAL_SEX_RATIO 20
#define PERSONAL_HATCH_CYCLES 21
#define PERSONAL_FORM_COUNT 32

u32 PML_PersonalGetParamSingle(u16 species, u16 form, u32 param);
void *PML_PersonalLoad(u16 species, u16 form, HeapID heapId);
u32 PML_PersonalGetParam(void *personal, u32 param);
void PML_PersonalFree(void *personal);
// The moves a species learns by level, pairs of move and level that end with two 0xffff
void PML_LearnsetLvUpLoad(u16 species, u8 form, void *dest);
// Allocates the regional Pokédex's order of species
u16 *PML_PersonalLoadRegionalDexTable(HeapID heapId, u32 a1);
// The experience a Pokémon of the species needs for the level
u32 PML_UtilGetPkmLvExp(u16 species, u16 form, u16 level);
// The regional Pokédex numbers, by national number. The caller frees the table
u16 *PML_PersonalLoadRegionalDexTable(HeapID heapId, u32 a1);

ArcTool *loadEvolutionFile(HeapID heapId);
BOOL func_02020bf0(ArcTool *evoFile, u16 species, u16 form, u16 index);

#endif // POKEBW2_PML_PERSONAL_H
