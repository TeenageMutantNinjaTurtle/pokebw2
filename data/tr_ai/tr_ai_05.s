#include "asm/tr_ai.inc"

TrAI05_0000:
    load_species TRAI_SIDE_ATTACKER
    if_equal SPECIES_RESHIRAM, TrAI05_0020
    if_equal SPECIES_ZEKROM, TrAI05_0020
    jump TrAI05_004C
TrAI05_0020:
    load_turn_count
    if_not_equal 0, TrAI05_004C
    if_move MOVE_FUSION_BOLT, TrAI05_0046
    if_move MOVE_FUSION_FLARE, TrAI05_0046
    jump TrAI05_004C
TrAI05_0046:
    add_to_score 10
TrAI05_004C:
    end
    .balign 4
