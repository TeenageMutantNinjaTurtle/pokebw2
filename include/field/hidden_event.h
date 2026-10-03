#ifndef POKEBW2_FIELD_HIDDEN_EVENT_H
#define POKEBW2_FIELD_HIDDEN_EVENT_H

#include "types.h"
#include "struct_decls.h"
#include "system/game_event.h"

struct HiddenEventArgs {
    u16 x;
    u16 z;
    GameSystem *gsys;
};

struct HiddenEventContext {
    u16 unk00;
    u8 unk02[2];
    u32 unk04;
    GameSystem *gsys;
    u16 unk0C;
};

struct HiddenEventData {
    void *unk00;
    u32 unk04;
    GameSystem *gsys;
    u16 unk0C;
    u16 unk0E;
    u32 unk10;
};

typedef BOOL (*HiddenCheckFunc)(HiddenEventContext *context);
typedef GameEvent *(*HiddenCtorFunc)(GameSystem *gsys, HiddenEventContext *context);

HiddenCheckFunc GetHidenEventCheckFunc(HiddenEventContext *context, u32 kind);
HiddenCtorFunc GetHidenEventCtorFunc(HiddenEventContext *context, u32 kind);
BOOL CheckAllowHidenEvent(u32 kind, HiddenEventContext *context);
void func_ov012_02159418(HiddenEventArgs *args, u16 x, u16 z, GameSystem *gsys);
GameEvent *CreateHidenEvent(u32 kind, GameSystem *gsys, HiddenEventContext *context);
BOOL func_ov012_02159440(HiddenEventContext *context);
u32 func_ov012_02159b5c(HiddenEventContext *context, u32 value);
void func_ov012_02159b40(HiddenEventData *data, HiddenEventArgs *param, HiddenEventContext *context);
BOOL EventCutCall_Check(HiddenEventContext *context);
GameEvent *EventCutCall_Create(HiddenEventArgs *param, HiddenEventContext *context);
GameEventReturnCode EventCutCall_Callback(GameEvent *event, u32 *state, void *data);
u32 EventSurfCall_Check(HiddenEventContext *context);
GameEvent *EventSurfCall_Create(HiddenEventArgs *param, HiddenEventContext *context);
GameEventReturnCode EventSurfCall_Callback(GameEvent *event, u32 *state, void *data);
u32 EventWaterfallCall_Check(HiddenEventContext *context);
GameEvent *EventWaterfallCall_Create(HiddenEventArgs *param, HiddenEventContext *context);
GameEventReturnCode EventWaterfallCall_Callback(GameEvent *event, u32 *state, void *data);
u32 EventStrengthCall_Check(HiddenEventContext *context);
GameEvent *EventStrengthCall_Create(HiddenEventArgs *param, HiddenEventContext *context);
GameEventReturnCode EventStrengthCall_Callback(GameEvent *event, u32 *state, void *data);

#endif // POKEBW2_FIELD_HIDDEN_EVENT_H
