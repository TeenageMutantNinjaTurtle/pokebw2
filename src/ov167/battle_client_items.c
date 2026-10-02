#include "battle/btl_main.h"
#include "battle/btl_setup.h"
#include "save/bag.h"

// Function names from swan.
void BattleClient_SubItem(BtlMainModule *mainModule, u8 clientId, u16 item) {
    BtlSetup *setup;

    setup = mainModule->setup;
    if (setup->unk23 == 0 && clientId == mainModule->playerClientId) {
        BagSave_SubItem(setup->bag, item, 1, mainModule->heapId);
    }
}

void BattleClient_AddItem(BtlMainModule *mainModule, u8 clientId, u16 item) {
    BtlSetup *setup;

    setup = mainModule->setup;
    if (setup->unk23 == 0 && clientId == mainModule->playerClientId) {
        BagSave_AddItem(setup->bag, item, 1, mainModule->heapId);
    }
}
