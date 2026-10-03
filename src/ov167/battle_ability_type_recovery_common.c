#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.
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
