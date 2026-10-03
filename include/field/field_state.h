#ifndef POKEBW2_FIELD_FIELD_STATE_H
#define POKEBW2_FIELD_FIELD_STATE_H

#include "types.h"
#include "struct_decls.h"

u32 Field_GetRenderMode(Field *field);
void Field_SetRenderMode(Field *field, u32 mode);
void *Field_GetSceneArea(Field *field);
void Field_SetFadeFlag(Field *field, BOOL flag);
BOOL Field_IsEventRunning(Field *field);
u16 Field_GetDayPeriod(Field *field);
BOOL Field_GetSeasonBannerOverdrawFlag(Field *field);
void Field_SetEffectRunningFlag(Field *field, BOOL flag);
void *Field_GetNDemoDataHandle(Field *field);
void Field_SetCasteliaRush(Field *field, BOOL flag);
BOOL Field_GetCasteliaRush(Field *field);
void *Field_GetColorPostFX(Field *field);

#endif // POKEBW2_FIELD_FIELD_STATE_H
