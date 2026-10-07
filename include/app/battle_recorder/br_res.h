#ifndef POKEBW2_APP_BATTLE_RECORDER_BR_RES_H
#define POKEBW2_APP_BATTLE_RECORDER_BR_RES_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "struct_decls.h"
#include "system/printsys.h"

// The Battle Recorder's resources (br_res.c): the font, the messages, the BG and OBJ graphics, and the color the
// player chose for it

// The cell actor resources that func_ov271_021f2c3c loads, each for the main screen and then the sub screen
enum {
    BR_RES_OBJ_BROWSE_BTN_M,
    BR_RES_OBJ_BROWSE_BTN_S,
    BR_RES_OBJ_MUSICAL_BTN_M,
    BR_RES_OBJ_MUSICAL_BTN_S,
};

// The graphics resources of a cell actor, as they are loaded
typedef struct {
    u32 cell;
    u32 chr;
    u32 plt;
} BrResObjData;

BrRes *func_ov271_021f266c(u32 color, BOOL isBrowse, HeapID heapId);
void func_ov271_021f2714(BrRes *res);
void func_ov271_021f274c(BrRes *res, u32 bgID, HeapID heapId);
void func_ov271_021f2b8c(BrRes *res, u32 bgID);
void func_ov271_021f2c3c(BrRes *res, u32 objID, HeapID heapId);
void func_ov271_021f2eb4(BrRes *res, u32 objID);
// Whether the resource is loaded, and if it is, its data
BOOL func_ov271_021f2f10(const BrRes *res, u32 objID, BrResObjData *data);
Font *func_ov271_021f2ff8(const BrRes *res);
MsgData *func_ov271_021f3000(const BrRes *res);
// The fade color for the player's color
u16 func_ov271_021f3010(BrRes *res);
// The color the player chose
u32 func_ov271_021f3024(BrRes *res);

#endif // POKEBW2_APP_BATTLE_RECORDER_BR_RES_H
