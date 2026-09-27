#include "types.h"

typedef struct {
    u32 unk0;
    void *unk4;
    u32 unk8;
    void *unkC;
    void *unk10;
    void *unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
    void *unk28;
    void *unk2C;
    void *unk30;
    void *unk34;
    void *unk38;
    void *unk3C;
    u32 unk40;
    u32 unk44;
    void *unk48;
    void *unk4C;
    u32 unk50;
} Ov004Work;

typedef struct {
    u32 unk0;
    u32 unk4;
} Ov004Args;

extern void *func_02016ad8(void *proc);
extern void *func_02016cb4(void *proc, u32 a1, void *func, u32 size);
extern void *func_02016b20(void *proc);
extern BOOL func_0202bdd4(void *a0);
extern void func_0202bd80(void *a0);
extern void *func_02016edc(void *a0);
extern void func_020787a8(void *dest, u32 value, u32 size);
extern void *func_02017934(void *a0);
extern void *func_0200b488(void *a0);
extern void *func_020092e4(void *a0);
extern void *func_0202018c(void *a0);
extern void *func_02017364(void *a0);
extern void *func_0200d190(void *a0);
extern void *func_02017238(void *a0);
extern void *func_02009b78(void *a0);
extern void *func_02008dd0(void *a0);
extern void *func_02008ddc(void *a0);
extern void *func_02009408(void *a0);
extern void *func_02017354(void *a0);
extern void *func_0200d1ac(void *a0);
extern void *func_0200a3dc(void *a0);
extern void func_02016d68(void *a0, void *a1);
extern void *func_ov036_021b870c(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 func_02005c9c(void);
extern void func_02005ea0(u32 a0);
extern void *func_020193a4(void *a0, u32 a1);
extern void func_02016a98(void *a0, u32 a1, void *a2, void *a3);
extern BOOL func_02016ad4(void *a0);
extern void func_02005df4(u32 a0, u32 a1);
extern void func_02005e68(u32 a0);
extern void *func_02019494(void *a0);
extern void *func_ov036_021b878c(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern u8 data_ov036_021e1ab8[];
// Defined by the linker script, the address is the overlay ID
extern u32 OVERLAY_214_ID[];

void *func_ov004_0214f50c(void *proc, u32 a1, u32 unused);
BOOL func_ov004_0214f5d0(void *proc, int *state, Ov004Work *work);

void *func_ov004_0214f500(void *proc, Ov004Args *args) {
    return func_ov004_0214f50c(proc, args->unk0, args->unk4);
}

void *func_ov004_0214f50c(void *proc, u32 a1, u32 unused) {
    void *unk = func_02016ad8(proc);
    void *result = func_02016cb4(proc, 0, func_ov004_0214f5d0, sizeof(Ov004Work));
    Ov004Work *work;

    if (func_0202bdd4(func_02016b20(proc))) {
        func_0202bd80(func_02016b20(proc));
    }

    work = func_02016edc(result);
    func_020787a8(work, 0, sizeof(Ov004Work));
    work->unk4 = proc;
    work->unk8 = a1;
    work->unk48 = func_02017934(unk);
    work->unkC = func_0200b488(work->unk48);
    work->unk10 = func_020092e4(work->unk48);
    work->unk14 = func_0202018c(work->unk48);
    work->unk18 = func_02017364(unk);
    work->unk1C = func_0200d190(unk);
    work->unk20 = func_02017238(unk);
    work->unk24 = func_02009b78(work->unk48);
    work->unk28 = func_02008dd0(work->unk48);
    work->unk2C = func_02008ddc(work->unk48);
    work->unk30 = func_02009408(work->unk48);
    work->unk34 = func_02017354(unk);
    work->unk4C = proc;
    work->unk38 = func_0200d1ac(work->unk1C);
    work->unk3C = func_0200a3dc(work->unk20);
    work->unk40 = 0;
    work->unk44 = 0;
    return result;
}

BOOL func_ov004_0214f5d0(void *proc, int *state, Ov004Work *work) {
    switch (*state) {
    case 0:
        if (!func_0202bdd4(func_02016b20(work->unk4))) {
            *state = 1;
        }
        break;
    case 1:
        if (work->unk50) {
            func_02016d68(proc, func_ov036_021b870c(work->unk4, work->unk8, 0, 0));
        }
        work->unk0 = func_02005c9c();
        func_02005ea0(6);
        *state = 2;
        break;
    case 2:
        func_02016d68(proc, func_020193a4(work->unk4, work->unk8));
        *state = 3;
        break;
    case 3:
        func_02016a98(work->unk4, (u32)OVERLAY_214_ID, data_ov036_021e1ab8, &work->unkC);
        *state = 4;
        break;
    case 4:
        if (!func_02016ad4(work->unk4)) {
            func_02005df4(work->unk0, 0xffff);
            func_02005e68(60);
            func_02016d68(proc, func_02019494(work->unk4));
            *state = 5;
        }
        break;
    case 5:
        if (work->unk50) {
            func_02016d68(proc, func_ov036_021b878c(work->unk4, work->unk8, 0, 0, 1, 0, 0));
        }
        *state = 6;
        break;
    case 6:
        return TRUE;
    }
    return FALSE;
}
