#include "types.h"
#include "app/funfest_mission.h"
#include "app/name_entry.h"
#include "battle/btl_setup.h"
#include "demo/shinka_demo.h"
#include "field/battle_facility.h"
#include "field/bsubway_scr.h"
#include "field/encounter.h"
#include "field/encounter_effect.h"
#include "field/entree_forest.h"
#include "field/entree_scripts.h"
#include "field/event_abyssal_ruins.h"
#include "field/event_cgear_shutdown.h"
#include "field/event_chatot.h"
#include "field/event_dendou_machine.h"
#include "field/event_dive.h"
#include "field/event_field_trade.h"
#include "field/event_fishing.h"
#include "field/event_fly.h"
#include "field/event_funfest_mission.h"
#include "field/event_game_manual.h"
#include "field/event_mapchange.h"
#include "field/event_phrase_input.h"
#include "field/event_pokemon_center.h"
#include "field/event_sound.h"
#include "field/event_sweet_scent.h"
#include "field/event_wild_battle.h"
#include "field/festival.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_actor_animation.h"
#include "field/field_display_control.h"
#include "field/field_effects.h"
#include "field/field_environment.h"
#include "field/field_event.h"
#include "field/field_fog.h"
#include "field/field_lifecycle.h"
#include "field/field_map.h"
#include "field/pdw_postman.h"
#include "field/field_move_scripts.h"
#include "field/field_move_tcb.h"
#include "field/field_party.h"
#include "field/field_player.h"
#include "field/field_prop.h"
#include "field/field_script.h"
#include "field/field_script_event.h"
#include "field/field_surf.h"
#include "field/field_task.h"
#include "field/field_visuals.h"
#include "field/fld_trade.h"
#include "field/funfest_scripts.h"
#include "field/ov131.h"
#include "field/pc_sound.h"
#include "field/player_state.h"
#include "field/subscreen.h"
#include "field/trial_house.h"
#include "field/unity_tower.h"
#include "field/zone.h"
#include "gfl/arc.h"
#include "gfl/bmpwin.h"
#include "gfl/fade.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/input.h"
#include "gfl/msg.h"
#include "gfl/net.h"
#include "gfl/overlay.h"
#include "gfl/random.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "pml/evolution.h"
#include "pml/poke_graphic.h"
#include "pml/poke_party.h"
#include "save/bag.h"
#include "save/box.h"
#include "save/bsubway_save.h"
#include "save/chatter.h"
#include "save/dream_world.h"
#include "save/high_link.h"
#include "save/join_avenue.h"
#include "save/mystery_gift.h"
#include "save/player_info.h"
#include "save/pokedex.h"
#include "save/records.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "save/trial_house.h"
#include "struct_decls.h"
#include "system/aeabi.h"
#include "system/game_comm.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/version.h"
#include "system/vm.h"

struct ActorAnimationFieldWork {
    u32 unk0;
    Field *field;
};

struct EventActorAnmProcWaitWork {
    FieldActorAnmProc *proc;
};

BOOL s0157_ActorAnimationInit(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    ActorAnimationFieldWork *fieldWork = ScriptWork_GetFieldWork(work);
    HeapID heapId = Field_GetHeapID(fieldWork->field);
    u16 actorId = ScriptReadAny(vm, env);
    VecFx32 pos;

    FieldPlayer_GetWPos(Field_GetPlayer(fieldWork->field), &pos);
    ScriptWork_SetActorAnmProc(work, FieldActorAnmProc_Create(fieldWork->field, actorId, &pos, heapId));
    return FALSE;
}

BOOL s0158_ActorAnimationFree(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);

    FieldActorAnmProc_Free(ScriptWork_GetActorAnmProc(work));
    ScriptWork_SetActorAnmProc(work, NULL);
    return FALSE;
}

BOOL s0159_ActorAnimationPlay(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    u16 animation = ScriptReadAny(vm, env);

    FieldActorAnmProc_Play(ScriptWork_GetActorAnmProc(work), animation);
    return FALSE;
}

