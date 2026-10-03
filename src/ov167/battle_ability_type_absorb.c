#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.

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
