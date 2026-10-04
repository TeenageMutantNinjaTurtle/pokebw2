#include "field/event_sound.h"
#include "field/field_script.h"
#include "field/field_sound.h"
#include "field/field_status.h"
#include "field/player_state.h"
#include "gfl/key.h"
#include "save/event_work.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/vm.h"

BOOL s001B_RTCallGlobalAsync(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    u16 scriptId;
    u16 zoneId;

    FieldScriptEnv_GetGameSystem(env);
    work = FieldScriptEnv_GetScriptWork(env);
    scriptId = VM_Read16(vm);
    zoneId = FieldScriptEnv_GetZoneID(env);
    ScriptWork_AddVM(work, zoneId, scriptId);
    return TRUE;
}

BOOL ScriptNative_WaitFinishSubScript(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work;
    u8 index;

    work = FieldScriptEnv_GetScriptWork(env);
    index = FieldScriptEnv_GetVMIndex(env);
    if (!FieldScript_VMExists(work, index)) {
        FieldScriptEnv_Restore(env);
        return TRUE;
    }
    return FALSE;
}

BOOL s001C_RTCallGlobal(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys;
    ScriptWork *work;
    u16 scriptId;
    u32 level;
    u32 index;

    gsys = FieldScriptEnv_GetGameSystem(env);
    work = FieldScriptEnv_GetScriptWork(env);
    scriptId = VM_Read16(vm);
    if (!FieldScriptEnv_IsReducedFeatureLevel(env)) {
        index = ScriptWork_AddVM(work, FieldScriptEnv_GetZoneID(env), scriptId);
        SetScrEnvVMIndex(env, index);
        FieldScriptEnv_Save(env);
        VM_SetNativeCallback(vm, (VMCommand)ScriptNative_WaitFinishSubScript);
        return TRUE;
    }
    FieldScriptEnv_Save(env);
    level = FieldScriptEnv_GetFeatureLevel(env);
    FieldScript_Run(gsys, work, scriptId, level);
    FieldScriptEnv_Restore(env);
    return FALSE;
}

BOOL s001D_RTEndGlobal(VM *vm, FieldScriptEnv *env) {
    FieldScriptEnv_GetScriptWork(env);
    VM_Halt(vm);
    return TRUE;
}

BOOL s001E_VMJump(VM *vm, FieldScriptEnv *env) {
    u32 offset = VM_Read32(vm);

    VM_Jump(vm, vm->pc + offset);
    return FALSE;
}

BOOL s001F_VMJumpIf(VM *vm, FieldScriptEnv *env) {
    u8 condition = VM_Read8(vm);
    u32 offset = VM_Read32(vm);
    if (condition == 0xff) {
        if (VM_StackPop(vm) == 1) {
            goto done;
        }
        goto jump;
    }
    if (VM_CMP_LUT[condition][vm->cmpResult] != 1) {
        goto done;
    }
jump:
    VM_Jump(vm, vm->pc + offset);
done:
    return FALSE;
}

BOOL s0020_VMCallIf(VM *vm, FieldScriptEnv *env) {
    u8 condition = VM_Read8(vm);
    u32 offset = VM_Read32(vm);

    if (VM_CMP_LUT[condition][vm->cmpResult] == 1) {
        VM_Call(vm, vm->pc + offset);
    }
    return FALSE;
}

BOOL s0021_RTReserveScript(VM *vm, FieldScriptEnv *env) {
    u16 scriptId = VM_Read16(vm);
    FieldStatus *status = GameData_GetFieldStatus(FieldScriptEnv_GetGameData(env));

    FieldStatus_ReserveScript(status, scriptId);
    return FALSE;
}

BOOL s0022_FieldGetContinueFlag(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
    FieldStatus *status = GameData_GetFieldStatus(FieldScriptEnv_GetGameData(env));

    *value = FieldStatus_CheckContinueFlag(status);
    return FALSE;
}

BOOL s0023_FlagSet(VM *vm, FieldScriptEnv *env) {
    EventWork *eventWork = GameData_GetEventWork(FieldScriptEnv_GetGameData(env));
    u16 flag = ScriptReadAny(vm, env);

    EventWork_FlagSet(eventWork, flag);
    return FALSE;
}

