#include "asm/tr_ai.inc"

TrAI07_0000:
    load_battle_style
TrAI07_0002:
    if_equal BTL_STYLE_DOUBLE, TrAI07_0018
    if_equal BTL_STYLE_TRIPLE, TrAI07_0018
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
    if_effectiveness TYPE_EFFECTIVENESS_HALF, TrAI07_007A
    if_effectiveness TYPE_EFFECTIVENESS_QUARTER, TrAI07_00A8
    jump TrAI07_00D6
TrAI07_007A:
    if_can_faint 0, TrAI07_00D6
    if_hp_equal TRAI_SIDE_DEFENDER_PARTNER, 0, TrAI07_00D6
    if_random_less_than 64, TrAI07_00D6
    add_to_score -1
    jump TrAI07_00D6
TrAI07_00A8:
    if_can_faint 0, TrAI07_00D6
    if_hp_equal TRAI_SIDE_DEFENDER_PARTNER, 0, TrAI07_00D6
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
    if_effectiveness TYPE_EFFECTIVENESS_DOUBLE, TrAI07_0172
    if_effectiveness TYPE_EFFECTIVENESS_QUADRUPLE, TrAI07_0188
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
    if_move MOVE_BLIZZARD, TrAI07_0F5E
    if_move MOVE_BLIZZARD, TrAI07_0F5E
    if_move MOVE_BLIZZARD, TrAI07_0F5E
    if_move MOVE_WIDE_GUARD, TrAI07_0D98
    if_move MOVE_ROUND, TrAI07_0E22
    if_move MOVE_ALLY_SWITCH, TrAI07_0E4E
    if_move MOVE_QUASH, TrAI07_0F16
    if_move MOVE_BESTOW, TrAI07_0F10
    if_move MOVE_SKILL_SWAP, TrAI07_0B02
    load_type TRAI_TYPE_MOVE
    if_move MOVE_EARTHQUAKE, TrAI07_0986
    if_move MOVE_MAGNITUDE, TrAI07_0986
    if_move MOVE_FUTURE_SIGHT, TrAI07_0A12
    if_move MOVE_DOOM_DESIRE, TrAI07_0A12
    if_move MOVE_RAIN_DANCE, TrAI07_02D2
    if_move MOVE_SUNNY_DAY, TrAI07_034E
    if_move MOVE_HAIL, TrAI07_0482
    if_move MOVE_SANDSTORM, TrAI07_04FA
    if_move MOVE_GRAVITY, TrAI07_057E
    if_move MOVE_TRICK_ROOM, TrAI07_06BE
    if_move MOVE_FOLLOW_ME, TrAI07_07A6
    if_move MOVE_HEAL_PULSE, TrAI07_0FAA
    if_move MOVE_AFTER_YOU, TrAI07_0FAA
    if_move MOVE_HELPING_HAND, TrAI07_0FAA
    load_type TRAI_TYPE_MOVE
    if_equal TYPE_ELECTRIC, TrAI07_0B7E
    if_equal TYPE_FIRE, TrAI07_0CF2
    if_equal TYPE_WATER, TrAI07_0C52
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_HELPING_HAND, TrAI07_08E0
    end
TrAI07_02D2:
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_HYDRATION, TrAI07_02F2
    if_equal ABILITY_DRY_SKIN, TrAI07_02FC
    jump TrAI07_0308
TrAI07_02F2:
    if_no_status TRAI_SIDE_ATTACKER, TrAI07_0308
TrAI07_02FC:
    add_to_score 2
    jump TrAI07_0308
TrAI07_0308:
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_HYDRATION
    if_equal 1, TrAI07_0336
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_DRY_SKIN
    if_equal 1, TrAI07_0340
    jump TrAI07_034C
TrAI07_0336:
    if_no_status TRAI_SIDE_ATTACKER_PARTNER, TrAI07_034C
TrAI07_0340:
    add_to_score 2
    jump TrAI07_034C
TrAI07_034C:
    end
TrAI07_034E:
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_LEAF_GUARD, TrAI07_0382
    if_equal ABILITY_FLOWER_GIFT, TrAI07_039A
    if_equal ABILITY_DRY_SKIN, TrAI07_03A6
    if_equal ABILITY_SOLAR_POWER, TrAI07_03B2
    jump TrAI07_03D6
TrAI07_0382:
    if_status TRAI_SIDE_ATTACKER, TrAI07_03D6
    if_hp_less_than TRAI_SIDE_ATTACKER, 30, TrAI07_03D6
TrAI07_039A:
    add_to_score 2
    jump TrAI07_03D6
TrAI07_03A6:
    add_to_score -2
    jump TrAI07_03D6
TrAI07_03B2:
    if_hp_less_than TRAI_SIDE_ATTACKER, 50, TrAI07_03C6
    add_to_score 1
TrAI07_03C6:
    if_random_less_than 128, TrAI07_03D6
    add_to_score -2
TrAI07_03D6:
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_LEAF_GUARD
    if_equal 1, TrAI07_042C
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_FLOWER_GIFT
    if_equal 1, TrAI07_0444
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_DRY_SKIN
    if_equal 1, TrAI07_0450
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_SOLAR_POWER
    if_equal 1, TrAI07_045C
    jump TrAI07_0480
TrAI07_042C:
    if_status TRAI_SIDE_ATTACKER_PARTNER, TrAI07_0480
    if_hp_less_than TRAI_SIDE_ATTACKER_PARTNER, 30, TrAI07_0480
