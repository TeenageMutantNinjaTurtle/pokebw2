#ifndef POKEBW2_GFL_NHTTP_RAP_H
#define POKEBW2_GFL_NHTTP_RAP_H

#include "types.h"
#include "gfl/heap.h"

// The HTTP connections of the network library (nhttp_rap.c, in overlay 189)

typedef struct NhttpRapWork NhttpRapWork;

void func_ov189_0219d0f8(NhttpRapWork *work);
void func_ov189_0219d124(NhttpRapWork *work);
// The state of the request, 15 while it runs
int func_ov189_0219d140(NhttpRapWork *work);
// The body of the response
void *func_ov189_0219d1a4(NhttpRapWork *work);
NhttpRapWork *func_ov189_0219d1b8(HeapID heapId, u32 profileId, void *buffer);
void func_ov189_0219d1f0(NhttpRapWork *work);
void func_ov189_0219d258(NhttpRapWork *work, HeapID heapId, u32 size, u32 a3);
// Adds data to the request
void func_ov189_0219d290(NhttpRapWork *work, const void *data, u32 size);
void func_ov189_0219d2b0(NhttpRapWork *work);
void func_ov189_0219d384(NhttpRapWork *work);
// The HTTP status of the response
int func_ov189_0219d3a8(NhttpRapWork *work);
// What the response says about the Pokémon sent, all of them and each
u8 func_ov189_0219d3e4(void *response);
BOOL func_ov189_0219d3e8(void *response, u8 index);

#endif // POKEBW2_GFL_NHTTP_RAP_H
