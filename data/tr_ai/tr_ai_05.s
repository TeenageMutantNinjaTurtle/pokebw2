    .include "asm/tr_ai.inc"

TrAI05_0000:
    load_species AI_ATTACKER
    if_equal 643, TrAI05_0020
    if_equal 644, TrAI05_0020
    jump TrAI05_004C
TrAI05_0020:
    load_turn_count
    if_not_equal 0, TrAI05_004C
    if_move 559, TrAI05_0046
    if_move 558, TrAI05_0046
    jump TrAI05_004C
TrAI05_0046:
    add_to_score 10
TrAI05_004C:
    end
    .balign 4
