#ifndef POKEBW2_BATTLE_BTL_DISPLAY_H
#define POKEBW2_BATTLE_BTL_DISPLAY_H

#include "types.h"
#include "struct_decls.h"

void func_ov167_021b1434(void *display, u32 event, u8 monId, ...);
u32 SCQUE_RESERVE_Pos(void *display, u32 event);
void func_ov167_021b14ec(void *display, u32 reserve, u32 event, u8 monIndex);
void func_ov167_021b15d0(void *display, u32 event, u32 message, ...);
void ServerDisplay_AbilityPopupAdd(BtlServerFlow *handler, BattleMon *mon);
void ServerDisplay_AbilityPopupRemove(BtlServerFlow *handler, BattleMon *mon);
void scPut_SetContFlag(BtlServerFlow *handler, BattleMon *mon, u32 flag);
void scPut_ResetContFlag(BtlServerFlow *handler, BattleMon *mon, u32 flag);
void ServerDisplay_SetTurnFlag(BtlServerFlow *handler, BattleMon *mon, u32 flag);
void ServerDisplay_UseHeldItem(BtlServerFlow *handler, BattleMon *mon);
void ServerDisplay_SimpleHP(BtlServerFlow *handler, BattleMon *mon, u32 amount, u32 flag);
void ServerDisplay_StandardMessage(BtlServerFlow *handler, u16 message, u32 count, u32 *args);
void ServerDisplay_SetMessage(BtlServerFlow *handler, u16 message, u32 count, u32 *args);
void ServerDisplay_StandardMessageEx(BtlServerFlow *handler, u16 message, u16 soundEffect, u32 count, u32 *args);
void ServerDisplay_SetMessageEx(BtlServerFlow *handler, u16 message, u16 soundEffect, u32 count, u32 *args);

// Command 0x18, with its arguments' types
static inline void BtlServerCmd_Put18(void *queue, u8 monId, u8 target, u8 result, u8 arg4, u16 move, u16 arg6) {
    func_ov167_021b1434(queue, 0x18, monId, target, result, arg4, move, arg6);
}

#endif // POKEBW2_BATTLE_BTL_DISPLAY_H
