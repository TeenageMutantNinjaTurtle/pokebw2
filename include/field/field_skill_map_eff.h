#ifndef POKEBW2_FIELD_FIELD_SKILL_MAP_EFF_H
#define POKEBW2_FIELD_FIELD_SKILL_MAP_EFF_H

#include "types.h"
#include "struct_decls.h"

void *Field_GetSkillMapEff(Field *field);
void *FieldSkillMapEff_GetFlash(void *skillMapEff);
void func_ov036_021c1c68(void *flash, u16 value);
u16 func_ov036_021c1c6c(void *flash);

#endif // POKEBW2_FIELD_FIELD_SKILL_MAP_EFF_H
