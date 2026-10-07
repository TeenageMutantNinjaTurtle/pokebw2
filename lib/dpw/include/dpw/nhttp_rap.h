#ifndef POKEBW2_DPW_NHTTP_RAP_H
#define POKEBW2_DPW_NHTTP_RAP_H

#include "types.h"
#include "gfl/heap.h"

// nhttp_rap.c in overlay 189, which the ROM names: Game Freak's wrapper of HTTP requests to the game's servers, such as
// the check of a Pokémon before the Global Trade Station takes it. None of its functions has a name yet; what they do
// is read off the Global Trade Station's calls

typedef struct NHttpRap NHttpRap;

// Unova Link's requests to the Pokémon Dream Radar's server: a download and an upload of data, with their settings
BOOL func_ov189_0219d010(u32 a0, NHttpRap *rap);
BOOL func_ov189_0219d05c(u32 a0, u32 id, NHttpRap *rap);

NHttpRap *func_ov189_0219d1b8(HeapID heapId, s32 pid, void *buffer);
void func_ov189_0219d1f0(NHttpRap *rap);
// Sets up a request of the given type with room for size bytes, adds data to it, and sends it
void func_ov189_0219d258(NHttpRap *rap, HeapID heapId, u32 size, u32 type);
void func_ov189_0219d290(NHttpRap *rap, const void *data, u32 size);
BOOL func_ov189_0219d2b0(NHttpRap *rap);
// The request's error, 0 when it started
int func_ov189_0219d0f8(NHttpRap *rap);
// 0 once the request ended, 15 while it runs, or an error
int func_ov189_0219d140(NHttpRap *rap);
// The HTTP status and the body of the answer
int func_ov189_0219d3a8(NHttpRap *rap);
void *func_ov189_0219d1a4(NHttpRap *rap);
void func_ov189_0219d124(NHttpRap *rap);
void func_ov189_0219d384(NHttpRap *rap);
void func_ov189_0219d3bc(NHttpRap *rap, void *buffer, u32 size);
void func_ov189_0219d3cc(NHttpRap *rap);

// The answer to a Pokémon's check: its status, each Pokémon's result and its signature
u8 func_ov189_0219d3e4(const void *body);
u32 func_ov189_0219d3e8(const void *body, int index);
void *func_ov189_0219d408(void *body, int index);

#endif // POKEBW2_DPW_NHTTP_RAP_H
