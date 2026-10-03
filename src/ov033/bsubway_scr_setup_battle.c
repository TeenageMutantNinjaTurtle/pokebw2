#include "field/battle_facility.h"
#include "field/bsubway_scr.h"
#include "gfl/heap.h"
#include "pml/poke_party.h"

BtlSetup *func_ov033_0217c094(BSubwayScrWork *bsw, GameSystem *gsys) {
    PokeParty *party;
    PokeParty *source;
    PartyPkm *pkm;
    BtlSetup *result;
    s32 i;

    party = PokeParty_Create(0x8004);
    source = func_ov033_0217bd60(bsw);
    PokeParty_InitCore(party, bsw->unk0[8]);
    for (i = 0; i < bsw->unk0[8]; i++) {
        pkm = PokeParty_GetPkm(source, bsw->unk1E[i]);
        PokeParty_AddPkm(party, pkm);
    }
    result =
        SetupTrialHouseBattle(gsys, party, bsw->playMode, bsw->unk88, bsw->unk2C8 + 0x120 * bsw->unkC_5, bsw->unk0[8]);
    GFL_HeapFree(party);
    return result;
}
