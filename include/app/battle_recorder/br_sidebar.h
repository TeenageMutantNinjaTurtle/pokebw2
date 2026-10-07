#ifndef POKEBW2_APP_BATTLE_RECORDER_BR_SIDEBAR_H
#define POKEBW2_APP_BATTLE_RECORDER_BR_SIDEBAR_H

#include "types.h"
#include "app/battle_recorder/br_fade.h"
#include "app/battle_recorder/br_res.h"
#include "gfl/clact.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The Battle Recorder's sidebars (br_sidebar.c), the animated strips along the edges of the screens

BrSidebar *func_ov271_021f5b68(ClActUnit *unit, BrFade *fade, BrRes *res, HeapID heapId);
void func_ov271_021f5bdc(BrSidebar *sidebar, BrRes *res);
void func_ov271_021f5c18(BrSidebar *sidebar);
void func_ov271_021f5c64(BrSidebar *sidebar);
void func_ov271_021f5cb4(BrSidebar *sidebar);

#endif // POKEBW2_APP_BATTLE_RECORDER_BR_SIDEBAR_H
