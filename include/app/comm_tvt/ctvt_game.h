#ifndef POKEBW2_APP_COMM_TVT_CTVT_GAME_H
#define POKEBW2_APP_COMM_TVT_CTVT_GAME_H

#include "types.h"
#include "gfl/g3d.h"
#include "struct_decls.h"

// The Xtransceiver's minigames

void func_ov257_021a26dc(CtvtGame *game, int value);
int func_ov257_021a26e0(CtvtGame *game);
G3DManager *func_ov257_021a26e4(CtvtGame *game);
BOOL func_ov257_021a26f0(CtvtGame *game);
void func_ov257_021a26fc(CtvtGame *game, BOOL value);
void func_ov257_021a2708(CtvtGame *game, BOOL value);
void func_ov257_021a2714(CtvtGame *game, BOOL value);
void func_ov257_021a2720(CtvtGame *game, BOOL value);
void func_ov257_021a2728(CtvtGame *game, u8 member);
void func_ov257_021a2744(CtvtGame *game, u8 member);
// Loads the textures of the member's balloon in the color
void func_ov257_021a27e0(CtvtGame *game, u8 netId, u8 color);
void func_ov257_021a2898(CtvtGame *game, u8 value);
void func_ov257_021a29d8(CtvtGame *game, u32 value);
void func_ov257_021a29e4(CtvtGame *game, u16 frame);
u16 func_ov257_021a2a00(CtvtGame *game);
void func_ov257_021a2a0c(CtvtComm *comm, CtvtGame *game, const void *packet, int netId);
void func_ov257_021a2a6c(CtvtGame *game, const void *packet, u8 mask);
void func_ov257_021a2bc0(CtvtGame *game, const void *data);
void func_ov257_021a2be0(CtvtComm *comm, CtvtGame *game, BOOL value, int netId);
void func_ov257_021a2c88(CtvtGame *game, u8 mask);

#endif // POKEBW2_APP_COMM_TVT_CTVT_GAME_H
