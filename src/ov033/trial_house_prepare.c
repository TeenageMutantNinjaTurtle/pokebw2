#include "field/battle_facility.h"
#include "field/trial_house.h"
#include "gfl/random.h"

void func_ov033_0217adbc(TrialHouseWork *work, u32 selectionFlag) {
    work->selectionFlag = selectionFlag;
}

void func_ov033_0217adc4(GameSystem *gsys, TrialHouseWork *work, u32 mode) {
    if (work->selectionFlag != 0) {
        func_ov033_0217ae5c(gsys, work, mode);
    } else {
        func_ov033_0217ade8(work, mode);
    }
    func_ov033_0217aed0(work);
}

void func_ov033_0217ade8(TrialHouseWork *work, u32 mode) {
    u32 base;
    u32 range;
    u32 value;
    u16 flag;
    u32 zero;

    switch (mode) {
    case 0:
        base = 0x32;
        range = 0x14;
        break;
    case 1:
        base = 0x6e;
        range = 0x32;
        break;
    case 2:
        base = 0xa0;
        range = 0x14;
        break;
    case 3:
        base = 0xf0;
        range = 0x1e;
        break;
    case 4:
        base = 0x10e;
        range = 0x1e;
        break;
    default:
        base = 0x32;
        range = 0x14;
        break;
    }
    value = base + GFL_RandomLC(range);
    zero = 0;
    flag = (work->heapId & 0x7fff) | 0x8000;
    func_ov012_02162864(work, value, work->capacity, zero, zero, zero, flag);
}
