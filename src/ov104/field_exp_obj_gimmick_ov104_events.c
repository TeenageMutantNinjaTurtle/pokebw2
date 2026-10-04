#include "field/encounter.h"
#include "field/field.h"
#include "field/field_exp_obj_gimmick_ov104.h"
#include "field/zone.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/str.h"
#include "save/event_work.h"
#include "system/game_data.h"
#include "system/rtc.h"
#include "system/wordset.h"

void func_ov104_021ef114(FieldExpObjGimmickOv104Work *work) {
    s32 count;
    s32 i;

    if (work->resList == 0) {
        count = GFL_ArcSysGetDataMax(0xa4);
        work->resList = GFL_HeapAllocate(work->heapId, count * sizeof(struct FieldExpObjGimmickOv104ResEntry), FALSE,
                                         data_ov104_021f078c, 0x4b5);
        for (i = 0; i < count; i++) {
            func_ov104_021f0324(&work->resList[i], 0xa4, i);
        }
        work->resCount = count;
    }
}

void func_ov104_021ef168(FieldExpObjGimmickOv104Work *work) {
    if (work->resList != 0) {
        GFL_HeapFree(work->resList);
        work->resList = 0;
        work->resCount = 0;
    }
}

struct FieldExpObjGimmickOv104ResEntry *func_ov104_021ef180(FieldExpObjGimmickOv104Work *work) {
    u16 zone;
    EventWork *eventWork;
    s32 i;
    s32 offset;
    BOOL flag;
    BOOL zoneMatch;

    zone = Field_GetPlayerStateZoneID(work->field);
    eventWork = GameData_GetEventWork(work->gameData);
    if (work->resList == 0) {
        return 0;
    }
    for (i = 0; i < work->resCount; i++) {
        offset = i * 0x24;
        flag = EventWork_FlagGet(eventWork, (u16) * (u32 *)((u8 *)work->resList + offset + 4));
        zoneMatch = func_ov104_021f0334((struct FieldExpObjGimmickOv104ResEntry *)((u8 *)work->resList + offset), zone);
        if (func_ov104_021f037c((struct FieldExpObjGimmickOv104ResEntry *)((u8 *)work->resList + offset)) && flag &&
            zoneMatch) {
            return (struct FieldExpObjGimmickOv104ResEntry *)((u8 *)work->resList + offset);
        }
    }
    return 0;
}

struct FieldExpObjGimmickOv104ResEntry *func_ov104_021ef204(FieldExpObjGimmickOv104Work *work) {
    u16 zone;
    EventWork *eventWork;
    s32 i;
    s32 offset;
    struct FieldExpObjGimmickOv104ResEntry *entry;
    BOOL flag;
    BOOL zoneMatch;

    zone = Field_GetPlayerStateZoneID(work->field);
    eventWork = GameData_GetEventWork(work->gameData);
    if (work->resList == 0) {
        return 0;
    }
    for (i = 0; i < work->resCount; i++) {
        offset = i * 0x24;
        flag = EventWork_FlagGet(eventWork, (u16) * (u32 *)((u8 *)work->resList + offset + 4));
        zoneMatch = func_ov104_021f0334((struct FieldExpObjGimmickOv104ResEntry *)((u8 *)work->resList + offset), zone);
        if (flag && zoneMatch) {
            entry = (struct FieldExpObjGimmickOv104ResEntry *)((u8 *)work->resList + offset);
            if (*(u32 *)((u8 *)entry + 0x10) == 2) {
                return entry;
            }
        }
    }
    return 0;
}

u32 func_ov104_021ef278(FieldExpObjGimmickOv104Work *work) {
    if (func_ov104_021ef180(work) != 0) {
        return 1;
    }
    return 0;
}

void func_ov104_021ef28c(FieldExpObjGimmickOv104Work *work, u32 message, u32 kind, void *arg) {
    func_ov104_021efc6c(work->state, (FieldExpObjGimmickOv104MessageArg *)message);
    if (kind == 8) {
        func_ov104_021ef02c(work, kind, *(u32 *)((u8 *)arg + 4));
    } else {
        func_ov104_021ef02c(work, kind, 0);
    }
    if (kind == 8 && *(u32 *)((u8 *)arg + 8) == 1) {
        EventWork_FlagReset(GameData_GetEventWork(work->gameData), (u16) * (u32 *)((u8 *)arg + 4));
    }
}

void func_ov104_021ef2cc(FieldExpObjGimmickOv104Work *work) {
    if (func_ov104_021ef04c(work) == 1) {
        func_ov104_021ef344(work);
        return;
    }
    if (func_ov104_021ef278(work) != 0) {
        func_ov104_021ef380(work);
        return;
    }
    func_ov104_021ef2fc(work);
}

