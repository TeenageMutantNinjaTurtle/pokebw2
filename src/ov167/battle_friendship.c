#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_setup.h"
#include "pml/poke_party.h"

struct FriendshipFieldEffectData {
    u8 unk00[0xa];
    u16 zoneId;
};

// Function names from swan.
void ChangeFriendshipWhenFainted(BtlMainModule *mainModule, BattleMon *mon, BOOL reason) {
    if (mainModule->setup->battleType <= 1 && mainModule->setup->unk23 == 0) {
        ChangeFriendship(mainModule, mon, reason ? 5 : 4);
    }
}

void ChangeFriendship(BtlMainModule *mainModule, BattleMon *mon, u32 reason) {
    u8 monId;
    const void *param1;
    const void *param2;
    PartyPkm *src1;
    PartyPkm *src2;
    const struct FriendshipFieldEffectData *field;

    monId = GetMonID(mon);
    // Two per-mon parameter sets live at these offsets in the battle module.
    param1 = GetPokeParamConst((u8 *)mainModule + 0x1b0, monId);
    param2 = GetPokeParamConst((u8 *)mainModule + 0xc8, monId);
    src1 = GetSrcData(param1);
    src2 = GetSrcData(param2);
    field = GetFieldEffectData(mainModule);
    FriendshipManagerCalc(src1, reason, field->zoneId, (u16)((mainModule->heapId & 0x7fff) | 0x8000));
    FriendshipManagerCalc(src2, reason, field->zoneId, (u16)((mainModule->heapId & 0x7fff) | 0x8000));
}
