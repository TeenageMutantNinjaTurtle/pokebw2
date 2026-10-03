#ifndef POKEBW2_FIELD_APP_CALL_H
#define POKEBW2_FIELD_APP_CALL_H

#include "types.h"
#include "struct_decls.h"
#include "field/player_action.h"
#include "system/game_event.h"

typedef BOOL (*FieldAppCallPredicate)(void *context, void *arg);

struct FieldAppCallParam {
    FieldAppCallPredicate canRetry;
    FieldAppCallPredicate callback1;
    FieldAppCallPredicate callback2;
    void *arg;
    void *context;
};

struct FieldAppCallInput {
    GameSystem *gameSystem;
    Field *field;
    GameEvent *parent;
    u32 unk0C;
    void *context;
    u32 unk14;
    FieldAppCallPredicate canRetry;
    FieldAppCallPredicate callback1;
    FieldAppCallPredicate callback2;
    void *arg;
};

struct FieldAppCallWork {
    u16 code;
    u16 pad02;
    void *callback04;
    void *callback08;
    void *callback0C;
    u32 unk10;
    GameEvent *event;
    FieldAppCallInput *input;
    u8 unk1C[4];
    FieldAppCallParam params;
    PlayerActionPerms perms;
    PlayerActionPossibilities action;
    u8 flag68;
    u8 pad69;
    u16 value6A;
    u8 unk6C[4];
    u32 unk70;
    u8 unk74[8];
};

GameEventReturnCode EventFieldAppCall_Callback(GameEvent *event, u32 *state, void *data);
GameEvent *EventFieldAppCall_Create(FieldAppCallInput *input, u16 code);
void EventFieldAppCall_ConvAppResultToEventType(u32 result, u32 *eventType);
void func_ov012_0215b754(FieldAppCallWork *work);
void func_ov012_0215b76c(FieldAppCallParam *param, void *context, FieldAppCallPredicate canRetry,
                          FieldAppCallPredicate callback1, FieldAppCallPredicate callback2, void *arg);
BOOL FieldAppCallParam_CanRetry(FieldAppCallParam *param);
BOOL func_ov012_0215b7a8(FieldAppCallParam *param);
BOOL func_ov012_0215b7c0(FieldAppCallParam *param);

#endif // POKEBW2_FIELD_APP_CALL_H
