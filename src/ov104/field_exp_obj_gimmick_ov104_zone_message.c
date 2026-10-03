#include "field/field_exp_obj_gimmick_ov104.h"
#include "field/zone.h"
#include "gfl/msg.h"
#include "gfl/str.h"

void func_ov104_021ef43c(FieldExpObjGimmickOv104Work *work) {
    FieldExpObjGimmickOv104MessageArg arg;
    FieldExpObjGimmickOv104ZoneList list;
    u32 message;
    WordSet *wordSet;
    WordSet *formatSet;
    MsgData *placeMessages;
    MsgData *weatherMessages;
    StrBuf *placeName;
    StrBuf *weatherName;
    StrBuf *template;
    StrBuf *formatted;
    u32 length;
    s32 i;
    u8 weather;

    func_ov104_021efa18(work, &list);
    length = 4;
    length += 0xfc;
    wordSet = GFL_WordSetSystemCreate(4, length, work->heapId);
    placeMessages = GFL_MsgSysLoadData(0, 2, 0x6d, work->heapId);
    weatherMessages = GFL_MsgSysLoadData(0, 2, 0x2b, work->heapId);
    for (i = 0; i < 4; i++) {
        if (list.zones[i] == 0x267) {
            continue;
        }
        weather = list.weather[i];
        placeName = GFL_MsgDataLoadStrbufNew(placeMessages, ZoneData_GetPlaceNameID(list.zones[i]));
        weatherName = GFL_MsgDataLoadStrbufNew(weatherMessages, data_ov104_021f068c[weather]);
        formatSet = GFL_WordSetSystemCreate(2, length, work->heapId);
        template = GFL_MsgDataLoadStrbufNew(weatherMessages, 0xc0);
        formatted = GFL_StrBufCreate(0x40, work->heapId);
        func_0202437c(formatSet, 0, placeName, 0, 1, 0);
        func_0202437c(formatSet, 1, weatherName, 0, 1, 0);
        GFL_WordSetFormatStrbuf(formatSet, formatted, template);
        GFL_StrBufFree(template);
        GFL_WordSetSystemFree(formatSet);
        func_0202437c(wordSet, i, formatted, 0, 1, 0);
        GFL_StrBufFree(placeName);
        GFL_StrBufFree(weatherName);
        GFL_StrBufFree(formatted);
    }
    GFL_MsgDataFree(weatherMessages);
    GFL_MsgDataFree(placeMessages);
    switch (func_ov104_021ef9c8(&list)) {
    case 1:
        message = 0xc1;
        break;
    case 2:
        message = 0xc2;
        break;
    case 3:
        message = 0xc3;
        break;
    case 4:
        message = 0xc4;
        break;
    }
    arg.kind = *(u16 *)((u8 *)&data_ov104_021f0620 + 6);
    arg.unk04 = *(u32 *)((u8 *)&data_ov104_021f0620 + 0x18);
    arg.unk08 = *(u32 *)((u8 *)&data_ov104_021f0620 + 0x34);
    arg.unk0c = 2;
    arg.unk10 = 0x2b;
    arg.unk14 = message;
    arg.wordSet = wordSet;
    func_ov104_021ef28c(work, (u32)&arg, 2, 0);
    GFL_WordSetSystemFree(wordSet);
}
