#include "field/field_script.h"
#include "gfl/input.h"
#include "system/vm.h"

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
