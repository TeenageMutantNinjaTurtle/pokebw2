#ifndef POKEBW2_BATTLE_POKEWOOD_CUTIN_H
#define POKEBW2_BATTLE_POKEWOOD_CUTIN_H

// Overlay 167's pokewood_cutin.c (named by its string): the cut-ins of the Pokestar Studios movies

#include "types.h"
#include "battle/btl_main.h"
#include "struct_decls.h"

void func_ov167_021d5e90(void *cutin);
BOOL func_ov167_021d5fc0(void *cutin);
void func_ov167_021d5fc4(void *cutin, const BtlScriptedRules *rules, s8 scene, u16 arg3, u32 gender);
void func_ov167_021d5fe4(void *cutin, BtlvCore *viewCore);
BOOL func_ov167_021d5fe8(const BtlScriptedRules *rules, s8 scene, u8 arg2, u32 arg3);

#endif // POKEBW2_BATTLE_POKEWOOD_CUTIN_H
