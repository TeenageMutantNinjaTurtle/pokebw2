#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_math.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"
#include "pml/waza.h"

// Function names from swan.

void HandlerCompoundEyes(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_MulValue(0x35, 0x14cd);
    }
}

const BattleEventHandlerEntry *EventAddCompoundEyes(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76d4;
}

void HandlerSandVeil(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (GetWeather(flow) == 4) {
            BattleEventVar_MulValue(0x35, 0xccd);
        }
    }
}

void HandlerSandVeilWeather(void *context, void *flow, u32 monId, u32 value) {
    CommonWeatherGuard(context, flow, monId, value, 4);
}

const BattleEventHandlerEntry *EventAddSandVeil(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a64;
}

void HandlerSnowCloak(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (GetWeather(flow) == 3) {
            BattleEventVar_MulValue(0x35, 0xccd);
        }
    }
}

void HandlerSnowCloakWeather(void *context, void *flow, u32 monId, u32 value) {
    CommonWeatherGuard(context, flow, monId, value, 3);
}

const BattleEventHandlerEntry *EventAddSnowCloak(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a74;
}

void CommonWeatherGuard(void *context, void *flow, u32 monId, u32 value, u8 weather) {
    if (BattleEventVar_GetValue(2) == monId) {
        if ((s32)BattleEventVar_GetValue(0x32) > 0) {
            if (BattleEventVar_GetValue(0x39) == weather) {
                BattleEventVar_RewriteValue(0x41, 1);
            }
        }
    }
}

void HandlerTintedLens(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (func_ov167_021bd2e8(BattleEventVar_GetValue(0x38)) == 3) {
            BattleEventVar_MulValue(0x35, 2 << 12);
        }
    }
}

const BattleEventHandlerEntry *EventAddTintedLens(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77bc;
}

void HandlerSolidRock(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (func_ov167_021bd2e8(BattleEventVar_GetValue(0x38)) == 2) {
            BattleEventVar_MulValue(0x35, 3 << 10);
        }
    }
}

const BattleEventHandlerEntry *EventAddSolidRock(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7844;
}

void HandlerSniper(void *context, void *item, u32 monId) {
    u32 multiplier;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        if (BattleEventVar_GetValue(0x45) != 0) {
            BattleEventVar_MulValue(0x35, multiplier << 11);
        }
    }
}

const BattleEventHandlerEntry *EventAddSniper(u32 *priority) {
    *priority = 1;
    return data_ov167_021d783c;
}

struct SpeedBoostWork {
    u32 flags;
    u32 count;
    u8 unk08[4];
    u8 active;
    u8 unk0d[2];
    u8 amount;
    u8 monId;
};

void HandlerSpeedBoost(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    SpeedBoostWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetAdditionalConditionFlag(mon, 0)) {
            work = BattleHandler_PushWork((BattleHandler *)flow, 0xe, (void *)monId);
            work->flags |= flag << 22;
            work->count = 5;
            work->amount = 1;
            work->monId = monId;
            work->active = 1;
            BattleHandler_PopWork((BattleHandler *)flow, work);
        }
    }
}

const BattleEventHandlerEntry *EventAddSpeedBoost(u32 *priority) {
    *priority = 1;
    return data_ov167_021d771c;
}

void HandlerAdaptability(void *context, void *item, u32 monId) {
    u32 multiplier;

    multiplier = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x44) != 0) {
            BattleEventVar_RewriteValue(0x35, multiplier << 12);
        }
    }
}

const BattleEventHandlerEntry *EventAddAdaptability(u32 *priority) {
    *priority = 1;
    return data_ov167_021d785c;
}

void HandlerBlaze(void *context, BtlServerFlow *flow, u32 monId) {
    CommonLowHPBoostAbility(flow, monId, 9);
}

const BattleEventHandlerEntry *EventAddBlaze(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7734;
}

void HandlerTorrent(void *context, BtlServerFlow *flow, u32 monId) {
    CommonLowHPBoostAbility(flow, monId, 10);
}

const BattleEventHandlerEntry *EventAddTorrent(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7694;
}

void HandlerOvergrow(void *context, BtlServerFlow *flow, u32 monId) {
    CommonLowHPBoostAbility(flow, monId, 11);
}

