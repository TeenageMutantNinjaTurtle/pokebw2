#include "battle/btl_pokeparam.h"

// Function names from swan.
u8 PokeTypePair_GetType1(PokeTypePair pair) {
    return (u8)(pair >> 8);
}

u8 PokeTypePair_GetType2(PokeTypePair pair) {
    return (u8)pair;
}
