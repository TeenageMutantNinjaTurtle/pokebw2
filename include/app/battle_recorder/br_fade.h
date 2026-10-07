#ifndef POKEBW2_APP_BATTLE_RECORDER_BR_FADE_H
#define POKEBW2_APP_BATTLE_RECORDER_BR_FADE_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The Battle Recorder's fades between its screens (br_fade.c), to its color with the palettes or by alpha blending

// The screens a fade applies to
#define BR_FADE_DISPLAY_MAIN 0x1
#define BR_FADE_DISPLAY_SUB 0x2
#define BR_FADE_DISPLAY_BOTH (BR_FADE_DISPLAY_MAIN | BR_FADE_DISPLAY_SUB)

BrFade *func_ov271_021f54d8(HeapID heapId);
void func_ov271_021f554c(BrFade *fade);
void func_ov271_021f5580(BrFade *fade);
void func_ov271_021f55cc(BrFade *fade);
void func_ov271_021f560c(BrFade *fade, u16 color);
void func_ov271_021f5610(BrFade *fade, u32 display);
void func_ov271_021f5658(BrFade *fade, u32 display, u32 alpha);
// Loads a palette into one of the fade's PaletteFade buffers
void func_ov271_021f5700(BrFade *fade, ArcTool *handle, u32 fileId, u32 buffer, u32 offset, u32 size, HeapID heapId);

#endif // POKEBW2_APP_BATTLE_RECORDER_BR_FADE_H
