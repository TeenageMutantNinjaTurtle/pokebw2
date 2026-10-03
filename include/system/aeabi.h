#ifndef POKEBW2_SYSTEM_AEABI_H
#define POKEBW2_SYSTEM_AEABI_H

#include "types.h"

// Quotient is returned in r0 and remainder in r1. The u64 declaration exposes both registers to C.
u64 __aeabi_uidivmod(u32 dividend, u32 divisor);

#endif // POKEBW2_SYSTEM_AEABI_H
