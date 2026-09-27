    .include "asm/tr_ai.inc"

TrAI00_0000:
    if_target_is_ally TrAI00_0756
    if_move 90, TrAI00_002A
    if_move 32, TrAI00_002A
    load_damage_rank 0
    if_equal 0, TrAI00_0148
TrAI00_002A:
    if_effectiveness 0, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0148
    load_known_ability AI_DEFENDER
    if_equal 10, TrAI00_00AA
    if_equal 78, TrAI00_00AA
    if_equal 31, TrAI00_00AA
    if_equal 11, TrAI00_00C0
    if_equal 18, TrAI00_00D6
    if_equal 25, TrAI00_00EC
    if_equal 26, TrAI00_0106
    if_equal 26, TrAI00_011C
    if_equal 157, TrAI00_0132
    jump TrAI00_0148
TrAI00_00AA:
    load_type 4
    if_equal_2 12, TrAI00_2366
    jump TrAI00_0148
TrAI00_00C0:
    load_type 4
    if_equal_2 10, TrAI00_2366
    jump TrAI00_0148
TrAI00_00D6:
    load_type 4
    if_equal_2 9, TrAI00_2366
    jump TrAI00_0148
TrAI00_00EC:
    if_effectiveness 4, TrAI00_0148
    if_effectiveness 5, TrAI00_0148
    jump TrAI00_2366
TrAI00_0106:
    load_type 4
    if_equal_2 4, TrAI00_2366
    jump TrAI00_0148
TrAI00_011C:
    load_type 4
    if_equal_2 10, TrAI00_2366
    jump TrAI00_0148
TrAI00_0132:
    load_type 4
    if_equal_2 11, TrAI00_2366
    jump TrAI00_0148
TrAI00_0148:
    load_known_ability AI_DEFENDER
    if_not_equal 43, TrAI00_01FE
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_01FE
    if_move 45, TrAI00_235E
    if_move 46, TrAI00_235E
    if_move 47, TrAI00_235E
    if_move 48, TrAI00_235E
    if_move 103, TrAI00_235E
    if_move 173, TrAI00_235E
    if_move 253, TrAI00_235E
    if_move 319, TrAI00_235E
    if_move 320, TrAI00_235E
    if_move 405, TrAI00_235E
    if_move 448, TrAI00_235E
    if_move 496, TrAI00_235E
    if_move 497, TrAI00_235E
    if_move 547, TrAI00_235E
    if_move 555, TrAI00_235E
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
    if_status AI_DEFENDER, TrAI00_235E
    if_side_effect AI_DEFENDER, 2, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 15, TrAI00_235E
    if_equal 72, TrAI00_235E
    if_equal 156, TrAI00_235E
    end
TrAI00_0796:
    if_effectiveness 0, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_07C0
    load_known_ability AI_DEFENDER
    if_equal 6, TrAI00_235E
TrAI00_07C0:
    load_able_party_count AI_ATTACKER
    if_not_equal 0, TrAI00_07E6
    load_able_party_count AI_DEFENDER
    if_not_equal 0, TrAI00_235E
    jump TrAI00_232E
TrAI00_07E6:
    end
TrAI00_07E8:
    if_condition AI_DEFENDER, 9, TrAI00_235E
    if_not_condition AI_DEFENDER, 2, TrAI00_2356
    load_known_ability AI_DEFENDER
    if_equal 98, TrAI00_235E
    end
TrAI00_0816:
    if_not_condition AI_DEFENDER, 2, TrAI00_2356
    if_effectiveness 0, TrAI00_235E
    end
TrAI00_0830:
    if_hp_less_than AI_ATTACKER, 51, TrAI00_235E
TrAI00_083E:
    if_stat_stage_equal AI_ATTACKER, 1, 12, TrAI00_235E
    end
TrAI00_0852:
    if_stat_stage_equal AI_ATTACKER, 2, 12, TrAI00_235E
    end
TrAI00_0866:
    if_field_effect 1, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 5, 12, TrAI00_235E
    end
TrAI00_0884:
    if_stat_stage_equal AI_ATTACKER, 3, 12, TrAI00_235E
    end
TrAI00_0898:
    if_stat_stage_equal AI_ATTACKER, 4, 12, TrAI00_235E
    end
TrAI00_08AC:
    load_known_ability AI_DEFENDER
    if_equal 99, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 99, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 6, 12, TrAI00_235E
    end
