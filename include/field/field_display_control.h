#ifndef POKEBW2_FIELD_FIELD_DISPLAY_CONTROL_H
#define POKEBW2_FIELD_FIELD_DISPLAY_CONTROL_H

#include "types.h"

void FieldDispControl_ReqAdjustAlphaA(void *control, u32 alpha, u32 complement);
void FieldDispControl_ReqSetAlphaA(void *control, u32 alpha, u32 beta, u32 planeMask, u32 complement);
void FieldDispControl_ReqSetBGEnabled(void *control, u32 bgId, BOOL enabled);

#endif // POKEBW2_FIELD_FIELD_DISPLAY_CONTROL_H
