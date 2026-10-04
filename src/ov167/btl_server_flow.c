#include "types.h"
#include "battle/btl_action.h"
#include "battle/btl_action_order.h"
#include "battle/btl_ability.h"
#include "battle/btl_display.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"
#include "battle/btl_handler.h"
#include "battle/btl_item.h"
#include "battle/btl_main.h"
#include "battle/btl_move.h"
#include "battle/btl_ov169.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server.h"
#include "battle/btl_server_flow.h"
#include "gfl/arc.h"
#include "gfl/std.h"
#include "pml/personal.h"

u32 ConvertConditionCode(BattleMon *mon, u32 *condition);

BOOL func_ov167_021acca8(u32 condition, u32 value, BattleMon *mon, u32 context, BattleHandlerString *string);

BOOL func_ov167_021aceb4(void *state, u8 monId);

BOOL func_ov167_021acec4(void *state, u8 monId);

BOOL func_ov167_021a6ab8(BtlServerFlow *handler, u8 monId, BattleMon *mon, u32 stat, s32 change, u32 displayCode,
                          u32 context, u32 value, u8 extra, BOOL flag);

BtlServerFlow *func_ov167_0219f390(BtlServer *server, BtlMainModule *mainModule, BtlPokeCon *pokeCon,
                                   BtlServerCmdQueue *queue, u32 a4, HeapID heapId) {
    BtlServerFlow *flow;

    flow = GFL_HeapAllocate(heapId, sizeof(BtlServerFlow), TRUE, "btl_server_flow.c", 583);
    flow->server = server;
    flow->pokeCon = pokeCon;
    flow->mainModule = mainModule;
    flow->actionOrderCount = 0;
    flow->unk10 = 0;
    flow->unk14 = 0;
    flow->queue = queue;
    flow->heapId = heapId;
    flow->unk18 = a4;
    flow->unk4A4 = loadEvolutionFile(heapId);
    func_ov167_0219f400(flow);
    return flow;
}

void func_ov167_0219f3f8(BtlServerFlow *flow) {
    func_ov167_0219f400(flow);
}

void func_ov167_0219f400(BtlServerFlow *flow) {
    func_ov167_021bc6bc();
    func_ov167_021d59a0(0);
    func_ov169_0689d178(flow->unk1C);
    func_ov169_0689d2a0(flow->unk3E0);
    func_ov169_0689d384(flow->unk1ab8, flow->mainModule, flow->pokeCon, BtlSetup_GetBattleStyle(flow->mainModule));
    sys_memset(flow->unk7A9, 0, sizeof(flow->unk7A9));
    sys_memset(flow->unk7C1, 0, sizeof(flow->unk7C1));
    sys_memset(flow->unk7D9, 0, sizeof(flow->unk7D9));
    sys_memset(flow->unk4D4, 0, sizeof(flow->unk4D4));
    func_ov167_021ab730(flow->unk1F80);
    func_ov167_021ac0c8(flow);
    func_ov167_021bda58(&flow->clientIdList);
    func_ov167_021b083c(&flow->actionState);
    func_ov167_021a8f8c(flow->unk1B54);
    func_ov169_06898bfc();
    flow->unk786 = 0;
    flow->unk787 = 0;
    flow->unk78A_0 = 0;
    flow->unk78A_1 = 0;
    flow->unk78A_2 = 0;
    flow->unk77C = 0;
    flow->unk789 = 0x1f;
    flow->unk1F78 = 0;
    flow->unk784 = 6;
    flow->unk774 = 0;
    flow->unk77E = 0;
    flow->unk778 = 0;
    flow->unk78A_6 = 0;
}

void func_ov167_0219f570(BtlServerFlow *flow) {
    GFL_ArcToolFree(flow->unk4A4);
    GFL_HeapFree(flow);
}

u8 func_ov167_0219f588(BtlServerFlow *flow) {
    BtlServerCmdQueue *queue;
    u8 result;
    u8 weather;
    u32 clientId;
    BtlServerClient *client;
    u32 i;
    BattleMon *mon;

    queue = flow->queue;
    queue->writePos = 0;
    result = FALSE;
    queue->readPos = 0;
    weather = GetFieldEffectData(flow->mainModule)->weather;
    if (weather != 0 && ServerControl_ChangeWeather(flow, weather, 0xff)) {
        result = TRUE;
    }
    for (clientId = 0; clientId < 4; clientId++) {
        client = func_ov167_0219f27c(flow->server, clientId);
        if (client != NULL) {
            for (i = 0; i < client->numCoverPos; i++) {
                mon = func_ov167_0219d4e4(client->party, i);
                if (mon != NULL && !IsFainted(mon)) {
                    ServerControl_SwitchInCore(flow, clientId, i, i);
                }
            }
            if (BtlSetup_GetBattleStyle(flow->mainModule) == 3) {
                for (i = 0; i < 3; i++) {
                    mon = func_ov167_0219d4e4(client->party, i);
                    if (mon != NULL && !IsFainted(mon)) {
                        func_ov167_0219bfa0(flow->mainModule, clientId, mon);
                    }
                }
            }
        }
    }
    if (ServerControl_AfterSwitchIn(flow)) {
        result = TRUE;
    }
    return result;
}

void func_ov167_0219f65c(BtlServerFlow *flow) {
    flow->unk77C = 0;
    flow->unk783 = 0;
}

u32 func_ov167_0219f66c(BtlServerFlow *flow, BtlClientActions *clientActions) {
    u32 i;

    flow->unk14 = 0;
    BtlServerCmdQueue_Init(flow->queue);
    if (flow->unk77C == 0) {
        func_ov167_021ac028(flow);
        func_ov169_0689d2bc(flow->unk3E0);
        for (i = 0; i < 4; i++) {
            flow->unk1FEC[i] = 0;
        }
        func_ov167_021bc6f8();
        func_ov167_0219f348(flow->server);
        func_ov167_021bccf4();
        func_ov167_0219f6fc(flow);
        flow->actionOrderCount = func_ov167_021a00a4(flow, clientActions, flow->actionOrder, 6);
        flow->unk77C = 1;
    }
    flow->unk783 = func_ov167_0219f9d0(flow, flow->unk783);
    return flow->unk14;
}

void func_ov167_0219f6fc(BtlServerFlow *flow) {
    BtlFlowMonIter iter;
    BattleMon *mon;

    func_ov167_021a0d5c(&iter, flow);
    while (func_ov167_021a0df4(&iter, flow, &mon)) {
        if (GetAdditionalConditionFlag(mon, 0xc)) {
            scPut_ResetContFlag(flow, mon, 0xc);
        }
    }
}

void func_ov167_0219f748(BtlServerFlow *flow) {
    flow->unk77C = 0;
}