const BattleEventHandlerEntry *EventAddOvergrow(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76cc;
}

void HandlerSwarm(void *context, BtlServerFlow *flow, u32 monId) {
    CommonLowHPBoostAbility(flow, monId, 6);
}

const BattleEventHandlerEntry *EventAddSwarm(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76c4;
}

void CommonLowHPBoostAbility(BtlServerFlow *flow, u32 monId, u32 type) {
    BattleMon *mon;
    u32 threshold;
    u32 divisor;

    divisor = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        mon = GetBattleMon(flow, monId);
        threshold = DivideMaxHp(mon, divisor);
        if (GetBattleMonStat(mon, 0xd) <= threshold) {
            if (BattleEventVar_GetValue(0x16) == type) {
                BattleEventVar_MulValue(0x35, divisor << 11);
            }
        }
    }
}

void HandlerGuts(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    u32 multiplier;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetBattleMonStatus(mon) != 0) {
            if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 1) {
                BattleEventVar_MulValue(0x35, multiplier << 11);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddGuts(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76bc;
}

void HandlerPlusMinus(void *context, void *flow, u32 monId, void *list) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (func_ov167_021be5c4(flow, monId, list, 0x39) || func_ov167_021be5c4(flow, monId, list, 0x3a)) {
            if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 2) {
                BattleEventVar_MulValue(0x35, 6 << 10);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddPlusMinus(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7724;
}

BOOL func_ov167_021be5c4(void *flow, u32 monId, void *list, u32 ability) {
    volatile u32 count;
    u32 clientCount;
    u16 packed;
    u8 i;
    u8 *mons;

    mons = list;
    clientCount = func_ov167_021abb50(flow);
    if (clientCount != 6) {
        packed = (7 << 8) | clientCount;
        count = HandlerGetAlivePartyCount((BattleHandler *)flow, packed, mons);
        for (i = 0; i < count; i++) {
            if (monId != mons[i]) {
                if (GetBattleMonStat(GetBattleMon(flow, mons[i]), 0x11) == ability) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

BOOL CheckFlowerGiftEnablePokemon(BtlServerFlow *flow, u32 monId) {
    return GetBattleMonSpecies(GetBattleMon(flow, monId)) == 0x1a5;
}

void HandlerFlowerGiftMemberOnField(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    u32 sunny;
    u32 weather;

    if (CheckFlowerGiftEnablePokemon(flow, monId)) {
        weather = GetWeather(flow);
        sunny = 1;
        if (weather != 1) {
            sunny = 0;
        }
        CommonFlowerGiftFormChange(context, flow, monId, sunny, 1);
        *result = 1;
    }
}

void HandlerFlowerGiftGotAbility(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    if (BattleEventVar_GetValue(2) == monId) {
        HandlerFlowerGiftMemberOnField(context, flow, monId, result);
    }
}

struct FlowerGiftFormWork {
    u32 flags;
    u8 monId;
    u8 form;
    u8 reserved[2];
    BattleHandlerString string;
};

void CommonFlowerGiftFormChange(void *context, BtlServerFlow *flow, u32 monId, u8 sunny, u8 cause) {
    BattleMon *mon;
    FlowerGiftFormWork *work;

    mon = GetBattleMon(flow, monId);
    if (sunny != GetBattleMonStat(mon, 0x13)) {
        work = BattleHandler_PushWork((BattleHandler *)flow, 0x39, (void *)monId);
        work->monId = monId;
        work->form = sunny;
        work->flags = (work->flags & 0xff7fffff) | ((cause & 1) << 23);
        BattleHandler_StrSetup(&work->string, 2, 0xde);
        BattleHandler_AddArg(&work->string, monId);
        BattleHandler_PopWork((BattleHandler *)flow, work);
    }
}

void HandlerFlowerGiftWeather(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    u32 weather;
    u32 sunny;

    if (*active) {
        if (CheckFlowerGiftEnablePokemon(flow, monId)) {
            weather = GetWeather(flow);
            sunny = 1;
            if (weather != 1) {
                sunny = 0;
            }
            CommonFlowerGiftFormChange(context, flow, monId, sunny, 1);
        }
    }
}

void HandlerFlowerGiftAbilityOff(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    if (*active) {
        if (BattleEventVar_GetValue(2) == monId) {
            if (CheckFlowerGiftEnablePokemon(flow, monId)) {
                CommonFlowerGiftFormChange(context, flow, monId, 0, 0);
            }
        }
    }
}

void HandlerFlowerGiftAirLock(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    if (*active) {
        if (CheckFlowerGiftEnablePokemon(flow, monId)) {
            CommonFlowerGiftFormChange(context, flow, monId, 0, 0);
        }
    }
}

void HandlerFlowerGiftAbilityChange(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    u32 ability;

    if (*active) {
        if (CheckFlowerGiftEnablePokemon(flow, monId)) {
            if (BattleEventVar_GetValue(2) == monId) {
                ability = BattleEventVar_GetValue(0x10);
                if (ability != BattleEventItem_GetSubID(context)) {
                    CommonFlowerGiftFormChange(context, flow, monId, 0, 0);
                }
            }
        }
    }
}

void HandlerFlowerGiftPower(void *context, BtlServerFlow *flow, u8 monId) {
    u32 multiplier;
    u8 allyMonId;

    multiplier = 3;
    if (CheckFlowerGiftEnablePokemon(flow, monId)) {
        if (GetWeather(flow) == 1) {
            allyMonId = BattleEventVar_GetValue(3);
            if (IsAllyMonID(monId, allyMonId)) {
                if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 1) {
                    BattleEventVar_MulValue(0x35, multiplier << 11);
                }
            }
        }
    }
}

void HandlerFlowerGiftSpecialDefense(void *context, BtlServerFlow *flow, u8 monId) {
    u8 allyMonId;

    if (CheckFlowerGiftEnablePokemon(flow, monId)) {
        if (GetWeather(flow) == 1) {
            allyMonId = BattleEventVar_GetValue(4);
            if (IsAllyMonID(monId, allyMonId)) {
                if (BattleEventVar_GetValue(0x1a) == 2) {
                    BattleEventVar_MulValue(0x35, 6 << 10);
                }
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddFlowerGift(u32 *priority) {
    *priority = 11;
    return data_ov167_021d7ea0;
}

void HandlerRivalry(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *attacker;
    BattleMon *defender;
    u8 attackerGender;
    u8 defenderGender;
    u32 targetMonId;
    u32 multiplier;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        attacker = GetBattleMon(flow, monId);
        targetMonId = BattleEventVar_GetValue(4);
        defender = GetBattleMon(flow, (u8)targetMonId);
        attackerGender = GetBattleMonStat(attacker, 0x12);
        defenderGender = GetBattleMonStat(defender, 0x12);
        if (attackerGender != 2 && defenderGender != 2) {
            if (attackerGender == defenderGender) {
                BattleEventVar_MulValue(0x31, 5 << 10);
                return;
            }
            BattleEventVar_MulValue(0x31, multiplier << 10);
        }
    }
}

const BattleEventHandlerEntry *EventAddRivalry(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7864;
}

void HandlerTechnician(void *context, void *flow, u32 monId) {
    u32 multiplier;

    multiplier = 0x30;
    if (BattleEventVar_GetValue(3) == monId) {
        if (BattleEventVar_GetValue(0x30) <= 0x3c) {
            BattleEventVar_MulValue(0x31, multiplier << 7);
        }
    }
}

const BattleEventHandlerEntry *EventAddTechnician(u32 *priority) {
    *priority = 1;
    return data_ov167_021d768c;
}

void HandlerIronFist(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (getMoveFlag(BattleEventVar_GetValue(0x12), 7)) {
            BattleEventVar_MulValue(0x31, 0x1333);
        }
    }
}

const BattleEventHandlerEntry *EventAddIronFist(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77dc;
}

void HandlerReckless(void *context, void *flow, u32 monId) {
    u16 move;

    if (BattleEventVar_GetValue(3) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (PML_MoveGetParam(move, 0x1e) || move == 0x1a || move == 0x88) {
            BattleEventVar_MulValue(0x31, 0x1333);
        }
    }
}

const BattleEventHandlerEntry *EventAddReckless(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77a4;
}

void HandlerMarvelScale(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;

    if (BattleEventVar_GetValue(4) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetBattleMonStatus(mon)) {
            BattleEventVar_GetValue(0x12);
            if (BattleEventVar_GetValue(0x1a) == 1) {
                BattleEventVar_MulValue(0x35, 6 << 10);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddMarvelScale(u32 *priority) {
    *priority = 1;
    return data_ov167_021d772c;
}

void HandlerSkillLink(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x51, 1);
    }
}

const BattleEventHandlerEntry *EventAddSkillLink(u32 *priority) {
    *priority = 1;
    return data_ov167_021d769c;
}

const BattleEventHandlerEntry *EventAddHyperCutter(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7904;
}

void HandlerHyperCutterCheck(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardCheck(flow, monId, result, 1);
}

void HandlerHyperCutterGuard(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardFixed(flow, monId, result, 0xc9);
}

const BattleEventHandlerEntry *EventAddKeenEye(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7914;
}

void HandlerKeenEyeCheck(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardCheck(flow, monId, result, 6);
}

void HandlerKeenEyeGuard(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardFixed(flow, monId, result, 0xcf);
}

const BattleEventHandlerEntry *EventAddClearBody(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7924;
}

void HandlerClearBodyCheck(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardCheck(flow, monId, result, 8);
}

void HandlerClearBodyGuard(void *context, void *flow, u32 monId, u32 *result) {
    CommonStatDropGuardFixed(flow, monId, result, 0xc6);
}

void CommonStatDropGuardCheck(void *flow, u32 monId, u32 *result, u32 stat) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(3) != monId) {
            if (stat == 8 || BattleEventVar_GetValue(0x1f) == stat) {
                if ((s32)BattleEventVar_GetValue(0x20) < 0) {
                    *result = BattleEventVar_RewriteValue(0x41, 1);
                }
            }
        }
    }
}

struct StatDropGuardMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void CommonStatDropGuardFixed(void *flow, u32 monId, u32 *result, u16 message) {
    u32 source;
    StatDropGuardMessageWork *work;

    if (BattleEventVar_GetValue(2) == monId && result[0]) {
        source = BattleEventVar_GetValue(0x19);
        if (source == 0 || result[1] != source) {
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
            BattleHandler_StrSetup(&work->string, 2, message);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
            result[1] = source;
        }
        result[0] = 0;
    }
}

void HandlerSimple(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x20, BattleEventVar_GetValue(0x20) << 1);
    }
}

const BattleEventHandlerEntry *EventAddSimple(u32 *priority) {
    *priority = 1;
    return data_ov167_021d773c;
}

void HandlerLeafGuard(void *context, void *flow, u32 monId, u32 *result) {
    u32 condition;

    if (BattleEventVar_GetValue(4) == monId) {
        if (GetWeather(flow) == 1) {
            condition = BattleEventVar_GetValue(0x1d);
            if (IsBasicStatus(condition) || condition == 0xe) {
                *result = BattleEventVar_RewriteValue(0x41, 1);
            }
        }
    }
}

void HandlerLeafGuardYawnCheck(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetWeather(flow) == 1) {
            BattleEventVar_RewriteValue(0x41, 1);
        }
    }
}

const BattleEventHandlerEntry *EventAddLeafGuard(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7ac4;
}

void HandlerLimberStatus(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 1);
}

void HandlerLimberCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 1);
}

void HandlerLimberActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 1);
}

const BattleEventHandlerEntry *EventAddLimber(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7c80;
}

void HandlerInsomniaStatus(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 2);
    if (!*result) {
        *result = HandlerCommonGuardStatus(flow, monId, 0xe);
    }
}

void HandlerInsomniaWake(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 2);
}

void HandlerInsomniaActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 2);
}

void HandlerInsomniaYawnCheck(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddInsomnia(u32 *priority) {
    *priority = 6;
    return data_ov167_021d7dc0;
}

void HandlerMagmaArmorStatus(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 3);
}

void HandlerMagmaArmorCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 3);
}

void HandlerMagmaArmorActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 3);
}

const BattleEventHandlerEntry *EventAddMagmaArmor(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7cd0;
}

void HandlerImmunity(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 5);
}

void HandlerImmunityCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 5);
}

void HandlerImmunityActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 5);
}

const BattleEventHandlerEntry *EventAddImmunity(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7cf8;
}

void HandlerWaterVeil(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 4);
}

void HandlerWaterVeilCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 4);
}

void HandlerWaterVeilActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 4);
}

const BattleEventHandlerEntry *EventAddWaterVeil(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7d20;
}

void HandlerOwnTempoStatus(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 6);
}

