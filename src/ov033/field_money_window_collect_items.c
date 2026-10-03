#include "field/field_money_window.h"
#include "gfl/heap.h"
#include "save/bag.h"
#include "system/game_data.h"

u32 *func_ov033_02177bd4(GameData *gameData, HeapID heapId, void *items, u32 *count) {
    u32 *result;
    BagSave *bag;
    u32 n;
    s32 i;
    u16 item;
    u16 quantity;

    bag = GameData_GetBag(gameData);
    result = GFL_HeapAllocate(heapId, 0x50, TRUE, data_ov033_0217c600, 0x14d);
    i = 0;
    n = 0;
    for (; i < 20; i++) {
        item = func_02009a18(items, i);
        quantity = func_02009a38(items, i);
        if (item != 0 && BagSave_CheckAvailItemSpace(bag, item, quantity, heapId) == TRUE) {
            ((u16 *)result)[n * 2] = item;
            ((u16 *)result)[n * 2 + 1] = quantity;
            n++;
        }
    }
    *count = n;
    return result;
}
