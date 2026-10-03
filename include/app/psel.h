#ifndef POKEBW2_APP_PSEL_H
#define POKEBW2_APP_PSEL_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// The choice of a starter Pokémon, overlay 316 (psel.c)
#define OVERLAY_PSEL OVERLAY_ID(316)

typedef struct {
    u16 *result;
    u32 unk04;
} PselParam;

extern const GameProcFunctions data_ov316_0219fba4;

#endif // POKEBW2_APP_PSEL_H
