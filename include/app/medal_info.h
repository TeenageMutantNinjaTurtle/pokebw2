#ifndef POKEBW2_APP_MEDAL_INFO_H
#define POKEBW2_APP_MEDAL_INFO_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "gfl/str.h"
#include "struct_decls.h"

// Overlay 187's screen of a Join Avenue visitor's medals, whose files are medal_info_beacon.c and
// medal_info_viewer.c
#define OVERLAY_MEDAL_INFO OVERLAY_ID(187)

typedef struct {
    u32 unk0;
    u16 unk4;
    StrBuf *name;
    u16 unkC;
    u16 unkE;
    u8 unk10;
    // The date, as the visitor's data packs it
    u8 year;
    u8 month;
    u8 day;
    u32 unk14;
    GameSystem *gsys;
    GameData *gameData;
    StrBuf *nameBuf;
} MedalInfoParam;

extern const GameProcFunctions data_ov187_021ea060;

// What the screen of the medals of a beacon's sender (medal_info_beacon.c) gets
typedef struct {
    GameSystem *gsys;
    GameData *gameData;
    u8 subscreen;
    // Set when the field is to return to the default subscreen
    u8 unk09;
    u8 mode;
    u8 unk0B;
} MedalInfoBeaconParam;

extern const GameProcFunctions data_ov187_021ea06c;

#endif // POKEBW2_APP_MEDAL_INFO_H
