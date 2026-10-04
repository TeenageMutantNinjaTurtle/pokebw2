#include "types.h"
#include "battle/btl_action.h"
#include "battle/btl_field.h"
#include "battle/btl_calc.h"
#include "battle/btl_pokeparam.h"
#include "constants/pokemon.h"
#include "gfl/std.h"
#include "pml/poke_party.h"
#include "pml/waza.h"

// Function name from swan.
void MoveWork_ClearSurface(BattleMon *mon) {
    u32 i;

    mon->moveCount = 0;
    for (i = 0; i < 4; i++) {
        mon->moves[i].surface = mon->moves[i].truth;
        if (mon->moves[i].surface.id != 0) {
            mon->moveCount++;
        }
        mon->moves[i].linked = 1;
    }
}


// Function names from swan.
void MoveWork_UpdateNumber(BattleMoveWork *work, u16 move, u8 maxPP, BOOL updateCurrent) {
    if (updateCurrent) {
        MoveCore_UpdateNumber(&work->truth, move, maxPP);
        if (work->linked != 0) {
            work->surface.id = work->truth.id;
            work->surface.ppPair = work->truth.ppPair;
            work->surface.flagsPair = work->truth.flagsPair;
        }
    } else {
        MoveCore_UpdateNumber(&work->surface, move, maxPP);
        work->linked = 0;
    }
}

void MoveCore_UpdateNumber(BattleMoveCore *core, u16 move, u8 maxPP) {
    u8 pp;

    core->id = move;
    core->flagsLow = 0;
    core->flagsHigh = 0;
    if (move != 0) {
        pp = PML_MoveGetMaxPP(move, 0);
    } else {
        pp = 0;
    }
    core->maxPP = pp;
    if (maxPP != 0 && core->maxPP > maxPP) {
        core->maxPP = maxPP;
    }
    core->pp = core->maxPP;
}

// Function name from swan.
void ClearFormChange(BattleMon *mon) {
    if (mon->transformed) {
        setupBySrcData(mon, mon->src, 0, 1);
        MoveWork_ClearSurface(mon);
        mon->transformed = 0;
    }
}

void ClearUsedMoveFlag(BattleMon *mon) {
    u32 i;

    for (i = 0; i < 4; i++) {
        func_ov167_021ba9cc(&mon->moves[i]);
    }
    mon->prevMoveUsed = 0;
    mon->prevMoveId = 0;
    mon->unk144 = 0x11;
    mon->consecutiveMoveCount = 0;
}

void ClearCounter(BattleMon *mon) {
    u32 i;

    for (i = 0; i < 5; i++) {
        mon->counters[i] = 0;
    }
}

// Function name from swan.
void ResetStatStages(u8 *stages) {
    stages[0] = 6;
    stages[1] = 6;
    stages[2] = 6;
    stages[3] = 6;
    stages[4] = 6;
    stages[5] = 6;
    stages[6] = 6;
}

// Function name from swan.
BOOL Move_IsPPFull(BattleMon *mon, u8 index, BOOL truth) {
    BattleMoveCore *move;

    if (truth != 0) {
        move = &mon->moves[index].truth;
    } else {
        move = &mon->moves[index].surface;
    }
    if (move->id != 0 && move->pp == move->maxPP) {
        return TRUE;
    }
    return FALSE;
}

// Function names from swan.
u16 Move_IncrementPP(BattleMon *mon, u8 index, u8 amount) {
    BattleMoveWork *move;

    move = &mon->moves[index];
    move->surface.pp += amount;
    if (move->surface.pp > move->surface.maxPP) {
        move->surface.pp = move->surface.maxPP;
    }
    if (move->linked != 0) {
        move->truth.pp = move->surface.pp;
    }
    return move->surface.id;
}

u16 Move_IncrementPP_Org(BattleMon *mon, u8 index, u8 amount) {
    BattleMoveWork *move;

    move = &mon->moves[index];
    move->truth.pp += amount;
    if (move->truth.pp > move->truth.maxPP) {
        move->truth.pp = move->truth.maxPP;
    }
    if (move->linked != 0) {
        move->surface.pp = move->truth.pp;
    }
    return move->truth.id;
}

// Function names from swan.
void Move_UpdateID(BattleMon *mon, u8 index, u16 move, u8 maxPP, BOOL updateCurrent) {
    MoveWork_UpdateNumber(&mon->moves[index], move, maxPP, updateCurrent);
}

