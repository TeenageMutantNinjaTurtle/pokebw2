#ifndef POKEBW2_APP_EVENT_PDC_RETURN_H
#define POKEBW2_APP_EVENT_PDC_RETURN_H

// Overlay 330's event_pdc_return.c, after its embedded name: the return from the Entree Forest's capture (overlay
// 172's pdc.c). For a caught Pokémon it registers it in the Pokédex, shows the Pokédex entry (overlay 297), offers a
// nickname (overlay 280) and puts it in the party, or in a box when the party is full

#include "types.h"
#include "gfl/heap.h"
#include "gfl/proc.h"
#include "gfl/str.h"
#include "struct_decls.h"

// How the capture ended
#define PDC_RESULT_CAUGHT 1
// The Pokémon was seen but not caught
#define PDC_RESULT_SEEN 2

// The parameter of overlay 297's Pokédex registration (zukan_toroku.c), which belongs in its own header once that
// overlay is decompiled
typedef struct {
    // 0 for a species caught for the first time
    u32 mode;
    PartyPkm *pkm;
    BOOL nationalDex;
    // The message about the box the Pokémon goes to, or NULL when it joins the party
    StrBuf *boxMessage;
    BoxSaveAccessor *boxes;
    u32 box;
    GameData *gameData;
    // TRUE when the player chose to give the Pokémon a nickname
    u32 nickname;
} ZukanTorokuParam;

extern const GameProcFunctions data_ov297_021f4e38;

typedef struct {
    GameData *gameData;
    // PDC_RESULT_*
    u32 result;
    PartyPkm *pkm;
} EventPdcReturnParam;

EventPdcReturnParam *EventPdcReturn_CreateParam(GameData *gameData, u32 result, PartyPkm *pkm, HeapID heapId);
void EventPdcReturn_FreeParam(EventPdcReturnParam *param);

extern const GameProcFunctions EVENT_PDC_RETURN_PROC_FUNCTIONS;

#endif // POKEBW2_APP_EVENT_PDC_RETURN_H
