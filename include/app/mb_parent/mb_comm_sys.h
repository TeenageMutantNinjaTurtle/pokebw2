#ifndef POKEBW2_APP_MB_PARENT_MB_COMM_SYS_H
#define POKEBW2_APP_MB_PARENT_MB_COMM_SYS_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The connection to the downloaded child once it has booted (mb_comm_sys.c), which the parent sends the child
// program to, and receives the Pokémon from

// What the parent tells the child about itself
typedef struct {
    s32 textSpeed;
    u16 highScore;
    u8 language;
} MBCommParentInfo;

MBCommSys *func_ov181_0219f580(HeapID heapId);
void func_ov181_0219f5d8(MBCommSys *comm);
void func_ov181_0219f60c(MBCommSys *comm);
void func_ov181_0219f6ac(MBCommSys *comm);
void func_ov181_0219f798(MBCommSys *comm);
BOOL func_ov181_0219f7b8(MBCommSys *comm);
BOOL func_ov181_0219f7c0(MBCommSys *comm);
void func_ov181_0219f7c8(MBCommSys *comm);
void func_ov181_0219f7d8(MBCommSys *comm);
BOOL func_ov181_0219f7f0(MBCommSys *comm);
BOOL func_ov181_0219f800(MBCommSys *comm);
int func_ov181_0219f810(MBCommSys *comm);
void func_ov181_0219f814(MBCommSys *comm);
BOOL func_ov181_0219f894(MBCommSys *comm);
BOOL func_ov181_0219f89c(MBCommSys *comm);
BOOL func_ov181_0219f8a4(MBCommSys *comm);
BOOL func_ov181_0219f8ac(MBCommSys *comm);
BOOL func_ov181_0219f8b4(MBCommSys *comm);
BOOL func_ov181_0219f8bc(MBCommSys *comm);
BOOL func_ov181_0219f8c4(MBCommSys *comm);
u16 func_ov181_0219f8cc(MBCommSys *comm);
u16 func_ov181_0219f8d4(MBCommSys *comm);
BOOL func_ov181_0219f8e8(MBCommSys *comm);
BOOL func_ov181_0219f8fc(MBCommSys *comm);
BOOL func_ov181_0219f910(MBCommSys *comm);
BOOL func_ov181_0219f918(MBCommSys *comm);
BOOL func_ov181_0219f920(MBCommSys *comm);
void func_ov181_0219f928(MBCommSys *comm, void *data, u32 size);
void func_ov181_0219f938(MBCommSys *comm);
BOOL func_ov181_0219f970(MBCommSys *comm);
BOOL func_ov181_0219f978(MBCommSys *comm);
u8 func_ov181_0219f980(MBCommSys *comm);
BoxPkm *func_ov181_0219f988(MBCommSys *comm, u8 index);
u16 func_ov181_0219f99c(MBCommSys *comm);
BOOL func_ov181_0219f9a4(MBCommSys *comm);
BOOL func_ov181_0219f9ac(MBCommSys *comm, u8 command, u32 value);
BOOL func_ov181_0219fb38(MBCommSys *comm, MBCommParentInfo *info);

#endif // POKEBW2_APP_MB_PARENT_MB_COMM_SYS_H
