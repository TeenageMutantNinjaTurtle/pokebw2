// Macros for the trainers in data/trainers: one file per trainer, which holds both its record in a/0/9/1 (section
// .trainer) and its party in a/0/9/2 (section .party). A file has one Trainer, then a PartyMon for each Pokémon of
// the party, then PartyEnd, which counts them for the trainer record.

#include "constants/battle.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/tr_ai.h"

    // What each party entry holds besides the Pokémon itself, OR'ed together
    .set PARTY_MOVES, 1
    .set PARTY_ITEMS, 2

    // The trainer record: its party's kind (PARTY_*), its class, the battle style (BTL_STYLE_*), the items it can
    // use in battle, its AI flags (AI_FLAG_*), whether it heals, the money it gives (a multiplier) and the item it
    // gives as a reward
    .macro Trainer class, party=0, style=BTL_STYLE_SINGLE, item1=ITEM_NONE, item2=ITEM_NONE, item3=ITEM_NONE, item4=ITEM_NONE, ai=0, heals=0, money=0, reward=ITEM_NONE
    .set _party_kind, \party
    .set _party_size, 0
    .section .trainer, "a"
    .byte \party, \class, \style, _party_count
    .2byte \item1, \item2, \item3, \item4
    .4byte \ai
    .byte \heals, \money
    .2byte \reward
    .section .party, "a"
    .endm

    // A Pokémon of the party. difficulty sets its individual values; gender and ability pick them when not 0. The
    // item is written for a party of PARTY_ITEMS, and the moves for one of PARTY_MOVES
    .macro PartyMon level, species, form=0, difficulty=0, gender=0, ability=0, item=ITEM_NONE, move1=MOVE_NONE, move2=MOVE_NONE, move3=MOVE_NONE, move4=MOVE_NONE
    .byte \difficulty, \gender | (\ability << 4), \level, 0
    .2byte \species, \form
    .if _party_kind & PARTY_ITEMS
    .2byte \item
    .endif
    .if _party_kind & PARTY_MOVES
    .2byte \move1, \move2, \move3, \move4
    .endif
    .set _party_size, _party_size + 1
    .endm

    .macro PartyEnd
    .equ _party_count, _party_size
    .endm
