#include "types.h"
#include "field/el_scoreboard.h"
#include "field/encounter.h"
#include "field/field.h"
#include "field/field_environment.h"
#include "field/field_exp_obj.h"
#include "field/field_exp_obj_gimmick_ov104.h"
#include "field/field_map.h"
#include "field/field_script.h"
#include "field/zone.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "save/event_work.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/rtc.h"
#include "system/version.h"

struct FieldExpObjGimmickOv104GateEventData {
    GameSystem *gameSystem;
    Field *field;
    u16 id;
    u8 padding[0x16];
};

void func_ov104_021efc6c(FieldExpObjGimmickOv104State *state, FieldExpObjGimmickOv104MessageArg *arg) {
    if (state->capacity > state->count) {
        state->messages[state->count] = func_ov104_021efe88(state, arg, state->count);
        state->count++;
    }
}

void func_ov104_021efc8c(FieldExpObjGimmickOv104State *state) {
    s32 i;

    GFL_FontFree(state->font);
    for (i = 0; i < state->count; i++) {
        func_ov104_021f0080(state->messages[i]);
    }
    GFL_HeapFree(state->messages);
    GFL_HeapFree(state->flags);
    GFL_HeapFree(state);
}

void func_ov104_021efcc4(FieldExpObjGimmickOv104State *state, u32 amount) {
    s32 i;

    for (i = 0; i < state->count; i++) {
        func_ov104_021f00bc(state, state->messages[i], amount);
    }
    state->current += amount;
}

s32 func_ov104_021efcf0(FieldExpObjGimmickOv104State *state) {
    return state->current;
}

u16 func_ov104_021efcf4(FieldExpObjGimmickOv104State *state) {
    return state->heapId;
}

u8 func_ov104_021efcf8(FieldExpObjGimmickOv104State *state) {
    return state->count;
}

void func_ov104_021f0080(FieldExpObjGimmickOv104Message *message) {
    ElScoreboard_Free(message->scoreboard);
    GFL_HeapFree(message);
}

void func_ov104_021f0094(FieldExpObjGimmickOv104Message *message) {
    if (message->active != 1) {
        message->active = 1;
        message->pending = 0;
        message->elapsed = 0;
        GFL_G3DActorBindAnm(message->actor, message->animation);
        GFL_G3DActorResetAnmFrame(message->actor, message->animation);
    }
}

void func_ov104_021f00bc(FieldExpObjGimmickOv104State *state, FieldExpObjGimmickOv104Message *message, u32 amount) {
    s32 next;

    if (message->active == 1) {
        ElScoreboard_Update(message->scoreboard);
        GFL_G3DActorStepAnmFrame(message->actor, message->animation, amount);
        message->elapsed += amount;
        if (message->triggerTime < message->elapsed && message->pending != 1) {
            next = (message->index + 1) % state->count;
            state->flags[next] = 1;
            message->pending = 1;
        }
        if (message->duration < message->elapsed) {
            func_ov104_021f0130(message);
        }
    } else if (state->flags[message->index] == 1) {
        func_ov104_021f0094(message);
        state->flags[message->index] = 0;
    }
}

void func_ov104_021f0130(FieldExpObjGimmickOv104Message *message) {
    if (message->active == 1) {
        message->active = 0;
        GFL_G3DActorUnbindAnm(message->actor, message->animation);
        GFL_G3DActorResetAnmFrame(message->actor, message->animation);
    }
}

BOOL func_ov104_021f0150(void *dest, u32 arcId, u32 fileId) {
    GFL_ArcSysReadRange(dest, arcId, fileId, 0, 0x7c);
    return TRUE;
}

GameEvent *func_ov104_021f02fc(GameSystem *gsys, Field *field, u32 id) {
    GameEvent *event;
    struct FieldExpObjGimmickOv104GateEventData *data;

    event = GameEvent_Create(gsys, 0, func_ov104_021f0160, sizeof(struct FieldExpObjGimmickOv104GateEventData));
    data = GameEvent_GetData(event);
    data->gameSystem = gsys;
    data->field = field;
    data->id = id;
    return event;
}

BOOL func_ov104_021f0324(struct FieldExpObjGimmickOv104ResEntry *entry, u32 arcId, u32 fileId) {
    GFL_ArcSysReadRange(entry, arcId, fileId, 0, 0x24);
    return TRUE;
}

BOOL func_ov104_021f0334(struct FieldExpObjGimmickOv104ResEntry *entry, u16 zone) {
    if (entry->zones[0] == 0x267 && entry->zones[1] == 0x267 && entry->zones[2] == 0x267 && entry->zones[3] == 0x267) {
        return TRUE;
    }
    if (entry->zones[0] == zone || entry->zones[1] == zone || entry->zones[2] == zone || entry->zones[3] == zone) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov104_021f037c(struct FieldExpObjGimmickOv104ResEntry *entry) {
    if (entry->unk00 == 0) {
        return TRUE;
    }
    if (entry->unk00 == getGameVersion()) {
        return TRUE;
    }
    return FALSE;
}
