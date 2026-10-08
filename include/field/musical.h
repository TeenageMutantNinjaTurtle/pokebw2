#ifndef POKEBW2_FIELD_MUSICAL_H
#define POKEBW2_FIELD_MUSICAL_H

// The Pokémon Musical: overlay 12's musical_event.c, which runs a show from the dressing room to the photo, the script
// commands of scrcmd_musical.c, and overlays 209, 210 and 211, which those load

#include "types.h"
#include "app/musical/mus_item_data.h"
#include "app/musical/musical_shot_sys.h"
#include "app/musical/musical_system.h"
#include "app/ov174.h"
#include "gfl/heap.h"
#include "gfl/proc.h"
#include "save/save_control.h"
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

// Overlay 12's musical_event.c
GameEvent *func_ov012_02150cf8(GameSystem *gsys, GameData *gameData, u8 slot, BOOL online, MusicalCommWork *comm);
// The position of the player's Pokémon on the stage
u8 func_ov012_02151b80(MusicalEventWork *work);
// The entry order of the Pokémon at a stage position
u8 func_ov012_02151b88(MusicalEventWork *work, u8 pos);
u8 func_ov012_02151ba8(MusicalEventWork *work);
// The program's title
StrBuf *func_ov012_02151bb4(MusicalEventWork *work, HeapID heapId);
// The points of the Pokémon at a stage position, at most 255
u8 func_ov012_02151bd4(MusicalEventWork *work, u8 pos);
u16 func_ov012_02151bf4(MusicalEventWork *work);
u16 func_ov012_02151c18(MusicalEventWork *work);
// The stage position that finished at a rank
u8 func_ov012_02151c3c(MusicalEventWork *work, u8 rank);
u8 func_ov012_02151c44(MusicalEventWork *work, u8 pos);
// The trainer class shown for the owner of the Pokémon at a stage position
u8 func_ov012_02151c8c(MusicalEventWork *work, u8 pos);
// Sets a word to the owner's name, or to the Pokémon's
void func_ov012_02151cd4(MusicalEventWork *work, u8 pos, WordSet *wordSet, u32 wordIndex);
void func_ov012_02151d6c(MusicalEventWork *work, u8 pos, WordSet *wordSet, u32 wordIndex);
void func_ov012_02151e44(MusicalEventWork *work);
// Whether the connection was lost
BOOL func_ov012_02151e64(MusicalEventWork *work);

// Overlay 211, the musical's communication
void *func_ov211_021ef1e0(HeapID heapId, GameSystem *gsys, GameCommSys *comm, u16 value);
void func_ov211_021ef220(void *comm);
void func_ov211_021ef3a0(void *comm);
void func_ov211_021ef3b8(void *comm);
void func_ov211_021ef3e4(void *comm, PlayerInfo *info, BoxPkm *pkm, GameCommSys *gameComm, Ov210Work *ov210,
                         HeapID heapId);
void func_ov211_021ef988(void *comm, u8 index);
BOOL func_ov211_021ef99c(void *comm, u8 index);
void func_ov211_021f00c8(void *comm);
PlayerInfo *func_ov211_021ef9c4(void *comm, u8 index);
BoxPkm *func_ov211_021ef9e0(void *comm, u8 index);
MusicalPoke *func_ov211_021f0094(void *comm, u8 index);
BOOL func_ov211_021f03d8(void *comm);
BOOL func_ov211_021f03e0(void *comm);
u8 func_ov211_021f0470(void *comm);
// The players' props on the stage: asks to use one, and whether it was sent; the prop each Pokémon uses (10 for
// none), which is then cleared; the position of the Pokémon in the limelight (4 or more for none), cleared with
// func_ov211_021f05b4; and the result of a prop's use
BOOL func_ov211_021f0460(void *comm, u8 equip);
void func_ov211_021f0510(void *comm, u8 pos, u8 equip);
u8 func_ov211_021f053c(void *comm, u8 pos);
void func_ov211_021f056c(void *comm, u8 pos);
u8 func_ov211_021f0598(void *comm);
void func_ov211_021f05b4(void *comm);
void func_ov211_021f05c0(void *comm, u8 pos, u8 equip, u32 result);
u8 func_ov211_021f0488(void *comm, u8 index);
u16 *func_ov211_021f0494(void *comm, u8 index);
BOOL func_ov211_021f04a0(void *comm);
BOOL func_ov211_021f04a4(void *comm);
BOOL func_ov211_021f04ac(void *comm);
void func_ov211_021f04b4(void *comm, u32 a1, u32 a2);
void func_ov211_021f04d4(void *comm);
void func_ov211_021f04e4(void *comm, MusicalPoke *poke);
u32 func_ov211_021f04f0(void *comm);
u32 func_ov211_021f04f8(void *comm);
u8 func_ov211_021f0500(void *comm, u8 index, u8 a2);
u32 func_ov211_021f0608(GameData *gameData);
// Its GameCommSys callbacks for GAME_COMM_NO_MUSICAL (see game_comm.c)
void *func_ov211_021ef230(u32 *seq, void *param);
BOOL func_ov211_021ef288(u32 *seq, void *param, void *work);
BOOL func_ov211_021ef378(u32 *seq, void *param, void *work);
void func_ov211_021ef394(u32 *seq, void *param, void *work);

#endif // POKEBW2_FIELD_MUSICAL_H
