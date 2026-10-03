#ifndef POKEBW2_FIELD_FLD_TRADE_H
#define POKEBW2_FIELD_FLD_TRADE_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "struct_decls.h"

// Function and type names from swan; member layout reconstructed from the game code.
struct FieldTradeOfferData {
    u32 unk00;
    u32 species;
    u32 unk08;
    u32 unk0c;
    u32 unk10[6];
    u32 unk28;
    u32 unk2c;
    u32 unk30;
    u32 unk34;
    u32 unk38[6];
    u32 trainerGender;
    u32 unk54;
    u32 unk58;
    u32 wantedSpecies;
    u32 wantedSex;
    u32 unk64;
    u32 nameMessageId;
};

struct FieldTradeInput {
    HeapID heapId;
    u16 padding;
    u32 offerIndex;
    FieldTradeOfferData *offerData;
    void *tradeData;
    PlayerInfo *trainer;
};

extern const char data_ov033_0217c624[];

FieldTradeInput *FieldTradeInput_Create(u32 heapId, u32 offerIndex);
void FieldTradeInput_Free(FieldTradeInput *input);
u32 FieldTradeInput_GetSpecies(FieldTradeInput *input);
u32 FieldTradeInput_GetWantedSpecies(FieldTradeInput *input);
u32 FieldTradeInput_GetWantedSex(FieldTradeInput *input);
StrBuf *FieldTradeInput_LoadName(u32 heapId, u32 messageId);

#endif // POKEBW2_FIELD_FLD_TRADE_H