void HandlerOwnTempoAddStatusFailed(void *context, void *flow, u32 monId, void *result) {
    CommonAddStatusFailed(context, flow, monId, result, 0x165);
}

void HandlerOwnTempoCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 6);
}

void HandlerOwnTempoActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 6);
}

const BattleEventHandlerEntry *EventAddOwnTempo(u32 *priority) {
    *priority = 4;
    return data_ov167_021d7c38;
}

struct ObliviousMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void HandlerOblivious(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 7);
}

void HandlerObliviousCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 7);
}

void HandlerObliviousActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 7);
}

void HandlerObliviousNoEffectCheck(void *context, void *flow, u32 monId) {
    ObliviousMessageWork *work;
    u32 command;

    command = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if ((u16)BattleEventVar_GetValue(0x12) == 0x1bd) {
            if (BattleEventVar_RewriteValue(0x40, 1)) {
                BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
                work = BattleHandler_PushWork((BattleHandler *)flow, command, (void *)monId);
                BattleHandler_StrSetup(&work->string, 2, 0xd2);
                BattleHandler_AddArg(&work->string, monId);
                BattleHandler_PopWork((BattleHandler *)flow, work);
                BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddOblivious(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7d48;
}

BOOL HandlerCommonGuardStatus(void *flow, u32 monId, u32 status) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x1d) == status) {
            return BattleEventVar_RewriteValue(0x41, 1);
        }
    }
    return FALSE;
}

