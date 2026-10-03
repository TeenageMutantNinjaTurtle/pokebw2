#include "field/field_script.h"

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
