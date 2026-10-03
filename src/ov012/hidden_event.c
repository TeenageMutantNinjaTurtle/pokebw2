#include "field/hidden_event.h"
#include "field/event_chatot.h"
#include "field/event_fly.h"
#include "field/event_mapchange.h"
#include "field/event_sweet_scent.h"
#include "field/field.h"
#include "field/field_script.h"
#include "field/field_status.h"
#include "field/skill_map_effect.h"
#include "field/zone.h"
#include "save/event_work.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

BOOL CheckAllowHidenEvent(u32 kind, HiddenEventContext *context) {
    HiddenCheckFunc check = GetHidenEventCheckFunc(context, kind);
    if (check == NULL) {
        return TRUE;
    }
    return check(context);
}

void func_ov012_02159418(HiddenEventArgs *args, u16 x, u16 z, GameSystem *gsys) {
    args->x = x;
    args->z = z;
    args->gsys = gsys;
}

GameEvent *CreateHidenEvent(u32 kind, GameSystem *gsys, HiddenEventContext *context) {
    HiddenCtorFunc ctor = GetHidenEventCtorFunc(context, kind);
    if (ctor == NULL) {
        return NULL;
    }
    return ctor(gsys, context);
}

BOOL func_ov012_02159440(HiddenEventContext *args) {
    return GameData_CheckPairFlag(GSYS_GetGameData(args->gsys));
}

BOOL EventCutCall_Check(HiddenEventContext *context) {
    u32 result = FALSE;
    if (func_ov012_02159b5c(context, 0) == 0) {
        result = TRUE;
    }
    return result;
}

GameEvent *EventCutCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;

    event = GameEvent_Create(context->gsys, NULL, EventCutCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventCutCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    u16 param;
    ScriptWork *scriptWork;

    GameData_GetEventWork(GSYS_GetGameData(work->gsys));
    param = work->unk0C;
    scriptWork = EventScriptCall_Replace(event, 0x2715, 0, 0);
    ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
    return GAMEEVENT_CONTINUE;
}

u32 EventSurfCall_Check(HiddenEventContext *context) {
    u32 state = context->unk04;
    if (state == 2) {
        return 4;
    }
    if (state == 3) {
        return 1;
    }
    if (func_ov012_02159b5c(context, 1) != 0) {
        if (func_ov012_02159440(context) != 0) {
            return 3;
        }
        return 0;
    }
    return 1;
}

GameEvent *EventSurfCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;

    event = GameEvent_Create(context->gsys, NULL, EventSurfCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventSurfCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    u16 param;
    ScriptWork *scriptWork;

    GameData_GetEventWork(GSYS_GetGameData(work->gsys));
    param = work->unk0C;
    scriptWork = EventScriptCall_Replace(event, 0x2713, 0, 0);
    ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
    return GAMEEVENT_CONTINUE;
}

u32 EventWaterfallCall_Check(HiddenEventContext *context) {
    if (func_ov012_02159b5c(context, 2) != 0) {
        if (func_ov012_02159440(context) != 0) {
            return 3;
        }
        return 0;
    }
    return 1;
}

GameEvent *EventWaterfallCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;

    event = GameEvent_Create(context->gsys, NULL, EventWaterfallCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventWaterfallCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    u16 param;
    ScriptWork *scriptWork;

    GameData_GetEventWork(GSYS_GetGameData(work->gsys));
    param = work->unk0C;
    scriptWork = EventScriptCall_Replace(event, 0x2717, 0, 0);
    ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
    return GAMEEVENT_CONTINUE;
}

u32 EventStrengthCall_Check(HiddenEventContext *context) {
    switch (func_ov012_02159b5c(context, 3)) {
    default:
        return FALSE;
    case 0:
        return TRUE;
    }
}

GameEvent *EventStrengthCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;

    event = GameEvent_Create(context->gsys, NULL, EventStrengthCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventStrengthCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    u16 param;
    ScriptWork *scriptWork;

    GameData_GetEventWork(GSYS_GetGameData(work->gsys));
    param = work->unk0C;
    scriptWork = EventScriptCall_Replace(event, 0x2711, 0, 0);
    ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
    return GAMEEVENT_CONTINUE;
}

u32 func_ov012_02159644(HiddenEventContext *context) {
    switch (func_ov012_02159b5c(context, 8)) {
    default:
        return FALSE;
    case 0:
        return TRUE;
    }
}

GameEvent *func_ov012_02159658(HiddenEventArgs *args, HiddenEventContext *context) {
    return func_ov033_021785d4(context->gsys, context->field, (u8)args->x);
}

