// Macros for the moves species learn by leveling up, in data/levelup_moves, archive a/0/1/8: one file per species
// record, as data/personal, with the moves in the order the game checks them and then LevelUpMovesEnd.

#include "constants/moves.h"

    .macro LevelUpMove level, move
    .2byte \move, \level
    .endm

    .macro LevelUpMovesEnd
    .4byte 0xffffffff
    .endm
