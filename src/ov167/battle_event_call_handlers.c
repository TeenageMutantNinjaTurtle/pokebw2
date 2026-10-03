#include "battle/btl_event.h"

// Function names from swan.
void BattleEvent_ForceCallHandlers(void *context, u32 event) {
    func_ov167_021bc918(context, event, 7, 0);
}

void BattleEvent_CallHandlers(void *context, u32 event) {
    func_ov167_021bc918(context, event, 7, 1);
}
