#ifndef POKEBW2_BATTLE_BTLV_H
#define POKEBW2_BATTLE_BTLV_H

#include "types.h"
#include "struct_decls.h"

void Btlv_StringParam_Setup(BtlvStringParam *param, u32 type, u16 message);
void Btlv_StringParam_AddArg(BtlvStringParam *param, u32 arg);

// The battle view, in overlay 168

u32 func_ov168_021e04ec(u8 pos);

#endif // POKEBW2_BATTLE_BTLV_H
