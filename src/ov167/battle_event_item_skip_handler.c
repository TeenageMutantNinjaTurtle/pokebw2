#include "battle/btl_event.h"

// Function names from swan.
void BattleEventItem_AttachSkipCheckHandler(BattleEventItem *item, void *handler) {
    *(void **)((u8 *)item + 0xc) = handler;
}

void BattleEventItem_DetachSkipCheckHandler(BattleEventItem *item) {
    *(void **)((u8 *)item + 0xc) = NULL;
}
