#ifndef POKEBW2_FIELD_MUSICAL_H
#define POKEBW2_FIELD_MUSICAL_H

// The Pokémon Musical: overlay 12's musical event code, which has no source file yet (musical_event.c and its
// neighbours, from 0x02150cec), the script commands of scrcmd_musical.c, and overlays 210 and 211, which those load

#include "types.h"
#include "app/ov174.h"
#include "gfl/heap.h"
#include "gfl/proc.h"
#include "struct_decls.h"
#include "system/game_event.h"

// The musical's communication work, which func_020179d4 keeps in the game data
struct MusicalCommWork {
    MusicalEventWork *event;
    // Overlay 211's communication work
    void *comm;
    // Overlay 36's menu
    void *menu;
    Ov174Param ov174;
    u16 *result;
    u16 value;
};

MusicalCommWork *func_020179dc(GameData *gameData);
void func_020179d4(GameData *gameData, MusicalCommWork *work);

// Overlay 12's musical event code
GameEvent *func_ov012_02150cf8(GameSystem *gsys, GameData *gameData, u8 kind, BOOL online, MusicalCommWork *work);
u8 func_ov012_02151b80(MusicalEventWork *event);
u8 func_ov012_02151b88(MusicalEventWork *event, u8 index);
u32 func_ov012_02151ba8(MusicalEventWork *event);
StrBuf *func_ov012_02151bb4(MusicalEventWork *event, HeapID heapId);
u32 func_ov012_02151bd4(MusicalEventWork *event, u8 index);
u32 func_ov012_02151bf4(MusicalEventWork *event);
u32 func_ov012_02151c18(MusicalEventWork *event);
u8 func_ov012_02151c3c(MusicalEventWork *event, u8 index);
u32 func_ov012_02151c44(MusicalEventWork *event, u8 index);
u32 func_ov012_02151c8c(MusicalEventWork *event, u8 index);
void func_ov012_02151cd4(MusicalEventWork *event, u8 index, WordSet *wordSet, u32 wordIndex);
void func_ov012_02151d6c(MusicalEventWork *event, u8 index, WordSet *wordSet, u32 wordIndex);
void func_ov012_02151e44(MusicalEventWork *event);
// Whether the connection was lost
BOOL func_ov012_02151e64(MusicalEventWork *event);
extern const GameProcFunctions data_ov012_0216dfc4;

// Overlay 210
BOOL func_ov210_021eec80(PartyPkm *pkm);
void *func_ov210_021eecac(PartyPkm *pkm, HeapID heapId);

// Overlay 211
void *func_ov211_021ef1e0(HeapID heapId, GameSystem *gsys, GameCommSys *comm, u16 value);
void func_ov211_021ef220(void *comm);
void func_ov211_021ef3a0(void *comm);
void func_ov211_021ef3b8(void *comm);
void func_ov211_021ef988(void *comm, u8 index);
BOOL func_ov211_021ef99c(void *comm, u8 index);
PlayerInfo *func_ov211_021ef9c4(void *comm, u8 index);
BOOL func_ov211_021f03e0(void *comm);
BOOL func_ov211_021f04ac(void *comm);
u32 func_ov211_021f0608(GameData *gameData);

// Overlay 209's screen
extern const GameProcFunctions data_ov209_021c3000;
// Overlay 20
GameEvent *func_ov020_0216e714(GameSystem *gsys, void *args);

#endif // POKEBW2_FIELD_MUSICAL_H
