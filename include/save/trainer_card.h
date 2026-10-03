#ifndef POKEBW2_SAVE_TRAINER_CARD_H
#define POKEBW2_SAVE_TRAINER_CARD_H

#include "types.h"
#include "struct_decls.h"

void setSecondsCurrentTimeInTrainerCard(TrainerCardSave *trainerCard, s64 seconds);
void setOneShotDRObtained(TrainerCardSave *trainerCard, u32 flag, PlayerInfo *playerInfo);
TrainerCardSave *getTrainerCardData_wrapper(SaveControl *save);
u32 func_0200c924(TrainerCardSave *trainerCard);
u32 func_0200c90c(TrainerCardSave *trainerCard);
u16 func_0200cb00(TrainerCardSave *trainerCard);
void func_0200cb08(TrainerCardSave *trainerCard, u16 value);
BOOL isBadgeObtained(TrainerCardSave *trainerCard, u32 badgeId);
void addBadge(TrainerCardSave *trainerCard, u32 badgeId);
void setBadgeGetSecondsTime(void *timeSig, u32 badgeId, u32 year, u32 month, u32 day);

#endif // POKEBW2_SAVE_TRAINER_CARD_H
