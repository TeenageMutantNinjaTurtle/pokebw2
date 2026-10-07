#ifndef POKEBW2_SAVE_CHATTER_H
#define POKEBW2_SAVE_CHATTER_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

void *getChatterBlockAddress(SaveControl *save);
void *allocChatotChatterBlk(HeapID heapId);
void moveChatter(void *dest, const void *src);
BOOL doesChatotExist(void *chatter);
u8 func_02007f90(void *chatter);
u32 func_02007e20(void);
// Clears the recorded cry when no Chatot is left in the party
void checkChatotInParty(void *chatter, PokeParty *party);

#endif // POKEBW2_SAVE_CHATTER_H
