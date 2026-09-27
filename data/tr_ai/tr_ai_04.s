    .include "asm/tr_ai.inc"

TrAI04_0000:
    load_damage_rank 0
    if_not_equal 0, TrAI04_0052
    if_hp_greater_than AI_DEFENDER, 50, TrAI04_0064
    if_random_less_than 128, TrAI04_002E
    add_to_score 1
TrAI04_002E:
    if_hp_greater_than AI_DEFENDER, 25, TrAI04_0064
    if_random_less_than 128, TrAI04_0064
    add_to_score 1
    jump TrAI04_0064
TrAI04_0052:
    load_turn_count
    if_not_equal 0, TrAI04_0064
    add_to_score 1
TrAI04_0064:
    end
TrAI04_0066:
    .4byte 1
    .4byte 7
    .4byte 9
    .4byte 38
    .4byte 43
    .4byte 49
    .4byte 83
    .4byte 88
    .4byte 89
    .4byte 98
    .4byte 118
    .4byte 120
    .4byte 122
    .4byte 140
    .4byte 142
    .4byte 144
    .4byte 170
    .4byte 185
    .4byte 199
    .4byte 219
    .4byte 226
    .4byte 227
    .4byte 230
    .4byte 241
    .4byte 248
    list_end
    .balign 4
