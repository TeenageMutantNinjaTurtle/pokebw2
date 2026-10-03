#include "battle/btl_pokeparam.h"

// Function name from swan.
BOOL PokeTypePair_IsMonotype(PokeTypePair pair) {
    return PokeTypePair_GetType1(pair) == PokeTypePair_GetType2(pair);
}
