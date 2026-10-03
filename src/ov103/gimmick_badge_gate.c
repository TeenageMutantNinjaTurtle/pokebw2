#include "types.h"
#include "field/badge_gate.h"
#include "field/field.h"
#include "field/field_camera.h"
#include "field/field_exp_obj.h"
#include "nitro/fx.h"
#include "gfl/g3d.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "save/event_work.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

// An actor of one of the gimmick's scenes
typedef struct {
    u32 scene;
    u32 actor;
    u32 unk08;
    FieldExpObjSystem *expObj;
} BadgeGateActor;

typedef struct {
    u16 unk00;
    FieldExpObjSystem *expObj;
    Field *field;
    EventWork *eventWork;
    // The actors of scenes 0, 1 and 2
    BadgeGateActor actors0[8];
    BadgeGateActor actors1[9];
    BadgeGateActor actors2[9];
    u32 last;
} BadgeGateWork;

typedef struct {
    BadgeGateWork *gimmickWork;
    u16 badge;
    u32 state;
    u8 unk0c[0x10];
} BadgeGateCheckEventData;

typedef struct {
    BadgeGateWork *gimmickWork;
    FieldCamera *camera;
    u8 unk08[0x10];
    u32 state;
    u8 unk1c[4];
    VecFx32 eyeOffset;
    VecFx32 targetOffset;
    Field *field;
} BadgeGateLastEventData;

void func_ov103_021eecfc(BadgeGateWork *work);
BOOL func_ov103_021eefbc(u32 badge, EventWork *work);
GameEventReturnCode BadgeGate_CheckEvent(GameEvent *event, u32 *state, void *data);
void func_ov103_021ef188(BadgeGateCheckEventData *data);
BadgeGateActor *func_ov103_021ef1ac(BadgeGateWork *work, u32 index, u32 scene);
void func_ov103_021ef1dc(BadgeGateActor *actor, u16 anm, BOOL paused);
fx32 func_ov103_021ef200(BadgeGateWork *work);
GameEventReturnCode BadgeGate_LastGateEvent(GameEvent *event, u32 *state, void *data);
void func_ov103_021ef5dc(BadgeGateLastEventData *data);
void func_ov103_021ef788(FieldExpObjSystem *system);

extern const G3DSceneSetup data_ov103_021ef814;
extern const G3DSceneSetup data_ov103_021ef824;
extern const G3DSceneSetup data_ov103_021ef844;
extern const u16 data_ov103_021ef854[];

void func_ov103_021eec80(Field *field) {
    HeapID heapId;
    GameData *gameData;
    BadgeGateWork *work;

    heapId = Field_GetHeapID(field);
    gameData = GSYS_GetGameData(Field_GetGameSystem(field));
    GameData_GetGimmickState(gameData);
    work = Field_AllocGimmickWorkBlock(field, 0, heapId, sizeof(BadgeGateWork));
    work->unk00 = 0x15;
    work->field = field;
    work->expObj = Field_GetExpObjSystem(field);
    work->eventWork = GameData_GetEventWork(gameData);
    work->last = 0;
    LoadFieldExpandObjData(work->expObj, &data_ov103_021ef814, 0);
    LoadFieldExpandObjData(work->expObj, &data_ov103_021ef824, 1);
    LoadFieldExpandObjData(work->expObj, &data_ov103_021ef844, 2);
    func_ov103_021eecfc(work);
}

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
    BadgeGateActor *entry0;
    BadgeGateActor *entry1;
    BadgeGateActor *entry2;
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

BadgeGateActor *func_ov103_021ef1ac(BadgeGateWork *work, u32 index, u32 scene) {
    switch (scene) {
    case 0:
        return &work->actors0[index];
    case 1:
        return &work->actors1[index];
    case 2:
        return &work->actors2[index];
    default:
        return NULL;
    }
}

void func_ov103_021ef1dc(BadgeGateActor *actor, u16 anm, BOOL paused) {
    FieldExpObjAnm_SetPaused(FieldExpObj_GetAnmInfo(actor->expObj, actor->scene, actor->actor, anm), paused);
}

fx32 func_ov103_021ef200(BadgeGateWork *work) {
    s32 i;
    BadgeGateActor *entry;
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

void func_ov103_021ef5dc(BadgeGateLastEventData *data) {
    if (data->state == 100) {
        GFL_SndSEPlay(0x89d);
    }
    if (data->state == 0) {
        GFL_SndSEPlay(0x89c);
    }
    if (data->state == 140) {
        GFL_SndSEPlay(0x89e);
        GFL_SndSEPlay(0x8a1);
    }
    if (data->state == 0x14a) {
        GFL_SndSEPlay(0x89f);
    }
}

void func_ov103_021ef788(FieldExpObjSystem *system) {
    FieldExpObj_FreeScene(system, 3);
}
