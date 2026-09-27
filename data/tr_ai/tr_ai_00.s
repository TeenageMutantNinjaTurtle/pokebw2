#include "asm/tr_ai.inc"

TrAI00_0000:
    if_target_is_ally TrAI00_0756
    if_move MOVE_FISSURE, TrAI00_002A
    if_move MOVE_HORN_DRILL, TrAI00_002A
    load_damage_rank 0
    if_equal 0, TrAI00_0148
TrAI00_002A:
    if_effectiveness TYPE_EFFECTIVENESS_IMMUNE, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0148
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_VOLT_ABSORB, TrAI00_00AA
    if_equal ABILITY_MOTOR_DRIVE, TrAI00_00AA
    if_equal ABILITY_LIGHTNINGROD, TrAI00_00AA
    if_equal ABILITY_WATER_ABSORB, TrAI00_00C0
    if_equal ABILITY_FLASH_FIRE, TrAI00_00D6
    if_equal ABILITY_WONDER_GUARD, TrAI00_00EC
    if_equal ABILITY_LEVITATE, TrAI00_0106
    if_equal ABILITY_LEVITATE, TrAI00_011C
    if_equal ABILITY_SAP_SIPPER, TrAI00_0132
    jump TrAI00_0148
TrAI00_00AA:
    load_type TRAI_TYPE_MOVE
    if_equal_2 TYPE_ELECTRIC, TrAI00_2366
    jump TrAI00_0148
TrAI00_00C0:
    load_type TRAI_TYPE_MOVE
    if_equal_2 TYPE_WATER, TrAI00_2366
    jump TrAI00_0148
TrAI00_00D6:
    load_type TRAI_TYPE_MOVE
    if_equal_2 TYPE_FIRE, TrAI00_2366
    jump TrAI00_0148
TrAI00_00EC:
    if_effectiveness TYPE_EFFECTIVENESS_DOUBLE, TrAI00_0148
    if_effectiveness TYPE_EFFECTIVENESS_QUADRUPLE, TrAI00_0148
    jump TrAI00_2366
TrAI00_0106:
    load_type TRAI_TYPE_MOVE
    if_equal_2 TYPE_GROUND, TrAI00_2366
    jump TrAI00_0148
TrAI00_011C:
    load_type TRAI_TYPE_MOVE
    if_equal_2 TYPE_WATER, TrAI00_2366
    jump TrAI00_0148
TrAI00_0132:
    load_type TRAI_TYPE_MOVE
    if_equal_2 TYPE_GRASS, TrAI00_2366
    jump TrAI00_0148
TrAI00_0148:
    load_known_ability TRAI_SIDE_DEFENDER
    if_not_equal ABILITY_SOUNDPROOF, TrAI00_01FE
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_01FE
    if_move MOVE_GROWL, TrAI00_235E
    if_move MOVE_ROAR, TrAI00_235E
    if_move MOVE_SING, TrAI00_235E
    if_move MOVE_SUPERSONIC, TrAI00_235E
    if_move MOVE_SCREECH, TrAI00_235E
    if_move MOVE_SNORE, TrAI00_235E
    if_move MOVE_UPROAR, TrAI00_235E
    if_move MOVE_METAL_SOUND, TrAI00_235E
    if_move MOVE_GRASS_WHISTLE, TrAI00_235E
    if_move MOVE_BUG_BUZZ, TrAI00_235E
    if_move MOVE_CHATTER, TrAI00_235E
    if_move MOVE_ROUND, TrAI00_235E
    if_move MOVE_ECHOED_VOICE, TrAI00_235E
    if_move MOVE_RELIC_SONG, TrAI00_235E
    if_move MOVE_SNARL, TrAI00_235E
TrAI00_01FE:
    jump_by_move_effect 0, 337, TrAI00_020E
    end
