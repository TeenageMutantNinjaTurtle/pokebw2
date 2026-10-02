#include "field/fld_trade.h"
#include "gfl/arc.h"
#include "gfl/msg.h"
#include "save/player_info.h"

FieldTradeInput *FieldTradeInput_Create(u32 heapId, u32 offerIndex) {
    u16 name[0x80];
    FieldTradeInput *input;
    StrBuf *nameBuf;

    input = GFL_HeapAllocate(heapId, sizeof(FieldTradeInput), TRUE, data_ov033_0217c624, 0x5f);
    input->heapId = heapId;
    input->offerIndex = offerIndex;
    input->offerData = GFL_ArcSysReadHeapNewRange(0xa3, offerIndex, heapId, 0, sizeof(FieldTradeOfferData));
    input->tradeData = GFL_HeapAllocate(heapId, 0xdc, FALSE, data_ov033_0217c624, 0x67);
    input->trainer = func_02008b0c(heapId);
    func_02008b40(input->trainer);
    nameBuf = FieldTradeInput_LoadName(heapId, input->offerData->nameMessageId);
    GFL_StrBufStoreString(nameBuf, name, 0x80);
    GFL_StrBufFree(nameBuf);
    copyTrainerName(input->trainer, name);
    setTrainerGender(input->trainer, input->offerData->trainerGender);
    return input;
}

void FieldTradeInput_Free(FieldTradeInput *input) {
    GFL_HeapFree(input->offerData);
    GFL_HeapFree(input->tradeData);
    GFL_HeapFree(input->trainer);
    GFL_HeapFree(input);
}

u32 FieldTradeInput_GetSpecies(FieldTradeInput *input) {
    return input->offerData->species;
}

u32 FieldTradeInput_GetWantedSpecies(FieldTradeInput *input) {
    return input->offerData->wantedSpecies;
}

u32 FieldTradeInput_GetWantedSex(FieldTradeInput *input) {
    return input->offerData->wantedSex;
}

StrBuf *FieldTradeInput_LoadName(u32 heapId, u32 messageId) {
    MsgData *msgData;
    StrBuf *name;

    msgData = GFL_MsgSysLoadData(FALSE, 2, 0x25, heapId);
    name = GFL_MsgDataLoadStrbufNew(msgData, messageId);
    GFL_MsgDataFree(msgData);
    return name;
}
