#include "field/field_money_window.h"
#include "save/bag.h"
#include "system/game_data.h"

void func_ov033_02177c48(GameData *gameData, HeapID heapId, void *items) {
    BagSave *bag;
    u32 i;
    u16 item;
    u16 quantity;

    bag = GameData_GetBag(gameData);
    for (i = 0; i < 20; i++) {
        item = func_02009a18(items, i);
        quantity = func_02009a38(items, i);
        if (item != 0 && BagSave_AddItem(bag, item, quantity, heapId) == TRUE) {
            func_02009a6c(items, i);
        }
    }
}
