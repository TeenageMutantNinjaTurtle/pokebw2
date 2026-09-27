    .include "asm/tr_ai.inc"

TrAI07_0000:
    load_battle_style
TrAI07_0002:
    if_equal 1, TrAI07_0018
    if_equal 2, TrAI07_0018
    end
TrAI07_0018:
    if_target_is_ally TrAI07_0FB2
    load_damage_rank 0
    if_equal 0, TrAI07_019E
    if_move_effect 38, TrAI07_00D6
    if_move_effect 41, TrAI07_00D6
    if_move_effect 87, TrAI07_00D6
    if_move_effect 88, TrAI07_00D6
    if_move_effect 130, TrAI07_00D6
    if_effectiveness 2, TrAI07_007A
    if_effectiveness 1, TrAI07_00A8
    jump TrAI07_00D6
TrAI07_007A:
    if_can_faint 0, TrAI07_00D6
    if_hp_equal AI_DEFENDER_PARTNER, 0, TrAI07_00D6
    if_random_less_than 64, TrAI07_00D6
    add_to_score -1
    jump TrAI07_00D6
TrAI07_00A8:
    if_can_faint 0, TrAI07_00D6
    if_hp_equal AI_DEFENDER_PARTNER, 0, TrAI07_00D6
    if_random_less_than 64, TrAI07_00D6
    add_to_score -2
    jump TrAI07_00D6
TrAI07_00D6:
    load_damage_rank_with_partners 0
    if_not_equal 2, TrAI07_0126
    if_move_effect 7, TrAI07_019E
    if_move_effect 103, TrAI07_0110
    if_random_less_than 128, TrAI07_0126
    add_to_score 1
    jump TrAI07_019E
TrAI07_0110:
    if_random_less_than 50, TrAI07_0126
    add_to_score 1
    jump TrAI07_019E
TrAI07_0126:
    if_move_effect 38, TrAI07_019E
    if_move_effect 41, TrAI07_019E
    if_move_effect 87, TrAI07_019E
    if_move_effect 88, TrAI07_019E
    if_move_effect 130, TrAI07_019E
    if_effectiveness 4, TrAI07_0172
    if_effectiveness 5, TrAI07_0188
    jump TrAI07_019E
TrAI07_0172:
    if_random_less_than 100, TrAI07_019E
    add_to_score 1
    jump TrAI07_019E
TrAI07_0188:
    if_random_less_than 64, TrAI07_019E
    add_to_score 1
    jump TrAI07_019E
TrAI07_019E:
    if_move_effect 313, TrAI07_0F5E
    if_move_effect 190, TrAI07_0F5E
    if_move 59, TrAI07_0F5E
    if_move 59, TrAI07_0F5E
    if_move 59, TrAI07_0F5E
    if_move 469, TrAI07_0D98
    if_move 496, TrAI07_0E22
    if_move 502, TrAI07_0E4E
    if_move 511, TrAI07_0F16
    if_move 516, TrAI07_0F10
    if_move 285, TrAI07_0B02
    load_type 4
    if_move 89, TrAI07_0986
    if_move 222, TrAI07_0986
    if_move 248, TrAI07_0A12
    if_move 353, TrAI07_0A12
    if_move 240, TrAI07_02D2
    if_move 241, TrAI07_034E
    if_move 258, TrAI07_0482
    if_move 201, TrAI07_04FA
    if_move 356, TrAI07_057E
    if_move 433, TrAI07_06BE
    if_move 266, TrAI07_07A6
    if_move 505, TrAI07_0FAA
    if_move 495, TrAI07_0FAA
    if_move 270, TrAI07_0FAA
    load_type 4
    if_equal 12, TrAI07_0B7E
    if_equal 9, TrAI07_0CF2
    if_equal 10, TrAI07_0C52
    if_knows_move AI_ATTACKER_PARTNER, 270, TrAI07_08E0
    end
TrAI07_02D2:
    load_known_ability AI_ATTACKER
    if_equal 93, TrAI07_02F2
    if_equal 87, TrAI07_02FC
    jump TrAI07_0308
TrAI07_02F2:
    if_no_status AI_ATTACKER, TrAI07_0308
TrAI07_02FC:
    add_to_score 2
    jump TrAI07_0308
TrAI07_0308:
    load_known_ability_is AI_ATTACKER_PARTNER, 93
    if_equal 1, TrAI07_0336
    load_known_ability_is AI_ATTACKER_PARTNER, 87
    if_equal 1, TrAI07_0340
    jump TrAI07_034C
TrAI07_0336:
    if_no_status AI_ATTACKER_PARTNER, TrAI07_034C
TrAI07_0340:
    add_to_score 2
    jump TrAI07_034C
TrAI07_034C:
    end
TrAI07_034E:
    load_known_ability AI_ATTACKER
    if_equal 102, TrAI07_0382
    if_equal 122, TrAI07_039A
    if_equal 87, TrAI07_03A6
    if_equal 94, TrAI07_03B2
    jump TrAI07_03D6
TrAI07_0382:
    if_status AI_ATTACKER, TrAI07_03D6
    if_hp_less_than AI_ATTACKER, 30, TrAI07_03D6
TrAI07_039A:
    add_to_score 2
    jump TrAI07_03D6
TrAI07_03A6:
    add_to_score -2
    jump TrAI07_03D6
TrAI07_03B2:
    if_hp_less_than AI_ATTACKER, 50, TrAI07_03C6
    add_to_score 1
TrAI07_03C6:
    if_random_less_than 128, TrAI07_03D6
    add_to_score -2