TrAI00_020E:
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0758 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0796 - TrAI00_020E
    .4byte TrAI00_0816 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_083E - TrAI00_020E
    .4byte TrAI00_0852 - TrAI00_020E
    .4byte TrAI00_0866 - TrAI00_020E
    .4byte TrAI00_0884 - TrAI00_020E
    .4byte TrAI00_0898 - TrAI00_020E
    .4byte TrAI00_08AC - TrAI00_020E
    .4byte TrAI00_08E0 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0914 - TrAI00_020E
    .4byte TrAI00_095C - TrAI00_020E
    .4byte TrAI00_0994 - TrAI00_020E
    .4byte TrAI00_09CA - TrAI00_020E
    .4byte TrAI00_09E2 - TrAI00_020E
    .4byte TrAI00_09FA - TrAI00_020E
    .4byte TrAI00_0A52 - TrAI00_020E
    .4byte TrAI00_0ACA - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0BCE - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0C0A - TrAI00_020E
    .4byte TrAI00_0C20 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0CE4 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0CF4 - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0D90 - TrAI00_020E
    .4byte TrAI00_0DA0 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0DB0 - TrAI00_020E
    .4byte TrAI00_083E - TrAI00_020E
    .4byte TrAI00_0852 - TrAI00_020E
    .4byte TrAI00_0866 - TrAI00_020E
    .4byte TrAI00_0884 - TrAI00_020E
    .4byte TrAI00_0898 - TrAI00_020E
    .4byte TrAI00_08AC - TrAI00_020E
    .4byte TrAI00_08E0 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0914 - TrAI00_020E
    .4byte TrAI00_095C - TrAI00_020E
    .4byte TrAI00_0994 - TrAI00_020E
    .4byte TrAI00_09CA - TrAI00_020E
    .4byte TrAI00_09E2 - TrAI00_020E
    .4byte TrAI00_09FA - TrAI00_020E
    .4byte TrAI00_0A52 - TrAI00_020E
    .4byte TrAI00_0DFE - TrAI00_020E
    .4byte TrAI00_0C20 - TrAI00_020E
    .4byte TrAI00_0E0E - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0E90 - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0EAA - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0EF4 - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0F24 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0F54 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0F64 - TrAI00_020E
    .4byte TrAI00_0F54 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0F94 - TrAI00_020E
    .4byte TrAI00_07E8 - TrAI00_020E
    .4byte TrAI00_08E0 - TrAI00_020E
    .4byte TrAI00_0FC4 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_102A - TrAI00_020E
    .4byte TrAI00_1070 - TrAI00_020E
    .4byte TrAI00_10A0 - TrAI00_020E
    .4byte TrAI00_10B0 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0DB0 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_10BE - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_114A - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0D2A - TrAI00_020E
    .4byte TrAI00_11CA - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0C0A - TrAI00_020E
    .4byte TrAI00_0C0A - TrAI00_020E
    .4byte TrAI00_0C0A - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_11DC - TrAI00_020E
    .4byte TrAI00_121E - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0830 - TrAI00_020E
    .4byte TrAI00_0ACA - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_122C - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_235E - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0852 - TrAI00_020E
    .4byte TrAI00_0C0A - TrAI00_020E
    .4byte TrAI00_1238 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_124A - TrAI00_020E
    .4byte TrAI00_125C - TrAI00_020E
    .4byte TrAI00_125C - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_1282 - TrAI00_020E
    .4byte TrAI00_1290 - TrAI00_020E
    .4byte TrAI00_0DB0 - TrAI00_020E
    .4byte TrAI00_12C0 - TrAI00_020E
    .4byte TrAI00_115A - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_1334 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_1342 - TrAI00_020E
    .4byte TrAI00_1352 - TrAI00_020E
    .4byte TrAI00_1360 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_1382 - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_1392 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0758 - TrAI00_020E
    .4byte TrAI00_1360 - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_13A4 - TrAI00_020E
    .4byte TrAI00_13B0 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_13EC - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_13F8 - TrAI00_020E
    .4byte TrAI00_1462 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_1488 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_14AE - TrAI00_020E
    .4byte TrAI00_14BA - TrAI00_020E
    .4byte TrAI00_14E0 - TrAI00_020E
    .4byte TrAI00_1510 - TrAI00_020E
    .4byte TrAI00_0C0A - TrAI00_020E
    .4byte TrAI00_1512 - TrAI00_020E
    .4byte TrAI00_151E - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_154E - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_1580 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_16A0 - TrAI00_020E
    .4byte TrAI00_16BA - TrAI00_020E
    .4byte TrAI00_173A - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_1790 - TrAI00_020E
    .4byte TrAI00_17DC - TrAI00_020E
    .4byte TrAI00_1A36 - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_1B72 - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_1BA2 - TrAI00_020E
    .4byte TrAI00_1BB2 - TrAI00_020E
    .4byte TrAI00_1C38 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_1C48 - TrAI00_020E
    .4byte TrAI00_1C6A - TrAI00_020E
    .4byte TrAI00_1C9A - TrAI00_020E
    .4byte TrAI00_0D4A - TrAI00_020E
    .4byte TrAI00_1CCA - TrAI00_020E
    .4byte TrAI00_1CDC - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_1D66 - TrAI00_020E
    .4byte TrAI00_0ACA - TrAI00_020E
    .4byte TrAI00_1DAC - TrAI00_020E
    .4byte TrAI00_1DBC - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_1DFC - TrAI00_020E
    .4byte TrAI00_1E98 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_1EAE - TrAI00_020E
    .4byte TrAI00_1F5C - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_1F9C - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_1FD8 - TrAI00_020E
    .4byte TrAI00_2032 - TrAI00_020E
    .4byte TrAI00_2040 - TrAI00_020E
    .4byte TrAI00_2042 - TrAI00_020E
    .4byte TrAI00_2044 - TrAI00_020E
    .4byte TrAI00_2050 - TrAI00_020E
    .4byte TrAI00_2052 - TrAI00_020E
    .4byte TrAI00_2054 - TrAI00_020E
    .4byte TrAI00_2068 - TrAI00_020E
    .4byte TrAI00_2098 - TrAI00_020E
    .4byte TrAI00_20A4 - TrAI00_020E
    .4byte TrAI00_20A6 - TrAI00_020E
    .4byte TrAI00_20A8 - TrAI00_020E
    .4byte TrAI00_20AA - TrAI00_020E
    .4byte TrAI00_20E2 - TrAI00_020E
    .4byte TrAI00_20E4 - TrAI00_020E
    .4byte TrAI00_20E6 - TrAI00_020E
    .4byte TrAI00_20E8 - TrAI00_020E
    .4byte TrAI00_210A - TrAI00_020E
    .4byte TrAI00_210C - TrAI00_020E
    .4byte TrAI00_210E - TrAI00_020E
    .4byte TrAI00_2110 - TrAI00_020E
    .4byte TrAI00_2160 - TrAI00_020E
    .4byte TrAI00_2182 - TrAI00_020E
    .4byte TrAI00_2190 - TrAI00_020E
    .4byte TrAI00_219E - TrAI00_020E
    .4byte TrAI00_21A0 - TrAI00_020E
    .4byte TrAI00_21A2 - TrAI00_020E
    .4byte TrAI00_21A4 - TrAI00_020E
    .4byte TrAI00_21A6 - TrAI00_020E
    .4byte TrAI00_21A8 - TrAI00_020E
    .4byte TrAI00_21B6 - TrAI00_020E
    .4byte TrAI00_21EE - TrAI00_020E
    .4byte TrAI00_21FC - TrAI00_020E
    .4byte TrAI00_21FE - TrAI00_020E
    .4byte TrAI00_2200 - TrAI00_020E
    .4byte TrAI00_2226 - TrAI00_020E
    .4byte TrAI00_2228 - TrAI00_020E
    .4byte TrAI00_222A - TrAI00_020E
    .4byte TrAI00_2238 - TrAI00_020E
    .4byte TrAI00_225E - TrAI00_020E
    .4byte TrAI00_2260 - TrAI00_020E
    .4byte TrAI00_2262 - TrAI00_020E
    .4byte TrAI00_2264 - TrAI00_020E
    .4byte TrAI00_228C - TrAI00_020E
    .4byte TrAI00_228E - TrAI00_020E
    .4byte TrAI00_22C6 - TrAI00_020E
    .4byte TrAI00_22E4 - TrAI00_020E
    .4byte TrAI00_22E6 - TrAI00_020E
    .4byte TrAI00_22E8 - TrAI00_020E
    .4byte TrAI00_22EA - TrAI00_020E
    .4byte TrAI00_2310 - TrAI00_020E
    .4byte TrAI00_2324 - TrAI00_020E
    .4byte TrAI00_2326 - TrAI00_020E
    .4byte TrAI00_2328 - TrAI00_020E
    .4byte TrAI00_232A - TrAI00_020E
    .4byte TrAI00_232C - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
    .4byte TrAI00_0756 - TrAI00_020E
TrAI00_0756:
    end
TrAI00_0758:
    if_status TRAI_SIDE_DEFENDER, TrAI00_235E
    if_side_effect TRAI_SIDE_DEFENDER, 2, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_INSOMNIA, TrAI00_235E
    if_equal ABILITY_VITAL_SPIRIT, TrAI00_235E
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_235E
    end
