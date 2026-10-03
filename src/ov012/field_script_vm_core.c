#include "field/field_script.h"
#include "save/event_work.h"
#include "system/game_data.h"
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

BOOL s0014_VMRegSet8(VM *vm, FieldScriptEnv *env) {
    u8 index = VM_Read8(vm);
    u8 value = VM_Read8(vm);

    vm->work[index] = value;
    return FALSE;
}

BOOL s0015_VMRegSet32(VM *vm, FieldScriptEnv *env) {
    u8 index = VM_Read8(vm);
    u32 value = VM_Read32(vm);

    vm->work[index] = value;
    return FALSE;
}

BOOL s0016_VMRegMov(VM *vm, FieldScriptEnv *env) {
    u8 dst = VM_Read8(vm);
    u8 src = VM_Read8(vm);

    vm->work[dst] = vm->work[src];
    return FALSE;
}

u8 VMCmp(u32 left, u32 right) {
    if (left < right) {
        return 0;
    }
    if (left == right) {
        return 1;
    }
    return 2;
}

BOOL s0017_VMRegCmp8(VM *vm, FieldScriptEnv *env) {
    u8 left = vm->work[VM_Read8(vm)];
    u8 right = vm->work[VM_Read8(vm)];

    vm->cmpResult = VMCmp(left, right);
    return FALSE;
}

BOOL s0018_VMRegCmpConst8(VM *vm, FieldScriptEnv *env) {
    u8 left = vm->work[VM_Read8(vm)];
    u8 right = VM_Read8(vm);

    vm->cmpResult = VMCmp(left, right);
    return FALSE;
}

BOOL s0019_WorkCmpConst(VM *vm, FieldScriptEnv *env) {
    u16 left = *ScriptReadVar(vm, env);
    u16 right = VM_Read16(vm);

    vm->cmpResult = VMCmp(left, right);
    return FALSE;
}

BOOL s001A_WorkCmpWork(VM *vm, FieldScriptEnv *env) {
    u16 *left = ScriptReadVar(vm, env);
    u16 *right = ScriptReadVar(vm, env);

    vm->cmpResult = VMCmp(*left, *right);
    return FALSE;
}

BOOL s0008_VMStackPushConst(VM *vm, FieldScriptEnv *env) {
    VM_StackPush(vm, VM_Read16(vm));
    return FALSE;
}

BOOL s0009_VMStackPush(VM *vm, FieldScriptEnv *env) {
    VM_StackPush(vm, ScriptReadAny(vm, env));
    return FALSE;
}

BOOL s000A_VMStackPop(VM *vm, FieldScriptEnv *env) {
    u32 value = VM_StackPop(vm);

    *ScriptReadVar(vm, env) = value;
    return FALSE;
}

BOOL s000B_VMStackDiscard(VM *vm, FieldScriptEnv *env) {
    VM_StackPop(vm);
    return FALSE;
}

BOOL s000C_VMStackAdd(VM *vm, FieldScriptEnv *env) {
    u32 right = VM_StackPop(vm);
    u32 left = VM_StackPop(vm);

    VM_StackPush(vm, left + right);
    return FALSE;
}

BOOL s000D_VMStackSub(VM *vm, FieldScriptEnv *env) {
    u32 right = VM_StackPop(vm);
    u32 left = VM_StackPop(vm);

    VM_StackPush(vm, left - right);
    return FALSE;
}

BOOL s000E_VMStackMul(VM *vm, FieldScriptEnv *env) {
    u32 right = VM_StackPop(vm);
    u32 left = VM_StackPop(vm);

    VM_StackPush(vm, left * right);
    return FALSE;
}

BOOL s000F_VMStackDiv(VM *vm, FieldScriptEnv *env) {
    u32 right = VM_StackPop(vm);
    u32 left = VM_StackPop(vm);

    VM_StackPush(vm, left / right);
    return FALSE;
}

BOOL s0010_VMStackPushFlag(VM *vm, FieldScriptEnv *env) {
    EventWork *eventWork = GameData_GetEventWork(FieldScriptEnv_GetGameData(env));
    u16 flag = ScriptReadAny(vm, env);

    VM_StackPush(vm, EventWork_FlagGet(eventWork, flag));
    return FALSE;
}

BOOL s0011_VMStackCmp(VM *vm, FieldScriptEnv *env) {
    u32 right = VM_StackPop(vm);
    u32 left = VM_StackPop(vm);
    u16 comparison = VM_Read16(vm);
    BOOL result;

    switch (comparison) {
    case 0:
        result = left < right;
        break;
    case 1:
        result = left == right;
        break;
    case 2:
        result = left > right;
        break;
    case 3:
        result = left <= right;
        break;
    case 4:
        result = left >= right;
        break;
    case 5:
        result = left != right;
        break;
    case 6:
        result = left == 1 || right == 1;
        break;
    case 7:
        result = left == 1 && right == 1;
        break;
    default:
        result = FALSE;
        break;
    }
    VM_StackPush(vm, result);
    return FALSE;
}