TrAI00_08E0:
    load_known_ability AI_DEFENDER
    if_equal 99, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 99, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 7, 12, TrAI00_235E
    end
TrAI00_0914:
    if_stat_stage_equal AI_DEFENDER, 1, 0, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 128, TrAI00_2366
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0A84
    load_known_ability AI_DEFENDER
    if_equal 52, TrAI00_235E
    jump TrAI00_0A84
TrAI00_095C:
    if_stat_stage_equal AI_DEFENDER, 2, 0, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0A84
    load_known_ability AI_DEFENDER
    if_equal 145, TrAI00_235E
    jump TrAI00_0A84
TrAI00_0994:
    if_field_effect 1, TrAI00_235E
    if_stat_stage_equal AI_DEFENDER, 5, 0, TrAI00_235E
    load_known_ability_is AI_DEFENDER, 3
    if_equal 1, TrAI00_235E
    jump TrAI00_0A84
TrAI00_09CA:
    if_stat_stage_equal AI_DEFENDER, 3, 0, TrAI00_235E
    jump TrAI00_0A84
TrAI00_09E2:
    if_stat_stage_equal AI_DEFENDER, 4, 0, TrAI00_235E
    jump TrAI00_0A84
TrAI00_09FA:
    if_stat_stage_equal AI_DEFENDER, 6, 0, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 99, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 99, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0A84
    load_known_ability AI_DEFENDER
    if_equal 51, TrAI00_235E
    jump TrAI00_0A84
TrAI00_0A52:
    if_stat_stage_equal AI_DEFENDER, 7, 0, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 99, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 99, TrAI00_235E
TrAI00_0A84:
    load_known_ability AI_DEFENDER
    if_equal 126, TrAI00_2366
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0AC8
    load_known_ability AI_DEFENDER
    if_equal 29, TrAI00_235E
    if_equal 73, TrAI00_235E
    if_equal 156, TrAI00_2366
TrAI00_0AC8:
    end
TrAI00_0ACA:
    if_stat_stage_less_than AI_ATTACKER, 1, 6, TrAI00_0BCC
    if_stat_stage_less_than AI_ATTACKER, 2, 6, TrAI00_0BCC
    if_stat_stage_less_than AI_ATTACKER, 5, 6, TrAI00_0BCC
    if_stat_stage_less_than AI_ATTACKER, 3, 6, TrAI00_0BCC
    if_stat_stage_less_than AI_ATTACKER, 4, 6, TrAI00_0BCC
    if_stat_stage_less_than AI_ATTACKER, 6, 6, TrAI00_0BCC
    if_stat_stage_less_than AI_ATTACKER, 7, 6, TrAI00_0BCC
    if_stat_stage_greater_than AI_DEFENDER, 1, 6, TrAI00_0BCC
    if_stat_stage_greater_than AI_DEFENDER, 2, 6, TrAI00_0BCC
    if_stat_stage_greater_than AI_DEFENDER, 5, 6, TrAI00_0BCC
    if_stat_stage_greater_than AI_DEFENDER, 3, 6, TrAI00_0BCC
    if_stat_stage_greater_than AI_DEFENDER, 4, 6, TrAI00_0BCC
    if_stat_stage_greater_than AI_DEFENDER, 6, 6, TrAI00_0BCC
    if_stat_stage_greater_than AI_DEFENDER, 7, 6, TrAI00_0BCC
    jump TrAI00_235E
TrAI00_0BCC:
    end
TrAI00_0BCE:
    load_able_party_count AI_DEFENDER
    if_equal 0, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0C08
    load_known_ability AI_DEFENDER
    if_equal 21, TrAI00_235E
    if_equal 156, TrAI00_2366
TrAI00_0C08:
    end
TrAI00_0C0A:
    if_hp_not_equal AI_ATTACKER, 100, TrAI00_0C1E
    add_to_score -8
TrAI00_0C1E:
    end
TrAI00_0C20:
    load_type 0
    if_equal 8, TrAI00_235E
    if_equal 3, TrAI00_235E
    load_type 2
    if_equal 8, TrAI00_235E
    if_equal 3, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 17, TrAI00_235E
    if_equal 98, TrAI00_235E
    if_equal 90, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0CAE
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
    if_not_equal 102, TrAI00_0CAE
    load_weather
    if_equal 1, TrAI00_235E
