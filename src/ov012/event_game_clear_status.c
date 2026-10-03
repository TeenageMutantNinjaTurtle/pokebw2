#include "field/event_game_clear.h"

void SetGameClearStatusSequence(GameClearWork *work) {
    u32 index = 0;

    work->states[1] = 2;
    work->states[2] = 3;
    work->states[3] = 4;
    work->states[4] = 5;
    work->states[5] = 6;
    work->states[0] = index;
    index += 6;
    if (work->unk08 == 0) {
        work->states[index++] = 11;
        work->states[index++] = 13;
    }
    work->states[index + 0] = 10;
    work->states[index + 1] = 12;
    work->states[index + 2] = 13;
    work->states[index + 3] = 19;
    work->states[index + 4] = 15;
    work->states[index + 5] = 21;
    work->states[index + 6] = 17;
    work->states[index + 7] = 4;
    work->states[index + 8] = 7;
    work->states[index + 9] = 8;
    work->states[index + 10] = 19;
    work->states[index + 11] = 16;
    work->states[index + 12] = 18;
    work->states[index + 13] = 23;
    work->states[index + 14] = 24;
    work->states[index + 15] = 4;
    work->states[index + 16] = 22;
    work->states[index + 17] = 14;
    work->states[index + 18] = 25;
    work->current = work->states[0];
}
