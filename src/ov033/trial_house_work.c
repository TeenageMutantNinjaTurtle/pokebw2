#include "field/trial_house.h"
#include "gfl/heap.h"
#include "pml/poke_party.h"
#include "save/save_control.h"
#include "save/trial_house.h"
#include "system/game_data.h"
#include "system/game_system.h"

struct TrialHouseWork *CreateTrialHouseWk(GameSystem *gsys) {
    u32 saveSize = func_0200ee20();
    GameData *gameData = GSYS_GetGameData(gsys);
    struct TrialHouseWork *work;

    GameData_GetSaveControl(gameData);
    work = GFL_HeapAllocate(HEAPID_TRIAL_HOUSE, sizeof(struct TrialHouseWork), TRUE, data_ov033_0217c630, 0x5d);
    work->heapId = HEAPID_TRIAL_HOUSE;
    work->saveBuffer = GFL_HeapAllocate(HEAPID_TRIAL_HOUSE, saveSize, TRUE, data_ov033_0217c630, 0x5f);
    func_ov033_0217acd4(gsys, work);
    work->party = PokeParty_Create(work->heapId);
    return work;
}

void func_ov033_0217acd4(GameSystem *gsys, TrialHouseWork *work) {
    u32 size;
    SaveControl *save;
    void *buffer;
    void *extraSave;
    BOOL check;

    save = GameData_GetSaveControl(GSYS_GetGameData(gsys));
    size = 0x800;
    buffer = GFL_HeapAllocate(0x8004, size, TRUE, data_ov033_0217c630, 0x79);
    func_02007560(save, 5, 0x8004, buffer, size);
    extraSave = getAddressOfExtraSaveBlk(save, 5, 0);
    size = 0;
    if (func_0200ee38(extraSave)) {
        check = func_0200ee64(extraSave);
        size = 1;
        if (!check) {
            size = 2;
        }
    }
    freeIntermediateSaveExtraBlksAfterLoad2(save, 5);
    GFL_HeapFree(buffer);
    work->initState = size;
}

void TrialHouseWorkDelete(void *unused, struct TrialHouseWork **workPtr) {
    if (*workPtr != NULL) {
        GFL_HeapFree((*workPtr)->saveBuffer);
        GFL_HeapFree((*workPtr)->party);
        GFL_HeapFree(*workPtr);
        *workPtr = NULL;
    }
}
