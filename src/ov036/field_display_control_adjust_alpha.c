#include "field/field_display_control.h"

void FieldDispControl_ReqAdjustAlphaA(FieldDispControl *control, u32 alpha, u32 complement) {
    control->requestA = 5;
    control->alphaA = alpha;
    control->betaA = complement;
}
