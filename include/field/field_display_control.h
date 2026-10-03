#ifndef POKEBW2_FIELD_FIELD_DISPLAY_CONTROL_H
#define POKEBW2_FIELD_FIELD_DISPLAY_CONTROL_H

#include "types.h"

typedef struct FieldDispControl {
    u16 requestA;
    u16 requestB;
    u32 alphaA;
    u32 betaA;
    u32 planeMaskA;
    u32 complementA;
    u32 allA;
    u32 alphaB;
    u32 betaB;
    u32 planeMaskB;
    u32 complementB;
    u32 unk28;
    u8 bgEnabled[4];
} FieldDispControl;

void FieldDispControl_ReqAdjustAlphaA(FieldDispControl *control, u32 alpha, u32 complement);
void FieldDispControl_ReqSetAlphaA(FieldDispControl *control, u32 alpha, u32 beta, u32 planeMask, u32 complement);
void FieldDispControl_ReqSetAllA(FieldDispControl *control, u32 alpha, u32 beta, u32 planeMask, u32 complement,
                                 u32 all);
void FieldDispControl_ReqSetAlphaB(FieldDispControl *control, u32 alpha, u32 beta, u32 planeMask, u32 complement);
void FieldDispControl_ReqSetBGEnabled(FieldDispControl *control, u32 bgId, BOOL enabled);

#endif // POKEBW2_FIELD_FIELD_DISPLAY_CONTROL_H
