// Macros for the experience tables in data/growth_rates, archive a/0/1/7: one file per growth rate (GROWTH_*), with
// the total experience of each level from 0 to 100, in order, then ExpTableEnd.

    .set _exp_level, 0

    .macro Level level, exp
    .if \level != _exp_level
    .error "the levels of an experience table go from 0 to 100 in order"
    .endif
    .4byte \exp
    .set _exp_level, _exp_level + 1
    .endm

    .macro ExpTableEnd
    .if _exp_level != 101
    .error "an experience table has the levels 0 to 100"
    .endif
    .endm
