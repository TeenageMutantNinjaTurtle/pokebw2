#ifndef POKEBW2_SAVE_BOX_H
#define POKEBW2_SAVE_BOX_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

u32 howManyNormalPokesAreInAllBoxes(BoxSaveAccessor *boxes);
u32 howManyTotalPokesAreInBoxes(BoxSaveAccessor *boxes);
BOOL BoxSaveAccessor_InsertPkm(BoxSaveAccessor *boxes, BoxPkm *pkm);
u32 BoxSaveAccessor_GetPkmParam(BoxSaveAccessor *boxes, u32 box, u32 slot, u32 param, void *buffer);
BoxPkm *BoxSaveAccessor_GetPkm(BoxSaveAccessor *boxes, u32 box, u32 slot);
u32 BoxSaveAccessor_GetLastOpenedBox(BoxSaveAccessor *boxes);
// How many boxes are open: 8, 16 or 24
u8 BoxSaveAccessor_GetAvailableBoxCount(BoxSaveAccessor *boxes);
// Opens 8 more boxes, up to 24, and returns how many are open
u8 BoxSaveAccessor_UnlockMoreBoxes(BoxSaveAccessor *boxes);
void saveLastOpenedBoxIdx(BoxSaveAccessor *boxes, u32 box);
u32 howManyPokesInGeneralAreInBox(BoxSaveAccessor *boxes, u32 box);

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
