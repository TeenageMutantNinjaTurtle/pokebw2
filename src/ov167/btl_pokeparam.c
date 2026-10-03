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

// Function names from swan.
extern const BattleEventHandlerEntry data_ov167_021d78d4[];

extern const BattleEventHandlerEntry data_ov167_021d78cc[];

extern const BattleEventHandlerEntry data_ov167_021d78c4[];

// Function name from swan.
void MoveWork_ClearSurface(BattleMon *mon) {
    u32 i;
    BattleMoveWork *move;

    mon->moveCount = 0;
    for (i = 0; i < 4; i++) {
        move = &mon->moves[i];
        move->original.id = move->current.id;
        move->original.ppPair = move->current.ppPair;
        move->original.flagsPair = move->current.flagsPair;
        if (move->original.id != 0) {
            mon->moveCount++;
        }
        move->originalActive = 1;
    }
}

// Function names from swan.
void MoveWork_UpdateNumber(BattleMoveWork *work, u16 move, u8 maxPP, BOOL updateCurrent) {
    if (updateCurrent) {
        MoveCore_UpdateNumber(&work->current, move, maxPP);
        if (work->originalActive != 0) {
            work->original.id = work->current.id;
            work->original.ppPair = work->current.ppPair;
            work->original.flagsPair = work->current.flagsPair;
        }
    } else {
        MoveCore_UpdateNumber(&work->original, move, maxPP);
        work->originalActive = 0;
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
    if (mon->formChange) {
        setupBySrcData(mon, mon->src, 0, 1);
        MoveWork_ClearSurface(mon);
        mon->formChange = 0;
    }
}

void ClearUsedMoveFlag(BattleMon *mon) {
    u32 i;
    u8 *data;

    data = (u8 *)mon;
    for (i = 0; i < 4; i++) {
        func_ov167_021ba9cc(data + 0x104 + i * 14);
    }
    *(u16 *)(data + 0x14a) = 0;
    *(u16 *)(data + 0x14c) = 0;
    data[0x144] = 0x11;
    *(u16 *)(data + 0x14e) = 0;
}

void ClearCounter(BattleMon *mon) {
    u32 i;
    u8 *data;

    data = (u8 *)mon;
    for (i = 0; i < 5; i++) {
        data[0x157 + i] = 0;
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
BOOL Move_IsPPFull(BattleMon *mon, u8 index, BOOL current) {
    u8 *move;

    if (current != 0) {
        move = (u8 *)mon + 0x104 + index * 14;
    } else {
        move = (u8 *)mon + 0x10a + index * 14;
    }
    if (*(u16 *)move != 0 && move[2] == move[3]) {
        return TRUE;
    }
    return FALSE;
}

// Function names from swan.
u16 Move_IncrementPP(BattleMon *mon, u8 index, u8 amount) {
    u8 *move;

    move = (u8 *)mon + 0x104 + index * 14;
    move[8] += amount;
    if (move[8] > move[9]) {
        move[8] = move[9];
    }
    if (move[12] != 0) {
        move[2] = move[8];
    }
    return *(u16 *)(move + 6);
}

u16 Move_IncrementPP_Org(BattleMon *mon, u8 index, u8 amount) {
    u8 *move;

    move = (u8 *)mon + 0x104 + index * 14;
    move[2] += amount;
    if (move[2] > move[3]) {
        move[2] = move[3];
    }
    if (move[12] != 0) {
        move[8] = move[2];
    }
    return *(u16 *)move;
}

// Function names from swan.
void Move_UpdateID(BattleMon *mon, u8 index, u16 move, u8 maxPP, BOOL updateCurrent) {
    MoveWork_UpdateNumber((BattleMoveWork *)((u8 *)mon + 0x104 + index * 14), move, maxPP, updateCurrent);
}

BOOL MoveIsUsable(BattleMon *mon, u16 move) {
    u32 i;

    for (i = 0; i < 4; i++) {
        if (*(u16 *)((u8 *)mon + 0x10a + i * 14) == move) {
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
    if (type != 2) {
        goto first_done;
    }
    if (condition == 0) {
        goto first_done;
    }
    type = 0x11;
    goto first_done;
first_done:
    *type1 = type;
    type = mon->type2;
    if (type == 2 && condition != 0) {
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
PartyPkm *GetSrcData(const void *mon) {
    return *(PartyPkm **)mon;
}

void SetIllusionDisguise(BattleMon *mon, void *disguise) {
    u8 *data;

    data = (u8 *)mon;
    *(void **)(data + 4) = disguise;
    data[0x1b] |= 0x40;
}

void func_ov167_021bb054(BattleMon *mon) {
    u8 flags;

    flags = ((u8 *)mon)[0x1b];
    *(void **)((u8 *)mon + 4) = NULL;
    ((u8 *)mon)[0x1b] = flags & ~0x40;
}

void *func_ov167_021bb064(BattleMon *mon) {
    void *disguise;

    disguise = *(void **)((u8 *)mon + 4);
    if (disguise != NULL && ((((u32)((u8 *)mon)[0x1b] << 25) >> 31) != 0)) {
        return disguise;
    }
    return *(void **)mon;
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

// Function name from swan.
u32 CritAtkDefLevel(BattleMon *mon, u32 stat) {
    BOOL useRaw;

    useRaw = FALSE;
    switch (func_ov167_021bb07c(mon, stat)) {
    case 8:
        if (*(s8 *)((u8 *)mon + 0xfc) < 6) {
            useRaw = TRUE;
        }
        break;
    case 10:
        if (*(s8 *)((u8 *)mon + 0xfe) < 6) {
            useRaw = TRUE;
        }
        break;
    case 9:
        if (*(s8 *)((u8 *)mon + 0xfd) > 6) {
            useRaw = TRUE;
        }
        break;
    case 11:
        if (*(s8 *)((u8 *)mon + 0xff) > 6) {
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
    u8 *data;
    u32 result;

    bit = flag & 7;
    mask = (u8)(1 << bit);
    flag = (flag << 21) >> 24;
    data = (u8 *)mon + flag;
    result = TRUE;
    if ((data[0x153] & mask) == 0) {
        result = FALSE;
    }
    return result;
}

u32 GetAdditionalConditionFlag(BattleMon *mon, u32 flag) {
    u32 bit;
    u8 mask;
    u8 *data;
    u32 result;

    bit = flag & 7;
    mask = (u8)(1 << bit);
    flag = (flag << 21) >> 24;
    data = (u8 *)mon + flag;
    result = TRUE;
    if ((data[0x155] & mask) == 0) {
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
    if (*(s8 *)((u8 *)mon + 0xfc) < 6) {
        return TRUE;
    }
    if (*(s8 *)((u8 *)mon + 0xfd) < 6) {
        return TRUE;
    }
    if (*(s8 *)((u8 *)mon + 0xfe) < 6) {
        return TRUE;
    }
    if (*(s8 *)((u8 *)mon + 0xff) < 6) {
        return TRUE;
    }
    if (*(s8 *)((u8 *)mon + 0x100) < 6) {
        return TRUE;
    }
    if (*(s8 *)((u8 *)mon + 0x101) < 6) {
        return TRUE;
    }
    if (*(s8 *)((u8 *)mon + 0x102) < 6) {
        return TRUE;
    }
    return FALSE;
}

// Function names from swan.
void HPAdd(BattleMon *mon, u16 amount) {
    u16 *words;

    words = (u16 *)mon;
    words[8] += amount;
    if (words[8] > words[7]) {
        words[8] = words[7];
    }
}

void HPZero(BattleMon *mon) {
    *(u16 *)((u8 *)mon + 0x10) = 0;
}

// Function name from swan.
void SetMoveCondition(BattleMon *mon, u32 condition, BattleCondition value) {
    u8 *data;
    u8 *count;

    data = (u8 *)mon;
    if (IsBasicStatus(condition)) {
        CureCondition(mon);
    }
    *(BattleCondition *)(data + 0x1c + condition * 4) = value;
    count = data + condition;
    count[0xac] = 0;
}

// Function names from swan.
void CureCondition(BattleMon *mon) {
    u32 i;
    u8 *data;

    data = (u8 *)mon;
    for (i = 1; i < 6; i++) {
        *(BattleCondition *)(data + 0x1c + i * 4) = ZeroConditionTurns();
        data[0xac + i] = 0;
        CureDependentCondition(mon, i);
    }
}

void CureDependentCondition(BattleMon *mon, u32 condition) {
    u8 *data;

    data = (u8 *)mon;
    if (condition == 2) {
        *(BattleCondition *)(data + 0x40) = ZeroConditionTurns();
        data[0xb5] = 0;
    }
}

void CureMoveCondition(BattleMon *mon, u32 condition) {
    u8 *data;
    u8 *count;

    data = (u8 *)mon;
    if (IsBasicStatus(condition)) {
        CureCondition(mon);
    } else {
        *(BattleCondition *)(data + 0x1c + condition * 4) = ZeroConditionTurns();
        count = data + condition;
        count[0xac] = 0;
    }
}

void func_ov167_021bba64(BattleMon *mon, u32 monId) {
    u32 i;
    u8 *entry;

    if (monId != 0x1f) {
        for (i = 0; i < 0x24; i++) {
            entry = (u8 *)mon + i * 4;
            if (!func_ov167_021ce168(*(BattleCondition *)(entry + 0x1c))) {
                if (Condition_GetMonID(*(BattleCondition *)(entry + 0x1c)) == monId) {
                    *(BattleCondition *)(entry + 0x1c) = ZeroConditionTurns();
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
    BattleCondition *conditions;

    conditions = (BattleCondition *)((u8 *)mon + 0x1c);
    return conditions[index].common.type != 0;
}

u16 GetDisabledMove(BattleMon *mon, u32 index) {
    BattleCondition *conditions;

    conditions = (BattleCondition *)((u8 *)mon + 0x1c);
    switch (conditions[index].common.type) {
    case 2:
        return (conditions[index].raw << 7) >> 16;
    case 3:
        return (conditions[index].raw << 23) >> 26;
    case 4:
        return (conditions[index].raw << 17) >> 26;
    default:
        return 0;
    }
}

BattleConditionCont GetConditionContinuationParam(BattleMon *mon, u32 index) {
    BattleCondition *conditions;

    conditions = (BattleCondition *)((u8 *)mon + 0x1c);
    return conditions[index];
}

u8 func_ov167_021bbb1c(BattleMon *mon, u32 index) {
    return ((u8 *)mon + index)[0xac];
}

// Function name from swan.
void ClearMoveStatusWork(BattleMon *mon, u32 flag) {
    u32 i;
    BattleCondition *conditions;

    i = 0;
    if (flag == 0) {
        i = 6;
    }
    for (; i < 0x24; i++) {
        conditions = (BattleCondition *)((u8 *)mon + 0x1c);
        ((u32 *)mon)[i + 7] = 0;
        conditions[i].raw &= ~7;
    }
    sys_memset((u8 *)mon + 0xac, 0, 0x24);
}

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

// Function names from swan.
void ConsumeItem(BattleMon *mon, u16 item) {
    u16 *words;

    words = (u16 *)mon;
    words[10] = item;
    words[9] = 0;
}

void ClearConsumedItem(BattleMon *mon) {
    ((u16 *)mon)[10] = 0;
}

u16 GetConsumedItem(BattleMon *mon) {
    return ((u16 *)mon)[10];
}

// Function names from swan.
u16 GetConsecutiveMoveCount(BattleMon *mon) {
    return *(u16 *)((u8 *)mon + 0x14e);
}

u16 GetPreviousMoveID(BattleMon *mon) {
    return *(u16 *)((u8 *)mon + 0x14c);
}

u8 func_ov167_021bbfb0(BattleMon *mon) {
    return *((u8 *)mon + 0x144);
}

u16 GetPreviousMoveUsed(BattleMon *mon) {
    return *(u16 *)((u8 *)mon + 0x14a);
}

u8 GetPrevTargetPos(BattleMon *mon) {
    return *((u8 *)mon + 0x152);
}

// Function names from swan.
void SetWeight(BattleMon *mon, u16 weight) {
    if (weight < 1) {
        weight = 1;
    }
    *(u16 *)((u8 *)mon + 0x13e) = weight;
}

u16 GetBattleMonWeight(BattleMon *mon) {
    return *(u16 *)((u8 *)mon + 0x13e);
}

// Function name from swan.
u8 GetConditionCount(BattleMon *mon, u32 index) {
    u8 *data;

    data = (u8 *)mon + index;
    return data[0x157];
}

// Function names from swan.
BOOL IsIllusionEnabled(BattleMon *mon) {
    return ((u32)((u8 *)mon)[0x1b] << 25) >> 31;
}

void IllusionBreak(BattleMon *mon) {
    struct {
        u8 unused : 6;
        u8 illusion : 1;
        u8 high : 1;
    } *flags;

    flags = (void *)((u8 *)mon + 0x1b);
    flags->illusion = 0;
    *(u32 *)((u8 *)mon + 4) = 0;
}

// Function name from swan.
BOOL TransformCheck(BattleMon *mon) {
    return ((u32)((u8 *)mon)[0x1b] << 26) >> 31;
}

// Function names from swan.
void func_ov167_021bc55c(BattleMon *mon, u16 value) {
    *(u16 *)((u8 *)mon + 0x1f2) = value;
    CureMoveCondition(mon, 8);
}

void ResetSpActPriority(BattleMon *mon) {
    *(u16 *)((u8 *)mon + 0x1f2) = 0;
}

BOOL IsSubstituteActive(BattleMon *mon) {
    if (*(u16 *)((u8 *)mon + 0x1f2) != 0) {
        return TRUE;
    }
    return FALSE;
}

// Function name from swan.
void ComboMove_ClearParam(BattleMon *mon) {
    u8 *data;

    data = (u8 *)mon;
    if (data[0x1f6] != 0x1f) {
        data[0x1f6] = 0x1f;
        *(u16 *)(data + 0x1f4) = 0;
    }
}
