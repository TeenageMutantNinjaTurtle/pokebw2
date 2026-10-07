#ifndef POKEBW2_FIELD_EVENT_ENTRANCE_EFFECT_H
#define POKEBW2_FIELD_EVENT_ENTRANCE_EFFECT_H

// Overlay 36's event_entrance_effect.c: the events that play an entrance, such as a door, when the player comes out of
// it or goes into it during a warp, and overlay 36's entrance camera that they drive. The file name is descriptive

#include "types.h"
#include "nitro/fx.h"
#include "struct_decls.h"

// What the entrance camera plays: the warp's transition, coming out of the entrance or going into it
typedef struct {
    u32 transitionType;
    BOOL isArrival;
    BOOL isDeparture;
} EntranceCameraParam;

// The position in front of the player, where an entrance the player walks into stands
void func_ov036_0219f178(Field *field, VecFx32 *pos);
// The events of the warp's entrance as the player comes out of it and goes into it
GameEvent *func_ov036_0219f190(WarpSequence *warp);
GameEvent *func_ov036_0219f4e0(WarpSequence *warp);

// The entrance camera, 0x021b7a34 onward
void *func_ov036_021b7a34(Field *field);
void func_ov036_021b7a58(void *camera);
void func_ov036_021b7a68(void *camera, const EntranceCameraParam *param);
void func_ov036_021b7ac0(void *camera);
void func_ov036_021b7ad4(void *camera);
BOOL func_ov036_021b7ae0(void *camera);
BOOL func_ov036_021b7ae8(void *camera);
// The event that walks the player into the entrance
GameEvent *func_ov036_021b74a0(GameSystem *gsys, WarpSequence *warp);

#endif // POKEBW2_FIELD_EVENT_ENTRANCE_EFFECT_H
