#ifndef POKEBW2_BATTLE_BTL_HANDLER_H
#define POKEBW2_BATTLE_BTL_HANDLER_H

#include "types.h"
#include "battle/btl_action.h"
#include "battle/btl_action_order.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server.h"
#include "struct_decls.h"

struct BattleHandlerPopupParam {
    u32 unk00 : 8;
    u32 monId : 5;
    u32 unk13 : 19;
};

struct BattleHandlerString {
    u16 message;
    union {
        u16 flags;
        struct {
            u16 enabled : 8;
            u16 count : 7;
            u16 hasSound : 1;
        };
    };
    u32 args[8];
    u32 soundEffect;
};

// A move's parameters as the events changed them
typedef struct {
    u16 move;
    u16 originalMove;
    u8 unk04;
    u8 unk05;
    u8 type;
    u8 unk07;
    u32 category;
    u32 unk0C;
    union {
        u32 raw;
        struct {
            u32 unk0 : 1;
            u32 unk1 : 31;
        };
    } flags;
} BtlFlowMoveParam;

// One target's result from the damage calculation of a move
typedef struct {
    u16 damage;
    u16 monId : 5;
    u16 effectiveness : 4;
    u16 unk9 : 4;
    u16 critical : 1;
    u16 fixedDamage : 1;
    u16 substitute : 1;
} BtlFlowDamageEntry;

typedef struct {
    u8 count;
    u8 substituteCount;
    u8 total;
    u8 unk03;
    BtlFlowDamageEntry entries[6];
} BtlFlowDamageList;

// How many times a move hits, and how its hits are checked
typedef struct {
    u8 count;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    u8 unk04;
    u8 unk05;
} BtlFlowHitWork;

// Mons that react to a move, with their targets
typedef struct {
    u8 count;
    u8 monIds[6];
    u8 targets[6];
    u8 unk0D[6];
} BtlFlowReactionList;

// Client IDs the flow collected, such as those that must switch in
typedef struct {
    u8 count;
    u8 clientIds[4];
    u8 unk05;
} BtlFlowClientList;

struct BtlServerFlow {
    BtlServer *server;
    BtlMainModule *mainModule;
    BtlPokeCon *pokeCon;
    BtlServerCmdQueue *queue;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u8 unk1C[0x3c4];
    u8 unk3E0[0xc4];
    ArcTool *unk4A4;
    BattleMoveEffectState *moveEffect;
    BtlFlowReactionList *unk4AC;
    BtlFlowReactionList *unk4B0;
    BtlFlowHitWork *unk4B4;
    BtlClientIDList clientIdList;
    u8 unk4C0[0xe];
    BtlFlowClientList unk4CE;
    u8 unk4D4[0x2a0];
    u32 unk774;
    u32 unk778;
    u8 unk77C;
    u8 unk77D;
    u8 unk77E;
    u8 unk77F;
    HeapID heapId;
    u8 actionOrderCount;
    u8 unk783;
    u8 unk784;
    u8 unk785;
    u8 unk786;
    u8 unk787;
    u8 unk788;
    u8 unk789;
    u8 unk78A_0 : 1;
    u8 unk78A_1 : 1;
    u8 unk78A_2 : 1;
    u8 unk78A_3 : 1;
    u8 unk78A_4 : 1;
    u8 unk78A_5 : 1;
    u8 unk78A_6 : 1;
    u8 unk78A_7 : 1;
    u8 unk78B[0x1e];
    // Per mon ID, cleared when the mon is revived
    u8 unk7A9[24];
    u8 unk7C1[24];
    u8 unk7D9[4];
    u8 unk7DD[3];
    ActionOrderEntry actionOrder[6];
    // Where an entry is kept while the order is reshuffled
    ActionOrderEntry tempEntry;
    // Two mon sets in overlay 169's format: the move's targets, and a copy
    void *unk850;
    void *unk854;
    void *unk858;
    void *unk85C;
    void *unk860;
    void *unk864;
    void *unk868;
    BtlFlowDamageList *unk86C;
    BtlFlowDamageList *unk870;
    u8 unk874[0x11f4];
    // The mons that came in this turn, in overlay 169's format
    u8 unk1A68[0x48];
    BtlFlowMoveParam *unk1AB0;
    BtlFlowMoveParam *unk1AB4;
    // Passed to the ov169 function that several BattleHandler commands call through veneers
    u8 unk1ab8[0x2c];
    BattleHandlerString message;
    u8 unk1B0C[0x48];
    u8 unk1B54[0x224];
    BtlActionState actionState;
    u8 unk1D7C[0x1fc];
    u16 unk1F78;
    u8 unk1F7A[2];
    u32 unk1F7C;
    u8 unk1F80[0xc];
    u8 unk1F8C[0x60];
    u8 unk1FEC[4];
    u8 unk1FF0[0x144];
};