TrAI00_0CAE:
    load_known_ability AI_DEFENDER
    if_not_equal 93, TrAI00_0CCA
    load_weather
    if_equal 2, TrAI00_235E
TrAI00_0CCA:
    if_status AI_DEFENDER, TrAI00_235E
    if_side_effect AI_DEFENDER, 2, TrAI00_235E
    end
TrAI00_0CE4:
    if_side_effect AI_ATTACKER, 1, TrAI00_2356
    end
TrAI00_0CF4:
    if_effectiveness 0, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0D1E
    load_known_ability AI_DEFENDER
    if_equal 5, TrAI00_235E
TrAI00_0D1E:
    if_level_compare 1, TrAI00_235E
    end
TrAI00_0D2A:
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0D4A
    load_known_ability AI_DEFENDER
    if_equal 26, TrAI00_235E
TrAI00_0D4A:
    if_effectiveness 0, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_not_equal 25, TrAI00_0D8E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0D8E
    if_effectiveness 4, TrAI00_0D8E
    if_effectiveness 5, TrAI00_0D8E
    jump TrAI00_235E
TrAI00_0D8E:
    end
TrAI00_0D90:
    if_side_effect AI_ATTACKER, 3, TrAI00_2356
    end
TrAI00_0DA0:
    if_condition_flag AI_ATTACKER, 9, TrAI00_235E
    end
TrAI00_0DB0:
    if_condition AI_DEFENDER, 6, TrAI00_2346
    if_side_effect AI_DEFENDER, 2, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 20, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0DFC
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_0DFC:
    end
TrAI00_0DFE:
    if_side_effect AI_ATTACKER, 0, TrAI00_2356
    end
TrAI00_0E0E:
    if_effectiveness 0, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 7, TrAI00_235E
    if_equal 98, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0E76
    if_move 86, TrAI00_0E52
    jump TrAI00_0E76
TrAI00_0E52:
    load_known_ability AI_DEFENDER
    if_equal 78, TrAI00_235E
    if_equal 10, TrAI00_235E
    if_equal 156, TrAI00_2366
TrAI00_0E76:
    if_status AI_DEFENDER, TrAI00_235E
    if_side_effect AI_DEFENDER, 2, TrAI00_235E
    end
TrAI00_0E90:
    if_substitute AI_ATTACKER, TrAI00_2356
    if_hp_less_than AI_ATTACKER, 26, TrAI00_235E
    end
TrAI00_0EAA:
    if_condition AI_DEFENDER, 18, TrAI00_235E
    load_type 0
    if_equal 11, TrAI00_235E
    load_type 2
    if_equal 11, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 98, TrAI00_235E
    if_equal 156, TrAI00_2366
    end
TrAI00_0EF4:
    if_condition AI_DEFENDER, 13, TrAI00_2356
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0F22
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_0F22:
    end
TrAI00_0F24:
    if_condition AI_DEFENDER, 23, TrAI00_2356
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0F52
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_0F52:
    end
TrAI00_0F54:
    if_not_condition AI_ATTACKER, 2, TrAI00_2356
    end
TrAI00_0F64:
    if_condition AI_DEFENDER, 29, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 99, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 99, TrAI00_235E
    end
TrAI00_0F94:
    if_condition AI_DEFENDER, 22, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_0FC2
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_0FC2:
    end
TrAI00_0FC4:
    load_type 1
    if_equal 7, TrAI00_100A
    load_type 3
    if_equal 7, TrAI00_100A
    if_stat_stage_equal AI_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 2, 12, TrAI00_2356
    end
TrAI00_100A:
    if_condition AI_DEFENDER, 10, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 98, TrAI00_235E
    end
TrAI00_102A:
    load_side_effect AI_DEFENDER, 6
    if_equal 3, TrAI00_235E
    load_able_party_count AI_DEFENDER
    if_equal 0, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_106E
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_106E:
    end
TrAI00_1070:
    if_condition AI_DEFENDER, 17, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_109E
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_109E:
    end
TrAI00_10A0:
    if_condition AI_DEFENDER, 20, TrAI00_235E
    end
TrAI00_10B0:
    load_weather
    if_equal 4, TrAI00_2356
    end
TrAI00_10BE:
    if_condition AI_DEFENDER, 7, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 12, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_10FC
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_10FC:
    load_gender AI_ATTACKER
    if_equal 0, TrAI00_111C
    if_equal 1, TrAI00_1132
    jump TrAI00_235E