void func_ov104_021ef2fc(FieldExpObjGimmickOv104Work *work) {
    if (!func_ov104_021efcf8(work->state) && work->substate && work->substate->enabled) {
        func_ov104_021ef5ac(work);
        func_ov104_021ef3c0(work);
        func_ov104_021ef43c(work);
        func_ov104_021ef658(work);
        func_ov104_021ef6dc(work);
        func_ov104_021ef760(work);
        func_ov104_021ef7e4(work);
    }
}

void func_ov104_021ef344(FieldExpObjGimmickOv104Work *work) {
    if (!func_ov104_021efcf8(work->state) && work->substate && work->substate->enabled) {
        func_ov104_021ef5ac(work);
        func_ov104_021ef3c0(work);
        func_ov104_021ef43c(work);
        func_ov104_021ef868(work);
        func_ov104_021ef7e4(work);
    }
}

void func_ov104_021ef380(FieldExpObjGimmickOv104Work *work) {
    if (!func_ov104_021efcf8(work->state) && work->resList && work->substate && work->substate->enabled) {
        func_ov104_021ef924(work);
        func_ov104_021ef5ac(work);
        func_ov104_021ef3c0(work);
        func_ov104_021ef43c(work);
        func_ov104_021ef7e4(work);
    }
}

void func_ov104_021ef3c0(FieldExpObjGimmickOv104Work *work) {
    WordSet *wordSet;
    FieldExpObjGimmickOv104MessageArg arg;
    RTCDate date;

    wordSet = GFL_WordSetSystemCreateDefault(work->heapId);
    func_0207cc10(&date);
    WordSetNumber(wordSet, 2, date.year, 2, 2, 1);
    loadMonthToStrbuf(wordSet, 0, date.month);
    WordSetNumber(wordSet, 1, date.day, 2, 0, 1);
    arg.kind = *(u16 *)((u8 *)&data_ov104_021f0620 + 4);
    arg.unk04 = *(u32 *)((u8 *)&data_ov104_021f0620 + 0x14);
    arg.unk08 = *(u32 *)((u8 *)&data_ov104_021f0620 + 0x30);
    arg.unk0c = 2;
    arg.unk10 = 0x2b;
    arg.unk14 = *(u32 *)&work->substate->unk18[0];
    arg.wordSet = wordSet;
    func_ov104_021ef28c(work, (u32)&arg, 1, 0);
    GFL_WordSetSystemFree(wordSet);
}

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

void func_ov104_021ef5ac(FieldExpObjGimmickOv104Work *work) {
    u16 zone;
    WordSet *wordSet;
    MsgData *msgData;
    StrBuf *zoneName;
    FieldExpObjGimmickOv104MessageArg arg;

    zone = getSwarmLevelRangeFromData(work->gameData);
    if (zone == 0xffff || (zone == 0x159 && GameData_GetSeason(work->gameData) == 3)) {
        return;
    }
    wordSet = GFL_WordSetSystemCreateDefault(work->heapId);
    msgData = GFL_MsgSysLoadData(0, 2, 0x6d, work->heapId);
    zoneName = GFL_MsgDataLoadStrbufNew(msgData, ZoneData_GetPlaceNameID(zone));
    func_0202437c(wordSet, 0, zoneName, 0, 1, 0);
    GFL_StrBufFree(zoneName);
    GFL_MsgDataFree(msgData);
    arg.kind = *(u16 *)((u8 *)&data_ov104_021f0620 + 8);
    arg.unk04 = *(u32 *)((u8 *)&data_ov104_021f0620 + 0x1c);
    arg.unk08 = *(u32 *)((u8 *)&data_ov104_021f0620 + 0x38);
    arg.unk0c = 2;
    arg.unk10 = 0x2b;
    arg.unk14 = *(u32 *)&work->substate->unk18[8];
    arg.wordSet = wordSet;
    func_ov104_021ef28c(work, (u32)&arg, 3, 0);
    GFL_WordSetSystemFree(wordSet);
}

void func_ov104_021ef658(FieldExpObjGimmickOv104Work *work) {
    FieldExpObjGimmickOv104MessageArg arg;
    RTCDate date;

    func_0207cc10(&date);
    switch (date.week) {
    case 0:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x24];
        break;
    case 1:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x18];
        break;
    case 2:
        arg.unk14 = *(u32 *)&work->substate->unk18[0xc];
        break;
    case 3:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x1c];
        break;
    case 4:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x10];
        break;
    case 5:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x20];
        break;
    case 6:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x14];
        break;
    }
    arg.kind = *(u16 *)((u8 *)&data_ov104_021f0620 + 0xa);
    arg.unk04 = *(u32 *)((u8 *)&data_ov104_021f0620 + 0x20);
    arg.unk08 = *(u32 *)((u8 *)&data_ov104_021f0620 + 0x3c);
    arg.unk0c = 2;
    arg.unk10 = 0x2b;
    arg.wordSet = 0;
    func_ov104_021ef28c(work, (u32)&arg, 4, 0);
}

