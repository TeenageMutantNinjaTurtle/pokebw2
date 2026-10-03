#include "battle/trainer_data.h"
#include "field/trainer_script.h"

BOOL isDoubleBattle(u32 trainerId) {
    return TrainerData_GetParam(trainerId, 2) == 1;
}

u8 getBattleType(u32 trainerId) {
    return TrainerData_GetParam(trainerId, 2);
}
