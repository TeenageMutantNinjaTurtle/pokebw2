#ifndef POKEBW2_SAVE_TRAINER_CARD_H
#define POKEBW2_SAVE_TRAINER_CARD_H

#include "types.h"
#include "struct_decls.h"

void setSecondsCurrentTimeInTrainerCard(TrainerCardSave *trainerCard, s64 seconds);
void setOneShotDRObtained(TrainerCardSave *trainerCard, u32 flag, PlayerInfo *playerInfo);
// Overlay 12
BOOL isOneShotDRObtained(TrainerCardSave *trainerCard, u32 flag, PlayerInfo *playerInfo);
TrainerCardSave *getTrainerCardData_wrapper(SaveControl *save);
u32 func_0200c924(TrainerCardSave *trainerCard);
u32 func_0200c90c(TrainerCardSave *trainerCard);
u16 func_0200cb00(TrainerCardSave *trainerCard);
void func_0200cb08(TrainerCardSave *trainerCard, u16 value);
// When the survey started, in seconds since 2000
s64 getSecondsFromTrainerCardData(TrainerGameInfoSave *info);
// Adds to the play time
void func_0200cb10(TrainerGameInfoSave *info, u16 minutes);
BOOL isBadgeObtained(TrainerCardSave *trainerCard, u32 badgeId);
void addBadge(TrainerCardSave *trainerCard, u32 badgeId);
void setBadgeGetSecondsTime(void *timeSig, u32 badgeId, u32 year, u32 month, u32 day);

#endif // POKEBW2_SAVE_TRAINER_CARD_H
