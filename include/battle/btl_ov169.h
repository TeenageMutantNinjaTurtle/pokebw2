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
void func_ov169_0689d678(void *data, u8 firstPos, u8 secondPos);
void func_ov169_0689d480(void *data, u8 monId);
void func_ov169_0689ced0(void *monSet, u8 count);
void func_ov169_0689cf00(void *monSet, void *copy);
void func_ov169_0689d06c(void *monSet);
void func_ov169_0689d1a4(void *data, u16 move, u32 turn, u8 monId);
void func_ov169_0689d4a8(void *data, u8 pos, u8 monId, BtlPokeCon *pokeCon);
void func_ov169_0689c814(BtlServerFlow *flow, BattleMon *mon);
void func_ov169_0689ccc4(void *monSet);
void func_ov169_0689ccd0(void *monSet, BattleMon *mon);
void func_ov169_0689ce0c(void *monSet);
BattleMon *func_ov169_0689ce14(void *monSet);
void SortBySpeed(void *monSet, BtlServerFlow *flow);
u8 GetBattlePos(void *data, u8 monId);
u32 func_ov169_0689cec0(void *monSet);
void func_ov169_0689cf54(void *monSet, BattleMon *mon, void *out);
void func_ov169_0689cfe0(void *monSet, BattleMon *mon, void *out);
BOOL func_ov169_0689ced8(void *monSet);
void func_ov169_0689cd9c(void *monSet, BattleMon *mon);
BOOL func_ov169_0689d724(void *data, BtlMainModule *mainModule, u8 monId);
void func_ov169_0689d1d8(void *data);
u32 func_ov169_0689cec8(void *monSet);
BattleMon *func_ov169_0689cdf8(void *monSet, u32 index);

#endif // POKEBW2_BATTLE_BTL_OV169_H