TrAI07_03D6:
    load_known_ability_is AI_ATTACKER_PARTNER, 102
    if_equal 1, TrAI07_042C
    load_known_ability_is AI_ATTACKER_PARTNER, 122
    if_equal 1, TrAI07_0444
    load_known_ability_is AI_ATTACKER_PARTNER, 87
    if_equal 1, TrAI07_0450
    load_known_ability_is AI_ATTACKER_PARTNER, 94
    if_equal 1, TrAI07_045C
    jump TrAI07_0480
TrAI07_042C:
    if_status AI_ATTACKER_PARTNER, TrAI07_0480
    if_hp_less_than AI_ATTACKER_PARTNER, 30, TrAI07_0480
TrAI07_0444:
    add_to_score 2
    jump TrAI07_0480
TrAI07_0450:
    add_to_score -2
    jump TrAI07_0480
TrAI07_045C:
    if_hp_less_than AI_ATTACKER_PARTNER, 50, TrAI07_0470
    add_to_score 1
TrAI07_0470:
    if_random_less_than 128, TrAI07_0480
    add_to_score -2
TrAI07_0480:
    end
TrAI07_0482:
    load_known_ability AI_ATTACKER
    if_equal 115, TrAI07_04B0
    if_equal 81, TrAI07_04B0
    if_knows_move AI_ATTACKER, 59, TrAI07_04B0
    jump TrAI07_04B6
TrAI07_04B0:
    add_to_score 2
TrAI07_04B6:
    load_known_ability_is AI_ATTACKER_PARTNER, 115
    if_equal 1, TrAI07_04F2
    load_known_ability_is AI_ATTACKER_PARTNER, 81
    if_equal 1, TrAI07_04F2
    if_knows_move AI_ATTACKER_PARTNER, 59, TrAI07_04F2
    jump TrAI07_04F8
TrAI07_04F2:
    add_to_score 2
TrAI07_04F8:
    end
TrAI07_04FA:
    load_known_ability AI_ATTACKER
    if_equal 8, TrAI07_0530
    load_type 1
    if_equal 5, TrAI07_0530
    load_type 3
    if_equal 5, TrAI07_0530
    jump TrAI07_053C
TrAI07_0530:
    add_to_score 2
    jump TrAI07_053C
TrAI07_053C:
    load_known_ability_is AI_ATTACKER_PARTNER, 8
    if_equal 1, TrAI07_0576
    load_type 6
    if_equal 5, TrAI07_0576
    load_type 8
    if_equal 5, TrAI07_0576
    jump TrAI07_057C
TrAI07_0576:
    add_to_score 2
TrAI07_057C:
    end
TrAI07_057E:
    if_field_effect 2, TrAI07_1FA0
    load_known_ability_is AI_ATTACKER, 26
    if_equal 1, TrAI07_05C4
    load_has_type AI_ATTACKER, 2
    if_equal 1, TrAI07_05C4
    if_condition AI_ATTACKER, 30, TrAI07_05C4
    jump TrAI07_05D0
TrAI07_05C4:
    add_to_score -5
    jump TrAI07_05D0
TrAI07_05D0:
    load_known_ability_is AI_ATTACKER_PARTNER, 26
    if_equal 1, TrAI07_060C
    load_has_type AI_ATTACKER_PARTNER, 2
    if_equal 1, TrAI07_060C
    if_condition AI_ATTACKER_PARTNER, 30, TrAI07_060C
    jump TrAI07_0618
TrAI07_060C:
    add_to_score -5
    jump TrAI07_0618
TrAI07_0618:
    load_known_ability_is AI_DEFENDER, 26
    if_equal 1, TrAI07_0654
    load_has_type AI_DEFENDER, 2
    if_equal 1, TrAI07_0654
    if_condition AI_DEFENDER, 30, TrAI07_0654
    jump TrAI07_066A
TrAI07_0654:
    if_random_less_than 64, TrAI07_066A
    add_to_score 3
    jump TrAI07_066A
TrAI07_066A:
    load_known_ability_is AI_DEFENDER_PARTNER, 26
    if_equal 1, TrAI07_06A6
    load_has_type AI_DEFENDER_PARTNER, 2
    if_equal 1, TrAI07_06A6
    if_condition AI_DEFENDER_PARTNER, 30, TrAI07_06A6
    jump TrAI07_06BC
TrAI07_06A6:
    if_random_less_than 64, TrAI07_06BC
    add_to_score 3
    jump TrAI07_06BC
TrAI07_06BC:
    end
TrAI07_06BE:
    if_hp_equal AI_ATTACKER_PARTNER, 0, TrAI07_1FE8
    if_hp_equal AI_DEFENDER_PARTNER, 0, TrAI07_1FE8
    if_hp_equal AI_DEFENDER, 0, TrAI07_1FE8
    load_speed_order AI_ATTACKER
    if_equal 0, TrAI07_071C
    if_equal 1, TrAI07_073C
    if_equal 2, TrAI07_0752
    if_equal 3, TrAI07_0778
    jump TrAI07_07A4
TrAI07_071C:
    load_speed_order AI_ATTACKER_PARTNER
    if_equal 1, TrAI07_1FE8
    if_equal 0, TrAI07_1FE8
    jump TrAI07_079E
TrAI07_073C:
    load_speed_order AI_ATTACKER_PARTNER
    if_equal 0, TrAI07_1FE8
    jump TrAI07_079E
TrAI07_0752:
    load_speed_order AI_ATTACKER_PARTNER
    if_not_equal 3, TrAI07_079E
    if_random_less_than 64, TrAI07_079E
    add_to_score 5
    jump TrAI07_07A4
TrAI07_0778:
    load_speed_order AI_ATTACKER_PARTNER
    if_not_equal 2, TrAI07_079E
    if_random_less_than 64, TrAI07_079E
    add_to_score 5
    jump TrAI07_07A4
TrAI07_079E:
    add_to_score -5
TrAI07_07A4:
    end
