#include "field/field_script.h"
#include "system/vm.h"

BOOL s0000_VMNop(VM *vm, FieldScriptEnv *env) {
    return FALSE;
}

BOOL s0001_VMNop2(VM *vm, FieldScriptEnv *env) {
    return FALSE;
}

BOOL s0002_VMHalt(VM *vm, FieldScriptEnv *env) {
    VM_Halt(vm);
    return TRUE;
}

BOOL swapToScrcmdEnvirDecPauseCtr(VM *vm, void *env) {
    return FieldScriptEnv_UpdateWaitCounter(env);
}

BOOL s0003_VMSleep(VM *vm, FieldScriptEnv *env) {
    FieldScriptEnv_SetWaitCounter(env, VM_Read16(vm));
    VM_SetNativeCallback(vm, swapToScrcmdEnvirDecPauseCtr);
    return TRUE;
}

BOOL s0004_VMCall(VM *vm, FieldScriptEnv *env) {
    u32 offset = VM_Read32(vm);

    VM_Call(vm, vm->pc + offset);
    return FALSE;
}

BOOL s0005_VMReturn(VM *vm, FieldScriptEnv *env) {
    VM_Return(vm);
    return FALSE;
}

BOOL s0006_DebugPrint(VM *vm, FieldScriptEnv *env) {
    FieldScriptEnv_GetGameData(env);
    ScriptReadAny(vm, env);
    return FALSE;
}

BOOL s0007_DebugStack(VM *vm, FieldScriptEnv *env) {
    VM_StackPop(vm);
    ScriptReadAny(vm, env);
    return FALSE;
}
