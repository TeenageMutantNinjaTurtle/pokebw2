#ifndef POKEBW2_FIELD_MEDAL_H
#define POKEBW2_FIELD_MEDAL_H

#include "gfl/heap.h"
#include "struct_decls.h"

void DiscoverInitialMedalsCore(MedalBox *box, HeapID heapId);
void DiscoverInitialMedals(MedalBox *box, HeapID heapId);
FieldActor *GetMrMedalActorIndex(Field *field);
u32 GetMrMedalActorUID(GameData *gameData);

#endif // POKEBW2_FIELD_MEDAL_H
