#include "types.h"
#include "battle/btl_ability.h"
#include "battle/btl_action.h"
#include "battle/btl_action_order.h"
#include "battle/btl_display.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"
#include "battle/btl_handler.h"
#include "battle/btl_item.h"
#include "battle/btl_main.h"
#include "battle/btl_math.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"
#include "battle/btl_setup.h"
#include "battle/btlv.h"
#include "constants/pokemon.h"
#include "gfl/std.h"
#include "pml/poke_party.h"
#include "pml/waza.h"
#include "save/bag.h"
#include "save/config.h"

BOOL IsStatChangeValid(BattleMon *mon, u32 stat, s32 change);

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.
extern const BattleEventHandlerEntry data_ov167_021d78d4[];

extern const BattleEventHandlerEntry data_ov167_021d78cc[];

extern const BattleEventHandlerEntry data_ov167_021d78c4[];

// Function names from swan.
void BattleEventItem_ConvertToIsolated(BattleEventItem *item) {
    *(u32 *)((u8 *)item + 0x10) = 6;
}

BOOL BattleEventItem_IsIsolated(BattleEventItem *item) {
    if (*(u32 *)((u8 *)item + 0x10) == 6) {
        return TRUE;
    }
    return FALSE;
}

u16 BattleEventItem_GetSubID(BattleEventItem *item) {
    return *(u16 *)((u8 *)item + 0x38);
}

u8 HandlerGetMainModule(BattleEventItem *handler) {
    return ((u8 *)handler)[0x3b];
}

u32 BattleEventItem_GetWorkValue(BattleEventItem *item, u32 index) {
    return *(u32 *)((u8 *)item + 0x1c + index * 4);
}

void BattleEventItem_SetTempItemFlag(BattleEventItem *item) {
    *(u32 *)((u8 *)item + 0x18) |= 1 << 26;
}

void BattleEventItem_SetRecallEnable(BattleEventItem *item) {
    u32 flags;

    flags = *(u32 *)((u8 *)item + 0x18);
    if ((flags << 7) >> 31) {
        *(u32 *)((u8 *)item + 0x18) = flags | (1 << 28);
    }
}

void BattleEventItem_SetWorkValue(BattleEventItem *item, u32 index, u32 value) {
    *(u32 *)((u8 *)item + 0x1c + index * 4) = value;
}

void BattleEvent_ForceCallHandlers(void *context, u32 event) {
    func_ov167_021bc918(context, event, 7, 0);
}

void BattleEvent_CallHandlers(void *context, u32 event) {
    func_ov167_021bc918(context, event, 7, 1);
}

void func_ov167_021bc90c(void *context, u32 event, u32 mask) {
    func_ov167_021bc918(context, event, mask, 1);
}

void func_ov167_021bc918(void *context, u32 event, u32 mask, u32 flag) {
    struct EventItemView *item;

    data_ov167_021db194.depth++;
    func_ov167_021bc94c(context, event, mask, flag);
    if (--data_ov167_021db194.depth == 0) {
        item = data_ov167_021db194.first;
        if (item != NULL) {
            do {
                item->flags &= 0xffff0000;
                item = item->next;
            } while (item != NULL);
        }
    }
}

// Function names from swan.
void BattleEventItem_AttachSkipCheckHandler(BattleEventItem *item, void *handler) {
    *(void **)((u8 *)item + 0xc) = handler;
}

void BattleEventItem_DetachSkipCheckHandler(BattleEventItem *item) {
    *(void **)((u8 *)item + 0xc) = NULL;
}
