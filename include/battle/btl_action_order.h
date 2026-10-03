#ifndef POKEBW2_BATTLE_BTL_ACTION_ORDER_H
#define POKEBW2_BATTLE_BTL_ACTION_ORDER_H

#include "types.h"
#include "struct_decls.h"

ActionOrderEntry *ActionOrder_SearchByMonID(ActionOrder *order, u8 monId);
ActionOrderEntry *ActionOrder_SearchByMoveID(ActionOrder *order, u16 moveId, u8 start);
s32 ActionOrderTool_Interrupt(ActionOrder *order, ActionOrderEntry *entry, u32 start);
void ActionOrderTool_SendToLast(ActionOrder *order, ActionOrderEntry *entry);

BOOL ActionOrder_InterruptReserve(ActionOrder *order, u8 monId);
BOOL ActionOrder_InterruptReserveByMove(ActionOrder *order, u16 moveId);
BOOL ActionOrder_SendToLast(ActionOrder *order, u8 monId);
void ActionOrder_ForceDone(ActionOrder *order, u8 monId);

#endif // POKEBW2_BATTLE_BTL_ACTION_ORDER_H