BOOL s0024_FlagReset(VM *vm, FieldScriptEnv *env) {
    EventWork *eventWork = GameData_GetEventWork(FieldScriptEnv_GetGameData(env));
    u16 flag = ScriptReadAny(vm, env);

    EventWork_FlagReset(eventWork, flag);
    return FALSE;
}

BOOL s0025_FlagGet(VM *vm, FieldScriptEnv *env) {
    EventWork *eventWork = GameData_GetEventWork(FieldScriptEnv_GetGameData(env));
    u16 flag = ScriptReadAny(vm, env);
    u16 *value = ScriptReadVar(vm, env);

    *value = EventWork_FlagGet(eventWork, flag);
    return FALSE;
}

BOOL s0026_WorkAdd(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
    u16 operand = ScriptReadAny(vm, env);

    *value += operand;
    return FALSE;
}

BOOL s0027_WorkSub(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
    u16 operand = ScriptReadAny(vm, env);

    *value -= operand;
    return FALSE;
}

BOOL s002B_WorkMul(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
    u16 operand = ScriptReadAny(vm, env);

    *value *= operand;
    return FALSE;
}

BOOL s002C_WorkDiv(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
    u16 operand = ScriptReadAny(vm, env);

    *value /= operand;
    return FALSE;
}

BOOL s002D_WorkMod(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
    u16 operand = ScriptReadAny(vm, env);

    *value %= operand;
    return FALSE;
}

BOOL s0012_WorkAnd(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
    u16 operand = ScriptReadAny(vm, env);

    *value &= operand;
    return FALSE;
}

BOOL s0013_WorkOr(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);
    u16 operand = ScriptReadAny(vm, env);

    *value |= operand;
    return FALSE;
}

BOOL s0028_WorkSetConst(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);

    *value = VM_Read16(vm);
    return FALSE;
}

BOOL s0029_WorkGet(VM *vm, FieldScriptEnv *env) {
    u16 *dst = ScriptReadVar(vm, env);
    u16 *src = ScriptReadVar(vm, env);

    *dst = *src;
    return FALSE;
}

BOOL s002A_WorkSet(VM *vm, FieldScriptEnv *env) {
    u16 *value = ScriptReadVar(vm, env);

    *value = ScriptReadAny(vm, env);
    return FALSE;
}

BOOL s002E_ActorsPauseAll(VM *vm, FieldScriptEnv *env) {
    return PauseEventMModels(vm, env);
}

BOOL s002F_ActorsUnpauseAll(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    GameData *gameData = GSYS_GetGameData(gsys);
    BOOL wait = FALSE;

    EnableAllActorsMovementScr(env);
    if (FieldSnd_BGMGetStackIndex(GameData_GetFieldSoundSystem(gameData)) != 0) {
        ScriptWork_CallEvent(work, EventBGMPopAll_Create(gsys, 0));
        wait = TRUE;
    }
    return wait;
}

BOOL s0030_FinishAllEvents(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameEvent *event;

    FieldScriptEnv_GetGameSystem(env);
    event = EventFinishScriptSubEvents_Create(env);
    if (event == NULL) {
        return TRUE;
    }
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

BOOL testAB(VM *vm, void *env) {
    return (GCTX_HIDGetPressedKeys() & 3) != 0;
}

BOOL s0031_ABKeyWait(VM *vm, FieldScriptEnv *env) {
    VM_SetNativeCallback(vm, testAB);
    return TRUE;
}

BOOL ScriptNative_LastKeyWait(VM *vm, void *env) {
    return (GCTX_HIDGetPressedKeys() & 0xf3) != 0;
}

BOOL s0032_LastKeyWait(VM *vm, FieldScriptEnv *env) {
    VM_SetNativeCallback(vm, ScriptNative_LastKeyWait);
    return TRUE;
}

u16 *ScriptReadVar(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    u16 id = VM_Read16(vm);

    return ScriptWork_GetWkAddr(work, gameData, id);
}

u16 ScriptReadAny(VM *vm, FieldScriptEnv *env) {
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    u16 value = VM_Read16(vm);

    return ScriptWork_ResolveHybridValue(work, gameData, value);
}

u16 FieldScriptEnv_GetZoneID(FieldScriptEnv *env) {
    return PlayerState_GetZoneID(GameData_GetPlayerState(FieldScriptEnv_GetGameData(env)));
}
