#ifndef POKEBW2_BATTLE_BTL_EVENT_H
#define POKEBW2_BATTLE_BTL_EVENT_H

#include "struct_decls.h"
#include "types.h"

// Checks whether an item's handlers are skipped for the item being run: the checking item, the server flow, the
// checked item's factor type, the event, and the checked item's sub ID and mon
typedef BOOL (*BattleEventSkipCheckFn)(BattleEventItem *item, BtlServerFlow *flow, u32 factorType, u32 event, u16 subId,
                                       u8 monId);
// Called with the item, the server flow, the item's mon and its work
typedef void (*BattleEventHandlerFn)(BattleEventItem *item, BtlServerFlow *flow, u8 monId, u32 *work);

struct BattleEventHandlerEntry {
    u32 event;
    BattleEventHandlerFn handler;
};

// A registered handler table for an ability, item, move or other effect, 0x3c bytes; 0x84 are pooled
struct BattleEventItem {
    BattleEventItem *prev;
    BattleEventItem *next;
    const BattleEventHandlerEntry *handlers;
    BattleEventSkipCheckFn skipCheck;
    u32 factorType;
    u32 priority;
    u32 flags;
    u32 work[7];
    u16 subId;
    u8 monId;
    u8 dependMonId;
};

void BattleEventItem_ConvertToIsolated(BattleEventItem *item);
BOOL BattleEventItem_IsIsolated(BattleEventItem *item);
u16 BattleEventItem_GetSubID(BattleEventItem *item);
u8 HandlerGetMainModule(BattleEventItem *handler);
u32 BattleEventItem_GetWorkValue(BattleEventItem *item, u32 index);
void BattleEventItem_SetTempItemFlag(BattleEventItem *item);
void BattleEventItem_SetRecallEnable(BattleEventItem *item);
void BattleEventItem_SetWorkValue(BattleEventItem *item, u32 index, u32 value);
void func_ov167_021bc918(void *context, u32 event, u32 mask, u32 flag);
void func_ov167_021bc90c(void *context, u32 event, u32 mask);
void func_ov167_021bc94c(void *context, u32 event, u32 mask, u32 flag);
void BattleEvent_ForceCallHandlers(void *context, u32 event);
void BattleEvent_CallHandlers(void *context, u32 event);
void BattleEventItem_AttachSkipCheckHandler(BattleEventItem *item, BattleEventSkipCheckFn handler);
void BattleEventItem_DetachSkipCheckHandler(BattleEventItem *item);
BattleEventItem *BattleEvent_SeekItem(u32 type, u32 monId);
void BattleEventItem_Remove(BattleEventItem *item);
void BattleEvent_ItemRotationSleep(u8 monId, u32 priority);
BOOL BattleEvent_ItemRotationWake(u8 monId, u32 priority);
u32 BattleEventVar_GetValue(u32 key);
BOOL BattleEventVar_RewriteValue(u32 key, u32 value);
void BattleEventVar_MulValue(u32 key, u32 value);

#endif // POKEBW2_BATTLE_BTL_EVENT_H
