#ifndef POKEBW2_FIELD_ITEM_USE_BLOCK_H
#define POKEBW2_FIELD_ITEM_USE_BLOCK_H

#include "types.h"
#include "struct_decls.h"

void EventFieldItemUseBlock_Call(GameEvent *parent, GameSystem *gsys, u32 action, u32 kind);
GameEvent *EventFieldItemUseBlock_Create(GameSystem *gsys, u32 arg1, u32 arg2);

#endif // POKEBW2_FIELD_ITEM_USE_BLOCK_H
