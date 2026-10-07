#ifndef POKEBW2_SYSTEM_BMP_OAM_H
#define POKEBW2_SYSTEM_BMP_OAM_H

#include "types.h"
#include "gfl/bmp.h"
#include "gfl/clact.h"
#include "gfl/heap.h"

// Actors that show a bitmap, such as text, on OAM. The ROM doesn't name this file; bmp_oam.c is a guess after the
// GFL's bitmap and window files. None of these functions has a name yet

typedef struct BmpOamActor BmpOamActor;
typedef struct BmpOamSys BmpOamSys;

// An actor to add: its bitmap, where it is, its palette resource and offset, its priorities and its surface
typedef struct {
    GFLBitmap *bitmap;
    s16 x;
    s16 y;
    u32 palette;
    u32 palOffset;
    u8 priority;
    u8 bgPriority;
    u16 surface;
    u32 vramType;
} BmpOamActorSetup;

// The system that adds the actors to a unit
BmpOamSys *func_0202ae5c(HeapID heapId, ClActUnit *unit);
void func_0202aeac(BmpOamSys *sys);
BmpOamActor *func_0202aec4(BmpOamSys *sys, const BmpOamActorSetup *setup);
void func_0202b030(BmpOamActor *actor);
// Whether the actor is shown
void func_0202b098(BmpOamActor *actor, BOOL visible);
BOOL func_0202b0e8(BmpOamActor *actor);

// Sends the actor's bitmap to its characters in VRAM
void func_0202b0f4(BmpOamActor *actor);
// Where the actor is
void func_0202b20c(BmpOamActor *actor, s16 *x, s16 *y);
void func_0202b230(BmpOamActor *actor, s16 x, s16 y);

#endif // POKEBW2_SYSTEM_BMP_OAM_H
