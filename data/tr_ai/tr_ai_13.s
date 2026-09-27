#include "asm/tr_ai.inc"

TrAI13_0000:
    if_hp_equal TRAI_SIDE_DEFENDER, 20, TrAI13_001E
    if_hp_less_than TRAI_SIDE_DEFENDER, 20, TrAI13_001E
    end
TrAI13_001E:
    flee
    end
    .balign 4
