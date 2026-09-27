#include "asm/tr_ai.inc"

TrAI11_0000:
    if_condition TRAI_SIDE_ATTACKER, 8, TrAI11_006E
    if_condition TRAI_SIDE_ATTACKER, 22, TrAI11_006E
    load_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_SHADOW_TAG, TrAI11_006E
    load_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_LEVITATE, TrAI11_006C
    load_type TRAI_TYPE_ATTACKER_1
    if_equal TYPE_FLYING, TrAI11_006C
    load_type TRAI_TYPE_ATTACKER_2
    if_equal TYPE_FLYING, TrAI11_006C
    load_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_ARENA_TRAP, TrAI11_006E
TrAI11_006C:
    flee
TrAI11_006E:
    end
