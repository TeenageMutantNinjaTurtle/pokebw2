#ifndef POKEBW2_FIELD_PLAYER_STATE_H
#define POKEBW2_FIELD_PLAYER_STATE_H

#include "types.h"
#include "nitro/fx.h"
#include "save/player_info.h"
#include "struct_decls.h"

struct PlayerState {
    u16 zoneId;
    u8 unk2[0x1e];
    PlayerInfo playerInfo;
    u32 exState;
};

u32 FieldPlayerState_GetExState(PlayerState *playerState);
u16 PlayerState_CalcDirection(PlayerState *playerState);
VecFx32 *PlayerState_GetWPos(PlayerState *playerState);
u16 PlayerState_GetZoneID(PlayerState *playerState);
void PlayerState_SetIsRail(PlayerState *playerState, BOOL isRail);
void PlayerState_SetRailPos(PlayerState *playerState, RailPosition *pos);
void PlayerState_SetRotation(PlayerState *playerState, u16 angle);
void PlayerState_SetWPos(PlayerState *playerState, VecFx32 *pos);
void PlayerState_SetZoneID(PlayerState *playerState, u16 zoneId);
void SetPlayerSpecialState(PlayerState *playerState, u32 state);

#endif // POKEBW2_FIELD_PLAYER_STATE_H
