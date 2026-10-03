#include "battle/btl_event.h"

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
