#ifndef POKEBW2_BATTLE_BTL_FIELD_H
#define POKEBW2_BATTLE_BTL_FIELD_H

#include "types.h"

// The weather and field effects of the battle in progress
u32 GetFieldWeather(void);
u32 IsFieldEffectActive(u32 fieldEffect);

#endif // POKEBW2_BATTLE_BTL_FIELD_H
