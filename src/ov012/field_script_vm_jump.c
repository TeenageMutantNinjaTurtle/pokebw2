#include "field/field_script.h"
#include "system/vm.h"

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
