#ifndef POKEBW2_FIELD_FIELD_PLAYER_H
#define POKEBW2_FIELD_FIELD_PLAYER_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "struct_decls.h"

BOOL Field_HasPlayer(Field *field);
BOOL Field_ToggleCycling(Field *field);
void FieldPlayer_GetWPosInDir(FieldPlayer *player, u32 direction, VecFx32 *position);
u32 FieldPlayer_GetExState(FieldPlayer *player);
u32 FieldPlayer_DeriveExState(FieldPlayer *player);
void FieldPlayer_SetSpecialState(FieldPlayer *player, u32 state);
void FieldPlayer_SetSpecialSeq(FieldPlayer *player, u32 seq);
BOOL func_ov036_0219a580(FieldPlayer *player);
u32 func_ov036_0219a864(FieldPlayer *player);
BOOL func_ov036_0219a834(FieldPlayer *player);
BOOL func_ov036_0219a870(FieldPlayer *player);
BOOL func_ov036_0219ab24(FieldPlayer *player);
u32 FieldPlayer_GetTileTypeUnder(FieldPlayer *player);
// The player's grid and rail movement
void FieldPlayer_InitGrid(FieldPlayer *player, HeapID heapId);
void func_ov036_0219accc(FieldPlayer *player, HeapID heapId);
u16 FieldPlayer_GetMoveDirByKey(FieldPlayer *player, u32 heldKeys);
BOOL func_ov036_0219a5dc(FieldPlayer *player);
BOOL FieldPlayer_CheckRunningShoesFlag(FieldPlayer *player);
void FieldPlayer_UpdateGridMovement(FieldPlayer *player, u32 pressedKeys, u32 heldKeys, u32 flags);
void FieldPlayer_UpdateRailMovement(FieldPlayer *player, u32 pressedKeys, u32 heldKeys);
void func_ov036_0219ace8(FieldPlayer *player, const void *pos);
void func_ov036_0219acf4(FieldPlayer *player);
BOOL func_ov036_0219ad00(FieldPlayer *player);
void *func_ov036_0219ad0c(FieldPlayer *player);
u32 FieldPlayer_GetTileTypeInDir(FieldPlayer *player, u16 direction);
FieldActor *FieldPlayer_GetActorInFront(FieldPlayer *player);
FieldActor *FieldPlayer_GetActorInFrontEx(FieldPlayer *player, fx32 maxHeightDiff);
BOOL CheckSurfHeightAllow(FieldPlayer *player, u32 direction);
BOOL CheckCanInteractWaterfall(FieldPlayer *player, u32 tileUnder, u32 tileInFront);
FieldPlayer *FieldPlayer_Create(PlayerState *state, Field *field, const VecFx32 *pos, u32 sex, HeapID heapId);
void FieldPlayer_Free(FieldPlayer *player);
void FieldPlayer_SyncState(FieldPlayer *player);
void FieldPlayer_ForceBrake(FieldPlayer *player);
void FieldPlayer_SetRailPos(FieldPlayer *player, const RailPosition *pos);
void FieldPlayer_GetRailWorldPos(FieldPlayer *player, VecFx32 *pos);

#endif // POKEBW2_FIELD_FIELD_PLAYER_H
