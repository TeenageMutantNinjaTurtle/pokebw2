#ifndef POKEBW2_BATTLE_BTL_ITEM_H
#define POKEBW2_BATTLE_BTL_ITEM_H

#include "types.h"
#include "struct_decls.h"

void *ItemEvent_TempAdd(BattleMon *mon, u16 item);
void func_ov167_021c27c4(void *temp);
void CommonRunCalcSkip(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work);

#endif // POKEBW2_BATTLE_BTL_ITEM_H
