#ifndef POKEBW2_APP_OV313_H
#define POKEBW2_APP_OV313_H

// Overlay 313, a screen of the Trial House's results, which overlay 12's event_trial_house.c runs

#include "types.h"
#include "gfl/proc.h"
#include "struct_decls.h"

typedef struct {
    u8 gender;
    TrialHouseSave *save;
    u32 unk08;
    u32 unk0C;
} Ov313Param;

extern const GameProcFunctions data_ov313_0219dc6c;

#endif // POKEBW2_APP_OV313_H
