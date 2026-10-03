#include "battle/btl_field.h"
#include "battle/btl_pokeparam.h"
#include "pml/poke_party.h"

// Function names from swan.
u32 func_ov167_021bb07c(BattleMon *mon, u32 stat) {
    switch (stat) {
    case 9:
        if (IsFieldEffectActive(6)) {
            stat = 11;
        }
        break;
    case 11:
        if (IsFieldEffectActive(6)) {
            stat = 9;
        }
        break;
    }
    return stat;
}

// Function name from swan.
u32 RawBattleMonStat(BattleMon *mon, u32 stat) {
    stat = func_ov167_021bb07c(mon, stat);
    switch (stat) {
    case 8:
        return *(u16 *)((u8 *)mon + 0xee);
    case 9:
        return *(u16 *)((u8 *)mon + 0xf0);
    case 10:
        return *(u16 *)((u8 *)mon + 0xf2);
    case 11:
        return *(u16 *)((u8 *)mon + 0xf4);
    case 12:
        return *(u16 *)((u8 *)mon + 0xf6);
    case 6:
        return 6;
    case 7:
        return 6;
    default:
        return GetBattleMonStat(mon, stat);
    }
}

void func_ov167_021bb10c(BattleMon *mon, u16 *stats) {
    u8 wasEncrypted;

    wasEncrypted = PokeParty_DecryptPkm(*(PartyPkm **)mon);
    stats[1] = PokeParty_GetParam(*(PartyPkm **)mon, (PkmField)0xa1, NULL);
    stats[2] = PokeParty_GetParam(*(PartyPkm **)mon, (PkmField)0xa2, NULL);
    stats[3] = PokeParty_GetParam(*(PartyPkm **)mon, (PkmField)0xa3, NULL);
    stats[4] = PokeParty_GetParam(*(PartyPkm **)mon, (PkmField)0xa5, NULL);
    stats[5] = PokeParty_GetParam(*(PartyPkm **)mon, (PkmField)0xa6, NULL);
    stats[6] = PokeParty_GetParam(*(PartyPkm **)mon, (PkmField)0xa4, NULL);
    PokeParty_EncryptPkm(*(PartyPkm **)mon, wasEncrypted);
}

void SetBaseStatus(BattleMon *mon, u32 stat, u16 value) {
    switch (func_ov167_021bb07c(mon, stat)) {
    case 8:
        *(u16 *)((u8 *)mon + 0xee) = value;
        break;
    case 9:
        *(u16 *)((u8 *)mon + 0xf0) = value;
        break;
    case 10:
        *(u16 *)((u8 *)mon + 0xf2) = value;
        break;
    case 11:
        *(u16 *)((u8 *)mon + 0xf4) = value;
        break;
    case 12:
        *(u16 *)((u8 *)mon + 0xf6) = value;
        break;
    }
}
