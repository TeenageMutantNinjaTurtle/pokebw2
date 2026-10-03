#include "field/app_call.h"
#include "gfl/std.h"

void func_ov012_0215b76c(FieldAppCallParam *param, void *context, FieldAppCallPredicate canRetry,
                          FieldAppCallPredicate callback1, FieldAppCallPredicate callback2, void *arg) {
    sys_memset(param, 0, sizeof(FieldAppCallParam));
    param->canRetry = canRetry;
    param->callback1 = callback1;
    param->callback2 = callback2;
    param->arg = arg;
    param->context = context;
}

BOOL FieldAppCallParam_CanRetry(FieldAppCallParam *param) {
    if (param->canRetry != NULL) {
        return param->canRetry(param->context, param->arg);
    }
    return TRUE;
}

BOOL func_ov012_0215b7a8(FieldAppCallParam *param) {
    if (param->callback1 != NULL) {
        return param->callback1(param->context, param->arg);
    }
    return TRUE;
}

BOOL func_ov012_0215b7c0(FieldAppCallParam *param) {
    if (param->callback2 != NULL) {
        return param->callback2(param->context, param->arg);
    }
    return TRUE;
}
