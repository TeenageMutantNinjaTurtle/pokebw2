#include "field/bsubway_scr.h"
#include "pml/poke_party.h"
#include "save/bsubway_save.h"

void func_ov033_0217b790(BSubwayScrWork *bsw, GameSystem *gsys) {
    PokeParty *party;
    PartyPkm *pkm;
    s32 i;

    bsw->unk0[8] = func_ov033_0217bdc0(bsw->playMode);
    func_0200e11c(bsw->unk70, 5, bsw->unk1E);
    party = func_ov033_0217bd60(bsw);
    for (i = 0; i < bsw->unk0[8]; i++) {
        pkm = PokeParty_GetPkm(party, bsw->unk1E[i]);
        bsw->unk22[i] = PokeParty_GetParam(pkm, (PkmField)5, NULL);
        bsw->unk22[i + 4] = PokeParty_GetParam(pkm, (PkmField)6, NULL);
    }
}

void func_ov033_0217b7e8(BSubwayScrWork *bsw) {
    u8 value;

    value = bsw->playMode;
    func_0200e1ac(bsw->unk70, 0, &value);
    func_0200e2ac(bsw->unk70);
    func_0200e1ac(bsw->unk70, 5, bsw->unk1E);
    func_0200e100(bsw->unk70, 1);
    if (bsw->playMode == 2 || bsw->playMode == 7) {
        value = bsw->unkC_5;
        func_0200e1ac(bsw->unk70, 9, &value);
        func_0200e1ac(bsw->unk70, 6, bsw->unk628 + 20 * bsw->unkC_5);
        func_0200e1ac(bsw->unk70, 7, bsw->unk664 + bsw->unkC_5);
    }
}
