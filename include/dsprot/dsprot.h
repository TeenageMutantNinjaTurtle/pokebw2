#ifndef POKEBW2_DSPROT_DSPROT_H
#define POKEBW2_DSPROT_DSPROT_H

#include "types.h"
#include "gfl/overlay.h"
#include "nitro/hw.h"

// DS Protect's anti-piracy checks run from overlay 337
#define OVERLAY_DSPROT OVERLAY_ID(337)

#define DSPROT_CHECKSUM 0x9f75a8d6

typedef void *(*DSProtCallback)(void *arg0, void *arg1);

extern u32 data_ov337_02182440;
extern DSProtCallback data_ov337_02182444[2];

// Calls a DS Protect function after verifying its code. If the checksum does not match, `tamper` is called instead.
// `nop` and `tamper` are put in a table in a random order, picked with the VBlank counter.
#define DSPROT_CHECKED_CALL(func, nop, tamper, arg0, arg1)                                                             \
    {                                                                                                                  \
        u32 index = *(u32 *)HW_VBLANK_COUNT_BUF & 1;                                                                   \
        u32 tamperIndex;                                                                                               \
        u32 i;                                                                                                         \
        u32 checksum;                                                                                                  \
        u32 *code;                                                                                                     \
        data_ov337_02182440 = index;                                                                                   \
        tamperIndex = index ^ 1;                                                                                       \
        data_ov337_02182444[index] = nop;                                                                              \
        data_ov337_02182444[tamperIndex] = tamper;                                                                     \
        code = (u32 *)func;                                                                                            \
        for (i = 0x25, checksum = 0; i != 0; i--) {                                                                    \
            checksum ^= (*code >> i) | (*code << (32 - i));                                                            \
            code++;                                                                                                    \
        }                                                                                                              \
        if (checksum == DSPROT_CHECKSUM) {                                                                             \
            func(arg0, arg1);                                                                                          \
        } else {                                                                                                       \
            data_ov337_02182444[tamperIndex](arg0, arg1);                                                              \
        }                                                                                                              \
    }

void *func_ov337_02180a84(void *arg0, void *arg1);
void *func_ov337_02180b30(void *arg0, void *arg1);
void func_ov337_02180bdc(void);

#endif // POKEBW2_DSPROT_DSPROT_H
