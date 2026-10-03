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

void func_ov167_0219d504(BattleParty *party, u32 first, u32 second) {
    BattleMon *mon;

    mon = party->mons[first];
    party->mons[first] = party->mons[second];
    party->mons[second] = mon;
}

void func_ov167_0219d518(BattleParty *party, u8 index) {
    BattleMon *mon;

    mon = party->mons[index];
    for (; index < party->count - 1; index++) {
        party->mons[index] = party->mons[index + 1];
    }
    party->mons[index] = mon;
}

void func_ov167_0219d544(BattleParty *party, u32 pos, BattleMon **oldOut, BattleMon **newOut) {
    BattleMon *first;
    BattleMon *next;
    BattleMon *other;
    u32 index1;
    u32 index2;

    if (pos != 0 && pos != 1) {
        first = party->mons[0];
        index1 = func_ov167_0219d38c(pos);
        index2 = func_ov167_0219d3a4(pos);
        next = party->mons[index1];
        party->mons[0] = next;
        other = party->mons[index2];
        party->mons[index1] = other;
        party->mons[index2] = first;
        if (oldOut != NULL) {
            *oldOut = first;
        }
        if (newOut != NULL) {
            *newOut = party->mons[0];
        }
    }
}

s32 FindPartyMon(BattleParty *party, BattleMon *mon) {
    s32 i;

    // The original reloads the party count after checking each mon.
    for (i = 0; i < ((volatile BattleParty *)party)->count; i++) {
        if (party->mons[i] == mon) {
            return i;
        }
    }
    return -1;
}
