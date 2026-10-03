#include "types.h"
#include "battle/battle_result.h"
#include "battle/trainer_data.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "field/app_call.h"
#include "field/black_tower_gimmick.h"
#include "field/day_care.h"
#include "field/encounter.h"
#include "field/event_3d_demo.h"
#include "field/event_action_call.h"
#include "field/event_actor_move.h"
#include "field/event_battle_lose.h"
#include "field/event_battle_video.h"
#include "field/event_chatot.h"
#include "field/event_data.h"
#include "field/event_fly.h"
#include "field/event_game_clear.h"
#include "field/event_irc.h"
#include "field/event_mapchange.h"
#include "field/event_save.h"
#include "field/event_sound.h"
#include "field/event_sweet_scent.h"
#include "field/event_wifibattlematch.h"
#include "field/field.h"
#include "field/field_acmd.h"
#include "field/field_actor.h"
#include "field/field_chunk.h"
#include "field/field_event.h"
#include "field/field_map.h"
#include "field/field_menu.h"
#include "field/field_player.h"
#include "field/field_script.h"
#include "field/field_script_event.h"
#include "field/field_script_plugin.h"
#include "field/field_script_supervisor.h"
#include "field/field_sound.h"
#include "field/field_status.h"
#include "field/field_visuals.h"
#include "field/hidden_event.h"
#include "field/item_use_block.h"
#include "field/player_action.h"
#include "field/player_state.h"
#include "field/pleasure_boat.h"
#include "field/script_network.h"
#include "field/shortcut_menu.h"
#include "field/skill_map_effect.h"
#include "field/stadium_script.h"
#include "field/subscreen.h"
#include "field/trainer_script.h"
#include "field/zone.h"
#include "gfl/arc.h"
#include "gfl/g3d.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/input.h"
#include "gfl/msg.h"
#include "gfl/overlay.h"
#include "gfl/random.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "nitro/fx.h"
#include "nitro/os.h"
#include "nitro/rtc.h"
#include "pml/item.h"
#include "pml/move_reminder.h"
#include "pml/personal.h"
#include "pml/poke_party.h"
#include "save/bag.h"
#include "save/box.h"
#include "save/config.h"
#include "save/encounter.h"
#include "save/event_work.h"
#include "save/medal_box.h"
#include "save/player_info.h"
#include "save/pokedex.h"
#include "save/save_control.h"
#include "save/shortcut.h"
#include "save/trainer_card.h"
#include "system/dsi.h"
#include "system/game_comm.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/season.h"
#include "system/version.h"
#include "system/vm.h"

void UpdateScriptFieldWk(void *fieldWork, GameSystem *gsys) {
    Field *field;
    void **ptr;

    field = GSYS_GetField(gsys);
    sys_memset32(0, fieldWork, 8);
    ptr = fieldWork;
    ptr[1] = field;
    if (field != NULL) {
        ptr[0] = Field_GetMsgBGSys(field);
    }
}

ScriptWork *ScriptWork_Create(HeapID heapId, GameSystem *gsys, GameEvent *event, u16 scriptId, u32 arg4, u32 featureLevel) {
    ScriptWork *work;
    u32 reduced;

    work = GFL_HeapAllocate(heapId, sizeof(ScriptWork), TRUE, "script_work.c", 0xaf);
    work->unk00 = 0x3643f;
    work->heapId = heapId;
    work->gsys = gsys;
    work->event = event;
    work->scriptId = scriptId;
    work->parentActor = NULL;
    work->unk20 = arg4;
    work->featureLevel = featureLevel;
    reduced = FieldScript_IsVMFeatureSetReduced(featureLevel);
    work->reducedFeatureLevel = reduced;
    if (reduced == 0) {
        work->wordSet = GFL_WordSetSystemCreate(0x1c, 0x40, heapId);
        work->mainStrBuf = GFL_StrBufCreate(0x500, heapId);
        work->altStrBuf = GFL_StrBufCreate(0x500, heapId);
    } else {
        work->wordSet = NULL;
        work->mainStrBuf = NULL;
        work->altStrBuf = NULL;
    }
    work->subwork = InitScriptSubwork(work, heapId);
    UpdateScriptFieldWk(work->fieldWork, gsys);
    if (work->reducedFeatureLevel == 0) {
        FieldScriptSubEvent_ResetAll();
    }
    return work;
}

void ScriptWork_Free(ScriptWork *work) {
    work->unk00 = 0;
    if (work->wordSet != NULL) {
        GFL_WordSetSystemFree(work->wordSet);
    }
    if (work->mainStrBuf != NULL) {
        GFL_StrBufFree(work->mainStrBuf);
    }
    if (work->altStrBuf != NULL) {
        GFL_StrBufFree(work->altStrBuf);
    }
    func_ov012_021550e4(work->subwork);
    GFL_HeapFree(work);
}

GameEvent *ScriptWork_GetEvent(ScriptWork *work) {
    return work->event;
}