TrAI00_111C:
    load_gender AI_DEFENDER
    if_equal 1, TrAI00_1148
    jump TrAI00_235E
TrAI00_1132:
    load_gender AI_DEFENDER
    if_equal 0, TrAI00_1148
    jump TrAI00_235E
TrAI00_1148:
    end
TrAI00_114A:
    if_side_effect AI_ATTACKER, 2, TrAI00_2356
    end
TrAI00_115A:
    load_known_ability AI_DEFENDER
    if_equal 126, TrAI00_2366
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_1194
    load_known_ability AI_DEFENDER
    if_equal 29, TrAI00_235E
    if_equal 73, TrAI00_235E
TrAI00_1194:
    if_stat_stage_equal AI_DEFENDER, 1, 0, TrAI00_235E
    if_stat_stage_equal AI_DEFENDER, 3, 0, TrAI00_2356
    load_able_party_count AI_ATTACKER
    if_equal 0, TrAI00_235E
    end
TrAI00_11CA:
    load_able_party_count AI_ATTACKER
    if_equal 0, TrAI00_235E
    end
TrAI00_11DC:
    load_known_ability AI_ATTACKER
    if_equal 33, TrAI00_1210
    if_equal 93, TrAI00_1210
    load_known_ability AI_DEFENDER
    if_not_equal 93, TrAI00_1210
    if_status AI_DEFENDER, TrAI00_2356
TrAI00_1210:
    load_weather
    if_equal 2, TrAI00_2356
    end
TrAI00_121E:
    load_weather
    if_equal 1, TrAI00_2356
    end
TrAI00_122C:
    unk_cmd_116 AI_DEFENDER, TrAI00_2366
    end
TrAI00_1238:
    load_fake_out_active AI_ATTACKER
    if_equal 0, TrAI00_235E
    end
TrAI00_124A:
    load_stockpile_count AI_ATTACKER
    if_equal 3, TrAI00_235E
    end
TrAI00_125C:
    if_effectiveness 0, TrAI00_235E
    load_stockpile_count AI_ATTACKER
    if_equal 0, TrAI00_235E
    if_move_effect 162, TrAI00_0C0A
    end
TrAI00_1282:
    load_weather
    if_equal 3, TrAI00_2356
    end
TrAI00_1290:
    if_condition AI_DEFENDER, 12, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_12BE
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_12BE:
    end
TrAI00_12C0:
    load_known_ability AI_DEFENDER
    if_equal 41, TrAI00_235E
    if_equal 98, TrAI00_235E
    if_status AI_DEFENDER, TrAI00_235E
    load_type 0
    if_equal 9, TrAI00_235E
    load_type 2
    if_equal 9, TrAI00_235E
    if_side_effect AI_DEFENDER, 2, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_1332
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_1332:
    end
TrAI00_1334:
    load_battle_style
    if_equal 0, TrAI00_235E
    end
TrAI00_1342:
    if_condition AI_DEFENDER, 11, TrAI00_235E
    end
TrAI00_1352:
    load_battle_style
    if_equal 0, TrAI00_235E
    end
TrAI00_1360:
    load_known_ability AI_DEFENDER
    if_equal 60, TrAI00_235E
    load_held_item AI_DEFENDER
    if_equal 0, TrAI00_235E
    end
TrAI00_1382:
    if_condition AI_ATTACKER, 21, TrAI00_235E
    end
TrAI00_1392:
    load_consumed_item AI_ATTACKER
    if_equal 0, TrAI00_235E
    end
TrAI00_13A4:
    if_field_effect 3, TrAI00_235E
    end
TrAI00_13B0:
    if_condition AI_ATTACKER, 5, TrAI00_13EA
    if_badly_poisoned AI_ATTACKER, TrAI00_13EA
    if_condition AI_ATTACKER, 1, TrAI00_13EA
    if_condition AI_ATTACKER, 4, TrAI00_13EA
    jump TrAI00_235E
TrAI00_13EA:
    end
TrAI00_13EC:
    if_field_effect 5, TrAI00_235E
    end
TrAI00_13F8:
    load_known_ability AI_DEFENDER
    if_equal 126, TrAI00_2366
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_143C
    load_known_ability AI_DEFENDER
    if_equal 29, TrAI00_235E
    if_equal 73, TrAI00_235E
    if_equal 156, TrAI00_2366
