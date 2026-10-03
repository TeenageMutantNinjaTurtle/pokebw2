#include "battle/btl_field.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

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

// Function names from swan.
BOOL BattleHandler_AddFieldEffect(BattleHandler *handler, BattleHandlerAddFieldEffectParam *param) {
    if (ServerControl_FieldEffectCore(handler, param->effect, param->value, param->duration)) {
        BattleHandler_SetString(handler, (BattleHandlerString *)param->string);
        return TRUE;
    }
    return FALSE;
}

BOOL BattleHandler_RemoveFieldEffect(BattleHandler *handler, BattleHandlerRemoveFieldEffectParam *param) {
    if (FieldStatusRemoveEffect(param->effect)) {
        ServerControl_FieldEffectEnd(handler, param->effect);
        return TRUE;
    }
    return FALSE;
}
