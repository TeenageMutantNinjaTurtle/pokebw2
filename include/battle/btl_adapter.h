#ifndef POKEBW2_BATTLE_BTL_ADAPTER_H
#define POKEBW2_BATTLE_BTL_ADAPTER_H

// Overlay 167's btl_adapter.c, which passes the server's commands to a client and the client's replies back

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

BtlAdapter *func_ov167_021d4a44(void *netHandle, u8 clientId, BOOL flag, HeapID heapId);
void func_ov167_021d4abc(BtlAdapter *adapter);
void func_ov167_021d4acc(BtlAdapter *adapter);
void func_ov167_021d4ad4(void);
void func_ov167_021d4ae8(void);
void func_ov167_021d4aec(BtlAdapter *adapter, u32 cmd, const void *data, u32 size);
BOOL func_ov167_021d4b18(BtlAdapter *adapter);
// The client's reply to the last command, and its size if size isn't NULL
void *func_ov167_021d4b50(BtlAdapter *adapter, u32 *size);
void func_ov167_021d4b5c(BtlAdapter *adapter);

void func_ov167_021d4bc8(BtlAdapter *adapter);
u32 func_ov167_021d4bd4(BtlAdapter *adapter);
// The data the adapter received, and its size
u16 func_ov167_021d4c0c(BtlAdapter *adapter, const void **data);
BOOL func_ov167_021d4c38(BtlAdapter *adapter, const void *data, u32 size);

#endif // POKEBW2_BATTLE_BTL_ADAPTER_H