TrAI07_07A6:
    if_hp_greater_than AI_ATTACKER, 90, TrAI07_07E0
    if_hp_greater_than AI_ATTACKER, 50, TrAI07_0810
    if_hp_greater_than AI_ATTACKER, 30, TrAI07_0840
    if_random_less_than 64, TrAI07_08DE
    jump TrAI07_1FC0
TrAI07_07E0:
    if_hp_greater_than AI_ATTACKER_PARTNER, 90, TrAI07_0870
    if_hp_greater_than AI_ATTACKER_PARTNER, 50, TrAI07_089C
    if_hp_greater_than AI_ATTACKER_PARTNER, 30, TrAI07_08B2
    jump TrAI07_08C8
TrAI07_0810:
    if_hp_greater_than AI_ATTACKER_PARTNER, 90, TrAI07_0886
    if_hp_greater_than AI_ATTACKER_PARTNER, 50, TrAI07_0870
    if_hp_greater_than AI_ATTACKER_PARTNER, 30, TrAI07_089C
    jump TrAI07_08B2
TrAI07_0840:
    if_hp_greater_than AI_ATTACKER_PARTNER, 90, TrAI07_0886
    if_hp_greater_than AI_ATTACKER_PARTNER, 50, TrAI07_0886
    if_hp_greater_than AI_ATTACKER_PARTNER, 30, TrAI07_089C
    jump TrAI07_08B2
TrAI07_0870:
    if_random_less_than 64, TrAI07_08DE
    add_to_score -1
    jump TrAI07_08DE
TrAI07_0886:
    if_random_less_than 64, TrAI07_08DE
    add_to_score -2
    jump TrAI07_08DE
TrAI07_089C:
    if_random_less_than 64, TrAI07_08DE
    add_to_score 1
    jump TrAI07_08DE
TrAI07_08B2:
    if_random_less_than 64, TrAI07_08DE
    add_to_score 2
    jump TrAI07_08DE
TrAI07_08C8:
    if_random_less_than 64, TrAI07_08DE
    add_to_score 3
    jump TrAI07_08DE
TrAI07_08DE:
    end
TrAI07_08E0:
    if_hp_greater_than AI_ATTACKER, 50, TrAI07_0904
    load_speed_order AI_ATTACKER
    if_less_than 1, TrAI07_0904
    jump TrAI07_0956
TrAI07_0904:
    if_move_effect 38, TrAI07_0956
    if_move_effect 41, TrAI07_0956
    if_move_effect 87, TrAI07_0956
    if_move_effect 88, TrAI07_0956
    if_move_effect 130, TrAI07_0956
    load_damage_rank 0
    if_equal 0, TrAI07_0956
    if_turn_random_less_than 128, TrAI07_0956
    add_to_score 3
TrAI07_0956:
    end
    if_status AI_ATTACKER, TrAI07_0964
    end
TrAI07_0964:
    load_damage_rank 0
    if_equal 0, TrAI07_1FC0
    add_to_score 1
    if_equal 2, TrAI07_1FF8
    end
TrAI07_0986:
    if_condition AI_ATTACKER_PARTNER, 30, TrAI07_1FF8
    load_known_ability_is AI_ATTACKER_PARTNER, 26
    if_equal 1, TrAI07_1FF8
    load_has_type AI_ATTACKER_PARTNER, 2
    if_equal 1, TrAI07_1FF8
    load_has_type AI_ATTACKER_PARTNER, 9
    if_equal 1, TrAI07_1FD8
    load_has_type AI_ATTACKER_PARTNER, 12
    if_equal 1, TrAI07_1FD8
    load_has_type AI_ATTACKER_PARTNER, 3
    if_equal 1, TrAI07_1FD8
    load_has_type AI_ATTACKER_PARTNER, 5
    if_equal 1, TrAI07_1FD8
    jump TrAI07_1FB8
TrAI07_0A12:
    if_hp_equal AI_ATTACKER_PARTNER, 0, TrAI07_0B00
    if_knows_move AI_ATTACKER_PARTNER, 248, TrAI07_0A42
    if_knows_move AI_ATTACKER_PARTNER, 353, TrAI07_0A42
    jump TrAI07_0B00
TrAI07_0A42:
    load_speed_order AI_ATTACKER
    if_equal 3, TrAI07_1FB8
    if_equal 2, TrAI07_0A76
    if_equal 1, TrAI07_0AB0
    if_equal 0, TrAI07_0AE0
    jump TrAI07_0B00
TrAI07_0A76:
    load_speed_order AI_ATTACKER_PARTNER
    if_equal 0, TrAI07_1FB8
    if_equal 1, TrAI07_1FB8
    if_random_less_than 128, TrAI07_0B00
    load_speed_order AI_ATTACKER_PARTNER
    if_equal 2, TrAI07_1FB8
    jump TrAI07_0B00
TrAI07_0AB0:
    load_speed_order AI_ATTACKER_PARTNER
    if_equal 0, TrAI07_1FB8
    if_random_less_than 128, TrAI07_0B00
    load_speed_order AI_ATTACKER_PARTNER
    if_equal 1, TrAI07_1FB8
    jump TrAI07_0B00
TrAI07_0AE0:
    if_random_less_than 128, TrAI07_0B00
    load_speed_order AI_ATTACKER_PARTNER
    if_equal 0, TrAI07_1FB8
    jump TrAI07_0B00
TrAI07_0B00:
    end
TrAI07_0B02:
    load_known_ability AI_ATTACKER
    if_equal 54, TrAI07_2008
    if_equal 112, TrAI07_2008
    if_equal 100, TrAI07_2008
    if_equal 103, TrAI07_2008
    load_known_ability AI_DEFENDER
    if_equal 23, TrAI07_1FF8
    if_equal 74, TrAI07_1FF8
    if_equal 37, TrAI07_1FF8
    if_equal 104, TrAI07_1FF8
    if_equal 116, TrAI07_1FF8
    if_equal 111, TrAI07_1FF8
    if_equal 122, TrAI07_1FF8
    end