u32 func_ov167_0219f754(BtlServerFlow *flow, BtlClientActions *clientActions) {
    flow->unk14 = 0;
    BtlServerCmdQueue_Init(flow->queue);
    if (flow->unk77C == 0) {
        func_ov167_0219f348(flow->server);
        func_ov167_021bccf4();
        flow->unk77D = 0;
        flow->unk77C = 1;
        if (func_ov167_0219fc74(flow, clientActions)) {
            flow->unk14 = 3;
            return flow->unk14;
        }
    }
    flow->unk783 = func_ov167_0219f9d0(flow, flow->unk783);
    return flow->unk14;
}

void func_ov167_0219f7a8(BtlServerFlow *flow) {
    flow->unk77C = 0;
}

u32 func_ov167_0219f7b4(BtlServerFlow *flow, BtlClientActions *clientActions) {
    u32 i;
    u32 sideEffects;

    flow->unk14 = 0;
    BtlServerCmdQueue_Init(flow->queue);
    if (flow->unk77C == 0) {
        func_ov167_0219f348(flow->server);
        func_ov167_021bccf4();
        sideEffects = func_ov169_0689d2fc(flow->unk3E0, 0);
        flow->actionOrderCount = func_ov167_021a00a4(flow, clientActions, flow->actionOrder, 6);
        flow->unk783 = 0;
        for (i = 0; i < flow->actionOrderCount; i++) {
            if (flow->actionOrder[i].action.change.action == 3 && !flow->actionOrder[i].action.change.unk10 &&
                !IsFainted(flow->actionOrder[i].mon)) {
                func_ov167_021a1740(flow, flow->actionOrder[i].mon, flow->actionOrder[i].action.change.slot);
                flow->actionOrder[i].done = TRUE;
            }
        }
        for (i = 0; i < flow->actionOrderCount; i++) {
            if (flow->actionOrder[i].action.change.action == 3 && !flow->actionOrder[i].action.change.unk10 &&
                IsFainted(flow->actionOrder[i].mon)) {
                ServerControl_SwitchInFillSlot(flow, flow->actionOrder[i].clientId, flow->actionOrder[i].action.change.unk4,
                                               flow->actionOrder[i].action.change.slot, TRUE);
                flow->actionOrder[i].done = TRUE;
            }
        }
        if (BtlSetup_GetBattleStyle(flow->mainModule) == 3) {
            for (i = 0; i < flow->actionOrderCount; i++) {
                if (flow->actionOrder[i].action.change.action == 6 && !flow->actionOrder[i].action.change.unk10) {
                    func_ov167_021a0778(flow, &flow->actionOrder[i]);
                }
            }
        }
        flow->unk77C = 1;
    }
    ServerControl_AfterSwitchIn(flow);
    func_ov167_021a8cc0(flow);
    func_ov167_0219ff70(flow, &flow->unk4CE);
    if (sideEffects == func_ov169_0689d2fc(flow->unk3E0, 0)) {
        func_ov167_021a80c4(flow);
        return 0;
    }
    if (!ServerControl_CheckMatchup(flow)) {
        func_ov167_021a9c70(flow, &flow->unk4CE);
        return 2;
    }
    return 4;
}

u32 func_ov167_0219f9d0(BtlServerFlow *flow, u32 i) {
    u8 fainted;
    u32 prevAction;
    u32 action;
    u8 matchup;
    u8 switched;
    u32 sideEffects;

    prevAction = 0;
    for (; i < flow->actionOrderCount; i++) {
        action = BattleAction_GetAction(&flow->actionOrder[i].action);
        if (prevAction == 6 && action != 6) {
            func_ov167_021a16d4(flow);
            func_ov167_0219fb3c(flow, &flow->actionOrder[i], flow->actionOrderCount - i);
        }
        prevAction = func_ov167_021a0778(flow, &flow->actionOrder[i]);
        fainted = func_ov167_021a8cc0(flow);
        func_ov167_021bc6ac(GetPokeParam(flow->pokeCon, 0));
        matchup = ServerControl_CheckMatchup(flow);
        func_ov167_021bc6ac(GetPokeParam(flow->pokeCon, 0));
        if (matchup) {
            flow->unk14 = 4;
            return i + 1;
        }
        if (flow->unk14 == 6) {
            return i + 1;
        }
        if (flow->unk14 == 1) {
            return i + 1;
        }
        if (fainted) {
            func_ov167_021bc6ac(GetPokeParam(flow->pokeCon, 0));
            flow->unk14 = 3;
            return i + 1;
        }
    }
    if (flow->unk14 == 0) {
        switched = func_ov167_021a7f1c(flow);
        if ((u8)ServerControl_CheckMatchup(flow)) {
            flow->unk14 = 4;
            return flow->actionOrderCount;
        }
        if (switched) {
            flow->unk14 = 3;
            return flow->actionOrderCount;
        }
        sideEffects = func_ov169_0689d2fc(flow->unk3E0, 0);
        if (func_ov167_021ac074(flow) || sideEffects) {
            func_ov167_0219ff70(flow, &flow->unk4CE);
            func_ov167_021a9c70(flow, &flow->unk4CE);
            flow->unk14 = 2;
            return flow->actionOrderCount;
        }
        flow->unk14 = 0;
    }
    return flow->actionOrderCount;
}

static inline u32 ActionOrder_MakeKey(u16 speed, u8 unk13, u8 unk16, u8 unk22) {
    return (speed & 0x1fff) | ((unk13 & 7) << 13) | ((unk16 & 0x3f) << 16) | ((unk22 & 7) << 22);
}

void func_ov167_0219fb3c(BtlServerFlow *flow, ActionOrderEntry *order, u32 count) {
    u32 i;
    u32 action;
    u16 move;
    u32 state;
    u8 unk16;

    for (i = 0; i < count; i++) {
        order[i].key = (order[i].key & 0xffffe000) | (ServerEvent_CalculateSpeed(flow, order[i].mon, TRUE) & 0x1fff);
        action = BattleAction_GetAction(&order[i].action);
        if (action == 1) {
            move = BattleAction_GetMove(&order[i].action);
            state = PushState(&flow->actionState, 0x436);
            unk16 = func_ov167_021a0380(flow, move, order[i].mon);
            order[i].key = ActionOrder_MakeKey(order[i].key & 0x1fff, (order[i].key >> 13) & 7, unk16, (order[i].key >> 22) & 7);
            PopState(&flow->actionState, state, 0x439);
        }
        if (action == 1 || action == 5) {
            state = PushState(&flow->actionState, 0x441);
            order[i].key = (order[i].key & 0xffff1fff) | ((func_ov167_021a9e68(flow, order[i].mon) & 7) << 13);
            PopState(&flow->actionState, state, 0x444);
        }
    }
    func_ov167_021a0308(order, count);
}

