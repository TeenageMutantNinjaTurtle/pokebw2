#include "field/field_exp_obj_gimmick_ov104.h"
#include "system/rtc.h"

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
