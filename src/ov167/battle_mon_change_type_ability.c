#include "battle/btl_pokeparam.h"

// Function names from swan.
void ChangePokeType(BattleMon *mon, u16 type) {
    u8 *data;

    data = (u8 *)mon;
    data[0xf8] = PokeTypePair_GetType1(type);
    data[0xf9] = PokeTypePair_GetType2(type);
}

void ChangeAbility(BattleMon *mon, u16 ability) {
    *(u16 *)((u8 *)mon + 0x13c) = ability;
}