struct StatusFailedMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void CommonAddStatusFailed(void *context, void *flow, u32 monId, u32 *result, u16 message) {
    StatusFailedMessageWork *work;
    u32 command;

    command = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (*result == 1) {
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, command, (void *)monId);
            BattleHandler_StrSetup(&work->string, 2, message);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
            *result = 0;
        }
    }
}

void HandlerAddStatusFailedCommon(void *context, void *flow, u32 monId, u32 *result) {
    CommonAddStatusFailed(context, flow, monId, result, 0xd2);
}

void CommonAbilityCureStatus(void *flow, u32 monId, u32 status) {
    if (BattleEventVar_GetValue(2) == monId) {
        CommonAbilityCureStatusCore(flow, monId, status);
    }
}

struct AbilityCureStatusWork {
    u32 flags;
    u32 status;
    u8 monId;
    u8 reserved[0xb];
    u8 active;
};

void CommonAbilityCureStatusCore(void *flow, u32 monId, u32 status) {
    BattleMon *mon;
    AbilityCureStatusWork *work;

    mon = GetBattleMon(flow, monId);
    if (CheckCondition(mon, status)) {
        BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
        work = BattleHandler_PushWork((BattleHandler *)flow, 0xb, (void *)monId);
        work->status = status;
        work->active = 1;
        work->monId = monId;
        BattleHandler_PopWork((BattleHandler *)flow, work);
        BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
    }
}

void HandlerDrizzle(void *context, void *flow, u32 monId) {
    CommonWeatherChangeAbility(flow, monId, 2);
}

const BattleEventHandlerEntry *EventAddDrizzle(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7954;
}

void HandlerDrought(void *context, void *flow, u32 monId) {
    CommonWeatherChangeAbility(flow, monId, 1);
}

const BattleEventHandlerEntry *EventAddDrought(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7964;
}

void HandlerSandStream(void *context, void *flow, u32 monId) {
    CommonWeatherChangeAbility(flow, monId, 4);
}

const BattleEventHandlerEntry *EventAddSandStream(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7974;
}

void HandlerSnowWarning(void *context, void *flow, u32 monId) {
    CommonWeatherChangeAbility(flow, monId, 3);
}