// Where the move goes, and its effect
struct BattleMoveEffectState {
    u16 unk00;
    u8 pos1;
    u8 pos2;
    u8 index;
    u8 enabled : 1;
    u8 unk05_1 : 1;
    u8 unk05_2 : 6;
};

struct BattleHandlerAbilityChangeParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u16 ability;
    u8 targetIndex;
    u8 force;
    u8 unk08;
    u8 unk09[3];
    BattleHandlerString string;
};

struct BattleHandlerAddConditionParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u32 condition;
    BattleCondition value;
    u8 unk0c;
    u8 unk0d[2];
    u8 targetIndex;
    u32 unk10;
    BattleHandlerString string;
};
struct BattleHandlerAddFieldEffectParam {
    u32 unk00;
    u32 effect;
    BattleCondition value;
    u8 duration;
    u8 unk0d[3];
    BattleHandlerString string;
};

struct BattleHandlerBatonPassParam {
    u32 unk00;
    u8 sourceMonIndex;
    u8 targetMonIndex;
};

struct BattleHandlerChangeFormParam {
    u32 unk00 : 23;
    u32 popup : 1;
    u32 unk18 : 8;
    u8 monIndex;
    u8 form;
    u8 unk06[2];
    BattleHandlerString string;
};

struct BattleHandlerChangeHPParam {
    u32 unk00;
    u8 count;
    u8 suppress;
    u8 skipReaction;
    u8 monIds[9];
    u32 hpChanges[6];
};

struct BattleHandlerChangeTypeParam {
    u32 unk00;
    u16 type;
    u8 monIndex;
    u8 suppressMessage;
};

struct BattleHandlerChangeWeatherParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u8 weather;
    u8 duration;
    u8 notifyAirLock;
    u8 unk07;
    BattleHandlerString string;
};

struct BattleHandlerCheckHeldItemParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05[3];
    u32 reaction;
};

struct BattleHandlerConsumeItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
    u32 skipDisplay;
    BattleHandlerString string;
};

struct BattleHandlerCureConditionParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 1;
    u32 unk25 : 1;
    u32 unk26 : 6;
    u32 condition;
    u8 monIds[12];
    u8 count;
    u8 useString;
    u8 unk16[2];
    BattleHandlerString string;
};

struct BattleHandlerRecoverHPParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u16 amount;
    u8 targetIndex;
    u8 unk07;
    BattleHandlerString string;
};

struct BattleHandlerDamageParam {
    u32 unk00 : 8;
    u32 sourceIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u16 amount;
    u8 targetIndex;
    u8 checkSemi : 1;
    u8 showViewEffect : 1;
    u8 unkFlags : 6;
    u16 effect;
    u8 effectArg1;
    u8 effectArg2;
    BattleHandlerString string;
};

struct BattleHandlerDecrementPPParam {
    u32 unk00;
    u8 amount;
    u8 monIndex;
    u8 moveIndex;
    u8 unk07 : 1;
    u8 allowFainted : 1;
    u8 unk09 : 6;
    BattleHandlerString string;
};

struct BattleHandlerDrainParam {
    u32 unk00;
    u16 amount;
    u8 monIndex;
    u8 sourceIndex;
    BattleHandlerString string;
};

struct BattleHandlerFaintParam {
    u32 unk00;
    u8 monIndex;
    u8 force;
    u8 unk06[2];
    BattleHandlerString string;
};

struct BattleHandlerFlagParam {
    u32 unk00;
    u32 flag;
    u8 monIndex;
};

struct BattleHandlerFlinchParam {
    u32 unk00;
    u8 monIndex;
    u8 flag;
};

struct BattleHandlerForceUseItemParam {
    u32 unk00 : 8;
    u32 monIndex2 : 5;
    u32 unk13 : 19;
    u8 monIndex;
    u8 unk05;
    u16 item;
};

struct BattleHandlerGravityCheckParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
};

struct BattleHandlerHideTurnParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05[3];
    u32 flag;
    BattleHandlerString string;
};

struct BattleHandlerIllusionBreakParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05[3];
    BattleHandlerString string;
};

struct BattleHandlerInterruptParam {
    u32 unk00;
    union {
        u8 monId;
        u16 moveId;
    };
    u16 unk06;
    BattleHandlerString string;
};

