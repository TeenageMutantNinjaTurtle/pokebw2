#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerDampStart(BattleEventItem *item, BtlServerFlow *flow, u32 monId) {
    BattleEventItem_AttachSkipCheckHandler(item, (void *)HandlerDampSkipCheck);
}
