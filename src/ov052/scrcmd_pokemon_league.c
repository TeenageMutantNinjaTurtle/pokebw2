#include "types.h"
#include "constants/sound.h"
#include "field/field.h"
#include "field/field_camera.h"
#include "field/field_script.h"
#include "field/pokemon_league_gimmicks.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/vm.h"

// The script plugin of the Pokémon League's rooms (plugin 3), commands from 1000. The Elite Four's rooms are numbered
// from 1 in the order of their cameras

void func_ov036_021b3da8(NoGridMapper *mapper, u32 a1, u32 a2);

static void func_ov052_021e5870(Field *field, u16 a1);
static u32 PokemonLeague_GetRoomCamera(u16 room);

static BOOL func_ov052_021e5800(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    Field *field = GSYS_GetField(FieldScriptEnv_GetGameSystem(env));
    u16 room = ScriptReadAny(vm, env);

    func_ov052_021e5870(field, room - 1);
    return FALSE;
}

// Sets the camera of an Elite Four's room
static BOOL PokemonLeagueCmd_SetCamera(VM *vm, FieldScriptEnv *env) {
    Field *field = GSYS_GetField(FieldScriptEnv_GetGameSystem(env));
    u16 room = ScriptReadAny(vm, env);
    FieldCamera *camera = Field_GetCameraSystem(field);

    FieldCamera_SetDefaultsIndex(camera, PokemonLeague_GetRoomCamera(room - 1));
    return FALSE;
}

static void func_ov052_021e5870(Field *field, u16 a1) {
    NoGridMapper *mapper = Field_GetNoGridMapper(field);

    func_ov036_021b3da8(mapper, 1, 0);
    func_ov036_021b3da8(mapper, 2, 0);
    if (a1 == 0) {
        func_ov036_021b3da8(mapper, 3, 0);
    }
}

static const u32 sRoomCameras[] = { 0x1c, 0x1d, 0x1e, 0x1f };

static u32 PokemonLeague_GetRoomCamera(u16 room) {
    return sRoomCameras[room];
}

// Grimsley's room
static BOOL func_ov052_021e58ac(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);

    func_ov123_021eed08(gsys, VM_Read16(vm));
    return FALSE;
}

// Grimsley's room
static BOOL func_ov052_021e58cc(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);

    func_ov123_021eed3c(gsys, VM_Read16(vm));
    return FALSE;
}

static BOOL PokemonLeagueCmd_PlayCaitlinAmbience(VM *vm, FieldScriptEnv *env) {
    FieldSnd_PlayAmbience(GameData_GetFieldSoundSystem(GSYS_GetGameData(FieldScriptEnv_GetGameSystem(env))),
                          SEQ_SE_SW_CATTLEYA_03);
    return FALSE;
}

// Caitlin's room
static BOOL func_ov052_021e590c(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);

    func_ov125_021eed10(gsys, VM_Read16(vm));
    return FALSE;
}

// Caitlin's room
static BOOL func_ov052_021e592c(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameEvent *event = func_ov125_021eed4c(FieldScriptEnv_GetGameSystem(env));

    if (event == NULL) {
        return FALSE;
    }
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

// Caitlin's room
static BOOL func_ov052_021e5954(VM *vm, FieldScriptEnv *env) {
    func_ov125_021eed6c(FieldScriptEnv_GetGameSystem(env));
    return FALSE;
}

// Caitlin's room
static BOOL func_ov052_021e5964(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    u16 actorId = VM_Read16(vm);

    func_ov125_021eed80(gsys, actorId, VM_Read16(vm));
    return FALSE;
}

// Shauntal's room
static BOOL func_ov052_021e598c(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameEvent *event = func_ov122_021eed14(FieldScriptEnv_GetGameSystem(env));

    if (event == NULL) {
        return FALSE;
    }
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

// Shauntal's room
static BOOL func_ov052_021e59b4(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);

    func_ov122_021eed40(gsys, VM_Read16(vm));
    return FALSE;
}

// Shauntal's room
static BOOL func_ov052_021e59dc(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    GameEvent *event = func_ov122_021eedcc(gsys, VM_Read16(vm));

    if (event == NULL) {
        return FALSE;
    }
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

// Shauntal's room
static BOOL func_ov052_021e5a14(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameEvent *event = func_ov122_021eedf8(FieldScriptEnv_GetGameSystem(env));

    if (event == NULL) {
        return FALSE;
    }
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

// Marshal's room
static BOOL func_ov052_021e5a3c(VM *vm, FieldScriptEnv *env) {
    func_ov124_021eecf0(FieldScriptEnv_GetGameSystem(env));
    return FALSE;
}

// Marshal's room
static BOOL func_ov052_021e5a4c(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);

    func_ov124_021eed20(gsys, VM_Read16(vm));
    return FALSE;
}

// Marshal's room
static BOOL func_ov052_021e5a6c(VM *vm, FieldScriptEnv *env) {
    func_ov124_021eed40(FieldScriptEnv_GetGameSystem(env));
    return FALSE;
}

// Marshal's room
static BOOL func_ov052_021e5a7c(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameEvent *event = func_ov124_021eed6c(FieldScriptEnv_GetGameSystem(env));

    if (event == NULL) {
        return FALSE;
    }
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

// The Champion's room
static BOOL func_ov052_021e5aa4(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameEvent *event = func_ov120_021eecf0(FieldScriptEnv_GetGameSystem(env));

    if (event == NULL) {
        return FALSE;
    }
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

// The Champion's room
static BOOL func_ov052_021e5acc(VM *vm, FieldScriptEnv *env) {
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    GameEvent *event = func_ov120_021eecf8(FieldScriptEnv_GetGameSystem(env));

    if (event == NULL) {
        return FALSE;
    }
    ScriptWork_CallEvent(work, event);
    return TRUE;
}

// The Champion's room
static BOOL func_ov052_021e5af4(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);

    func_ov120_021eed00(gsys, VM_Read16(vm));
    return FALSE;
}

// The Champion's room
static BOOL func_ov052_021e5b14(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);

    func_ov120_021eed1c(gsys, VM_Read16(vm));
    return FALSE;
}

// The Champion's room
static BOOL func_ov052_021e5b34(VM *vm, FieldScriptEnv *env) {
    func_ov120_021eed38(FieldScriptEnv_GetGameSystem(env));
    return FALSE;
}

const FieldScriptCommand POKEMON_LEAGUE_SCRIPT_COMMANDS[] = {
    func_ov052_021e5800,
    PokemonLeagueCmd_SetCamera,
    func_ov052_021e58ac,
    func_ov052_021e58cc,
    PokemonLeagueCmd_PlayCaitlinAmbience,
    func_ov052_021e590c,
    func_ov052_021e592c,
    func_ov052_021e5954,
    func_ov052_021e5964,
    func_ov052_021e598c,
    func_ov052_021e59b4,
    func_ov052_021e59dc,
    func_ov052_021e5a14,
    func_ov052_021e5a3c,
    func_ov052_021e5a4c,
    func_ov052_021e5a6c,
    func_ov052_021e5a7c,
    func_ov052_021e5aa4,
    func_ov052_021e5acc,
    func_ov052_021e5af4,
    func_ov052_021e5b14,
    func_ov052_021e5b34,
    (FieldScriptCommand)0xFFFFFFFF,
};
