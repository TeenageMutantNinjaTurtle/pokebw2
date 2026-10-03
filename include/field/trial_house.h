#ifndef POKEBW2_FIELD_TRIAL_HOUSE_H
#define POKEBW2_FIELD_TRIAL_HOUSE_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

struct TrialHouseWork {
    u8 unk00[0x120];
    u16 heapId;
    u8 unk122[2];
    u32 capacity;
    PokeParty *party;
    u32 battleType;
    u32 selectionFlag;
    u8 unk134[0x18];
    void *saveBuffer;
    u32 initState;
};

extern const char data_ov033_0217c630[];

u32 func_0200ee20(GameSystem *gsys);
struct TrialHouseWork *CreateTrialHouseWk(GameSystem *gsys);
void func_ov033_0217acd4(GameSystem *gsys, struct TrialHouseWork *work);
void TrialHouseWorkDelete(void *unused, struct TrialHouseWork **work);
void func_ov033_0217adbc(TrialHouseWork *work, u32 selectionFlag);
void func_ov033_0217adc4(GameSystem *gsys, TrialHouseWork *work, u32 mode);
void func_ov033_0217ade8(TrialHouseWork *work, u32 mode);
void func_ov033_0217ae5c(GameSystem *gsys, TrialHouseWork *work, u32 mode);
u32 func_ov033_0217aed0(TrialHouseWork *work);
void *func_ov012_02162864(TrialHouseWork *work, u16 value, u32 capacity, u32 arg3, u32 arg4, u32 arg5, u16 flag);

#endif // POKEBW2_FIELD_TRIAL_HOUSE_H
