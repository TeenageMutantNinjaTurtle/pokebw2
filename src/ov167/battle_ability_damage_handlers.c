#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"
#include "pml/waza.h"

// Function names from swan.

struct SturdyMessageWork {
    u32 flags;
    BattleHandlerString string;
};

const BattleEventHandlerEntry *EventAddSturdy(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b84;
}
void HandlerSturdyOneshotCheck(void *context, BtlServerFlow *flow, u32 monId) {
    SturdyMessageWork *work;
    u32 command;
    command = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_RewriteValue(0x41, 1)) {
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, command, (void *)monId);
            BattleHandler_StrSetup(&work->string, 2, 0xd2);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
        }
    }
}
void HandlerSturdyEndureCheck(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    u32 value;
    value = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (IsMonFullHP(GetBattleMon(flow, monId))) {
            *result = BattleEventVar_RewriteValue(0x3a, value);
        } else {
            *result = 0;
        }
    }
}
void HandlerSturdySurvive(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    SturdyMessageWork *work;
    if (BattleEventVar_GetValue(2) == monId) {
        if (*active) {
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
            BattleHandler_StrSetup(&work->string, 2, 0x202);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
            *active = 0;
        }
    }
}

void HandlerUnawareHitRank(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x28, 6);
    } else if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x27, 6);
    }
}

void HandlerUnawareAttackRank(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        BattleEventVar_RewriteValue(0x51, 1);
    }
}

void HandlerUnawareDefenseRank(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x51, 1);
    }
}

const BattleEventHandlerEntry *EventAddUnaware(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7b9c;
}

s32 func_ov167_021bd31c(s32 value, s32 minimum);

void HandlerHeatproofPower(void *context, void *flow, u32 monId) {
    u32 factor;

    factor = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x16) == 9) {
            BattleEventVar_MulValue(0x31, factor << 9);
        }
    }
}

void HandlerHeatproofStatus(void *context, void *flow, u32 monId) {
    s32 damage;

    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x1d) == 4) {
            damage = BattleEventVar_GetValue(0x32);
            damage = func_ov167_021bd31c(damage / 2, 1);
            BattleEventVar_RewriteValue(0x32, damage);
        }
    }
}

const BattleEventHandlerEntry *EventAddHeatproof(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a54;
}

BOOL CommonDamageRecoverCheck(BtlServerFlow *flow, u32 monId, u32 type) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(3) != monId) {
            if (BattleEventVar_GetValue(0x16) == type) {
                return BattleEventVar_RewriteValue(0x40, 1);
            }
        }
    }
    return FALSE;
}

struct TypeRecoverWork {
    u32 flags;
    u16 amount;
    u8 monId;
    u8 reserved07;
    BattleHandlerString string;
};
struct TypeRecoverMessageWork {
    u32 flags;
    BattleHandlerString string;
};
struct TypeRankUpWork {
    u32 flags;
    u32 stat;
    u8 reserved08[4];
    u8 amount;
    u8 reserved0d;
    u8 active;
    u8 showPopup;
    u8 monId;
};
struct TypeRankMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void CommonTypeRecoverHP(BtlServerFlow *flow, u32 monId, u32 divisor) {
    BattleMon *mon;
    TypeRecoverWork *work;
    TypeRecoverMessageWork *message;
    mon = GetBattleMon(flow, monId);
    if (!IsMonFullHP(mon)) {
        work = BattleHandler_PushWork((BattleHandler *)flow, 5, (void *)monId);
        work->monId = monId;
        work->amount = DivideMaxHPZeroCheck(mon, divisor);
        work->flags |= 2 << 22;
        BattleHandler_StrSetup(&work->string, 2, 0x183);
        BattleHandler_AddArg(&work->string, monId);
        BattleHandler_PopWork((BattleHandler *)flow, work);
    } else {
        message = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
        BattleHandler_StrSetup(&message->string, 2, 0xd2);
        BattleHandler_AddArg(&message->string, monId);
        message->flags |= 2 << 22;
        BattleHandler_PopWork((BattleHandler *)flow, message);
    }
    BattleEventVar_RewriteValue(0x51, 1);
}

void CommonTypeNoEffectRankUp(BtlServerFlow *flow, u32 monId, u32 stat, u32 amount) {
    BattleMon *mon;
    TypeRankUpWork *work;
    TypeRankMessageWork *message;
    mon = GetBattleMon(flow, monId);
    if (IsStatChangeValid(mon, stat, amount)) {
        work = BattleHandler_PushWork((BattleHandler *)flow, 0xe, (void *)monId);
        work->showPopup = 1;
        work->monId = monId;
        work->active = 1;
        work->stat = stat;
        work->amount = amount;
        work->flags |= 1 << 23;
        BattleHandler_PopWork((BattleHandler *)flow, work);
    } else {
        message = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
        BattleHandler_StrSetup(&message->string, 2, 0xd2);
        BattleHandler_AddArg(&message->string, monId);
        message->flags |= 2 << 22;
        BattleHandler_PopWork((BattleHandler *)flow, message);
    }
}

