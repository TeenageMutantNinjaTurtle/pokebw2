#include "field/mystery_gift_script.h"
#include "save/mystery_gift.h"

void *func_ov033_021783a8(void *save, u32 slot, void *gift) {
    u8 kind;

    if (!func_0200a800(save, slot)) {
        return NULL;
    }
    if (func_0200a820(save, slot) == 1) {
        return NULL;
    }
    if (!func_0200a71c(save, slot, gift)) {
        return NULL;
    }
    kind = *((u8 *)gift + 0xb3);
    if (kind == 0) {
        return NULL;
    }
    if (kind >= 5) {
        gift = NULL;
    }
    return gift;
}

void *func_ov033_021783f8(void *save, u32 *slot, void *gift) {
    s32 i;
    void *result;

    for (i = 0; i < 12; i++) {
        result = func_ov033_021783a8(save, i, gift);
        if (result != NULL) {
            *slot = i;
            return gift;
        }
    }
    return NULL;
}

void func_ov033_02178420(void *save, u32 slot) {
    func_0200a858(save, slot);
}

u32 func_ov033_02178428(void *save) {
    u32 slot;
    u8 gift[0xcc];
    void *result;

    result = func_ov033_021783f8(save, &slot, gift);
    if (result == NULL) {
        return 0;
    }
    return *((u8 *)result + 0xb3);
}
