#ifndef POKEBW2_APP_ZUKAN_AWARD_H
#define POKEBW2_APP_ZUKAN_AWARD_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// The Pokédex diplomas: the regional one, overlay 314 (chihou_zukan_award.c), and the national one, overlay 315
// (zenkoku_zukan_award.c)
#define OVERLAY_CHIHOU_ZUKAN_AWARD OVERLAY_ID(314)
#define OVERLAY_ZENKOKU_ZUKAN_AWARD OVERLAY_ID(315)

typedef struct {
    GameData *gameData;
    u32 unk04;
} ZukanAwardParam;

extern const GameProcFunctions data_ov314_0219da74;
extern const GameProcFunctions data_ov315_0219db20;

#endif // POKEBW2_APP_ZUKAN_AWARD_H
