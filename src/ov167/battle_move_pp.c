#include "battle/btl_pokeparam.h"

// Function names from swan.
u16 Move_IncrementPP(BattleMon *mon, u8 index, u8 amount) {
    u8 *move;

    move = (u8 *)mon + 0x104 + index * 14;
    move[8] += amount;
    if (move[8] > move[9]) {
        move[8] = move[9];
    }
    if (move[12] != 0) {
        move[2] = move[8];
    }
    return *(u16 *)(move + 6);
}

u16 Move_IncrementPP_Org(BattleMon *mon, u8 index, u8 amount) {
    u8 *move;

    move = (u8 *)mon + 0x104 + index * 14;
    move[2] += amount;
    if (move[2] > move[3]) {
        move[2] = move[3];
    }
    if (move[12] != 0) {
        move[8] = move[2];
    }
    return *(u16 *)move;
}