TrAI00_143C:
    if_stat_stage_equal AI_DEFENDER, 1, 0, TrAI00_235E
    if_stat_stage_equal AI_DEFENDER, 2, 0, TrAI00_2356
    end
TrAI00_1462:
    if_stat_stage_equal AI_ATTACKER, 2, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 4, 12, TrAI00_2356
    end
TrAI00_1488:
    if_stat_stage_equal AI_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 2, 12, TrAI00_2356
    end
TrAI00_14AE:
    if_field_effect 4, TrAI00_235E
    end
TrAI00_14BA:
    if_stat_stage_equal AI_ATTACKER, 3, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 4, 12, TrAI00_2356
    end
TrAI00_14E0:
    if_field_effect 1, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 5, 12, TrAI00_2356
    end
TrAI00_1510:
    end
TrAI00_1512:
    if_field_effect 2, TrAI00_235E
    end
TrAI00_151E:
    if_condition AI_DEFENDER, 17, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_154C
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_154C:
    end
TrAI00_154E:
    add_to_score -20
    load_able_party_count AI_ATTACKER
    if_equal 0, TrAI00_235E
    if_party_member_no_status AI_ATTACKER, TrAI00_157E
    if_party_member_damaged AI_ATTACKER, TrAI00_157E
    jump TrAI00_235E
TrAI00_157E:
    end
TrAI00_1580:
    load_held_item AI_ATTACKER
    if_not_in_list TrAI00_159C, TrAI00_235E
    if_effectiveness 0, TrAI00_235E
    end
TrAI00_159C:
    .4byte 149
    .4byte 150
    .4byte 151
    .4byte 152
    .4byte 153
    .4byte 154
    .4byte 155
    .4byte 156
    .4byte 157
    .4byte 158
    .4byte 159
    .4byte 160
    .4byte 161
    .4byte 162
    .4byte 163
    .4byte 164
    .4byte 165
    .4byte 166
    .4byte 167
    .4byte 168
    .4byte 169
    .4byte 170
    .4byte 171
    .4byte 172
    .4byte 173
    .4byte 174
    .4byte 175
    .4byte 176
    .4byte 177
    .4byte 178
    .4byte 179
    .4byte 180
    .4byte 181
    .4byte 182
    .4byte 183
    .4byte 184
    .4byte 185
    .4byte 186
    .4byte 187
    .4byte 188
    .4byte 189
    .4byte 190
    .4byte 191
    .4byte 192
    .4byte 193
    .4byte 194
    .4byte 195
    .4byte 196
    .4byte 197
    .4byte 198
    .4byte 199
    .4byte 200
    .4byte 201
    .4byte 202
    .4byte 203
    .4byte 204
    .4byte 205
    .4byte 206
    .4byte 207
    .4byte 208
    .4byte 209
    .4byte 210
    .4byte 211
    .4byte 212
    list_end
TrAI00_16A0:
    if_field_effect 1, TrAI00_2356
    if_side_effect AI_ATTACKER, 4, TrAI00_235E
    end
TrAI00_16BA:
    if_stat_stage_equal AI_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 2, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 5, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 3, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 4, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 7, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 6, 12, TrAI00_235E
    end
TrAI00_173A:
    if_effectiveness 0, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 100, TrAI00_235E
    load_held_item_effect AI_DEFENDER
    if_equal 107, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 100, TrAI00_178E
    load_held_item_effect AI_ATTACKER
    if_equal 107, TrAI00_178E
    if_speed_compare 0, TrAI00_235E
TrAI00_178E:
    end
TrAI00_1790:
    if_condition AI_DEFENDER, 19, TrAI00_235E
    load_consumed_item AI_DEFENDER
    if_equal 0, TrAI00_17DA
    load_battle_type
    if_equal 2, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_17DA
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_17DA:
    end
TrAI00_17DC:
    if_effectiveness 0, TrAI00_235E
    load_fling_power AI_ATTACKER
    if_less_than 10, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 121, TrAI00_235E
    load_held_item_effect AI_ATTACKER
    if_in_list TrAI00_1A1A, TrAI00_182C
    if_in_list TrAI00_1A26, TrAI00_1934
    if_in_list TrAI00_1A2E, TrAI00_19F0
    end
