#include "battle/btl_display.h"
#include "battle/btl_handler.h"

// Function name from swan.
BOOL BattleHandler_SetString(BattleHandler *handler, BattleHandlerString *string) {
    u16 soundEffect;
    u32 flags;

    flags = string->flags;

    if (!((flags << 16) >> 31)) {
        switch ((flags & 0xff)) {
        case 1:
            ServerDisplay_StandardMessage(handler, string->message, ((flags << 17) >> 25), string->args);
            return TRUE;
        case 2:
            ServerDisplay_SetMessage(handler, string->message, ((flags << 17) >> 25), string->args);
            return TRUE;
        }
    } else {
        soundEffect = string->soundEffect;
        switch ((flags & 0xff)) {
        case 1:
            ServerDisplay_StandardMessageEx(handler, string->message, soundEffect, ((flags << 17) >> 25), string->args);
            return TRUE;
        case 2:
            ServerDisplay_SetMessageEx(handler, string->message, soundEffect, ((flags << 17) >> 25), string->args);
            return TRUE;
        }
    }
    return FALSE;
}
