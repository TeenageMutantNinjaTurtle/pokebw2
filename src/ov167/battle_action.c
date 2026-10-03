#include "types.h"
#include "battle/btl_ability.h"
#include "battle/btl_action.h"
#include "battle/btl_action_order.h"
#include "battle/btl_display.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"
#include "battle/btl_handler.h"
#include "battle/btl_item.h"
#include "battle/btl_main.h"
#include "battle/btl_math.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"
#include "battle/btl_setup.h"
#include "battle/btlv.h"
#include "constants/pokemon.h"
#include "gfl/std.h"
#include "pml/poke_party.h"
#include "pml/waza.h"
#include "save/bag.h"
#include "save/config.h"

// Function names from swan.
void BattleAction_SetFightParam(BattleAction *action, u16 move, u8 target) {
    action->raw = 0;
    action->bits.action = 1;
    action->bits.target = target;
    action->bits.move = move;
}

void BattleAction_ChangeFightTargetPos(BattleAction *action, u8 target) {
    if (action->bits.action == 1 && target != 6) {
        action->bits.target = target;
    }
}

// Function name from swan.
void BattleAction_SetNull(BattleAction *action) {
    action->bits.action = 0;
    action->raw &= 0xf;
}

void BattleAction_SetSkip(BattleAction *action) {
    action->bits.action = 7;
}

u32 BattleAction_GetAction(const BattleAction *action) {
    return action->bits.action;
}
