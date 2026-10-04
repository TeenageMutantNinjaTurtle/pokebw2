#ifndef POKEBW2_BATTLE_BTL_NET_H
#define POKEBW2_BATTLE_BTL_NET_H

// Overlay 167's link battle functions, which exchange the clients' data before a link battle starts

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

void func_ov167_021b9950(void *netHandle, u16 arg1, HeapID heapId);
BOOL func_ov167_021b9a30(void);
void func_ov167_021b9a54(void);
// Whether the link failed
BOOL func_ov167_021b9a70(void);
BOOL func_ov167_021b9a94(u8 clientId);
BOOL func_ov167_021b9b48(void);
BOOL func_ov167_021b9b60(void);
u8 func_ov167_021b9b78(void);
BOOL func_ov167_021b9bb8(void *data);
BOOL func_ov167_021b9c0c(void *data);
BOOL func_ov167_021b9c38(PokeParty *party);
BOOL func_ov167_021b9ccc(void);
void func_ov167_021b9d00(void);
BOOL func_ov167_021b9d0c(void *chatter);
BOOL func_ov167_021b9dfc(void);
void *func_ov167_021b9e48(u8 clientId);
void func_ov167_021b9e74(void);
BOOL func_ov167_021b9e80(void *data);
BOOL func_ov167_021b9f84(u8 clientId);
PokeParty *func_ov167_021b9fa4(u8 clientId);
void func_ov167_021ba000(void);
BOOL func_ov167_021ba008(PlayerInfo *info);
BOOL func_ov167_021ba098(void);
PlayerInfo *func_ov167_021ba0cc(u8 clientId);
BOOL func_ov167_021ba108(BtlSetupTrainer *trainer);
BOOL func_ov167_021ba1b0(void);
void *func_ov167_021ba1cc(void);
void func_ov167_021ba1e0(void);
void func_ov167_021ba204(void);
void func_ov167_021ba2f4(u8 id);
BOOL func_ov167_021ba318(u8 id);
void *func_ov167_021ba524(u32 size, HeapID heapId);
void func_ov167_021ba55c(void *data);
void func_ov167_021ba564(void *data, PokeParty *party);

#endif // POKEBW2_BATTLE_BTL_NET_H