TrAI00_182C:
    if_side_effect AI_DEFENDER, 2, TrAI00_18AE
    if_status AI_DEFENDER, TrAI00_18AE
    load_known_ability AI_ATTACKER
    if_equal 90, TrAI00_18AE
    load_type 0
    if_equal 3, TrAI00_18AE
    if_equal 8, TrAI00_18AE
    load_type 2
    if_equal 3, TrAI00_18AE
    if_equal 8, TrAI00_18AE
    load_known_ability AI_DEFENDER
    if_equal 17, TrAI00_18AE
    if_equal 90, TrAI00_18AE
    if_equal 98, TrAI00_18AE
    end
TrAI00_18AE:
    if_side_effect AI_ATTACKER, 2, TrAI00_2346
    if_status AI_ATTACKER, TrAI00_2346
    load_type 1
    if_equal 3, TrAI00_2346
    if_equal 8, TrAI00_2346
    load_type 3
    if_equal 3, TrAI00_2346
    if_equal 8, TrAI00_2346
    load_known_ability AI_ATTACKER
    if_equal 103, TrAI00_2346
    if_equal 17, TrAI00_2346
    if_equal 90, TrAI00_2346
    if_equal 98, TrAI00_2346
    if_equal 62, TrAI00_2346
    end
TrAI00_1934:
    if_side_effect AI_DEFENDER, 2, TrAI00_1988
    if_status AI_DEFENDER, TrAI00_1988
    load_type 0
    if_equal 9, TrAI00_1988
    load_type 2
    if_equal 9, TrAI00_1988
    load_known_ability AI_DEFENDER
    if_equal 98, TrAI00_1988
    if_equal 41, TrAI00_1988
    end
TrAI00_1988:
    if_side_effect AI_ATTACKER, 2, TrAI00_2346
    if_status AI_ATTACKER, TrAI00_2346
    load_type 1
    if_equal 9, TrAI00_2346
    load_type 3
    if_equal 9, TrAI00_2346
    load_known_ability AI_ATTACKER
    if_equal 103, TrAI00_2346
    if_equal 98, TrAI00_2346
    if_equal 41, TrAI00_2346
    if_equal 62, TrAI00_2346
    end
TrAI00_19F0:
    if_side_effect AI_DEFENDER, 2, TrAI00_2346
    if_status AI_DEFENDER, TrAI00_2346
    load_known_ability AI_DEFENDER
    if_equal 7, TrAI00_2346
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
    if_no_status AI_ATTACKER, TrAI00_235E
    if_status AI_DEFENDER, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_1A6A
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_235E
TrAI00_1A6A:
    if_side_effect AI_DEFENDER, 2, TrAI00_235E
    if_condition AI_ATTACKER, 5, TrAI00_1AB2
    if_badly_poisoned AI_ATTACKER, TrAI00_1AB2
    if_condition AI_ATTACKER, 4, TrAI00_1B20
    if_condition AI_ATTACKER, 1, TrAI00_1B60
    jump TrAI00_1B70
TrAI00_1AB2:
    load_known_ability AI_ATTACKER
    if_equal 90, TrAI00_235E
    load_type 0
    if_equal 3, TrAI00_235E
    if_equal 8, TrAI00_235E
    load_type 2
    if_equal 3, TrAI00_235E
    if_equal 8, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 17, TrAI00_235E
    if_equal 90, TrAI00_235E
    if_equal 98, TrAI00_235E
    jump TrAI00_1B70
TrAI00_1B20:
    load_type 0
    if_equal 9, TrAI00_235E
    load_type 2
    if_equal 9, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 98, TrAI00_235E
    if_equal 41, TrAI00_235E
    jump TrAI00_1B70
TrAI00_1B60:
    load_known_ability AI_DEFENDER
    if_equal 7, TrAI00_235E
TrAI00_1B70:
    end
TrAI00_1B72:
    if_condition AI_DEFENDER, 15, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_1BA0
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_1BA0:
    end
TrAI00_1BA2:
    if_condition_flag AI_ATTACKER, 10, TrAI00_235E
    end
TrAI00_1BB2:
    if_condition AI_DEFENDER, 16, TrAI00_235E
    load_known_ability AI_DEFENDER
    if_equal 121, TrAI00_235E
    if_equal 54, TrAI00_235E
    if_equal 129, TrAI00_235E
    if_equal 112, TrAI00_235E
    if_equal 1, TrAI00_235E
    if_equal 50, TrAI00_235E
    if_equal 53, TrAI00_235E
    if_equal 118, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_1C36
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_1C36:
    end
TrAI00_1C38:
    if_side_effect AI_ATTACKER, 5, TrAI00_235E
    end
