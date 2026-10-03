#include "field/badge_gate.h"
#include "field/field.h"
#include "field/field_camera.h"
#include "field/field_exp_obj.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "save/event_work.h"
#include "system/game_event.h"
#include "system/game_system.h"

BOOL func_ov103_021eefbc(u32 badge, EventWork *work) {
    u16 *value;

    value = EventWork_GetWkPtr(work, data_ov103_021ef854[badge]);
    return *value == 2;
}

void func_ov103_021eefe0(Field *field) {
    BadgeGateWork *work;

    work = Field_GetGimmickWorkBlock(field, 0);
    FieldExpObj_FreeScene(work->expObj, 1);
    FieldExpObj_FreeScene(work->expObj, 2);
    FieldExpObj_FreeScene(work->expObj, 0);
    Field_DeleteGimmickWorkBlock(field, 0);
}

void func_ov103_021ef010(Field *field) {
    BadgeGateWork *work;

    work = Field_GetGimmickWorkBlock(field, 0);
    FieldExpObj_StepAllAnimations(work->expObj);
}

GameEvent *BadgeGate_CreateCheckEvent(GameSystem *gsys, u8 badge) {
    Field *field;
    GameEvent *event;
    BadgeGateCheckEventData *data;

    field = GSYS_GetField(gsys);
    event = GameEvent_Create(gsys, NULL, BadgeGate_CheckEvent, sizeof(BadgeGateCheckEventData));
    data = GameEvent_GetData(event);
    GSYS_GetGameData(gsys);
    sys_memset(data, 0, sizeof(BadgeGateCheckEventData));
    data->badge = badge;
    data->state = 0;
    data->gimmickWork = Field_GetGimmickWorkBlock(field, 0);
    return event;
}

GameEventReturnCode BadgeGate_CheckEvent(GameEvent *event, u32 *state, void *arg) {
    BadgeGateCheckEventData *data;
    BadgeGateAnimationEntry *entry0;
    BadgeGateAnimationEntry *entry1;
    BadgeGateAnimationEntry *entry2;
    FieldExpObjAnm *anm;
    fx32 frame;

    data = arg;
    entry0 = func_ov103_021ef1ac(data->gimmickWork, data->badge, 0);
    entry1 = func_ov103_021ef1ac(data->gimmickWork, data->badge, 1);
    entry2 = func_ov103_021ef1ac(data->gimmickWork, data->badge, 2);
    func_ov103_021ef188(data);
    data->state++;

    switch (*state) {
    case 0:
        FieldExpObj_SetActorHidden(entry1->expObj, entry1->scene, entry1->actor, TRUE);
        FieldExpObj_SetActorHidden(entry0->expObj, entry0->scene, entry0->actor, FALSE);
        func_ov103_021ef1dc(entry0, 0, FALSE);
        func_ov103_021ef1dc(entry0, 1, FALSE);
        (*state)++;
        break;
    case 1:
        anm = FieldExpObj_GetAnmInfo(entry0->expObj, entry0->scene, entry0->actor, 0);
        if (FieldExpObjAnm_IsPlaybackFinished(anm) == TRUE) {
            func_ov103_021ef1dc(entry0, 0, TRUE);
            (*state)++;
            return GAMEEVENT_CONTINUE_DIRECT;
        }
        break;
    case 2:
        FieldExpObj_SetActorHidden(entry0->expObj, entry0->scene, entry0->actor, TRUE);
        FieldExpObj_SetActorHidden(entry2->expObj, entry2->scene, entry2->actor, FALSE);
        frame = func_ov103_021ef200(data->gimmickWork);
        FieldExpObj_SetAnmFrame(entry2->expObj, entry2->scene, entry2->actor, 0, frame);
        func_ov103_021ef1dc(entry2, 0, FALSE);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

void func_ov103_021ef188(BadgeGateCheckEventData *data) {
    if (data->state == 0) {
        GFL_SndSEPlay(0x8a0);
    }
    if (data->state == 0x32) {
        GFL_SndSEPlay(0x89b);
    }
}

void *func_ov103_021ef1ac(void *work, u32 index, u32 group) {
    switch (group) {
    case 0:
        return (u8 *)work + 0x10 + index * 0x10;
    case 1:
        return (u8 *)work + 0x90 + index * 0x10;
    case 2:
        return (u8 *)work + 0x120 + index * 0x10;
    default:
        return NULL;
    }
}

typedef FieldExpObjAnm *(*BadgeGateAnmInfoGetter)(FieldExpObjSystem *, u16, u16, u32);

void func_ov103_021ef1dc(void *data, u32 anim, u32 paused) {
    BadgeGateAnimationEntry *entry;
    FieldExpObjAnm *anm;

    entry = data;
    // This caller passes the full animation index; the shared declaration narrows it for other callers.
    anm = ((BadgeGateAnmInfoGetter)FieldExpObj_GetAnmInfo)(entry->expObj, entry->scene, entry->actor, anim);
    FieldExpObjAnm_SetPaused(anm, paused);
}

u32 func_ov103_021ef200(void *work) {
    s32 i;
    BadgeGateAnimationEntry *entry;
    FieldExpObjAnm *anm;

    for (i = 0; i < 8; i++) {
        entry = func_ov103_021ef1ac(work, i, 2);
        anm = FieldExpObj_GetAnmInfo(entry->expObj, entry->scene, entry->actor, 0);
        if (!func_ov036_021b84ec(anm)) {
            return func_ov036_021b8520(entry->expObj, entry->scene, entry->actor, 0);
        }
    }
    return 0;
}

GameEvent *BadgeGate_CreateLastGateEvent(GameSystem *gsys) {
    Field *field;
    GameEvent *event;
    BadgeGateLastEventData *data;

    field = GSYS_GetField(gsys);
    event = GameEvent_Create(gsys, NULL, BadgeGate_LastGateEvent, sizeof(BadgeGateLastEventData));
    data = GameEvent_GetData(event);
    GSYS_GetGameData(gsys);
    sys_memset(data, 0, sizeof(BadgeGateLastEventData));
    data->gimmickWork = Field_GetGimmickWorkBlock(field, 0);
    data->camera = Field_GetCameraSystem(field);
    data->field = field;
    data->state = 0;
    FieldCamera_CoordsGetEyeOffset(data->camera, &data->eyeOffset);
    FieldCamera_CoordsGetTargetOffset(data->camera, &data->targetOffset);
    return event;
}