TrAI00_0796:
    if_effectiveness TYPE_EFFECTIVENESS_IMMUNE, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_07C0
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_DAMP, TrAI00_235E
TrAI00_07C0:
    load_able_party_count TRAI_SIDE_ATTACKER
    if_not_equal 0, TrAI00_07E6
    load_able_party_count TRAI_SIDE_DEFENDER
    if_not_equal 0, TrAI00_235E
    jump TrAI00_232E
TrAI00_07E6:
    end
TrAI00_07E8:
    if_condition TRAI_SIDE_DEFENDER, 9, TrAI00_235E
    if_not_condition TRAI_SIDE_DEFENDER, 2, TrAI00_2356
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_GUARD, TrAI00_235E
    end
TrAI00_0816:
    if_not_condition TRAI_SIDE_DEFENDER, 2, TrAI00_2356
    if_effectiveness TYPE_EFFECTIVENESS_IMMUNE, TrAI00_235E
    end
TrAI00_0830:
    if_hp_less_than TRAI_SIDE_ATTACKER, 51, TrAI00_235E
TrAI00_083E:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 1, 12, TrAI00_235E
    end
TrAI00_0852:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 2, 12, TrAI00_235E
    end
TrAI00_0866:
    if_field_effect 1, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 5, 12, TrAI00_235E
    end
TrAI00_0884:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 3, 12, TrAI00_235E
    end
TrAI00_0898:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 4, 12, TrAI00_235E
    end
TrAI00_08AC:
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_NO_GUARD, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_NO_GUARD, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 6, 12, TrAI00_235E
    end
TrAI00_08E0:
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_NO_GUARD, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_NO_GUARD, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 7, 12, TrAI00_235E
    end
TrAI00_0914:
    if_stat_stage_equal TRAI_SIDE_DEFENDER, 1, 0, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_DEFIANT, TrAI00_2366
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0A84
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_HYPER_CUTTER, TrAI00_235E
    jump TrAI00_0A84
TrAI00_095C:
    if_stat_stage_equal TRAI_SIDE_DEFENDER, 2, 0, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0A84
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_BIG_PECKS, TrAI00_235E
    jump TrAI00_0A84
TrAI00_0994:
    if_field_effect 1, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_DEFENDER, 5, 0, TrAI00_235E
    load_known_ability_is TRAI_SIDE_DEFENDER, ABILITY_SPEED_BOOST
    if_equal 1, TrAI00_235E
    jump TrAI00_0A84
TrAI00_09CA:
    if_stat_stage_equal TRAI_SIDE_DEFENDER, 3, 0, TrAI00_235E
    jump TrAI00_0A84
TrAI00_09E2:
    if_stat_stage_equal TRAI_SIDE_DEFENDER, 4, 0, TrAI00_235E
    jump TrAI00_0A84
TrAI00_09FA:
    if_stat_stage_equal TRAI_SIDE_DEFENDER, 6, 0, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_NO_GUARD, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_NO_GUARD, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0A84
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_KEEN_EYE, TrAI00_235E
    jump TrAI00_0A84
TrAI00_0A52:
    if_stat_stage_equal TRAI_SIDE_DEFENDER, 7, 0, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_NO_GUARD, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_NO_GUARD, TrAI00_235E
TrAI00_0A84:
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_CONTRARY, TrAI00_2366
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0AC8
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_CLEAR_BODY, TrAI00_235E
    if_equal ABILITY_WHITE_SMOKE, TrAI00_235E
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_0AC8:
    end
TrAI00_0ACA:
    if_stat_stage_less_than TRAI_SIDE_ATTACKER, 1, 6, TrAI00_0BCC
    if_stat_stage_less_than TRAI_SIDE_ATTACKER, 2, 6, TrAI00_0BCC
    if_stat_stage_less_than TRAI_SIDE_ATTACKER, 5, 6, TrAI00_0BCC
    if_stat_stage_less_than TRAI_SIDE_ATTACKER, 3, 6, TrAI00_0BCC
    if_stat_stage_less_than TRAI_SIDE_ATTACKER, 4, 6, TrAI00_0BCC
    if_stat_stage_less_than TRAI_SIDE_ATTACKER, 6, 6, TrAI00_0BCC
    if_stat_stage_less_than TRAI_SIDE_ATTACKER, 7, 6, TrAI00_0BCC
    if_stat_stage_greater_than TRAI_SIDE_DEFENDER, 1, 6, TrAI00_0BCC
    if_stat_stage_greater_than TRAI_SIDE_DEFENDER, 2, 6, TrAI00_0BCC
    if_stat_stage_greater_than TRAI_SIDE_DEFENDER, 5, 6, TrAI00_0BCC
    if_stat_stage_greater_than TRAI_SIDE_DEFENDER, 3, 6, TrAI00_0BCC
    if_stat_stage_greater_than TRAI_SIDE_DEFENDER, 4, 6, TrAI00_0BCC
    if_stat_stage_greater_than TRAI_SIDE_DEFENDER, 6, 6, TrAI00_0BCC
    if_stat_stage_greater_than TRAI_SIDE_DEFENDER, 7, 6, TrAI00_0BCC
    jump TrAI00_235E
TrAI00_0BCC:
    end
TrAI00_0BCE:
    load_able_party_count TRAI_SIDE_DEFENDER
    if_equal 0, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0C08
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_SUCTION_CUPS, TrAI00_235E
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_0C08:
    end
TrAI00_0C0A:
    if_hp_not_equal TRAI_SIDE_ATTACKER, 100, TrAI00_0C1E
    add_to_score -8
TrAI00_0C1E:
    end
TrAI00_0C20:
    load_type TRAI_TYPE_DEFENDER_1
    if_equal TYPE_STEEL, TrAI00_235E
    if_equal TYPE_POISON, TrAI00_235E
    load_type TRAI_TYPE_DEFENDER_2
    if_equal TYPE_STEEL, TrAI00_235E
    if_equal TYPE_POISON, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_IMMUNITY, TrAI00_235E
    if_equal ABILITY_MAGIC_GUARD, TrAI00_235E
    if_equal ABILITY_POISON_HEAL, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0CAE
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
    if_not_equal ABILITY_LEAF_GUARD, TrAI00_0CAE
    load_weather
    if_equal 1, TrAI00_235E
TrAI00_0CAE:
    load_known_ability TRAI_SIDE_DEFENDER
    if_not_equal ABILITY_HYDRATION, TrAI00_0CCA
    load_weather
    if_equal 2, TrAI00_235E
TrAI00_0CCA:
    if_status TRAI_SIDE_DEFENDER, TrAI00_235E
    if_side_effect TRAI_SIDE_DEFENDER, 2, TrAI00_235E
    end
