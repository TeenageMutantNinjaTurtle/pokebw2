#include "field/field_money_window.h"
#include "save/bag.h"
#include "system/game_data.h"

u32 func_ov033_02177c8c(GameData *gameData, HeapID heapId, void *items) {
    BagSave *bag;
    u32 i;
    u32 count;
    u16 item;
    u16 quantity;

    bag = GameData_GetBag(gameData);
    i = 0;
    count = 0;
    for (; i < 20; i++) {
        item = func_02009a18(items, i);
        quantity = func_02009a38(items, i);
        if (item != 0 && BagSave_CheckAvailItemSpace(bag, item, quantity, heapId) == FALSE) {
            count++;
        }
    }
    return count;
}
