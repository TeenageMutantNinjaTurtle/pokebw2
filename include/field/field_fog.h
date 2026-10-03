#ifndef POKEBW2_FIELD_FIELD_FOG_H
#define POKEBW2_FIELD_FIELD_FOG_H

#include "types.h"
#include "nitro/gx.h"
#include "struct_decls.h"

// The field's fog, which takes effect when flushed
void FieldFog_SetEnabled(FieldFog *fog, BOOL enabled);
void FieldFog_SetAlphaMode(FieldFog *fog, u32 alphaMode);
void FieldFog_SetAlpha(FieldFog *fog, u32 alpha);
void FieldFog_SetDepthShift(FieldFog *fog, u32 depthShift);
void FieldFog_SetOffset(FieldFog *fog, u32 offset);
void FieldFog_SetColor(FieldFog *fog, GXRgb color);
// The fog's density at 32 depths
void FieldFog_SetTable(FieldFog *fog, const u8 *table);
void FieldFog_Flush(FieldFog *fog);
u32 FieldFog_GetDepthShift(FieldFog *fog);
void FieldFog_Animate(FieldFog *fog, u32 color, u32 depthShift, u32 duration);

#endif // POKEBW2_FIELD_FIELD_FOG_H
