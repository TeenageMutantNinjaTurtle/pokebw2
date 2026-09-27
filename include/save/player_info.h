#ifndef POKEBW2_SAVE_PLAYER_INFO_H
#define POKEBW2_SAVE_PLAYER_INFO_H

#include "types.h"
#include "struct_decls.h"

#define GENDER_MALE 0
#define GENDER_FEMALE 1

u16 *GetPlayerName(PlayerInfo *info);
u32 PlayerInfo_GetSize(void);
u32 getTrainerGender(PlayerInfo *info);

#endif // POKEBW2_SAVE_PLAYER_INFO_H