TrAI00_1C48:
    load_turn_count
    if_not_equal 0, TrAI00_1C68
    if_speed_compare 1, TrAI00_1C68
    if_speed_compare 0, TrAI00_235E
TrAI00_1C68:
    end
TrAI00_1C6A:
    load_stat_stage_difference AI_DEFENDER, 1
    if_less_than 1, TrAI00_1C84
    jump TrAI00_1C98
TrAI00_1C84:
    load_stat_stage_difference AI_DEFENDER, 3
    if_less_than 1, TrAI00_235E
TrAI00_1C98:
    end
TrAI00_1C9A:
    load_stat_stage_difference AI_DEFENDER, 2
    if_less_than 1, TrAI00_1CB4
    jump TrAI00_1CC8
TrAI00_1CB4:
    load_stat_stage_difference AI_DEFENDER, 4
    if_less_than 1, TrAI00_235E
TrAI00_1CC8:
    end
TrAI00_1CCA:
    if_can_use_last_resort AI_ATTACKER, TrAI00_1CDA
    add_to_score -10
TrAI00_1CDA:
    end
TrAI00_1CDC:
    load_known_ability AI_DEFENDER
    if_equal 54, TrAI00_235E
    if_equal 129, TrAI00_235E
    if_equal 15, TrAI00_235E
    if_equal 72, TrAI00_235E
    if_equal 121, TrAI00_235E
    if_not_condition AI_DEFENDER, 2, TrAI00_1D64
    if_knows_move AI_DEFENDER, 214, TrAI00_1D64
    if_knows_move AI_DEFENDER, 173, TrAI00_1D64
    add_to_score -10
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_1D64
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_1D64:
    end
TrAI00_1D66:
    load_side_effect AI_DEFENDER, 7
    if_equal 2, TrAI00_235E
    load_able_party_count AI_DEFENDER
    if_equal 0, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_1DAA
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_1DAA:
    end
TrAI00_1DAC:
    if_condition AI_ATTACKER, 35, TrAI00_235E
    end
TrAI00_1DBC:
    if_condition AI_ATTACKER, 30, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 26, TrAI00_235E
    load_type 1
    if_equal 2, TrAI00_235E
    load_type 3
    if_equal 2, TrAI00_235E
    end
TrAI00_1DFC:
    if_stat_stage_not_equal AI_DEFENDER, 7, 0, TrAI00_1E96
    if_side_effect AI_DEFENDER, 1, TrAI00_1E96
    if_side_effect AI_DEFENDER, 0, TrAI00_1E96
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_1E4A
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_1E4A:
    load_weather
    if_equal 0, TrAI00_1E96
    load_able_party_count AI_DEFENDER
    if_equal 0, TrAI00_235E
    if_side_effect AI_DEFENDER, 6, TrAI00_1E96
    if_side_effect AI_DEFENDER, 8, TrAI00_1E96
    if_side_effect AI_DEFENDER, 7, TrAI00_1E96
    jump TrAI00_235E
TrAI00_1E96:
    end
TrAI00_1E98:
    if_speed_compare 0, TrAI00_235E
    if_speed_compare 2, TrAI00_235E
    end
TrAI00_1EAE:
    load_known_ability AI_DEFENDER
    if_equal 126, TrAI00_2366
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_1EFC
    load_known_ability AI_DEFENDER
    if_equal 12, TrAI00_235E
    if_equal 29, TrAI00_235E
    if_equal 73, TrAI00_235E
    if_equal 156, TrAI00_2366
TrAI00_1EFC:
    load_gender AI_ATTACKER
    if_equal 0, TrAI00_1F1C
    if_equal 1, TrAI00_1F32
    jump TrAI00_235E
TrAI00_1F1C:
    load_gender AI_DEFENDER
    if_equal 1, TrAI00_1F48
    jump TrAI00_235E
TrAI00_1F32:
    load_gender AI_DEFENDER
    if_equal 0, TrAI00_1F48
    jump TrAI00_235E
TrAI00_1F48:
    if_stat_stage_less_than AI_DEFENDER, 3, 1, TrAI00_235E
    end
TrAI00_1F5C:
    if_side_effect AI_DEFENDER, 8, TrAI00_235E
    load_able_party_count AI_DEFENDER
    if_equal 0, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_1F9A
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_1F9A:
    end
