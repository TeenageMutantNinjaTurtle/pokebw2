#ifndef POKEBW2_DEMO_INTRO_H
#define POKEBW2_DEMO_INTRO_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// The intro of a new game, overlay 294, which ov162 runs before and after the name entry
#define OVERLAY_INTRO OVERLAY_ID(294)

typedef struct {
    void *unk0;
    void *unk4;
    // 1 at the start of the intro, and 7 when ov162 runs it again after the name entry
    u32 unk8;
    void *unkC;
    void *unk10;
    void *unk14;
} IntroParam;

typedef struct IntroGraphic IntroGraphic;
typedef struct IntroCmd IntroCmd;
typedef struct IntroMcss IntroMcss;
typedef struct IntroG3d IntroG3d;
typedef struct IntroParticle IntroParticle;

extern const GameProcFunctions INTRO_PROC_FUNCTIONS;
// The sound sequences that the intro plays, which ov162 loads before it
extern const u32 INTRO_SOUND_COUNT;
extern const u32 INTRO_SOUNDS[];

// intro_graphic.c
IntroGraphic *func_ov294_021a1cf8(u32 a0, u32 a1, HeapID heapId);
void func_ov294_021a1dd4(IntroGraphic *graphic);
void func_ov294_021a1e30(IntroGraphic *graphic);
void func_ov294_021a1e44(IntroGraphic *graphic);
void func_ov294_021a1e50(IntroGraphic *graphic);

// intro_cmd.c
IntroCmd *func_ov294_021a2ee8(IntroG3d *g3d, IntroParticle *particle, IntroMcss *mcss, IntroParam *param,
                              IntroGraphic *graphic, HeapID heapId);
void func_ov294_021a2f3c(IntroCmd *cmd);
BOOL func_ov294_021a2f50(IntroCmd *cmd);

// intro_mcss.c
IntroMcss *func_ov294_021a355c(HeapID heapId, u32 a1);
void func_ov294_021a35ac(IntroMcss *mcss);
void func_ov294_021a35dc(IntroMcss *mcss);
void func_ov294_021a3864(IntroMcss *mcss);

// intro_g3d.c
IntroG3d *func_ov294_021a38a8(IntroGraphic *graphic, u32 a1, HeapID heapId);
void func_ov294_021a39a4(IntroG3d *g3d);
void func_ov294_021a39d0(IntroG3d *g3d);

// intro_particle.c
IntroParticle *func_ov294_021a3bf8(IntroGraphic *graphic, HeapID heapId);
void func_ov294_021a3ca4(IntroParticle *particle);
void func_ov294_021a3cb4(IntroParticle *particle);

#endif // POKEBW2_DEMO_INTRO_H
