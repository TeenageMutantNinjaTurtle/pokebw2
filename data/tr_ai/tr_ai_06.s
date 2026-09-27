#include "asm/tr_ai.inc"

TrAI06_0000:
    if_target_is_ally TrAI06_0148
    load_able_party_count TRAI_SIDE_ATTACKER
    if_equal 0, TrAI06_0148
    load_damage_rank 0
    if_not_equal 0, TrAI06_0148
    if_knows_move_effect TRAI_SIDE_ATTACKER, 127, TrAI06_003E
    if_random_less_than 80, TrAI06_0148
TrAI06_003E:
    if_move MOVE_SWORDS_DANCE, TrAI06_008A
    if_move MOVE_DRAGON_DANCE, TrAI06_008A
    if_move MOVE_CALM_MIND, TrAI06_008A
    if_move MOVE_NASTY_PLOT, TrAI06_008A
    if_move_effect 111, TrAI06_00AA
    if_move MOVE_BATON_PASS, TrAI06_00CE
    if_random_less_than 20, TrAI06_0148
    add_to_score 3
TrAI06_008A:
    load_turn_count
    if_equal 0, TrAI06_01AA
    if_hp_less_than TRAI_SIDE_ATTACKER, 60, TrAI06_017A
    jump TrAI06_0192
TrAI06_00AA:
    load_last_move TRAI_SIDE_ATTACKER
    if_in_list TrAI06_00C2, TrAI06_0152
    add_to_score 2
    end
TrAI06_00C2:
    .4byte MOVE_PROTECT
    .4byte MOVE_DETECT
    list_end
TrAI06_00CE:
    load_turn_count
    if_equal 0, TrAI06_0152
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER, 1, 8, TrAI06_01A2
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER, 1, 7, TrAI06_019A
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER, 1, 6, TrAI06_0192
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER, 3, 8, TrAI06_01A2
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER, 3, 7, TrAI06_019A
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER, 3, 6, TrAI06_0192
    end
TrAI06_0148:
    end
    add_to_score -1
    end
TrAI06_0152:
    add_to_score -2
    end
    add_to_score -3
    end
    add_to_score -5
    end
    add_to_score -6
    end
    add_to_score -8
    end
TrAI06_017A:
    add_to_score -10
    end
    add_to_score -12
    end
    add_to_score -30
    end
TrAI06_0192:
    add_to_score 1
    end
TrAI06_019A:
    add_to_score 2
    end
TrAI06_01A2:
    add_to_score 3
    end
TrAI06_01AA:
    add_to_score 5
    end
    add_to_score 10
    end
    .balign 4
