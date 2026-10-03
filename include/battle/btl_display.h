#ifndef POKEBW2_BATTLE_BTL_DISPLAY_H
#define POKEBW2_BATTLE_BTL_DISPLAY_H

#include "types.h"
#include "struct_decls.h"

void func_ov167_021b1434(void *display, u32 event, u8 monId, ...);
u32 SCQUE_RESERVE_Pos(void *display, u32 event);
void func_ov167_021b14ec(void *display, u32 reserve, u32 event, u8 monIndex);
void ServerDisplay_AbilityPopupAdd(BattleHandler *handler, BattleMon *mon);
void ServerDisplay_AbilityPopupRemove(BattleHandler *handler, BattleMon *mon);
void scPut_SetContFlag(BattleHandler *handler, BattleMon *mon, u32 flag);
void scPut_ResetContFlag(BattleHandler *handler, BattleMon *mon, u32 flag);
void ServerDisplay_SetTurnFlag(BattleHandler *handler, BattleMon *mon, u32 flag);
void ServerDisplay_UseHeldItem(BattleHandler *handler, BattleMon *mon);
void ServerDisplay_StandardMessage(BattleHandler *handler, u16 message, u32 count, u32 *args);
void ServerDisplay_SetMessage(BattleHandler *handler, u16 message, u32 count, u32 *args);
void ServerDisplay_StandardMessageEx(BattleHandler *handler, u16 message, u16 soundEffect, u32 count, u32 *args);
void ServerDisplay_SetMessageEx(BattleHandler *handler, u16 message, u16 soundEffect, u32 count, u32 *args);

#endif // POKEBW2_BATTLE_BTL_DISPLAY_H
