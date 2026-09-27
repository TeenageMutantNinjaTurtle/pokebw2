#ifndef POKEBW2_FIELD_EL_SCOREBOARD_H
#define POKEBW2_FIELD_EL_SCOREBOARD_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

ElScoreboard *ElScoreboard_Create(void *a0, u32 a1, u32 a2, u32 a3, u16 a4, u16 a5, HeapID heapId);
void ElScoreboard_Free(ElScoreboard *board);
void ElScoreboard_Update(ElScoreboard *board);

#endif // POKEBW2_FIELD_EL_SCOREBOARD_H
