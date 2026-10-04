#ifndef POKEBW2_SAVE_BOX_H
#define POKEBW2_SAVE_BOX_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

u32 BoxSaveAccessor_GetAvailableBoxCount(BoxSaveAccessor *boxes);
void BoxSaveAccessor_SetPkm(BoxSaveAccessor *boxes, u32 box, u32 slot, BoxPkm *pkm);
// The size of a box, and a box
u32 getSizeofPokeBox(void);
u32 getSizeofBox(void);
void *BoxSaveAccessor_GetBox(BoxSaveAccessor *boxes, u32 box);
u32 howManyNormalPokesAreInAllBoxes(BoxSaveAccessor *boxes);
u32 howManyTotalPokesAreInBoxes(BoxSaveAccessor *boxes);
BOOL BoxSaveAccessor_InsertPkm(BoxSaveAccessor *boxes, BoxPkm *pkm);
u32 BoxSaveAccessor_GetPkmParam(BoxSaveAccessor *boxes, u32 box, u32 slot, u32 param, void *buffer);
BoxPkm *BoxSaveAccessor_GetPkm(BoxSaveAccessor *boxes, u32 box, u32 slot);

// The battle box, save block 0x31
BattleBoxSave *getBattleBox(SaveControl *save);
// Allocates a party of the battle box's Pokémon
PokeParty *convertBoxedPokeSetToParty(BattleBoxSave *battleBox, HeapID heapId);
BoxPkm *getBoxSlotAddress(BattleBoxSave *battleBox, u32 a1, u32 slot);
BOOL func_0200c340(BattleBoxSave *battleBox);

// The day care, save block 0x32
DayCareSave *getDaycareBlockAddress(SaveControl *save);
u32 DayCareSave_GetPkmStatus(DayCareSave *dayCare, u32 slot);
PartyPkm *DayCareSave_GetPkm(DayCareSave *dayCare, u32 slot);

// Sets flags of the box save
void func_02007d8c(BoxSaveAccessor *accessor, u32 flags);

#endif // POKEBW2_SAVE_BOX_H