TrAI07_0444:
    add_to_score 2
    jump TrAI07_0480
TrAI07_0450:
    add_to_score -2
    jump TrAI07_0480
TrAI07_045C:
    if_hp_less_than TRAI_SIDE_ATTACKER_PARTNER, 50, TrAI07_0470
    add_to_score 1
TrAI07_0470:
    if_random_less_than 128, TrAI07_0480
    add_to_score -2
TrAI07_0480:
    end
TrAI07_0482:
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_ICE_BODY, TrAI07_04B0
    if_equal ABILITY_SNOW_CLOAK, TrAI07_04B0
    if_knows_move TRAI_SIDE_ATTACKER, MOVE_BLIZZARD, TrAI07_04B0
    jump TrAI07_04B6
TrAI07_04B0:
    add_to_score 2
TrAI07_04B6:
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_ICE_BODY
    if_equal 1, TrAI07_04F2
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_SNOW_CLOAK
    if_equal 1, TrAI07_04F2
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_BLIZZARD, TrAI07_04F2
    jump TrAI07_04F8
TrAI07_04F2:
    add_to_score 2
TrAI07_04F8:
    end
TrAI07_04FA:
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_SAND_VEIL, TrAI07_0530
    load_type TRAI_TYPE_ATTACKER_1
    if_equal TYPE_ROCK, TrAI07_0530
    load_type TRAI_TYPE_ATTACKER_2
    if_equal TYPE_ROCK, TrAI07_0530
    jump TrAI07_053C
TrAI07_0530:
    add_to_score 2
    jump TrAI07_053C
TrAI07_053C:
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_SAND_VEIL
    if_equal 1, TrAI07_0576
    load_type TRAI_TYPE_ATTACKER_PARTNER_1
    if_equal TYPE_ROCK, TrAI07_0576
    load_type TRAI_TYPE_ATTACKER_PARTNER_2
    if_equal TYPE_ROCK, TrAI07_0576
    jump TrAI07_057C
TrAI07_0576:
    add_to_score 2
TrAI07_057C:
    end
TrAI07_057E:
    if_field_effect 2, TrAI07_1FA0
    load_known_ability_is TRAI_SIDE_ATTACKER, ABILITY_LEVITATE
    if_equal 1, TrAI07_05C4
    load_has_type TRAI_SIDE_ATTACKER, TYPE_FLYING
    if_equal 1, TrAI07_05C4
    if_condition TRAI_SIDE_ATTACKER, 30, TrAI07_05C4
    jump TrAI07_05D0
TrAI07_05C4:
    add_to_score -5
    jump TrAI07_05D0
TrAI07_05D0:
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_LEVITATE
    if_equal 1, TrAI07_060C
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_FLYING
    if_equal 1, TrAI07_060C
    if_condition TRAI_SIDE_ATTACKER_PARTNER, 30, TrAI07_060C
    jump TrAI07_0618
TrAI07_060C:
    add_to_score -5
    jump TrAI07_0618
TrAI07_0618:
    load_known_ability_is TRAI_SIDE_DEFENDER, ABILITY_LEVITATE
    if_equal 1, TrAI07_0654
    load_has_type TRAI_SIDE_DEFENDER, TYPE_FLYING
    if_equal 1, TrAI07_0654
    if_condition TRAI_SIDE_DEFENDER, 30, TrAI07_0654
    jump TrAI07_066A
TrAI07_0654:
    if_random_less_than 64, TrAI07_066A
    add_to_score 3
    jump TrAI07_066A
TrAI07_066A:
    load_known_ability_is TRAI_SIDE_DEFENDER_PARTNER, ABILITY_LEVITATE
    if_equal 1, TrAI07_06A6
    load_has_type TRAI_SIDE_DEFENDER_PARTNER, TYPE_FLYING
    if_equal 1, TrAI07_06A6
    if_condition TRAI_SIDE_DEFENDER_PARTNER, 30, TrAI07_06A6
    jump TrAI07_06BC
TrAI07_06A6:
    if_random_less_than 64, TrAI07_06BC
    add_to_score 3
    jump TrAI07_06BC
TrAI07_06BC:
    end
TrAI07_06BE:
    if_hp_equal TRAI_SIDE_ATTACKER_PARTNER, 0, TrAI07_1FE8
    if_hp_equal TRAI_SIDE_DEFENDER_PARTNER, 0, TrAI07_1FE8
    if_hp_equal TRAI_SIDE_DEFENDER, 0, TrAI07_1FE8
    load_speed_order TRAI_SIDE_ATTACKER
    if_equal 0, TrAI07_071C
    if_equal 1, TrAI07_073C
    if_equal 2, TrAI07_0752
    if_equal 3, TrAI07_0778
    jump TrAI07_07A4
TrAI07_071C:
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_equal 1, TrAI07_1FE8
    if_equal 0, TrAI07_1FE8
    jump TrAI07_079E
TrAI07_073C:
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_equal 0, TrAI07_1FE8
    jump TrAI07_079E
TrAI07_0752:
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_not_equal 3, TrAI07_079E
    if_random_less_than 64, TrAI07_079E
    add_to_score 5
    jump TrAI07_07A4
TrAI07_0778:
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_not_equal 2, TrAI07_079E
    if_random_less_than 64, TrAI07_079E
    add_to_score 5
    jump TrAI07_07A4
TrAI07_079E:
    add_to_score -5
