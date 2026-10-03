#ifndef POKEBW2_BATTLE_BTL_SERVER_FLOW_H
#define POKEBW2_BATTLE_BTL_SERVER_FLOW_H

#include "types.h"
#include "constants/battle.h"
#include "struct_decls.h"

BOOL DoesSwitchModeNeedConfirming(BtlServerFlow *serverFlow);
u8 GetNextEnemyForSwitchMode(BtlServerFlow *serverFlow);
BOOL IsSwitchModeEnabled(const void *switchMode);

// The damage of a move, with the type effectiveness if withEffectiveness is set. damageRoll is USE_MIN_DAMAGE for the
// lowest random roll, or ROLL_FOR_DAMAGE for a random one
u32 AICalcDamage(BtlServerFlow *serverFlow, u8 attackerId, u8 defenderId, u16 move, BOOL withEffectiveness,
                 u32 damageRoll);
u16 GetTurnCounter(BtlServerFlow *serverFlow);
u32 CalcMoveEffectiveness(BtlServerFlow *serverFlow, u8 attackerId, u8 defenderId, u16 move);
u16 func_ov167_021abd08(BtlServerFlow *serverFlow, BattleMon *mon, BOOL a2);
u32 func_ov167_021abd10(BtlServerFlow *serverFlow, BattleMon *mon, BOOL a2);
u32 func_ov167_021abe10(BtlServerFlow *serverFlow, u8 pos, u32 sideEffect);
BOOL func_ov167_021abe34(BtlServerFlow *serverFlow, u8 pos, u32 a2);
BOOL ServerControl_HideTurnCancel(BattleHandler *handler, BattleMon *mon, u32 flag);
BOOL ServerControl_FlinchCore(BattleHandler *handler, BattleMon *mon, u8 flag);
BOOL ServerControl_SwitchInFillSlot(BattleHandler *handler, u8 target, u8 slot, u8 slotAgain, BOOL flag);
void ServerControl_AfterSwitchIn(BattleHandler *handler);
void ServerControl_SetMonCounter(BattleHandler *handler, BattleMon *mon, u8 counter, u8 value);
void ServerControl_CheckItemReaction(BattleHandler *handler, BattleMon *mon, u32 reaction);
void ServerControl_ChangeHeldItem(BattleHandler *handler, BattleMon *mon, u8 item, u8 flag);
BOOL ServerControl_UseHeldItem(BattleHandler *handler, BattleMon *mon);
BOOL ServerControl_EscapeSub(BattleHandler *handler, BattleMon *mon, u32 flag);
BOOL ServerControl_CheckMatchup(BattleHandler *handler);
BOOL func_ov167_021abeb4(BattleHandler *handler, u8 monIndex);
BOOL ServerControl_SwitchOut(BattleHandler *handler, BattleMon *mon, u8 flag);
void RequestChangePokemon(BtlServerFlow *serverFlow, u8 pos);
BOOL ServerControl_FieldEffectCore(BattleHandler *handler, u32 effect, BattleCondition value, u8 duration);
void ServerControl_FieldEffectEnd(BattleHandler *handler, u32 effect);
BOOL ServerControl_DecrementPP(BattleHandler *handler, BattleMon *mon, u8 moveIndex, u8 amount);
BOOL ServerEvent_DecrementPP(BattleHandler *handler, BattleMon *mon, u8 moveIndex);
void ServerEvent_EquipTempItem(BattleHandler *handler, BattleMon *mon, u8 monIndex);
void ServerEvent_GastroAcidConfirmed(BattleHandler *handler, BattleMon *mon);
void ServerControl_MoveCore(BattleHandler *handler, u8 clientId, u8 firstSlot, u8 secondSlot, u32 flag);
void ServerControl_AfterMove(BattleHandler *handler, u8 clientId, u8 firstSlot, u8 secondSlot);
BOOL ServerControl_ChangeWeatherCheck(BattleHandler *handler, u8 weather, u8 duration);
void ServerControl_ChangeWeatherCore(BattleHandler *handler, u8 weather, u8 duration);
void ServerEvent_NotifyAirLock(BattleHandler *handler);

#endif // POKEBW2_BATTLE_BTL_SERVER_FLOW_H
