#include "types.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_setup.h"
#include "constants/pokemon.h"
#include "gfl/heap.h"
#include "pml/poke_party.h"
#include "save/bag.h"
#include "save/config.h"

// Layout reconstructed from the opponent-position lookup in the game code.
struct AdjacentOpponentData {
    u16 count1;
    u16 count2;
    u8 list1[3];
    u8 list2[3];
};

// Function names from swan.
u32 BtlSetup_GetBattleStyle(BtlMainModule *mainModule) {
    return mainModule->setup->battleStyle;
}

u32 func_ov167_0219bd88(BtlMainModule *mainModule) {
    return mainModule->unk473_2;
}

u8 func_ov167_0219bd98(BtlMainModule *mainModule) {
    return mainModule->setup->unk98;
}

// Function name from swan.
BOOL IsSwitchMode(BtlMainModule *mainModule) {
    if (BtlSetup_GetBattleType(mainModule) == 1 && BtlSetup_GetBattleStyle(mainModule) == 0 &&
        func_ov167_0219bee4(mainModule) == 0 && func_ov167_0219c988(mainModule) == 0 &&
        func_02008a68(mainModule->setup->config) == 0) {
        return TRUE;
    }
    return FALSE;
}

// Function names from swan.
u32 GetValidPosMax(BtlMainModule *mainModule) {
    switch (mainModule->setup->battleStyle) {
    case 0:
        return 1;
    case 1:
        return 3;
    case 2:
        return 5;
    case 3:
        return 5;
    default:
        return 5;
    }
}

u32 func_ov167_0219be8c(BtlMainModule *mainModule) {
    switch (mainModule->setup->battleStyle) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 1;
    default:
        return 1;
    }
}

BOOL func_ov167_0219bebc(BtlMainModule *mainModule, u32 pos) {
    return pos < func_ov167_0219be8c(mainModule) * 2;
}

u32 BtlSetup_GetBattleType(BtlMainModule *mainModule) {
    return mainModule->setup->battleType;
}

u8 func_ov167_0219bedc(BtlMainModule *mainModule) {
    return mainModule->setup->fieldSituation.unk1a;
}

u8 func_ov167_0219bee4(BtlMainModule *mainModule) {
    return mainModule->setup->fieldSituation.unk18;
}

BOOL func_ov167_0219beec(BtlMainModule *mainModule) {
    return mainModule->setup->fieldSituation.unk1a != 0;
}

u16 func_ov167_0219bf00(BtlMainModule *mainModule) {
    return mainModule->setup->fieldSituation.unk12;
}

u16 func_ov167_0219bf08(BtlMainModule *mainModule) {
    return mainModule->setup->unk138;
}

u16 func_ov167_0219bf14(BtlMainModule *mainModule) {
    return mainModule->setup->unk13a;
}

u32 GetRunMode(BtlMainModule *mainModule) {
    switch (mainModule->setup->battleType) {
    case 0:
        return 0;
    case 1:
        if (func_ov167_0219c988(mainModule) == 1) {
            return 2;
        }
        return 1;
    case 2:
        return 2;
    case 3:
        return 2;
    default:
        return 1;
    }
}

BtlFieldSituation *GetFieldEffectData(BtlMainModule *mainModule) {
    return &mainModule->setup->fieldSituation;
}