TrAI07_07A4:
    end
TrAI07_07A6:
    if_hp_greater_than TRAI_SIDE_ATTACKER, 90, TrAI07_07E0
    if_hp_greater_than TRAI_SIDE_ATTACKER, 50, TrAI07_0810
    if_hp_greater_than TRAI_SIDE_ATTACKER, 30, TrAI07_0840
    if_random_less_than 64, TrAI07_08DE
    jump TrAI07_1FC0
TrAI07_07E0:
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 90, TrAI07_0870
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 50, TrAI07_089C
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 30, TrAI07_08B2
    jump TrAI07_08C8
TrAI07_0810:
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 90, TrAI07_0886
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 50, TrAI07_0870
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 30, TrAI07_089C
    jump TrAI07_08B2
TrAI07_0840:
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 90, TrAI07_0886
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 50, TrAI07_0886
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 30, TrAI07_089C
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
    if_hp_greater_than TRAI_SIDE_ATTACKER, 50, TrAI07_0904
    load_speed_order TRAI_SIDE_ATTACKER
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
    if_status TRAI_SIDE_ATTACKER, TrAI07_0964
    end
TrAI07_0964:
    load_damage_rank 0
    if_equal 0, TrAI07_1FC0
    add_to_score 1
    if_equal 2, TrAI07_1FF8
    end
TrAI07_0986:
    if_condition TRAI_SIDE_ATTACKER_PARTNER, 30, TrAI07_1FF8
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_LEVITATE
    if_equal 1, TrAI07_1FF8
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_FLYING
    if_equal 1, TrAI07_1FF8
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_FIRE
    if_equal 1, TrAI07_1FD8
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_ELECTRIC
    if_equal 1, TrAI07_1FD8
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_POISON
    if_equal 1, TrAI07_1FD8
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_ROCK
    if_equal 1, TrAI07_1FD8
    jump TrAI07_1FB8
TrAI07_0A12:
    if_hp_equal TRAI_SIDE_ATTACKER_PARTNER, 0, TrAI07_0B00
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_FUTURE_SIGHT, TrAI07_0A42
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_DOOM_DESIRE, TrAI07_0A42
    jump TrAI07_0B00
TrAI07_0A42:
    load_speed_order TRAI_SIDE_ATTACKER
    if_equal 3, TrAI07_1FB8
    if_equal 2, TrAI07_0A76
    if_equal 1, TrAI07_0AB0
    if_equal 0, TrAI07_0AE0
    jump TrAI07_0B00
TrAI07_0A76:
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_equal 0, TrAI07_1FB8
    if_equal 1, TrAI07_1FB8
    if_random_less_than 128, TrAI07_0B00
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_equal 2, TrAI07_1FB8
    jump TrAI07_0B00
TrAI07_0AB0:
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_equal 0, TrAI07_1FB8
    if_random_less_than 128, TrAI07_0B00
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_equal 1, TrAI07_1FB8
    jump TrAI07_0B00
TrAI07_0AE0:
    if_random_less_than 128, TrAI07_0B00
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_equal 0, TrAI07_1FB8
    jump TrAI07_0B00
TrAI07_0B00:
    end
TrAI07_0B02:
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_TRUANT, TrAI07_2008
    if_equal ABILITY_SLOW_START, TrAI07_2008
    if_equal ABILITY_STALL, TrAI07_2008
    if_equal ABILITY_KLUTZ, TrAI07_2008
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_SHADOW_TAG, TrAI07_1FF8
    if_equal ABILITY_PURE_POWER, TrAI07_1FF8
    if_equal ABILITY_HUGE_POWER, TrAI07_1FF8
    if_equal ABILITY_MOLD_BREAKER, TrAI07_1FF8
    if_equal ABILITY_SOLID_ROCK, TrAI07_1FF8
    if_equal ABILITY_FILTER, TrAI07_1FF8
    if_equal ABILITY_FLOWER_GIFT, TrAI07_1FF8
    end
TrAI07_0B7E:
    if_move MOVE_DISCHARGE, TrAI07_0BE6
    load_known_ability_is TRAI_SIDE_DEFENDER_PARTNER, ABILITY_LIGHTNINGROD
    if_equal 1, TrAI07_0BA2
    jump TrAI07_0BC2
TrAI07_0BA2:
    add_to_score -1
    load_has_type TRAI_SIDE_DEFENDER_PARTNER, TYPE_GROUND
    if_equal 0, TrAI07_0BC2
    add_to_score -8
TrAI07_0BC2:
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_LIGHTNINGROD
    if_equal 1, TrAI07_1FD8
    if_move MOVE_DISCHARGE, TrAI07_0BE6
    jump TrAI07_0C50
TrAI07_0BE6:
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_MOTOR_DRIVE
    if_equal 1, TrAI07_2000
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_VOLT_ABSORB
    if_equal 1, TrAI07_2000
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_WATER
    if_equal 1, TrAI07_1FD8
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_FLYING
    if_equal 1, TrAI07_1FD8
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_GROUND
    if_equal 1, TrAI07_2000
    add_to_score -3
TrAI07_0C50:
    end
TrAI07_0C52:
    if_move MOVE_SURF, TrAI07_0C9A
    load_known_ability_is TRAI_SIDE_DEFENDER_PARTNER, ABILITY_STORM_DRAIN
    if_equal 0, TrAI07_0C76
    add_to_score -1
