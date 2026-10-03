#ifndef POKEBW2_BATTLE_BTL_MATH_H
#define POKEBW2_BATTLE_BTL_MATH_H

#include "types.h"

u32 fixed_round(u32 value, u32 ratio);
u32 GetRatioOverZero(u32 value, u32 ratio);
u32 BattleRandom(u32 max);
BOOL RollEffectChance(u32 chance);

#endif // POKEBW2_BATTLE_BTL_MATH_H
