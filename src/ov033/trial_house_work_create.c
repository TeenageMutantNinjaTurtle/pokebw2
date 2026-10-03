#include "field/trial_house.h"
#include "gfl/heap.h"
#include "pml/poke_party.h"
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
