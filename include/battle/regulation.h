#ifndef POKEBW2_BATTLE_REGULATION_H
#define POKEBW2_BATTLE_REGULATION_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

struct Regulation {
    u8 unk0[2];
    u8 unk2;
    u8 unk3;
    u8 unk4[0xb8];
};

// The rules of a battle, such as the level cap
Regulation *Regulation_Create(HeapID heapId);
// Reads a regulation from arc 106
void func_0201f744(u32 fileId, Regulation *regulation);
// Allocates a regulation read from arc 106
Regulation *func_0201f734(u32 fileId, HeapID heapId);
u32 func_0201f268(Regulation *regulation, PokeParty *party);
// Values out of the parameter's range are ignored
void Regulation_SetParam(Regulation *regulation, u32 param, u32 value);

#endif // POKEBW2_BATTLE_REGULATION_H