TrAI07_0C76:
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_STORM_DRAIN
    if_equal 1, TrAI07_1FD8
    if_move MOVE_SURF, TrAI07_0C9A
    jump TrAI07_0CF0
TrAI07_0C9A:
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_DRY_SKIN
    if_equal 1, TrAI07_2000
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_WATER_ABSORB
    if_equal 1, TrAI07_2000
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_GROUND
    if_equal 1, TrAI07_1FD8
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_FIRE
    if_equal 1, TrAI07_1FD8
    add_to_score -3
TrAI07_0CF0:
    end
TrAI07_0CF2:
    if_flash_fire TRAI_SIDE_ATTACKER, TrAI07_0D02
    jump TrAI07_0D08
TrAI07_0D02:
    add_to_score 1
TrAI07_0D08:
    if_move MOVE_LAVA_PLUME, TrAI07_0D18
    jump TrAI07_0D96
TrAI07_0D18:
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_DRY_SKIN
    if_equal 1, TrAI07_1FB8
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_FLASH_FIRE
    if_equal 1, TrAI07_2000
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_GRASS
    if_equal 1, TrAI07_1FD8
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_STEEL
    if_equal 1, TrAI07_1FD8
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_ICE
    if_equal 1, TrAI07_1FD8
    load_has_type TRAI_SIDE_ATTACKER_PARTNER, TYPE_BUG
    if_equal 1, TrAI07_1FD8
    add_to_score -3
TrAI07_0D96:
    end
TrAI07_0D98:
    if_random_less_than 50, TrAI07_0DB2
    load_last_move TRAI_SIDE_ATTACKER
    if_equal MOVE_WIDE_GUARD, TrAI07_0DC4
TrAI07_0DB2:
    load_last_move TRAI_SIDE_DEFENDER
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
    .4byte MOVE_BLIZZARD
    .4byte MOVE_ROCK_SLIDE
    .4byte MOVE_HEAT_WAVE
    .4byte MOVE_ERUPTION
    .4byte MOVE_WATER_SPOUT
    .4byte MOVE_MUDDY_WATER
    .4byte MOVE_GLACIATE
    .4byte MOVE_SNARL
    .4byte MOVE_SURF
    .4byte MOVE_EARTHQUAKE
    .4byte MOVE_DISCHARGE
    .4byte MOVE_LAVA_PLUME
    .4byte MOVE_SLUDGE_WAVE
    .4byte MOVE_BULLDOZE
    .4byte MOVE_SEARING_SHOT
    list_end
TrAI07_0E22:
    if_not_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_ROUND, TrAI07_0E46
    if_turn_random_less_than 128, TrAI07_0E46
    add_to_score 3
    jump TrAI07_0E4C
TrAI07_0E46:
    add_to_score -1
TrAI07_0E4C:
    end
TrAI07_0E4E:
    load_species TRAI_SIDE_DEFENDER
    if_in_list TrAI07_0E9C, TrAI07_0E64
    jump TrAI07_0E9A
TrAI07_0E64:
    load_fake_out_active TRAI_SIDE_DEFENDER
    if_not_equal 0, TrAI07_0E9A
    if_random_less_than 128, TrAI07_0E9A
    add_to_score 2
    jump TrAI07_0E9A
    if_random_less_than 128, TrAI07_0E9A
    add_to_score -1
TrAI07_0E9A:
    end
TrAI07_0E9C:
    .4byte SPECIES_BLASTOISE
    .4byte SPECIES_PERSIAN
    .4byte SPECIES_DEWGONG
    .4byte SPECIES_KANGASKHAN
    .4byte SPECIES_MR_MIME
    .4byte SPECIES_PIKACHU
    .4byte SPECIES_RAICHU
    .4byte SPECIES_AMBIPOM
    .4byte SPECIES_WEAVILE
    .4byte SPECIES_HITMONCHAN
    .4byte SPECIES_HITMONLEE
    .4byte SPECIES_HITMONTOP
    .4byte SPECIES_JYNX
    .4byte SPECIES_LUDICOLO
    .4byte SPECIES_SHIFTRY
    .4byte SPECIES_HARIYAMA
    .4byte SPECIES_DELCATTY
    .4byte SPECIES_SABLEYE
    .4byte SPECIES_MEDICHAM
    .4byte SPECIES_SPINDA
    .4byte SPECIES_KECLEON
    .4byte SPECIES_INFERNAPE
    .4byte SPECIES_LOPUNNY
    .4byte SPECIES_PURUGLY
    .4byte SPECIES_CROAGUNK
    .4byte SPECIES_DELIBIRD
    .4byte SPECIES_SCRAFTY
    .4byte SPECIES_LIEPARD
    list_end
TrAI07_0F10:
    jump TrAI07_1FD8
TrAI07_0F16:
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_equal 0, TrAI07_1FD8
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_equal 1, TrAI07_1FD8
    load_speed_order TRAI_SIDE_ATTACKER
    if_equal 0, TrAI07_0F4C
    jump TrAI07_1FD8
TrAI07_0F4C:
    if_turn_random_less_than 128, TrAI07_0F5C
    add_to_score 1
TrAI07_0F5C:
    end
TrAI07_0F5E:
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_AFTER_YOU, TrAI07_0F6E
    end
