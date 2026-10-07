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
// The field effect of a phenomenon, which fldeff_encount.c plays
void *func_ov036_021a53f8(EncountSystem *system, void *fieldEffects, u16 x, u16 z, fx32 height, u32 kind);
void func_ov036_021a5498(void *effect, u32 a1);
void func_ov036_021a54a8(void *effect, u32 a1);
void *func_ov036_021a58e0(void *effects, VecFx32 *position, u32 direction, u32 flag);
void *FieldEffects_Create(Field *field, u32 count, HeapID heapId);
void FieldEffects_Free(void *effects);
void FieldEffects_Update(void *effects);
void FieldEffects_Draw(void *effects);
void FieldEffects_Load(void *effects, const u32 *ids, u32 count);
void FieldEffects_TCBManagerInit(void *effects, u32 count);
void FieldEffects_SetLuminanceTable(void *effects, void *table);
u32 FieldEffects_GetSeason(void *effects);
// The effects that actors make on the terrain
void func_ov036_021a3bf0(FieldActor *actor, void *effects);
// The dust of an actor landing
void func_ov036_021a3e74(FieldActor *actor, void *effects);
void func_ov036_021a40ac(void *effects, FieldActor *actor, BOOL moving, u32 kind);
void func_ov036_021b47c8(FieldActor *actor, void *effects, u32 kind);
void func_ov036_021b49ac(MMSys *system, FieldActor *actor, void *effects, u32 kind);
void func_ov036_021be828(void *effects, FieldActor *actor, u32 arg2, u32 arg3);
void func_ov036_021bea3c(void *effects, FieldActor *actor);
void func_ov036_021c289c(FieldActor *actor, void *effects);
void func_ov036_021c94e0(void *effects, FieldActor *actor);
// The effects that every map loads, and their count
extern const u32 STATIC_LOADED_FIELD_EFFECT_IDS[];
extern const u32 data_ov036_021d0388;

#endif // POKEBW2_FIELD_FIELD_EFFECT_H
