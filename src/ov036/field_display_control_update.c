#include "field/field_display_control.h"
#include "gfl/graphics.h"
#include "nitro/hw.h"

void FieldDispControl_Update(FieldDispControl *control) {
    void (*proc)(void *, u32);
    s32 i;

    proc = FIELD_DISP_CONTROL_PROCS[control->requestA];
    if (proc != NULL) {
        proc(&control->alphaA, 1);
        control->requestA = 0;
    }

    proc = FIELD_DISP_CONTROL_PROCS[control->requestB];
    if (proc != NULL) {
        proc(&control->alphaB, 0);
        control->requestB = 0;
    }

    for (i = 0; i < 8; i++) {
        if (control->bgEnabled[i] != 0xff) {
            GFL_BGSysSetBGEnabled(i, control->bgEnabled[i]);
            control->bgEnabled[i] = 0xff;
        }
    }

    if (control->brightnessRequest[0] != 0) {
        GFXRegSetMasterBrightness(REG_MASTER_BRIGHT_ADDR, control->brightnessValue[0]);
        control->brightnessRequest[0] = 0;
    }
    if (control->brightnessRequest[1] != 0) {
        GFXRegSetMasterBrightness(REG_DB_MASTER_BRIGHT_ADDR, control->brightnessValue[1]);
        control->brightnessRequest[1] = 0;
    }
}
