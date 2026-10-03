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
extern const BattleEventHandlerEntry data_ov167_021d78d4[];

extern const BattleEventHandlerEntry data_ov167_021d78cc[];

extern const BattleEventHandlerEntry data_ov167_021d78c4[];

// Function name from swan.
PokeTypePair PokeTypePair_Make(u32 type1, u32 type2) {
    u32 first;
    u32 second;

    first = (type1 << 24) >> 16;
    second = (type2 << 24) >> 24;
    return (u16)(first | second);
}

PokeTypePair func_ov167_021ce530(u32 type) {
    return PokeTypePair_Make(type, type);
}

u8 PokeTypePair_GetType1(PokeTypePair pair) {
    return (u8)(pair >> 8);
}

u8 PokeTypePair_GetType2(PokeTypePair pair) {
    return (u8)pair;
}

void func_ov167_021ce54c(PokeTypePair pair, u8 *type1, u8 *type2) {
    *type1 = PokeTypePair_GetType1(pair);
    *type2 = PokeTypePair_GetType2(pair);
}

BOOL func_ov167_021ce564(PokeTypePair pair, u32 type) {
    if (PokeTypePair_GetType1(pair) == type) {
        return TRUE;
    }
    if (PokeTypePair_GetType2(pair) == type) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov167_021ce588(PokeTypePair first, PokeTypePair second) {
    if (PokeTypePair_GetType1(first) == PokeTypePair_GetType1(second)) {
        return TRUE;
    }
    if (PokeTypePair_GetType1(first) == PokeTypePair_GetType2(second)) {
        return TRUE;
    }
    if (PokeTypePair_GetType2(first) == PokeTypePair_GetType1(second)) {
        return TRUE;
    }
    if (PokeTypePair_GetType2(first) == PokeTypePair_GetType2(second)) {
        return TRUE;
    }
    return FALSE;
}

BOOL PokeTypePair_IsMonotype(PokeTypePair pair) {
    return PokeTypePair_GetType1(pair) == PokeTypePair_GetType2(pair);
}
