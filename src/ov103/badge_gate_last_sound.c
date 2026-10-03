#include "field/badge_gate.h"
#include "gfl/sound.h"

void func_ov103_021ef5dc(BadgeGateLastEventData *data) {
    if (data->state == 100) {
        GFL_SndSEPlay(0x89d);
    }
    if (data->state == 0) {
        GFL_SndSEPlay(0x89c);
    }
    if (data->state == 140) {
        GFL_SndSEPlay(0x89e);
        GFL_SndSEPlay(0x8a1);
    }
    if (data->state == 0x14a) {
        GFL_SndSEPlay(0x89f);
    }
}
