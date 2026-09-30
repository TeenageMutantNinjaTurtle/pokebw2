#ifndef POKEBW2_APP_NAME_ENTRY_H
#define POKEBW2_APP_NAME_ENTRY_H

#include "types.h"
#include "gfl/proc.h"
#include "gfl/str.h"
#include "save/save_control_intr.h"

// The name entry, overlay 280

// What the name entry is for
#define NAME_ENTRY_RIVAL 3

typedef struct {
    u32 mode;
    u16 gender;
    u8 unk6[0x1a];
    // The name, which starts as a default
    StrBuf *name;
    // The save data that the new game creates in the background
    SaveControlIntr *saveTask;
} NameEntryParam;

// In ov012
NameEntryParam *setupNameEntry(u32 mode, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
// The name entry for a Pokémon's nickname
NameEntryParam *setupPokemonNameEntry(HeapID heapId, PartyPkm *pkm, u32 a2, u32 a3, TrainerGameInfoSave *gameInfo);
void func_ov012_02165ae8(NameEntryParam *param);
// Copies the entered name, and compares it with a string
void func_ov012_02165afc(NameEntryParam *param, StrBuf *dest);
BOOL func_ov012_02165b0c(NameEntryParam *param);
BOOL func_ov012_02165b10(NameEntryParam *param, const StrBuf *str);

extern const GameProcFunctions NAME_ENTRY_PROC_FUNCTIONS;
// The sound sequences that the name entry plays, which the new game loads before it
extern const u32 NAME_ENTRY_SOUND_COUNT;
extern const u32 NAME_ENTRY_SOUNDS[];

#endif // POKEBW2_APP_NAME_ENTRY_H