BOOL MoveIsUsable(BattleMon *mon, u16 move) {
    u32 i;

    for (i = 0; i < 4; i++) {
        if (mon->moves[i].surface.id == move) {
            return TRUE;
        }
    }
    return FALSE;
}

// Function name from swan.
void splitTypeCore(BattleMon *mon, u8 *type1, u8 *type2) {
    BOOL condition;
    u8 type;

    condition = CheckCondition(mon, 0x18);
    type = mon->type1;
    if (type == 2 && condition) {
        *type1 = 0x11;
    } else {
        *type1 = type;
    }
    type = mon->type2;
    if (type == 2 && condition) {
        *type2 = 0x11;
    } else {
        *type2 = type;
    }
    if (*type1 == 0x11) {
        if (*type2 == 0x11) {
            *type2 = 0;
        }
        *type1 = *type2;
    } else if (*type2 == 0x11) {
        *type2 = *type1;
    }
}


// Function name from swan.
BOOL DoesMonHaveType(BattleMon *mon, u32 type) {
    u8 type1;
    u8 type2;

    if (type != 0x11) {
        splitTypeCore(mon, &type1, &type2);
        if (type1 == type || type2 == type) {
            return TRUE;
        }
    }
    return FALSE;
}

// Function names from swan.
PartyPkm *GetSrcData(const BattleMon *mon) {
    return mon->src;
}

void SetIllusionDisguise(BattleMon *mon, PartyPkm *disguise) {
    mon->illusionDisguise = disguise;
    mon->illusion = 1;
}

void func_ov167_021bb054(BattleMon *mon) {
    mon->illusionDisguise = NULL;
    mon->illusion = 0;
}

PartyPkm *func_ov167_021bb064(BattleMon *mon) {
    PartyPkm *disguise;

    disguise = mon->illusionDisguise;
    if (disguise != NULL && mon->illusion) {
        return disguise;
    }
    return mon->src;
}

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
        return mon->attack;
    case 9:
        return mon->defense;
    case 10:
        return mon->spAttack;
    case 11:
        return mon->spDefense;
    case 12:
        return mon->speed;
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

    wasEncrypted = PokeParty_DecryptPkm(mon->src);
    stats[1] = PokeParty_GetParam(mon->src, PKM_PARAM_MAX_HP, NULL);
    stats[2] = PokeParty_GetParam(mon->src, PKM_PARAM_ATTACK, NULL);
    stats[3] = PokeParty_GetParam(mon->src, PKM_PARAM_DEFENSE, NULL);
    stats[4] = PokeParty_GetParam(mon->src, PKM_PARAM_SP_ATTACK, NULL);
    stats[5] = PokeParty_GetParam(mon->src, PKM_PARAM_SP_DEFENSE, NULL);
    stats[6] = PokeParty_GetParam(mon->src, PKM_PARAM_SPEED, NULL);
    PokeParty_EncryptPkm(mon->src, wasEncrypted);
}

void SetBaseStatus(BattleMon *mon, u32 stat, u16 value) {
    switch (func_ov167_021bb07c(mon, stat)) {
    case 8:
        mon->attack = value;
        break;
    case 9:
        mon->defense = value;
        break;
    case 10:
        mon->spAttack = value;
        break;
    case 11:
        mon->spDefense = value;
        break;
    case 12:
        mon->speed = value;
        break;
    }
}

// Function name from swan.
u32 CritAtkDefLevel(BattleMon *mon, u32 stat) {
    BOOL useRaw;

    useRaw = FALSE;
    switch (func_ov167_021bb07c(mon, stat)) {
    case 8:
        if (mon->statStages[0] < 6) {
            useRaw = TRUE;
        }
        break;
    case 10:
        if (mon->statStages[2] < 6) {
            useRaw = TRUE;
        }
        break;
    case 9:
        if (mon->statStages[1] > 6) {
            useRaw = TRUE;
        }
        break;
    case 11:
        if (mon->statStages[3] > 6) {
            useRaw = TRUE;
        }
        break;
    }
    if (useRaw) {
        return RawBattleMonStat(mon, stat);
    }
    return GetBattleMonStat(mon, stat);
}

