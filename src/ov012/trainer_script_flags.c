#include "field/trainer_script.h"
#include "save/event_work.h"

BOOL TrainerFlagGet(EventWork *eventWork, u16 trainerId) {
    return EventWork_FlagGet(eventWork, (u16)(trainerId + 0x5f0));
}

void setTrainerBattleFlag(EventWork *eventWork, u16 trainerId) {
    EventWork_FlagSet(eventWork, (u16)(trainerId + 0x5f0));
}

void clearTrainerBattleFlag(EventWork *eventWork, u16 trainerId) {
    EventWork_FlagReset(eventWork, (u16)(trainerId + 0x5f0));
}
