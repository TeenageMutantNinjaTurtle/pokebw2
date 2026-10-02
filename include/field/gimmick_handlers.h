#ifndef POKEBW2_FIELD_GIMMICK_HANDLERS_H
#define POKEBW2_FIELD_GIMMICK_HANDLERS_H

#include "types.h"
#include "struct_decls.h"

struct GimmickHandlerTable {
    u32 reserved[10];
    u32 count;
    void *handlers[7];
    u32 tail[6];
};

extern GimmickHandlerTable data_ov074_021e9240;

// Shared field gimmick helpers in overlay 36, called by the overlay 74 handler table.
u32 *func_ov036_021997e4(void *ctx);
void func_ov036_02199734(void *ctx, u32 a1, u32 a2);
void func_ov036_02199740(void *ctx, u32 a1, u32 a2);
void func_ov036_0219974c(void *ctx, u32 a1);
void func_ov036_0219990c(void *ctx, u32 a1, u32 a2, u32 a3);
void func_ov036_02199948(void *ctx, u32 a1);
void func_ov036_02199958(void *ctx, u32 a1, u32 a2, u32 a3, u32 a4);
void func_ov036_021999bc(void *ctx, u32 a1, u32 a2, u32 a3);
BOOL func_ov036_021999dc(void *ctx);
BOOL func_ov036_02199a00(void *ctx);
BOOL func_ov036_02199a14(void *ctx);
BOOL func_ov036_02199a20(void *ctx);
u32 func_ov036_02199a2c(void *ctx);
u32 func_ov036_02199a38(void *ctx);
u32 func_ov036_02199a44(void *ctx);

BOOL func_ov074_021e90c0(void *ctx, u32 arg);
BOOL func_ov074_021e9108(void *ctx, u32 arg);
BOOL func_ov074_021e9170(void *ctx, u32 arg);
BOOL func_ov074_021e91b8(void);
BOOL func_ov074_021e91bc(void *ctx, u32 arg);
BOOL func_ov074_021e91e0(void *ctx);
BOOL func_ov074_021e91f4(void *ctx, u32 arg);

#endif // POKEBW2_FIELD_GIMMICK_HANDLERS_H
