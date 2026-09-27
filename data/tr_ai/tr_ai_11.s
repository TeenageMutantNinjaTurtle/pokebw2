    .include "asm/tr_ai.inc"

TrAI11_0000:
    if_condition AI_ATTACKER, 8, TrAI11_006E
    if_condition AI_ATTACKER, 22, TrAI11_006E
    load_ability AI_DEFENDER
    if_equal 23, TrAI11_006E
    load_ability AI_ATTACKER
    if_equal 26, TrAI11_006C
    load_type 1
    if_equal 2, TrAI11_006C
    load_type 3
    if_equal 2, TrAI11_006C
    load_ability AI_DEFENDER
    if_equal 71, TrAI11_006E
TrAI11_006C:
    flee
TrAI11_006E:
    end