GameSystem *ScriptWork_GetGameSystem(ScriptWork *work) {
    return work->gsys;
}

void *ScriptWork_GetFieldWork(ScriptWork *work) {
    UpdateScriptFieldWk(work->fieldWork, work->gsys);
    return work->fieldWork;
}

void *ScriptWork_GetSubwork(ScriptWork *work) {
    return work->subwork;
}

WordSet *ScriptWork_GetWordSet(ScriptWork *work) {
    return work->wordSet;
}

StrBuf *ScriptWork_GetMainStrBuf(ScriptWork *work) {
    return work->mainStrBuf;
}

StrBuf *ScriptWork_GetAltStrBuf(ScriptWork *work) {
    return work->altStrBuf;
}

void func_ov012_02153ed0(ScriptWork *work, void *value) {
    work->unk38 = value;
}

void *func_ov012_02153ed4(ScriptWork *work) {
    return work->unk38;
}

u32 *ScriptWork_GetSEBitMask(ScriptWork *work) {
    return &work->seBitMask;
}

u16 ScriptWork_GetSCRID(ScriptWork *work) {
    return work->scriptId;
}

FieldActor *ScriptWork_GetParentActor(ScriptWork *work) {
    return work->parentActor;
}

void ScriptWork_SetParentActor(ScriptWork *work, FieldActor *actor) {
    work->parentActor = actor;
    if (actor != NULL) {
        *ScriptWork_GetLocalWork(work, 0x8011) = GetActorUID(actor);
    }
}

void **ScriptWork_GetUserHeapPtr(ScriptWork *work) {
    return &work->userHeap;
}

void *ScriptWork_GetUserHeap(ScriptWork *work) {
    return work->userHeap;
}

void ScriptWork_FreeUserHeap(ScriptWork *work) {
    if (work->userHeap != NULL) {
        GFL_HeapFree(work->userHeap);
        work->userHeap = NULL;
    }
}

u16 *ScriptWork_GetLocalWork(ScriptWork *work, u16 id) {
    return &work->localWork[id - 0x8000];
}

u16 *ScriptWork_GetWkAddr(ScriptWork *work, GameData *gameData, u16 id) {
    EventWork *eventWork = GameData_GetEventWork(gameData);
    if (id < 0x4000) {
        return NULL;
    }
    if (id < 0x8000) {
        return EventWork_GetWkPtr(eventWork, id);
    }
    if (id < 0xc000) {
        return ScriptWork_GetLocalWork(work, id);
    }
    return NULL;
}

u16 ScriptWork_ResolveHybridValue(ScriptWork *work, GameData *gameData, u16 value) {
    u16 *ptr = ScriptWork_GetWkAddr(work, gameData, value);
    if (ptr != NULL) {
        value = *ptr;
    }
    return value;
}

BOOL ScriptWork_SetWkValue(ScriptWork *work, u16 id, u32 value) {
    GameData *gameData = GSYS_GetGameData(work->gsys);
    u16 *ptr = ScriptWork_GetWkAddr(work, gameData, id);
    if (ptr == NULL) {
        return FALSE;
    }
    *ptr = value;
    return TRUE;
}

void ScriptWork_SetParams(ScriptWork *work, u16 param0, u32 param1, u16 param2, u16 param3) {
    ScriptWork_SetWkValue(work, 0x8000, param0);
    ScriptWork_SetWkValue(work, 0x8001, param1);
    ScriptWork_SetWkValue(work, 0x8002, param2);
    ScriptWork_SetWkValue(work, 0x8003, param3);
}

void *ScriptWork_CreateVarCopy(ScriptWork *work) {
    void *copy;
    u16 *vars;

    copy = GFL_HeapAllocate(work->heapId, 0x7e, TRUE, "script_work.c", 0x21b);
    vars = ScriptWork_GetLocalWork(work, 0x8020);
    sys_memcpy16(vars, copy, 0x7e);
    return copy;
}

void ScriptWork_RestoreVarCopy(ScriptWork *work, void *copy) {
    u16 *vars;

    vars = ScriptWork_GetLocalWork(work, 0x8020);
    sys_memcpy16(copy, vars, 0x7e);
    GFL_HeapFree(copy);
}

void ScriptWork_SetActorAnmProc(ScriptWork *work, FieldActorAnmProc *proc) {
    work->actorAnmProc = proc;
}

FieldActorAnmProc *ScriptWork_GetActorAnmProc(ScriptWork *work) {
    return work->actorAnmProc;
}

void ScriptWork_SetStadiumTrainers(ScriptWork *work, void *trainers) {
    work->stadiumTrainers = trainers;
}

void *ScriptWork_GetStadiumTrainers(ScriptWork *work) {
    return work->stadiumTrainers;
}

void *ScriptWork_GetTrainerState(ScriptWork *work, int index) {
    return work->trainerState[index];
}