TrAI00_0CE4:
    if_side_effect TRAI_SIDE_ATTACKER, 1, TrAI00_2356
    end
TrAI00_0CF4:
    if_effectiveness TYPE_EFFECTIVENESS_IMMUNE, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0D1E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_STURDY, TrAI00_235E
TrAI00_0D1E:
    if_level_compare 1, TrAI00_235E
    end
TrAI00_0D2A:
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0D4A
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_LEVITATE, TrAI00_235E
TrAI00_0D4A:
    if_effectiveness TYPE_EFFECTIVENESS_IMMUNE, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_not_equal ABILITY_WONDER_GUARD, TrAI00_0D8E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0D8E
    if_effectiveness TYPE_EFFECTIVENESS_DOUBLE, TrAI00_0D8E
    if_effectiveness TYPE_EFFECTIVENESS_QUADRUPLE, TrAI00_0D8E
    jump TrAI00_235E
TrAI00_0D8E:
    end
TrAI00_0D90:
    if_side_effect TRAI_SIDE_ATTACKER, 3, TrAI00_2356
    end
TrAI00_0DA0:
    if_condition_flag TRAI_SIDE_ATTACKER, 9, TrAI00_235E
    end
TrAI00_0DB0:
    if_condition TRAI_SIDE_DEFENDER, 6, TrAI00_2346
    if_side_effect TRAI_SIDE_DEFENDER, 2, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_OWN_TEMPO, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0DFC
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_0DFC:
    end
TrAI00_0DFE:
    if_side_effect TRAI_SIDE_ATTACKER, 0, TrAI00_2356
    end
TrAI00_0E0E:
    if_effectiveness TYPE_EFFECTIVENESS_IMMUNE, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_LIMBER, TrAI00_235E
    if_equal ABILITY_MAGIC_GUARD, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0E76
    if_move MOVE_THUNDER_WAVE, TrAI00_0E52
    jump TrAI00_0E76
TrAI00_0E52:
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MOTOR_DRIVE, TrAI00_235E
    if_equal ABILITY_VOLT_ABSORB, TrAI00_235E
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_0E76:
    if_status TRAI_SIDE_DEFENDER, TrAI00_235E
    if_side_effect TRAI_SIDE_DEFENDER, 2, TrAI00_235E
    end
TrAI00_0E90:
    if_substitute TRAI_SIDE_ATTACKER, TrAI00_2356
    if_hp_less_than TRAI_SIDE_ATTACKER, 26, TrAI00_235E
    end
TrAI00_0EAA:
    if_condition TRAI_SIDE_DEFENDER, 18, TrAI00_235E
    load_type TRAI_TYPE_DEFENDER_1
    if_equal TYPE_GRASS, TrAI00_235E
    load_type TRAI_TYPE_DEFENDER_2
    if_equal TYPE_GRASS, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_GUARD, TrAI00_235E
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
    end
TrAI00_0EF4:
    if_condition TRAI_SIDE_DEFENDER, 13, TrAI00_2356
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0F22
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_0F22:
    end
TrAI00_0F24:
    if_condition TRAI_SIDE_DEFENDER, 23, TrAI00_2356
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0F52
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_0F52:
    end
TrAI00_0F54:
    if_not_condition TRAI_SIDE_ATTACKER, 2, TrAI00_2356
    end
TrAI00_0F64:
    if_condition TRAI_SIDE_DEFENDER, 29, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_NO_GUARD, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_NO_GUARD, TrAI00_235E
    end
TrAI00_0F94:
    if_condition TRAI_SIDE_DEFENDER, 22, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_0FC2
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_0FC2:
    end
TrAI00_0FC4:
    load_type TRAI_TYPE_ATTACKER_1
    if_equal TYPE_GHOST, TrAI00_100A
    load_type TRAI_TYPE_ATTACKER_2
    if_equal TYPE_GHOST, TrAI00_100A
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 2, 12, TrAI00_2356
    end
TrAI00_100A:
    if_condition TRAI_SIDE_DEFENDER, 10, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_GUARD, TrAI00_235E
    end
TrAI00_102A:
    load_side_effect TRAI_SIDE_DEFENDER, 6
    if_equal 3, TrAI00_235E
    load_able_party_count TRAI_SIDE_DEFENDER
    if_equal 0, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_106E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_106E:
    end
TrAI00_1070:
    if_condition TRAI_SIDE_DEFENDER, 17, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_109E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_109E:
    end
TrAI00_10A0:
    if_condition TRAI_SIDE_DEFENDER, 20, TrAI00_235E
    end
TrAI00_10B0:
    load_weather
    if_equal 4, TrAI00_2356
    end
TrAI00_10BE:
    if_condition TRAI_SIDE_DEFENDER, 7, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_OBLIVIOUS, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_10FC
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_10FC:
    load_gender TRAI_SIDE_ATTACKER
    if_equal 0, TrAI00_111C
    if_equal 1, TrAI00_1132
    jump TrAI00_235E
TrAI00_111C:
    load_gender TRAI_SIDE_DEFENDER
    if_equal 1, TrAI00_1148
    jump TrAI00_235E
TrAI00_1132:
    load_gender TRAI_SIDE_DEFENDER
    if_equal 0, TrAI00_1148
    jump TrAI00_235E
TrAI00_1148:
    end
TrAI00_114A:
    if_side_effect TRAI_SIDE_ATTACKER, 2, TrAI00_2356
    end
TrAI00_115A:
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_CONTRARY, TrAI00_2366
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_1194
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_CLEAR_BODY, TrAI00_235E
    if_equal ABILITY_WHITE_SMOKE, TrAI00_235E
TrAI00_1194:
    if_stat_stage_equal TRAI_SIDE_DEFENDER, 1, 0, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_DEFENDER, 3, 0, TrAI00_2356
    load_able_party_count TRAI_SIDE_ATTACKER
    if_equal 0, TrAI00_235E
    end
TrAI00_11CA:
    load_able_party_count TRAI_SIDE_ATTACKER
    if_equal 0, TrAI00_235E
    end
TrAI00_11DC:
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_SWIFT_SWIM, TrAI00_1210
    if_equal ABILITY_HYDRATION, TrAI00_1210
    load_known_ability TRAI_SIDE_DEFENDER
    if_not_equal ABILITY_HYDRATION, TrAI00_1210
    if_status TRAI_SIDE_DEFENDER, TrAI00_2356
TrAI00_1210:
    load_weather
    if_equal 2, TrAI00_2356
    end
TrAI00_121E:
    load_weather
    if_equal 1, TrAI00_2356
    end
