#include "asm/tr_ai.inc"

TrAI03_0000:
    if_target_is_ally TrAI03_002E
    load_turn_count
    if_not_equal 0, TrAI03_002E
    load_move_effect
    if_not_in_list TrAI03_0030, TrAI03_002E
    if_random_less_than 80, TrAI03_002E
    add_to_score 2
TrAI03_002E:
    end
TrAI03_0030:
    .4byte 10
    .4byte 11
    .4byte 12
    .4byte 13
    .4byte 14
    .4byte 15
    .4byte 16
    .4byte 18
    .4byte 19
    .4byte 20
    .4byte 21
    .4byte 22
    .4byte 23
    .4byte 24
    .4byte 30
    .4byte 35
    .4byte 54
    .4byte 47
    .4byte 49
    .4byte 50
    .4byte 51
    .4byte 52
    .4byte 53
    .4byte 54
    .4byte 55
    .4byte 56
    .4byte 58
    .4byte 59
    .4byte 60
    .4byte 61
    .4byte 62
    .4byte 63
    .4byte 64
    .4byte 65
    .4byte 66
    .4byte 67
    .4byte 79
    .4byte 84
    .4byte 108
    .4byte 109
    .4byte 118
    .4byte 213
    .4byte 187
    .4byte 156
    .4byte 165
    .4byte 166
    .4byte 167
    .4byte 181
    .4byte 192
    .4byte 199
    .4byte 205
    .4byte 206
    .4byte 208
    .4byte 211
    .4byte 213
    .4byte 225
    .4byte 226
    .4byte 240
    .4byte 252
    .4byte 258
    .4byte 261
    list_end
