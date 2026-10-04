#ifndef POKEBW2_SAVE_MYSTERY_GIFT_H
#define POKEBW2_SAVE_MYSTERY_GIFT_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// A mystery gift card, 0xcc bytes
struct MysteryGift {
    // The item, Pass Power or other thing the gift gives. A Pokémon gift keeps the Pokémon's data from here
    u32 value;
    u8 unk04[0xac];
    u16 id;
    u8 unkB2;
    // What the gift gives, 1 for a Pokémon and 2 for an item
    u8 kind;
    u8 unkB4[0x18];
};

// Loads the mystery gift save into a new buffer, and frees it. Function name from swan
MysteryGiftSave *mysteryGiftBlock(SaveControl *save, u32 a1, HeapID heapId);
void func_0200aa54(MysteryGiftSave *save);
// Copies the card in the slot into gift
BOOL func_0200a71c(MysteryGiftSave *save, u32 slot, MysteryGift *gift);
BOOL func_0200a800(MysteryGiftSave *save, u32 slot);
BOOL func_0200a820(MysteryGiftSave *save, u32 slot);
void func_0200a858(MysteryGiftSave *save, u32 slot);

#endif // POKEBW2_SAVE_MYSTERY_GIFT_H