GameEventReturnCode EventActorAnmProcWait_Callback(GameEvent *event, u32 *state, void *data) {
    EventActorAnmProcWaitWork *work = data;

    return FieldActorAnmProc_IsPlaying(work->proc) == TRUE ? GAMEEVENT_DONE : GAMEEVENT_CONTINUE;
}

BOOL s015A_ActorAnimationWait(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    GameEvent *event = GameEvent_Create(gsys, NULL, EventActorAnmProcWait_Callback, sizeof(EventActorAnmProcWaitWork));
    EventActorAnmProcWaitWork *eventWork = GameEvent_GetData(event);

    eventWork->proc = ScriptWork_GetActorAnmProc(work);
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

FieldActorAnmProc *FieldActorAnmProc_Create(Field *field, u16 actorId, const VecFx32 *pos, HeapID heapId) {
    MMSys *actors = Field_GetActorSystem(field);
    FieldAsyncProc *asyncProc =
        FieldAsyncProcManager_AddProc(OVERLAY_NONE, Field_GetAsyncProcMgr(field), &FIELD_ACTOR_ANM_ASYNC_PROC_TEMPLATE);
    FieldActorAnmProc *work = FieldAsyncProc_GetData(asyncProc);

    work->asyncProc = asyncProc;
    work->heapId = heapId;
    work->pos = *pos;
    work->actor = FindFieldActor(actors, actorId);
    return work;
}

void FieldActorAnmProc_Free(FieldActorAnmProc *proc) {
    FieldAsyncProc_End(proc->asyncProc);
}

void FieldActorAnmProc_Play(FieldActorAnmProc *proc, u16 animation) {
    proc->curve = GFL_G3DCurveCreateToLoadBuffer(proc->heapId, 0xc8, animation, 0xa, proc->unk4, sizeof(proc->unk4));
    proc->finished = TRUE;
    proc->animation = animation;
    FieldActorAnmProc_CommitTransform(proc->curve, proc->actor, &proc->pos);
    SetActorMovementFlag(proc->actor, 0x8000);
}

BOOL FieldActorAnmProc_IsPlaying(FieldActorAnmProc *proc) {
    return proc->finished == 0;
}

void FieldActorAnmProc_Update(FieldAsyncProc *asyncProc, Field *field, void *data) {
    FieldActorAnmProc *work = data;

    if (work->finished != 0 && work->finished == 1) {
        if (GFL_G3DCurveFrameStepLoop(work->curve, FX32_ONE) == 0) {
            FieldActorAnmProc_CommitTransform(work->curve, work->actor, &work->pos);
        } else {
            VecFx32 pos;

            GFL_G3DCurveFree(work->curve);
            work->curve = NULL;
            work->finished = 0;
            CopyActorWPos(work->actor, &pos);
            SetActorWPosAll(work->actor, &pos, GetActorFaceDir(work->actor));
            if (FIELD_ACTOR_ANM_IS_ALLOW_MOVE_ON_END[work->animation] != 0) {
                ClearActorMovementFlag(work->actor, 0x8000);
            }
        }
        FldAct_InvokeUpdateCallback(work->actor);
    }
}

void FieldActorAnmProc_Draw(FieldAsyncProc *asyncProc, Field *field, void *data) {
}

void FieldActorAnmProc_CommitTransform(G3DCurve *curve, FieldActor *actor, VecFx32 *pos) {
    VecFx32 translation;
    VecFx32 rotation;

    GFL_G3DCurveGetNowTranslation(curve, &translation);
    GFL_G3DCurveGetNowRotation(curve, &rotation);
    VEC_Add(&translation, pos, &translation);
    SetActorWPosValue(actor, &translation);

    switch (rotation.y) {
    case 0:
        ChangeActorDirection(actor, DIR_DOWN);
        break;
    case 90 * FX32_ONE:
    case -270 * FX32_ONE:
        ChangeActorDirection(actor, DIR_RIGHT);
        break;
    case 180 * FX32_ONE:
    case -180 * FX32_ONE:
        ChangeActorDirection(actor, DIR_UP);
        break;
    case 270 * FX32_ONE:
    case -90 * FX32_ONE:
        ChangeActorDirection(actor, DIR_LEFT);
        break;
    }
}
