#ifndef POKEBW2_BATTLE_BTL_OV169_H
#define POKEBW2_BATTLE_BTL_OV169_H

#include "types.h"
#include "struct_decls.h"

// Overlay 169's functions that the battle server's flow calls. dsd reads that overlay as data, so these are its
// addresses, which the calls reach through linker veneers

void func_ov169_06898bfc(void);
void func_ov169_0689d178(void *data);
void func_ov169_0689d2a0(void *data);
void func_ov169_0689d2bc(void *data);
void func_ov169_0689d384(void *data, BtlMainModule *mainModule, BtlPokeCon *pokeCon, u32 battleStyle);
u32 func_ov169_0689d2fc(void *data, u32 arg1);
void func_ov169_0689d4c0(void *data, u8 slot, u8 clientId, BattleMon *mon, BtlPokeCon *pokeCon);
u8 func_ov169_0689d6e0(void *data, u8 clientId, u8 *positions);
BOOL DoesBattleMonExist(void *data, u8 monId);
u8 GetBattlePos(void *data, u8 monId);
BOOL func_ov169_0689cec0(void *monSet);
u32 func_ov169_0689cec8(void *monSet);
BattleMon *func_ov169_0689cdf8(void *monSet, u32 index);

#endif // POKEBW2_BATTLE_BTL_OV169_H
