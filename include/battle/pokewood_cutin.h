#ifndef POKEBW2_BATTLE_POKEWOOD_CUTIN_H
#define POKEBW2_BATTLE_POKEWOOD_CUTIN_H

// Overlay 167's pokewood_cutin.c (named by its string): the cut-ins of the Pokestar Studios movies

#include "types.h"
#include "battle/btl_main.h"
#include "struct_decls.h"

PokewoodCutin *func_ov167_021d5e1c(HeapID heapId);
void func_ov167_021d5e68(PokewoodCutin *cutin);
void func_ov167_021d5e90(PokewoodCutin *cutin);
BOOL func_ov167_021d5fc0(PokewoodCutin *cutin);
void func_ov167_021d5fc4(PokewoodCutin *cutin, const BtlScriptedRules *rules, s8 scene, u16 choice, u32 gender);
void func_ov167_021d5fe4(PokewoodCutin *cutin, BtlvCore *viewCore);
// unused is a debug flag the client passes, which the function ignores
BOOL func_ov167_021d5fe8(const BtlScriptedRules *rules, s8 scene, u8 result, u32 unused);

#endif // POKEBW2_BATTLE_POKEWOOD_CUTIN_H
