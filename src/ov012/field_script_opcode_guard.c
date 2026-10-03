#include "field/field_script.h"
#include "system/game_system.h"
#include "system/vm.h"

BOOL func_02042788(void);
void func_020428a0(void);
void func_02042860(u32 value);
void func_020429f0(void);
void func_020428e0(void);
BOOL func_020427a4(void);
void func_02005430(void);

BOOL FieldScript_CheckSCRID(u16 scriptId) {
    if (scriptId == 0x7d0) {
        return FALSE;
    }
    if (scriptId < 0x2aa2) {
        return TRUE;
    }
    return FALSE;
}

u32 FieldScript_IsVMFeatureSetReduced(u32 featureLevel) {
    if (featureLevel != 0) {
        return 1;
    }
    return 0;
}

void FieldScript_ThrowOpcodeAccessError(void) {
    if (func_02042788()) {
        func_020428a0();
        func_02042860(0);
        func_020429f0();
        do {
            func_020428e0();
        } while (!func_020427a4());
    }
    while (TRUE) {
        func_02005430();
    }
}

BOOL FieldScript_OpcodeGuard(VM *vm, void *env, void *gsys, u16 cmd) {
    u32 featureLevel;
    u32 allowed;

    GSYS_GetField((GameSystem *)gsys);
    FieldScriptEnv_IsReducedFeatureLevel((FieldScriptEnv *)env);
    featureLevel = FieldScriptEnv_GetFeatureLevel((FieldScriptEnv *)env);
    allowed = 0;
    switch (featureLevel) {
    case 0:
        allowed = EVCMD_PERM_TABLE[cmd].level0;
        break;
    case 1:
        allowed = EVCMD_PERM_TABLE[cmd].level1;
        break;
    case 2:
        allowed = EVCMD_PERM_TABLE[cmd].level2;
        break;
    }
    if (!allowed) {
        FieldScript_ThrowOpcodeAccessError();
    }
    return allowed;
}

void FieldScript_AttachOpcodeGuard(VM *vm) {
    FieldScriptEnv *env;
    GameSystem *gsys;

    env = VM_GetEnv(vm);
    gsys = FieldScriptEnv_GetGameSystem(env);
    VM_SetCallbackVerifier(vm, FieldScript_OpcodeGuard, gsys);
}