const BattleEventHandlerEntry *EventAddSnowWarning(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7984;
}

struct WeatherChangeAbilityWork {
    u32 flags;
    u8 weather;
    u8 duration;
};

void CommonWeatherChangeAbility(void *flow, u32 monId, u32 weather) {
    WeatherChangeAbilityWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        work = BattleHandler_PushWork((BattleHandler *)flow, 0x1d, (void *)monId);
        work->flags |= flag << 22;
        work->weather = weather;
        work->duration = 0xff;
        BattleHandler_PopWork((BattleHandler *)flow, work);
    }
}

struct AirLockWeatherWork {
    u32 flags;
    u8 weather;
    u8 duration;
    u8 active;
    u8 reserved;
    BattleHandlerString string;
};

void HandlerAirLockMemberIn(void *context, void *flow, u32 monId) {
    AirLockWeatherWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        work = BattleHandler_PushWork((BattleHandler *)flow, 0x1d, (void *)monId);
        work->flags |= flag << 22;
        work->weather = 0;
        work->active = 1;
        BattleHandler_StrSetup(&work->string, 1, 0x5e);
        BattleHandler_PopWork((BattleHandler *)flow, work);
    }
}

BOOL HandlerAirLockChangeWeather(void *context, void *flow, u32 monId) {
    return BattleEventVar_RewriteValue(0x41, 1);
}

const BattleEventHandlerEntry *EventAddAirLock(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7994;
}

void HandlerIceBody(void *context, BtlServerFlow *flow, u32 monId) {
    CommonWeatherRecoveryAbility(flow, monId, 3);
}

const BattleEventHandlerEntry *EventAddIceBody(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7644;
}

void HandlerRainDish(void *context, BtlServerFlow *flow, u32 monId) {
    CommonWeatherRecoveryAbility(flow, monId, 2);
}

const BattleEventHandlerEntry *EventAddRainDish(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76f4;
}

struct WeatherRecoveryWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

void CommonWeatherRecoveryAbility(BtlServerFlow *flow, u32 monId, u32 weather) {
    BattleMon *mon;
    WeatherRecoveryWork *work;

    if (BattleEventVar_GetValue(0x39) == weather) {
        if (BattleEventVar_GetValue(2) == monId) {
            mon = GetBattleMon(flow, monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, 5, (void *)monId);
            work->flags |= 2 << 22;
            work->monId = monId;
            work->amount = DivideMaxHPZeroCheck(mon, 0x10);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleEventVar_RewriteValue(0x41, 1);
        }
    }
}

struct SolarPowerWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

void HandlerSolarPowerWeather(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    SolarPowerWork *work;
    u16 amount;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x39) == 1) {
            mon = GetBattleMon(flow, monId);
            amount = DivideMaxHPZeroCheck(mon, 8);
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, 7, (void *)monId);
            work->monId = monId;
            work->amount = amount;
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
        }
    }
}

void HandlerSolarPowerPower(void *context, BtlServerFlow *flow, u32 monId) {
    u32 multiplier;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        if (GetWeather(flow) == 1) {
            if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 2) {
                BattleEventVar_MulValue(0x35, multiplier << 11);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddSolarPower(u32 *priority) {
    *priority = 2;
    return data_ov167_021d79b4;
}

void HandlerShieldDustStatus(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(3) != monId) {
            if (BattleEventVar_GetValue(0x1d) != 8) {
                BattleEventVar_RewriteValue(0x41, 1);
            }
        }
    }
}

void HandlerShieldDustRank(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(3) != monId) {
            BattleEventVar_RewriteValue(0x41, 1);
        }
    }
}

void HandlerShieldDustShrink(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

void HandlerShieldDustGuard(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x47, 1);
    }
}

void HandlerShieldDustGuardHitEnd(void *context, void *flow, u32 monId) {
    if (func_ov167_021cde38(monId)) {
        if (BattleEventVar_GetValue(5) == 1) {
            BattleEventVar_RewriteValue(0x47, 1);
        }
    }
}

const BattleEventHandlerEntry *EventAddShieldDust(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7d70;
}

