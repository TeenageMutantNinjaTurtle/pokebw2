#ifndef POKEBW2_APP_NAME_ENTRY_H
#define POKEBW2_APP_NAME_ENTRY_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/proc.h"
#include "gfl/str.h"
#include "save/save_control_intr.h"
#include "struct_decls.h"

// The name entry, overlay 280

// What the name entry is for
#define NAME_ENTRY_POKEMON 1
#define NAME_ENTRY_RIVAL 3

typedef struct {
    u32 mode;
    // The gender, or the Pokémon's species
    u16 gender;
    // The Pokémon's form, and its sex in the high byte
    u16 unk6;
    PartyPkm *pkm;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 maxLength;
    // 1 when the name is to be left as it was
    u32 unk1C;
    // The name, which starts as a default
    StrBuf *name;
    // The save data that the new game creates in the background
    SaveControlIntr *saveTask;
    TrainerGameInfoSave *gameInfo;
    u32 unk2C;
    void *unk30;
    u32 unk34;
} NameEntryParam;

// Overlay 12's namein_setup.c
// The name starts as a copy of name, if given
NameEntryParam *setupNameEntry(HeapID heapId, u32 mode, u32 a2, u32 a3, u32 maxLength, const StrBuf *name,
                               TrainerGameInfoSave *gameInfo);
// The name entry for a Pokémon's nickname
NameEntryParam *setupPokemonNameEntry(HeapID heapId, PartyPkm *pkm, u32 maxLength, const StrBuf *name,
                                      TrainerGameInfoSave *gameInfo);
NameEntryParam *pokemonNameEntry(HeapID heapId, PartyPkm *pkm, u32 maxLength, const StrBuf *name, u32 unkC, u32 unk10,
                                 u32 unk14, TrainerGameInfoSave *gameInfo);
void func_ov012_02165ae8(NameEntryParam *param);
// Copies the entered name, and compares it with a string
void func_ov012_02165afc(NameEntryParam *param, StrBuf *dest);
BOOL func_ov012_02165b0c(NameEntryParam *param);
BOOL func_ov012_02165b10(NameEntryParam *param, const StrBuf *str);
// Overlay 12
void func_ov012_021603ec(StrBuf *name, u8 value);

extern const GameProcFunctions NAME_ENTRY_PROC_FUNCTIONS;
// The sound sequences that the name entry plays, which the new game loads before it
extern const u32 NAME_ENTRY_SOUND_COUNT;
extern const u32 NAME_ENTRY_SOUNDS[];

#endif // POKEBW2_APP_NAME_ENTRY_H
