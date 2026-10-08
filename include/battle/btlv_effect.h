#ifndef POKEBW2_BATTLE_BTLV_EFFECT_H
#define POKEBW2_BATTLE_BTLV_EFFECT_H

#include "types.h"
#include "gfl/tcb.h"
#include "nitro/fx.h"
#include "struct_decls.h"

// Overlay 168's btlv_effect.c (named by its string), the battle effect manager. So far only the effect tools the
// stage, field and camera use; the rest is in battle/btlv.h until the file is decompiled. Every name is ours

// A value moving toward a goal, or swinging back and forth, by a step every few frames. The effect tools' work,
// 0x3c bytes, stepped by btlv_effect.c's tools
typedef struct {
    s32 type;          // 0x00  0: jump to the end, 1 and 4: move to the end, 2 and 3: swing, back to the start
    VecFx32 start;     // 0x04
    VecFx32 end;       // 0x10
    VecFx32 step;      // 0x1c
    s32 stepTime;      // 0x28  frames until the swing turns
    s32 stepTimeReset; // 0x2c
    s32 wait;          // 0x30  frames until the next step
    s32 waitReset;     // 0x34
    s32 count;         // 0x38  the swing's turns left
} BtlvEffToolMove;

// A fade of 3D textures' palettes toward a color, which func_ov168_021e0d54 (btlv_effect.c) steps; the stage and the
// field each have one
typedef struct {
    void **resources; // 0x0  the G3D resources whose palettes fade
    void **palettes;  // 0x4  a copy of each one's palette data, the fade's source
    u8 active;        // 0x8
    u8 count;         // 0x9  of resources
    u8 evy;           // 0xa  the current blend, stepped by one toward targetEvy
    u8 targetEvy;     // 0xb
    u8 wait;          // 0xc  frames left until the next step
    u8 waitFrames;    // 0xd
    u16 color;        // 0xe
} BtlvTexPaletteFade;

// The effect's task slots: a task with its end function and group, and its end
void func_ov168_021e035c(TCB *tcb, void (*endFunc)(TCB *tcb), u32 group);
void func_ov168_021e03ac(TCB *tcb);

// The effect tools at 0x021e0b7c-0x021e0d54
void func_ov168_021e0b7c(const VecFx32 *start, const VecFx32 *end, VecFx32 *step, fx32 frames);
void func_ov168_021e0c10(fx32 *value, const fx32 *step, const fx32 *end, BOOL *done);
BOOL func_ov168_021e0c50(BtlvEffToolMove *move, VecFx32 *value);
void func_ov168_021e0d54(BtlvTexPaletteFade *fade);

#endif // POKEBW2_BATTLE_BTLV_EFFECT_H