TrAI00_122C:
    unk_cmd_116 TRAI_SIDE_DEFENDER, TrAI00_2366
    end
TrAI00_1238:
    load_fake_out_active TRAI_SIDE_ATTACKER
    if_equal 0, TrAI00_235E
    end
TrAI00_124A:
    load_stockpile_count TRAI_SIDE_ATTACKER
    if_equal 3, TrAI00_235E
    end
TrAI00_125C:
    if_effectiveness TYPE_EFFECTIVENESS_IMMUNE, TrAI00_235E
    load_stockpile_count TRAI_SIDE_ATTACKER
    if_equal 0, TrAI00_235E
    if_move_effect 162, TrAI00_0C0A
    end
TrAI00_1282:
    load_weather
    if_equal 3, TrAI00_2356
    end
TrAI00_1290:
    if_condition TRAI_SIDE_DEFENDER, 12, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_12BE
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_12BE:
    end
TrAI00_12C0:
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_WATER_VEIL, TrAI00_235E
    if_equal ABILITY_MAGIC_GUARD, TrAI00_235E
    if_status TRAI_SIDE_DEFENDER, TrAI00_235E
    load_type TRAI_TYPE_DEFENDER_1
    if_equal TYPE_FIRE, TrAI00_235E
    load_type TRAI_TYPE_DEFENDER_2
    if_equal TYPE_FIRE, TrAI00_235E
    if_side_effect TRAI_SIDE_DEFENDER, 2, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_1332
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_1332:
    end
TrAI00_1334:
    load_battle_style
    if_equal BTL_STYLE_SINGLE, TrAI00_235E
    end
TrAI00_1342:
    if_condition TRAI_SIDE_DEFENDER, 11, TrAI00_235E
    end
TrAI00_1352:
    load_battle_style
    if_equal BTL_STYLE_SINGLE, TrAI00_235E
    end
TrAI00_1360:
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_STICKY_HOLD, TrAI00_235E
    load_held_item TRAI_SIDE_DEFENDER
    if_equal ITEM_NONE, TrAI00_235E
    end
TrAI00_1382:
    if_condition TRAI_SIDE_ATTACKER, 21, TrAI00_235E
    end
TrAI00_1392:
    load_consumed_item TRAI_SIDE_ATTACKER
    if_equal ITEM_NONE, TrAI00_235E
    end
TrAI00_13A4:
    if_field_effect 3, TrAI00_235E
    end
TrAI00_13B0:
    if_condition TRAI_SIDE_ATTACKER, 5, TrAI00_13EA
    if_badly_poisoned TRAI_SIDE_ATTACKER, TrAI00_13EA
    if_condition TRAI_SIDE_ATTACKER, 1, TrAI00_13EA
    if_condition TRAI_SIDE_ATTACKER, 4, TrAI00_13EA
    jump TrAI00_235E
TrAI00_13EA:
    end
TrAI00_13EC:
    if_field_effect 5, TrAI00_235E
    end
TrAI00_13F8:
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_CONTRARY, TrAI00_2366
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_143C
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_CLEAR_BODY, TrAI00_235E
    if_equal ABILITY_WHITE_SMOKE, TrAI00_235E
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_143C:
    if_stat_stage_equal TRAI_SIDE_DEFENDER, 1, 0, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_DEFENDER, 2, 0, TrAI00_2356
    end
TrAI00_1462:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 2, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 4, 12, TrAI00_2356
    end
TrAI00_1488:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 2, 12, TrAI00_2356
    end
TrAI00_14AE:
    if_field_effect 4, TrAI00_235E
    end
TrAI00_14BA:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 3, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 4, 12, TrAI00_2356
    end
TrAI00_14E0:
    if_field_effect 1, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 5, 12, TrAI00_2356
    end
TrAI00_1510:
    end
TrAI00_1512:
    if_field_effect 2, TrAI00_235E
    end
TrAI00_151E:
    if_condition TRAI_SIDE_DEFENDER, 17, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_154C
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_154C:
    end
TrAI00_154E:
    add_to_score -20
    load_able_party_count TRAI_SIDE_ATTACKER
    if_equal 0, TrAI00_235E
    if_party_member_no_status TRAI_SIDE_ATTACKER, TrAI00_157E
    if_party_member_damaged TRAI_SIDE_ATTACKER, TrAI00_157E
    jump TrAI00_235E
TrAI00_157E:
    end
TrAI00_1580:
    load_held_item TRAI_SIDE_ATTACKER
    if_not_in_list TrAI00_159C, TrAI00_235E
    if_effectiveness TYPE_EFFECTIVENESS_IMMUNE, TrAI00_235E
    end
TrAI00_159C:
    .4byte ITEM_CHERI_BERRY
    .4byte ITEM_CHESTO_BERRY
    .4byte ITEM_PECHA_BERRY
    .4byte ITEM_RAWST_BERRY
    .4byte ITEM_ASPEAR_BERRY
    .4byte ITEM_LEPPA_BERRY
    .4byte ITEM_ORAN_BERRY
    .4byte ITEM_PERSIM_BERRY
    .4byte ITEM_LUM_BERRY
    .4byte ITEM_SITRUS_BERRY
    .4byte ITEM_FIGY_BERRY
    .4byte ITEM_WIKI_BERRY
    .4byte ITEM_MAGO_BERRY
    .4byte ITEM_AGUAV_BERRY
    .4byte ITEM_IAPAPA_BERRY
    .4byte ITEM_RAZZ_BERRY
    .4byte ITEM_BLUK_BERRY
    .4byte ITEM_NANAB_BERRY
    .4byte ITEM_WEPEAR_BERRY
    .4byte ITEM_PINAP_BERRY
    .4byte ITEM_POMEG_BERRY
    .4byte ITEM_KELPSY_BERRY
    .4byte ITEM_QUALOT_BERRY
    .4byte ITEM_HONDEW_BERRY
    .4byte ITEM_GREPA_BERRY
    .4byte ITEM_TAMATO_BERRY
    .4byte ITEM_CORNN_BERRY
    .4byte ITEM_MAGOST_BERRY
    .4byte ITEM_RABUTA_BERRY
    .4byte ITEM_NOMEL_BERRY
    .4byte ITEM_SPELON_BERRY
    .4byte ITEM_PAMTRE_BERRY
    .4byte ITEM_WATMEL_BERRY
    .4byte ITEM_DURIN_BERRY
    .4byte ITEM_BELUE_BERRY
    .4byte ITEM_OCCA_BERRY
    .4byte ITEM_PASSHO_BERRY
    .4byte ITEM_WACAN_BERRY
    .4byte ITEM_RINDO_BERRY
    .4byte ITEM_YACHE_BERRY
    .4byte ITEM_CHOPLE_BERRY
    .4byte ITEM_KEBIA_BERRY
    .4byte ITEM_SHUCA_BERRY
    .4byte ITEM_COBA_BERRY
    .4byte ITEM_PAYAPA_BERRY
    .4byte ITEM_TANGA_BERRY
    .4byte ITEM_CHARTI_BERRY
    .4byte ITEM_KASIB_BERRY
    .4byte ITEM_HABAN_BERRY
    .4byte ITEM_COLBUR_BERRY
    .4byte ITEM_BABIRI_BERRY
    .4byte ITEM_CHILAN_BERRY
    .4byte ITEM_LIECHI_BERRY
    .4byte ITEM_GANLON_BERRY
    .4byte ITEM_SALAC_BERRY
    .4byte ITEM_PETAYA_BERRY
    .4byte ITEM_APICOT_BERRY
    .4byte ITEM_LANSAT_BERRY
    .4byte ITEM_STARF_BERRY
    .4byte ITEM_ENIGMA_BERRY
    .4byte ITEM_MICLE_BERRY
    .4byte ITEM_CUSTAP_BERRY
    .4byte ITEM_JABOCA_BERRY
    .4byte ITEM_ROWAP_BERRY
    list_end
