#ifndef POKEBW2_FIELD_FIELD_PROP_H
#define POKEBW2_FIELD_FIELD_PROP_H

#include "types.h"
#include "struct_decls.h"

void FieldPropHandle_CallAnmCmd(FieldPropHandle *handle, u32 animation, u32 command);
BOOL FieldPropHandle_IsAnmIdle(FieldPropHandle *handle, u32 animation);
void FieldChunkPropHolder_CallAnmCmd(FieldChunkPropHolder *holder, void *prop, u32 animation, u32 command);

#endif // POKEBW2_FIELD_FIELD_PROP_H
