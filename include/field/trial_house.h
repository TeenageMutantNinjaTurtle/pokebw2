#ifndef POKEBW2_FIELD_TRIAL_HOUSE_H
#define POKEBW2_FIELD_TRIAL_HOUSE_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

struct TrialHouseWork {
    u8 unk00[0x120];
    u16 heapId;
    u8 unk122[6];
    PokeParty *party;
    u8 unk12c[0x20];
    void *saveBuffer;
    u32 initState;
};

extern const char data_ov033_0217c630[];

u32 func_0200ee20(GameSystem *gsys);
struct TrialHouseWork *CreateTrialHouseWk(GameSystem *gsys);
void func_ov033_0217acd4(GameSystem *gsys, struct TrialHouseWork *work);
void TrialHouseWorkDelete(void *unused, struct TrialHouseWork **work);

#endif // POKEBW2_FIELD_TRIAL_HOUSE_H
