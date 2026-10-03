#include "gfl/random.h"

u16 randFFFFFFFFdivFFFF(void) {
    return GFL_RandomLC(0xffffffff) / 0xffff;
}
