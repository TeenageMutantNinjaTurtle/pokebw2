#ifndef POKEBW2_BATTLE_BTL_EVENT_H
#define POKEBW2_BATTLE_BTL_EVENT_H

#include "struct_decls.h"
#include "types.h"

void BattleEventItem_ConvertToIsolated(BattleEventItem *item);
BOOL BattleEventItem_IsIsolated(BattleEventItem *item);
u16 BattleEventItem_GetSubID(BattleEventItem *item);
u8 HandlerGetMainModule(BattleEventItem *handler);
u32 BattleEventItem_GetWorkValue(BattleEventItem *item, u32 index);
void BattleEventItem_SetTempItemFlag(BattleEventItem *item);
void BattleEventItem_SetRecallEnable(BattleEventItem *item);
void BattleEventItem_SetWorkValue(BattleEventItem *item, u32 index, u32 value);

#endif // POKEBW2_BATTLE_BTL_EVENT_H
