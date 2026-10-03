#ifndef POKEBW2_BATTLE_BATTLE_RESULT_H
#define POKEBW2_BATTLE_BATTLE_RESULT_H

#include "types.h"

BOOL IsBattleResultDefeat(u32 result, u32 battleType);
u32 GetWildBattleResultByCombined(u32 result);

#endif // POKEBW2_BATTLE_BATTLE_RESULT_H
