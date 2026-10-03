#include "battle/btl_event.h"

struct EventItemView {
    u32 unk00;
    struct EventItemView *next;
    u8 unk08[0x10];
    u32 flags;
};

struct EventDispatchView {
    u32 depth;
    struct EventItemView *first;
};

extern struct EventDispatchView data_ov167_021db194;

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
