#include "asm/tr_ai.inc"

TrAI08_0000:
    if_target_is_ally TrAI08_00CA
    if_hp_greater_than TRAI_SIDE_ATTACKER, 70, TrAI08_0034
    if_hp_greater_than TRAI_SIDE_ATTACKER, 30, TrAI08_0046
    load_move_effect
    if_in_list TrAI08_01BC, TrAI08_0058
    jump TrAI08_0068
TrAI08_0034:
    load_move_effect
    if_in_list TrAI08_00CC, TrAI08_0058
    jump TrAI08_0068
TrAI08_0046:
    load_move_effect
    if_in_list TrAI08_0100, TrAI08_0058
    jump TrAI08_0068
TrAI08_0058:
    if_random_less_than 50, TrAI08_0068
    add_to_score -2
TrAI08_0068:
    if_hp_greater_than TRAI_SIDE_DEFENDER, 70, TrAI08_0096
    if_hp_greater_than TRAI_SIDE_DEFENDER, 30, TrAI08_00A8
    load_move_effect
    if_in_list TrAI08_033C, TrAI08_00BA
    jump TrAI08_00CA
TrAI08_0096:
    load_move_effect
    if_in_list TrAI08_028C, TrAI08_00BA
    jump TrAI08_00CA
TrAI08_00A8:
    load_move_effect
    if_in_list TrAI08_0290, TrAI08_00BA
    jump TrAI08_00CA
TrAI08_00BA:
    if_random_less_than 50, TrAI08_00CA
    add_to_score -2
TrAI08_00CA:
    end
TrAI08_00CC:
    .4byte 7
    .4byte 32
    .4byte 37
    .4byte 98
    .4byte 99
    .4byte 116
    .4byte 132
    .4byte 168
    .4byte 194
    .4byte 214
    .4byte 220
    .4byte 270
    list_end
TrAI08_0100:
    .4byte 7
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
    .4byte 26
    .4byte 30
    .4byte 35
    .4byte 46
    .4byte 47
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
    .4byte 93
    .4byte 124
    .4byte 142
    .4byte 205
    .4byte 206
    .4byte 208
    .4byte 211
    .4byte 212
    .4byte 240
    .4byte 243
    .4byte 244
    .4byte 265
    list_end
TrAI08_01BC:
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
    .4byte 26
    .4byte 30
    .4byte 35
    .4byte 46
    .4byte 47
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
    .4byte 81
    .4byte 93
    .4byte 94
    .4byte 124
    .4byte 142
    .4byte 143
    .4byte 144
    .4byte 190
    .4byte 205
    .4byte 206
    .4byte 208
    .4byte 211
    .4byte 212
    .4byte 201
    .4byte 210
    .4byte 226
    .4byte 227
    .4byte 265
    list_end
TrAI08_028C:
    list_end
TrAI08_0290:
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
    .4byte 46
    .4byte 47
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
    .4byte 66
    .4byte 91
    .4byte 114
    .4byte 124
    .4byte 205
    .4byte 206
    .4byte 208
    .4byte 211
    .4byte 212
    .4byte 226
    .4byte 237
    .4byte 265
    list_end
TrAI08_033C:
    .4byte 1
    .4byte 7
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
    .4byte 26
    .4byte 30
    .4byte 33
    .4byte 35
    .4byte 38
    .4byte 40
    .4byte 40
    .4byte 46
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
    .4byte 66
    .4byte 67
    .4byte 91
    .4byte 93
    .4byte 94
    .4byte 100
    .4byte 114
    .4byte 118
    .4byte 119
    .4byte 120
    .4byte 124
    .4byte 143
    .4byte 144
    .4byte 167
    .4byte 205
    .4byte 206
    .4byte 208
    .4byte 211
    .4byte 212
    .4byte 226
    .4byte 237
    .4byte 265
    list_end
