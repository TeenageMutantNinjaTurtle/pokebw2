#ifndef POKEBW2_APP_PDC_H
#define POKEBW2_APP_PDC_H

// Overlay 172's pdc.c, after its embedded name: catching a Pokémon of the Entree Forest. Overlay 330's
// event_pdc_return.c shows the result. Only the declarations overlay 12's scrcmd_entree_forest.c needs

#include "types.h"
#include "field/field_event.h"
#include "gfl/heap.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// Overlay 172
void *func_ov172_021998c0(GameData *gameData, PartyPkm *pkm, BtlFieldStatus *status, PlayerInfo *playerInfo,
                          BagSave *bag, TrainerDataSave *trainerData, PokeDexSave *pokedex, HeapID heapId);
// Whether the Pokémon was caught
BOOL func_ov172_02199918(void *param);

extern const GameProcFunctions data_ov172_0219a53c;

// Overlay 330
void *func_ov330_0219ce80(GameData *gameData, BOOL caught, PartyPkm *pkm, HeapID heapId);
void func_ov330_0219cea8(void *param);

extern const GameProcFunctions data_ov330_0219d1b4;

#endif // POKEBW2_APP_PDC_H
