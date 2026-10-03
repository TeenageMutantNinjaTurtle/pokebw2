#include "field/battle_facility.h"
#include "field/bsubway_scr.h"
#include "gfl/heap.h"
#include "gfl/random.h"

void *func_ov033_0217c264(BSubwayScrWork *bsw, void *param, u16 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7) {
    return func_ov012_02162864(param, a2, a3, a4, a5, a6, a7);
}

u16 func_ov033_0217c288(u32 value) {
    if (value < 100) {
        return 3;
    }
    if (value < 120) {
        return 6;
    }
    if (value < 140) {
        return 9;
    }
    if (value < 160) {
        return 12;
    }
    if (value < 180) {
        return 15;
    }
    if (value < 200) {
        return 18;
    }
    if (value < 220) {
        return 21;
    }
    return 31;
}

void func_ov033_0217c2c4(void *unused, u8 *dst, u32 level, u32 arg3, BSubwayTeamConfig *config, HeapID heapId) {
    u32 adjusted;
    void *temp;
    s32 i;

    temp = func_ov012_021628c0(dst, 0xd4, level, 15, heapId);
    adjusted = func_ov033_0217c288(level);
    for (i = 0; i < 2; i++) {
        func_ov012_02162490((BSubwayPokemon *)(dst + 0x30 + 0x3c * i), 0xd3, config->unk4[i], config->unk0,
                            config->unk8[i], adjusted, i, arg3, heapId);
    }
    GFL_HeapFree(temp);
}

u16 randFFFFFFFFdivFFFF(void) {
    return GFL_RandomLC(0xffffffff) / 0xffff;
}