TrAI07_0B7E:
    if_move 435, TrAI07_0BE6
    load_known_ability_is AI_DEFENDER_PARTNER, 31
    if_equal 1, TrAI07_0BA2
    jump TrAI07_0BC2
TrAI07_0BA2:
    add_to_score -1
    load_has_type AI_DEFENDER_PARTNER, 4
    if_equal 0, TrAI07_0BC2
    add_to_score -8
TrAI07_0BC2:
    load_known_ability_is AI_ATTACKER_PARTNER, 31
    if_equal 1, TrAI07_1FD8
    if_move 435, TrAI07_0BE6
    jump TrAI07_0C50
TrAI07_0BE6:
    load_known_ability_is AI_ATTACKER_PARTNER, 78
    if_equal 1, TrAI07_2000
    load_known_ability_is AI_ATTACKER_PARTNER, 10
    if_equal 1, TrAI07_2000
    load_has_type AI_ATTACKER_PARTNER, 10
    if_equal 1, TrAI07_1FD8
    load_has_type AI_ATTACKER_PARTNER, 2
    if_equal 1, TrAI07_1FD8
    load_has_type AI_ATTACKER_PARTNER, 4
    if_equal 1, TrAI07_2000
    add_to_score -3
TrAI07_0C50:
    end
TrAI07_0C52:
    if_move 57, TrAI07_0C9A
    load_known_ability_is AI_DEFENDER_PARTNER, 114
    if_equal 0, TrAI07_0C76
    add_to_score -1
TrAI07_0C76:
    load_known_ability_is AI_ATTACKER_PARTNER, 114
    if_equal 1, TrAI07_1FD8
    if_move 57, TrAI07_0C9A
    jump TrAI07_0CF0
TrAI07_0C9A:
    load_known_ability_is AI_ATTACKER_PARTNER, 87
    if_equal 1, TrAI07_2000
    load_known_ability_is AI_ATTACKER_PARTNER, 11
    if_equal 1, TrAI07_2000
    load_has_type AI_ATTACKER_PARTNER, 4
    if_equal 1, TrAI07_1FD8
    load_has_type AI_ATTACKER_PARTNER, 9
    if_equal 1, TrAI07_1FD8
    add_to_score -3
TrAI07_0CF0:
    end
TrAI07_0CF2:
    if_flash_fire AI_ATTACKER, TrAI07_0D02
    jump TrAI07_0D08
TrAI07_0D02:
    add_to_score 1
TrAI07_0D08:
    if_move 436, TrAI07_0D18
    jump TrAI07_0D96
TrAI07_0D18:
    load_known_ability_is AI_ATTACKER_PARTNER, 87
    if_equal 1, TrAI07_1FB8
    load_known_ability_is AI_ATTACKER_PARTNER, 18
    if_equal 1, TrAI07_2000
    load_has_type AI_ATTACKER_PARTNER, 11
    if_equal 1, TrAI07_1FD8
    load_has_type AI_ATTACKER_PARTNER, 8
    if_equal 1, TrAI07_1FD8
    load_has_type AI_ATTACKER_PARTNER, 14
    if_equal 1, TrAI07_1FD8
    load_has_type AI_ATTACKER_PARTNER, 6
    if_equal 1, TrAI07_1FD8
    add_to_score -3
TrAI07_0D96:
    end
TrAI07_0D98:
    if_random_less_than 50, TrAI07_0DB2
    load_last_move AI_ATTACKER
    if_equal 469, TrAI07_0DC4
TrAI07_0DB2:
    load_last_move AI_DEFENDER
    if_not_in_list TrAI07_0DE2, TrAI07_0DD0
    end
TrAI07_0DC4:
    add_to_score -4
    jump TrAI07_0DE0
TrAI07_0DD0:
    if_random_less_than 80, TrAI07_0DE0
    add_to_score 2
TrAI07_0DE0:
    end
TrAI07_0DE2:
    .4byte 59
    .4byte 157
    .4byte 257
    .4byte 284
    .4byte 323
    .4byte 330
    .4byte 549
    .4byte 555
    .4byte 57
    .4byte 89
    .4byte 435
    .4byte 436
    .4byte 482
    .4byte 523
    .4byte 545
    list_end
TrAI07_0E22:
    if_not_knows_move AI_ATTACKER_PARTNER, 496, TrAI07_0E46
    if_turn_random_less_than 128, TrAI07_0E46
    add_to_score 3
    jump TrAI07_0E4C
TrAI07_0E46:
    add_to_score -1
TrAI07_0E4C:
    end
TrAI07_0E4E:
    load_species AI_DEFENDER
    if_in_list TrAI07_0E9C, TrAI07_0E64
    jump TrAI07_0E9A
TrAI07_0E64:
    load_fake_out_active AI_DEFENDER
    if_not_equal 0, TrAI07_0E9A
    if_random_less_than 128, TrAI07_0E9A
    add_to_score 2
    jump TrAI07_0E9A
    if_random_less_than 128, TrAI07_0E9A
    add_to_score -1
TrAI07_0E9A:
    end
TrAI07_0E9C:
    .4byte 9
    .4byte 53
    .4byte 87
    .4byte 115
    .4byte 122
    .4byte 25
    .4byte 26
    .4byte 424
    .4byte 461
    .4byte 107
    .4byte 106
    .4byte 237
    .4byte 124
    .4byte 272
    .4byte 275
    .4byte 297
    .4byte 301
    .4byte 302
    .4byte 308
    .4byte 327
    .4byte 352
    .4byte 392
    .4byte 428
    .4byte 432
    .4byte 453
    .4byte 225
    .4byte 560
    .4byte 510
    list_end
