#include "field/encounter.h"
#include "field/field_exp_obj_gimmick_ov104.h"
#include "field/zone.h"
#include "gfl/msg.h"
#include "gfl/str.h"
#include "system/game_data.h"

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
