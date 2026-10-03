#include "types.h"
#include "battle/trainer_data.h"
#include "field/field_script.h"
#include "field/trainer_script.h"
#include "nitro/os.h"
#include "save/event_work.h"

void SetupTrainerClashSlot(GameEvent *event, int index, const TrainerClashSlot *slot) {
    ScriptWork *work = EventScriptCall_GetWork(event);
    TrainerClashSlot *dst = ScriptWork_GetTrainerState(work, index);

    dst->payload = slot->payload;
    dst->result = 0;
}

u16 GetNPCTrainerIDFromSCRID(u32 scriptId) {
    if (scriptId < 0x1388) {
        return scriptId - 0xbb8;
    }
    return scriptId - 0x1388;
}

u16 GetNormalSCRIDFromTrainerID(u32 trainerId) {
    return trainerId + 0xbb8;
}

u16 GetPairMember2SCRIDFromTrainerID(u32 trainerId) {
    return trainerId + 0x1388;
}

BOOL isTrainerScrIdDoublePair2(u32 scriptId) {
    return scriptId >= 0x1388;
}

BOOL isDoubleBattle(u32 trainerId) {
    return TrainerData_GetParam(trainerId, 2) == 1;
}

u8 getBattleType(u32 trainerId) {
    return TrainerData_GetParam(trainerId, 2);
}

BOOL TrainerFlagGet(EventWork *eventWork, u16 trainerId) {
    return EventWork_FlagGet(eventWork, (trainerId + 0x5f0));
}

void setTrainerBattleFlag(EventWork *eventWork, u16 trainerId) {
    EventWork_FlagSet(eventWork, (trainerId + 0x5f0));
}

void clearTrainerBattleFlag(EventWork *eventWork, u16 trainerId) {
    EventWork_FlagReset(eventWork, (trainerId + 0x5f0));
}

void resetRebattleTrainers(EventWork *eventWork) {
    int i;

    clock();
    for (i = 0; i < 12; i++) {
        EventWork_FlagReset(eventWork, (data_ov012_0216c9a8[i] + 0x5f0));
    }
    clock();
}