// Function names from swan.
u32 GetTurnFlag(BattleMon *mon, u32 flag) {
    u32 bit;
    u8 mask;
    u32 result;

    bit = flag & 7;
    mask = (u8)(1 << bit);
    flag = (flag << 21) >> 24;
    result = TRUE;
    if ((mon->turnFlags[flag] & mask) == 0) {
        result = FALSE;
    }
    return result;
}

u32 GetAdditionalConditionFlag(BattleMon *mon, u32 flag) {
    u32 bit;
    u8 mask;
    u32 result;

    bit = flag & 7;
    mask = (u8)(1 << bit);
    flag = (flag << 21) >> 24;
    result = TRUE;
    if ((mon->conditionFlags[flag] & mask) == 0) {
        result = FALSE;
    }
    return result;
}

u32 func_ov167_021bb408(BattleMon *mon) {
    u32 i;

    for (i = 0; i < 4; i++) {
        if (GetAdditionalConditionFlag(mon, data_ov167_021d7490[i])) {
            return data_ov167_021d7490[i];
        }
    }
    return 0x10;
}

BOOL IsSemiInvulnMove(BattleMon *mon) {
    if (func_ov167_021bb408(mon) != 0x10) {
        return TRUE;
    }
    return FALSE;
}

// Function name from swan.
fx32 GetHPRatio(BattleMon *mon) {
    double ratio;
    double fixed;

    ratio = (double)(mon->hp * 100) / (double)mon->maxHP;
    if (ratio > 0.0) {
        fixed = ratio * 4096.0 + 0.5;
    } else {
        fixed = ratio * 4096.0 - 0.5;
    }
    return (fx32)fixed;
}

// Function name from swan.
BOOL IsStatChangeValid(BattleMon *mon, u32 stat, s32 change) {
    s8 min;
    s8 max;
    s8 *stage;

    stage = func_ov167_021bb4b4(mon, stat, &min, &max);
    if (change > 0) {
        return *stage < max;
    }
    return *stage > min;
}

s32 func_ov167_021bb550(BattleMon *mon, u32 stat) {
    s8 min;
    s8 max;
    s8 *stage;

    stage = func_ov167_021bb4b4(mon, stat, &min, &max);
    return max - *stage;
}

// Function name from swan.
BOOL AreStatsLowered(BattleMon *mon) {
    if (mon->statStages[0] < 6) {
        return TRUE;
    }
    if (mon->statStages[1] < 6) {
        return TRUE;
    }
    if (mon->statStages[2] < 6) {
        return TRUE;
    }
    if (mon->statStages[3] < 6) {
        return TRUE;
    }
    if (mon->statStages[4] < 6) {
        return TRUE;
    }
    if (mon->statStages[5] < 6) {
        return TRUE;
    }
    if (mon->statStages[6] < 6) {
        return TRUE;
    }
    return FALSE;
}

// Function names from swan.
void HPAdd(BattleMon *mon, u16 amount) {
    mon->hp += amount;
    if (mon->hp > mon->maxHP) {
        mon->hp = mon->maxHP;
    }
}

void HPZero(BattleMon *mon) {
    mon->hp = 0;
}

// Function name from swan.
void SetMoveCondition(BattleMon *mon, u32 condition, BattleCondition value) {
    if (IsBasicStatus(condition)) {
        CureCondition(mon);
    }
    mon->conditions[condition] = value;
    mon->conditionCounters[condition] = 0;
}

// Function names from swan.
void CureCondition(BattleMon *mon) {
    u32 i;

    for (i = 1; i < 6; i++) {
        mon->conditions[i] = ZeroConditionTurns();
        mon->conditionCounters[i] = 0;
        CureDependentCondition(mon, i);
    }
}

void CureDependentCondition(BattleMon *mon, u32 condition) {
    if (condition == 2) {
        mon->conditions[9] = ZeroConditionTurns();
        mon->conditionCounters[9] = 0;
    }
}

void CureMoveCondition(BattleMon *mon, u32 condition) {
    if (IsBasicStatus(condition)) {
        CureCondition(mon);
    } else {
        mon->conditions[condition] = ZeroConditionTurns();
        mon->conditionCounters[condition] = 0;
    }
}

