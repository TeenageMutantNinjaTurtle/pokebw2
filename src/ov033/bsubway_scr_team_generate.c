#include "field/bsubway_scr.h"
#include "gfl/heap.h"

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
