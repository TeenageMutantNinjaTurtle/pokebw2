#include "types.h"

typedef struct {
    u16 unk0;
    u16 unk2;
} U16Pair;

typedef struct {
    u8 count;
    u16 *keys;
    u8 *values;
} U16ToU8Table;

typedef struct {
    u32 unk0;
    u32 unk4;
    u8 unk8[0x2c];
} Struct0213b278;

extern Struct0213b278 data_0213b278[3];

BOOL func_020066c0(void) {
    int i;
    for (i = 0; i < 3; i++) {
        if (data_0213b278[i].unk4 == 1) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_02006c50(u8 *buf, u32 len) {
    u32 i;
    for (i = 0; i < len / 2; i++) {
        u8 tmp = buf[i];
        buf[i] = buf[len - 1 - i];
        buf[len - 1 - i] = tmp;
    }
}

u8 func_02006f24(U16ToU8Table *table, u16 key) {
    int i;
    for (i = 0; i < table->count; i++) {
        if (key == table->keys[i]) {
            return table->values[i];
        }
    }
    return 0;
}

U16Pair *func_020082bc(U16Pair *pairs, u32 count, u16 key, u16 min) {
    u32 i;
    for (i = 0; i < count; i++) {
        if (key == pairs[i].unk0) {
            if (pairs[i].unk2 < min) {
                return NULL;
            }
            return &pairs[i];
        }
    }
    return NULL;
}

u32 func_02008488(U16Pair *pairs, u32 count) {
    u32 result = 0;
    u32 i;
    if (pairs != NULL) {
        for (i = 0; i < count; i++) {
            if (pairs[i].unk0 != 0) {
                result++;
            }
        }
    }
    return result;
}

void func_02008658(U16Pair *pairs, u32 count) {
    u32 i;
    for (i = 0; i < count; i++) {
        if (pairs[i].unk0 == 0) {
            pairs[i].unk2 = 0;
        }
    }
}