TrAI07_0F6E:
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_not_equal 0, TrAI07_1FD8
    load_speed_order TRAI_SIDE_ATTACKER
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
    if_fainted TRAI_SIDE_ATTACKER_PARTNER, TrAI07_1FA0
    load_damage_rank 0
    if_equal 0, TrAI07_1236
    load_type TRAI_TYPE_MOVE
    if_equal TYPE_FIRE, TrAI07_1000
    if_equal TYPE_ELECTRIC, TrAI07_1058
    if_equal TYPE_WATER, TrAI07_116A
    if_move MOVE_FLING, TrAI07_173C
TrAI07_0FFA:
    jump TrAI07_1FE8
TrAI07_1000:
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_FLASH_FIRE
    if_equal 1, TrAI07_101A
    jump TrAI07_0FFA
TrAI07_101A:
    if_flash_fire TRAI_SIDE_ATTACKER_PARTNER, TrAI07_0FFA
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI07_0FFA
    if_equal ABILITY_TURBOBLAZE, TrAI07_0FFA
    if_equal ABILITY_TERAVOLT, TrAI07_0FFA
    if_random_less_than 150, TrAI07_0FFA
    jump TrAI07_1FF0
TrAI07_1058:
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_MOTOR_DRIVE
    if_equal 1, TrAI07_1086
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_VOLT_ABSORB
    if_equal 1, TrAI07_10CC
    jump TrAI07_0FFA
TrAI07_1086:
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI07_0FFA
    if_equal ABILITY_TURBOBLAZE, TrAI07_0FFA
    if_equal ABILITY_TERAVOLT, TrAI07_0FFA
    if_random_less_than 160, TrAI07_1168
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 5, 7, TrAI07_0FFA
    jump TrAI07_1FF0
TrAI07_10CC:
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI07_0FFA
    if_equal ABILITY_TURBOBLAZE, TrAI07_0FFA
    if_equal ABILITY_TERAVOLT, TrAI07_0FFA
    if_random_less_than 150, TrAI07_0FFA
    if_hp_equal TRAI_SIDE_ATTACKER_PARTNER, 100, TrAI07_1FD8
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 90, TrAI07_1168
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 75, TrAI07_1138
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 50, TrAI07_1148
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
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_WATER_ABSORB
    if_equal 1, TrAI07_1198
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_DRY_SKIN
    if_equal 1, TrAI07_1198
    jump TrAI07_0FFA
TrAI07_1198:
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI07_0FFA
    if_equal ABILITY_TURBOBLAZE, TrAI07_0FFA
    if_equal ABILITY_TERAVOLT, TrAI07_0FFA
    if_random_less_than 150, TrAI07_0FFA
    if_hp_equal TRAI_SIDE_ATTACKER_PARTNER, 100, TrAI07_1FD8
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 90, TrAI07_1234
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 75, TrAI07_1204
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 50, TrAI07_1214
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
    if_move MOVE_SKILL_SWAP, TrAI07_12D2
    if_move MOVE_ROLE_PLAY, TrAI07_14F2
    if_move MOVE_WILL_O_WISP, TrAI07_157E
    if_move MOVE_THUNDER_WAVE, TrAI07_1600
    if_move_effect 33, TrAI07_164E
    if_move_effect 66, TrAI07_164E
    if_move MOVE_HELPING_HAND, TrAI07_168E
    if_move MOVE_SWAGGER, TrAI07_16D8
    if_move MOVE_TRICK, TrAI07_173C
    if_move MOVE_SWITCHEROO, TrAI07_173C
    if_move MOVE_BESTOW, TrAI07_173C
    if_move MOVE_GASTRO_ACID, TrAI07_1CF6
    if_move MOVE_ACUPRESSURE, TrAI07_1D3A
    if_move MOVE_AFTER_YOU, TrAI07_1DFC
    if_move MOVE_HEAL_PULSE, TrAI07_1EC8
    jump TrAI07_1FA0
TrAI07_12D2:
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_TRUANT, TrAI07_2010
    if_equal ABILITY_SLOW_START, TrAI07_2010
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_LEVITATE, TrAI07_132A
    if_equal ABILITY_COMPOUNDEYES, TrAI07_13C2
    if_equal ABILITY_NO_GUARD, TrAI07_13C2
    if_equal ABILITY_INSOMNIA, TrAI07_14CA
    if_equal ABILITY_OWN_TEMPO, TrAI07_14DE
    jump TrAI07_1FA0
TrAI07_132A:
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_LEVITATE, TrAI07_1FD8
    load_type TRAI_TYPE_DEFENDER_1
    if_equal TYPE_FLYING, TrAI07_1FD0
    load_type TRAI_TYPE_DEFENDER_2
    if_equal TYPE_FLYING, TrAI07_1FD0
    load_type TRAI_TYPE_DEFENDER_1
    if_equal TYPE_GRASS, TrAI07_1FC0
    if_equal TYPE_BUG, TrAI07_1FC0
    load_type TRAI_TYPE_DEFENDER_2
    if_equal TYPE_GRASS, TrAI07_1FC0
    if_equal TYPE_BUG, TrAI07_1FC0
    if_condition TRAI_SIDE_DEFENDER, 30, TrAI07_1FB0
    load_type TRAI_TYPE_DEFENDER_1
    if_equal TYPE_ELECTRIC, TrAI07_2000
    load_type TRAI_TYPE_DEFENDER_2
    if_equal TYPE_ELECTRIC, TrAI07_2000
    jump TrAI07_1FA0