TrAI07_0F10:
    jump TrAI07_1FD8
TrAI07_0F16:
    load_speed_order AI_ATTACKER_PARTNER
    if_equal 0, TrAI07_1FD8
    load_speed_order AI_ATTACKER_PARTNER
    if_equal 1, TrAI07_1FD8
    load_speed_order AI_ATTACKER
    if_equal 0, TrAI07_0F4C
    jump TrAI07_1FD8
TrAI07_0F4C:
    if_turn_random_less_than 128, TrAI07_0F5C
    add_to_score 1
TrAI07_0F5C:
    end
TrAI07_0F5E:
    if_knows_move AI_ATTACKER_PARTNER, 495, TrAI07_0F6E
    end
TrAI07_0F6E:
    load_speed_order AI_ATTACKER_PARTNER
    if_not_equal 0, TrAI07_1FD8
    load_speed_order AI_ATTACKER
    if_equal 0, TrAI07_1FD8
    if_equal 1, TrAI07_1FD8
    if_turn_random_less_than 128, TrAI07_0FA8
    add_to_score 3
TrAI07_0FA8:
    end
TrAI07_0FAA:
    add_to_score -40
    end
TrAI07_0FB2:
    if_fainted AI_ATTACKER_PARTNER, TrAI07_1FA0
    load_damage_rank 0
    if_equal 0, TrAI07_1236
    load_type 4
    if_equal 9, TrAI07_1000
    if_equal 12, TrAI07_1058
    if_equal 10, TrAI07_116A
    if_move 374, TrAI07_173C
TrAI07_0FFA:
    jump TrAI07_1FE8
TrAI07_1000:
    load_known_ability_is AI_ATTACKER_PARTNER, 18
    if_equal 1, TrAI07_101A
    jump TrAI07_0FFA
TrAI07_101A:
    if_flash_fire AI_ATTACKER_PARTNER, TrAI07_0FFA
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI07_0FFA
    if_equal 163, TrAI07_0FFA
    if_equal 164, TrAI07_0FFA
    if_random_less_than 150, TrAI07_0FFA
    jump TrAI07_1FF0
TrAI07_1058:
    load_known_ability_is AI_ATTACKER_PARTNER, 78
    if_equal 1, TrAI07_1086
    load_known_ability_is AI_ATTACKER_PARTNER, 10
    if_equal 1, TrAI07_10CC
    jump TrAI07_0FFA
TrAI07_1086:
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI07_0FFA
    if_equal 163, TrAI07_0FFA
    if_equal 164, TrAI07_0FFA
    if_random_less_than 160, TrAI07_1168
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 5, 7, TrAI07_0FFA
    jump TrAI07_1FF0
TrAI07_10CC:
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI07_0FFA
    if_equal 163, TrAI07_0FFA
    if_equal 164, TrAI07_0FFA
    if_random_less_than 150, TrAI07_0FFA
    if_hp_equal AI_ATTACKER_PARTNER, 100, TrAI07_1FD8
    if_hp_greater_than AI_ATTACKER_PARTNER, 90, TrAI07_1168
    if_hp_greater_than AI_ATTACKER_PARTNER, 75, TrAI07_1138
    if_hp_greater_than AI_ATTACKER_PARTNER, 50, TrAI07_1148
    jump TrAI07_1158
TrAI07_1138:
    if_random_less_than 64, TrAI07_1FF0
    jump TrAI07_1168
TrAI07_1148:
    if_random_less_than 128, TrAI07_1FF0
    jump TrAI07_1168
TrAI07_1158:
    if_random_less_than 192, TrAI07_1FF0
    jump TrAI07_1168
TrAI07_1168:
    end
TrAI07_116A:
    load_known_ability_is AI_ATTACKER_PARTNER, 11
    if_equal 1, TrAI07_1198
    load_known_ability_is AI_ATTACKER_PARTNER, 87
    if_equal 1, TrAI07_1198
    jump TrAI07_0FFA
TrAI07_1198:
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI07_0FFA
    if_equal 163, TrAI07_0FFA
    if_equal 164, TrAI07_0FFA
    if_random_less_than 150, TrAI07_0FFA
    if_hp_equal AI_ATTACKER_PARTNER, 100, TrAI07_1FD8
    if_hp_greater_than AI_ATTACKER_PARTNER, 90, TrAI07_1234
    if_hp_greater_than AI_ATTACKER_PARTNER, 75, TrAI07_1204
    if_hp_greater_than AI_ATTACKER_PARTNER, 50, TrAI07_1214
    jump TrAI07_1224
TrAI07_1204:
    if_random_less_than 64, TrAI07_1FF0
    jump TrAI07_1234
TrAI07_1214:
    if_random_less_than 128, TrAI07_1FF0
    jump TrAI07_1234
TrAI07_1224:
    if_random_less_than 192, TrAI07_1FF0
    jump TrAI07_1234
TrAI07_1234:
    end
TrAI07_1236:
    if_move 285, TrAI07_12D2
    if_move 272, TrAI07_14F2
    if_move 261, TrAI07_157E
    if_move 86, TrAI07_1600
    if_move_effect 33, TrAI07_164E
    if_move_effect 66, TrAI07_164E
    if_move 270, TrAI07_168E
    if_move 207, TrAI07_16D8
    if_move 271, TrAI07_173C
    if_move 415, TrAI07_173C
    if_move 516, TrAI07_173C
    if_move 380, TrAI07_1CF6
    if_move 367, TrAI07_1D3A
    if_move 495, TrAI07_1DFC
    if_move 505, TrAI07_1EC8
    jump TrAI07_1FA0
