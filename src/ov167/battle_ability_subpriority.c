#include "battle/btl_ability.h"
#include "battle/btl_pokeparam.h"

// Function name from swan.
u16 calcAbilHandlerSubPriority(BattleMon *mon) {
    return RawBattleMonStat(mon, 12);
}
