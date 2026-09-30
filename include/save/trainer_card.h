#ifndef POKEBW2_SAVE_TRAINER_CARD_H
#define POKEBW2_SAVE_TRAINER_CARD_H

#include "types.h"
#include "struct_decls.h"

void setSecondsCurrentTimeInTrainerCard(TrainerCardSave *trainerCard, s64 seconds);
TrainerCardSave *getTrainerCardData_wrapper(SaveControl *save);
u32 func_0200c924(TrainerCardSave *trainerCard);

#endif // POKEBW2_SAVE_TRAINER_CARD_H
