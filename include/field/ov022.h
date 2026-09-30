#ifndef POKEBW2_FIELD_OV022_H
#define POKEBW2_FIELD_OV022_H

#include "types.h"
#include "struct_decls.h"

// Overlay 22, the Pokémon World Tournament's events, which its script plugins start

// Events for GameEvent_CreateOverlayDelegate
GameEvent *func_ov022_0216e6e8(GameSystem *gsys, void *args);
// Shows the tournament's Trainers from a WbtSetup, then frees it
GameEvent *func_ov022_0216e73c(GameSystem *gsys, void *args);
// Run overlay 326's screens with a WbtOv326Param and a WbtOv326Param2, then free them
GameEvent *func_ov022_0216e878(GameSystem *gsys, void *args);
GameEvent *func_ov022_0216e8f8(GameSystem *gsys, void *args);

#endif // POKEBW2_FIELD_OV022_H
