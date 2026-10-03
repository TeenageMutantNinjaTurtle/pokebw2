#include "field/field_display_control.h"

void FieldDispControl_ReqSetBGEnabled(FieldDispControl *control, u32 bgId, BOOL enabled) {
    u8 *target = (u8 *)control + bgId;

    ((FieldDispControl *)target)->bgEnabled[0] = enabled;
}
