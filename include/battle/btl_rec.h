#ifndef POKEBW2_BATTLE_BTL_REC_H
#define POKEBW2_BATTLE_BTL_REC_H

// Overlay 167's btl_rec.c, which packs the clients' actions for the battle recording

#include "types.h"

// The actions of a turn: the clients in clientFlags, each with a header byte (client ID in bits 5 to 7, action count in
// bits 0 to 4) and its actions
typedef struct {
    u8 size;
    u8 clientFlags;
    u8 numClients;
    u8 unk03_0 : 6;
    u8 unk03_6 : 1;
    u8 overflow : 1;
    u8 data[0x3c];
} BtlRecTool;

void func_ov167_021d48a0(BtlRecTool *tool, BOOL flag);
void *func_ov167_021d48c4(BtlRecTool *tool, u32 *size, u8 value);
void func_ov167_021d48e0(BtlRecTool *tool, u8 clientId, const void *actions, u8 count);
void *func_ov167_021d4958(BtlRecTool *tool, u8 value, u32 *size);
void *func_ov167_021d4990(BtlRecTool *tool, u32 *size);
void func_ov167_021d49a0(BtlRecTool *tool, const void *data, u32 size);
BOOL func_ov167_021d49d0(BtlRecTool *tool, u32 *pos, u8 *clientId, u8 *count, void *actions);

#endif // POKEBW2_BATTLE_BTL_REC_H
