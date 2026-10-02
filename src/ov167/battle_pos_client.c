#include "battle/btl_main.h"

// Function name from swan.
u8 BattlePosToClientID(BtlMainModule *mainModule, u8 pos) {
    return mainModule->posClientIds[pos];
}
