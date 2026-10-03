#include "battle/btl_handler.h"
#include "gfl/std.h"

struct BattleHandlerString {
    u16 message;
    u16 enabled : 8;
    u16 count : 7;
    u16 hasSound : 1;
    u32 args[8];
    u32 soundEffect;
};

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