TrAI00_16A0:
    if_field_effect 1, TrAI00_2356
    if_side_effect TRAI_SIDE_ATTACKER, 4, TrAI00_235E
    end
TrAI00_16BA:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 2, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 5, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 3, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 4, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 7, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 6, 12, TrAI00_235E
    end
TrAI00_173A:
    if_effectiveness TYPE_EFFECTIVENESS_IMMUNE, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_STALL, TrAI00_235E
    load_held_item_effect TRAI_SIDE_DEFENDER
    if_equal 107, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_STALL, TrAI00_178E
    load_held_item_effect TRAI_SIDE_ATTACKER
    if_equal 107, TrAI00_178E
    if_speed_compare 0, TrAI00_235E
TrAI00_178E:
    end
TrAI00_1790:
    if_condition TRAI_SIDE_DEFENDER, 19, TrAI00_235E
    load_consumed_item TRAI_SIDE_DEFENDER
    if_equal ITEM_NONE, TrAI00_17DA
    load_battle_type
    if_equal 2, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_17DA
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_17DA:
    end
TrAI00_17DC:
    if_effectiveness TYPE_EFFECTIVENESS_IMMUNE, TrAI00_235E
    load_fling_power TRAI_SIDE_ATTACKER
    if_less_than 10, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MULTITYPE, TrAI00_235E
    load_held_item_effect TRAI_SIDE_ATTACKER
    if_in_list TrAI00_1A1A, TrAI00_182C
    if_in_list TrAI00_1A26, TrAI00_1934
    if_in_list TrAI00_1A2E, TrAI00_19F0
    end
TrAI00_182C:
    if_side_effect TRAI_SIDE_DEFENDER, 2, TrAI00_18AE
    if_status TRAI_SIDE_DEFENDER, TrAI00_18AE
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_POISON_HEAL, TrAI00_18AE
    load_type TRAI_TYPE_DEFENDER_1
    if_equal TYPE_POISON, TrAI00_18AE
    if_equal TYPE_STEEL, TrAI00_18AE
    load_type TRAI_TYPE_DEFENDER_2
    if_equal TYPE_POISON, TrAI00_18AE
    if_equal TYPE_STEEL, TrAI00_18AE
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_IMMUNITY, TrAI00_18AE
    if_equal ABILITY_POISON_HEAL, TrAI00_18AE
    if_equal ABILITY_MAGIC_GUARD, TrAI00_18AE
    end
TrAI00_18AE:
    if_side_effect TRAI_SIDE_ATTACKER, 2, TrAI00_2346
    if_status TRAI_SIDE_ATTACKER, TrAI00_2346
    load_type TRAI_TYPE_ATTACKER_1
    if_equal TYPE_POISON, TrAI00_2346
    if_equal TYPE_STEEL, TrAI00_2346
    load_type TRAI_TYPE_ATTACKER_2
    if_equal TYPE_POISON, TrAI00_2346
    if_equal TYPE_STEEL, TrAI00_2346
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_KLUTZ, TrAI00_2346
    if_equal ABILITY_IMMUNITY, TrAI00_2346
    if_equal ABILITY_POISON_HEAL, TrAI00_2346
    if_equal ABILITY_MAGIC_GUARD, TrAI00_2346
    if_equal ABILITY_GUTS, TrAI00_2346
    end
TrAI00_1934:
    if_side_effect TRAI_SIDE_DEFENDER, 2, TrAI00_1988
    if_status TRAI_SIDE_DEFENDER, TrAI00_1988
    load_type TRAI_TYPE_DEFENDER_1
    if_equal TYPE_FIRE, TrAI00_1988
    load_type TRAI_TYPE_DEFENDER_2
    if_equal TYPE_FIRE, TrAI00_1988
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_GUARD, TrAI00_1988
    if_equal ABILITY_WATER_VEIL, TrAI00_1988
    end
TrAI00_1988:
    if_side_effect TRAI_SIDE_ATTACKER, 2, TrAI00_2346
    if_status TRAI_SIDE_ATTACKER, TrAI00_2346
    load_type TRAI_TYPE_ATTACKER_1
    if_equal TYPE_FIRE, TrAI00_2346
    load_type TRAI_TYPE_ATTACKER_2
    if_equal TYPE_FIRE, TrAI00_2346
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_KLUTZ, TrAI00_2346
    if_equal ABILITY_MAGIC_GUARD, TrAI00_2346
    if_equal ABILITY_WATER_VEIL, TrAI00_2346
    if_equal ABILITY_GUTS, TrAI00_2346
    end
TrAI00_19F0:
    if_side_effect TRAI_SIDE_DEFENDER, 2, TrAI00_2346
    if_status TRAI_SIDE_DEFENDER, TrAI00_2346
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_LIMBER, TrAI00_2346
    end
TrAI00_1A1A:
    .4byte 100
    .4byte 80
    list_end
TrAI00_1A26:
    .4byte 101
    list_end
TrAI00_1A2E:
    .4byte 71
    list_end