TrAI07_13C2:
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_FIRE_BLAST, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_THUNDER, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_CROSS_CHOP, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_HYDRO_PUMP, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_DYNAMIC_PUNCH, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_BLIZZARD, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_ZAP_CANNON, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_MEGAHORN, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_FOCUS_BLAST, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_GUNK_SHOT, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_MAGMA_STORM, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_POWER_WHIP, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_SEED_FLARE, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_HEAD_SMASH, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_SHEER_COLD, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_FISSURE, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_GUILLOTINE, TrAI07_14C4
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_HORN_DRILL, TrAI07_14C4
    jump TrAI07_1FA0
TrAI07_14C4:
    jump TrAI07_2000
TrAI07_14CA:
    if_not_condition TRAI_SIDE_DEFENDER, 2, TrAI07_1FD0
    jump TrAI07_2000
TrAI07_14DE:
    if_not_condition TRAI_SIDE_DEFENDER, 6, TrAI07_1FD0
    jump TrAI07_2000
TrAI07_14F2:
    load_known_ability TRAI_SIDE_DEFENDER
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
    .4byte ABILITY_TELEPATHY
    .4byte ABILITY_FRIEND_GUARD
    .4byte ABILITY_SPEED_BOOST
    .4byte ABILITY_INTIMIDATE
    .4byte ABILITY_PURE_POWER
    .4byte ABILITY_CURSED_BODY
    list_end
TrAI07_154A:
    .4byte ABILITY_SOLAR_POWER
    .4byte ABILITY_DRY_SKIN
    .4byte ABILITY_MOTOR_DRIVE
    .4byte ABILITY_RAIN_DISH
    .4byte ABILITY_HUGE_POWER
    .4byte ABILITY_CHLOROPHYLL
    .4byte ABILITY_SWIFT_SWIM
    .4byte ABILITY_ICE_BODY
    .4byte ABILITY_HARVEST
    .4byte ABILITY_SAND_RUSH
    .4byte ABILITY_MAGIC_BOUNCE
    .4byte ABILITY_PRANKSTER
    list_end
TrAI07_157E:
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_FLASH_FIRE
    if_equal 1, TrAI07_1000
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_GUTS
    if_not_equal 1, TrAI07_1FA0
    if_status TRAI_SIDE_ATTACKER_PARTNER, TrAI07_1FA0
    load_type TRAI_TYPE_DEFENDER_1
    if_equal TYPE_FIRE, TrAI07_1FA0
    load_type TRAI_TYPE_DEFENDER_2
    if_equal TYPE_FIRE, TrAI07_1FA0
    if_held_item TRAI_SIDE_ATTACKER_PARTNER, ITEM_FLAME_ORB, TrAI07_1FA0
    if_held_item TRAI_SIDE_ATTACKER_PARTNER, ITEM_TOXIC_ORB, TrAI07_1FA0
    if_hp_less_than TRAI_SIDE_ATTACKER_PARTNER, 81, TrAI07_1FA0
    jump TrAI07_2008
TrAI07_1600:
    load_type TRAI_TYPE_DEFENDER_1
    if_equal TYPE_GROUND, TrAI07_1FA0
    load_type TRAI_TYPE_DEFENDER_2
    if_equal TYPE_GROUND, TrAI07_1FA0
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_MOTOR_DRIVE
    if_equal 1, TrAI07_1058
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_VOLT_ABSORB
    if_equal 1, TrAI07_1058
    jump TrAI07_1FA0
TrAI07_164E:
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_POISON_HEAL
    if_not_equal 1, TrAI07_1FA0
    if_status TRAI_SIDE_DEFENDER, TrAI07_1FA0
    if_held_item TRAI_SIDE_ATTACKER_PARTNER, ITEM_TOXIC_ORB, TrAI07_1FA0
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 91, TrAI07_1FA0
    jump TrAI07_2008
TrAI07_168E:
    if_hp_equal TRAI_SIDE_ATTACKER_PARTNER, 0, TrAI07_1FE8
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 50, TrAI07_16C6
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_less_than 1, TrAI07_16C6
    add_to_score -1
    jump TrAI07_16D6
TrAI07_16C6:
    if_turn_random_less_than 128, TrAI07_16D6
    add_to_score 3
TrAI07_16D6:
    end
TrAI07_16D8:
    if_attack_less_than_sp_attack TRAI_SIDE_DEFENDER, TrAI07_171C
    if_held_item TRAI_SIDE_DEFENDER, ITEM_PERSIM_BERRY, TrAI07_1722
    if_held_item TRAI_SIDE_DEFENDER, ITEM_LUM_BERRY, TrAI07_1722
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_OWN_TEMPO, TrAI07_1722
    if_side_effect TRAI_SIDE_DEFENDER, 2, TrAI07_1722
TrAI07_171C:
    jump TrAI07_1FA0
TrAI07_1722:
    if_stat_stage_greater_than TRAI_SIDE_DEFENDER, 1, 7, TrAI07_173A
    add_to_score 3
TrAI07_173A:
    end
