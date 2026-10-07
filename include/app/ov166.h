#ifndef POKEBW2_APP_OV166_H
#define POKEBW2_APP_OV166_H

// Overlay 166, a process that overlay 12's event_battle.c runs after a battle

#include "types.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// Its parameter
typedef struct {
    GameData *gameData;
    BtlSetup *setup;
} Ov166Param;

extern const GameProcFunctions data_ov166_0219d6a0;

#endif // POKEBW2_APP_OV166_H
