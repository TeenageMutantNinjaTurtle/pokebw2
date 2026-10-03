#ifndef POKEBW2_BATTLE_BTL_EVENT_H
#define POKEBW2_BATTLE_BTL_EVENT_H

#include "struct_decls.h"
#include "types.h"

typedef void (*BattleEventHandlerFn)(void *context, void *item, u32 monId);

struct BattleEventHandlerEntry {
    u32 event;
    BattleEventHandlerFn handler;
};

extern EventDispatchView data_ov167_021db194;

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
void BattleEventItem_AttachSkipCheckHandler(BattleEventItem *item, void *handler);
void BattleEventItem_DetachSkipCheckHandler(BattleEventItem *item);
void BattleEvent_ItemRotationSleep(u8 monId, u32 priority);
BOOL BattleEvent_ItemRotationWake(u8 monId, u32 priority);
u32 BattleEventVar_GetValue(u32 key);
BOOL BattleEventVar_RewriteValue(u32 key, u32 value);
void BattleEventVar_MulValue(u32 key, u32 value);

#endif // POKEBW2_BATTLE_BTL_EVENT_H