struct BattleHandlerMessageParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    BattleHandlerString string;
};

struct BattleHandlerMoveEffectParam {
    u8 unk00[4];
    u8 index;
};

struct BattleHandlerQuitBattleParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
};

struct BattleHandlerRecoverStatStageParam {
    u32 unk00;
    u8 monIndex;
};

struct BattleHandlerRemoveFieldEffectParam {
    u32 unk00;
    u32 effect;
};

struct BattleHandlerResetStatStageParam {
    u32 unk00;
    u8 count;
    u8 monIndices[6];
};

struct BattleHandlerReviveParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05;
    u16 amount;
    BattleHandlerString string;
};

struct BattleHandlerSetCounterParam {
    u32 unk00;
    u8 monIndex;
    u8 counter;
    u8 value;
};

struct BattleHandlerSetItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u16 item;
    u8 targetIndex;
    u8 clearConsumed;
    u8 clearOtherConsumed;
    u8 otherIndex;
    u8 unk0a[2];
    BattleHandlerString string;
};

struct BattleHandlerSetWeightParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05;
    u16 weight;
    BattleHandlerString string;
};

struct BattleHandlerStatChangeParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u32 stat;
    u32 value;
    s8 change;
    u8 flag;
    u8 unk0e;
    u8 count;
    u8 monIds[8];
    BattleHandlerString string;
};

struct BattleHandlerSwapItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u8 otherIndex;
    u8 unk05[3];
    BattleHandlerString firstString;
    BattleHandlerString secondString;
    BattleHandlerString thirdString;
};

struct BattleHandlerSwapPokeParam {
    u32 unk00;
    u8 firstMonIndex;
    u8 secondMonIndex;
    u8 unk06[2];
    BattleHandlerString string;
};

struct BattleHandlerSwitchParam {
    u32 unk00;
    BattleHandlerString firstString;
    BattleHandlerString secondString;
    u8 monIndex;
    u8 flag;
};

struct BattleHandlerTransformParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u8 targetIndex;
    u8 unk05[3];
    BattleHandlerString string;
};

struct BattleHandlerUseHeldItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
    u32 checkFullHp : 1;
    u32 allowFainted : 1;
    u32 unk22 : 30;
};

void BattleHandler_StrClear(BattleHandlerString *string);
BOOL BattleHandler_StrIsEnabled(BattleHandlerString *string);
void BattleHandler_StrSetup(BattleHandlerString *string, u32 enabled, u16 message);
void BattleHandler_AddArg(BattleHandlerString *string, u32 arg);
void BattleHandler_AddSoundEffect(BattleHandlerString *string, u32 soundEffect);

void *BattleHandler_PushWork(BtlServerFlow *flow, u32 command, u32 monId);
void BattleHandler_PushRun(BtlServerFlow *flow, u32 command, u32 monId);
void BattleHandler_PopWork(BtlServerFlow *flow, void *work);
u32 BattleHandler_Result(BtlServerFlow *handler);
void BattleHandler_Execute(BtlServerFlow *handler);