GameEvent *EventFly_Create(HiddenEventArgs *args, HiddenEventContext *context) {
    func_ov012_0216002c(0x13);
    return func_ov033_02178908(context->gsys, context->field, (u32)args->gsys);
}

u32 EventFly_Check(HiddenEventContext *context) {
    if (func_ov012_02159b5c(context, 4) != 0) {
        if (func_ov012_02159440(context) != 0) {
            return 3;
        }
        return 0;
    }
    return 1;
}

u32 EventFlash_Check(HiddenEventContext *context) {
    switch (func_ov012_02159b5c(context, 5)) {
    default:
        return FALSE;
    case 0:
        return TRUE;
    }
}

GameEvent *EventFlash_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;

    event = GameEvent_Create(context->gsys, NULL, EventFlash_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventFlash_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    GameData *gameData;
    FieldStatus *status;
    void *flash;
    HeapID heapId;
    ScriptWork *scriptWork;
    u16 param;
    u32 flags;
    FieldStatus *status2;

    gameData = GSYS_GetGameData(work->gsys);
    GameData_GetEventWork(gameData);
    status = GameData_GetFieldStatus(gameData);
    flash = FieldSkillMapEff_GetFlash(Field_GetSkillMapEff(GSYS_GetField(work->gsys)));
    heapId = Field_GetHeapID(GSYS_GetField(work->gsys));
    switch (*state) {
    case 0:
        param = work->unk0C;
        scriptWork = EventScriptCall_Start(event, 0x2718, NULL, NULL, heapId);
        ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
        ++*state;
        break;
    case 1:
        if (!FieldStatus_CheckFlashUsed(status)) {
            status2 = GameData_GetFieldStatus(gameData);
            FieldStatus_SetFlashUsed(status, TRUE);
            func_ov012_0216002c(0x94);
            func_ov036_021c1c68(flash, 1);
            flags = FieldStatus_GetFlashPerms(status2);
            flags &= ~FLD_FLASH_ALLOW;
            flags |= FLD_FLASH_ACTIVE;
            FieldStatus_SetFlashPerms(status2, flags);
        } else {
            return GAMEEVENT_DONE;
        }
        ++*state;
        break;
    case 2:
        if (func_ov036_021c1c6c(flash) == 3)
            return GAMEEVENT_DONE;
        break;
    }
    return GAMEEVENT_CONTINUE;
}

u32 EventDigCall_Check(HiddenEventContext *context) {
    if (func_ov012_02159b5c(context, 7) != 0) {
        if (func_ov012_02159440(context) != 0)
            return 3;
        return 0;
    }
    return 1;
}

GameEvent *EventDigCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;
    func_ov012_0216002c(0x5b);
    event = GameEvent_Create(context->gsys, NULL, EventDigCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventDigCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    ScriptWork *scriptWork;
    u16 param;

    switch (*state) {
    case 0:
        param = work->unk0C;
        scriptWork = EventScriptCall_Start(event, 0x271a, NULL, NULL, 0x15);
        ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
        ++*state;
        break;
    case 1:
        GameEvent_Replace(event, EventMapChangeDig_Create(work->gsys));
        break;
    }
    return GAMEEVENT_CONTINUE;
}

u32 EventTeleportCall_Check(HiddenEventContext *context) {
    if (func_ov012_02159b5c(context, 6) != 0) {
        if (func_ov012_02159440(context) != 0)
            return 3;
        return 0;
    }
    return 1;
}

GameEvent *EventTeleportCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;
    func_ov012_0216002c(0x64);
    event = GameEvent_Create(context->gsys, NULL, EventTeleportCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventTeleportCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    ScriptWork *scriptWork;
    u16 param;

    switch (*state) {
    case 0:
        param = work->unk0C;
        scriptWork = EventScriptCall_Start(event, 0x2719, NULL, NULL, 0x15);
        ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
        ++*state;
        break;
    case 1:
        GameEvent_Replace(event, EventMapChangeTeleport_Create(work->gsys));
        break;
    }
    return GAMEEVENT_CONTINUE;
}

u32 EventDivingCall_Check(HiddenEventContext *context) {
    if (func_ov012_02159b5c(context, 10) != 0) {
        if (func_ov012_02159440(context) != 0)
            return 3;
        return 0;
    }
    return 1;
}

GameEvent *EventDivingCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;
    event = GameEvent_Create(context->gsys, NULL, EventDivingCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventDivingCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    ScriptWork *scriptWork;
    u16 param;

    GameData_GetEventWork(GSYS_GetGameData(work->gsys));
    param = work->unk0C;
    scriptWork = EventScriptCall_Replace(event, 0x271c, 0, 0);
    ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
    return GAMEEVENT_CONTINUE;
}

