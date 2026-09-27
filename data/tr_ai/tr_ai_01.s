    .include "asm/tr_ai.inc"

TrAI01_0000:
    if_target_is_ally TrAI01_00C6
    if_can_faint 0, TrAI01_0072
    load_damage_rank 0
    if_equal 1, TrAI01_00C8
    if_move_effect 7, TrAI01_0044
    if_move_effect 170, TrAI01_0044
    if_move_effect 248, TrAI01_0044
    jump TrAI01_0054
TrAI01_0044:
    if_random_less_than 51, TrAI01_0054
    add_to_score -2
TrAI01_0054:
    if_effectiveness 5, TrAI01_0060
    end
TrAI01_0060:
    if_random_less_than 80, TrAI01_00C6
    add_to_score 2
    end
TrAI01_0072:
    if_move_effect 7, TrAI01_00C6
    if_move_effect 170, TrAI01_00AA
    if_move_effect 248, TrAI01_00AA
    if_move_effect 148, TrAI01_00AA
    if_move_effect 103, TrAI01_00BA
    jump TrAI01_00C0
TrAI01_00AA:
    if_random_less_than 170, TrAI01_00C6
    jump TrAI01_00C0
TrAI01_00BA:
    add_to_score 2
TrAI01_00C0:
    add_to_score 4
TrAI01_00C6:
    end
TrAI01_00C8:
    add_to_score -1
    end
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
    add_to_score -10
    end
    add_to_score -12
    end
    add_to_score -30
    end
    add_to_score 1
    end
    add_to_score 2
    end
    add_to_score 3
    end
    add_to_score 5
    end
    add_to_score 10
    end
