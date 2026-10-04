#ifndef POKEBW2_FIELD_FIELD_VISUALS_H
#define POKEBW2_FIELD_FIELD_VISUALS_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "nitro/fx.h"
#include "struct_decls.h"

void *FieldG2D_GetDispControl(Field *field);

void *Field_GetFieldEffects(Field *field);
void *Field_GetG3DObjSys(Field *field);
// The field effects' archive, and their 3D object system
ArcTool *FieldEffects_GetArc(void *effects);
struct FieldG3DObjSystem *func_ov036_021a3724(void *effects);
void *func_ov036_021b3f14(void *effects, FieldActor *actor, u32 arg2, u32 arg3);
void func_ov036_021a5968(void *effect, u32 arg1);
void func_ov036_021a3a70(void *effect);
void *func_ov036_021a58e0(void *effects, VecFx32 *position, u32 direction, u32 flag);

#endif // POKEBW2_FIELD_FIELD_VISUALS_H