u32 func_ov012_02159984(HiddenEventContext *context) {
    switch (func_ov012_02159b5c(context, 9)) {
    default:
        return FALSE;
    case 0:
        return TRUE;
    }
}

GameEvent *func_ov012_02159998(HiddenEventArgs *args, HiddenEventContext *context) {
    func_ov012_0216002c(0x1c0);
    return func_ov033_02178ca8(context->gsys, context->field, (u8)args->x);
}

GameEventReturnCode EventRuinsStrengthCall_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    ScriptWork *scriptWork;
    u16 param;
    HeapID heapId;

    GameData_GetEventWork(GSYS_GetGameData(work->gsys));
    heapId = Field_GetHeapID(GSYS_GetField(work->gsys));
    switch (*state) {
    case 0:
        param = work->unk0C;
        scriptWork = EventScriptCall_Start(event, 0x271e, NULL, NULL, heapId);
        ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
        ++*state;
        break;
    case 1:
        EventScriptCall_Replace(event, 0x28ed, 0, 0);
        break;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *EventRuinsStrengthCall_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;
    event = GameEvent_Create(context->gsys, NULL, EventRuinsStrengthCall_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

GameEventReturnCode EventRuinsFlash_Callback(GameEvent *event, u32 *state, void *data) {
    HiddenEventData *work = data;
    ScriptWork *scriptWork;
    u16 param;
    HeapID heapId;

    GameData_GetEventWork(GSYS_GetGameData(work->gsys));
    heapId = Field_GetHeapID(GSYS_GetField(work->gsys));
    switch (*state) {
    case 0:
        param = work->unk0C;
        scriptWork = EventScriptCall_Start(event, 0x271d, NULL, NULL, heapId);
        ScriptWork_SetParams(scriptWork, param, 0, 0, 0);
        ++*state;
        break;
    case 1:
        EventScriptCall_Replace(event, 0x28ec, 0, 0);
        break;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *EventRuinsFlash_Create(HiddenEventArgs *param, HiddenEventContext *context) {
    GameEvent *event;
    HiddenEventData *data;
    event = GameEvent_Create(context->gsys, NULL, EventRuinsFlash_Callback, 0x14);
    data = GameEvent_GetData(event);
    func_ov012_02159b40(data, param, context);
    return event;
}

HiddenCheckFunc GetHidenEventCheckFunc(HiddenEventContext *context, u32 kind) {
    if ((s32)kind >= 11) {
        return NULL;
    }
    if (IsZoneAbyssalRuinsInside(context->unk00)) {
        return HIDEN_EVENTS_RUINS[kind].check;
    }
    return HIDEN_EVENTS_NORMAL[kind].check;
}

HiddenCtorFunc GetHidenEventCtorFunc(HiddenEventContext *context, u32 kind) {
    if ((s32)kind >= 11) {
        return NULL;
    }
    if (IsZoneAbyssalRuinsInside(context->unk00)) {
        return HIDEN_EVENTS_RUINS[kind].create;
    }
    return HIDEN_EVENTS_NORMAL[kind].create;
}

void func_ov012_02159b40(HiddenEventData *data, HiddenEventArgs *param, HiddenEventContext *context) {
    u32 packedCoords;
    u32 extra;

    data->unk00 = (void *)0x19740205;
    data->unk04 = *(u32 *)&context->unk0C;
    packedCoords = *(u32 *)param;
    extra = (u32)param->gsys;
    data->unk10 = extra;
    *(u32 *)&data->unk0C = packedCoords;
    data->gsys = context->gsys;
}

u32 func_ov012_02159b5c(HiddenEventContext *context, u32 value) {
    u16 flags = context->flags;
    u32 mask = 1 << value;
    return (flags & mask) ? TRUE : FALSE;
}

BOOL func_ov012_02159b70(const HiddenArea *area, u16 x, u16 z, u16 flag, Field *field) {
    GameSystem *gsys;
    GameData *gameData;
    EventWork *eventWork;
    s32 dx;
    s32 dz;

    gsys = Field_GetGameSystem(field);
    gameData = GSYS_GetGameData(gsys);
    eventWork = GameData_GetEventWork(gameData);
    if (EventWork_FlagGet(eventWork, flag)) {
        return FALSE;
    }
    dx = area->x - x;
    dz = area->z - z;
    if (dx < 0) {
        dx = -dx;
    }
    if (dx < area->width) {
        if (dz < 0) {
            dz = -dz;
        }
        if (dz < area->height) {
            return TRUE;
        }
    }
    return FALSE;
}