void func_ov104_021ef6dc(FieldExpObjGimmickOv104Work *work) {
    FieldExpObjGimmickOv104MessageArg arg;
    RTCDate date;

    func_0207cc10(&date);
    switch (date.week) {
    case 0:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x28];
        break;
    case 1:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x1c];
        break;
    case 2:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x10];
        break;
    case 3:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x20];
        break;
    case 4:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x14];
        break;
    case 5:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x24];
        break;
    case 6:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x18];
        break;
    }
    arg.kind = *(u16 *)((u8 *)&data_ov104_021f0620 + 0xc);
    arg.unk04 = *(u32 *)((u8 *)&data_ov104_021f0620 + 0x24);
    arg.unk08 = *(u32 *)((u8 *)&data_ov104_021f0620 + 0x40);
    arg.unk0c = 2;
    arg.unk10 = 0x2b;
    arg.wordSet = 0;
    func_ov104_021ef28c(work, (u32)&arg, 5, 0);
}

void func_ov104_021ef760(FieldExpObjGimmickOv104Work *work) {
    FieldExpObjGimmickOv104MessageArg arg;
    RTCDate date;

    func_0207cc10(&date);
    switch (date.week) {
    case 0:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x2c];
        break;
    case 1:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x20];
        break;
    case 2:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x14];
        break;
    case 3:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x24];
        break;
    case 4:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x18];
        break;
    case 5:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x28];
        break;
    case 6:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x1c];
        break;
    }
    arg.kind = *(u16 *)((u8 *)&data_ov104_021f0620 + 0xe);
    arg.unk04 = *(u32 *)((u8 *)&data_ov104_021f0620 + 0x28);
    arg.unk08 = *(u32 *)((u8 *)&data_ov104_021f0620 + 0x44);
    arg.unk0c = 2;
    arg.unk10 = 0x2b;
    arg.wordSet = 0;
    func_ov104_021ef28c(work, (u32)&arg, 6, 0);
}

void func_ov104_021ef7e4(FieldExpObjGimmickOv104Work *work) {
    FieldExpObjGimmickOv104MessageArg arg;
    RTCDate date;

    func_0207cc10(&date);
    switch (date.week) {
    case 0:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x48];
        break;
    case 1:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x30];
        break;
    case 2:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x34];
        break;
    case 3:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x38];
        break;
    case 4:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x3c];
        break;
    case 5:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x40];
        break;
    case 6:
        arg.unk14 = *(u32 *)&work->substate->unk18[0x44];
        break;
    }
    arg.kind = *(u16 *)((u8 *)&data_ov104_021f0620 + 0x10);
    arg.unk04 = *(u32 *)((u8 *)&data_ov104_021f0620 + 0x2c);
    arg.unk08 = *(u32 *)((u8 *)&data_ov104_021f0620 + 0x48);
    arg.unk0c = 2;
    arg.unk10 = 0x2b;
    arg.wordSet = 0;
    func_ov104_021ef28c(work, (u32)&arg, 7, 0);
}

void func_ov104_021ef868(FieldExpObjGimmickOv104Work *work) {
    s32 count;
    FieldExpObjGimmickOv104MessageArg arg;
    u32 species[6];
    WordSet *wordSet;
    const u32 *data;
    u32 message;
    s32 i;

    wordSet = GFL_WordSetSystemCreateDefault(func_ov104_021efcf4(work->state));
    func_ov104_021ef084(work, species, &count);
    switch (count) {
    case 1:
        message = 0xcd;
        break;
    case 2:
        message = 0xce;
        break;
    case 3:
        message = 0xcf;
        break;
    case 4:
        message = 0xd0;
        break;
    case 5:
        message = 0xd1;
        break;
    case 6:
        message = 0xd2;
        break;
    }
    for (i = 0; i < count; i++) {
        WordSet_LoadSpeciesName(wordSet, i, (u16)species[i]);
    }
    copyVarForText(wordSet, 6, GetGameDataPlayerInfo(work->gameData));
    data = &data_ov104_021f0620;
    arg.kind = ((const u16 *)data)[5];
    arg.unk04 = data[8];
    arg.unk08 = data[15];
    arg.unk0c = 2;
    arg.unk10 = 0x2b;
    arg.unk14 = message;
    arg.wordSet = wordSet;
    func_ov104_021ef28c(work, (u32)&arg, 9, 0);
    GFL_WordSetSystemFree(wordSet);
}

void func_ov104_021ef924(FieldExpObjGimmickOv104Work *work) {
    struct FieldExpObjGimmickOv104ResEntry *entry;

    entry = func_ov104_021ef180(work);
    switch (entry->type) {
    case 0:
        func_ov104_021ef94c(work, entry, 3);
        break;
    case 2:
        func_ov104_021ef994(work);
        break;
    }
}