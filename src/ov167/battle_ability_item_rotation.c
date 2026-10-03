#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_pokeparam.h"

// Function names from swan.
void AbilityEvent_ItemRotationSleep(BattleMon *mon) {
    BattleEvent_ItemRotationSleep(GetMonID(mon), 4);
}

void AbilityEvent_ItemRotationWake(BattleMon *mon) {
    if (!BattleEvent_ItemRotationWake(GetMonID(mon), 4)) {
        AbilityEvent_AddItem(mon);
    }
}