TrAI00_1F9C:
    add_to_score -20
    load_able_party_count AI_ATTACKER
    if_equal 0, TrAI00_235E
    if_party_member_damaged AI_ATTACKER, TrAI00_1FD6
    if_party_member_no_status AI_ATTACKER, TrAI00_1FD6
    if_party_member_used_pp AI_ATTACKER, TrAI00_1FD6
    jump TrAI00_235E
TrAI00_1FD6:
    end
TrAI00_1FD8:
    load_known_ability AI_ATTACKER
    if_not_equal 86, TrAI00_200C
    if_stat_stage_greater_than AI_ATTACKER, 1, 8, TrAI00_235E
    if_stat_stage_greater_than AI_ATTACKER, 6, 8, TrAI00_2356
TrAI00_200C:
    if_stat_stage_equal AI_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 6, 12, TrAI00_2356
    end
TrAI00_2032:
    load_battle_style
    if_equal 0, TrAI00_235E
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
    if_stat_stage_equal AI_ATTACKER, 5, 12, TrAI00_235E
    end
TrAI00_2068:
    if_condition AI_DEFENDER, 32, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_2096
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
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
    if_stat_stage_equal AI_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 2, 12, TrAI00_2356
    if_stat_stage_equal AI_ATTACKER, 5, 12, TrAI00_234E
    end
TrAI00_20E2:
    end
TrAI00_20E4:
    end
TrAI00_20E6:
    end
TrAI00_20E8:
    load_type 0
    if_not_equal_2 10, TrAI00_2108
    load_type 2
    if_equal_2 10, TrAI00_235E
TrAI00_2108:
    end
TrAI00_210A:
    end
TrAI00_210C:
    end
TrAI00_210E:
    end
TrAI00_2110:
    load_known_ability AI_DEFENDER
    if_equal 121, TrAI00_235E
    if_equal 54, TrAI00_235E
    if_equal 129, TrAI00_235E
    if_equal 112, TrAI00_235E
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_215E
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_215E:
    end
TrAI00_2160:
    load_known_ability AI_ATTACKER
    if_equal 104, TrAI00_2180
    load_known_ability AI_DEFENDER
    if_equal 156, TrAI00_2366
TrAI00_2180:
    end
TrAI00_2182:
    load_battle_style
    if_equal 0, TrAI00_235E
    end
TrAI00_2190:
    load_battle_style
    if_equal 0, TrAI00_235E
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
    if_equal 0, TrAI00_235E
    end
TrAI00_21B6:
    if_stat_stage_equal AI_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 3, 12, TrAI00_2356
    if_stat_stage_equal AI_ATTACKER, 5, 12, TrAI00_234E
    end
TrAI00_21EE:
    load_battle_style
    if_equal 0, TrAI00_235E
    end
TrAI00_21FC:
    end
TrAI00_21FE:
    end
TrAI00_2200:
    if_stat_stage_equal AI_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 5, 12, TrAI00_2356
    end
TrAI00_2226:
    end
TrAI00_2228:
    end
TrAI00_222A:
    load_battle_style
    if_equal 0, TrAI00_235E
    end
TrAI00_2238:
    if_stat_stage_equal AI_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 3, 12, TrAI00_2356
    end
TrAI00_225E:
    end
TrAI00_2260:
    end
TrAI00_2262:
    end
TrAI00_2264:
    load_able_party_count AI_ATTACKER
    if_not_equal 0, TrAI00_228A
    load_able_party_count AI_DEFENDER
    if_not_equal 0, TrAI00_235E
    jump TrAI00_232E
TrAI00_228A:
    end
TrAI00_228C:
    end
TrAI00_228E:
    if_stat_stage_equal AI_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 2, 12, TrAI00_2356
    if_stat_stage_equal AI_ATTACKER, 6, 12, TrAI00_234E
    end
TrAI00_22C6:
    load_held_item AI_DEFENDER
    if_not_equal 0, TrAI00_235E
    load_battle_style
    if_equal 0, TrAI00_235E
    end
TrAI00_22E4:
    end
TrAI00_22E6:
    end
TrAI00_22E8:
    end
TrAI00_22EA:
    if_stat_stage_equal AI_ATTACKER, 1, 12, TrAI00_235E
    if_stat_stage_equal AI_ATTACKER, 3, 12, TrAI00_2356
    end
TrAI00_2310:
    if_stat_stage_equal AI_ATTACKER, 2, 12, TrAI00_235E
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
