#ifndef POKEBW2_FIELD_FIELD_EFFECT_H
#define POKEBW2_FIELD_FIELD_EFFECT_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "struct_decls.h"

void *Field_GetEffectBlAct(Field *field);
void *Field_GetWildEffectBlAct(Field *field);
void *func_ov036_021c6cc8(u32 effectId, Field *field);
void func_ov036_021c6d14(void *effect);
void func_ov036_021c6d3c(void *effect);
void func_ov036_021c6cf8(void *effect);

// The field effects' archive, and their 3D object system
ArcTool *FieldEffects_GetArc(void *effects);
struct FieldG3DObjSystem *func_ov036_021a3724(void *effects);
void *func_ov036_021b3f14(void *effects, FieldActor *actor, u32 arg2, u32 arg3);
void func_ov036_021a5968(void *effect, u32 arg1);
void func_ov036_021a3a70(void *effect);
void *func_ov036_021a58e0(void *effects, VecFx32 *position, u32 direction, u32 flag);
void *FieldEffects_Create(Field *field, u32 count, HeapID heapId);
void FieldEffects_Free(void *effects);
void FieldEffects_Update(void *effects);
void FieldEffects_Draw(void *effects);
void FieldEffects_Load(void *effects, const u32 *ids, u32 count);
void FieldEffects_TCBManagerInit(void *effects, u32 count);
void FieldEffects_SetLuminanceTable(void *effects, void *table);
// The effects that every map loads, and their count
extern const u32 STATIC_LOADED_FIELD_EFFECT_IDS[];
extern const u32 data_ov036_021d0388;

#endif // POKEBW2_FIELD_FIELD_EFFECT_H
