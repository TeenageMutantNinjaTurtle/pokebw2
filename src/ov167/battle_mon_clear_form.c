#include "battle/btl_pokeparam.h"

struct BattleMonFormView {
    void *src;
    u8 unk04[0x17];
    u8 unk1b_0 : 5;
    u8 formChange : 1;
    u8 unk1b_6 : 2;
};

// Function name from swan.
void ClearFormChange(BattleMon *mon) {
    struct BattleMonFormView *view;

    view = (struct BattleMonFormView *)mon;
    if (view->formChange) {
        setupBySrcData(mon, view->src, 0, 1);
        MoveWork_ClearSurface(mon);
        view->formChange = 0;
    }
}