void HandlerSereneGrace(void *context, void *flow, u32 monId) {
    u32 chance;

    if (BattleEventVar_GetValue(3) == monId) {
        chance = BattleEventVar_GetValue(0x26);
        chance = (u16)(chance << 1);
        BattleEventVar_RewriteValue(0x26, chance);
    }
}

void HandlerSereneGraceShrink(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x45, 1);
    }
}

const BattleEventHandlerEntry *EventAddSereneGrace(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b0c;
}

struct HydrationWork {
    u32 flags;
    u32 status;
    u8 monId;
    u8 reserved[0xb];
    u8 active;
};

void HandlerHydration(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    HydrationWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetWeather(flow) == 2) {
            mon = GetBattleMon(flow, monId);
            if (GetBattleMonStatus(mon)) {
                BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
                work = BattleHandler_PushWork((BattleHandler *)flow, 0xb, (void *)monId);
                work->status = 0x24;
                work->monId = monId;
                work->active = 1;
                work->flags |= flag << 24;
                BattleHandler_PopWork((BattleHandler *)flow, work);
                BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddHydration(u32 *priority) {
    *priority = 1;
    return data_ov167_021d762c;
}

struct ShedSkinWork {
    u32 flags;
    u32 status;
    u8 monId;
    u8 reserved[0xb];
    u8 active;
};

void HandlerShedSkin(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    ShedSkinWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetBattleMonStatus(mon)) {
            if (AbilityEvent_RollEffectChance((BattleMon *)flow, 0x21)) {
                work = BattleHandler_PushWork((BattleHandler *)flow, 0xb, (void *)monId);
                work->flags |= flag << 22;
                work->flags |= flag << 24;
                work->status = 0x24;
                work->monId = monId;
                work->active = 1;
                BattleHandler_PopWork((BattleHandler *)flow, work);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddShedSkin(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78fc;
}

struct PoisonHealWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

void HandlerPoisonHeal(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    PoisonHealWork *work;
    u32 flag;

    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x1d) == 5) {
            mon = GetBattleMon(flow, monId);
            BattleEventVar_RewriteValue(0x32, 0);
            work = BattleHandler_PushWork((BattleHandler *)flow, 5, (void *)monId);
            work->amount = DivideMaxHPZeroCheck(mon, 8);
            work->monId = monId;
            flag = 8;
            work->flags |= flag << 20;
            BattleHandler_PopWork((BattleHandler *)flow, work);
        }
    }
}

const BattleEventHandlerEntry *EventAddPoisonHeal(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78f4;
}

void HandlerBattleArmor(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddBattleArmor(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78ec;
}

void HandlerSuperLuck(void *context, void *flow, u32 monId) {
    u32 level;

    if (BattleEventVar_GetValue(3) == monId) {
        level = BattleEventVar_GetValue(0x2c);
        level = (u8)(level + 1);
        BattleEventVar_RewriteValue(0x2c, level);
    }
}

const BattleEventHandlerEntry *EventAddSuperLuck(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78e4;
}

struct AngerPointWork {
    u32 flags;
    u32 stage;
    u8 reserved08[4];
    u8 amount;
    u8 active;
    u8 showPopup;
    u8 showMessage;
    u8 monId;
    u8 reserved11[7];
    BattleHandlerString string;
};

void HandlerAngerPoint(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    AngerPointWork *work;
    s32 amount;

    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x46) == 0) {
            if (BattleEventVar_GetValue(0x45) != 0) {
                mon = GetBattleMon(flow, monId);
                if (func_ov167_021bb550(mon, 1) > 0) {
                    work = BattleHandler_PushWork((BattleHandler *)flow, 0xe, (void *)monId);
                    work->stage = 1;
                    amount = func_ov167_021bb550(mon, 1);
                    work->amount = amount;
                    work->showPopup = 1;
                    work->showMessage = 1;
                    work->monId = monId;
                    work->active = 1;
                    work->flags |= 1 << 23;
                    BattleHandler_StrSetup(&work->string, 2, 0x1e1);
                    BattleHandler_AddArg(&work->string, monId);
                    BattleHandler_PopWork((BattleHandler *)flow, work);
                }
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddAngerPoint(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78dc;
}
