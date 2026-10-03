#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"

// Function name from swan.
void AddBattleMonToParty(BattleParty *party, BattleMon *mon) {
    party->mons[party->count++] = mon;
}

void func_ov167_0219d454(BattleParty *party) {
    u32 i;
    u32 processed;

    processed = 0;
    i = 0;
    for (; processed < party->count; processed++) {
        if (CanPokemonBattle(party->mons[i])) {
            i++;
        } else {
            func_ov167_0219d518(party, i);
        }
    }
}

u8 GetNumMonsInParty(BattleParty *party) {
    return party->count;
}

u8 GetAlivePartyCount(BattleParty *party) {
    s32 i;
    s32 count;

    i = 0;
    count = 0;
    for (; i < party->count; i++) {
        if (CanPokemonBattle(party->mons[i])) {
            count++;
        }
    }
    return count;
}

u8 func_ov167_0219d4b8(BattleParty *party, s32 index) {
    s32 i;
    u32 count;

    count = 0;
    for (i = index; i < party->count; i++) {
        if (CanPokemonBattle(party->mons[i])) {
            count++;
        }
    }
    return count;
}

BattleMon *func_ov167_0219d4e4(BattleParty *party, u32 index) {
    if (index < party->count) {
        return party->mons[index];
    }
    return NULL;
}

BattleMon *GetBattleMonFromParty(BattleParty *party, u8 index) {
    if (index < party->count) {
        return party->mons[index];
    }
    return 0;
}
