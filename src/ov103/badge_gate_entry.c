#include "field/badge_gate.h"

void *func_ov103_021ef1ac(void *work, u32 index, u32 group) {
    switch (group) {
    case 0:
        return (u8 *)work + 0x10 + index * 0x10;
    case 1:
        return (u8 *)work + 0x90 + index * 0x10;
    case 2:
        return (u8 *)work + 0x120 + index * 0x10;
    default:
        return NULL;
    }
}
