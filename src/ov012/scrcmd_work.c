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

ScriptSubwork *InitScriptSubwork(ScriptWork *work, HeapID heapId) {
    ScriptSubwork *subwork = GFL_HeapAllocate(heapId, sizeof(ScriptSubwork), TRUE, "scrcmd_work.c", 0x7b);

    subwork->work = work;
    subwork->gsys = ScriptWork_GetGameSystem(work);
    subwork->gameData = GSYS_GetGameData(subwork->gsys);
    subwork->mmSys = GameData_GetMMSys(subwork->gameData);
    subwork->actorMsgPosActual = 7;
    return subwork;
}

void func_ov012_021550e4(void *subwork) {
    GFL_HeapFree(subwork);
}

FieldScriptEnv *CreateFieldScriptEnv(const FieldScriptEnvArgs *args, HeapID heapId) {
    FieldScriptEnv *env =
        GFL_HeapAllocate(HEAPID_TAIL(heapId), sizeof(FieldScriptEnv), TRUE, "scrcmd_work.c", 0x97);

    env->heapId = heapId;
    env->args = *args;
    env->subwork = ScriptWork_GetSubwork(args->work);
    return env;
}

void FreeFieldScriptEnv(FieldScriptEnv *env) {
    if (env->ownedHeap != NULL) {
        GFL_HeapFree(env->ownedHeap);
    }
    if (env->msgData != NULL) {
        GFL_MsgDataFree(env->msgData);
    }
    func_ov012_021552c8(env);
    GFL_HeapFree(env);
}

HeapID FieldScriptEnv_GetHeapID(FieldScriptEnv *env) {
    return env->heapId;
}

u16 GetScriptEnvZoneID(FieldScriptEnv *env) {
    return env->args.zoneId;
}

u32 FieldScriptEnv_IsReducedFeatureLevel(FieldScriptEnv *env) {
    return env->args.reducedFeatureLevel;
}

u32 FieldScriptEnv_GetFeatureLevel(FieldScriptEnv *env) {
    return env->args.featureLevel;
}

GameSystem *FieldScriptEnv_GetGameSystem(FieldScriptEnv *env) {
    return env->subwork->gsys;
}

GameData *FieldScriptEnv_GetGameData(FieldScriptEnv *env) {
    return env->subwork->gameData;
}

MMSys *GetScrEnvMMdlSys(FieldScriptEnv *env) {
    return env->subwork->mmSys;
}

ScriptWork *FieldScriptEnv_GetScriptWork(FieldScriptEnv *env) {
    return env->subwork->work;
}

void *func_ov012_0215518c(FieldScriptEnv *env) {
    return *(void **)ScriptWork_GetFieldWork(FieldScriptEnv_GetScriptWork(env));
}

MsgData *GetFieldScriptMsgData(FieldScriptEnv *env) {
    return env->msgData;
}

u16 GetFieldScriptMsgFileNo(FieldScriptEnv *env) {
    return env->msgFileNo;
}

void setMapDisplayInfoPtr(FieldScriptEnv *env, void *info) {
    env->subwork->mapDisplayInfo = info;
}

void *getMapDisplayInfoPtr(FieldScriptEnv *env) {
    return env->subwork->mapDisplayInfo;
}

void SetSpecialMessageIconPtr(FieldScriptEnv *env, void *icon) {
    env->subwork->specialMessageIcon = icon;
}

void *func_ov012_021551c0(FieldScriptEnv *env) {
    return env->subwork->specialMessageIcon;
}

void *GetFieldScriptActorWk(FieldScriptEnv *env) {
    return env->subwork->actorWork;
}

void FieldScriptEnv_SetPlayerGridEventTCB(FieldScriptEnv *env, void *task) {
    env->subwork->playerGridEventTCB = task;
}

void *FieldScriptEnv_GetPlayerGridEventTCB(FieldScriptEnv *env) {
    return env->subwork->playerGridEventTCB;
}

u8 ActorMsgWin_GetPosActual(FieldScriptEnv *env) {
    return env->subwork->actorMsgPosActual;
}

void ActorMsgWin_SetPosActual(FieldScriptEnv *env, u8 pos) {
    env->subwork->actorMsgPosActual = pos;
}

u8 ActorMsgWin_GetPos(FieldScriptEnv *env) {
    return env->subwork->actorMsgPos;
}

void ActorMsgWin_SetPos(FieldScriptEnv *env, u8 pos) {
    env->subwork->actorMsgPos = pos;
}

void FieldScriptEnv_SetWaitCounter(FieldScriptEnv *env, u16 frames) {
    env->subwork->waitCounter = frames;
}

BOOL FieldScriptEnv_UpdateWaitCounter(FieldScriptEnv *env) {
    if (env->subwork->waitCounter == 0) {
        return TRUE;
    }
    env->subwork->waitCounter--;
    return FALSE;
}

void *GetScrEnvNowPkmVoice(FieldScriptEnv *env) {
    return env->subwork->nowPkmVoice;
}

void SetScrEnvNowPkmVoice(FieldScriptEnv *env, void *voice) {
    env->subwork->nowPkmVoice = voice;
}

void *FieldScriptEnv_GetElevatorTable(FieldScriptEnv *env) {
    return env->subwork->elevatorTable;
}

void FieldScriptEnv_SetElevatorTable(FieldScriptEnv *env, void *table) {
    env->subwork->elevatorTable = table;
}

void FieldScriptEnv_AddAcmdTask(FieldScriptEnv *env, FieldAcmdTCB *task) {
    int i;

    for (i = 0; i < 8; i++) {
        if (env->subwork->acmdTasks[i] == NULL) {
            env->subwork->acmdTasks[i] = task;
            return;
        }
    }
}

BOOL FieldScriptEnv_CheckAcmdQueueRunning(FieldScriptEnv *env) {
    int i;
    BOOL running = FALSE;

    for (i = 0; i < 8; i++) {
        if (env->subwork->acmdTasks[i] != NULL) {
            if (FieldAcmdTCB_CheckEnded(env->subwork->acmdTasks[i]) == TRUE) {
                FieldAcmdTCB_Remove(env->subwork->acmdTasks[i]);
                env->subwork->acmdTasks[i] = NULL;
            } else {
                running = TRUE;
            }
        }
    }

    return running;
}

void func_ov012_021552c8(FieldScriptEnv *env) {
    int i;

    for (i = 0; i < 8; i++) {
        if (env->subwork->acmdTasks[i] != NULL) {
            FieldAcmdTCB_Remove(env->subwork->acmdTasks[i]);
            env->subwork->acmdTasks[i] = NULL;
        }
    }
}

void SetFieldScriptEnvMsgData(FieldScriptEnv *env, u32 arcId, u32 fileNo) {
    env->msgData = GFL_MsgSysLoadData(FALSE, (u16)arcId, (u16)fileNo, env->heapId);
    env->msgFileNo = (u16)fileNo;
}

void FieldScriptEnv_Save(FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    env->ownedHeap = ScriptWork_CreateVarCopy(work);
}

void FieldScriptEnv_Restore(FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    ScriptWork_RestoreVarCopy(work, env->ownedHeap);
    env->ownedHeap = NULL;
}

void SetScrEnvVMIndex(FieldScriptEnv *env, u32 index) {
    env->vmIndex = index;
}

u8 FieldScriptEnv_GetVMIndex(FieldScriptEnv *env) {
    return env->vmIndex;
}
