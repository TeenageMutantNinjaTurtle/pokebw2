#include "battle/btl_pokeparam.h"

// Function name from swan.
PokeTypePair PokeTypePair_Make(u32 type1, u32 type2) {
    u32 first;
    u32 second;

    first = (type1 << 24) >> 16;
    second = (type2 << 24) >> 24;
    return (u16)(first | second);
}
