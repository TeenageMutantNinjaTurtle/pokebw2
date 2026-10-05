#ifndef POKEBW2_SAVE_PLAYER_INFO_H
#define POKEBW2_SAVE_PLAYER_INFO_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "struct_decls.h"

#define GENDER_MALE 0
#define GENDER_FEMALE 1

struct PlayerInfo {
    u16 name[8];
    u32 id;
    u8 unk14[7];
    u8 unk1B;
    u8 unk1C;
    u8 gender;
    u8 unk1E[2];
};

u16 *GetPlayerName(PlayerInfo *info);
// Whether the name is empty
BOOL func_02008b5c(PlayerInfo *info);
u32 PlayerInfo_GetSize(void);
u32 getTrainerGender(PlayerInfo *info);
u8 func_02008bfc(PlayerInfo *info);
u32 func_02008bf4(PlayerInfo *info);
// A table's entry for func_02008bf4's value, 2 past the end of the table
u8 func_0202b5e8(u32 index);
u32 getIDAsUInt(PlayerInfo *info);
void setTrainerGender(PlayerInfo *info, u32 gender);
PlayerInfo *func_02008b0c(u32 heapId);
void func_02008b40(PlayerInfo *info);
void copyTrainerName(PlayerInfo *info, const u16 *name);
// Copies a player's info
void func_02008b34(const PlayerInfo *src, PlayerInfo *dest);
void copyTrainerNameFromStrbuf(PlayerInfo *info, const StrBuf *name);
void setIDAsUInt(PlayerInfo *info, u32 id);
// A new game sets this to a random 0 to 7, plus 8 for a female player
void func_02008bf8(PlayerInfo *info, u8 value);

#endif // POKEBW2_SAVE_PLAYER_INFO_H
