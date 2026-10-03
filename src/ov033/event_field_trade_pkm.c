#include "field/event_field_trade.h"
#include "gfl/str.h"
#include "pml/poke_party.h"
#include "system/game_data.h"

void EventFieldTrade_CreatePkm(GameData *gameData, HeapID heapId, PartyPkm *pkm, const FieldTradeOfferData *offer,
                               u32 offerIndex) {
    u32 sexMode = offer->unk30;
    u32 pid;
    u32 zero = 0;
    StrBuf *name;

    if (sexMode == 0xff) {
        sexMode = 2;
    }
    pid = PML_GenPID(offer->unk34, (u16)offer->species, (u16)offer->unk08, sexMode, offer->unk28, zero);
    PokeParty_CreatePkm(pkm, (u16)offer->species, (u16)offer->unk0c, offer->unk34, zero, -1, pid, zero);
    PokeParty_SetParam(pkm, 0x6f, offer->unk08);
    EventFieldTrade_DebugLogPkm(pkm);

    name = FieldTradeInput_LoadName(heapId, offer->unk64);
    PokeParty_SetParam(pkm, 0x73, (u32)name);
    GFL_StrBufFree(name);

    if (offer->unk10[0] != 0xff) {
        PokeParty_SetParam(pkm, 0x46, offer->unk10[0]);
    }
    if (offer->unk10[1] != 0xff) {
        PokeParty_SetParam(pkm, 0x47, offer->unk10[1]);
    }
    if (offer->unk10[2] != 0xff) {
        PokeParty_SetParam(pkm, 0x48, offer->unk10[2]);
    }
    if (offer->unk10[3] != 0xff) {
        PokeParty_SetParam(pkm, 0x49, offer->unk10[3]);
    }
    if (offer->unk10[4] != 0xff) {
        PokeParty_SetParam(pkm, 0x4a, offer->unk10[4]);
    }
    if (offer->unk10[5] != 0xff) {
        PokeParty_SetParam(pkm, 0x4b, offer->unk10[5]);
    }
    if (offer->unk28 == 2) {
        PokeParty_SetHiddenAbil(pkm, offer->species, offer->unk08);
    }
    if (offer->unk2c != 0xff) {
        PokeParty_SetParam(pkm, 0x70, offer->unk2c);
    }

    PokeParty_SetParam(pkm, 0x13, offer->unk38[0]);
    PokeParty_SetParam(pkm, 0x14, offer->unk38[1]);
    PokeParty_SetParam(pkm, 0x15, offer->unk38[2]);
    PokeParty_SetParam(pkm, 0x16, offer->unk38[3]);
    PokeParty_SetParam(pkm, 0x17, offer->unk38[4]);
    PokeParty_SetParam(pkm, 0x6, offer->unk38[5]);

    name = FieldTradeInput_LoadName(heapId, offer->nameMessageId);
    PokeParty_SetParam(pkm, 0x8d, (u32)name);
    GFL_StrBufFree(name);
    PokeParty_SetParam(pkm, 0x9a, offer->trainerGender);
    PokeParty_SetParam(pkm, 0xc, offer->unk58);
    PokeParty_SetupMetData(pkm, 1, GetGameDataPlayerInfo(gameData), 0x7532, heapId);
    PokeParty_SetParam(pkm, 9, 0x46);
    EventFieldTrade_DebugLogPkm(pkm);
    PokeParty_RecalcStats(pkm);
}
