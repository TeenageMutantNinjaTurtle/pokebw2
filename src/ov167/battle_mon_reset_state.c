#include "battle/btl_pokeparam.h"

// Function names from swan.

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

void ClearUsedMoveFlag(BattleMon *mon) {
    u32 i;
    u8 *data;

    data = (u8 *)mon;
    for (i = 0; i < 4; i++) {
        func_ov167_021ba9cc(data + 0x104 + i * 14);
    }
    *(u16 *)(data + 0x14a) = 0;
    *(u16 *)(data + 0x14c) = 0;
    data[0x144] = 0x11;
    *(u16 *)(data + 0x14e) = 0;
}

void ClearCounter(BattleMon *mon) {
    u32 i;
    u8 *data;

    data = (u8 *)mon;
    for (i = 0; i < 5; i++) {
        data[0x157 + i] = 0;
    }
}
