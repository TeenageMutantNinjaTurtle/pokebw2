#ifndef POKEBW2_SAVE_CHATTER_H
#define POKEBW2_SAVE_CHATTER_H

#include "types.h"
#include "struct_decls.h"

void *getChatterBlockAddress(SaveControl *save);
BOOL doesChatotExist(void *chatter);

#endif // POKEBW2_SAVE_CHATTER_H
