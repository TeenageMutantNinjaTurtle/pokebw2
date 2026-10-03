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
extern const BattleEventHandlerEntry data_ov167_021d78d4[];

extern const BattleEventHandlerEntry data_ov167_021d78cc[];

extern const BattleEventHandlerEntry data_ov167_021d78c4[];

// Function names from swan.
void Btlv_StringParam_Setup(BtlvStringParam *param, u32 type, u16 message) {
    u32 i;

    for (i = 0; i < 9; i++) {
        param->args[i] = 0;
    }
    param->count = 0;
    param->message = message;
    param->type = type;
    param->mode = 0x50;
}

void Btlv_StringParam_AddArg(BtlvStringParam *param, u32 arg) {
    u8 count;

    count = param->count;
    if (count < 9) {
        param->count = count + 1;
        param->args[count] = arg;
    }
}
