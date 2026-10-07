#ifndef POKEBW2_FIELD_BATTLE_FACILITY_H
#define POKEBW2_FIELD_BATTLE_FACILITY_H

// Overlay 12's fld_btl_inst_tool.c: the trainers, Pokémon and battles of the battle facilities, the Battle Subway and
// the Trial House. func_ov012_021621d4, func_ov012_02162490 and func_ov012_021628c0 are in field/bsubway_scr.h

#include "types.h"
#include "gfl/heap.h"
#include "nitro/math.h"
#include "struct_decls.h"

// A file of a battle facility's Pokémon arc
typedef struct {
    u16 species;
    u16 moves[4];
    // A bit for each stat that gets effort values
    u8 evFlags;
    u8 nature;
    u16 item;
    u16 form;
} BSubwayPokemonData;

// What a trainer class gives, for the Trial House and Battle Subway
u32 func_ov012_02162b38(u16 trainerClass);
// Loads the trainer of the file, and count Pokémon for it, none of species and none holding items
BOOL func_ov012_02162864(BSubwayTrainer *trainer, u16 trainerId, u32 count, const u16 *species, const u16 *items,
                         BSubwayTeamConfig *config, HeapID heapId);
BtlSetup *SetupTrialHouseBattle(GameSystem *gsys, PokeParty *party, u32 mode, BSubwayTrainer *trainers,
                                BSubwayTrainer *partner, u32 count);
// A file of the arc, loaded
void *func_ov012_021627c0(u32 arcId, u16 file, HeapID heapId);
BOOL func_ov012_0216292c(const u16 *trainerData, u16 trainerId, BSubwayPokemon *pkms, u8 count, u32 arcId,
                         const u16 *species, const u16 *items, BSubwayTeamConfig *config, MATHRandContext32 *rand,
                         u8 iv, HeapID heapId);
u32 func_ov012_02162b0c(u32 arcId, u16 file, HeapID heapId);
u16 func_ov012_02162b28(u32 arcId, u16 file, HeapID heapId);

#endif // POKEBW2_FIELD_BATTLE_FACILITY_H
