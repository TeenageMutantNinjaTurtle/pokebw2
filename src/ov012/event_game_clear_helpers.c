#include "field/event_game_clear.h"
#include "system/version.h"

u32 EventGameClear_Get3DDemoID(void) {
    u32 version = getGameVersion();

    if (version == 0x16) {
        goto seven;
    }
    if (version == 0x17) {
        goto six;
    }
seven:
    return 7;
six:
    return 6;
}

void EventGameClear_NextState(GameClearWork *work, u32 *state) {
    ++*state;
    work->current = work->states[*state];
}
