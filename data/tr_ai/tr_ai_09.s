    .include "asm/tr_ai.inc"

TrAI09_0000:
    if_target_is_ally TrAI09_0098
    load_turn_count
    if_not_equal 0, TrAI09_0098
    if_move_effect 137, TrAI09_003A
    if_move_effect 136, TrAI09_004C
    if_move_effect 115, TrAI09_005E
    if_move_effect 164, TrAI09_0070
TrAI09_003A:
    load_weather
    if_equal 1, TrAI09_0098
    jump TrAI09_0082
TrAI09_004C:
    load_weather
    if_equal 2, TrAI09_0098
    jump TrAI09_0082
TrAI09_005E:
    load_weather
    if_equal 4, TrAI09_0098
    jump TrAI09_0082
TrAI09_0070:
    load_weather
    if_equal 3, TrAI09_0098
    jump TrAI09_0082
TrAI09_0082:
    load_fake_out_active AI_ATTACKER
    if_equal 0, TrAI09_0098
    add_to_score 5
TrAI09_0098:
    end
    .balign 4
