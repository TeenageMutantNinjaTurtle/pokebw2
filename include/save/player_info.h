#ifndef POKEBW2_SAVE_PLAYER_INFO_H
#define POKEBW2_SAVE_PLAYER_INFO_H

#include "types.h"
#include "struct_decls.h"

#define GENDER_MALE 0
#define GENDER_FEMALE 1

void *GetPlayerName(PlayerInfo *info);
u32 PlayerInfo_GetSize(void);
u32 getTrainerGender(PlayerInfo *info);
void setSecondsCurrentTimeInTrainerCard(void *trainerCard, s64 seconds);

#endif // POKEBW2_SAVE_PLAYER_INFO_H
