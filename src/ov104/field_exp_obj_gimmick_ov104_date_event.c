#include "field/field_exp_obj_gimmick_ov104.h"
#include "gfl/str.h"
#include "system/rtc.h"

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
