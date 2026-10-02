#include "types.h"

typedef struct {
    u32 reserved[10];
    u32 count;
    void *handlers[7];
    u32 tail[6];
} GimmickHandlerTable;

extern BOOL func_ov036_02199a00(void *ctx);
extern u32 *func_ov036_021997e4(void *ctx);
extern BOOL func_ov036_02199a14(void *ctx);
extern u32 func_ov036_02199a2c(void *ctx);
extern u32 func_ov036_02199a38(void *ctx);
extern void func_ov036_0219990c(void *ctx, u32 a1, u32 a2, u32 a3);
extern void func_ov036_02199958(void *ctx, u32 a1, u32 a2, u32 a3, u32 a4);
extern BOOL func_ov036_02199a20(void *ctx);
extern u32 func_ov036_02199a44(void *ctx);
extern void func_ov036_02199734(void *ctx, u32 a1, u32 a2);
extern void func_ov036_02199740(void *ctx, u32 a1, u32 a2);
extern BOOL func_ov036_021999dc(void *ctx);
extern void func_ov036_021999bc(void *ctx, u32 a1, u32 a2, u32 a3);
extern void func_ov036_02199948(void *ctx, u32 a1);
extern void func_ov036_0219974c(void *ctx, u32 a1);

BOOL func_ov074_021e90c0(void *ctx, u32 arg);
BOOL func_ov074_021e9108(void *ctx, u32 arg);
BOOL func_ov074_021e9170(void *ctx, u32 arg);
BOOL func_ov074_021e91b8(void);
BOOL func_ov074_021e91bc(void *ctx, u32 arg);
BOOL func_ov074_021e91e0(void *ctx);
BOOL func_ov074_021e91f4(void *ctx, u32 arg);

GimmickHandlerTable data_ov074_021e9240 = {
    {0}, 4,
    {(void *)func_ov074_021e90c0, (void *)func_ov074_021e9108, (void *)func_ov074_021e9170,
     (void *)func_ov074_021e91b8, (void *)func_ov074_021e91bc, (void *)func_ov074_021e91e0,
     (void *)func_ov074_021e91f4},
    {0}
};

BOOL func_ov074_021e90c0(void *ctx, u32 arg) {
    if (func_ov036_02199a00(ctx)) {
        return FALSE;
    }
    *func_ov036_021997e4(ctx) = 0;
    if (func_ov036_02199a14(ctx)) {
        func_ov036_02199a2c(ctx);
        func_ov036_0219990c(ctx, func_ov036_02199a38(ctx), 0x7fff, arg);
    }
    return TRUE;
}

BOOL func_ov074_021e9108(void *ctx, u32 arg) {
    u32 *state = func_ov036_021997e4(ctx);
    if (*state == 0) {
        if (func_ov036_02199a14(ctx)) {
            u32 value = func_ov036_02199a2c(ctx);
            func_ov036_02199958(ctx, func_ov036_02199a38(ctx), value, 0xa0, arg);
        }
        if (func_ov036_02199a20(ctx)) {
            func_ov036_02199734(ctx, 0x51, func_ov036_02199a44(ctx));
        }
        *state = 1;
    }
    if (func_ov036_021999dc(ctx)) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov074_021e9170(void *ctx, u32 arg) {
    if (func_ov036_02199a14(ctx)) {
        u32 value = func_ov036_02199a2c(ctx);
        func_ov036_0219990c(ctx, func_ov036_02199a38(ctx), value, arg);
    }
    if (func_ov036_02199a20(ctx)) {
        func_ov036_02199740(ctx, 0x51, func_ov036_02199a44(ctx));
    }
    return TRUE;
}

BOOL func_ov074_021e91b8(void) {
    return FALSE;
}

BOOL func_ov074_021e91bc(void *ctx, u32 arg) {
    if (func_ov036_02199a14(ctx)) {
        func_ov036_021999bc(ctx, 0x7fff, 0x50, arg);
    }
    return TRUE;
}

BOOL func_ov074_021e91e0(void *ctx) {
    if (func_ov036_021999dc(ctx)) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov074_021e91f4(void *ctx, u32 arg) {
    if (func_ov036_02199a14(ctx)) {
        func_ov036_02199948(ctx, arg);
    }
    if (func_ov036_02199a20(ctx)) {
        func_ov036_0219974c(ctx, arg);
    }
    return TRUE;
}
