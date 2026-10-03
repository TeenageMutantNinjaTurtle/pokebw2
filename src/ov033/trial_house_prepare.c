#include "field/battle_facility.h"
#include "field/trial_house.h"
#include "gfl/heap.h"
#include "gfl/random.h"
#include "save/save_control.h"
#include "save/trial_house.h"
#include "system/game_data.h"
#include "system/game_system.h"

struct TrialHouseCopyBlock {
    u32 words[0x48];
};

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

void func_ov033_0217ae5c(GameSystem *gsys, TrialHouseWork *work, u32 mode) {
    SaveControl *save;
    void *buffer;
    void *extra;
    TrialHouseCopyBlock *source;
    u32 size;

    save = GameData_GetSaveControl(GSYS_GetGameData(gsys));
    size = 0x800;
    buffer = GFL_HeapAllocate(0x8004, size, TRUE, data_ov033_0217c630, 0x14c);
    if (func_02007560(save, 5, 0x8004, buffer, size) == 1) {
        extra = getAddressOfExtraSaveBlk(save, 5, 0);
        source = func_0200ee90(extra, mode);
        *(TrialHouseCopyBlock *)work = *source;
    }
    freeIntermediateSaveExtraBlksAfterLoad2(save, 5);
    GFL_HeapFree(buffer);
}
