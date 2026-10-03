#ifndef POKEBW2_FIELD_BATTLE_FACILITY_H
#define POKEBW2_FIELD_BATTLE_FACILITY_H

#include "types.h"
#include "struct_decls.h"

// Shared value lookup used by the Trial House and Battle Subway.
u32 func_ov012_02162b38(u16 value);
BOOL func_ov012_02162864(BSubwayTrainer *trainer, u16 trainerId, u32 count, const u16 *species, const u16 *items,
                        const BSubwayTeamConfig *config, HeapID heapId);
BtlSetup *SetupTrialHouseBattle(GameSystem *gsys, PokeParty *party, u32 mode, BSubwayTrainer *trainers,
                                BSubwayTrainer *partner, u32 count);

#endif // POKEBW2_FIELD_BATTLE_FACILITY_H
