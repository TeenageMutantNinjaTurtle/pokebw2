#ifndef POKEBW2_FIELD_SUBSCREEN_H
#define POKEBW2_FIELD_SUBSCREEN_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

void FieldSubscreen_ReqChange(FieldSubscreen *subscreen, u32 mode);
// Changes the subscreen, calling the callback with work once it has changed
void FieldSubscreen_ReqChangeEx(FieldSubscreen *subscreen, u32 mode, void (*callback)(void *work), void *work);
u32 FieldSubscreen_GetIDForChange(FieldSubscreen *subscreen, u32 param);
u32 FieldSubscreen_GetScreenID(FieldSubscreen *subscreen);
u32 FieldSubscreen_GetReturnSubscreen(FieldSubscreen *subscreen);
void func_ov036_021984e4(FieldSubscreen *subscreen);
void func_ov036_0219886c(FieldSubscreen *subscreen, u32 param);
BOOL FieldSubscreen_IsReady(FieldSubscreen *subscreen);
u32 func_ov036_02198854(FieldSubscreen *subscreen);
FieldSubscreen *FieldSubscreen_Create(HeapID heapId, Field *field, u32 mode);
u8 FieldSubscreen_Free(FieldSubscreen *subscreen);
void FieldSubscreen_Update(FieldSubscreen *subscreen);
void FieldSubscreen_UpdateAltFrame(FieldSubscreen *subscreen);

#endif // POKEBW2_FIELD_SUBSCREEN_H