TrAI00_1A36:
    if_no_status TRAI_SIDE_ATTACKER, TrAI00_235E
    if_status TRAI_SIDE_DEFENDER, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_1A6A
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_235E
TrAI00_1A6A:
    if_side_effect TRAI_SIDE_DEFENDER, 2, TrAI00_235E
    if_condition TRAI_SIDE_ATTACKER, 5, TrAI00_1AB2
    if_badly_poisoned TRAI_SIDE_ATTACKER, TrAI00_1AB2
    if_condition TRAI_SIDE_ATTACKER, 4, TrAI00_1B20
    if_condition TRAI_SIDE_ATTACKER, 1, TrAI00_1B60
    jump TrAI00_1B70
TrAI00_1AB2:
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_POISON_HEAL, TrAI00_235E
    load_type TRAI_TYPE_DEFENDER_1
    if_equal TYPE_POISON, TrAI00_235E
    if_equal TYPE_STEEL, TrAI00_235E
    load_type TRAI_TYPE_DEFENDER_2
    if_equal TYPE_POISON, TrAI00_235E
    if_equal TYPE_STEEL, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_IMMUNITY, TrAI00_235E
    if_equal ABILITY_POISON_HEAL, TrAI00_235E
    if_equal ABILITY_MAGIC_GUARD, TrAI00_235E
    jump TrAI00_1B70
TrAI00_1B20:
    load_type TRAI_TYPE_DEFENDER_1
    if_equal TYPE_FIRE, TrAI00_235E
    load_type TRAI_TYPE_DEFENDER_2
    if_equal TYPE_FIRE, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_GUARD, TrAI00_235E
    if_equal ABILITY_WATER_VEIL, TrAI00_235E
    jump TrAI00_1B70
TrAI00_1B60:
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_LIMBER, TrAI00_235E
TrAI00_1B70:
    end
TrAI00_1B72:
    if_condition TRAI_SIDE_DEFENDER, 15, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_1BA0
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_1BA0:
    end
TrAI00_1BA2:
    if_condition_flag TRAI_SIDE_ATTACKER, 10, TrAI00_235E
    end
TrAI00_1BB2:
    if_condition TRAI_SIDE_DEFENDER, 16, TrAI00_235E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MULTITYPE, TrAI00_235E
    if_equal ABILITY_TRUANT, TrAI00_235E
    if_equal ABILITY_DEFEATIST, TrAI00_235E
    if_equal ABILITY_SLOW_START, TrAI00_235E
    if_equal ABILITY_STENCH, TrAI00_235E
    if_equal ABILITY_RUN_AWAY, TrAI00_235E
    if_equal ABILITY_PICKUP, TrAI00_235E
    if_equal ABILITY_HONEY_GATHER, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_1C36
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_1C36:
    end
TrAI00_1C38:
    if_side_effect TRAI_SIDE_ATTACKER, 5, TrAI00_235E
    end
TrAI00_1C48:
    load_turn_count
    if_not_equal 0, TrAI00_1C68
    if_speed_compare 1, TrAI00_1C68
    if_speed_compare 0, TrAI00_235E
TrAI00_1C68:
    end
TrAI00_1C6A:
    load_stat_stage_difference TRAI_SIDE_DEFENDER, 1
    if_less_than 1, TrAI00_1C84
    jump TrAI00_1C98
TrAI00_1C84:
    load_stat_stage_difference TRAI_SIDE_DEFENDER, 3
    if_less_than 1, TrAI00_235E
TrAI00_1C98:
    end
TrAI00_1C9A:
    load_stat_stage_difference TRAI_SIDE_DEFENDER, 2
    if_less_than 1, TrAI00_1CB4
    jump TrAI00_1CC8
TrAI00_1CB4:
    load_stat_stage_difference TRAI_SIDE_DEFENDER, 4
    if_less_than 1, TrAI00_235E
TrAI00_1CC8:
    end
TrAI00_1CCA:
    if_can_use_last_resort TRAI_SIDE_ATTACKER, TrAI00_1CDA
    add_to_score -10
TrAI00_1CDA:
    end
TrAI00_1CDC:
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_TRUANT, TrAI00_235E
    if_equal ABILITY_DEFEATIST, TrAI00_235E
    if_equal ABILITY_INSOMNIA, TrAI00_235E
    if_equal ABILITY_VITAL_SPIRIT, TrAI00_235E
    if_equal ABILITY_MULTITYPE, TrAI00_235E
    if_not_condition TRAI_SIDE_DEFENDER, 2, TrAI00_1D64
    if_knows_move TRAI_SIDE_DEFENDER, MOVE_SLEEP_TALK, TrAI00_1D64
    if_knows_move TRAI_SIDE_DEFENDER, MOVE_SNORE, TrAI00_1D64
    add_to_score -10
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_1D64
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_1D64:
    end
TrAI00_1D66:
    load_side_effect TRAI_SIDE_DEFENDER, 7
    if_equal 2, TrAI00_235E
    load_able_party_count TRAI_SIDE_DEFENDER
    if_equal 0, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_1DAA
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_1DAA:
    end
TrAI00_1DAC:
    if_condition TRAI_SIDE_ATTACKER, 35, TrAI00_235E
    end
TrAI00_1DBC:
    if_condition TRAI_SIDE_ATTACKER, 30, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_LEVITATE, TrAI00_235E
    load_type TRAI_TYPE_ATTACKER_1
    if_equal TYPE_FLYING, TrAI00_235E
    load_type TRAI_TYPE_ATTACKER_2
    if_equal TYPE_FLYING, TrAI00_235E
    end
TrAI00_1DFC:
    if_stat_stage_not_equal TRAI_SIDE_DEFENDER, 7, 0, TrAI00_1E96
    if_side_effect TRAI_SIDE_DEFENDER, 1, TrAI00_1E96
    if_side_effect TRAI_SIDE_DEFENDER, 0, TrAI00_1E96
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_1E4A
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_1E4A:
    load_weather
    if_equal 0, TrAI00_1E96
    load_able_party_count TRAI_SIDE_DEFENDER
    if_equal 0, TrAI00_235E
    if_side_effect TRAI_SIDE_DEFENDER, 6, TrAI00_1E96
    if_side_effect TRAI_SIDE_DEFENDER, 8, TrAI00_1E96
    if_side_effect TRAI_SIDE_DEFENDER, 7, TrAI00_1E96
    jump TrAI00_235E
TrAI00_1E96:
    end
TrAI00_1E98:
    if_speed_compare 0, TrAI00_235E
    if_speed_compare 2, TrAI00_235E
    end
TrAI00_1EAE:
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_CONTRARY, TrAI00_2366
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_1EFC
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_OBLIVIOUS, TrAI00_235E
    if_equal ABILITY_CLEAR_BODY, TrAI00_235E
    if_equal ABILITY_WHITE_SMOKE, TrAI00_235E
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_1EFC:
    load_gender TRAI_SIDE_ATTACKER
    if_equal 0, TrAI00_1F1C
    if_equal 1, TrAI00_1F32
    jump TrAI00_235E