struct DrySkinWeatherWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

void HandlerDrySkinWeather(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    DrySkinWeatherWork *work;
    u8 weather;
    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        weather = BattleEventVar_GetValue(0x39);
        if (weather == 1) {
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, 7, (void *)monId);
            work->monId = monId;
            work->amount = DivideMaxHPZeroCheck(mon, 8);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
        } else if (weather == 2) {
            work = BattleHandler_PushWork((BattleHandler *)flow, 5, (void *)monId);
            work->flags |= 2 << 22;
            work->monId = monId;
            work->amount = DivideMaxHPZeroCheck(mon, 8);
            BattleHandler_PopWork((BattleHandler *)flow, work);
        }
    }
}

void HandlerDrySkinDamageRecover(void *context, BtlServerFlow *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x16) == 9) {
            BattleEventVar_MulValue(0x31, 5 << 10);
        }
    }
}

void HandlerDrySkinCheck(void *context, BtlServerFlow *flow, u32 monId) {
    if (CommonDamageRecoverCheck(flow, monId, 10)) {
        CommonTypeRecoverHP(flow, monId, 4);
    }
}

const BattleEventHandlerEntry *EventAddDrySkin(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7bb4;
}

void HandlerWaterAbsorbCheck(void *context, BtlServerFlow *flow, u32 monId) {
    if (CommonDamageRecoverCheck(flow, monId, 10)) {
        CommonTypeRecoverHP(flow, monId, 4);
    }
}

const BattleEventHandlerEntry *EventAddWaterAbsorb(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77b4;
}

void HandlerVoltAbsorbCheck(void *context, BtlServerFlow *flow, u32 monId) {
    if (CommonDamageRecoverCheck(flow, monId, 12)) {
        CommonTypeRecoverHP(flow, monId, 4);
    }
}

const BattleEventHandlerEntry *EventAddVoltAbsorb(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7824;
}

const BattleEventHandlerEntry *EventAddMotorDrive(u32 *priority) {
    *priority = 1;
    return data_ov167_021d781c;
}

void HandlerMotorDriveCheck(void *context, BtlServerFlow *flow, u32 monId) {
    if (CommonDamageRecoverCheck(flow, monId, 12)) {
        CommonTypeNoEffectRankUp(flow, monId, 5, 1);
    }
}

void HandlerScrappy(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (BattleEventVar_GetValue(0x15) == 7) {
            BattleEventVar_RewriteValue(0x4b, 1);
        }
    }
}

const BattleEventHandlerEntry *EventAddScrappy(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7814;
}

struct SoundproofMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void HandlerSoundproof(void *context, BtlServerFlow *flow, u32 monId) {
    SoundproofMessageWork *work;
    u32 command;
    u16 move;

    command = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (getMoveFlag(move, 8)) {
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

const BattleEventHandlerEntry *EventAddSoundproof(u32 *priority) {
    *priority = 1;
    return data_ov167_021d780c;
}

void HandlerLevitate(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    u32 key;

    if (BattleEventVar_GetValue(2) == monId) {
        key = 0x51;
        if (BattleEventVar_GetValue(key) == 0) {
            *result = BattleEventVar_RewriteValue(key, 1);
        }
    }
}

struct LevitateImmunityWork {
    u32 flags;
    BattleHandlerString string;
};

void HandlerLevitateAddImmunity(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    LevitateImmunityWork *work;

    if (BattleEventVar_GetValue(2) == monId) {
        if (*active) {
            work = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
            work->flags |= 4 << 21;
            BattleHandler_StrSetup(&work->string, 2, 0xd2);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            *active = 0;
        }
    }
}

void HandlerLevitateTurnCheck(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    if (BattleEventVar_GetValue(2) == monId) {
        *result = 0;
    }
}

const BattleEventHandlerEntry *EventAddLevitate(u32 *priority) {
    *priority = 3;
    return data_ov167_021d7a94;
}

struct WonderGuardMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void HandlerWonderGuard(void *context, BtlServerFlow *flow, u32 monId) {
    WonderGuardMessageWork *work;
    u16 move;
    u32 run;

    if (BattleEventVar_GetValue(4) == monId) {
        run = 3;
        if (BattleEventVar_GetValue(run) != monId) {
            GetBattleMon(flow, monId);
            move = BattleEventVar_GetValue(0x12);
            if (PML_MoveIsDamaging(move)) {
                if (move != 0xa5) {
                    if ((s32)BattleEventVar_GetValue(0x38) <= 3) {
                        if (BattleEventVar_RewriteValue(0x40, 1)) {
                            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
                            work = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
                            BattleHandler_StrSetup(&work->string, 2, 0xd2);
                            BattleHandler_AddArg(&work->string, monId);
                            BattleHandler_PopWork((BattleHandler *)flow, work);
                            BattleHandler_PushRun((BattleHandler *)flow, run, (void *)monId);
                        }
                    }
                }
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddWonderGuard(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76e4;
}
