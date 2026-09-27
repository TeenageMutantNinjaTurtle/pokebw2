#ifndef POKEBW2_CONSTANTS_TR_AI_H
#define POKEBW2_CONSTANTS_TR_AI_H

// Constants of the trainer AI scripts, see src/ov170/tr_ai.c

// Which Pokemon a command refers to
#define TRAI_SIDE_DEFENDER 0
#define TRAI_SIDE_ATTACKER 1
#define TRAI_SIDE_DEFENDER_PARTNER 2
#define TRAI_SIDE_ATTACKER_PARTNER 3

// Which type load_type loads: the first or second type of a Pokemon, or the move's type
#define TRAI_TYPE_DEFENDER_1 0
#define TRAI_TYPE_ATTACKER_1 1
#define TRAI_TYPE_DEFENDER_2 2
#define TRAI_TYPE_ATTACKER_2 3
#define TRAI_TYPE_MOVE 4
#define TRAI_TYPE_DEFENDER_PARTNER_1 5
#define TRAI_TYPE_ATTACKER_PARTNER_1 6
#define TRAI_TYPE_DEFENDER_PARTNER_2 7
#define TRAI_TYPE_ATTACKER_PARTNER_2 8

#endif // POKEBW2_CONSTANTS_TR_AI_H
