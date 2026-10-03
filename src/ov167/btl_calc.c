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

BOOL IsStatChangeValid(BattleMon *mon, u32 stat, s32 change);

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.
// Function name from swan.
BOOL RollEffectChance(u32 chance) {
    if (BattleRandom(100) < chance) {
        return TRUE;
    }
    return FALSE;
}

// Function names from swan.
u32 fixed_round(u32 value, u32 ratio) {
    u32 result;

    ratio *= value;
    result = ratio >> 12;
    if ((ratio & 0xfff) > 0x800) {
        result++;
    }
    return result;
}

// Function name from swan.
u32 GetRatioOverZero(u32 value, u32 ratio) {
    u32 result;

    result = fixed_round(value, ratio);
    if (result == 0) {
        result = 1;
    }
    return result;
}

u32 MultiplyValueByRatio(u32 value, u32 ratio) {
    u32 remainder;
    u32 result;

    value *= ratio;
    remainder = value % 100;
    result = value / 100;
    if (remainder >= 50) {
        result++;
    }
    return result;
}

// Function names from swan.
u32 DivideMaxHp(BattleMon *mon, u32 divisor) {
    return GetBattleMonStat(mon, 14) / divisor;
}

u32 DivideMaxHPZeroCheck(BattleMon *mon, u32 divisor) {
    u32 result;

    result = GetBattleMonStat(mon, 14) / divisor;
    if (result == 0) {
        result = 1;
    }
    return result;
}

// Function name from swan.
u32 GetNumMonsOnField(u32 battleType, u32 count) {
    if (battleType == 3) {
        count = 3;
    }
    return count;
}
