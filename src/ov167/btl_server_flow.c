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
#include "battle/btl_move.h"
#include "battle/btl_ov169.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server.h"
#include "battle/btl_server_flow.h"
#include "gfl/arc.h"
#include "gfl/std.h"
#include "pml/personal.h"
#include "pml/poke_party.h"
#include "pml/waza.h"

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
                ServerControl_SwitchInFillSlot(flow, flow->actionOrder[i].clientId,
                                               flow->actionOrder[i].action.change.unk4,
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
            order[i].key =
                ActionOrder_MakeKey(order[i].key & 0x1fff, (order[i].key >> 13) & 7, unk16, (order[i].key >> 22) & 7);
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
            GetClientSide(flow->mainModule, i) ==
                GetClientSide(flow->mainModule, GetPlayerClientID(flow->mainModule)) &&
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

u8 func_ov167_021a00a4(BtlServerFlow *flow, BtlClientActions *clientActions, ActionOrderEntry *order, u8 max) {
    u32 speed;
    BattleMon *mon;
    u32 state;
    u8 clientId;
    u8 j;
    u8 numActions;
    BOOL rotated;
    u8 i;
    u8 count;
    BtlServerClient *client;
    u8 slot;
    ActionOrderEntry *entry;
    u8 kind;
    u8 priority;

    rotated = FALSE;
    count = 0;
    for (clientId = 0; clientId < 4; clientId++) {
        client = func_ov167_0219f260(flow->server, clientId);
        if (client == NULL) {
            continue;
        }
        numActions = func_ov167_0219f2ac(clientActions, clientId);
        slot = 0;
        for (j = 0; j < numActions; j++) {
            entry = &order[count];
            entry->action = func_ov167_0219f2b4(clientActions, clientId, j);
            if (func_ov167_021bdc08(&entry->action)) {
                break;
            }
            switch ((u8)BattleAction_GetAction(&entry->action)) {
            case 6:
                slot = func_ov167_0219d38c((u8)entry->action.change.unk4);
                entry->mon = func_ov167_0219d4e4(client->party, slot);
                rotated = TRUE;
                break;
            case 3:
                entry->mon = func_ov167_0219d4e4(client->party, entry->action.change.unk4);
                slot++;
                break;
            default:
                entry->mon = func_ov167_0219d4e4(client->party, slot);
                slot++;
                break;
            }
            entry->clientId = clientId;
            entry->done = FALSE;
            entry->unk0E[0] = 0;
            count++;
        }
    }
    for (i = 0; i < count; i++) {
        state = PushState(&flow->actionState, 0x64a);
        entry = &order[i];
        mon = order[i].mon;
        switch (entry->action.bits.action) {
        case 4:
            if (BtlSetup_GetBattleType(flow->mainModule) == 0 && entry->clientId == 1) {
                kind = 0;
            } else {
                kind = 4;
            }
            break;
        case 3:
            kind = 3;
            break;
        case 2:
            kind = 2;
            break;
        case 6:
            kind = 1;
            break;
        case 7:
            kind = 0;
            break;
        case 5:
            kind = 0;
            break;
        case 1:
            kind = 0;
            break;
        case 0:
            entry->key = ActionOrder_MakeKey(0, 1, 0, 4);
            continue;
        default:
            kind = 0;
            break;
        case 8:
            continue;
        }
        if (entry->action.bits.action == 1) {
            priority = func_ov167_021a0380(flow, BattleAction_GetMove(&order[i].action), mon);
        } else if (entry->action.bits.action == 5 || entry->action.bits.action == 7) {
            priority = 7;
        } else {
            priority = 0;
        }
        speed = ServerEvent_CalculateSpeed(flow, mon, TRUE);
        PopState(&flow->actionState, state, 0x682);
        entry->key = ActionOrder_MakeKey(speed, 1, priority, kind);
    }
    func_ov167_021a0308(order, count);
    if (!rotated) {
        for (i = 0; i < count; i++) {
            entry = &order[i];
            if (entry->action.bits.action == 1 || entry->action.bits.action == 5) {
                state = PushState(&flow->actionState, 0x694);
                entry->key = (entry->key & 0xffff1fff) | ((func_ov167_021a9e68(flow, entry->mon) & 7) << 13);
                PopState(&flow->actionState, state, 0x697);
            }
        }
        func_ov167_021a0308(order, count);
    }
    return count;
}

void func_ov167_021a0308(ActionOrderEntry *order, u32 count) {
    u32 i;
    u32 j;
    ActionOrderEntry *a;
    ActionOrderEntry *b;
    ActionOrderEntry tmp;

    for (i = 0; i < count; i++) {
        a = &order[i];
        for (j = i + 1; j < count; j++) {
            b = &order[j];
            if (a->key <= b->key && (a->key != b->key || BattleRandom(2) != 0)) {
                tmp = *a;
                *a = *b;
                *b = tmp;
            }
        }
    }
}

u8 func_ov167_021a0380(BtlServerFlow *flow, u16 move, BattleMon *mon) {
    u8 priority;

    priority = PML_MoveGetParam(move, 6) + 7;
    BattleEventVar_Push(0x6d1);
    BattleEventVar_SetConstValue(3, GetMonID(mon));
    BattleEventVar_SetConstValue(0x12, move);
    BattleEventVar_SetValue(0x18, priority);
    BattleEvent_CallHandlers(flow, 0x11);
    priority = BattleEventVar_GetValue(0x18);
    BattleEventVar_Pop(0x6d7);
    return priority;
}

u16 ServerEvent_CalculateSpeed(BtlServerFlow *flow, BattleMon *mon, BOOL flag) {
    u32 speed;

    speed = GetBattleMonStat(mon, 0xc);
    BattleEventVar_Push(0x6ea);
    BattleEventVar_SetConstValue(2, GetMonID(mon));
    BattleEventVar_SetConstValue(0x2f, speed);
    BattleEventVar_SetValue(0x51, 1);
    BattleEventVar_SetValue(0x4a, 0);
    BattleEventVar_SetMulValue(0x35, 0x1000, 0x19a, 0x20000);
    BattleEvent_CallHandlers(flow, 0x13);
    speed = fixed_round(BattleEventVar_GetValue(0x2f), BattleEventVar_GetValue(0x35));
    if (GetBattleMonStatus(mon) == 1 && BattleEventVar_GetValue(0x51)) {
        speed = speed * 25 / 100;
    }
    if (speed > 10000) {
        speed = 10000;
    }
    if (flag && BattleEventVar_GetValue(0x4a)) {
        speed = 10000 - speed;
    }
    BattleEventVar_Pop(0x70a);
    return speed;
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

ActionOrderEntry *func_ov167_021a04e8(BtlServerFlow *flow, ActionOrderEntry *after, u8 monId) {
    u32 i;

    for (i = 0; i < flow->actionOrderCount; i++) {
        if (&flow->actionOrder[i] == after) {
            i++;
            break;
        }
    }
    for (; i < flow->actionOrderCount; i++) {
        if (monId == GetMonID(flow->actionOrder[i].mon)) {
            return &flow->actionOrder[i];
        }
    }
    return NULL;
}

ActionOrderEntry *ActionOrder_SearchByMoveID(BtlServerFlow *flow, u16 moveId, u8 start) {
    u32 i;

    for (i = start; i < flow->actionOrderCount; i++) {
        if (!flow->actionOrder[i].done && BattleAction_GetAction(&flow->actionOrder[i].action) == 1 &&
            moveId == func_ov167_021bdb68(&flow->actionOrder[i].action)) {
            return &flow->actionOrder[i];
        }
    }
    return NULL;
}

ActionOrderEntry *func_ov167_021a05ac(BtlServerFlow *flow, u16 move, u8 monId, u8 target) {
    ActionOrderEntry *entry;

    entry = ActionOrder_SearchByMoveID(flow, move, 0);
    while (entry != NULL) {
        if (IsAllyMonID(monId, GetMonID(entry->mon)) && !IsFainted(entry->mon)) {
            return entry;
        }
        entry = ActionOrder_SearchByMoveID(flow, move, func_ov167_021a0600(flow, entry) + 1);
    }
    return NULL;
}

u8 func_ov167_021a0600(BtlServerFlow *flow, ActionOrderEntry *entry) {
    s32 i;

    for (i = 0; i < flow->actionOrderCount; i++) {
        if (&flow->actionOrder[i] == entry) {
            return i;
        }
    }
    return flow->actionOrderCount;
}

s32 ActionOrderTool_Interrupt(BtlServerFlow *flow, ActionOrderEntry *entry, s32 start) {
    s32 from;
    s32 to;
    s32 i;
    u8 count;

    from = -1;
    to = -1;
    count = flow->actionOrderCount;
    for (i = start; i < count; i++) {
        if (&flow->actionOrder[i] == entry) {
            from = i;
            break;
        }
    }
    for (; start < count; start++) {
        if (!flow->actionOrder[start].done) {
            to = start;
            break;
        }
    }
    if (from >= 0 && to >= 0 && from > to) {
        flow->tempEntry = *entry;
        for (; from > to; from--) {
            flow->actionOrder[from] = flow->actionOrder[from - 1];
        }
        flow->actionOrder[to] = flow->tempEntry;
        return to;
    }
    return -1;
}

void ActionOrderTool_SendToLast(BtlServerFlow *flow, ActionOrderEntry *entry) {
    s32 from;
    s32 i;

    from = -1;
    for (i = 0; i < flow->actionOrderCount; i++) {
        if (&flow->actionOrder[i] == entry) {
            from = i;
            break;
        }
    }
    if (from >= 0) {
        flow->tempEntry = *entry;
        for (; from < flow->actionOrderCount - 1; from++) {
            flow->actionOrder[from] = flow->actionOrder[from + 1];
        }
        flow->actionOrder[from] = flow->tempEntry;
    }
}

u32 func_ov167_021a0778(BtlServerFlow *flow, ActionOrderEntry *entry) {
    BattleMon *mon;
    BattleAction action;
    u32 state;

    if (!entry->done) {
        mon = entry->mon;
        action = entry->action;
        func_ov167_021ac0dc(flow);
        entry->done = TRUE;
        if ((flow->unk14 != 5 || action.bits.action == 4) && !IsFainted(mon) &&
            (action.bits.action == 6 || DoesBattleMonExist(flow->unk1ab8, GetMonID(mon)))) {
            if (CheckCondition(mon, 0x21) && (action.bits.action != 4 || GetRunMode(flow->mainModule) != 2)) {
                if (GetConditionCount(mon, 3)) {
                    ServerControl_SetMonCounter(flow, mon, 3, 0);
                }
            } else {
                func_ov167_021a0994(flow, mon, entry->action.bits.action);
                func_ov167_021bb7c0(mon, 0);
                switch (action.bits.action) {
                case 6:
                    if (BtlSetup_GetBattleStyle(flow->mainModule) == 3) {
                        func_ov167_0219feac(flow, entry->clientId, action.change.unk4);
                    }
                    break;
                case 1:
                    if (!flow->unk1FEC[0]) {
                        func_ov167_0219fffc(flow);
                        flow->unk1FEC[0] = TRUE;
                    }
                    flow->unk1F7C = func_ov167_021a0a44(flow, mon);
                    func_ov167_021a1940(flow, mon, &action, entry->key & 0x3fffff);
                    break;
                case 2:
                    if (func_ov167_021af2ac(flow, mon, action.item.item, action.item.param, action.item.target) == 1 &&
                        func_ov167_021a11b0(flow, mon, TRUE, TRUE)) {
                        flow->unk14 = 5;
                    }
                    break;
                case 3:
                    func_ov167_021a1740(flow, mon, action.change.slot);
                    ServerControl_AfterSwitchIn(flow);
                    break;
                case 4:
                    if (ServerControl_Escape(flow, mon)) {
                        flow->unk14 = 5;
                    }
                    break;
                case 8:
                    flow->unk14 = 4;
                    break;
                case 5:
                    func_ov167_021a0e90(flow, mon);
                    break;
                case 7:
                    func_ov167_021a8fd4(flow, mon);
                    break;
                }
                if (action.bits.action == 1 || action.bits.action == 2) {
                    func_ov167_021bb7c0(mon, 1);
                    scPut_SetContFlag(flow, mon, 0);
                }
                state = PushState(&flow->actionState, 0x845);
                func_ov167_021a0a08(flow, mon, action.bits.action);
                PopState(&flow->actionState, state, 0x847);
            }
        }
        func_ov167_021ac0f8(flow);
        return action.bits.action;
    }
    return 0;
}

void func_ov167_021a0994(BtlServerFlow *flow, BattleMon *mon, u32 action) {
    u32 state;

    state = PushState(&flow->actionState, 0x85e);
    func_ov167_021a09cc(flow, mon, action);
    PopState(&flow->actionState, state, 0x861);
}

void func_ov167_021a09cc(BtlServerFlow *flow, BattleMon *mon, u32 action) {
    BattleEventVar_Push(0x86e);
    BattleEventVar_SetConstValue(2, GetMonID(mon));
    BattleEventVar_SetConstValue(0xc, action);
    BattleEvent_CallHandlers(flow, 1);
    BattleEventVar_Pop(0x872);
}

void func_ov167_021a0a08(BtlServerFlow *flow, BattleMon *mon, u32 action) {
    BattleEventVar_Push(0x87e);
    BattleEventVar_SetConstValue(2, GetMonID(mon));
    BattleEventVar_SetConstValue(0xc, action);
    BattleEvent_CallHandlers(flow, 2);
    BattleEventVar_Pop(0x882);
}

u32 func_ov167_021a0a44(BtlServerFlow *flow, BattleMon *mon) {
    void *src;
    PlayerInfo *player;
    u32 badges;
    u16 level;
    u16 maxLevel;
    u16 rand;

    if (BtlSetup_GetBattleType(flow->mainModule) <= 1 &&
        func_ov167_0219c648(GetMonID(mon)) == GetPlayerClientID(flow->mainModule)) {
        src = GetSrcData(mon);
        player = func_ov167_0219bf68(flow->mainModule);
        if (func_ov167_0219c988(flow->mainModule) != 0) {
            return 0;
        }
        if (!IsTrainerOT(src, player)) {
            badges = func_ov167_0219bd98(flow->mainModule);
            if (badges < 8) {
                level = GetBattleMonStat(mon, 0xf);
                maxLevel = (badges + 1) * 10;
                if (level <= maxLevel) {
                    return 0;
                }
                if ((u16)BattleRandom(level + maxLevel + 1) < maxLevel) {
                    return 0;
                }
                if (CheckCondition(mon, 2)) {
                    return 4;
                }
                rand = BattleRandom(256);
                if (rand < level - maxLevel && !func_ov167_021a0b28(flow, mon)) {
                    return 2;
                }
                if ((u16)(rand - (u16)(level - maxLevel)) < level - maxLevel) {
                    return 3;
                }
                return 4;
            }
        }
    }
    return 0;
}

BOOL func_ov167_021a0b28(BtlServerFlow *flow, BattleMon *mon) {
    BOOL result;

    BattleEventVar_Push(0x8e0);
    BattleEventVar_SetConstValue(2, GetMonID(mon));
    BattleEventVar_SetRewriteOnceValue(0x41, 0);
    BattleEvent_CallHandlers(flow, 0xe);
    result = BattleEventVar_GetValue(0x41);
    BattleEventVar_Pop(0x8e5);
    return result;
}

BOOL ActionOrder_InterruptProc(BtlServerFlow *flow, u8 monId, u8 targetId) {
    ActionOrderEntry *entry;

    entry = ActionOrder_SearchByMonID(flow, monId);
    if (entry != NULL) {
        if (entry->done && BattleAction_GetAction(&entry->action) == 6) {
            entry = func_ov167_021a04e8(flow, entry, monId);
        }
        if (!entry->done) {
            if (func_ov167_021a18f0(entry->mon, &entry->action)) {
                return FALSE;
            }
            if (BattleAction_GetAction(&entry->action) == 6) {
                return FALSE;
            }
            BattleAction_ChangeFightTargetPos(&entry->action, GetBattlePos(flow->unk1ab8, targetId));
            func_ov167_021a0778(flow, entry);
            return TRUE;
        }
    }
    return FALSE;
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

void func_ov167_021a0c88(BattleMoveEffectState *targets) {
    targets->unk00 = 0;
    targets->pos1 = 6;
    targets->pos2 = 6;
    targets->index = 0;
    targets->enabled = FALSE;
    targets->unk05_1 = 0;
}

void func_ov167_021a0ca8(BattleMoveEffectState *targets, BtlServerFlow *flow, BattleMon *mon, void *monSet) {
    u32 count;

    count = func_ov169_0689cec8(monSet);
    targets->pos1 = GetBattlePos(flow->unk1ab8, GetMonID(mon));
    targets->pos2 = 6;
    targets->enabled = FALSE;
    targets->unk05_1 = 0;
    if (count == 1 && func_ov169_0689cec0(monSet)) {
        targets->pos2 = GetBattlePos(flow->unk1ab8, GetMonID(func_ov169_0689cdf8(monSet, 0)));
    }
}

void func_ov167_021a0d5c(BtlFlowMonIter *iter, BtlServerFlow *flow) {
    u8 clientId;
    BtlServerClient *client;
    u8 i;

    clientId = 0;
    iter->clientId = 0;
    iter->index = clientId;
    iter->done = TRUE;
    iter->rotation = clientId;
    for (; clientId < 4; clientId++) {
        client = func_ov167_0219f27c(flow->server, clientId);
        if (client != NULL) {
            for (i = 0; i < client->numCoverPos; i++) {
                if (BtlFlow_IsMonAlive(GetBattleMonFromParty(client->party, i))) {
                    iter->clientId = clientId;
                    iter->done = FALSE;
                    iter->index = i;
                    return;
                }
            }
        }
    }
}

void func_ov167_021a0de0(BtlFlowMonIter *iter, BtlServerFlow *flow) {
    if (BtlSetup_GetBattleStyle(flow->mainModule) == 3) {
        iter->rotation = TRUE;
    }
}

BOOL func_ov167_021a0df4(BtlFlowMonIter *iter, BtlServerFlow *flow, BattleMon **mon) {
    BtlServerClient *client;
    u8 count;

    if (iter->done) {
        return FALSE;
    }
    *mon = func_ov167_0219d4e4(func_ov167_0219f260(flow->server, iter->clientId)->party, iter->index);
    iter->index++;
    while (iter->clientId < 4) {
        client = func_ov167_0219f27c(flow->server, iter->clientId);
        if (client != NULL) {
            count = !iter->rotation ? client->numCoverPos : 3;
            for (; iter->index < count; iter->index++) {
                if (BtlFlow_IsMonAlive(func_ov167_0219d4e4(client->party, iter->index))) {
                    return TRUE;
                }
            }
        }
        iter->clientId++;
        iter->index = 0;
    }
    iter->done = TRUE;
    return TRUE;
}

void func_ov167_021a0e90(BtlServerFlow *flow, BattleMon *mon) {
    u8 clientId;
    s32 slot;

    clientId = func_ov167_0219c648(GetMonID(mon));
    slot = FindPartyMon(GetPartyData(flow->pokeCon, clientId), mon);
    if (slot == 0 || slot == 2) {
        ServerControl_MoveCore(flow, clientId, slot, 1, 0);
        ServerDisplay_SkyDropTargetAppear(flow, mon, 0xe7);
        ServerControl_AfterMove(flow, clientId, slot, 1);
    }
}

void ServerControl_MoveCore(BtlServerFlow *handler, u8 clientId, u8 firstSlot, u8 secondSlot, u32 flag) {
    BattleParty *party;
    u8 firstPos;
    u8 secondPos;
    BattleMon *first;
    BattleMon *second;

    party = GetPartyData(handler->pokeCon, clientId);
    firstPos = func_ov167_0219c458(handler->mainModule, clientId, firstSlot);
    secondPos = func_ov167_0219c458(handler->mainModule, clientId, secondSlot);
    func_ov169_0689d678(handler->unk1ab8, firstPos, secondPos);
    func_ov167_0219d504(party, firstSlot, secondSlot);
    if (!flag) {
        func_ov167_021b1434(handler->queue, 0x44, clientId, firstPos, secondPos);
        first = func_ov167_0219d4e4(party, firstSlot);
        second = func_ov167_0219d4e4(party, secondSlot);
        if (!IsFainted(first)) {
            func_ov167_021bb7c0(first, 0xc);
        }
        if (!IsFainted(second)) {
            func_ov167_021bb7c0(second, 0xc);
        }
    }
}

void ServerControl_AfterMove(BtlServerFlow *handler, u8 clientId, u8 firstSlot, u8 secondSlot) {
    BattleParty *party;
    BattleMon *first;
    BattleMon *second;

    party = GetPartyData(handler->pokeCon, clientId);
    first = GetBattleMonFromParty(party, firstSlot);
    second = GetBattleMonFromParty(party, secondSlot);
    ServerControl_AfterMoveCore(handler, first);
    ServerControl_AfterMoveCore(handler, second);
}

void ServerControl_AfterMoveCore(BtlServerFlow *flow, BattleMon *mon) {
    u32 state;

    if (!IsFainted(mon)) {
        state = PushState(&flow->actionState, 0xa99);
        func_ov167_021a0ffc(flow, mon);
        PopState(&flow->actionState, state, 0xa9b);
    }
}

void func_ov167_021a0ffc(BtlServerFlow *flow, BattleMon *mon) {
    BattleEventVar_Push(0xaa8);
    BattleEventVar_SetValue(2, GetMonID(mon));
    BattleEvent_CallHandlers(flow, 0xa4);
    BattleEventVar_Pop(0xaab);
}

BOOL ServerControl_Escape(BtlServerFlow *flow, BattleMon *mon) {
    u8 clientId;
    u8 playerClientId;
    BOOL result;

    clientId = func_ov167_0219c648(GetMonID(mon));
    playerClientId = GetPlayerClientID(flow->mainModule);
    result = ServerControl_EscapeSub(flow, mon, FALSE);
    if (result) {
        return TRUE;
    }
    if (clientId == playerClientId) {
        func_ov167_0219dad0(flow->mainModule, 0x4e);
        func_ov167_021b15d0(flow->queue, 0x5a, 0x49, 0xffff0000);
    } else {
        func_ov167_021b15d0(flow->queue, 0x5b, 0x36b, GetMonID(mon), 0xffff0000);
    }
    if (clientId == playerClientId) {
        flow->unk786++;
        if (flow->unk786 > 30) {
            flow->unk786 = 30;
        }
    }
    return result;
}

BOOL ServerControl_EscapeSub(BtlServerFlow *handler, BattleMon *mon, u32 flag) {
    BOOL result;
    BattleMon *enemy;
    u16 speed;
    u16 enemySpeed;
    u32 chance;

    result = FALSE;
    if (GetRunMode(handler->mainModule) == 0) {
        if (func_ov167_0219c648(GetMonID(mon)) == GetPlayerClientID(handler->mainModule)) {
            result = func_ov167_021a1160(handler, mon);
            if (result) {
                flag = TRUE;
            }
        } else {
            flag = TRUE;
        }
    } else {
        flag = TRUE;
        result = TRUE;
    }
    if (!flag) {
        enemy = GetClientMonData(handler->pokeCon, 1, 0);
        if (enemy != NULL) {
            speed = RawBattleMonStat(mon, 0xc);
            enemySpeed = RawBattleMonStat(enemy, 0xc);
            if (speed <= enemySpeed) {
                chance = (speed << 12) / enemySpeed * 128 >> 12;
                chance += handler->unk786 * 30;
                if (BattleRandom(256) >= chance) {
                    return FALSE;
                }
            }
        }
    }
    return func_ov167_021a11b0(handler, mon, result, FALSE);
}

BOOL func_ov167_021a1160(BtlServerFlow *flow, BattleMon *mon) {
    BOOL result;

    if (!IsFainted(mon)) {
        BattleEventVar_Push(0xb31);
        BattleEventVar_SetConstValue(2, GetMonID(mon));
        BattleEventVar_SetRewriteOnceValue(0x51, 0);
        BattleEvent_CallHandlers(flow, 0xb);
        result = BattleEventVar_GetValue(0x51);
        BattleEventVar_Pop(0xb36);
        return result;
    }
    return FALSE;
}

BOOL func_ov167_021a11b0(BtlServerFlow *flow, BattleMon *mon, BOOL arg2, BOOL arg3) {
    u8 clientId;
    u8 isEnemy;
    BOOL result;
    u32 state;
    u32 state2;

    clientId = func_ov167_0219c648(GetMonID(mon));
    if (GetRunMode(flow->mainModule) == 0) {
        isEnemy = !IsAllyClientID(clientId, GetPlayerClientID(flow->mainModule)) ? TRUE : FALSE;
        if (!arg2 && !IsFainted(mon)) {
            state = PushState(&flow->actionState, 0xb58);
            result = func_ov167_021a12f8(flow, mon);
            PopState(&flow->actionState, state, 0xb5a);
            if (result) {
                return FALSE;
            }
        }
        if (!flow->unk78A_2) {
            if (!arg3) {
                state2 = PushState(&flow->actionState, 0xb68);
                result = func_ov167_021a1354(flow, mon);
                PopState(&flow->actionState, state2, 0xb6a);
            } else {
                result = FALSE;
            }
            if (!result) {
                if (isEnemy) {
                    if (BtlSetup_GetBattleType(flow->mainModule) == 0) {
                        func_ov167_021b15d0(flow->queue, 0x5c, 0x4b, 0x56a, GetMonID(mon), 0xffff0000);
                    }
                } else {
                    func_ov167_021b15d0(flow->queue, 0x5c, 0x48, 0x56a, 0xffff0000);
                }
            }
            flow->unk78A_2 = TRUE;
        }
    } else if (func_ov167_0219bee4(flow->mainModule) && !flow->unk78A_2) {
        func_ov167_021b15d0(flow->queue, 0x5a, 0xc6, 0xffff0000);
        flow->unk78A_2 = TRUE;
    }
    func_ov167_021bda6c(&flow->clientIdList, clientId);
    return TRUE;
}

BOOL func_ov167_021a12f8(BtlServerFlow *flow, BattleMon *mon) {
    BOOL result;

    BattleEventVar_Push(0xb9d);
    BattleEventVar_SetConstValue(2, GetMonID(mon));
    BattleEventVar_SetRewriteOnceValue(0x41, 0);
    func_ov169_0689c814(flow, mon);
    BattleEvent_CallHandlers(flow, 0xc);
    result = BattleEventVar_GetValue(0x41);
    BattleEventVar_Pop(0xba3);
    return result;
}

BOOL func_ov167_021a1354(BtlServerFlow *flow, BattleMon *mon) {
    BOOL result;

    BattleEventVar_Push(0xbb3);
    BattleEventVar_SetValue(2, GetMonID(mon));
    BattleEventVar_SetRewriteOnceValue(0x51, 0);
    BattleEvent_CallHandlers(flow, 0xd);
    result = BattleEventVar_GetValue(0x51);
    BattleEventVar_Pop(0xbb8);
    return result;
}

void ServerControl_SwitchInCore(BtlServerFlow *flow, u8 clientId, u8 pos, u8 slot) {
    BattleParty *party;
    BattleMon *mon;
    u8 monId;

    party = GetPartyData(flow->pokeCon, clientId);
    func_ov167_021b1434(flow->queue, 0x2a, clientId);
    func_ov167_0219d604(flow->mainModule, party, clientId);
    if (pos != slot) {
        func_ov167_0219d504(party, pos, slot);
    }
    mon = func_ov167_0219d4e4(party, pos);
    monId = GetMonID(mon);
    func_ov167_0219bfa0(flow->mainModule, clientId, mon);
    AbilityEvent_AddItem(mon);
    ItemEvent_AddItem(mon);
    func_ov167_021bbbec(mon, flow->unk10);
    func_ov167_021bbd80(mon);
    flow->unk7C1[monId] = TRUE;
    if (BtlSetup_GetBattleStyle(flow->mainModule) == 3 && GetClientBattlerCount(flow->mainModule, clientId) <= pos) {
        flow->unk7C1[monId] = FALSE;
    }
    func_ov167_021b1434(flow->queue, 0x12, clientId, pos, slot, (u16)flow->unk10);
    func_ov169_0689d4a8(flow->unk1ab8, func_ov167_0219c458(flow->mainModule, clientId, pos), monId, flow->pokeCon);
}

void ServerControl_SwitchInFillSlot(BtlServerFlow *handler, u8 target, u8 slot, u8 slotAgain, BOOL flag) {
    ServerControl_SwitchInCore(handler, target, slot, slotAgain);
    func_ov167_021b1434(handler->queue, 0x3d, target, slot, slotAgain, (u8)flag);
}

BOOL ServerControl_AfterSwitchIn(BtlServerFlow *handler) {
    BOOL result;
    BtlFlowMonIter iter;
    BattleMon *mon;
    u8 monId;
    void *monSet;
    u32 state;

    result = FALSE;
    monSet = handler->unk1A68;
    func_ov169_0689ccc4(monSet);
    func_ov167_021a0d5c(&iter, handler);
    while (func_ov167_021a0df4(&iter, handler, &mon)) {
        monId = GetMonID(mon);
        if (handler->unk7C1[monId]) {
            func_ov169_0689ccd0(monSet, mon);
            handler->unk7C1[monId] = FALSE;
        }
    }
    SortBySpeed(monSet, handler);
    state = PushState(&handler->actionState, 0xc28);
    func_ov167_021a1694(handler);
    if (BattleHandler_Result(handler)) {
        result = TRUE;
    }
    PopState(&handler->actionState, state, 0xc2e);
    func_ov169_0689ce0c(monSet);
    while ((mon = func_ov169_0689ce14(monSet)) != NULL) {
        state = PushState(&handler->actionState, 0xc34);
        func_ov167_021a1630(handler, mon);
        if (BattleHandler_Result(handler)) {
            result = TRUE;
        }
        PopState(&handler->actionState, state, 0xc3a);
    }
    state = PushState(&handler->actionState, 0xc3d);
    func_ov167_021a16b4(handler);
    if (BattleHandler_Result(handler)) {
        result = TRUE;
    }
    PopState(&handler->actionState, state, 0xc43);
    return result;
}

void func_ov167_021a1630(BtlServerFlow *flow, BattleMon *mon) {
    BattleEventVar_Push(0xc53);
    BattleEventVar_SetConstValue(2, GetMonID(mon));
    BattleEvent_CallHandlers(flow, 0x55);
    BattleEventVar_Pop(0xc56);
}

void func_ov167_021a1660(BtlServerFlow *flow, BattleMon *mon) {
    BattleEventVar_Push(0xc65);
    BattleEventVar_SetConstValue(2, GetMonID(mon));
    func_ov167_021bc90c(flow, 0x55, 4);
    BattleEventVar_Pop(0xc68);
}

void func_ov167_021a1694(BtlServerFlow *flow) {
    BattleEventVar_Push(0xc75);
    BattleEvent_CallHandlers(flow, 0x56);
    BattleEventVar_Pop(0xc77);
}

void func_ov167_021a16b4(BtlServerFlow *flow) {
    BattleEventVar_Push(0xc83);
    BattleEvent_CallHandlers(flow, 0x57);
    BattleEventVar_Pop(0xc85);
}

void func_ov167_021a16d4(BtlServerFlow *flow) {
    u32 state;

    state = PushState(&flow->actionState, 0xc92);
    func_ov167_021a1700(flow);
    PopState(&flow->actionState, state, 0xc94);
}

void func_ov167_021a1700(BtlServerFlow *flow) {
    BattleEventVar_Push(0xca1);
    BattleEvent_CallHandlers(flow, 0x58);
    BattleEventVar_Pop(0xca3);
}

void func_ov167_021a1720(BtlServerFlow *flow, BattleMon *mon) {
    u8 monId;

    monId = GetMonID(mon);
    func_ov167_021b1434(flow->queue, 0x3b, func_ov167_0219c648(monId), monId);
}

void func_ov167_021a1740(BtlServerFlow *flow, BattleMon *mon, u8 slot) {
    u8 clientId;
    u8 index;

    func_ov167_021a1720(flow, mon);
    if (ServerControl_SwitchOut(flow, mon, FALSE)) {
        func_ov167_0219c694(flow->mainModule, MonIDToBattlePos(flow->mainModule, flow->pokeCon, GetMonID(mon)),
                            &clientId, &index);
        if (flow->unk7D9[clientId] < 0xff) {
            flow->unk7D9[clientId]++;
        }
        ServerControl_SwitchInFillSlot(flow, clientId, index, slot, TRUE);
    }
}

BOOL ServerControl_SwitchOut(BtlServerFlow *handler, BattleMon *mon, u8 flag) {
    u32 count;
    u32 i;

    if (!flag) {
        count = ServerEvent_InterruptSwitch(handler, mon);
        if (count != 0) {
            handler->unk78A_0 = TRUE;
            for (i = 0; i < count; i++) {
                ActionOrder_InterruptProc(handler, handler->unk78B[i], GetMonID(mon));
                if (IsFainted(mon)) {
                    break;
                }
            }
            handler->unk78A_0 = FALSE;
        }
    }
    if (!IsFainted(mon)) {
        ServerControl_SwitchOutCore(handler, mon, 0x26c);
        return TRUE;
    }
    return FALSE;
}

void ServerControl_SwitchOutCore(BtlServerFlow *flow, BattleMon *mon, u32 effect) {
    u8 monId;
    u8 pos;
    u32 state;

    monId = GetMonID(mon);
    pos = MonIDToBattlePos(flow->mainModule, flow->pokeCon, monId);
    if (pos != 6) {
        func_ov167_021b1434(flow->queue, 0x3c, pos, effect);
    }
    ActionOrder_ForceDone(flow, monId);
    state = PushState(&flow->actionState, 0xd0f);
    ServerControl_SwitchOutConfirm(flow, mon);
    PopState(&flow->actionState, state, 0xd11);
    ServerControl_ClearMonDependentEffects(flow, mon, FALSE);
    Clear_ForSwitch(mon);
    func_ov167_021b1434(flow->queue, 0x20, GetMonID(mon));
    func_ov169_0689d480(flow->unk1ab8, monId);
}

void ServerControl_SwitchOutConfirm(BtlServerFlow *flow, BattleMon *mon) {
    BattleEventVar_Push(0xd24);
    BattleEventVar_SetConstValue(2, GetMonID(mon));
    BattleEvent_CallHandlers(flow, 0x54);
    BattleEventVar_Pop(0xd27);
}

u16 func_ov167_021a18f0(BattleMon *mon, BattleAction *action) {
    u16 move;

    if (CheckCondition(mon, 0x17) && action->bits.move != 0xa5) {
        move = Condition_GetParam(GetConditionContinuationParam(mon, 0x17));
        if (move != action->bits.move && func_ov167_021bada0(mon, move)) {
            return move;
        }
    }
    return 0;
}

void func_ov167_021a1940(BtlServerFlow *flow, BattleMon *mon, BattleAction *action, u32 key) {
    BtlFlowFightWork work;
    u8 target;
    u32 prevStatus;
    u8 cond19;
    u8 cond1a;
    u8 hasDelegate;
    BOOL usedMove;
    u8 moveSlot;
    u8 targetCount;
    u16 move;
    u16 actualMove;
    u16 encoreMove;

    prevStatus = func_ov167_021bb408(mon);
    func_ov167_021a0c88(flow->moveEffect);
    func_ov167_021a1fc0(flow->unk4B0);
    work.move = 0;
    work.target = 6;
    encoreMove = func_ov167_021a18f0(mon, action);
    if (encoreMove) {
        BattleAction_SetFightParam(action, encoreMove,
                                   func_ov167_021bd8e4(flow->mainModule, flow->pokeCon, mon, encoreMove));
    }
    move = action->bits.move;
    moveSlot = func_ov167_021baf78(mon, move);
    actualMove = move;
    target = action->bits.target;
    usedMove = FALSE;
    work.result = 0;
    cond19 = CheckCondition(mon, 0x19);
    cond1a = CheckCondition(mon, 0x1a);
    MoveEvent_AddItem(mon, move, key);
    func_ov167_021a23cc(flow, mon, move);
    do {
        if (func_ov167_021a3ac0(flow, mon, move, cond19 || cond1a)) {
            break;
        }
        if (!func_ov167_021a9df0(flow, mon, move, target, &work.move)) {
            func_ov167_021a911c(flow, mon, move);
            ServerEvent_GetMoveParam(flow, move, mon, flow->unk1AB4);
            func_ov167_021ae32c(flow, mon, target, flow->unk1AB4, flow->unk850);
            func_ov167_021a4250(flow, mon, move, moveSlot, flow->unk850);
            usedMove = TRUE;
            func_ov167_021a3ef4(flow, mon, move, 0x1a);
            break;
        }
        hasDelegate = work.move != 0 ? TRUE : FALSE;
        if (hasDelegate) {
            func_ov167_021a911c(flow, mon, move);
            func_ov167_021a2680(flow, mon, move, target);
            MoveEvent_AddItem(mon, work.move, key);
            actualMove = work.move;
            target = work.target;
        } else {
            actualMove = move;
        }
        ServerEvent_GetMoveParam(flow, move, mon, flow->unk1AB4);
        if (hasDelegate) {
            ServerEvent_GetMoveParam(flow, actualMove, mon, flow->unk1AB0);
            flow->unk1AB0->flags.raw |= 4;
            flow->unk1AB0->originalMove = move;
            if (func_ov167_021a1e50(flow, mon, flow->unk1AB0)) {
                func_ov167_021a4250(flow, mon, move, moveSlot, flow->unk850);
                usedMove = TRUE;
                break;
            }
        } else {
            *flow->unk1AB0 = *flow->unk1AB4;
        }
        func_ov169_0689ccc4(flow->unk850);
        func_ov169_0689ccc4(flow->unk854);
        func_ov167_021ae32c(flow, mon, target, flow->unk1AB0, flow->unk850);
        targetCount = func_ov169_0689cec8(flow->unk850);
        func_ov169_0689d06c(flow->unk850);
        func_ov169_0689cf00(flow->unk850, flow->unk854);
        func_ov169_0689ced0(flow->unk854, targetCount);
        if (!cond19 && !cond1a && moveSlot != 4) {
            func_ov167_021a4250(flow, mon, move, moveSlot, flow->unk850);
            usedMove = TRUE;
        }
        func_ov167_021a2114(flow, mon, flow->unk1AB4, 0x22);
        func_ov167_021a20c8(flow, mon, flow->unk1AB0);
        if (func_ov167_021a9f70(flow, mon, move, actualMove, &flow->message)) {
            BattleHandler_SetString(flow, &flow->message);
            BattleHandler_StrClear(&flow->message);
        } else {
            func_ov167_021a911c(flow, mon, actualMove);
        }
        flow->unk1F78 = actualMove;
        if (CheckCondition(mon, 0x22)) {
            ServerControl_CureCondition(flow, mon, 0x22, 0);
            func_ov167_021bb7c0(mon, 0xe);
        }
        if (func_ov167_021a3cf0(flow, mon, actualMove)) {
            break;
        }
        if (func_ov167_021a228c(flow, mon, actualMove, target, &work)) {
            break;
        }
        if (func_ov167_021a2194(flow, mon, actualMove, target)) {
            break;
        }
        func_ov169_0689d1a4(flow->unk1C, actualMove, flow->unk10, GetMonID(mon));
        func_ov167_021a2114(flow, mon, flow->unk1AB0, 0x23);
        if (func_ov167_021a255c(flow, mon, actualMove, flow->unk854, flow->unk4AC)) {
            func_ov167_021a1ff8(flow, mon, actualMove, flow->unk854);
        } else {
            work.result = func_ov167_021a2700(flow, mon, actualMove, flow->unk854);
        }
    } while (0);
    func_ov167_021bb7c0(mon, 3);
    if (usedMove || cond19 || actualMove == 0xa5) {
        func_ov167_021bbf44(mon, target, work.result, flow->unk1AB0->type, actualMove, move);
        BtlServerCmd_Put18(flow->queue, GetMonID(mon), target, work.result, flow->unk1AB0->type, actualMove, move);
    } else if (GetConditionCount(mon, 3)) {
        ServerControl_SetMonCounter(flow, mon, 3, 0);
    }
    if (prevStatus != 0x10 && func_ov167_021bb408(mon) != 0x10) {
        func_ov167_021a3904(flow, mon);
    }
    if (GetTurnFlag(mon, 0xb)) {
        func_ov167_021b1434(flow->queue, 0x31, GetMonID(mon), 0);
        ServerControl_SkyDropCheckRelease(flow, mon, FALSE);
    }
    func_ov167_021a243c(flow, mon, actualMove, work.result);
    if (work.move) {
        func_ov167_021c5bbc(mon, work.move);
    }
    func_ov167_021c5bbc(mon, move);
    func_ov167_021a1ea8(flow, actualMove);
}

BOOL func_ov167_021a1e50(BtlServerFlow *flow, BattleMon *mon, BtlFlowMoveParam *param) {
    u16 move;
    u32 condition;

    move = param->move;
    condition = 0;
    if (CheckCondition(mon, 0xf) && getMoveFlag(move, 0xc)) {
        condition = 0xd;
    } else if (IsFieldEffectActive(2) && getMoveFlag(move, 9)) {
        condition = 0x14;
    }
    if (condition != 0) {
        func_ov167_021a3ef4(flow, mon, move, condition);
        return TRUE;
    }
    return FALSE;
}

void func_ov167_021a1ea8(BtlServerFlow *flow, u16 move) {
    u32 i;
    BattleMon *mon;
    BattleMon *target;
    u32 state;

    for (i = 0; i < flow->unk4B0->count; i++) {
        mon = GetPokeParam(flow->pokeCon, flow->unk4B0->monIds[i]);
        target = GetPokeParam(flow->pokeCon, flow->unk4B0->unk0D[i]);
        if (CanPokemonBattle(mon)) {
            state = PushState(&flow->actionState, 0xe59);
            func_ov167_021a2508(flow, mon, target, move);
            PopState(&flow->actionState, state, 0xe5b);
            ServerEvent_GetMoveParam(flow, move, mon, flow->unk1AB0);
            flow->unk1AB0->flags.unk0 = TRUE;
            func_ov167_021ae32c(flow, mon, flow->unk4B0->targets[i], flow->unk1AB0, flow->unk864);
            func_ov167_021bcba4(GetMonID(mon));
            MoveEvent_AddItem(mon, move, GetBattleMonStat(mon, 0xc));
            func_ov167_021a2700(flow, mon, move, flow->unk864);
            RemoveForce(mon, move);
            func_ov167_021bcbe4(GetMonID(mon));
        }
    }
}

void func_ov167_021a1fc0(BtlFlowReactionList *list) {
    u32 i;

    list->count = 0;
    for (i = 0; i < 6; i++) {
        list->monIds[i] = 0x1f;
    }
}

void func_ov167_021a1fd4(BtlFlowReactionList *list, u8 monId, u8 arg2, u8 target) {
    if (list->count < 6) {
        list->monIds[list->count] = monId;
        list->unk0D[list->count] = arg2;
        list->targets[list->count] = target;
        list->count++;
    }
}

void func_ov167_021a1ff8(BtlServerFlow *flow, BattleMon *attacker, u16 move, void *targets) {
    BattleMon *mon;
    u32 state;

    if (flow->unk4AC->count != 0) {
        mon = GetPokeParam(flow->pokeCon, flow->unk4AC->monIds[0]);
        state = PushState(&flow->actionState, 0xe98);
        func_ov167_021a24bc(flow, mon, attacker, move);
        PopState(&flow->actionState, state, 0xe9a);
        ServerEvent_GetMoveParam(flow, move, mon, flow->unk1AB0);
        func_ov167_021ae32c(flow, mon, flow->unk4AC->targets[0], flow->unk1AB0, flow->unk864);
        if (CheckCondition(mon, 0xf) && getMoveFlag(move, 0xc)) {
            func_ov167_021a3fc4(flow, mon, move, 0xd);
            return;
        }
        MoveEvent_AddItem(mon, move, GetBattleMonStat(mon, 0xc));
        func_ov167_021a2700(flow, mon, move, flow->unk864);
        RemoveForce(mon, move);
    }
}

void func_ov167_021a20c8(BtlServerFlow *flow, BattleMon *mon, BtlFlowMoveParam *param) {
    BattleEventVar_Push(0xebb);
    BattleEventVar_SetConstValue(3, GetMonID(mon));
    BattleEventVar_SetConstValue(0x12, param->move);
    BattleEventVar_SetRewriteOnceValue(0x16, param->type);
    BattleEvent_CallHandlers(flow, 0xa2);
    param->type = BattleEventVar_GetValue(0x16);
    BattleEventVar_Pop(0xec1);
}

void func_ov167_021a2114(BtlServerFlow *flow, BattleMon *mon, BtlFlowMoveParam *param, u32 event) {
    u32 state;

    state = PushState(&flow->actionState, 0xece);
    func_ov167_021a2150(flow, mon, param, event);
    PopState(&flow->actionState, state, 0xed2);
}

void func_ov167_021a2150(BtlServerFlow *flow, BattleMon *mon, BtlFlowMoveParam *param, u32 event) {
    BattleEventVar_Push(0xedf);
    BattleEventVar_SetConstValue(3, GetMonID(mon));
    BattleEventVar_SetConstValue(0x12, param->move);
    BattleEventVar_SetConstValue(0x16, param->type);
    BattleEvent_CallHandlers(flow, event);
    BattleEventVar_Pop(0xee4);
}

BOOL func_ov167_021a2194(BtlServerFlow *flow, BattleMon *mon, u16 move, u8 target) {
    u32 i;
    u32 count;
    u8 monId;
    u8 partnerId;
    BattleMon *partner;
    u32 index;
    u32 minIndex;
    ActionOrderEntry *entry;
    ActionOrderEntry *found[2];

    for (i = 0; i < 3; i++) {
        if (move == data_ov167_021d6cec[i]) {
            break;
        }
    }
    if (i != 3 && !GetTurnFlag(mon, 0xa) && !func_ov167_021bc674(mon)) {
        count = 0;
        monId = GetMonID(mon);
        for (i = 0; i < 3; i++) {
            if (move != data_ov167_021d6cec[i]) {
                found[count] = func_ov167_021a05ac(flow, data_ov167_021d6cec[i], monId, target);
                if (found[count] != NULL) {
                    count++;
                    if (count >= 2) {
                        break;
                    }
                }
            }
        }
        if (count != 0) {
            minIndex = 6;
            partner = found[0]->mon;
            for (i = 0; i < count; i++) {
                entry = found[i];
                index = func_ov167_021a0600(flow, entry);
                if (index < minIndex) {
                    minIndex = index;
                    partner = entry->mon;
                }
            }
            partnerId = GetMonID(partner);
            func_ov167_021bb7c0(mon, 0xa);
            func_ov167_021bc640(partner, monId, move);
            func_ov167_021b15d0(flow->queue, 0x5b, 0x47a, monId, partnerId, 0xffff0000);
            ActionOrder_InterruptReserve(flow, partnerId);
            return TRUE;
        }
    }
    return FALSE;
}

BOOL func_ov167_021a228c(BtlServerFlow *flow, BattleMon *mon, u16 move, u8 target, BtlFlowFightWork *work) {
    u32 state;
    BOOL result;
    u8 pos;

    state = PushState(&flow->actionState, 0xf46);
    result = func_ov167_021a2320(flow, mon, target);
    work->result = 0;
    if (result) {
        pos = MonIDToBattlePos(flow->mainModule, flow->pokeCon, GetMonID(mon));
        if (BattleHandler_Result(flow) == 2) {
            func_ov167_021b1434(flow->queue, 0x30, pos, target, move, 0);
            func_ov167_021a236c(flow, mon);
            work->result = 1;
        } else {
            func_ov167_021a9230(flow, mon, move);
        }
    }
    PopState(&flow->actionState, state, 0xf59);
    return result;
}

BOOL func_ov167_021a2320(BtlServerFlow *flow, BattleMon *mon, u8 target) {
    BOOL result;

    BattleEventVar_Push(0xf6b);
    BattleEventVar_SetConstValue(3, GetMonID(mon));
    BattleEventVar_SetConstValue(0xd, target);
    BattleEventVar_SetRewriteOnceValue(0x51, 0);
    BattleEvent_CallHandlers(flow, 6);
    result = BattleEventVar_GetValue(0x51);
    BattleEventVar_Pop(0xf71);
    return result;
}

void func_ov167_021a236c(BtlServerFlow *flow, BattleMon *mon) {
    u32 state;

    state = PushState(&flow->actionState, 0xf7f);
    func_ov167_021a239c(flow, mon);
    PopState(&flow->actionState, state, 0xf84);
}

void func_ov167_021a239c(BtlServerFlow *flow, BattleMon *mon) {
    BattleEventVar_Push(0xf90);
    BattleEventVar_SetConstValue(3, GetMonID(mon));
    BattleEvent_CallHandlers(flow, 7);
    BattleEventVar_Pop(0xf93);
}

void func_ov167_021a23cc(BtlServerFlow *flow, BattleMon *mon, u16 move) {
    u32 state;

    state = PushState(&flow->actionState, 0xfa1);
    func_ov167_021a2404(flow, mon, move);
    PopState(&flow->actionState, state, 0xfa3);
}

void func_ov167_021a2404(BtlServerFlow *flow, BattleMon *mon, u16 move) {
    BattleEventVar_Push(0xfb0);
    BattleEventVar_SetConstValue(3, GetMonID(mon));
    BattleEventVar_SetConstValue(0x12, move);
    BattleEvent_CallHandlers(flow, 3);
    BattleEventVar_Pop(0xfb4);
}

void func_ov167_021a243c(BtlServerFlow *flow, BattleMon *mon, u16 move, u8 result) {
    u32 state;

    state = PushState(&flow->actionState, 0xfc1);
    func_ov167_021a2478(flow, mon, move, result);
    PopState(&flow->actionState, state, 0xfc3);
}

void func_ov167_021a2478(BtlServerFlow *flow, BattleMon *mon, u16 move, u8 result) {
    BattleEventVar_Push(0xfd0);
    BattleEventVar_SetConstValue(2, GetMonID(mon));
    BattleEventVar_SetConstValue(0x12, move);
    BattleEventVar_SetConstValue(0x51, result);
    BattleEvent_CallHandlers(flow, 4);
    BattleEventVar_Pop(0xfd5);
}

void func_ov167_021a24bc(BtlServerFlow *flow, BattleMon *mon, BattleMon *attacker, u16 move) {
    BattleEventVar_Push(0xfe3);
    BattleEventVar_SetConstValue(2, GetMonID(mon));
    BattleEventVar_SetConstValue(3, GetMonID(attacker));
    BattleEventVar_SetConstValue(0x12, move);
    BattleEvent_CallHandlers(flow, 8);
    BattleEventVar_Pop(0xfe8);
}

void func_ov167_021a2508(BtlServerFlow *flow, BattleMon *mon, BattleMon *target, u16 move) {
    BattleEventVar_Push(0xff5);
    BattleEventVar_SetConstValue(2, GetMonID(mon));
    BattleEventVar_SetConstValue(3, GetMonID(target));
    BattleEventVar_SetConstValue(0x12, move);
    BattleEventVar_SetRewriteOnceValue(0x51, 0);
    BattleEvent_CallHandlers(flow, 9);
    BattleEventVar_Pop(0xffb);
}

BOOL func_ov167_021a255c(BtlServerFlow *flow, BattleMon *mon, u16 move, void *targets, BtlFlowReactionList *list) {
    u8 monId;
    u8 target;

    monId = 0x1f;
    target = 0x1f;
    func_ov167_021a25bc(flow, mon, move, targets, &monId, &target);
    if (monId != 0x1f) {
        list->targets[0] = target != 0x1f ? GetBattlePos(flow->unk1ab8, target) : 6;
        list->monIds[0] = monId;
        list->count = 1;
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov167_021a25bc(BtlServerFlow *flow, BattleMon *mon, u16 move, void *targets, u8 *monId, u8 *target) {
    u32 count;
    u32 i;

    count = func_ov169_0689cec0(targets);
    BattleEventVar_Push(0x1038);
    BattleEventVar_SetConstValue(0x12, move);
    BattleEventVar_SetConstValue(3, GetMonID(mon));
    BattleEventVar_SetConstValue(5, count);
    for (i = 0; i < count; i++) {
        BattleEventVar_SetConstValue(i + 6, GetMonID(func_ov169_0689cdf8(targets, i)));
    }
    BattleEventVar_SetRewriteOnceValue(2, 0x1f);
    BattleEventVar_SetValue(4, 0x1f);
    BattleEvent_CallHandlers(flow, 0x1a);
    *monId = BattleEventVar_GetValue(2);
    *target = BattleEventVar_GetValue(4);
    BattleEventVar_Pop(0x104b);
    if (*monId != 0x1f) {
        return TRUE;
    }
    return FALSE;
}

void func_ov167_021a2680(BtlServerFlow *flow, BattleMon *mon, u16 move, u8 target) {
    func_ov167_021b1434(flow->queue, 0x30, MonIDToBattlePos(flow->mainModule, flow->pokeCon, GetMonID(mon)), target,
                        move, 0);
}

BOOL func_ov167_021a26b0(BtlServerFlow *flow, BattleMon *mon) {
    if (func_ov167_0219c648(GetMonID(mon)) == GetPlayerClientID(flow->mainModule)) {
        return TRUE;
    }
    return FALSE;
}

void func_ov167_021a26d4(BtlServerFlow *flow, BattleMon *mon, u16 move) {
    if (func_ov167_021a26b0(flow, mon)) {
        if (move == 0x96) {
            func_ov167_0219dad0(flow->mainModule, 0x49);
        } else if (move == 0xa5) {
            func_ov167_0219dad0(flow->mainModule, 0x4a);
        }
    }
}

BOOL func_ov167_021a2700(BtlServerFlow *flow, BattleMon *mon, u16 move, void *targets) {
    s32 quality;
    u8 monId;
    BOOL success;
    BOOL isDamage;
    BOOL isDamage2;
    u32 reserved;
    u32 state;
    u32 result;

    quality = PML_MoveGetQuality(move);
    monId = GetMonID(mon);
    success = TRUE;
    isDamage = FALSE;
    isDamage2 = FALSE;
    func_ov167_021a26d4(flow, mon, move);
    if (getMoveFlag(move, 1)) {
        switch (func_ov167_021a36ac(flow, mon, targets, move)) {
        case 0:
            break;
        case 1:
            return isDamage;
        case 2:
            return success;
        case 3:
            return isDamage;
        case 4:
            break;
        }
    }
    func_ov169_0689ccc4(flow->unk860);
    reserved = SCQUE_RESERVE_Pos(flow->queue, 0x30);
    func_ov167_021a0ca8(flow->moveEffect, flow, mon, targets);
    state = PushState(&flow->actionState, 0x10b8);
    result = func_ov167_021aa0c0(flow, mon, move, targets);
    PopState(&flow->actionState, state, 0x10ba);
    if (result) {
        if (!flow->moveEffect->enabled) {
            flow->moveEffect->enabled = TRUE;
        }
        if (result == 2) {
            func_ov167_021a3674(flow, move, flow->moveEffect, reserved);
            return TRUE;
        }
    }
    switch (quality) {
    case 0:
    case 4:
    case 6:
    case 7:
    case 8:
        isDamage = TRUE;
        isDamage2 = TRUE;
        break;
    case 9:
        isDamage2 = TRUE;
        break;
    }
    func_ov169_0689d06c(targets);
    func_ov167_021a2af4(flow, flow->unk1AB0, mon, targets);
    func_ov167_021a2b8c(flow, mon, targets, flow->unk1AB0, isDamage);
    if (func_ov169_0689ced8(targets)) {
        if (!flow->unk78A_4) {
            func_ov167_021a9230(flow, mon, move);
        }
        success = FALSE;
    }
    if (success) {
        if (quality != 9) {
            func_ov167_021a32e0(flow, flow->unk1AB0, mon, targets);
        }
        func_ov167_021b0814(flow->unk1F8C);
        if (isDamage2 || func_ov167_021a2c10(flow, flow->unk1AB0, mon)) {
            func_ov167_021a2e80(flow, flow->unk1AB0, mon, targets, flow->unk1F8C);
        }
        func_ov167_021a2f54(flow, flow->unk1AB0, mon, targets, flow->unk1F8C);
        if (quality != 9) {
            func_ov167_021a3378(flow, flow->unk1AB0, mon, targets);
        }
        if (func_ov169_0689ced8(targets)) {
            func_ov167_021a2d24(flow, monId, move);
            success = FALSE;
        } else {
            func_ov167_021a2c5c(flow, flow->unk1AB0, mon, targets, isDamage2);
            if (func_ov169_0689ced8(targets)) {
                func_ov167_021a9230(flow, mon, move);
                func_ov167_021a2d24(flow, monId, move);
                success = FALSE;
            }
        }
    }
    if (success) {
        if (isDamage) {
            func_ov167_021a43c0(flow, flow->unk1AB0, mon, targets, flow->unk1F8C, 0);
        } else {
            switch (quality) {
            case 2:
                ServerControl_SimpleEffect(flow, flow->unk1AB0, mon, targets);
                break;
            case 1:
                ServerControl_SimpleCondition(flow, move, mon, targets);
                break;
            case 5:
                func_ov167_021a6c34(flow, flow->unk1AB0, mon, targets);
                break;
            case 9:
                ServerControl_OHKO(flow, flow->unk1AB0, mon, targets);
                break;
            case 0xc:
                ServerControl_ForceSwitch(flow, move, mon, targets);
                break;
            case 3:
                func_ov167_021a6d24(flow, move, mon, targets);
                break;
            case 0xa:
                ServerControl_FieldEffect(flow, flow->unk1AB0, mon);
                break;
            case 0xb:
            case 0xd:
                func_ov167_021a77b8(flow, flow->unk1AB0, mon, targets);
                break;
            }
        }
        if (flow->moveEffect->enabled) {
            if (!flow->moveEffect->unk05_1) {
                func_ov167_021a3674(flow, move, flow->moveEffect, reserved);
            }
            func_ov169_0689d1d8(flow->unk1C);
            if (!IsFainted(mon) && getMoveFlag(move, 2)) {
                scPut_SetContFlag(flow, mon, 0xc);
            }
            func_ov167_021a2cec(flow, monId, move);
        } else {
            func_ov167_021a2d24(flow, monId, move);
            success = FALSE;
        }
    } else if (flow->moveEffect->enabled) {
        func_ov167_021a3674(flow, move, flow->moveEffect, reserved);
    }
    func_ov167_021a2d5c(flow, monId, move);
    ServerControl_CheckFainted(flow, mon);
    return success;
}

void func_ov167_021a2af4(BtlServerFlow *flow, BtlFlowMoveParam *param, BattleMon *mon, void *targets) {
    BattleMon *target;

    func_ov169_0689ce0c(targets);
    while ((target = func_ov169_0689ce14(targets)) != NULL) {
        if (func_ov167_021a34a4(flow, mon, target, param->move)) {
            func_ov169_0689cd9c(targets, target);
            func_ov167_021a9244(flow, target, param->move);
            flow->unk78A_4 = TRUE;
        }
    }
}

void func_ov167_021a2b8c(BtlServerFlow *flow, BattleMon *mon, void *targets, BtlFlowMoveParam *param, BOOL flag) {
    BattleMon *target;

    if (func_ov169_0689cec8(targets) == 1) {
        target = func_ov169_0689cdf8(targets, 0);
        if (target != NULL && GetMonID(target) == GetMonID(mon) && param->unk0C != 7 &&
            (GetTurnFlag(mon, 0xc) || flag)) {
            func_ov169_0689cd9c(targets, target);
        }
    }
}

BOOL func_ov167_021a2c10(BtlServerFlow *flow, BtlFlowMoveParam *param, BattleMon *mon) {
    BOOL result;

    BattleEventVar_Push(0x11a4);
    BattleEventVar_SetValue(3, GetMonID(mon));
    BattleEventVar_SetValue(0x12, param->move);
    BattleEventVar_SetRewriteOnceValue(0x51, 0);
    BattleEvent_CallHandlers(flow, 0x3d);
    result = BattleEventVar_GetValue(0x51);
    BattleEventVar_Pop(0x11aa);
    return result;
}

void func_ov167_021a2c5c(BtlServerFlow *flow, BtlFlowMoveParam *param, BattleMon *mon, void *targets, BOOL flag) {
    BattleMon *target;

    func_ov169_0689ce0c(targets);
    while ((target = func_ov169_0689ce14(targets)) != NULL) {
        if (mon != target && IsSubstituteActive(target) && !flag && !getMoveFlag(param->move, 0xd)) {
            func_ov169_0689cd9c(targets, target);
        }
    }
}

void func_ov167_021a2cec(BtlServerFlow *flow, u8 monId, u16 move) {
    u32 state;

    state = PushState(&flow->actionState, 0x11f7);
    func_ov167_021a2d94(flow, monId, move, 0x25);
    PopState(&flow->actionState, state, 0x11f9);
}

void func_ov167_021a2d24(BtlServerFlow *flow, u8 monId, u16 move) {
    u32 state;

    state = PushState(&flow->actionState, 0x1206);
    func_ov167_021a2d94(flow, monId, move, 0x26);
    PopState(&flow->actionState, state, 0x1208);
}

void func_ov167_021a2d5c(BtlServerFlow *flow, u8 monId, u16 move) {
    u32 state;

    state = PushState(&flow->actionState, 0x1215);
    func_ov167_021a2d94(flow, monId, move, 0x27);
    PopState(&flow->actionState, state, 0x1217);
}

void func_ov167_021a2d94(BtlServerFlow *flow, u8 monId, u16 move, u32 event) {
    BattleEventVar_Push(0x1224);
    BattleEventVar_SetConstValue(2, monId);
    BattleEventVar_SetConstValue(0x12, move);
    BattleEvent_CallHandlers(flow, event);
    BattleEventVar_Pop(0x1228);
}

BOOL IsGuaranteedHit(BtlServerFlow *flow, BattleMon *attacker, BattleMon *defender) {
    u8 lockedId;

    if (func_ov169_0689d724(flow->unk1ab8, flow->mainModule, GetMonID(attacker)) &&
        GetBattleMonStat(attacker, 0x11) == 0x63) {
        return TRUE;
    }
    if (func_ov169_0689d724(flow->unk1ab8, flow->mainModule, GetMonID(defender)) &&
        GetBattleMonStat(defender, 0x11) == 0x63) {
        return TRUE;
    }
    if (CheckCondition(attacker, 0x1c)) {
        return TRUE;
    }
    if (CheckCondition(attacker, 0x1d)) {
        lockedId = GetDisabledMove(attacker, 0x1d);
        if (lockedId == GetMonID(defender)) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_ov167_021a2e80(BtlServerFlow *flow, BtlFlowMoveParam *param, BattleMon *mon, void *targets, void *data) {
    BattleMon *target;
    BOOL hit;

    func_ov167_021b0814(data);
    func_ov169_0689ce0c(targets);
    while ((target = func_ov169_0689ce14(targets)) != NULL) {
        hit = func_ov167_021aa954(flow, mon, target, param, TRUE);
        func_ov167_021b0824(data, GetMonID(target), hit);
        if (!hit) {
            func_ov169_0689cd9c(targets, target);
            func_ov167_021ab73c(flow->unk1F80, flow, mon, target, 0);
            if (func_ov167_0219c648(GetMonID(mon)) == GetPlayerClientID(flow->mainModule)) {
                func_ov167_0219dad0(flow->mainModule, 0x4b);
            }
        }
    }
}

void func_ov167_021a2f54(BtlServerFlow *flow, BtlFlowMoveParam *param, BattleMon *mon, void *targets, void *data) {
    BattleMon *target;

    func_ov169_0689ce0c(targets);
    while ((target = func_ov169_0689ce14(targets)) != NULL) {
        if (!IsGuaranteedHit(flow, mon, target) && func_ov167_021a3190(flow, param, mon, target, data, 0x2b)) {
            func_ov169_0689cd9c(targets, target);
        }
    }
    func_ov169_0689ce0c(targets);
    while ((target = func_ov169_0689ce14(targets)) != NULL) {
        if (func_ov167_021a3190(flow, param, mon, target, data, 0x2c)) {
            func_ov169_0689cd9c(targets, target);
        }
    }
    if (getMoveFlag(param->move, 3)) {
        func_ov169_0689ce0c(targets);
        while ((target = func_ov169_0689ce14(targets)) != NULL) {
            if (GetTurnFlag(target, 7) && !func_ov167_021aa180(flow, mon, target, param->move)) {
                func_ov169_0689cd9c(targets, target);
                func_ov167_021b15d0(flow->queue, 0x5b, 0x20b, GetMonID(target), 0xffff0000);
            }
        }
    }
    func_ov169_0689ce0c(targets);
    while ((target = func_ov169_0689ce14(targets)) != NULL) {
        if (func_ov167_021a3190(flow, param, mon, target, data, 0x2d)) {
            func_ov169_0689cd9c(targets, target);
        }
    }
}

BOOL func_ov167_021a3190(BtlServerFlow *flow, BtlFlowMoveParam *param, BattleMon *mon, BattleMon *target, void *data,
                         u32 event) {
    u32 state;
    BOOL result;
    BOOL silent;

    state = PushState(&flow->actionState, 0x12c0);
    silent = FALSE;
    result = func_ov167_021a3230(flow, param, event, mon, target, data, &flow->message, &silent);
    if (result) {
        if (BattleHandler_StrIsEnabled(&flow->message)) {
            BattleHandler_SetString(flow, &flow->message);
            BattleHandler_StrClear(&flow->message);
        } else if (BattleHandler_Result(flow) == 0 && !silent) {
            func_ov167_021b15d0(flow->queue, 0x5b, 0xd2, GetMonID(target), 0xffff0000);
        }
    }
    PopState(&flow->actionState, state, 0x12da);
    return result;
}

BOOL func_ov167_021a3230(BtlServerFlow *flow, BtlFlowMoveParam *param, u32 event, BattleMon *mon, BattleMon *target,
                         void *data, BattleHandlerString *string, BOOL *silent) {
    u32 value;
    BOOL result;

    value = func_ov167_021b0834(data, GetMonID(target));
    BattleHandler_StrClear(string);
    BattleEventVar_Push(0x12f2);
    BattleEventVar_SetConstValue(3, GetMonID(mon));
    BattleEventVar_SetConstValue(4, GetMonID(target));
    BattleEventVar_SetConstValue(0x12, param->move);
    BattleEventVar_SetConstValue(0x16, param->type);
    BattleEventVar_SetConstValue(0x4e, param->flags.unk0);
    BattleEventVar_SetConstValue(0x3f, (s32)string);
    BattleEventVar_SetConstValue(0x38, value);
    BattleEventVar_SetRewriteOnceValue(0x40, 0);
    BattleEventVar_SetRewriteOnceValue(0x51, 0);
    BattleEvent_CallHandlers(flow, event);
    result = BattleEventVar_GetValue(0x40);
    *silent = BattleEventVar_GetValue(0x51);
    BattleEventVar_Pop(0x12ff);
    return result;
}

void func_ov167_021a32e0(BtlServerFlow *flow, BtlFlowMoveParam *param, BattleMon *mon, void *targets) {
    BattleMon *target;

    func_ov169_0689ce0c(targets);
    while ((target = func_ov169_0689ce14(targets)) != NULL) {
        if (!IsGuaranteedHit(flow, mon, target) && func_ov167_021aa460(flow, mon, target, param->move)) {
            func_ov169_0689cd9c(targets, target);
            func_ov167_021a9244(flow, target, param->move);
        }
    }
}

void func_ov167_021a3378(BtlServerFlow *flow, BtlFlowMoveParam *param, BattleMon *mon, void *targets) {
    BattleMon *target;

    if (func_ov169_0689cec8(targets) != 1 || func_ov169_0689cdf8(targets, 0) != mon) {
        func_ov169_0689ce0c(targets);
        while ((target = func_ov169_0689ce14(targets)) != NULL) {
            if (!func_ov167_021a3448(flow, mon, target, param) && !func_ov167_021a3504(flow, mon, target, param)) {
                func_ov169_0689cd9c(targets, target);
                func_ov167_021a9244(flow, target, param->move);
            }
        }
    }
}

BOOL func_ov167_021a3448(BtlServerFlow *flow, BattleMon *mon, BattleMon *target, BtlFlowMoveParam *param) {
    BOOL result;

    BattleEventVar_Push(0x1351);
    BattleEventVar_SetConstValue(3, GetMonID(mon));
    BattleEventVar_SetConstValue(4, GetMonID(target));
    BattleEventVar_SetConstValue(0x12, param->move);
    BattleEventVar_SetRewriteOnceValue(0x51, 0);
    BattleEvent_CallHandlers(flow, 0x1c);
    result = BattleEventVar_GetValue(0x51);
    BattleEventVar_Pop(0x1358);
    return result;
}

BOOL func_ov167_021a34a4(BtlServerFlow *flow, BattleMon *mon, BattleMon *target, u16 move) {
    if (BtlSetup_GetBattleStyle(flow->mainModule) == 2) {
        u8 pos1, pos2;
        if (move != 0 && getMoveFlag(move, 0xb)) {
            return FALSE;
        }
        pos1 = MonIDToBattlePos(flow->mainModule, flow->pokeCon, GetMonID(mon));
        pos2 = MonIDToBattlePos(flow->mainModule, flow->pokeCon, GetMonID(target));
        if (!IsAdjacentOpponent(pos1, pos2)) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL func_ov167_021a3504(BtlServerFlow *flow, BattleMon *mon, BattleMon *target, BtlFlowMoveParam *param) {
    u8 ignore;
    s8 accuracy;
    u32 base;
    s8 evasion;
    u32 ratio;
    s32 stage;
    u32 chance;

    if (IsGuaranteedHit(flow, mon, target)) {
        return TRUE;
    }
    if (func_ov167_021aa4d0(flow, mon, target, param->move)) {
        return TRUE;
    }
    if (CheckCondition(target, 0x20)) {
        return TRUE;
    }
    base = func_ov167_021aa51c(flow, mon, target, param);

    BattleEventVar_Push(0x13a6);
    BattleEventVar_SetConstValue(3, GetMonID(mon));
    BattleEventVar_SetConstValue(4, GetMonID(target));
    BattleEventVar_SetRewriteOnceValue(0x4b, 0);
    BattleEventVar_SetValue(0x27, GetBattleMonStat(mon, 6));
    BattleEventVar_SetValue(0x28, GetBattleMonStat(target, 7));
    BattleEventVar_SetMulValue(0x35, 0x1000, 0x29, 0x20000);
    BattleEvent_CallHandlers(flow, 0x33);
    accuracy = BattleEventVar_GetValue(0x27);
    evasion = BattleEventVar_GetValue(0x28);
    ignore = BattleEventVar_GetValue(0x4b);
    if ((CheckCondition(target, 0x11) && evasion > 6) || ignore) {
        evasion = 6;
    }
    if (GetTurnFlag(mon, 0xe)) {
        BattleEventVar_MulValue(0x35, 0x1333);
    }
    ratio = BattleEventVar_GetValue(0x35);
    BattleEventVar_Pop(0x13bf);

    stage = accuracy + 6 - evasion;
    if (stage < 0) {
        stage = 0;
    }
    if (stage > 12) {
        stage = 12;
    }
    chance = fixed_round(func_ov167_021bd11c((u8)base, (u8)(s8)stage), ratio);
    if (chance > 100) {
        chance = 100;
    }
    if (ReturnZero(flow->mainModule, 6)) {
        chance = 100;
    }
    return BattleRandom(100) < (u8)chance;
}

void func_ov167_021a3674(BtlServerFlow *flow, u16 move, BattleMoveEffectState *effect, u32 reserved) {
    u32 shown = effect->unk00 ? effect->unk00 : move;
    func_ov167_021b14ec(flow->queue, (u16)reserved, 0x30, effect->pos1, effect->pos2, shown, effect->index);
    effect->index = 0;
    effect->unk05_1 = 1;
}

u32 func_ov167_021a36ac(BtlServerFlow *flow, BattleMon *mon, void *targets, u16 move) {
    u32 state;
    u32 result;

    if (!CheckCondition(mon, 0x1a)) {
        u8 pos = MonIDToBattlePos(flow->mainModule, flow->pokeCon, GetMonID(mon));
        if (func_ov167_021aa1c4(flow, mon, targets)) {
            func_ov167_021a9230(flow, mon, move);
            return 1;
        }
        if (!func_ov167_021aa238(flow, mon, move)) {
            if (func_ov167_021a37c8(flow, mon, pos, targets, move)) {
                BattleCondition cond = AddTurnCondition(2, move);
                ServerDisplay_AddCondition(flow, mon, 0x1a, cond);
            }
            return 2;
        }
        if (!func_ov167_021a37c8(flow, mon, pos, targets, move)) {
            return 1;
        }
        state = PushState(&flow->actionState, 0x1414);
        func_ov167_021aa390(flow, mon, move);
        PopState(&flow->actionState, state, 0x1416);
    }
    flow->moveEffect->index = 1;
    state = PushState(&flow->actionState, 0x141e);
    result = func_ov167_021aa3c0(flow, mon, targets, move);
    PopState(&flow->actionState, state, 0x1420);
    func_ov167_021bb7c0(mon, 0xb);
    func_ov167_021a3904(flow, mon);
    return result ? 4 : 3;
}

BOOL func_ov167_021a37c8(BtlServerFlow *flow, BattleMon *mon, u8 pos, void *targets, u16 move) {
    u32 state;
    BOOL result;
    BOOL failed = FALSE;
    u8 id = 0x1f;

    state = PushState(&flow->actionState, 0x1438);
    result = func_ov167_021aa284(flow, mon, targets, move, &id, &failed);
    if (result) {
        u8 targetPos = flow->unk77F;
        if (func_ov169_0689cec0(targets)) {
            targetPos = GetBattlePos(flow->unk1ab8, GetMonID(func_ov169_0689cdf8(targets, 0)));
        }
        func_ov167_021b1434(flow->queue, 0x30, pos, targetPos, move, 0);
    }
    PopState(&flow->actionState, state, 0x1445);
    if (result) {
        state = PushState(&flow->actionState, 0x1449);
        func_ov167_021aa360(flow, mon);
        PopState(&flow->actionState, state, 0x144b);
        if (IsSemiInvulnMove(mon)) {
            func_ov167_021b1434(flow->queue, 0x31, GetMonID(mon), 1);
        }
        if (id != 0x1f) {
            func_ov167_021b1434(flow->queue, 0x31, id, 1);
        }
    } else if (!failed) {
        func_ov167_021a9230(flow, mon, move);
    }
    return result;
}

void func_ov167_021a3904(BtlServerFlow *flow, BattleMon *mon) {
    u32 flag;
    if (CheckCondition(mon, 0x1a)) {
        ServerControl_CureCondition(flow, mon, 0x1a, 0);
        func_ov167_021bb7c0(mon, 0xb);
    }
    while ((flag = func_ov167_021bb408(mon)) != 0x10) {
        scPut_ResetContFlag(flow, mon, flag);
    }
}

BOOL func_ov167_021a3950(BtlServerFlow *flow, BattleMon *attacker, BattleMon *target, BOOL *failed) {
    *failed = FALSE;
    if (!IsFainted(target) && !IsSubstituteActive(target) && !IsSemiInvulnMove(target)) {
        if (!GetTurnFlag(target, 7)) {
            u8 targetId = GetMonID(target);
            BattleCondition cond;

            scPut_SetContFlag(flow, attacker, 3);
            scPut_SetContFlag(flow, target, 3);
            ServerControl_SetMonCounter(flow, attacker, 4, targetId + 1);
            cond = func_ov167_021ce1dc(GetMonID(attacker));
            ServerControl_AddCondition(flow, target, attacker, 0x21, cond, FALSE, FALSE, NULL);
            return TRUE;
        }
        func_ov167_021b15d0(flow->queue, 0x5b, 0x20b, GetMonID(target), 0xffff0000);
        *failed = TRUE;
    }
    return FALSE;
}

void ServerControl_SkyDropCheckRelease(BtlServerFlow *flow, BattleMon *mon, BOOL flag) {
    u8 targetId;
    u8 counter = GetConditionCount(mon, 4);
    if (counter == 0 || (targetId = counter - 1) >= 0x18) {
        targetId = 0x1f;
    }
    if (targetId != 0x1f) {
        BattleMon *target = GetPokeParam(flow->pokeCon, targetId);
        if (CheckCondition(target, 0x21)) {
            ServerControl_CureCondition(flow, target, 0x21, 0);
            scPut_ResetContFlag(flow, target, 3);
            if (DoesBattleMonExist(flow->unk1ab8, targetId)) {
                func_ov167_021b1434(flow->queue, 0x31, targetId, 0);
                ServerDisplay_SkyDropTargetAppear(flow, target, 0x465);
            }
        }
        ServerControl_SetMonCounter(flow, mon, 4, 0);
        if (!flag && !IsFainted(mon)) {
            func_ov167_021b1434(flow->queue, 0x31, GetMonID(mon), 0);
        }
    }
}

BOOL func_ov167_021a3ac0(BtlServerFlow *flow, BattleMon *mon, u16 move, u8 flag) {
    u32 status;
    BOOL thawedByMove = FALSE;
    u32 cause = 0;

    func_ov167_021a3e7c(flow, mon, move);
    status = GetBattleMonStatus(mon);
    do {
        if (status == 2 && !func_ov167_021a3d18(flow, mon, move, 2)) {
            cause = 2;
            break;
        }
        thawedByMove = func_ov167_021a3ea8(flow, mon, move);
        status = GetBattleMonStatus(mon);
        if (status == 3 && !thawedByMove) {
            cause = 4;
            break;
        }
        if (flow->unk1F7C == 4) {
            cause = 0x16;
            break;
        }
        if (flow->unk1F7C == 2) {
            cause = 0x17;
            break;
        }
        if (!flag) {
            u8 slot = func_ov167_021baf78(mon, move);
            if (slot != 4 && GetMovePP(mon, slot) == 0) {
                cause = 1;
                break;
            }
        }
        cause = func_ov167_021a3d70(flow, mon, move, 0x1e);
        if (cause != 0) {
            break;
        }
        if (GetTurnFlag(mon, 6)) {
            cause = 7;
            break;
        }
        if (GetTurnFlag(mon, 4)) {
            cause = 6;
            break;
        }
        if (CheckCondition(mon, 0xd) && move != 0xa5) {
            BattleConditionCont cont = GetConditionContinuationParam(mon, 0xd);
            if (move == Condition_GetParam(cont)) {
                cause = 9;
                break;
            }
        }
        if (CheckCondition(mon, 0xf) && getMoveFlag(move, 0xc)) {
            cause = 0xd;
            break;
        }
        if (IsFieldEffectActive(2) && getMoveFlag(move, 9)) {
            cause = 0x14;
            break;
        }
        if (move != 0xa5) {
            if (CheckCondition(mon, 0x17)) {
                u16 prev = GetPreviousMoveUsed(mon);
                if (prev != 0xa5 && prev != move) {
                    cause = 0x11;
                    break;
                }
            }
            if (CheckCondition(mon, 0x19) && move != GetPreviousMoveID(mon)) {
                cause = 0x11;
                break;
            }
            if (CheckCondition(mon, 0xb) && !PML_MoveIsDamaging(move)) {
                cause = 0xa;
                break;
            }
            if (IsFieldEffectActive(3) && func_ov167_021d5a48(flow->pokeCon, mon, move)) {
                cause = 0xc;
                break;
            }
        }
        if (func_ov167_021a3dc0(flow, mon)) {
            cause = 5;
            break;
        }
        if (status == 1 && RollEffectChance(0x19)) {
            cause = 3;
            break;
        }
        if (func_ov167_021a3e50(flow, mon)) {
            cause = 8;
            break;
        }
    } while (0);

    if (cause != 0) {
        func_ov167_021a3ef4(flow, mon, move, cause);
        return TRUE;
    }
    if (status == 2) {
        func_ov167_021a3fc4(flow, mon, move, 2);
        ServerDisplay_AddEffectAtPosition(flow, mon, 0x256);
    } else if (thawedByMove && status == 3) {
        func_ov167_021a9094(flow, mon, status, FALSE);
        func_ov167_021b15d0(flow->queue, 0x5b, 0x12f, GetMonID(mon), move, 0xffff0000);
    }
    return FALSE;
}

BOOL func_ov167_021a3cf0(BtlServerFlow *flow, BattleMon *mon, u16 move) {
    u32 cause;
    if (move != 0xa5) {
        cause = func_ov167_021a3d70(flow, mon, move, 0x1f);
        if (cause != 0) {
            func_ov167_021a3ef4(flow, mon, move, cause);
            return TRUE;
        }
    }
    return FALSE;
}

BOOL func_ov167_021a3d18(BtlServerFlow *flow, BattleMon *mon, u16 move, u32 status) {
    BOOL result;
    BattleEventVar_Push(0x15b1);
    BattleEventVar_SetConstValue(2, GetMonID(mon));
    BattleEventVar_SetConstValue(0x22, status);
    BattleEventVar_SetConstValue(0x12, move);
    BattleEventVar_SetRewriteOnceValue(0x41, 0);
    BattleEvent_CallHandlers(flow, 0x1d);
    result = BattleEventVar_GetValue(0x41);
    BattleEventVar_Pop(0x15b8);
    return result;
}

u32 func_ov167_021a3d70(BtlServerFlow *flow, BattleMon *mon, u16 move, u32 event) {
    u32 cause;
    BattleEventVar_Push(0x15cb);
    BattleEventVar_SetConstValue(0x12, move);
    BattleEventVar_SetConstValue(2, GetMonID(mon));
    BattleEventVar_SetRewriteOnceValue(0x22, 0);
    BattleEvent_CallHandlers(flow, event);
    cause = BattleEventVar_GetValue(0x22);
    BattleEventVar_Pop(0x15d1);
    return cause;
}

BOOL func_ov167_021a3dc0(BtlServerFlow *flow, BattleMon *mon) {
    if (flow->unk1F7C == 3) {
        func_ov167_021b15d0(flow->queue, 0x5a, 0xbc, GetMonID(mon), 0xffff0000);
        return TRUE;
    }
    if (CheckCondition(mon, 6)) {
        if (func_ov167_021bb9a8(mon)) {
            ServerControl_CureCondition(flow, mon, 6, 0);
            func_ov167_021b15d0(flow->queue, 0x5b, 0x15f, GetMonID(mon), 0xffff0000);
            return FALSE;
        }
        func_ov167_021a8fe0(flow, mon);
        return RollEffectChance(0x32);
    }
    return FALSE;
}

BOOL func_ov167_021a3e50(BtlServerFlow *flow, BattleMon *mon) {
    if (CheckCondition(mon, 7)) {
        func_ov167_021a9014(flow, mon);
        if (RollEffectChance(0x32)) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_ov167_021a3e7c(BtlServerFlow *flow, BattleMon *mon, u16 move) {
    u32 status = GetBattleMonStatus(mon);
    if (status == 2 && func_ov167_021bb930(mon)) {
        func_ov167_021a9094(flow, mon, status, TRUE);
    }
}

BOOL func_ov167_021a3ea8(BtlServerFlow *flow, BattleMon *mon, u16 move) {
    u32 status = GetBattleMonStatus(mon);
    BOOL thawed = FALSE;
    BOOL thawedByMove = FALSE;
    if (status == 3) {
        if (getMoveFlag(move, 0xa)) {
            thawedByMove = TRUE;
        } else if (RollEffectChance(0x14)) {
            thawed = TRUE;
        }
    }
    if (thawed) {
        func_ov167_021a9094(flow, mon, status, TRUE);
    }
    return thawedByMove;
}

void func_ov167_021a3ef4(BtlServerFlow *flow, BattleMon *mon, u16 move, s32 cause) {
    u32 state;

    if (cause == 5) {
        func_ov167_021a9ee8(flow, mon);
        if (ServerControl_CheckFainted(flow, mon) && ServerControl_CheckMatchup(flow)) {
            return;
        }
    } else {
        func_ov167_021a3fc4(flow, mon, move, cause);
        switch (cause) {
        case 2:
            ServerDisplay_AddEffectAtPosition(flow, mon, 0x256);
            break;
        case 3:
            ServerDisplay_AddEffectAtPosition(flow, mon, 0x25a);
            break;
        case 4:
            ServerDisplay_AddEffectAtPosition(flow, mon, 0x259);
            break;
        case 0x17: {
            BattleCondition cond = func_ov167_021bd52c(2);
            func_ov167_021b1434(flow->queue, 0x31, GetMonID(mon), 0);
            ServerDisplay_AddCondition(flow, mon, 2, cond);
            ServerDisplay_AddEffectAtPosition(flow, mon, 0x256);
            break;
        }
        }
    }
    state = PushState(&flow->actionState, 0x1670);
    func_ov167_021aa07c(flow, mon, move, cause);
    PopState(&flow->actionState, state, 0x1672);
}

void func_ov167_021a3fc4(BtlServerFlow *flow, BattleMon *mon, u16 move, u32 cause) {
    u8 monId = GetMonID(mon);

    switch (cause) {
    case 2:
        func_ov167_021b15d0(flow->queue, 0x5b, 0x135, monId, 0xffff0000);
        break;
    case 3:
        func_ov167_021b15d0(flow->queue, 0x5b, 0x114, monId, 0xffff0000);
        break;
    case 4:
        func_ov167_021b15d0(flow->queue, 0x5b, 0x123, monId, 0xffff0000);
        break;
    case 6:
        func_ov167_021b15d0(flow->queue, 0x5b, 0x16b, monId, 0xffff0000);
        break;
    case 7:
        func_ov167_021b15d0(flow->queue, 0x5b, 0x16e, monId, 0xffff0000);
        break;
    case 8:
        func_ov167_021b15d0(flow->queue, 0x5b, 0x150, monId, 0xffff0000);
        break;
    case 9:
        func_ov167_021b15d0(flow->queue, 0x5b, 0x253, monId, move, 0xffff0000);
        break;
    case 0x12:
        func_ov167_021b15d0(flow->queue, 0x5b, 0x1bd, monId, 0xffff0000);
        break;
    case 0xa:
        func_ov167_021b15d0(flow->queue, 0x5b, 0x23b, monId, move, 0xffff0000);
        break;
    case 0xb:
        func_ov167_021b15d0(flow->queue, 0x5b, 0x244, monId, move, 0xffff0000);
        break;
    case 0xc:
        func_ov167_021b15d0(flow->queue, 0x5b, 0x24d, monId, move, 0xffff0000);
        break;
    case 0xd:
        func_ov167_021b15d0(flow->queue, 0x5b, 0x37a, monId, move, 0xffff0000);
        break;
    case 0xe:
        func_ov167_021b15d0(flow->queue, 0x5b, 0x37d, monId, 0xffff0000);
        break;
    case 0xf:
        func_ov167_021b1434(flow->queue, 0x57, monId);
        func_ov167_021b15d0(flow->queue, 0x5b, 0x1c3, monId, 0xffff0000);
        func_ov167_021b1434(flow->queue, 0x58, monId);
        break;
    case 0x14:
        func_ov167_021b15d0(flow->queue, 0x5b, 0x43e, monId, move, 0xffff0000);
        break;
    case 0x16:
        if (CheckCondition(mon, 2)) {
            func_ov167_021b15d0(flow->queue, 0x5a, 0xc2, monId, 0xffff0000);
        } else {
            u8 index = BattleRandom(4);
            func_ov167_021b15d0(flow->queue, 0x5a, 0xbc + index, monId, 0xffff0000);
        }
        break;
    case 0x17:
        func_ov167_021b15d0(flow->queue, 0x5a, 0xc1, monId, 0xffff0000);
        break;
    case 1:
        func_ov167_021a911c(flow, mon, move);
        func_ov167_021b15d0(flow->queue, 0x5a, 0x52, monId, 0xffff0000);
        break;
    case 0x13:
    case 0x19:
        break;
    default:
        func_ov167_021b15d0(flow->queue, 0x5a, 0x47, monId, 0xffff0000);
        break;
    }
}

void ServerControl_SetMonCounter(BtlServerFlow *flow, BattleMon *mon, u32 counter, u8 value) {
    func_ov167_021b1434(flow->queue, 0x25, GetMonID(mon), (u8)counter, value);
    COUNTER_Set(mon, counter, value);
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
                if (func_ov167_021acca8(code, resultCondition, mon, context, &handler->message)) {
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
                if (func_ov167_021a6ab8(handler, param->monIndex, mon, stat, param->change, 0x1f, context, param->value,
                                        param->unk0e, param->flag == 0)) {
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
