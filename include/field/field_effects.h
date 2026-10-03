#ifndef POKEBW2_FIELD_FIELD_EFFECTS_H
#define POKEBW2_FIELD_FIELD_EFFECTS_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"

void *Field_GetEffectBlAct(Field *field);
void *Field_GetWildEffectBlAct(Field *field);
void *func_ov036_021c6cc8(u32 effectId, Field *field);
void func_ov036_021c6d14(void *effect);
void func_ov036_021c6d3c(void *effect);
void func_ov036_021c6cf8(void *effect);

#endif // POKEBW2_FIELD_FIELD_EFFECTS_H
