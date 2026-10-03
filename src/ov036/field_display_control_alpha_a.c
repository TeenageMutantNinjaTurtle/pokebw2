#include "field/field_display_control.h"

void FieldDispControl_ReqSetAlphaA(FieldDispControl *control, u32 alpha, u32 beta, u32 planeMask, u32 complement) {
    control->requestA = 2;
    control->alphaA = alpha;
    control->betaA = beta;
    control->planeMaskA = planeMask;
    control->complementA = complement;
}

void FieldDispControl_ReqSetAllA(FieldDispControl *control, u32 alpha, u32 beta, u32 planeMask, u32 complement,
                                 u32 all) {
    control->requestA = 4;
    control->alphaA = alpha;
    control->betaA = beta;
    control->planeMaskA = planeMask;
    control->complementA = complement;
    control->allA = all;
}
