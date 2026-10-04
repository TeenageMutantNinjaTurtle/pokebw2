#ifndef POKEBW2_SAVE_CHATTER_H
#define POKEBW2_SAVE_CHATTER_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

void *getChatterBlockAddress(SaveControl *save);
void *allocChatotChatterBlk(HeapID heapId);
void moveChatter(void *dest, const void *src);
BOOL doesChatotExist(void *chatter);
// Forgets the recorded cry once no Chatot is in the party
void checkChatotInParty(void *chatter, PokeParty *party);
u8 func_02007f90(void *chatter);
u32 func_02007e20(void);

#endif // POKEBW2_SAVE_CHATTER_H
