#ifndef POKEBW2_DWC_DWC_H
#define POKEBW2_DWC_DWC_H

#include "types.h"

// Nintendo's Wi-Fi Connection library (NitroDWC), in main and overlay 11. The ROM names none of it; what these
// functions do is read off their callers, and they have no names yet

// The friend key of the player's user data
u64 func_02057ec4(const void *userData);

// Starts connecting to the access point; one of the calls that end the connection after a server error; and the
// connection's state
void func_ov011_0215dec0(void);
void func_ov011_0215fb78(void);
int func_ov011_0215df40(void);

#endif // POKEBW2_DWC_DWC_H
