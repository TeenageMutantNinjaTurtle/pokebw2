#ifndef POKEBW2_APP_OV141_H
#define POKEBW2_APP_OV141_H

// Overlay 141, a screen of the Battle Subway's records, which overlay 12's event_bsubway.c runs

#include "types.h"
#include "gfl/proc.h"
#include "struct_decls.h"

typedef struct {
    GameData *gameData;
    u32 unk04;
    u32 unk08;
} Ov141Param;

extern const GameProcFunctions data_ov141_0219df2c;

#endif // POKEBW2_APP_OV141_H