void func_ov167_021bba64(BattleMon *mon, u32 monId) {
    u32 i;

    if (monId != 0x1f) {
        for (i = 0; i < 0x24; i++) {
            if (!func_ov167_021ce168(mon->conditions[i])) {
                if (Condition_GetMonID(mon->conditions[i]) == monId) {
                    mon->conditions[i] = ZeroConditionTurns();
                    CureDependentCondition(mon, i);
                }
            }
        }
    }
}

// Function names from swan.
u32 GetBattleMonStatus(BattleMon *mon) {
    u32 i;

    for (i = 1; i < 6; i++) {
        if (mon->conditions[i].common.type != 0) {
            return i;
        }
    }
    return 0;
}

BOOL CheckCondition(BattleMon *mon, u32 index) {
    return mon->conditions[index].common.type != 0;
}

u16 GetDisabledMove(BattleMon *mon, u32 index) {
    switch (mon->conditions[index].common.type) {
    case 2:
        return (mon->conditions[index].raw << 7) >> 16;
    case 3:
        return (mon->conditions[index].raw << 23) >> 26;
    case 4:
        return (mon->conditions[index].raw << 17) >> 26;
    default:
        return 0;
    }
}

BattleConditionCont GetConditionContinuationParam(BattleMon *mon, u32 index) {
    return mon->conditions[index];
}

u8 func_ov167_021bbb1c(BattleMon *mon, u32 index) {
    return mon->conditionCounters[index];
}

// Function name from swan.
void ClearMoveStatusWork(BattleMon *mon, u32 flag) {
    u32 i;

    i = 0;
    if (flag == 0) {
        i = 6;
    }
    for (; i < 0x24; i++) {
        mon->conditions[i].raw = 0;
        mon->conditions[i].common.type = 0;
    }
    sys_memset(mon->conditionCounters, 0, 0x24);
}

// Function names from swan.
void ChangePokeType(BattleMon *mon, u16 type) {
    mon->type1 = PokeTypePair_GetType1(type);
    mon->type2 = PokeTypePair_GetType2(type);
}

void ChangeAbility(BattleMon *mon, u16 ability) {
    mon->ability = ability;
}

// Function names from swan.
void ConsumeItem(BattleMon *mon, u16 item) {
    mon->consumedItem = item;
    mon->heldItem = 0;
}

void ClearConsumedItem(BattleMon *mon) {
    mon->consumedItem = 0;
}

u16 GetConsumedItem(BattleMon *mon) {
    return mon->consumedItem;
}

// Function names from swan.
u16 GetConsecutiveMoveCount(BattleMon *mon) {
    return mon->consecutiveMoveCount;
}

u16 GetPreviousMoveID(BattleMon *mon) {
    return mon->prevMoveId;
}

u8 func_ov167_021bbfb0(BattleMon *mon) {
    return mon->unk144;
}

u16 GetPreviousMoveUsed(BattleMon *mon) {
    return mon->prevMoveUsed;
}

u8 GetPrevTargetPos(BattleMon *mon) {
    return mon->prevTargetPos;
}

// Function names from swan.
void SetWeight(BattleMon *mon, u16 weight) {
    if (weight < 1) {
        weight = 1;
    }
    mon->weight = weight;
}

u16 GetBattleMonWeight(BattleMon *mon) {
    return mon->weight;
}

// Function name from swan.
u8 GetConditionCount(BattleMon *mon, u32 index) {
    return mon->counters[index];
}

// Function names from swan.
BOOL IsIllusionEnabled(BattleMon *mon) {
    return mon->illusion;
}

void IllusionBreak(BattleMon *mon) {
    mon->illusion = 0;
    mon->illusionDisguise = NULL;
}

// Function name from swan.
BOOL TransformCheck(BattleMon *mon) {
    return mon->transformed;
}

// Function names from swan.
void func_ov167_021bc55c(BattleMon *mon, u16 value) {
    mon->substituteHP = value;
    CureMoveCondition(mon, 8);
}

void ResetSpActPriority(BattleMon *mon) {
    mon->substituteHP = 0;
}

BOOL IsSubstituteActive(BattleMon *mon) {
    if (mon->substituteHP != 0) {
        return TRUE;
    }
    return FALSE;
}

// Function name from swan.
void ComboMove_ClearParam(BattleMon *mon) {
    if (mon->comboMonId != 0x1f) {
        mon->comboMonId = 0x1f;
        mon->comboMove = 0;
    }
}