TrAI07_173C:
    if_held_item TRAI_SIDE_ATTACKER, ITEM_LUM_BERRY, TrAI07_17CE
    if_held_item TRAI_SIDE_ATTACKER, ITEM_CHESTO_BERRY, TrAI07_1824
    if_held_item TRAI_SIDE_ATTACKER, ITEM_CHERI_BERRY, TrAI07_1838
    if_held_item TRAI_SIDE_ATTACKER, ITEM_RAWST_BERRY, TrAI07_184C
    if_held_item TRAI_SIDE_ATTACKER, ITEM_ASPEAR_BERRY, TrAI07_1860
    if_held_item TRAI_SIDE_ATTACKER, ITEM_PECHA_BERRY, TrAI07_1874
    if_held_item TRAI_SIDE_ATTACKER, ITEM_PERSIM_BERRY, TrAI07_1884
    if_held_item TRAI_SIDE_ATTACKER, ITEM_WHITE_HERB, TrAI07_1898
    if_held_item TRAI_SIDE_ATTACKER, ITEM_SITRUS_BERRY, TrAI07_196C
    if_held_item TRAI_SIDE_ATTACKER, ITEM_MENTAL_HERB, TrAI07_192E
    jump TrAI07_1FA0
TrAI07_17CE:
    if_condition TRAI_SIDE_DEFENDER, 2, TrAI07_1980
    if_condition TRAI_SIDE_DEFENDER, 1, TrAI07_1A06
    if_condition TRAI_SIDE_DEFENDER, 3, TrAI07_1A38
    if_condition TRAI_SIDE_DEFENDER, 3, TrAI07_1AC8
    if_badly_poisoned TRAI_SIDE_DEFENDER, TrAI07_1B9C
    if_condition TRAI_SIDE_DEFENDER, 6, TrAI07_1B32
    jump TrAI07_1FA0
TrAI07_1824:
    if_condition TRAI_SIDE_DEFENDER, 2, TrAI07_1980
    jump TrAI07_1FA0
TrAI07_1838:
    if_condition TRAI_SIDE_DEFENDER, 1, TrAI07_1A06
    jump TrAI07_1FA0
TrAI07_184C:
    if_condition TRAI_SIDE_DEFENDER, 3, TrAI07_1A38
    jump TrAI07_1FA0
TrAI07_1860:
    if_condition TRAI_SIDE_DEFENDER, 3, TrAI07_1AC8
    jump TrAI07_1FA0
TrAI07_1874:
    if_badly_poisoned TRAI_SIDE_DEFENDER, TrAI07_1B9C
    jump TrAI07_1FA0
TrAI07_1884:
    if_condition TRAI_SIDE_DEFENDER, 6, TrAI07_1B32
    jump TrAI07_1FA0
TrAI07_1898:
    if_stat_stage_less_than TRAI_SIDE_ATTACKER_PARTNER, 1, 5, TrAI07_1C02
    if_stat_stage_less_than TRAI_SIDE_ATTACKER_PARTNER, 2, 5, TrAI07_1C02
    if_stat_stage_less_than TRAI_SIDE_ATTACKER_PARTNER, 3, 5, TrAI07_1C02
    if_stat_stage_less_than TRAI_SIDE_ATTACKER_PARTNER, 4, 5, TrAI07_1C02
    if_stat_stage_less_than TRAI_SIDE_ATTACKER_PARTNER, 7, 5, TrAI07_1C02
    if_stat_stage_less_than TRAI_SIDE_ATTACKER_PARTNER, 5, 5, TrAI07_1C02
    if_stat_stage_less_than TRAI_SIDE_ATTACKER_PARTNER, 4, 5, TrAI07_1C02
    if_stat_stage_less_than TRAI_SIDE_ATTACKER_PARTNER, 7, 5, TrAI07_1C02
    jump TrAI07_1FA0
TrAI07_192E:
    if_condition TRAI_SIDE_DEFENDER, 7, TrAI07_1C7A
    if_condition TRAI_SIDE_DEFENDER, 6, TrAI07_1B32
    if_condition TRAI_SIDE_DEFENDER, 12, TrAI07_1C7A
    if_condition TRAI_SIDE_DEFENDER, 11, TrAI07_1C7A
    jump TrAI07_1FA0
TrAI07_196C:
    if_hp_less_than TRAI_SIDE_ATTACKER_PARTNER, 50, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1980:
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_SNORE, TrAI07_1FA0
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_SLEEP_TALK, TrAI07_1FA0
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 40, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 2, 7, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 4, 7, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 7, 7, TrAI07_1CE4
    load_speed_order TRAI_SIDE_ATTACKER
    if_not_equal 0, TrAI07_1FA0
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_not_equal 1, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1A06:
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_REST, TrAI07_1FA0
    if_hp_less_than TRAI_SIDE_ATTACKER_PARTNER, 80, TrAI07_1FA0
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_not_equal 3, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1A38:
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_REST, TrAI07_1FA0
    if_hp_less_than TRAI_SIDE_ATTACKER_PARTNER, 40, TrAI07_1FA0
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 2, 7, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 4, 7, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 7, 7, TrAI07_1CE4
    if_attack_less_than_sp_attack TRAI_SIDE_ATTACKER_PARTNER, TrAI07_1FA0
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 80, TrAI07_1CE4
    load_speed_order TRAI_SIDE_ATTACKER
    if_not_equal 0, TrAI07_1FA0
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_not_equal 1, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1AC8:
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 40, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 2, 7, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 4, 7, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 7, 7, TrAI07_1CE4
    load_speed_order TRAI_SIDE_ATTACKER
    if_not_equal 0, TrAI07_1FA0
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_not_equal 1, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1B32:
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 40, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 2, 7, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 4, 7, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 7, 7, TrAI07_1CE4
    load_speed_order TRAI_SIDE_ATTACKER
    if_not_equal 0, TrAI07_1FA0
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_not_equal 1, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1B9C:
    if_knows_move TRAI_SIDE_ATTACKER_PARTNER, MOVE_REST, TrAI07_1FA0
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 80, TrAI07_1CE4
    if_hp_less_than TRAI_SIDE_ATTACKER_PARTNER, 40, TrAI07_1FA0
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 2, 7, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 4, 7, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 7, 7, TrAI07_1CE4
    jump TrAI07_1FA0
