#ifndef POKEBW2_BATTLE_REGULATION_H
#define POKEBW2_BATTLE_REGULATION_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

struct Regulation {
    u8 unk0[2];
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA[0x52];
    u8 unk5C[0x4c];
    u8 unkA8[0x10];
    // Whether the partners' teams are shown in the selection, and its time limit
    u8 showPartners;
    u8 timeLimit;
    u8 unkBA;
    u8 unkBB;
};

// The rules of a battle, such as the level cap
Regulation *Regulation_Create(HeapID heapId);
// Reads a regulation from arc 106
void func_0201f744(u32 fileId, Regulation *regulation);
// Allocates a regulation read from arc 106
Regulation *func_0201f734(u32 fileId, HeapID heapId);
// Checks the Pokémon picked from a party, by their slots from 1, against the regulation
// Checks a Pokémon against the regulation, returning 0 if it may join
u32 func_0201f14c(Regulation *regulation, void *a1, PartyPkm *pkm);
u32 func_0201f1e8(Regulation *regulation, PokeParty *party, const u8 *picked);
u32 func_0201f268(Regulation *regulation, PokeParty *party);
u32 func_0201f424(Regulation *regulation, PokeParty *party, u32 *a2);
// Picks Pokémon of a party that the regulation allows, by their slots from 1, and returns how many it picked
u32 func_0201f97c(Regulation *regulation, PokeParty *party, u8 *picked);
// Values out of the parameter's range are ignored
void Regulation_SetParam(Regulation *regulation, u32 param, u32 value);

#endif // POKEBW2_BATTLE_REGULATION_H