BOOL BattleHandler_SetTurnFlag(BtlServerFlow *handler, BattleHandlerFlagParam *param);
BOOL BattleHandler_ResetTurnFlag(BtlServerFlow *handler, BattleHandlerFlagParam *param);
BOOL BattleHandler_SetContinueFlag(BtlServerFlow *handler, BattleHandlerFlagParam *param);
BOOL BattleHandler_ResetContinueFlag(BtlServerFlow *handler, BattleHandlerFlagParam *param);
BOOL BattleHandler_InterruptAction(BtlServerFlow *handler, BattleHandlerInterruptParam *param);
u8 BattleHandler_InterruptMove(BtlServerFlow *handler, BattleHandlerInterruptParam *param);
BOOL BattleHandler_SendLast(BtlServerFlow *handler, BattleHandlerInterruptParam *param);
BOOL BattleHandler_SetString(BtlServerFlow *handler, BattleHandlerString *string);
BOOL BattleHandler_AbilityPopupRemove(BtlServerFlow *handler, BattleHandlerPopupParam *param);
BOOL BattleHandler_HideTurnCancel(BtlServerFlow *handler, BattleHandlerHideTurnParam *param);
BOOL BattleHandler_RemoveMessageWindow(BtlServerFlow *handler);
BOOL BattleHandler_ChangeForm(BtlServerFlow *handler, BattleHandlerChangeFormParam *param);
u8 BattleHandler_Flinch(BtlServerFlow *handler, BattleHandlerFlinchParam *param);
BOOL BattleHandler_SetWeight(BtlServerFlow *handler, BattleHandlerSetWeightParam *param);
BOOL BattleHandler_Revive(BtlServerFlow *handler, BattleHandlerReviveParam *param);
BOOL BattleHandler_SetCounter(BtlServerFlow *handler, BattleHandlerSetCounterParam *param);
BOOL BattleHandler_CheckHeldItem(BtlServerFlow *handler, BattleHandlerCheckHeldItemParam *param);
BOOL BattleHandler_UseHeldItem(BtlServerFlow *handler, BattleHandlerUseHeldItemParam *param);
BOOL BattleHandler_ConsumeItem(BtlServerFlow *handler, BattleHandlerConsumeItemParam *param);
BOOL BattleHandler_QuitBattle(BtlServerFlow *handler, BattleHandlerQuitBattleParam *param);
BOOL BattleHandler_Switch(BtlServerFlow *handler, BattleHandlerSwitchParam *param);
BOOL BattleHandler_AddFieldEffect(BtlServerFlow *handler, BattleHandlerAddFieldEffectParam *param);
BOOL BattleHandler_RemoveFieldEffect(BtlServerFlow *handler, BattleHandlerRemoveFieldEffectParam *param);
u8 BattleHandler_RecoverStatStage(BtlServerFlow *handler, BattleHandlerRecoverStatStageParam *param);
BOOL BattleHandler_ResetStatStage(BtlServerFlow *handler, BattleHandlerResetStatStageParam *param);
BOOL BattleHandler_Message(BtlServerFlow *handler, BattleHandlerMessageParam *param);
BOOL BattleHandler_DecrementPP(BtlServerFlow *handler, BattleHandlerDecrementPPParam *param);
BOOL BattleHandler_ForceUseItem(BtlServerFlow *handler, BattleHandlerForceUseItemParam *param);
BOOL BattleHandler_BatonPass(BtlServerFlow *handler, BattleHandlerBatonPassParam *param);
BOOL BattleHandler_IllusionBreak(BtlServerFlow *handler, BattleHandlerIllusionBreakParam *param);
BOOL BattleHandler_SwapPoke(BtlServerFlow *handler, BattleHandlerSwapPokeParam *param);
u8 BattleHandler_ChangeWeather(BtlServerFlow *handler, BattleHandlerChangeWeatherParam *param);
BOOL BattleHandler_GravityCheck(BtlServerFlow *handler, BattleHandlerGravityCheckParam *param);
BOOL BattleHandler_Transform(BtlServerFlow *handler, BattleHandlerTransformParam *param);
BOOL BattleHandler_SetItem(BtlServerFlow *handler, BattleHandlerSetItemParam *param);
BOOL BattleHandler_SwapItem(BtlServerFlow *handler, BattleHandlerSwapItemParam *param);
BOOL BattleHandler_Drain(BtlServerFlow *handler, BattleHandlerDrainParam *param);
u8 func_ov167_021ac988(void *state, u8 monIndex);
BOOL BattleHandler_Damage(BtlServerFlow *handler, BattleHandlerDamageParam *param);
BOOL BattleHandler_ChangeHP(BtlServerFlow *handler, BattleHandlerChangeHPParam *param);
BOOL BattleHandler_Faint(BtlServerFlow *handler, BattleHandlerFaintParam *param);
u8 func_ov167_021aca54(void *state, u8 monIndex);
u8 func_ov167_021acad4(void *state, u8 monIndex);
u8 func_ov167_021ad15c(void *state, u8 monIndex);
BOOL BattleHandler_ChangeType(BtlServerFlow *handler, BattleHandlerChangeTypeParam *param);
BOOL BattleHandler_AbilityChange(BtlServerFlow *handler, BattleHandlerAbilityChangeParam *param);
u8 func_ov167_021ad1f4(void *state, u8 monIndex);
BOOL func_ov167_021ad204(u16 species);
u8 HandlerGetAlivePartyCount(BtlServerFlow *handler, u16 code, u8 *monIds);
u8 func_ov167_021ab840(void *flow, u32 monId);
u8 *func_ov167_021abc60(void *flow, u32 value);
u8 func_ov167_021add78(void *state, u8 monIndex);
u8 func_ov167_021ae0fc(void *state, u8 monIndex);

BOOL BattleHandler_SetMoveEffectIndex(BtlServerFlow *handler, BattleHandlerMoveEffectParam *param);
BOOL BattleHandler_SetMoveEffectEnable(BtlServerFlow *handler);

#endif // POKEBW2_BATTLE_BTL_HANDLER_H
