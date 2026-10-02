#include "field/field_script.h"
#include "save/event_work.h"
#include "system/game_data.h"
#include "system/vm.h"

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
