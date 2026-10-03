#ifndef POKEBW2_FIELD_APP_CALL_H
#define POKEBW2_FIELD_APP_CALL_H

#include "types.h"
#include "struct_decls.h"

typedef BOOL (*FieldAppCallPredicate)(void *context, void *arg);

struct FieldAppCallParam {
    FieldAppCallPredicate canRetry;
    FieldAppCallPredicate callback1;
    FieldAppCallPredicate callback2;
    void *arg;
    void *context;
};

void EventFieldAppCall_ConvAppResultToEventType(u32 result, u32 *eventType);
void func_ov012_0215b76c(FieldAppCallParam *param, void *context, FieldAppCallPredicate canRetry,
                          FieldAppCallPredicate callback1, FieldAppCallPredicate callback2, void *arg);
BOOL FieldAppCallParam_CanRetry(FieldAppCallParam *param);
BOOL func_ov012_0215b7a8(FieldAppCallParam *param);
BOOL func_ov012_0215b7c0(FieldAppCallParam *param);

#endif // POKEBW2_FIELD_APP_CALL_H
