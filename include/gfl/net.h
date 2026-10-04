#ifndef POKEBW2_GFL_NET_H
#define POKEBW2_GFL_NET_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The unnamed functions below are from the network library. Some appear to synchronize with the other player or
// toggle error checks, but that is not confirmed.

BOOL GFL_NetErrCheck(void);
void GFL_NetErrMarkShown(void);
void GFL_NetErrShow(u32 a0);
void func_02011de0(void);
// Calls into the functions that show the wireless strength icons
void func_02042ba8(u32 a0, HeapID heapId);
void func_02012154(void);
u32 func_0203ffc4(void);
u32 func_02042bc4(void);
int func_02042a78(void);
NetHandle *func_02040440(void);
void func_02040624(NetHandle *handle, u32 a1, u32 a2);
BOOL func_02040664(NetHandle *handle, u32 a1, u32 a2);
void func_02040c20(u32 a0, const void *commands, u32 count, void *work);
void func_02040c64(u32 a0);
void func_020421ac(u32 a0);
BOOL func_02042788(void);
BOOL func_ov036_02180f80(GameCommSys *comm);
BOOL func_0202bde0(GameCommSys *comm);
BOOL func_020427a4(void);
void func_02042860(u32 a0);
// Steps the network while the game waits for it, as before a soft reset
void func_020428e0(void);
u32 func_02042a6c(NetHandle *handle);
u32 func_02042c18(NetHandle *handle, u32 destination, u32 command, u32 size, const void *data, u32 count, u32 a6,
                  u32 a7);
BOOL func_02042ab8(void);
void func_02042e94(BOOL a0);
void func_02042e9c(BOOL a0);

#endif // POKEBW2_GFL_NET_H
