#include "field/stadium_script.h"

u32 FindStadiumTrainerIndex(StadiumTrainerEntry *trainers, u16 a, u16 b) {
    s32 i;
    for (i = 0; i < 0x84; i++) {
        if (trainers[i].unk00 == a && trainers[i].unk02 == b) {
            return i;
        }
    }
    return 0;
}
