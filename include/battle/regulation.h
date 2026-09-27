#ifndef POKEBW2_BATTLE_REGULATION_H
#define POKEBW2_BATTLE_REGULATION_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The rules of a battle, such as the level cap
Regulation *Regulation_Create(HeapID heapId);
// Values out of the parameter's range are ignored
void Regulation_SetParam(Regulation *regulation, u32 param, u32 value);

#endif // POKEBW2_BATTLE_REGULATION_H
