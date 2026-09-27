#include "asm/tr_ai.inc"

TrAI10_0000:
    if_target_is_ally TrAI10_0022
    load_move_effect
    if_not_in_list TrAI10_0024, TrAI10_0022
    if_random_less_than 128, TrAI10_0022
    add_to_score 2
TrAI10_0022:
    end
TrAI10_0024:
    .4byte 1
    .4byte 18
    .4byte 19
    .4byte 23
    .4byte 24
    .4byte 49
    .4byte 58
    .4byte 59
    .4byte 60
    .4byte 62
    .4byte 66
    .4byte 67
    .4byte 84
    .4byte 90
    .4byte 100
    .4byte 112
    .4byte 118
    .4byte 120
    .4byte 165
    .4byte 166
    .4byte 167
    .4byte 173
    .4byte 187
    .4byte 188
    .4byte 192
    .4byte 197
    .4byte 199
    .4byte 205
    .4byte 213
    .4byte 232
    .4byte 234
    .4byte 249
    .4byte 258
    .4byte 265
    list_end
