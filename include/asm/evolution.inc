// Macros for the evolutions in data/evolutions, archive a/0/1/9: one file per species record, as data/personal, with
// up to seven evolutions and then EvolutionsEnd.

#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/species.h"

    .set _evolutions, 0

    // An evolution into a species by a method (EVO_METHOD_*). The parameter depends on the method: a level, an
    // item, a move, a species, or a value such as the friendship or beauty needed
    .macro Evolution method, param, species
    .2byte \method, \param, \species
    .set _evolutions, _evolutions + 1
    .endm

    // Fills the rest of the seven entries
    .macro EvolutionsEnd
    .if _evolutions > 7
    .error "a species has at most seven evolutions"
    .endif
    .rept 7 - _evolutions
    .2byte 0, 0, 0
    .endr
    .endm
