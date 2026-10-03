#include "field/field_script.h"
#include "field/trainer_script.h"
#include "nitro/os.h"
#include "save/event_work.h"

void resetRebattleTrainers(EventWork *eventWork) {
    int i;

    clock();
    for (i = 0; i < 12; i++) {
        EventWork_FlagReset(eventWork, (u16)(data_ov012_0216c9a8[i] + 0x5f0));
    }
    clock();
}
