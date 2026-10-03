#include "field/field_script.h"
#include "field/trainer_script.h"

void SetupTrainerClashSlot(GameEvent *event, int index, const TrainerClashSlot *slot) {
    ScriptWork *work = EventScriptCall_GetWork(event);
    TrainerClashSlot *dst = ScriptWork_GetTrainerState(work, index);

    dst->payload = slot->payload;
    dst->result = 0;
}
