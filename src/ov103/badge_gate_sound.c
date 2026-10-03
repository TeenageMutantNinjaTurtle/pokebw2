#include "field/badge_gate.h"
#include "gfl/sound.h"

void func_ov103_021ef188(BadgeGateCheckEventData *data) {
    if (data->state == 0) {
        GFL_SndSEPlay(0x8a0);
    }
    if (data->state == 0x32) {
        GFL_SndSEPlay(0x89b);
    }
}
