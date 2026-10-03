#include "battle/btl_action_order.h"
#include "battle/btl_pokeparam.h"

struct ActionOrder {
    u8 unk00[0x782];
    u8 count;
    u8 unk783[0x5d];
    ActionOrderEntry entries[6];
};

// Function name from swan.
ActionOrderEntry *ActionOrder_SearchByMonID(ActionOrder *order, u8 monId) {
    u32 i;

    for (i = 0; i < order->count; i++) {
        if (GetMonID(order->entries[i].mon) == monId) {
            return &order->entries[i];
        }
    }
    return NULL;
}