TrAI07_1C02:
    if_hp_less_than TRAI_SIDE_ATTACKER_PARTNER, 40, TrAI07_1FA0
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 2, 7, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 4, 7, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 7, 7, TrAI07_1CE4
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 80, TrAI07_1CE4
    load_speed_order TRAI_SIDE_ATTACKER
    if_not_equal 0, TrAI07_1FA0
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_not_equal 1, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1C7A:
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 40, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 2, 7, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 4, 7, TrAI07_1CE4
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 7, 7, TrAI07_1CE4
    load_speed_order TRAI_SIDE_ATTACKER
    if_not_equal 0, TrAI07_1FA0
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_not_equal 1, TrAI07_1FA0
    jump TrAI07_1CE4
TrAI07_1CE4:
    if_turn_random_less_than 128, TrAI07_1CF4
    add_to_score 3
TrAI07_1CF4:
    end
TrAI07_1CF6:
    if_condition TRAI_SIDE_ATTACKER_PARTNER, 16, TrAI07_1FA0
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_TRUANT
    if_equal 1, TrAI07_1D32
    load_known_ability_is TRAI_SIDE_ATTACKER_PARTNER, ABILITY_SLOW_START
    if_equal 1, TrAI07_1D32
    jump TrAI07_1D38
TrAI07_1D32:
    add_to_score 5
TrAI07_1D38:
    end
TrAI07_1D3A:
    if_stat_stage_equal TRAI_SIDE_ATTACKER_PARTNER, 1, 12, TrAI07_1FA0
    if_stat_stage_equal TRAI_SIDE_ATTACKER_PARTNER, 2, 12, TrAI07_1FA0
    if_stat_stage_equal TRAI_SIDE_ATTACKER_PARTNER, 5, 12, TrAI07_1FA0
    if_stat_stage_equal TRAI_SIDE_ATTACKER_PARTNER, 3, 12, TrAI07_1FA0
    if_stat_stage_equal TRAI_SIDE_ATTACKER_PARTNER, 4, 12, TrAI07_1FA0
    if_stat_stage_equal TRAI_SIDE_ATTACKER_PARTNER, 7, 12, TrAI07_1FA0
    if_stat_stage_equal TRAI_SIDE_ATTACKER_PARTNER, 6, 12, TrAI07_1FA0
    if_hp_less_than TRAI_SIDE_ATTACKER_PARTNER, 51, TrAI07_1DF4
    if_hp_greater_than TRAI_SIDE_ATTACKER_PARTNER, 90, TrAI07_1DDE
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
    load_speed_order TRAI_SIDE_ATTACKER
    if_not_equal 0, TrAI07_1FD8
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_equal 0, TrAI07_1FD8
    if_equal 1, TrAI07_1FD8
    if_knows_move_effect TRAI_SIDE_DEFENDER, 313, TrAI07_1EB6
    if_field_effect 1, TrAI07_1E4C
    if_knows_move TRAI_SIDE_DEFENDER, MOVE_TRICK_ROOM, TrAI07_1EB6
TrAI07_1E4C:
    if_knows_move_effect TRAI_SIDE_DEFENDER, 190, TrAI07_1EB6
    if_knows_move TRAI_SIDE_DEFENDER, MOVE_DARK_VOID, TrAI07_1EB6
    if_knows_move TRAI_SIDE_DEFENDER, MOVE_BLIZZARD, TrAI07_1EB6
    if_knows_move TRAI_SIDE_DEFENDER, MOVE_ROCK_SLIDE, TrAI07_1EB6
    if_knows_move TRAI_SIDE_DEFENDER, MOVE_ROCK_SLIDE, TrAI07_1EB6
    if_knows_move_effect TRAI_SIDE_DEFENDER, 28, TrAI07_1EC6
    if_random_less_than 50, TrAI07_1EC6
    add_to_score -2
    jump TrAI07_1EC6
TrAI07_1EB6:
    if_turn_random_less_than 128, TrAI07_1EC6
    add_to_score 3
TrAI07_1EC6:
    end
TrAI07_1EC8:
    if_hp_equal TRAI_SIDE_DEFENDER, 0, TrAI07_1FA0
    if_hp_greater_than TRAI_SIDE_DEFENDER, 100, TrAI07_1F98
    if_hp_greater_than TRAI_SIDE_DEFENDER, 70, TrAI07_1F6C
    if_hp_greater_than TRAI_SIDE_DEFENDER, 30, TrAI07_1F82
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 2, 7, TrAI07_1F82
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 4, 7, TrAI07_1F82
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER_PARTNER, 7, 7, TrAI07_1F82
    load_speed_order TRAI_SIDE_ATTACKER
    if_equal 0, TrAI07_1F82
    load_speed_order TRAI_SIDE_ATTACKER_PARTNER
    if_not_equal 0, TrAI07_1F98
    load_speed_order TRAI_SIDE_ATTACKER
    if_equal 1, TrAI07_1F82
    jump TrAI07_1F98
TrAI07_1F6C:
    load_speed_order TRAI_SIDE_ATTACKER
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