TrAI07_12D2:
    load_known_ability AI_DEFENDER
    if_equal 54, TrAI07_2010
    if_equal 112, TrAI07_2010
    load_known_ability AI_ATTACKER
    if_equal 26, TrAI07_132A
    if_equal 14, TrAI07_13C2
    if_equal 99, TrAI07_13C2
    if_equal 15, TrAI07_14CA
    if_equal 20, TrAI07_14DE
    jump TrAI07_1FA0
TrAI07_132A:
    load_known_ability AI_DEFENDER
    if_equal 26, TrAI07_1FD8
    load_type 0
    if_equal 2, TrAI07_1FD0
    load_type 2
    if_equal 2, TrAI07_1FD0
    load_type 0
    if_equal 11, TrAI07_1FC0
    if_equal 6, TrAI07_1FC0
    load_type 2
    if_equal 11, TrAI07_1FC0
    if_equal 6, TrAI07_1FC0
    if_condition AI_DEFENDER, 30, TrAI07_1FB0
    load_type 0
    if_equal 12, TrAI07_2000
    load_type 2
    if_equal 12, TrAI07_2000
    jump TrAI07_1FA0
TrAI07_13C2:
    if_knows_move AI_ATTACKER_PARTNER, 126, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 87, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 238, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 56, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 223, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 59, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 192, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 224, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 411, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 441, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 463, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 438, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 465, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 457, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 329, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 90, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 12, TrAI07_14C4
    if_knows_move AI_ATTACKER_PARTNER, 32, TrAI07_14C4
    jump TrAI07_1FA0
TrAI07_14C4:
    jump TrAI07_2000
TrAI07_14CA:
    if_not_condition AI_DEFENDER, 2, TrAI07_1FD0
    jump TrAI07_2000
TrAI07_14DE:
    if_not_condition AI_DEFENDER, 6, TrAI07_1FD0
    jump TrAI07_2000
TrAI07_14F2:
    load_known_ability AI_DEFENDER
    if_in_list TrAI07_152E, TrAI07_151C
    if_random_less_than 128, TrAI07_1FA0
    if_in_list TrAI07_154A, TrAI07_151C
    jump TrAI07_1FA0
TrAI07_151C:
    if_random_less_than 50, TrAI07_152C
    add_to_score 1
TrAI07_152C:
    end
TrAI07_152E:
    .4byte 140
    .4byte 132
    .4byte 3
    .4byte 22
    .4byte 74
    .4byte 130
    list_end
TrAI07_154A:
    .4byte 94
    .4byte 87
    .4byte 78
    .4byte 44
    .4byte 37
    .4byte 34
    .4byte 33
    .4byte 115
    .4byte 139
    .4byte 146
    .4byte 156
    .4byte 158
    list_end
TrAI07_157E:
    load_known_ability_is AI_ATTACKER_PARTNER, 18
    if_equal 1, TrAI07_1000
    load_known_ability_is AI_ATTACKER_PARTNER, 62
    if_not_equal 1, TrAI07_1FA0
    if_status AI_ATTACKER_PARTNER, TrAI07_1FA0
    load_type 0
    if_equal 9, TrAI07_1FA0
    load_type 2
    if_equal 9, TrAI07_1FA0
    if_held_item AI_ATTACKER_PARTNER, 273, TrAI07_1FA0
    if_held_item AI_ATTACKER_PARTNER, 272, TrAI07_1FA0
    if_hp_less_than AI_ATTACKER_PARTNER, 81, TrAI07_1FA0
    jump TrAI07_2008
TrAI07_1600:
    load_type 0
    if_equal 4, TrAI07_1FA0
    load_type 2
    if_equal 4, TrAI07_1FA0
    load_known_ability_is AI_ATTACKER_PARTNER, 78
    if_equal 1, TrAI07_1058
    load_known_ability_is AI_ATTACKER_PARTNER, 10
    if_equal 1, TrAI07_1058
    jump TrAI07_1FA0
TrAI07_164E:
    load_known_ability_is AI_ATTACKER_PARTNER, 90
    if_not_equal 1, TrAI07_1FA0
    if_status AI_DEFENDER, TrAI07_1FA0
    if_held_item AI_ATTACKER_PARTNER, 272, TrAI07_1FA0
    if_hp_greater_than AI_ATTACKER_PARTNER, 91, TrAI07_1FA0
    jump TrAI07_2008
TrAI07_168E:
    if_hp_equal AI_ATTACKER_PARTNER, 0, TrAI07_1FE8
    if_hp_greater_than AI_ATTACKER_PARTNER, 50, TrAI07_16C6
    load_speed_order AI_ATTACKER_PARTNER
    if_less_than 1, TrAI07_16C6
    add_to_score -1
    jump TrAI07_16D6
TrAI07_16C6:
    if_turn_random_less_than 128, TrAI07_16D6
    add_to_score 3
TrAI07_16D6:
    end
TrAI07_16D8:
    if_attack_less_than_sp_attack AI_DEFENDER, TrAI07_171C
    if_held_item AI_DEFENDER, 156, TrAI07_1722
    if_held_item AI_DEFENDER, 157, TrAI07_1722
    load_known_ability AI_DEFENDER
    if_equal 20, TrAI07_1722
    if_side_effect AI_DEFENDER, 2, TrAI07_1722
TrAI07_171C:
    jump TrAI07_1FA0
TrAI07_1722:
    if_stat_stage_greater_than AI_DEFENDER, 1, 7, TrAI07_173A
    add_to_score 3
TrAI07_173A:
    end
TrAI07_173C:
    if_held_item AI_ATTACKER, 157, TrAI07_17CE
    if_held_item AI_ATTACKER, 150, TrAI07_1824
    if_held_item AI_ATTACKER, 149, TrAI07_1838
    if_held_item AI_ATTACKER, 152, TrAI07_184C
    if_held_item AI_ATTACKER, 153, TrAI07_1860
    if_held_item AI_ATTACKER, 151, TrAI07_1874
    if_held_item AI_ATTACKER, 156, TrAI07_1884
    if_held_item AI_ATTACKER, 214, TrAI07_1898
    if_held_item AI_ATTACKER, 158, TrAI07_196C
    if_held_item AI_ATTACKER, 219, TrAI07_192E
    jump TrAI07_1FA0
