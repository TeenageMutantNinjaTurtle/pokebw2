#ifndef POKEBW2_FIELD_SUBSCREEN_H
#define POKEBW2_FIELD_SUBSCREEN_H

#include "types.h"
#include "struct_decls.h"

void FieldSubscreen_ReqChange(FieldSubscreen *subscreen, u32 mode);
u32 FieldSubscreen_GetReturnSubscreen(FieldSubscreen *subscreen);
void func_ov036_021984e4(FieldSubscreen *subscreen);

#endif // POKEBW2_FIELD_SUBSCREEN_H
