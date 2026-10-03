#include "field/bsubway_scr.h"
#include "gfl/heap.h"
#include "gfl/std.h"
#include "pml/poke_party.h"
#include "save/bsubway_save.h"

void func_ov033_0217c010(BSubwayScrWork *bsw, SaveControl *save, u32 flag) {
    void *team;
    PokeParty *party;
    s32 i;
    u16 heapId;

    heapId = *(u32 *)((u8 *)bsw + 4);
    team = GFL_HeapAllocate((heapId & 0x7fff) | 0x8000, 0xb4, FALSE, data_ov033_0217c640, 0x8a1);
    sys_memset(team, 0, 0xb4);
    party = func_ov033_0217bd60(bsw);
    for (i = 0; i < 3; i++) {
        func_ov033_0217bf04((u8 *)team + 0x3c * i, PokeParty_GetPkm(party, bsw->unk1E[i]));
    }
    func_0200e4e8(bsw->unk74, flag, team);
    sys_memset(team, 0, 0xb4);
    GFL_HeapFree(team);
}
