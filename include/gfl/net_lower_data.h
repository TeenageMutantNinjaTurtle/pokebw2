#ifndef POKEBW2_GFL_NET_LOWER_DATA_H
#define POKEBW2_GFL_NET_LOWER_DATA_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// Sending data larger than a packet in pieces, a little each frame, to buffers the receiving machines set up

void func_02043868(HeapID heapId, BOOL a1);
void func_020438dc(void);
// Starts sending, to the machines in dest, from the server's handle or this machine's
void func_0204393c(void *data, u32 size, int dest, BOOL fromServer);
// Sets up and frees the buffer for what a machine sends
void func_020439a4(u32 bufferSize, int netId, HeapID heapId, void *buffer);
void func_02043a1c(int netId);
void *func_02043a80(int netId);
u32 func_02043ac8(int netId);
// Whether all of the data has been sent, and whether all of a machine's has arrived
BOOL func_02043b10(void);
BOOL func_02043b24(int netId);
// Sends the next piece each frame
void func_02043b44(void);
// The command handlers for the data and for its header
void *func_02043c64(int netId, void *work, int size);
void func_02043ca0(int netId, int size, void *data, void *work, NetHandle *handle);
void func_02043d6c(int netId, int size, void *data, void *work, NetHandle *handle);

#endif // POKEBW2_GFL_NET_LOWER_DATA_H
