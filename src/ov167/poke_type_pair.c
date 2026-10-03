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


struct SwitchModeState {
    void *actionManager;
    u8 unk04[7];
    u8 enabled;
};

struct BtlServerFlow {
    u8 unk00[0xc];
    BtlMainModule *mainModule;
    BtlPokeCon *pokeCon;
    u8 unk14[0xc];
    struct SwitchModeState switchMode;
    u8 unk2c[0xc88];
    u8 posList[6];
    u8 count;
};

struct ActionOrder {
    u8 unk00[0x782];
    u8 count;
    u8 unk783[0x5d];
    ActionOrderEntry entries[6];
};

struct BattleHandlerDrainParam {
    u32 unk00;
    u16 amount;
    u8 monIndex;
    u8 sourceIndex;
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

struct BattleHandlerChangeHPParam {
    u32 unk00;
    u8 count;
    u8 suppress;
    u8 skipReaction;
    u8 monIds[9];
    u32 hpChanges[6];
};

struct BattleHandlerDecrementPPParam {
    u32 unk00;
    u8 amount;
    u8 monIndex;
    u8 moveIndex;
    u8 unk07 : 1;
    u8 allowFainted : 1;
    u8 unk09 : 6;
    u8 string[0x28];
};

BOOL IsStatChangeValid(BattleMon *mon, u32 stat, s32 change);

struct BattleHandlerRecoverStatStageParam {
    u32 unk00;
    u8 monIndex;
};

struct BattleHandlerResetStatStageParam {
    u32 unk00;
    u8 count;
    u8 monIndices[6];
};

struct BattleHandlerFaintParam {
    u32 unk00;
    u8 monIndex;
    u8 force;
    u8 unk06[2];
    BattleHandlerString string;
};

struct BattleHandlerChangeTypeParam {
    u32 unk00;
    u16 type;
    u8 monIndex;
    u8 suppressMessage;
};

// Function names from swan.

struct BattleHandlerMessageParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u8 string[0x28];
};

struct BattleHandlerFlagParam {
    u32 unk00;
    u32 flag;
    u8 monIndex;
};

// Function names from swan.

struct BattleHandlerAddFieldEffectParam {
    u32 unk00;
    u32 effect;
    BattleCondition value;
    u8 duration;
    u8 unk0d[3];
    u8 string[0x28];
};

struct BattleHandlerRemoveFieldEffectParam {
    u32 unk00;
    u32 effect;
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

struct BattleHandlerAbilityChangeParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u16 ability;
    u8 targetIndex;
    u8 force;
    u8 unk08[4];
    BattleHandlerString string;
};

// Function names from swan.

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

struct BattleHandlerCheckHeldItemParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05[3];
    u32 reaction;
};

struct BattleHandlerUseHeldItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
    u32 checkFullHp : 1;
    u32 allowFainted : 1;
    u32 unk22 : 30;
};

struct BattleHandlerForceUseItemParam {
    u32 unk00 : 8;
    u32 monIndex2 : 5;
    u32 unk13 : 19;
    u8 monIndex;
    u8 unk05;
    u16 item;
};

struct BattleHandlerConsumeItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
    u32 skipDisplay;
    u8 string[0x28];
};

struct BattleHandlerSetCounterParam {
    u32 unk00;
    u8 monIndex;
    u8 counter;
    u8 value;
};

// Function names from swan.

struct BattleHandlerQuitBattleParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
};

struct BattleHandlerSwitchParam {
    u32 unk00;
    u8 firstString[0x28];
    u8 secondString[0x28];
    u8 monIndex;
    u8 flag;
};

struct BattleHandlerBatonPassParam {
    u32 unk00;
    u8 sourceMonIndex;
    u8 targetMonIndex;
};

// Function names from swan.

struct BattleHandlerFlinchParam {
    u32 unk00;
    u8 monIndex;
    u8 flag;
};

struct BattleHandlerReviveParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05;
    u16 amount;
    u8 string[0x28];
};

struct BattleHandlerSetWeightParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05;
    u16 weight;
    u8 string[0x28];
};

struct BattleHandlerInterruptParam {
    u32 unk00;
    union {
        u8 monId;
        u16 moveId;
    };
    u16 unk06;
    u8 string[0x28];
};

// Function names from swan.

struct BattleHandlerSwapPokeParam {
    u32 unk00;
    u8 firstMonIndex;
    u8 secondMonIndex;
    u8 unk06[2];
    BattleHandlerString string;
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

struct BattleHandlerIllusionBreakParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05[3];
    BattleHandlerString string;
};

// Function names from swan.

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
    u8 string[0x28];
};

struct BattleHandlerChangeFormParam {
    u32 unk00 : 23;
    u32 showAbility : 1;
    u32 unk18 : 8;
    u8 monIndex;
    u8 form;
    u8 unk06[2];
    u8 string[0x28];
};

struct BattleMoveEffectState {
    u8 unk00[4];
    u8 index;
    u8 enabled : 1;
    u8 unk05 : 7;
};

struct BattleHandlerMoveEffectParam {
    u8 unk00[4];
    u8 index;
};

struct BtlActionState {
    u32 useItemNo : 10;
    u32 unk10 : 18;
    u32 prevResult : 1;
    u32 result : 1;
    u32 used : 1;
    u32 unk31 : 1;
};





struct EventItemView {
    u32 unk00;
    struct EventItemView *next;
    u8 unk08[0x10];
    u32 flags;
};

struct EventDispatchView {
    u32 depth;
    struct EventItemView *first;
};

// Function names from swan.
extern const BattleEventHandlerEntry data_ov167_021d78d4[];

extern const BattleEventHandlerEntry data_ov167_021d78cc[];

extern const BattleEventHandlerEntry data_ov167_021d78c4[];

struct BtlvStringParam {
    u16 message;
    u8 mode;
    u8 type : 4;
    u8 count : 4;
    u32 args[9];
};

// Function name from swan.
PokeTypePair PokeTypePair_Make(u32 type1, u32 type2) {
    u32 first;
    u32 second;

    first = (type1 << 24) >> 16;
    second = (type2 << 24) >> 24;
    return (u16)(first | second);
}

PokeTypePair func_ov167_021ce530(u32 type) {
    return PokeTypePair_Make(type, type);
}

u8 PokeTypePair_GetType1(PokeTypePair pair) {
    return (u8)(pair >> 8);
}

u8 PokeTypePair_GetType2(PokeTypePair pair) {
    return (u8)pair;
}

void func_ov167_021ce54c(PokeTypePair pair, u8 *type1, u8 *type2) {
    *type1 = PokeTypePair_GetType1(pair);
    *type2 = PokeTypePair_GetType2(pair);
}

BOOL func_ov167_021ce564(PokeTypePair pair, u32 type) {
    if (PokeTypePair_GetType1(pair) == type) {
        return TRUE;
    }
    if (PokeTypePair_GetType2(pair) == type) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov167_021ce588(PokeTypePair first, PokeTypePair second) {
    if (PokeTypePair_GetType1(first) == PokeTypePair_GetType1(second)) {
        return TRUE;
    }
    if (PokeTypePair_GetType1(first) == PokeTypePair_GetType2(second)) {
        return TRUE;
    }
    if (PokeTypePair_GetType2(first) == PokeTypePair_GetType1(second)) {
        return TRUE;
    }
    if (PokeTypePair_GetType2(first) == PokeTypePair_GetType2(second)) {
        return TRUE;
    }
    return FALSE;
}

BOOL PokeTypePair_IsMonotype(PokeTypePair pair) {
    return PokeTypePair_GetType1(pair) == PokeTypePair_GetType2(pair);
}
