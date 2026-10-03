#ifndef POKEBW2_BATTLE_BTL_FIELD_H
#define POKEBW2_BATTLE_BTL_FIELD_H

#include "types.h"
#include "struct_decls.h"

// The weather and field effects of the battle in progress
u32 GetFieldWeather(void);
u32 IsFieldEffectActive(u32 fieldEffect);
BOOL FieldStatusRemoveEffect(u32 effect);
u32 GetWeather(BtlServerFlow *serverFlow);

#endif // POKEBW2_BATTLE_BTL_FIELD_H
