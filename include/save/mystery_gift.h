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

// The Pokémon of a Pokémon gift, which the card keeps from its start. 0xff, or 0, leaves a value to the game
typedef struct {
    u32 trainerId;
    u32 version;
    u32 personality;
    // A bit for each of the ribbons the Pokémon has
    u16 ribbons;
    u16 ball;
    u16 heldItem;
    u16 moves[4];
    u16 species;
    u8 form;
    u8 language;
    u16 nickname[11];
    u8 nature;
    u8 gender;
    // 0 or 1, the hidden ability (2), either at random (4), or 3
    u8 abilityType;
    // 0 for any, 1 shiny, 2 never shiny
    u8 shininess;
    u16 eggLocation;
    u16 metLocation;
    u8 metLevel;
    u8 contest[6];
    u8 ivs[6];
    u8 pad49;
    u16 otName[8];
    u8 otGender;
    u8 level;
    u8 isEgg;
    u8 unk5D[0x4f];
    // The date the gift was made, as year << 16 | month << 8 | day
    s32 date;
} MysteryGiftPokemon;

// Loads the mystery gift save into a new buffer, and frees it. Function name from swan
MysteryGiftSave *mysteryGiftBlock(SaveControl *save, u32 a1, HeapID heapId);
void func_0200aa54(MysteryGiftSave *save);
// Copies the card in the slot into gift
BOOL func_0200a71c(MysteryGiftSave *save, u32 slot, MysteryGift *gift);
BOOL func_0200a800(MysteryGiftSave *save, u32 slot);
BOOL func_0200a820(MysteryGiftSave *save, u32 slot);
void func_0200a858(MysteryGiftSave *save, u32 slot);

#endif // POKEBW2_SAVE_MYSTERY_GIFT_H
