@ Macros for the trainer AI scripts, written by tools/scripts/tr_ai_script.py inc

    .set AI_DEFENDER, 0
    .set AI_ATTACKER, 1
    .set AI_DEFENDER_PARTNER, 2
    .set AI_ATTACKER_PARTNER, 3

    .macro ai_cmd id
    .2byte \id
    .endm

    .macro list_end
    .4byte 0xffffffff
    .endm

    @ AIGreaterThanRandom: jumps if a random number below 256 is less than value
    .macro if_random_less_than a0, a1
    ai_cmd 0
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AILessThanRandom
    .macro if_random_greater_than a0, a1
    ai_cmd 1
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIEqualToRandom
    .macro if_random_equal a0, a1
    ai_cmd 2
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AINotEqualToRandom
    .macro if_random_not_equal a0, a1
    ai_cmd 3
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIncrementScore: adds a signed value to the move's score, which stays at least 0
    .macro add_to_score a0
    ai_cmd 4
    .4byte \a0
    .endm

    @ AIIsHPLessThan: compares the HP percentage
    .macro if_hp_less_than a0, a1, a2
    ai_cmd 5
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIIsHPGreaterThan
    .macro if_hp_greater_than a0, a1, a2
    ai_cmd 6
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIIsHPEqualTo
    .macro if_hp_equal a0, a1, a2
    ai_cmd 7
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIIsHPNotEqualTo
    .macro if_hp_not_equal a0, a1, a2
    ai_cmd 8
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIHasStatus: jumps if the Pokemon has a status
    .macro if_status a0, a1
    ai_cmd 9
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIDoesNotHaveStatus
    .macro if_no_status a0, a1
    ai_cmd 10
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIHasCondition
    .macro if_condition a0, a1, a2
    ai_cmd 11
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIDoesNotHaveCondition
    .macro if_not_condition a0, a1, a2
    ai_cmd 12
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIIsBadlyPoisoned
    .macro if_badly_poisoned a0, a1
    ai_cmd 13
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIsNotBadlyPoisoned
    .macro if_not_badly_poisoned a0, a1
    ai_cmd 14
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIHasConditionFlag
    .macro if_condition_flag a0, a1, a2
    ai_cmd 15
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIDoesNotHaveConditionFlag
    .macro if_not_condition_flag a0, a1, a2
    ai_cmd 16
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIIfSideEffect
    .macro if_side_effect a0, a1, a2
    ai_cmd 17
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIIfNotSideEffect
    .macro if_not_side_effect a0, a1, a2
    ai_cmd 18
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIIfLessThan: compares the result
    .macro if_less_than a0, a1
    ai_cmd 19
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfGreaterThan
    .macro if_greater_than a0, a1
    ai_cmd 20
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfEqual
    .macro if_equal a0, a1
    ai_cmd 21
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfNotEqual
    .macro if_not_equal a0, a1
    ai_cmd 22
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfBit: jumps if the result has any of the bits
    .macro if_bits_set a0, a1
    ai_cmd 23
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfNotBit
    .macro if_bits_clear a0, a1
    ai_cmd 24
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfMove: compares the move being scored
    .macro if_move a0, a1
    ai_cmd 25
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfNotMove
    .macro if_not_move a0, a1
    ai_cmd 26
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfResultInList
    .macro if_in_list a0, a1
    ai_cmd 27
    .4byte \a0 - (. + 4)
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfResultNotInList
    .macro if_not_in_list a0, a1
    ai_cmd 28
    .4byte \a0 - (. + 4)
    .4byte \a1 - (. + 4)
    .endm

    @ AIHasDamagingMove: jumps if the attacker has a move with power
    .macro if_has_damaging_move a0
    ai_cmd 29
    .4byte \a0 - (. + 4)
    .endm

    @ AIDoesNotHaveDamagingMove
    .macro if_no_damaging_move a0
    ai_cmd 30
    .4byte \a0 - (. + 4)
    .endm

    @ AIGetTurnCount
    .macro load_turn_count
    ai_cmd 31
    .endm

    @ AIGetType
    .macro load_type a0
    ai_cmd 32
    .4byte \a0
    .endm

    @ AIGetBasePower: the base power of the move being scored
    .macro load_power
    ai_cmd 33
    .endm

    @ AIGetHighestDamagingMove: 0 if the move deals no damage, 1 if another move deals more, 2 otherwise
    .macro load_damage_rank a0
    ai_cmd 34
    .4byte \a0
    .endm

    @ AIGetPreviousMove
    .macro load_last_move a0
    ai_cmd 35
    .4byte \a0
    .endm

    @ AIIfEqual, a second ID
    .macro if_equal_2 a0, a1
    ai_cmd 36
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfNotEqual, a second ID
    .macro if_not_equal_2 a0, a1
    ai_cmd 37
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AICompareSpeed: 0 jumps if the attacker is faster, 1 if slower, 2 if equal
    .macro if_speed_compare a0, a1
    ai_cmd 38
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AICheckTeamCount: the party's Pokemon that aren't in battle and can battle
    .macro load_able_party_count a0
    ai_cmd 39
    .4byte \a0
    .endm

    @ AICheckMoveID: the move being scored
    .macro load_move
    ai_cmd 40
    .endm

    @ AICheckMoveEffect
    .macro load_move_effect
    ai_cmd 41
    .endm

    @ AICheckAbility: the ability the AI knows or guesses
    .macro load_known_ability a0
    ai_cmd 42
    .4byte \a0
    .endm

    @ AINop43
    .macro nop_43
    ai_cmd 43
    .endm

    @ AIIfTypeEffectiveness: TYPE_EFFECTIVENESS_* of the move being scored
    .macro if_effectiveness a0, a1
    ai_cmd 44
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfStatusInParty: jumps if a party member that isn't in battle has no status
    .macro if_party_member_no_status a0, a1
    ai_cmd 45
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfStatusNotInParty
    .macro if_party_member_status a0, a1
    ai_cmd 46
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIGetWeather
    .macro load_weather
    ai_cmd 47
    .endm

    @ AIHasMoveID: compares the effect of the move being scored
    .macro if_move_effect a0, a1
    ai_cmd 48
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIDoesNotHaveMoveID
    .macro if_not_move_effect a0, a1
    ai_cmd 49
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIStatStageLessThan: stat, then stage
    .macro if_stat_stage_less_than a0, a1, a2, a3
    ai_cmd 50
    .4byte \a0
    .4byte \a1
    .4byte \a2
    .4byte \a3 - (. + 4)
    .endm

    @ AIStatStageGreaterThan
    .macro if_stat_stage_greater_than a0, a1, a2, a3
    ai_cmd 51
    .4byte \a0
    .4byte \a1
    .4byte \a2
    .4byte \a3 - (. + 4)
    .endm

    @ AIStatStageEqual
    .macro if_stat_stage_equal a0, a1, a2, a3
    ai_cmd 52
    .4byte \a0
    .4byte \a1
    .4byte \a2
    .4byte \a3 - (. + 4)
    .endm

    @ AIStatStageNotEqual
    .macro if_stat_stage_not_equal a0, a1, a2, a3
    ai_cmd 53
    .4byte \a0
    .4byte \a1
    .4byte \a2
    .4byte \a3 - (. + 4)
    .endm

    @ AIIfCanFaint: the first argument is unused
    .macro if_can_faint a0, a1
    ai_cmd 54
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfCannotFaint
    .macro if_cannot_faint a0, a1
    ai_cmd 55
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfHasMove: for the defender, only the moves it was seen to use
    .macro if_knows_move a0, a1, a2
    ai_cmd 56
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIIfDoesNotHaveMove
    .macro if_not_knows_move a0, a1, a2
    ai_cmd 57
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIIfHasMoveWithEffect
    .macro if_knows_move_effect a0, a1, a2
    ai_cmd 58
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIIfDoesNotHaveMoveWithEffect
    .macro if_not_knows_move_effect a0, a1, a2
    ai_cmd 59
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AINop60
    .macro nop_60
    ai_cmd 60
    .endm

    @ AIFlee
    .macro flee
    ai_cmd 61
    .endm

    @ AINop62
    .macro nop_62
    ai_cmd 62
    .endm

    @ AINop63
    .macro nop_63
    ai_cmd 63
    .endm

    @ AIGetHeldItem
    .macro load_held_item a0
    ai_cmd 64
    .4byte \a0
    .endm

    @ AIGetItemEffect: item parameter 1
    .macro load_held_item_effect a0
    ai_cmd 65
    .4byte \a0
    .endm

    @ AIGetGender
    .macro load_gender a0
    ai_cmd 66
    .4byte \a0
    .endm

    @ AIIsFakeOutActive: TRUE if condition flag 0 is clear
    .macro load_fake_out_active a0
    ai_cmd 67
    .4byte \a0
    .endm

    @ AIGetStockpileCount
    .macro load_stockpile_count a0
    ai_cmd 68
    .4byte \a0
    .endm

    @ AIGetBattleStyle
    .macro load_battle_style
    ai_cmd 69
    .endm

    @ AIGetBattleType
    .macro load_battle_type
    ai_cmd 70
    .endm

    @ AIGetConsumedItem
    .macro load_consumed_item a0
    ai_cmd 71
    .4byte \a0
    .endm

    @ AINop72
    .macro nop_72
    ai_cmd 72
    .endm

    @ AIGetMovePower: replaces the result, a move, with its power
    .macro load_result_power
    ai_cmd 73
    .endm

    @ AIGetMoveID: replaces the result, a move, with its effect
    .macro load_result_effect
    ai_cmd 74
    .endm

    @ AIGetProtectCount
    .macro load_protect_count a0
    ai_cmd 75
    .4byte \a0
    .endm

    @ AIJump
    .macro jump a0
    ai_cmd 76
    .4byte \a0 - (. + 4)
    .endm

    @ AIEnd: ends the script for this move
    .macro end
    ai_cmd 77
    .endm

    @ AICompareLevel: 0 jumps if the attacker's level is higher, 1 if lower, 2 if equal
    .macro if_level_compare a0, a1
    ai_cmd 78
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfTaunted: the defender
    .macro if_taunted a0
    ai_cmd 79
    .4byte \a0 - (. + 4)
    .endm

    @ AIIfNotTaunted
    .macro if_not_taunted a0
    ai_cmd 80
    .4byte \a0 - (. + 4)
    .endm

    @ AIIfTargetIsAlly
    .macro if_target_is_ally a0
    ai_cmd 81
    .4byte \a0 - (. + 4)
    .endm

    @ AIDoesMonHaveType
    .macro load_has_type a0, a1
    ai_cmd 82
    .4byte \a0
    .4byte \a1
    .endm

    @ AIGuessAbility
    .macro load_known_ability_is a0, a1
    ai_cmd 83
    .4byte \a0
    .4byte \a1
    .endm

    @ AIIfFlashFireIsActive
    .macro if_flash_fire a0, a1
    ai_cmd 84
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfHasItem
    .macro if_held_item a0, a1, a2
    ai_cmd 85
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIIfFieldEffect
    .macro if_field_effect a0, a1
    ai_cmd 86
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIGetSideEffect
    .macro load_side_effect a0, a1
    ai_cmd 87
    .4byte \a0
    .4byte \a1
    .endm

    @ AIIfPartyMemberDamaged
    .macro if_party_member_damaged a0, a1
    ai_cmd 88
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfPartyMemberUsedPP
    .macro if_party_member_used_pp a0, a1
    ai_cmd 89
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIGetFlingPower
    .macro load_fling_power a0
    ai_cmd 90
    .4byte \a0
    .endm

    @ AIGetMovePP
    .macro load_move_pp
    ai_cmd 91
    .endm

    @ AIIfCanUseLastResort
    .macro if_can_use_last_resort a0, a1
    ai_cmd 92
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIGetMoveCategory
    .macro load_move_category
    ai_cmd 93
    .endm

    @ AIGetLastMoveCategory: the defender's last move
    .macro load_last_move_category
    ai_cmd 94
    .endm

    @ AIGetOrderInTurn
    .macro load_speed_order a0
    ai_cmd 95
    .4byte \a0
    .endm

    @ func_ov170_0218119c
    .macro load_unk_96 a0
    ai_cmd 96
    .4byte \a0
    .endm

    @ AIIfPartyMemberDealsMoreDamage
    .macro if_party_member_deals_more_damage a0, a1
    ai_cmd 97
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIfHasSuperEffectiveMove
    .macro if_has_super_effective_move a0
    ai_cmd 98
    .4byte \a0 - (. + 4)
    .endm

    @ AIIfLastMoveDealsMoreDamage
    .macro if_last_move_deals_more_damage a0, a1, a2
    ai_cmd 99
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ AIGetPositiveStatStageTotal
    .macro load_positive_stat_stage_total a0
    ai_cmd 100
    .4byte \a0
    .endm

    @ AIGetStatStageDifference
    .macro load_stat_stage_difference a0, a1
    ai_cmd 101
    .4byte \a0
    .4byte \a1
    .endm

    @ AINop102
    .macro nop_102
    ai_cmd 102
    .endm

    @ AINop103
    .macro nop_103
    ai_cmd 103
    .endm

    @ AINop104
    .macro nop_104
    ai_cmd 104
    .endm

    @ AIGetHighestDamagingMoveWithPartners
    .macro load_damage_rank_with_partners a0
    ai_cmd 105
    .4byte \a0
    .endm

    @ AIIsFainted
    .macro if_fainted a0, a1
    ai_cmd 106
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIsNotFainted
    .macro if_not_fainted a0, a1
    ai_cmd 107
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIGetAbility: battle Pokemon value 17
    .macro load_ability a0
    ai_cmd 108
    .4byte \a0
    .endm

    @ AIIfSubstitute
    .macro if_substitute a0, a1
    ai_cmd 109
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIGetSpecies
    .macro load_species a0
    ai_cmd 110
    .4byte \a0
    .endm

    @ AIGreaterThanTurnRandom: compares the random number of the turn
    .macro if_turn_random_less_than a0, a1
    ai_cmd 111
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AILessThanTurnRandom
    .macro if_turn_random_greater_than a0, a1
    ai_cmd 112
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIEqualToTurnRandom
    .macro if_turn_random_equal a0, a1
    ai_cmd 113
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AINotEqualToTurnRandom
    .macro if_turn_random_not_equal a0, a1
    ai_cmd 114
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIJumpByMoveEffect: mode, the highest effect, table
    .macro jump_by_move_effect a0, a1, a2
    ai_cmd 115
    .4byte \a0
    .4byte \a1
    .4byte \a2 - (. + 4)
    .endm

    @ func_ov170_02181734
    .macro unk_cmd_116 a0, a1
    ai_cmd 116
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIsAtkLessThanSpAtk: the original compares the position with the special attack
    .macro if_attack_less_than_sp_attack a0, a1
    ai_cmd 117
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIsAtkGreaterThanSpAtk
    .macro if_attack_greater_than_sp_attack a0, a1
    ai_cmd 118
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm

    @ AIIsAtkEqualToSpAtk
    .macro if_attack_equal_sp_attack a0, a1
    ai_cmd 119
    .4byte \a0
    .4byte \a1 - (. + 4)
    .endm
