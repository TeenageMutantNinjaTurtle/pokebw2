#ifndef POKEBW2_BATTLE_BTL_SERVER_FLOW_H
#define POKEBW2_BATTLE_BTL_SERVER_FLOW_H

#include "types.h"
#include "constants/battle.h"
#include "struct_decls.h"
#include "battle/btl_server.h"

BtlServerFlow *func_ov167_0219f390(BtlServer *server, BtlMainModule *mainModule, BtlPokeCon *pokeCon,
                                   BtlServerCmdQueue *queue, u32 a4, HeapID heapId);
void func_ov167_0219f3f8(BtlServerFlow *serverFlow);
void func_ov167_0219f570(BtlServerFlow *serverFlow);
u8 func_ov167_0219f588(BtlServerFlow *serverFlow);
void func_ov167_0219f65c(BtlServerFlow *serverFlow);
u32 func_ov167_0219f66c(BtlServerFlow *serverFlow, BtlClientActions *clientActions);
void func_ov167_0219f748(BtlServerFlow *serverFlow);
u32 func_ov167_0219f754(BtlServerFlow *serverFlow, BtlClientActions *clientActions);
void func_ov167_0219f7a8(BtlServerFlow *serverFlow);
u32 func_ov167_0219f7b4(BtlServerFlow *serverFlow, BtlClientActions *clientActions);
u32 func_ov167_0219fdf4(BtlServerFlow *serverFlow);
BOOL func_ov167_0219fe24(BtlServerFlow *serverFlow);
BtlClientIDList *func_ov167_0219ffe4(BtlServerFlow *serverFlow);
u8 func_ov167_0219fff0(BtlServerFlow *serverFlow);
u32 func_ov167_021ac018(BtlServerFlow *serverFlow);

// The damage of a move, with the type effectiveness if withEffectiveness is set. damageRoll is USE_MIN_DAMAGE for the
// lowest random roll, or ROLL_FOR_DAMAGE for a random one
u32 AICalcDamage(BtlServerFlow *serverFlow, u8 attackerId, u8 defenderId, u16 move, BOOL withEffectiveness,
                 u32 damageRoll);
u16 GetTurnCounter(BtlServerFlow *serverFlow);
BattleMon *GetBattleMon(BtlServerFlow *serverFlow, u32 monId);
u32 func_ov167_021abb50(BtlServerFlow *serverFlow);
u32 CalcMoveEffectiveness(BtlServerFlow *serverFlow, u8 attackerId, u8 defenderId, u16 move);
u16 func_ov167_021abd08(BtlServerFlow *serverFlow, BattleMon *mon, BOOL a2);
u32 func_ov167_021abd10(BtlServerFlow *serverFlow, BattleMon *mon, BOOL a2);
u32 func_ov167_021abe10(BtlServerFlow *serverFlow, u8 pos, u32 sideEffect);
BOOL func_ov167_021abe34(BtlServerFlow *serverFlow, u8 pos, u32 a2);
BOOL ServerControl_HideTurnCancel(BtlServerFlow *handler, BattleMon *mon, u32 flag);
BOOL ServerControl_FlinchCore(BtlServerFlow *handler, BattleMon *mon, u8 flag);
BOOL ServerControl_SwitchInFillSlot(BtlServerFlow *handler, u8 target, u8 slot, u8 slotAgain, BOOL flag);
void ServerControl_AfterSwitchIn(BtlServerFlow *handler);
void ServerControl_SetMonCounter(BtlServerFlow *handler, BattleMon *mon, u8 counter, u8 value);
void ServerControl_CheckItemReaction(BtlServerFlow *handler, BattleMon *mon, u32 reaction);
void ServerControl_ChangeHeldItem(BtlServerFlow *handler, BattleMon *mon, u16 item, u8 flag);
BOOL ServerControl_UseHeldItem(BtlServerFlow *handler, BattleMon *mon);
BOOL ServerControl_EscapeSub(BtlServerFlow *handler, BattleMon *mon, u32 flag);
BOOL ServerControl_CheckMatchup(BtlServerFlow *handler);
BOOL func_ov167_021abeb4(BtlServerFlow *handler, u8 monIndex);
BOOL ServerControl_SwitchOut(BtlServerFlow *handler, BattleMon *mon, u8 flag);
BOOL ServerControl_FieldEffectCore(BtlServerFlow *handler, u32 effect, BattleCondition value, u8 duration);
void ServerControl_FieldEffectEnd(BtlServerFlow *handler, u32 effect);
BOOL ServerControl_DecrementPP(BtlServerFlow *handler, BattleMon *mon, u8 moveIndex, u8 amount);
BOOL ServerEvent_DecrementPP(BtlServerFlow *handler, BattleMon *mon, u8 moveIndex);
void ServerEvent_EquipTempItem(BtlServerFlow *handler, BattleMon *mon, u8 monIndex);
void ServerEvent_GastroAcidConfirmed(BtlServerFlow *handler, BattleMon *mon);
void ServerControl_MoveCore(BtlServerFlow *handler, u8 clientId, u8 firstSlot, u8 secondSlot, u32 flag);
void ServerControl_AfterMove(BtlServerFlow *handler, u8 clientId, u8 firstSlot, u8 secondSlot);
BOOL ServerControl_ChangeWeatherCheck(BtlServerFlow *handler, u8 weather, u8 duration);
void ServerControl_ChangeWeatherCore(BtlServerFlow *handler, u8 weather, u8 duration);
void ServerEvent_NotifyAirLock(BtlServerFlow *handler);
BOOL ServerEvent_CheckFloating(BtlServerFlow *handler, BattleMon *mon, u32 flag);
void ServerControl_CureCondition(BtlServerFlow *handler, BattleMon *mon, u32 condition, u32 flag);
u32 ServerEvent_CheckItemSet(BtlServerFlow *handler, BattleMon *mon, u16 item);
void ServerEvent_ItemSetFailed(BtlServerFlow *handler, BattleMon *mon);
void ServerEvent_ChangeAbilityAfter(BtlServerFlow *handler, u8 monIndex);
void ServerEvent_ChangeAbilityBefore(BtlServerFlow *handler, u8 monIndex, u16 oldAbility, u16 newAbility);
void ServerControl_UnnerveAction(BtlServerFlow *handler, BattleMon *mon);
BOOL ServerControl_DrainCore(BtlServerFlow *handler, BattleMon *mon, BattleMon *source, u16 amount);
BOOL ServerControl_CheckSimpleDamageEnabled(BtlServerFlow *handler, BattleMon *mon, u16 damage);
void ServerControl_ViewEffect(BtlServerFlow *handler, u16 effect, u8 arg1, u8 arg2, u32 flag1, u32 flag2);
void ServerControl_SimpleDamageCore(BtlServerFlow *handler, BattleMon *mon, u16 damage, BattleHandlerString *string);
void ServerControl_FaintPokemon(BtlServerFlow *handler, BattleMon *mon);

u8 func_ov167_021ab7fc(BtlServerFlow *flow);
u8 func_ov167_021ab804(BtlServerFlow *flow);
u8 func_ov167_021ab810(BtlServerFlow *flow);
u8 func_ov167_021ab81c(BtlServerFlow *flow);
u8 func_ov167_021ab828(BtlServerFlow *flow);
u8 func_ov167_021abc80(BtlServerFlow *flow, u32 arg1);
u32 func_ov167_021ae320(BtlServerFlow *flow);

#endif // POKEBW2_BATTLE_BTL_SERVER_FLOW_H
