#ifndef POKEBW2_FIELD_EVENT_POKEWOOD_H
#define POKEBW2_FIELD_EVENT_POKEWOOD_H

#include "types.h"
#include "struct_decls.h"

// Overlay 23's event_pokewood.c, which runs Pokéstar Studios' movies for its script plugin (overlay 62)

#define OVERLAY_EVENT_POKEWOOD OVERLAY_ID(23)

void func_ov023_0216f59c(PokewoodSave *save, GameData *gameData, u32 a2, u32 a3, u32 a4);
u8 func_ov023_0216f698(u32 movie);

// Events for GameEvent_CreateOverlayDelegate
GameEvent *func_ov023_0216f2dc(GameSystem *gsys, void *args);
GameEvent *func_ov023_0216f30c(GameSystem *gsys, void *args);
GameEvent *func_ov023_0216f338(GameSystem *gsys, void *args);
GameEvent *func_ov023_0216f364(GameSystem *gsys, void *args);
GameEvent *func_ov023_0216f41c(GameSystem *gsys, void *args);
GameEvent *func_ov023_0216f544(GameSystem *gsys, void *args);
GameEvent *func_ov023_0216f6a4(GameSystem *gsys, void *args);

#endif // POKEBW2_FIELD_EVENT_POKEWOOD_H