TrAI07_17CE:
    if_condition AI_DEFENDER, 2, TrAI07_1980
    if_condition AI_DEFENDER, 1, TrAI07_1A06
    if_condition AI_DEFENDER, 3, TrAI07_1A38
    if_condition AI_DEFENDER, 3, TrAI07_1AC8
    if_badly_poisoned AI_DEFENDER, TrAI07_1B9C
    if_condition AI_DEFENDER, 6, TrAI07_1B32
    jump TrAI07_1FA0
TrAI07_1824:
    if_condition AI_DEFENDER, 2, TrAI07_1980
    jump TrAI07_1FA0
TrAI07_1838:
    if_condition AI_DEFENDER, 1, TrAI07_1A06
    jump TrAI07_1FA0
TrAI07_184C:
    if_condition AI_DEFENDER, 3, TrAI07_1A38
    jump TrAI07_1FA0
TrAI07_1860:
    if_condition AI_DEFENDER, 3, TrAI07_1AC8
    jump TrAI07_1FA0
TrAI07_1874:
    if_badly_poisoned AI_DEFENDER, TrAI07_1B9C
    jump TrAI07_1FA0
TrAI07_1884:
    if_condition AI_DEFENDER, 6, TrAI07_1B32
    jump TrAI07_1FA0
TrAI07_1898:
    if_stat_stage_less_than AI_ATTACKER_PARTNER, 1, 5, TrAI07_1C02
    if_stat_stage_less_than AI_ATTACKER_PARTNER, 2, 5, TrAI07_1C02
    if_stat_stage_less_than AI_ATTACKER_PARTNER, 3, 5, TrAI07_1C02
    if_stat_stage_less_than AI_ATTACKER_PARTNER, 4, 5, TrAI07_1C02
    if_stat_stage_less_than AI_ATTACKER_PARTNER, 7, 5, TrAI07_1C02
    if_stat_stage_less_than AI_ATTACKER_PARTNER, 5, 5, TrAI07_1C02
    if_stat_stage_less_than AI_ATTACKER_PARTNER, 4, 5, TrAI07_1C02
    if_stat_stage_less_than AI_ATTACKER_PARTNER, 7, 5, TrAI07_1C02
    jump TrAI07_1FA0
TrAI07_192E:
    if_condition AI_DEFENDER, 7, TrAI07_1C7A
    if_condition AI_DEFENDER, 6, TrAI07_1B32
    if_condition AI_DEFENDER, 12, TrAI07_1C7A
    if_condition AI_DEFENDER, 11, TrAI07_1C7A
    jump TrAI07_1FA0
TrAI07_196C:
    if_hp_less_than AI_ATTACKER_PARTNER, 50, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1980:
    if_knows_move AI_ATTACKER_PARTNER, 173, TrAI07_1FA0
    if_knows_move AI_ATTACKER_PARTNER, 214, TrAI07_1FA0
    if_hp_greater_than AI_ATTACKER_PARTNER, 40, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 2, 7, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 4, 7, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 7, 7, TrAI07_1CE4
    load_speed_order AI_ATTACKER
    if_not_equal 0, TrAI07_1FA0
    load_speed_order AI_ATTACKER_PARTNER
    if_not_equal 1, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1A06:
    if_knows_move AI_ATTACKER_PARTNER, 156, TrAI07_1FA0
    if_hp_less_than AI_ATTACKER_PARTNER, 80, TrAI07_1FA0
    load_speed_order AI_ATTACKER_PARTNER
    if_not_equal 3, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1A38:
    if_knows_move AI_ATTACKER_PARTNER, 156, TrAI07_1FA0
    if_hp_less_than AI_ATTACKER_PARTNER, 40, TrAI07_1FA0
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 2, 7, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 4, 7, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 7, 7, TrAI07_1CE4
    if_attack_less_than_sp_attack AI_ATTACKER_PARTNER, TrAI07_1FA0
    if_hp_greater_than AI_ATTACKER_PARTNER, 80, TrAI07_1CE4
    load_speed_order AI_ATTACKER
    if_not_equal 0, TrAI07_1FA0
    load_speed_order AI_ATTACKER_PARTNER
    if_not_equal 1, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1AC8:
    if_hp_greater_than AI_ATTACKER_PARTNER, 40, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 2, 7, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 4, 7, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 7, 7, TrAI07_1CE4
    load_speed_order AI_ATTACKER
    if_not_equal 0, TrAI07_1FA0
    load_speed_order AI_ATTACKER_PARTNER
    if_not_equal 1, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1B32:
    if_hp_greater_than AI_ATTACKER_PARTNER, 40, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 2, 7, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 4, 7, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 7, 7, TrAI07_1CE4
    load_speed_order AI_ATTACKER
    if_not_equal 0, TrAI07_1FA0
    load_speed_order AI_ATTACKER_PARTNER
    if_not_equal 1, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1B9C:
    if_knows_move AI_ATTACKER_PARTNER, 156, TrAI07_1FA0
    if_hp_greater_than AI_ATTACKER_PARTNER, 80, TrAI07_1CE4
    if_hp_less_than AI_ATTACKER_PARTNER, 40, TrAI07_1FA0
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 2, 7, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 4, 7, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 7, 7, TrAI07_1CE4
    jump TrAI07_1FA0
