#include "field/field_script.h"
#include "field/mystery_gift_script.h"

u32 func_ov033_02177ed0(u32 index, u32 arg1, u32 arg2, u32 arg3) {
    u32 (*handler)(u32, u32, u32);

    handler = *(u32(**)(u32, u32, u32))(data_ov033_0217c410 + 24 * index);
    if (arg3 != 0 && handler != NULL) {
        return handler(arg1, arg2, arg3);
    }
    return 0;
}

u32 func_ov033_02177ef4(u32 index, u32 arg1, FieldScriptEnv *env) {
    WordSet *words;
    u32 (*handler)(WordSet *, u32, FieldScriptEnv *);

    words = ScriptWork_GetWordSet(FieldScriptEnv_GetScriptWork(env));
    handler = *(u32(**)(WordSet *, u32, FieldScriptEnv *))(data_ov033_0217c41c + 24 * index);
    if (arg1 != 0 && handler != NULL) {
        return handler(words, arg1, env);
    }
    return 7;
}

u32 func_ov033_02177f28(u32 index, u32 arg1, FieldScriptEnv *env) {
    WordSet *words;
    u32 (*handler)(WordSet *, u32, FieldScriptEnv *);

    words = ScriptWork_GetWordSet(FieldScriptEnv_GetScriptWork(env));
    handler = *(u32(**)(WordSet *, u32, FieldScriptEnv *))(data_ov033_0217c420 + 24 * index);
    if (arg1 != 0 && handler != NULL) {
        return handler(words, arg1, env);
    }
    return 8;
}

BOOL func_ov033_02177f5c(u32 index, u32 arg1, u32 arg2, u32 arg3) {
    void (*handler)(u32, u32, u32);

    handler = *(void (**)(u32, u32, u32))(data_ov033_0217c414 + 24 * index);
    if (arg3 != 0 && handler != NULL) {
        handler(arg1, arg2, arg3);
        return TRUE;
    }
    return FALSE;
}

u32 func_ov033_02177f84(u32 index, u32 arg1, u32 arg2, u32 arg3) {
    u32 (*handler)(u32, u32, u32);

    handler = *(u32(**)(u32, u32, u32))(data_ov033_0217c418 + 24 * index);
    if (arg3 != 0 && handler != NULL) {
        return handler(arg1, arg2, arg3);
    }
    return 0;
}
