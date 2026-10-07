#ifndef POKEBW2_FIELD_MUSICAL_H
#define POKEBW2_FIELD_MUSICAL_H

// The Pokémon Musical: overlay 12's musical_event.c, which runs a show from the dressing room to the photo, the script
// commands of scrcmd_musical.c, and overlays 209, 210 and 211, which those load

#include "types.h"
#include "app/musical/musical_shot_sys.h"
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

// Overlay 210, the musical's data
struct Ov210Work {
    u32 unk0;
    void *unk4;
    // The archive of the program's messages
    void *msgArc;
};

// A prop a Pokémon wears on the stage
typedef struct {
    u16 itemId;
    s16 unk2;
    // The slot it is worn on
    u8 slot;
} MusicalPokeEquip;

// A Pokémon on the stage
struct MusicalPoke {
    // Who frees it: 0 the event, 1 the communication, 2 the stage
    u32 owner;
    // The party Pokémon it was made from, or NULL
    PartyPkm *pkm;
    u16 species;
    u8 sex;
    u8 form;
    u8 rare;
    u32 personality;
    MusicalPokeEquip equips[9];
    u16 points;
    u16 unk4C[4];
    BOOL unk54[9];
    u16 unk78;
};

BOOL func_ov210_021eec80(PartyPkm *pkm);
MusicalPoke *func_ov210_021eecac(PartyPkm *pkm, HeapID heapId);
MusicalPoke *func_ov210_021eed30(u16 species, u8 sex, u8 form, u8 rare, u32 personality, HeapID heapId);
Ov210Work *func_ov210_021eedac(HeapID heapId);
void func_ov210_021eedd8(Ov210Work *work);
void func_ov210_021eee0c(Ov210Work *work, SaveControl *save, GameData *gameData, u8 a3, HeapID heapId);
void *func_ov210_021eef38(HeapID heapId);
void func_ov210_021eef64(void *items);
u32 func_ov210_021ef164(void *items, u16 itemId);
// A prop's entry in the table func_ov210_021eef38 loads, 12 bytes
typedef struct MusicalItemData MusicalItemData;
MusicalItemData *func_ov210_021eef78(void *items, u16 itemId);
// The prop's offset from where it is worn, x then y
void func_ov210_021eef84(MusicalItemData *item, s32 *offset);
// The BlAct size of its texture
u32 func_ov210_021eef94(MusicalItemData *item);
// Whether the prop can be worn at a position, by its flags
BOOL func_ov210_021eef98(MusicalItemData *item, u8 pos);
BOOL func_ov210_021ef018(MusicalItemData *item, u8 pos);
// Whether the prop's category is that of a position
BOOL func_ov210_021ef088(MusicalItemData *item, u8 pos);
// Its flags 0x80 and 0x200
BOOL func_ov210_021ef0f4(MusicalItemData *item);
BOOL func_ov210_021ef104(MusicalItemData *item);

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

// Overlay 20
GameEvent *func_ov020_0216e714(GameSystem *gsys, void *args);

#endif // POKEBW2_FIELD_MUSICAL_H