BOOL func_ov167_0219fc74(BtlServerFlow *flow, BtlClientActions *clientActions) {
    u32 clientId;
    u32 count;
    u32 i;
    BattleAction action;

    for (clientId = 0; clientId < 4; clientId++) {
        if (func_ov167_0219f260(flow->server, clientId)) {
            count = func_ov167_0219f2ac(clientActions, clientId);
            for (i = 0; i < count; i++) {
                action = func_ov167_0219f2b4(clientActions, clientId, i);
                if (action.change.action == 3 && !action.change.unk10) {
                    ServerControl_SwitchInFillSlot(flow, clientId, action.change.unk4, action.change.slot, TRUE);
                }
            }
        }
    }
    ServerControl_AfterSwitchIn(flow);
    return func_ov167_021a8cc0(flow);
}

BOOL ServerControl_CheckMatchup(BtlServerFlow *flow) {
    u8 hasMons[2];
    u32 i;
    BattleParty *party;
    u8 side;
    u32 alive;

    hasMons[0] = hasMons[1] = 0;
    for (i = 0; i < 4; i++) {
        if (DoesClientExist(flow->mainModule, i)) {
            party = GetPartyData(flow->pokeCon, i);
            side = GetClientSide(flow->mainModule, i);
            alive = GetAlivePartyCount(party);
            if (i == 0) {
                func_ov167_021bc6ac(GetPokeParam(flow->pokeCon, 0));
            }
            if (alive != 0) {
                hasMons[side] = 1;
            }
        }
    }
    func_ov167_021bc6ac(GetPokeParam(flow->pokeCon, 0));
    if ((func_ov167_0219c988(flow->mainModule) == 1 || func_ov167_0219c988(flow->mainModule) == 2) &&
        func_ov167_021b0318(flow->mainModule, flow->pokeCon)) {
        return TRUE;
    }
    if (!hasMons[0] || !hasMons[1]) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov167_0219fda4(BtlServerFlow *flow) {
    u32 i;

    for (i = 0; i < 4; i++) {
        if (DoesClientExist(flow->mainModule, i) &&
            GetClientSide(flow->mainModule, i) == GetClientSide(flow->mainModule, GetPlayerClientID(flow->mainModule)) &&
            GetAlivePartyCount(GetPartyData(flow->pokeCon, i)) != 0) {
            return TRUE;
        }
    }
    return FALSE;
}

u32 func_ov167_0219fdf4(BtlServerFlow *flow) {
    BattleMon *mon;
    u32 result;

    mon = func_ov167_0219d1e8(flow->pokeCon, GetPlayerClientID(flow->mainModule), 0);
    result = 0;
    BtlServerCmdQueue_Init(flow->queue);
    if (ServerControl_Escape(flow, mon)) {
        result = 1;
    }
    return result;
}

BOOL func_ov167_0219fe24(BtlServerFlow *flow) {
    BOOL result;

    result = FALSE;
    BtlServerCmdQueue_Init(flow->queue);
    func_ov167_0219fe44(flow);
    if (flow->queue->writePos != 0) {
        result = TRUE;
    }
    return result;
}

void func_ov167_0219fe44(BtlServerFlow *flow) {
    u32 i;
    u32 count;
    u8 clientIds[4];

    if (flow->unk18 == 1) {
        for (i = 0; i < 4; i++) {
            if (func_ov167_0219f294(flow->server, i)) {
                if (BtlSetup_GetBattleStyle(flow->mainModule) != 2) {
                    count = 1;
                } else {
                    count = func_ov169_0689d6e0(flow->unk1ab8, i, clientIds) + 1;
                }
                func_ov167_021b1434(flow->queue, 0x29, i, (u8)count);
            }
        }
    }
}

void func_ov167_0219feac(BtlServerFlow *flow, u8 clientId, u8 slot) {
    BattleParty *party;
    BattleMon *outMon;
    BattleMon *inMon;

    if (slot != 1 && slot != 0) {
        party = GetPartyData(flow->pokeCon, clientId);
        func_ov167_021b1434(flow->queue, 0x48, clientId, slot);
        func_ov167_0219d544(party, slot, &outMon, &inMon);
        if (!IsFainted(outMon)) {
            ServerControl_ClearMonDependentEffects(flow, outMon, TRUE);
        }
        if (!IsFainted(inMon)) {
            if (IsFieldEffectActive(2)) {
                if (CheckCondition(inMon, 0x20)) {
                    ServerControl_CureCondition(flow, inMon, 0x20, 0);
                }
                if (CheckCondition(inMon, 0x1e)) {
                    ServerControl_CureCondition(flow, inMon, 0x1e, 0);
                }
            }
            AbilityEvent_ItemRotationWake(inMon);
            ItemEvent_ItemRotationWake(inMon);
        }
        func_ov169_0689d4c0(flow->unk1ab8, slot, clientId, inMon, flow->pokeCon);
    }
}

BOOL func_ov167_0219ff70(BtlServerFlow *flow, BtlFlowClientList *list) {
    BOOL result;
    u8 clientId;
    u8 count;
    u8 i;
    u8 positions[4];

    result = FALSE;
    list->count = 0;
    for (clientId = 0; clientId < 4; clientId++) {
        count = func_ov169_0689d6e0(flow->unk1ab8, clientId, positions);
        if (count != 0) {
            for (i = 0; i < count; i++) {
                RequestChangePokemon(flow->server, positions[i]);
            }
            result = TRUE;
            list->clientIds[list->count++] = clientId;
        }
    }
    return result;
}

BtlClientIDList *func_ov167_0219ffe4(BtlServerFlow *flow) {
    return &flow->clientIdList;
}

u8 func_ov167_0219fff0(BtlServerFlow *flow) {
    return flow->unk784;
}

void func_ov167_0219fffc(BtlServerFlow *flow) {
    u32 state;
    u32 i;
    u16 move;
    BattleMon *mon;
    ActionOrderEntry *entry;

    state = PushState(&flow->actionState, 0x59b);
    for (i = 0; i < flow->actionOrderCount; i++) {
        entry = &flow->actionOrder[i];
        move = BattleAction_GetMove(&entry->action);
        if (move != 0) {
            mon = flow->actionOrder[i].mon;
            if (MoveEvent_AddItem(mon, move, GetBattleMonStat(mon, 0xc))) {
                func_ov167_021a9eac(flow, mon, move);
                func_ov167_021c5bbc(mon, move);
            }
        }
    }
    PopState(&flow->actionState, state, 0x5aa);
}

// Function name from swan.
ActionOrderEntry *ActionOrder_SearchByMonID(BtlServerFlow *flow, u8 monId) {
    u32 i;

    for (i = 0; i < flow->actionOrderCount; i++) {
        if (GetMonID(flow->actionOrder[i].mon) == monId) {
            return &flow->actionOrder[i];
        }
    }
    return NULL;
}

// Function names from swan.
BOOL ActionOrder_InterruptReserve(BtlServerFlow *flow, u8 monId) {
    ActionOrderEntry *entry;

    entry = ActionOrder_SearchByMonID(flow, monId);
    if (entry && !entry->done && ActionOrderTool_Interrupt(flow, entry, 0) >= 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL ActionOrder_InterruptReserveByMove(BtlServerFlow *flow, u16 moveId) {
    u32 start;
    BOOL didInterrupt;
    ActionOrderEntry *entry;
    s32 index;

    start = 0;
    entry = ActionOrder_SearchByMoveID(flow, moveId, 0);
    didInterrupt = FALSE;
    while (entry) {
        index = ActionOrderTool_Interrupt(flow, entry, start);
        if (index < 0) {
            break;
        }
        start = index + 1;
        entry = ActionOrder_SearchByMoveID(flow, moveId, (u8)start);
        didInterrupt = TRUE;
    }
    return didInterrupt;
}

BOOL ActionOrder_SendToLast(BtlServerFlow *flow, u8 monId) {
    ActionOrderEntry *entry;

    entry = ActionOrder_SearchByMonID(flow, monId);
    if (entry && !entry->done) {
        ActionOrderTool_SendToLast(flow, entry);
        return TRUE;
    }
    return FALSE;
}

void ActionOrder_ForceDone(BtlServerFlow *flow, u8 monId) {
    ActionOrderEntry *entry;

    entry = ActionOrder_SearchByMonID(flow, monId);
    if (entry) {
        entry->done = 1;
    }
}

// Function names from swan.
void ServerDisplay_AbilityPopupAdd(BtlServerFlow *handler, BattleMon *mon) {
    func_ov167_021b1434(handler->queue, 0x57, GetMonID(mon));
}

void ServerDisplay_AbilityPopupRemove(BtlServerFlow *handler, BattleMon *mon) {
    func_ov167_021b1434(handler->queue, 0x58, GetMonID(mon));
}

// Function names from swan.
void scPut_SetContFlag(BtlServerFlow *handler, BattleMon *mon, u32 flag) {
    func_ov167_021bb7e4(mon, flag);
    func_ov167_021b1434(handler->queue, 0x19, GetMonID(mon), flag);
}

void scPut_ResetContFlag(BtlServerFlow *handler, BattleMon *mon, u32 flag) {
    func_ov167_021bb808(mon, flag);
    func_ov167_021b1434(handler->queue, 0x1a, GetMonID(mon), flag);
}

void ServerDisplay_SetTurnFlag(BtlServerFlow *handler, BattleMon *mon, u32 flag) {
    func_ov167_021bb7c0(mon, flag);
    func_ov167_021b1434(handler->queue, 0x1b, GetMonID(mon), flag);
}

void BattleHandler_StrClear(BattleHandlerString *string) {
    sys_memset(string, 0, 0x28);
    string->enabled = 0;
}

BOOL BattleHandler_StrIsEnabled(BattleHandlerString *string) {
    return string->enabled != 0;
}

void BattleHandler_StrSetup(BattleHandlerString *string, u32 enabled, u16 message) {
    string->enabled = enabled;
    string->message = message;
    string->count = 0;
}

void BattleHandler_AddArg(BattleHandlerString *string, u32 arg) {
    u16 count;

    count = string->count;
    if (count < 9) {
        string->count = count + 1;
        string->args[count] = arg;
    }
}

void BattleHandler_AddSoundEffect(BattleHandlerString *string, u32 soundEffect) {
    if (string->count < 9) {
        string->soundEffect = soundEffect;
        string->hasSound = 1;
    }
}

void *BattleHandler_PushWork(BtlServerFlow *flow, u32 command, u32 monId) {
    return func_ov167_021b0920(&flow->actionState, command, monId);
}

void BattleHandler_PushRun(BtlServerFlow *flow, u32 command, u32 monId) {
    void *work;

    work = BattleHandler_PushWork(flow, command, monId);
    BattleHandler_PopWork(flow, work);
}

void BattleHandler_PopWork(BtlServerFlow *flow, void *work) {
    BattleHandler_Execute(flow);
    PopWork(&flow->actionState, work);
}

u32 BattleHandler_Result(BtlServerFlow *handler) {
    BtlActionState *state;

    state = &handler->actionState;
    if (IsUsed(state)) {
        if (func_ov167_021b0918(state)) {
            return 2;
        }
        return 1;
    }
    return 0;
}

// Function name from swan.
BOOL BattleHandler_AbilityPopupRemove(BtlServerFlow *handler, BattleHandlerPopupParam *param) {
    BattleMon *mon = GetPokeParam(handler->pokeCon, param->monId);
    ServerDisplay_AbilityPopupRemove(handler, mon);
    return TRUE;
}

// Function name from swan.
BOOL BattleHandler_Drain(BtlServerFlow *handler, BattleHandlerDrainParam *param) {
    BattleMon *source;
    BattleMon *mon;

    source = NULL;
    if (param->sourceIndex != 0x1f) {
        source = GetPokeParam(handler->pokeCon, param->sourceIndex);
    }
    if (func_ov167_021ac988(handler->unk1ab8, param->monIndex)) {
        mon = GetPokeParam(handler->pokeCon, param->monIndex);
        if (!IsFainted(mon)) {
            if (ServerControl_DrainCore(handler, mon, source, param->amount)) {
                if (param->string.enabled) {
                    BattleHandler_SetString(handler, &param->string);
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_Damage(BtlServerFlow *handler, BattleHandlerDamageParam *param) {
    BattleMon *mon;
    BattleMon *source;

    if (func_ov167_021aca54(handler->unk1ab8, param->targetIndex)) {
        mon = GetPokeParam(handler->pokeCon, param->targetIndex);
        source = NULL;
        if (param->sourceIndex != 0x1f) {
            source = GetPokeParam(handler->pokeCon, param->sourceIndex);
        }
        if (!IsFainted(mon)) {
            if (!param->checkSemi || !IsSemiInvulnMove(mon)) {
                if (ServerControl_CheckSimpleDamageEnabled(handler, mon, param->amount)) {
                    if (param->popup) {
                        ServerDisplay_AbilityPopupAdd(handler, source);
                    }
                    if (param->showViewEffect) {
                        ServerControl_ViewEffect(handler, param->effect, param->effectArg1, param->effectArg2, 0, 0);
                    }
                    ServerControl_SimpleDamageCore(handler, mon, param->amount, &param->string);
                    if (param->popup) {
                        ServerDisplay_AbilityPopupRemove(handler, source);
                    }
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_ChangeHP(BtlServerFlow *handler, BattleHandlerChangeHPParam *param) {
    u32 result;
    u32 i;
    BattleMon *mon;

    result = FALSE;
    for (i = 0; i < param->count; i++) {
        if (func_ov167_021acad4(handler->unk1ab8, param->monIds[i])) {
            mon = GetPokeParam(handler->pokeCon, param->monIds[i]);
            if (!IsFainted(mon)) {
                ServerDisplay_SimpleHP(handler, mon, param->hpChanges[i], param->suppress == 0);
                if (param->skipReaction == 0) {
                    ServerControl_CheckItemReaction(handler, mon, 1);
                }
                result = TRUE;
            }
        }
    }
    return result;
}

// Function name from swan.
BOOL BattleHandler_DecrementPP(BtlServerFlow *handler, BattleHandlerDecrementPPParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon) || param->allowFainted) {
        if (ServerControl_DecrementPP(handler, mon, param->moveIndex, param->amount)) {
            BattleHandler_SetString(handler, &param->string);
            if (ServerEvent_DecrementPP(handler, mon, param->moveIndex)) {
                ServerControl_UseHeldItem(handler, mon);
            }
        }
        return TRUE;
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_CureCondition(BtlServerFlow *handler, struct BattleHandlerCureConditionParam *param, u32 context) {
    BattleMon *mon;
    BattleMon *target;
    u32 changed;
    u32 i;
    u32 condition;
    u32 code;
    u32 resultCondition;
    BattleHandlerString *string;

    target = GetPokeParam(handler->pokeCon, param->monIndex);
    changed = FALSE;
    if (param->popup) {
        ServerDisplay_AbilityPopupAdd(handler, target);
    }
    for (i = 0; i < param->count; i++) {
        mon = GetPokeParam(handler->pokeCon, param->monIds[i]);
        if (!CanPokemonBattle(mon)) {
            continue;
        }
        condition = param->condition;
        code = ConvertConditionCode(mon, &condition);
        if (code == 0) {
            continue;
        }
        string = &param->string;
        changed = TRUE;
        do {
                    ((void (*)(BtlServerFlow *, BattleMon *, u32, u32 *))ServerControl_CureCondition)(handler, mon, code,
                                                                                                 &resultCondition);
                    if (param->useString == 0) {
                        if (func_ov167_021acca8(code, resultCondition, mon, context,
                                                &handler->message)) {
                            BattleHandler_SetString(handler, &handler->message);
                            BattleHandler_StrClear(&handler->message);
                        }
                    } else {
                        BattleHandler_SetString(handler, string);
                    }
                    if (code == 0x13) {
                        ServerControl_CheckItemReaction(handler, mon, 0);
                    }
                    code = ConvertConditionCode(mon, &condition);
        } while (code);
    }
    if (param->popup) {
        ServerDisplay_AbilityPopupRemove(handler, target);
    }
    return changed;
}

// Function name from swan.
BOOL BattleHandler_StatChange(BtlServerFlow *handler, struct BattleHandlerStatChangeParam *param, u32 context) {
    BattleMon *popupMon;
    BattleMon *mon;
    BOOL valid;
    BOOL result;
    u32 i;
    u32 stat;

    popupMon = GetPokeParam(handler->pokeCon, param->monIndex);
    valid = FALSE;
    result = FALSE;
    for (i = 0; i < param->count; i++) {
        if (func_ov167_021aceb4(handler->unk1ab8, param->monIds[i])) {
            mon = GetPokeParam(handler->pokeCon, param->monIds[i]);
            if (!IsFainted(mon) && IsStatChangeValid(mon, param->stat, param->change)) {
                valid = TRUE;
                break;
            }
        }
    }
    if (valid && param->popup) {
        ServerDisplay_AbilityPopupAdd(handler, popupMon);
    }
    for (i = 0; i < param->count; i++) {
        if (func_ov167_021acec4(handler->unk1ab8, param->monIds[i])) {
            mon = GetPokeParam(handler->pokeCon, param->monIds[i]);
            if (!IsFainted(mon)) {
                stat = param->stat;
                if (func_ov167_021a6ab8(handler, param->monIndex, mon, stat, param->change, 0x1f, context,
                                         param->value, param->unk0e, param->flag == 0)) {
                    BattleHandler_SetString(handler, &param->string);
                    result = TRUE;
                }
            }
        }
    }
    if (valid && param->popup) {
        ServerDisplay_AbilityPopupRemove(handler, popupMon);
    }
    return result;
}

// Function names from swan.
u8 BattleHandler_RecoverStatStage(BtlServerFlow *handler, BattleHandlerRecoverStatStageParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        func_ov167_021b1434(handler->queue, 0xc, param->monIndex);
        return StatStageRecover(mon);
    }
    return FALSE;
}

BOOL BattleHandler_ResetStatStage(BtlServerFlow *handler, BattleHandlerResetStatStageParam *param) {
    u32 i;
    BOOL result;
    BattleMon *mon;

    result = FALSE;
    for (i = 0; i < param->count; i++) {
        mon = GetPokeParam(handler->pokeCon, param->monIndices[i]);
        if (!IsFainted(mon)) {
            func_ov167_021b1434(handler->queue, 0xd, param->monIndices[i]);
            StatStageReset(mon);
            result = TRUE;
        }
    }
    return result;
}

// Function name from swan.
BOOL BattleHandler_Faint(BtlServerFlow *handler, BattleHandlerFaintParam *param) {
    BattleMon *mon;

    if (func_ov167_021ad15c(handler->unk1ab8, param->monIndex)) {
        mon = GetPokeParam(handler->pokeCon, param->monIndex);
        if (!IsFainted(mon) || param->force) {
            BattleHandler_SetString(handler, &param->string);
            ServerControl_FaintPokemon(handler, mon);
            return TRUE;
        }
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_ChangeType(BtlServerFlow *handler, BattleHandlerChangeTypeParam *param) {
    BattleMon *mon;

    if (func_ov167_021ad1f4(handler->unk1ab8, param->monIndex)) {
        mon = GetPokeParam(handler->pokeCon, param->monIndex);
        if (!IsFainted(mon) && !func_ov167_021ad204(GetBattleMonSpecies(mon))) {
            func_ov167_021b1434(handler->queue, 0x16, param->monIndex, param->type);
            ChangePokeType(mon, param->type);
            if (!param->suppressMessage && PokeTypePair_IsMonotype(param->type)) {
                func_ov167_021b15d0(handler->queue, 0x5b, 0x380, param->monIndex, PokeTypePair_GetType1(param->type),
                                    0xffff0000);
            }
            return TRUE;
        }
    }
    return FALSE;
}

BOOL BattleHandler_Message(BtlServerFlow *handler, BattleHandlerMessageParam *param) {
    BattleMon *mon;

    mon = NULL;
    if (param->monIndex != 0x1f) {
        mon = GetPokeParam(handler->pokeCon, param->monIndex);
    }
    if (param->popup && mon != NULL) {
        ServerDisplay_AbilityPopupAdd(handler, mon);
    }
    BattleHandler_SetString(handler, &param->string);
    if (param->popup && mon != NULL) {
        ServerDisplay_AbilityPopupRemove(handler, mon);
    }
    return TRUE;
}

BOOL BattleHandler_SetTurnFlag(BtlServerFlow *handler, BattleHandlerFlagParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        func_ov167_021bb7c0(mon, param->flag);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_ResetTurnFlag(BtlServerFlow *handler, BattleHandlerFlagParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        func_ov167_021bbc40(mon, param->flag);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_SetContinueFlag(BtlServerFlow *handler, BattleHandlerFlagParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        scPut_SetContFlag(handler, mon, param->flag);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_ResetContinueFlag(BtlServerFlow *handler, BattleHandlerFlagParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        scPut_ResetContFlag(handler, mon, param->flag);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_AddFieldEffect(BtlServerFlow *handler, BattleHandlerAddFieldEffectParam *param) {
    if (ServerControl_FieldEffectCore(handler, param->effect, param->value, param->duration)) {
        BattleHandler_SetString(handler, &param->string);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_RemoveFieldEffect(BtlServerFlow *handler, BattleHandlerRemoveFieldEffectParam *param) {
    if (FieldStatusRemoveEffect(param->effect)) {
        ServerControl_FieldEffectEnd(handler, param->effect);
        return TRUE;
    }
    return FALSE;
}

u8 BattleHandler_ChangeWeather(BtlServerFlow *handler, BattleHandlerChangeWeatherParam *param) {
    BattleMon *mon;
    u32 result;
    u32 state;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    result = FALSE;
    if (param->weather != 0) {
        if (ServerControl_ChangeWeatherCheck(handler, param->weather, param->duration)) {
            if (param->popup) {
                ServerDisplay_AbilityPopupAdd(handler, mon);
            }
            ServerControl_ChangeWeatherCore(handler, param->weather, param->duration);
            BattleHandler_SetString(handler, &param->string);
            result = TRUE;
            if (param->popup) {
                ServerDisplay_AbilityPopupRemove(handler, mon);
            }
        }
    } else if (param->notifyAirLock != 0) {
        if (param->popup) {
            ServerDisplay_AbilityPopupAdd(handler, mon);
        }
        BattleHandler_SetString(handler, &param->string);
        state = PushState(&handler->actionState, 0x3c98);
        ServerEvent_NotifyAirLock(handler);
        PopState(&handler->actionState, state, 0x3c9a);
        result = TRUE;
        if (param->popup) {
            ServerDisplay_AbilityPopupRemove(handler, mon);
        }
    }
    return result;
}

// Function name from swan.
BOOL BattleHandler_SetString(BtlServerFlow *handler, BattleHandlerString *string) {
    u16 soundEffect;
    u32 flags;

    flags = string->flags;

    if (!((flags << 16) >> 31)) {
        switch ((flags & 0xff)) {
        case 1:
            ServerDisplay_StandardMessage(handler, string->message, ((flags << 17) >> 25), string->args);
            return TRUE;
        case 2:
            ServerDisplay_SetMessage(handler, string->message, ((flags << 17) >> 25), string->args);
            return TRUE;
        }
    } else {
        soundEffect = string->soundEffect;
        switch ((flags & 0xff)) {
        case 1:
            ServerDisplay_StandardMessageEx(handler, string->message, soundEffect, ((flags << 17) >> 25), string->args);
            return TRUE;
        case 2:
            ServerDisplay_SetMessageEx(handler, string->message, soundEffect, ((flags << 17) >> 25), string->args);
            return TRUE;
        }
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_AbilityChange(BtlServerFlow *handler, BattleHandlerAbilityChangeParam *param) {
    BattleMon *mon;
    u16 oldAbility;
    u32 state;

    mon = GetPokeParam(handler->pokeCon, param->targetIndex);
    oldAbility = GetBattleMonStat(mon, 0x10);
    if (func_ov167_021ad6e8(oldAbility)) {
        return FALSE;
    }
    if (IsFainted(mon)) {
        return FALSE;
    }
    if (param->force || param->ability != oldAbility) {
        if (param->popup) {
            func_ov167_021b1434(handler->queue, 0x57, param->monIndex);
        }
        func_ov167_021b1434(handler->queue, 0x49, param->targetIndex, param->ability);
        BattleHandler_SetString(handler, &param->string);
        state = PushState(&handler->actionState, 0x3cf6);
        ServerEvent_ChangeAbilityBefore(handler, param->targetIndex, oldAbility, param->ability);
        PopState(&handler->actionState, state, 0x3cf8);
        AbilityEvent_RemoveItem(mon);
        ChangeAbility(mon, param->ability);
        func_ov167_021b1434(handler->queue, 0x1d, param->targetIndex, param->ability);
        AbilityEvent_AddItem(mon);
        func_ov167_021b1434(handler->queue, 0x58, param->targetIndex);
        if (oldAbility != param->ability) {
            state = PushState(&handler->actionState, 0x3d06);
            ServerEvent_ChangeAbilityAfter(handler, param->targetIndex);
            PopState(&handler->actionState, state, 0x3d08);
        }
        if (param->popup) {
            func_ov167_021b1434(handler->queue, 0x58, param->monIndex);
        }
        if (!CheckCondition(mon, 16)) {
            if (oldAbility == 0x67) {
                ServerControl_CheckItemReaction(handler, mon, 0);
            }
            if (oldAbility == 0x7f) {
                ServerControl_UnnerveAction(handler, mon);
            }
        }
        return TRUE;
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_SetItem(BtlServerFlow *handler, BattleHandlerSetItemParam *param) {
    BattleMon *mon;
    u8 result;
    u32 state;

    mon = GetPokeParam(handler->pokeCon, param->targetIndex);
    if (param->monIndex != param->targetIndex) {
        state = PushState(&handler->actionState, 0x3d2c);
        result = ServerEvent_CheckItemSet(handler, mon, param->item);
        PopState(&handler->actionState, state, 0x3d2e);
        if (result) {
            state = PushState(&handler->actionState, 0x3d32);
            ServerEvent_ItemSetFailed(handler, mon);
            PopState(&handler->actionState, state, 0x3d34);
            return FALSE;
        }
    }
    if (param->popup) {
        func_ov167_021b1434(handler->queue, 0x57, param->monIndex);
    }
    BattleHandler_SetString(handler, &param->string);
    ServerControl_ChangeHeldItem(handler, mon, param->item, 0);
    if (param->popup) {
        func_ov167_021b1434(handler->queue, 0x58, param->monIndex);
    }
    if (param->clearConsumed) {
        ClearConsumedItem(mon);
        func_ov167_021b1434(handler->queue, 0x2b, param->targetIndex);
    }
    if (param->clearOtherConsumed) {
        ClearConsumedItem(GetPokeParam(handler->pokeCon, param->otherIndex));
        func_ov167_021b1434(handler->queue, 0x2b, param->otherIndex);
    }
    ServerControl_CheckItemReaction(handler, mon, 0);
    return TRUE;
}

// Function name from swan.
BOOL BattleHandler_SwapItem(BtlServerFlow *handler, BattleHandlerSwapItemParam *param) {
    BattleMon *first;
    BattleMon *second;
    u16 firstItem;
    u16 secondItem;
    u8 result;
    u32 state;

    first = GetPokeParam(handler->pokeCon, param->otherIndex);
    second = GetPokeParam(handler->pokeCon, param->monIndex);
    firstItem = GetBattleMonHeldItem(second);
    secondItem = GetBattleMonHeldItem(first);
    state = PushState(&handler->actionState, 0x3d64);
    result = ServerEvent_CheckItemSet(handler, first, firstItem);
    PopState(&handler->actionState, state, 0x3d66);
    if (result) {
        state = PushState(&handler->actionState, 0x3d69);
        ServerEvent_ItemSetFailed(handler, first);
        PopState(&handler->actionState, state, 0x3d6b);
        return FALSE;
    }
    if (param->popup) {
        ServerDisplay_AbilityPopupAdd(handler, second);
    }
    BattleHandler_SetString(handler, &param->firstString);
    BattleHandler_SetString(handler, &param->secondString);
    BattleHandler_SetString(handler, &param->thirdString);
    if (param->popup) {
        ServerDisplay_AbilityPopupRemove(handler, second);
    }
    ServerControl_ChangeHeldItem(handler, second, secondItem, 0);
    ServerControl_ChangeHeldItem(handler, first, firstItem, 0);
    ServerControl_CheckItemReaction(handler, second, 0);
    ServerControl_CheckItemReaction(handler, first, 0);
    return TRUE;
}

// Function name from swan.
BOOL BattleHandler_CheckHeldItem(BtlServerFlow *handler, BattleHandlerCheckHeldItemParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    ServerControl_CheckItemReaction(handler, mon, param->reaction);
    return TRUE;
}

// Function name from swan.
BOOL BattleHandler_UseHeldItem(BtlServerFlow *handler, BattleHandlerUseHeldItemParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon) || param->allowFainted) {
        if (param->checkFullHp && IsMonFullHP(mon)) {
            return FALSE;
        }
        if (ServerControl_UseHeldItem(handler, mon)) {
            return TRUE;
        }
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_ForceUseItem(BtlServerFlow *handler, BattleHandlerForceUseItemParam *param) {
    BattleMon *mon;
    void *temp;
    u32 reserve;
    u32 state;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        temp = ItemEvent_TempAdd(mon, param->item);
        if (temp != NULL) {
            reserve = SCQUE_RESERVE_Pos(handler->queue, 0x42);
            state = PushState(&handler->actionState, 0x3db8);
            ServerEvent_EquipTempItem(handler, mon, param->monIndex2);
            if (BattleHandler_Result(handler) == 2) {
                func_ov167_021b14ec(handler->queue, reserve, 0x42, param->monIndex);
            }
            PopState(&handler->actionState, state, 0x3dbf);
            func_ov167_021c27c4(temp);
            return TRUE;
        }
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_ConsumeItem(BtlServerFlow *handler, BattleHandlerConsumeItemParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (param->skipDisplay == 0) {
        ServerDisplay_UseHeldItem(handler, mon);
        BattleHandler_SetString(handler, &param->string);
    }
    ServerControl_ChangeHeldItem(handler, mon, 0, 1);
    return TRUE;
}

// Function name from swan.
BOOL BattleHandler_SetCounter(BtlServerFlow *handler, BattleHandlerSetCounterParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    ServerControl_SetMonCounter(handler, mon, param->counter, param->value);
    return TRUE;
}

// Function name from swan.
BOOL BattleHandler_QuitBattle(BtlServerFlow *handler, BattleHandlerQuitBattleParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (ServerControl_EscapeSub(handler, mon, TRUE)) {
        handler->unk14 = 5;
        return TRUE;
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_Switch(BtlServerFlow *handler, BattleHandlerSwitchParam *param) {
    BattleMon *mon;
    u8 pos;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!ServerControl_CheckMatchup(handler) && !func_ov167_021abeb4(handler, param->monIndex) && handler->unk14 == 0) {
        BattleHandler_SetString(handler, &param->firstString);
        if (ServerControl_SwitchOut(handler, mon, param->flag)) {
            pos = MonIDToBattlePos(handler->mainModule, handler->pokeCon, param->monIndex);
            RequestChangePokemon(handler->server, pos);
            BattleHandler_SetString(handler, &param->secondString);
            handler->unk14 = 1;
            return TRUE;
        }
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_BatonPass(BtlServerFlow *handler, BattleHandlerBatonPassParam *param) {
    BattleMon *source;
    BattleMon *target;
    u8 substitute;

    source = GetPokeParam(handler->pokeCon, param->sourceMonIndex);
    target = GetPokeParam(handler->pokeCon, param->targetMonIndex);
    if (CheckCondition(source, 16)) {
        ServerEvent_GastroAcidConfirmed(handler, target);
    }
    CopyBatonPassParams(target, source);
    func_ov167_021b1434(handler->queue, 0x26, param->sourceMonIndex, param->targetMonIndex);
    if (IsSubstituteActive(target)) {
        substitute = func_ov167_021add78(handler->unk1ab8, param->targetMonIndex);
        func_ov167_021b1434(handler->queue, 0x51, substitute);
    }
    return TRUE;
}

// Function name from swan.
u8 BattleHandler_Flinch(BtlServerFlow *handler, BattleHandlerFlinchParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (ServerControl_FlinchCore(handler, mon, param->flag)) {
        return TRUE;
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_Revive(BtlServerFlow *handler, BattleHandlerReviveParam *param) {
    BattleMon *mon;
    u8 pos;
    u8 target;
    u8 slot;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    HPAdd(mon, param->amount);
    func_ov167_021b1434(handler->queue, 2, param->monIndex, param->amount);
    handler->unk7A9[param->monIndex] = 0;
    BattleHandler_SetString(handler, &param->string);
    pos = MonIDToBattlePos(handler->mainModule, handler->pokeCon, param->monIndex);
    if (pos != BTL_POS_MAX) {
        target = func_ov167_0219c648(param->monIndex);
        slot = func_ov167_0219c658(handler->mainModule, pos);
        ServerControl_SwitchInFillSlot(handler, target, slot, slot, TRUE);
        ServerControl_AfterSwitchIn(handler);
    }
    return TRUE;
}

// Function name from swan.
BOOL BattleHandler_SetWeight(BtlServerFlow *handler, BattleHandlerSetWeightParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    SetWeight(mon, param->weight);
    func_ov167_021b1434(handler->queue, 0x14, param->monIndex, param->weight);
    BattleHandler_SetString(handler, &param->string);
    return TRUE;
}

// Function names from swan.
BOOL BattleHandler_InterruptAction(BtlServerFlow *handler, BattleHandlerInterruptParam *param) {
    if (ActionOrder_InterruptReserve(handler, param->monId)) {
        BattleHandler_SetString(handler, &param->string);
        return TRUE;
    }
    return FALSE;
}

u8 BattleHandler_InterruptMove(BtlServerFlow *handler, BattleHandlerInterruptParam *param) {
    return ActionOrder_InterruptReserveByMove(handler, param->moveId) != 0;
}

BOOL BattleHandler_SendLast(BtlServerFlow *handler, BattleHandlerInterruptParam *param) {
    if (ActionOrder_SendToLast(handler, param->monId)) {
        BattleHandler_SetString(handler, &param->string);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_SwapPoke(BtlServerFlow *handler, BattleHandlerSwapPokeParam *param) {
    u8 clientId;
    BattleMon *first;
    BattleMon *second;
    BattleParty *party;
    s16 firstSlot;
    s16 secondSlot;

    if (param->firstMonIndex != param->secondMonIndex) {
        clientId = func_ov167_0219c648(param->firstMonIndex);
        if (clientId == func_ov167_0219c648(param->secondMonIndex)) {
            first = GetPokeParam(handler->pokeCon, param->firstMonIndex);
            second = GetPokeParam(handler->pokeCon, param->secondMonIndex);
            if (!IsFainted(first) && !IsFainted(second)) {
                party = GetPartyData(handler->pokeCon, clientId);
                firstSlot = FindPartyMon(party, first);
                secondSlot = FindPartyMon(party, second);
                if (firstSlot >= 0 && secondSlot >= 0) {
                    ServerControl_MoveCore(handler, clientId, firstSlot, secondSlot, 0);
                    BattleHandler_SetString(handler, &param->string);
                    ServerControl_AfterMove(handler, clientId, firstSlot, secondSlot);
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

BOOL BattleHandler_Transform(BtlServerFlow *handler, BattleHandlerTransformParam *param) {
    BattleMon *mon;
    BattleMon *target;
    u16 oldAbility;
    u8 monId;
    u8 targetId;
    u32 state;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    target = GetPokeParam(handler->pokeCon, param->targetIndex);
    if (!IsIllusionEnabled(mon) && !IsIllusionEnabled(target) && !IsSemiInvulnMove(mon)) {
        oldAbility = GetBattleMonStat(mon, 0x10);
        if (TransformSet(mon, target)) {
            monId = GetMonID(mon);
            targetId = GetMonID(target);
            if (param->popup) {
                ServerDisplay_AbilityPopupAdd(handler, mon);
            }
            RemoveForceAll(mon);
            AbilityEvent_RemoveItem(mon);
            AbilityEvent_AddItem(mon);
            func_ov167_021b1434(handler->queue, 0x53, monId, targetId);
            BattleHandler_SetString(handler, &param->string);
            if (param->popup) {
                ServerDisplay_AbilityPopupRemove(handler, mon);
            }
            if (oldAbility != GetBattleMonStat(mon, 0x11)) {
                state = PushState(&handler->actionState, 0x3f37);
                ServerEvent_ChangeAbilityAfter(handler, monId);
                PopState(&handler->actionState, state, 0x3f39);
            }
            return TRUE;
        }
    }
    return FALSE;
}

BOOL BattleHandler_IllusionBreak(BtlServerFlow *handler, BattleHandlerIllusionBreakParam *param) {
    BattleMon *mon;

    if (func_ov167_021ae0fc(handler->unk1ab8, param->monIndex)) {
        mon = GetPokeParam(handler->pokeCon, param->monIndex);
        if (IsIllusionEnabled(mon)) {
            IllusionBreak(mon);
            func_ov167_021b1434(handler->queue, 0x4b, param->monIndex);
            BattleHandler_SetString(handler, &param->string);
            return TRUE;
        }
    }
    return FALSE;
}

BOOL BattleHandler_GravityCheck(BtlServerFlow *handler, BattleHandlerGravityCheckParam *param) {
    u8 monIds[6];
    u8 count;
    u8 i;
    BattleMon *mon;
    u32 changed;
    u16 code;
    u8 pos;

    pos = MonIDToBattlePos(handler->mainModule, handler->pokeCon, param->monIndex);
    code = (2 << 10) | pos;
    count = HandlerGetAlivePartyCount(handler, code, monIds);
    for (i = 0; i < count; i++) {
        mon = GetPokeParam(handler->pokeCon, monIds[i]);
        changed = FALSE;
        if (GetAdditionalConditionFlag(mon, 3)) {
            ServerControl_HideTurnCancel(handler, mon, 3);
            changed = TRUE;
        }
        if (ServerEvent_CheckFloating(handler, mon, 1)) {
            changed = TRUE;
        }
        if (CheckCondition(mon, 0x1e)) {
            ServerControl_CureCondition(handler, mon, 0x1e, 0);
            changed = TRUE;
        }
        if (CheckCondition(mon, 0x20)) {
            ServerControl_CureCondition(handler, mon, 0x20, 0);
            changed = TRUE;
        }
        if (changed) {
            func_ov167_021b15d0(handler->queue, 0x5b, 0x43b, monIds[i], 0xffff0000);
        }
    }
    return TRUE;
}

BOOL BattleHandler_HideTurnCancel(BtlServerFlow *handler, BattleHandlerHideTurnParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon) && ServerControl_HideTurnCancel(handler, mon, param->flag)) {
        BattleHandler_SetString(handler, &param->string);
        return TRUE;
    }
    return FALSE;
}

// Function name from swan.
BOOL BattleHandler_RemoveMessageWindow(BtlServerFlow *handler) {
    func_ov167_021b1434(handler->queue, 0x56, 0);
    return TRUE;
}

// Function name from swan.
BOOL BattleHandler_ChangeForm(BtlServerFlow *handler, BattleHandlerChangeFormParam *param) {
    BattleMon *mon;
    u8 currentForm;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon) && !TransformCheck(mon)) {
        currentForm = GetBattleMonStat(mon, 0x13);
        if (currentForm != param->form) {
            if (param->popup) {
                ServerDisplay_AbilityPopupAdd(handler, mon);
            }
            ChangeForm(mon, param->form);
            func_ov167_021b1434(handler->queue, 0x4f, param->monIndex, param->form);
            BattleHandler_SetString(handler, &param->string);
            if (param->popup) {
                ServerDisplay_AbilityPopupRemove(handler, mon);
            }
            return TRUE;
        }
    }
    return FALSE;
}

BOOL BattleHandler_SetMoveEffectIndex(BtlServerFlow *handler, BattleHandlerMoveEffectParam *param) {
    handler->moveEffect->index = param->index;
    return TRUE;
}

BOOL BattleHandler_SetMoveEffectEnable(BtlServerFlow *handler) {
    if (!handler->moveEffect->enabled) {
        handler->moveEffect->enabled = 1;
    }
    return TRUE;
}

// Function names from swan.
void PopState(BtlActionState *state, u32 value, u32 command) {
    state->raw = value;
}

u16 GetUseItemNo(BtlActionState *state) {
    return state->useItemNo;
}

BOOL IsUsed(BtlActionState *state) {
    return state->used;
}

void SetResult(BtlActionState *state, BOOL result) {
    if (result) {
        state->prevResult = 1;
        state->result = 1;
    } else {
        state->prevResult = 0;
    }
    state->used = 1;
}

BOOL GetPrevResult(BtlActionState *state) {
    return state->prevResult;
}
