#ifndef POKEBW2_BATTLE_BTL_DISPLAY_H
#define POKEBW2_BATTLE_BTL_DISPLAY_H

#include "types.h"
#include "battle/btl_server.h"
#include "struct_decls.h"

// Each command's format: the number of its arguments in the low nibble, and their widths in the high one
extern const u8 data_ov167_021d6e50[0x60];

void func_ov167_021b1434(BtlServerCmdQueue *que, u32 event, ...);
void func_ov167_021b0a1c(BtlServerCmdQueue *que, u8 value);
u8 func_ov167_021b0a4c(BtlServerCmdQueue *que);
void func_ov167_021b0a58(BtlServerCmdQueue *que, u16 value);
u16 func_ov167_021b0a94(BtlServerCmdQueue *que);
void func_ov167_021b0ab0(BtlServerCmdQueue *que, u32 value);
u32 func_ov167_021b0af8(BtlServerCmdQueue *que);
void func_ov167_021b0b18(BtlServerCmdQueue *que, u32 value);
u32 func_ov167_021b0b6c(BtlServerCmdQueue *que);
void func_ov167_021b0b90(BtlServerCmdQueue *que, u32 event, s32 format, const u32 *args);
void func_ov167_021b1074(BtlServerCmdQueue *que, s32 format, u32 *args);
u16 SCQUE_RESERVE_Pos(BtlServerCmdQueue *que, u32 event);
void func_ov167_021b14ec(BtlServerCmdQueue *que, u32 reserve, u32 event, ...);
u16 func_ov167_021b1564(BtlServerCmdQueue *que, u32 *args);
void func_ov167_021b15c0(BtlServerCmdQueue *que, u8 value);
u8 func_ov167_021b15c8(BtlServerCmdQueue *que);
void func_ov167_021b15d0(BtlServerCmdQueue *que, u8 event, ...);
void func_ov167_021b1630(BtlServerCmdQueue *que, u8 event, u32 *args);
void func_ov167_021b1670(void);
void ServerDisplay_AbilityPopupAdd(BtlServerFlow *handler, BattleMon *mon);
void ServerDisplay_AbilityPopupRemove(BtlServerFlow *handler, BattleMon *mon);
void scPut_SetContFlag(BtlServerFlow *handler, BattleMon *mon, u32 flag);
void scPut_ResetContFlag(BtlServerFlow *handler, BattleMon *mon, u32 flag);
void ServerDisplay_SetTurnFlag(BtlServerFlow *handler, BattleMon *mon, u32 flag);
void ServerDisplay_UseHeldItem(BtlServerFlow *handler, BattleMon *mon);
void ServerDisplay_RecoverPP(BtlServerFlow *handler, BattleMon *mon, u8 slot, u8 amount, BOOL original);
void ServerDisplay_SimpleHP(BtlServerFlow *handler, BattleMon *mon, s32 amount, BOOL show);
void ServerDisplay_StandardMessage(BtlServerFlow *handler, u16 message, u32 count, const u32 *args);
void ServerDisplay_SetMessage(BtlServerFlow *handler, u16 message, u32 count, const u32 *args);
void ServerDisplay_StandardMessageEx(BtlServerFlow *handler, u16 message, u16 soundEffect, u32 count, const u32 *args);
void ServerDisplay_SetMessageEx(BtlServerFlow *handler, u16 message, u16 soundEffect, u32 count, const u32 *args);

// Command 0x18, with its arguments' types
static inline void BtlServerCmd_Put18(void *queue, u8 monId, u8 target, u8 result, u8 arg4, u16 move, u16 arg6) {
    func_ov167_021b1434(queue, 0x18, monId, target, result, arg4, move, arg6);
}

// Command 0x54, with its arguments' types
static inline void BtlServerCmd_Put54(void *queue, u8 monId, u8 effectiveness, u16 move) {
    func_ov167_021b1434(queue, 0x54, monId, effectiveness, move);
}

#endif // POKEBW2_BATTLE_BTL_DISPLAY_H
