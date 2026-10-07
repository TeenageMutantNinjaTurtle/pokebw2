#ifndef POKEBW2_APP_BATTLE_RECORDER_BR_GRAPHIC_H
#define POKEBW2_APP_BATTLE_RECORDER_BR_GRAPHIC_H

#include "types.h"
#include "gfl/clact.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The Battle Recorder's graphics system (br_graphic.c): the BG system, the cell actors and the VBlank task

BrGraphic *func_ov271_021f31b8(u32 vramType, u32 displayLayout, HeapID heapId);
void func_ov271_021f3270(BrGraphic *graphic);
void func_ov271_021f32c4(BrGraphic *graphic);
ClActUnit *func_ov271_021f32d8(BrGraphic *graphic);

#endif // POKEBW2_APP_BATTLE_RECORDER_BR_GRAPHIC_H
