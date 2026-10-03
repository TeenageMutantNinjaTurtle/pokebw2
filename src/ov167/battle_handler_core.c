#include "battle/btl_handler.h"
#include "gfl/std.h"
#include "battle/btl_action.h"

// Function names from swan.

void BattleHandler_StrClear(BattleHandlerString *string) {
    sys_memset(string, 0, 0x28);
    string->enabled = 0;
}

BOOL BattleHandler_StrIsEnabled(BattleHandlerString *string) {
    return string->enabled != 0;
}

void BattleHandler_StrSetup(BattleHandlerString *string, u32 enabled, u16 message) {
    string->enabled = enabled;
    string->message = message;
    string->count = 0;
}

void BattleHandler_AddArg(BattleHandlerString *string, u32 arg) {
    u16 count;

    count = string->count;
    if (count < 9) {
        string->count = count + 1;
        string->args[count] = arg;
    }
}

void BattleHandler_AddSoundEffect(BattleHandlerString *string, u32 soundEffect) {
    if (string->count < 9) {
        string->soundEffect = soundEffect;
        string->hasSound = 1;
    }
}

void *BattleHandler_PushWork(BattleHandler *handler, u32 command, void *data) {
    return func_ov167_021b0920((BtlActionState *)&handler->actionState, command, data);
}

void BattleHandler_PushRun(BattleHandler *handler, u32 command, void *data) {
    void *work;

    work = BattleHandler_PushWork(handler, command, data);
    BattleHandler_PopWork(handler, work);
}

void BattleHandler_PopWork(BattleHandler *handler, void *work) {
    BattleHandler_Execute(handler);
    PopWork((BtlActionState *)&handler->actionState, work);
}

u32 BattleHandler_Result(BattleHandler *handler) {
    BtlActionState *state;

    state = (BtlActionState *)&handler->actionState;
    if (IsUsed(state)) {
        if (func_ov167_021b0918(state)) {
            return 2;
        }
        return 1;
    }
    return 0;
}