TrAI07_1C02:
    if_hp_less_than AI_ATTACKER_PARTNER, 40, TrAI07_1FA0
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 2, 7, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 4, 7, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 7, 7, TrAI07_1CE4
    if_hp_greater_than AI_ATTACKER_PARTNER, 80, TrAI07_1CE4
    load_speed_order AI_ATTACKER
    if_not_equal 0, TrAI07_1FA0
    load_speed_order AI_ATTACKER_PARTNER
    if_not_equal 1, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1C7A:
    if_hp_greater_than AI_ATTACKER_PARTNER, 40, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 2, 7, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 4, 7, TrAI07_1CE4
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 7, 7, TrAI07_1CE4
    load_speed_order AI_ATTACKER
    if_not_equal 0, TrAI07_1FA0
    load_speed_order AI_ATTACKER_PARTNER
    if_not_equal 1, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1CE4:
    if_turn_random_less_than 128, TrAI07_1CF4
    add_to_score 3
TrAI07_1CF4:
    end
TrAI07_1CF6:
    if_condition AI_ATTACKER_PARTNER, 16, TrAI07_1FA0
    load_known_ability_is AI_ATTACKER_PARTNER, 54
    if_equal 1, TrAI07_1D32
    load_known_ability_is AI_ATTACKER_PARTNER, 112
    if_equal 1, TrAI07_1D32
    jump TrAI07_1D38
TrAI07_1D32:
    add_to_score 5
TrAI07_1D38:
    end
TrAI07_1D3A:
    if_stat_stage_equal AI_ATTACKER_PARTNER, 1, 12, TrAI07_1FA0
    if_stat_stage_equal AI_ATTACKER_PARTNER, 2, 12, TrAI07_1FA0
    if_stat_stage_equal AI_ATTACKER_PARTNER, 5, 12, TrAI07_1FA0
    if_stat_stage_equal AI_ATTACKER_PARTNER, 3, 12, TrAI07_1FA0
    if_stat_stage_equal AI_ATTACKER_PARTNER, 4, 12, TrAI07_1FA0
    if_stat_stage_equal AI_ATTACKER_PARTNER, 7, 12, TrAI07_1FA0
    if_stat_stage_equal AI_ATTACKER_PARTNER, 6, 12, TrAI07_1FA0
    if_hp_less_than AI_ATTACKER_PARTNER, 51, TrAI07_1DF4
    if_hp_greater_than AI_ATTACKER_PARTNER, 90, TrAI07_1DDE
    if_random_less_than 128, TrAI07_1DFA
TrAI07_1DDE:
    if_random_less_than 80, TrAI07_1DFA
    add_to_score 2
    jump TrAI07_1DFA
TrAI07_1DF4:
    add_to_score -1
TrAI07_1DFA:
    end
TrAI07_1DFC:
    load_speed_order AI_ATTACKER
    if_not_equal 0, TrAI07_1FD8
    load_speed_order AI_ATTACKER_PARTNER
    if_equal 0, TrAI07_1FD8
    if_equal 1, TrAI07_1FD8
    if_knows_move_effect AI_DEFENDER, 313, TrAI07_1EB6
    if_field_effect 1, TrAI07_1E4C
    if_knows_move AI_DEFENDER, 433, TrAI07_1EB6
TrAI07_1E4C:
    if_knows_move_effect AI_DEFENDER, 190, TrAI07_1EB6
    if_knows_move AI_DEFENDER, 464, TrAI07_1EB6
    if_knows_move AI_DEFENDER, 59, TrAI07_1EB6
    if_knows_move AI_DEFENDER, 157, TrAI07_1EB6
    if_knows_move AI_DEFENDER, 157, TrAI07_1EB6
    if_knows_move_effect AI_DEFENDER, 28, TrAI07_1EC6
    if_random_less_than 50, TrAI07_1EC6
    add_to_score -2
    jump TrAI07_1EC6
TrAI07_1EB6:
    if_turn_random_less_than 128, TrAI07_1EC6
    add_to_score 3
TrAI07_1EC6:
    end
TrAI07_1EC8:
    if_hp_equal AI_DEFENDER, 0, TrAI07_1FA0
    if_hp_greater_than AI_DEFENDER, 100, TrAI07_1F98
    if_hp_greater_than AI_DEFENDER, 70, TrAI07_1F6C
    if_hp_greater_than AI_DEFENDER, 30, TrAI07_1F82
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 2, 7, TrAI07_1F82
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 4, 7, TrAI07_1F82
    if_stat_stage_greater_than AI_ATTACKER_PARTNER, 7, 7, TrAI07_1F82
    load_speed_order AI_ATTACKER
    if_equal 0, TrAI07_1F82
    load_speed_order AI_ATTACKER_PARTNER
    if_not_equal 0, TrAI07_1F98
    load_speed_order AI_ATTACKER
    if_equal 1, TrAI07_1F82
    jump TrAI07_1F98
TrAI07_1F6C:
    load_speed_order AI_ATTACKER
    if_equal 3, TrAI07_1F82
    jump TrAI07_1F98
TrAI07_1F82:
    if_turn_random_less_than 128, TrAI07_1F98
    add_to_score 3
    jump TrAI07_1F98
TrAI07_1F98:
    add_to_score -1
    end
TrAI07_1FA0:
    add_to_score -30
    end
    add_to_score -1
    end
TrAI07_1FB0:
    add_to_score -2
    end
TrAI07_1FB8:
    add_to_score -3
    end
TrAI07_1FC0:
    add_to_score -5
    end
    add_to_score -6
    end
TrAI07_1FD0:
    add_to_score -8
    end
TrAI07_1FD8:
    add_to_score -10
    end
    add_to_score -12
    end
TrAI07_1FE8:
    add_to_score -30
    end
TrAI07_1FF0:
    add_to_score 1
    end
TrAI07_1FF8:
    add_to_score 2
    end
TrAI07_2000:
    add_to_score 3
    end
TrAI07_2008:
    add_to_score 5
    end
TrAI07_2010:
    add_to_score 10
    end
