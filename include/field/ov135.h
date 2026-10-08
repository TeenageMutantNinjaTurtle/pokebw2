#ifndef POKEBW2_FIELD_OV135_H
#define POKEBW2_FIELD_OV135_H

#include "types.h"
#include "app/p_status.h"
#include "app/pokelist.h"
#include "struct_decls.h"

// The gimmick of the Pokémon World Tournament's entrance (zone 192, overlay 135), which script plugin 6 drives

void func_ov135_021ef904(WbtSystem *sys, GameData *gameData);
// The Battle Points for winning the tournament
u8 func_ov135_021ef978(WbtSystem *sys);
u32 func_ov135_021ef9e8(WbtSystem *sys, GameData *gameData);
void func_ov135_021efa2c(WbtSystem *sys, GameData *gameData);
// Takes the picks from overlay 22's party screen
void func_ov135_021efaa8(WbtSystem *sys, PokeListParam *param);
// The party the player enters the tournament with
PokeParty *func_ov135_021efb04(WbtSystem *sys, GameData *gameData);
// Copies the Battle Box's party, if it has one, to the system
void func_ov135_021efb34(WbtSystem *sys, GameData *gameData);
// Fill in overlay 22's party screen and summary screen for picking the Pokémon to enter
void func_ov135_021efb60(WbtSystem *sys, GameData *gameData, PokeListParam *param);
void func_ov135_021efbb4(WbtSystem *sys, GameData *gameData, PStatusParam *param);

#endif // POKEBW2_FIELD_OV135_H