// Function names from swan.
BOOL DoesClientExist(BtlMainModule *mainModule, u8 clientId) {
    u32 i;

    if (clientId < 4) {
        for (i = 0; i < 6; i++) {
            if (mainModule->posClientIds[i] == clientId) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

u8 GetClientSide(BtlMainModule *mainModule, u8 clientId) {
    return clientId & 1;
}

// Function name from swan.
u8 GetPosOnSameSide(u8 pos, u8 index) {
    if ((pos & 1) == 0) {
        return index * 2;
    }
    return index * 2 + 1;
}

// Function name from swan.
BOOL AreClientsOnOppositeSides(BtlMainModule *mainModule, u8 clientId1, u8 clientId2) {
    return (clientId1 & 1) != (clientId2 & 1);
}

// Function name from swan.
u8 BattlePosToClientID(BtlMainModule *mainModule, u8 pos) {
    return mainModule->posClientIds[pos];
}

// Function name from swan.
u8 MonIDToClientID(u8 monId) {
    u8 i;
    u8 first;
    u8 last;

    for (i = 0; i < 4; i++) {
        first = data_ov167_021d6c24[i];
        last = first + 5;
        if (monId >= first && monId <= last) {
            return i;
        }
    }
    return 0;
}

// Function name from swan.
u8 MonIDToBattlePos(BtlMainModule *mainModule, BtlPokeCon *pokeCon, u8 monId) {
    u8 clientId;
    s32 slot;
    u8 pos;

    clientId = MonIDToClientID(monId);
    slot = func_ov167_0219d140(pokeCon, clientId, monId);
    if (slot >= 0) {
        pos = func_ov167_0219c458(mainModule, clientId, slot);
        if (pos != 6) {
            return pos;
        }
    }
    return 6;
}

// Function name from swan.
u8 GetPlayerClientID(BtlMainModule *mainModule) {
    return mainModule->playerClientId;
}

u8 func_ov167_0219c86c(BtlMainModule *mainModule) {
    return func_ov167_0219c87c(mainModule, mainModule->playerClientId);
}

u8 func_ov167_0219c87c(BtlMainModule *mainModule, u8 clientId) {
    u8 allyId = (clientId + 2) & 3;

    if (!DoesClientExist(mainModule, allyId)) {
        allyId = 4;
    }
    return allyId;
}

// Function name from swan.
BOOL IsAllyClientID(u8 clientId1, u8 clientId2) {
    if (clientId1 == clientId2) {
        return TRUE;
    }
    if (clientId1 == (u8)((clientId2 + 2) & 3)) {
        return TRUE;
    }
    return FALSE;
}

u8 func_ov167_0219c8b8(BtlMainModule *mainModule, u8 other) {
    return func_ov167_0219c8d0(mainModule, mainModule->playerClientId, other);
}

u32 func_ov167_0219c8d0(BtlMainModule *mainModule, u8 clientId, u8 other) {
    u8 oppositeSide = clientId;
    oppositeSide &= 1;
    oppositeSide ^= 1;

    if (other != 0) {
        u8 candidate = oppositeSide + ((other & 1) << 1);
        if (DoesClientExist(mainModule, candidate)) {
            oppositeSide = candidate;
        }
    }
    return oppositeSide;
}

// Function names from swan.
void BattleClient_SubItem(BtlMainModule *mainModule, u8 clientId, u16 item) {
    BtlSetup *setup;

    setup = mainModule->setup;
    if (setup->fieldSituation.unk1b == 0 && clientId == mainModule->playerClientId) {
        BagSave_SubItem(setup->bag, item, 1, mainModule->heapId);
    }
}

void BattleClient_AddItem(BtlMainModule *mainModule, u8 clientId, u16 item) {
    BtlSetup *setup;

    setup = mainModule->setup;
    if (setup->fieldSituation.unk1b == 0 && clientId == mainModule->playerClientId) {
        BagSave_AddItem(setup->bag, item, 1, mainModule->heapId);
    }
}

// Function names from swan.
void ChangeFriendshipWhenFainted(BtlMainModule *mainModule, BattleMon *mon, BOOL reason) {
    if (mainModule->setup->battleType <= 1 && mainModule->setup->fieldSituation.unk1b == 0) {
        ChangeFriendship(mainModule, mon, reason ? 5 : 4);
    }
}

void ChangeFriendship(BtlMainModule *mainModule, BattleMon *mon, u32 reason) {
    u8 monId;
    const BattleMon *param1;
    const BattleMon *param2;
    PartyPkm *src1;
    PartyPkm *src2;
    const BtlFieldSituation *field;

    monId = GetMonID(mon);
    param1 = GetPokeParamConst(&mainModule->pokeCons[1], monId);
    param2 = GetPokeParamConst(&mainModule->pokeCons[0], monId);
    src1 = GetSrcData(param1);
    src2 = GetSrcData(param2);
    field = GetFieldEffectData(mainModule);
    FriendshipManagerCalc(src1, reason, field->zoneId, HEAPID_TAIL(mainModule->heapId));
    FriendshipManagerCalc(src2, reason, field->zoneId, HEAPID_TAIL(mainModule->heapId));
}

// Function name from swan.
s32 GetPartyPkmnEligibleForBattle(PokeParty *party) {
    s32 index;
    PartyPkm *pkm;

    for (index = PokeParty_GetPkmCount(party) - 1; index >= 0; index--) {
        pkm = PokeParty_GetPkm(party, index);
        if (PokeParty_GetParam(pkm, (PkmField)PKM_PARAM_IS_EGG, NULL) == 0 &&
            PokeParty_GetParam(pkm, (PkmField)PKM_PARAM_HP, NULL) != 0) {
            return index;
        }
    }
    return -1;
}

// Function names from swan.
BattleMon *GetClientMonData(BtlPokeCon *pokeCon, u8 clientId, u8 monId) {
    return GetBattleMonFromParty(&pokeCon->parties[clientId], monId);
}

BattleMon *GetPokeParam(BtlPokeCon *pokeCon, u8 monId) {
    return pokeCon->mons[monId];
}

const BattleMon *GetPokeParamConst(const BtlPokeCon *pokeCon, u8 monId) {
    return pokeCon->mons[monId];
}

// Function name from swan.
s32 GetClientBattlerCount(BtlMainModule *mainModule, u8 clientId) {
    return func_ov167_0219a180(mainModule, clientId);
}

// Function name from swan.
BOOL IsAllyMonID(u8 monId1, u8 monId2) {
    return GetSideFromMonID(monId1) == GetSideFromMonID(monId2);
}

// Public function name from swan.
u8 GetSideFromOpposingMonID(u8 monId) {
    return func_ov167_0219d338(GetSideFromMonID(monId));
}

u8 func_ov167_0219d338(u8 side) {
    return side == 0;
}

// Function name from swan.
BOOL IsAdjacentOpponent(u8 pos1, u8 pos2) {
    const struct AdjacentOpponentData *data;
    u32 i;

    data = func_ov167_0219d2bc(pos1);
    for (i = 0; i < data->count1; i++) {
        if (pos2 == data->list1[i]) {
            return TRUE;
        }
    }
    for (i = 0; i < data->count2; i++) {
        if (pos2 == data->list2[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

// Function names from swan.
BattleParty *GetPartyData(BtlPokeCon *pokeCon, u8 clientId) {
    return &pokeCon->parties[clientId];
}

BattleParty *GetClientParty(BtlPokeCon *pokeCon, u8 clientId) {
    return &pokeCon->parties[clientId];
}

// Function name from swan.
void func_ov167_0219d434(BattleParty *party) {
    s32 i;

    party->count = 0;
    for (i = 0; i < 6; i++) {
        party->mons[i] = NULL;
    }
}

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

s32 FindPartyMon(const BattleParty *party, BattleMon *mon) {
    s32 i;

    for (i = 0; i < party->count; i++) {
        if (party->mons[i] == mon) {
            return i;
        }
    }
    return -1;
}

s32 func_ov167_0219d5b0(const BattleParty *party, u32 monId) {
    s32 i;

    for (i = 0; i < party->count; i++) {
        if (GetMonID(party->mons[i]) == monId) {
            return i;
        }
    }
    return -1;
}

BattleMon *func_ov167_0219d5dc(const BattleParty *party) {
    s32 i;

    for (i = 0; i < party->count; i++) {
        if (CanPokemonBattle(party->mons[i])) {
            return party->mons[i];
        }
    }
    return NULL;
}

// Function name from swan.
u32 BtlSetup_IsBattleType(BtlMainModule *mainModule, u32 flag) {
    return BtlSetup_CheckFlag(mainModule->setup, flag);
}