TrAI00_1F1C:
    load_gender TRAI_SIDE_DEFENDER
    if_equal 1, TrAI00_1F48
    jump TrAI00_235E
TrAI00_1F32:
    load_gender TRAI_SIDE_DEFENDER
    if_equal 0, TrAI00_1F48
    jump TrAI00_235E
TrAI00_1F48:
    if_stat_stage_less_than TRAI_SIDE_DEFENDER, 3, 1, TrAI00_235E
    end
TrAI00_1F5C:
    if_side_effect TRAI_SIDE_DEFENDER, 8, TrAI00_235E
    load_able_party_count TRAI_SIDE_DEFENDER
    if_equal 0, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_1F9A
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_1F9A:
    end
TrAI00_1F9C:
    add_to_score -20
    load_able_party_count TRAI_SIDE_ATTACKER
    if_equal 0, TrAI00_235E
    if_party_member_damaged TRAI_SIDE_ATTACKER, TrAI00_1FD6
    if_party_member_no_status TRAI_SIDE_ATTACKER, TrAI00_1FD6
    if_party_member_used_pp TRAI_SIDE_ATTACKER, TrAI00_1FD6
    jump TrAI00_235E
TrAI00_1FD6:
    end
TrAI00_1FD8:
    load_known_ability TRAI_SIDE_ATTACKER
    if_not_equal ABILITY_SIMPLE, TrAI00_200C
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER, 1, 8, TrAI00_235E
    if_stat_stage_greater_than TRAI_SIDE_ATTACKER, 6, 8, TrAI00_2356
TrAI00_200C:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 6, 12, TrAI00_2356
    end
TrAI00_2032:
    load_battle_style
    if_equal BTL_STYLE_SINGLE, TrAI00_235E
    end
TrAI00_2040:
    end
TrAI00_2042:
    end
TrAI00_2044:
    if_field_effect 6, TrAI00_235E
    end
TrAI00_2050:
    end
TrAI00_2052:
    end
TrAI00_2054:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 5, 12, TrAI00_235E
    end
TrAI00_2068:
    if_condition TRAI_SIDE_DEFENDER, 32, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_2096
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_2096:
    end
TrAI00_2098:
    if_field_effect 7, TrAI00_235E
    end
TrAI00_20A4:
    end
TrAI00_20A6:
    end
TrAI00_20A8:
    end
TrAI00_20AA:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 2, 12, TrAI00_2356
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 5, 12, TrAI00_234E
    end
TrAI00_20E2:
    end
TrAI00_20E4:
    end
TrAI00_20E6:
    end
TrAI00_20E8:
    load_type TRAI_TYPE_DEFENDER_1
    if_not_equal_2 TYPE_WATER, TrAI00_2108
    load_type TRAI_TYPE_DEFENDER_2
    if_equal_2 TYPE_WATER, TrAI00_235E
TrAI00_2108:
    end
TrAI00_210A:
    end
TrAI00_210C:
    end
TrAI00_210E:
    end
TrAI00_2110:
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MULTITYPE, TrAI00_235E
    if_equal ABILITY_TRUANT, TrAI00_235E
    if_equal ABILITY_DEFEATIST, TrAI00_235E
    if_equal ABILITY_SLOW_START, TrAI00_235E
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_215E
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_215E:
    end
TrAI00_2160:
    load_known_ability TRAI_SIDE_ATTACKER
    if_equal ABILITY_MOLD_BREAKER, TrAI00_2180
    load_known_ability TRAI_SIDE_DEFENDER
    if_equal ABILITY_MAGIC_BOUNCE, TrAI00_2366
TrAI00_2180:
    end
TrAI00_2182:
    load_battle_style
    if_equal BTL_STYLE_SINGLE, TrAI00_235E
    end
TrAI00_2190:
    load_battle_style
    if_equal BTL_STYLE_SINGLE, TrAI00_235E
    end
TrAI00_219E:
    end
TrAI00_21A0:
    end
TrAI00_21A2:
    end
TrAI00_21A4:
    end
TrAI00_21A6:
    end
TrAI00_21A8:
    load_battle_style
    if_equal BTL_STYLE_SINGLE, TrAI00_235E
    end
TrAI00_21B6:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 3, 12, TrAI00_2356
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 5, 12, TrAI00_234E
    end
TrAI00_21EE:
    load_battle_style
    if_equal BTL_STYLE_SINGLE, TrAI00_235E
    end
TrAI00_21FC:
    end
TrAI00_21FE:
    end
TrAI00_2200:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 5, 12, TrAI00_2356
    end
TrAI00_2226:
    end
TrAI00_2228:
    end
TrAI00_222A:
    load_battle_style
    if_equal BTL_STYLE_SINGLE, TrAI00_235E
    end
TrAI00_2238:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 3, 12, TrAI00_2356
    end
TrAI00_225E:
    end
TrAI00_2260:
    end
TrAI00_2262:
    end
TrAI00_2264:
    load_able_party_count TRAI_SIDE_ATTACKER
    if_not_equal 0, TrAI00_228A
    load_able_party_count TRAI_SIDE_DEFENDER
    if_not_equal 0, TrAI00_235E
    jump TrAI00_232E
TrAI00_228A:
    end
TrAI00_228C:
    end
TrAI00_228E:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 2, 12, TrAI00_2356
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 6, 12, TrAI00_234E
    end
TrAI00_22C6:
    load_held_item TRAI_SIDE_DEFENDER
    if_not_equal ITEM_NONE, TrAI00_235E
    load_battle_style
    if_equal BTL_STYLE_SINGLE, TrAI00_235E
    end
TrAI00_22E4:
    end
TrAI00_22E6:
    end
TrAI00_22E8:
    end
TrAI00_22EA:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 3, 12, TrAI00_2356
    end
TrAI00_2310:
    if_stat_stage_equal TRAI_SIDE_ATTACKER, 2, 12, TrAI00_235E
    end
TrAI00_2324:
    end
TrAI00_2326:
    end
TrAI00_2328:
    end
TrAI00_232A:
    end
TrAI00_232C:
    end
TrAI00_232E:
    add_to_score -1
    end
    add_to_score -2
    end
    add_to_score -3
    end
TrAI00_2346:
    add_to_score -5
    end
TrAI00_234E:
    add_to_score -6
    end
TrAI00_2356:
    add_to_score -8
    end
TrAI00_235E:
    add_to_score -10
    end
TrAI00_2366:
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
    .balign 4
