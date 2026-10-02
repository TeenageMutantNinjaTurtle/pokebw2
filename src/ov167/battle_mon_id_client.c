#include "battle/btl_main.h"

// Function name from swan.
u8 MonIDToClientID(u8 monId) {
    u8 i;
    u8 first;
    u8 last;

    for (i = 0; i < 4; i++) {
        first = data_ov167_021d6c24[i];
        last = first + 5;
        if (monId >= first && monId <= last) {
            return i;
        }
    }
    return 0;
}
