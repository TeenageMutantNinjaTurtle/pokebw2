#ifndef POKEBW2_SAVE_PLAYER_INFO_H
#define POKEBW2_SAVE_PLAYER_INFO_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "struct_decls.h"

#define GENDER_MALE 0
#define GENDER_FEMALE 1

u16 *GetPlayerName(PlayerInfo *info);
u32 PlayerInfo_GetSize(void);
u32 getTrainerGender(PlayerInfo *info);
u32 getIDAsUInt(PlayerInfo *info);
void setTrainerGender(PlayerInfo *info, u32 gender);
PlayerInfo *func_02008b0c(HeapID heapId);
// Copies a player's info
void func_02008b34(const PlayerInfo *src, PlayerInfo *dest);
void copyTrainerNameFromStrbuf(PlayerInfo *info, const StrBuf *name);
void setIDAsUInt(PlayerInfo *info, u32 id);
// A new game sets this to a random 0 to 7, plus 8 for a female player
void func_02008bf8(PlayerInfo *info, u8 value);

#endif // POKEBW2_SAVE_PLAYER_INFO_H
