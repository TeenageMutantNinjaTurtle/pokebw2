#include "field/field_display_control.h"

void FieldDispControl_ReqSetAlphaB(FieldDispControl *control, u32 alpha, u32 beta, u32 planeMask, u32 complement) {
    control->requestB = 2;
    control->alphaB = alpha;
    control->betaB = beta;
    control->planeMaskB = planeMask;
    control->complementB = complement;
}
