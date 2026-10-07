#ifndef POKEBW2_APP_BOX_SEARCH_GRAPHIC_H
#define POKEBW2_APP_BOX_SEARCH_GRAPHIC_H

#include "types.h"
#include "gfl/clact.h"
#include "gfl/heap.h"

// box_search_graphic.c: the BGs and cell actors of the PC box's Pokémon search

typedef struct BoxSearchGraphic BoxSearchGraphic;

BoxSearchGraphic *func_ov255_021d6d28(u32 layout, HeapID heapId);
void func_ov255_021d6dc8(BoxSearchGraphic *graphic);
// Called every frame
void func_ov255_021d6e1c(BoxSearchGraphic *graphic);
// Begin and end the frame's 3D, which the search doesn't draw
void func_ov255_021d6e30(BoxSearchGraphic *graphic);
void func_ov255_021d6e34(BoxSearchGraphic *graphic);
ClActUnit *func_ov255_021d6e38(BoxSearchGraphic *graphic);

#endif // POKEBW2_APP_BOX_SEARCH_GRAPHIC_H
