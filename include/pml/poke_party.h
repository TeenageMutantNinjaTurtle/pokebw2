#ifndef POKEBW2_PML_POKE_PARTY_H
#define POKEBW2_PML_POKE_PARTY_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "nitro/rtc.h"
#include "pml/mail.h"
#include "struct_decls.h"

// A Pokémon's data, encrypted unless decrypted for a series of reads and writes. Names from swan
typedef struct {
    u8 rawData[32];
} PkmBufferChunk;

typedef struct {
    PkmBufferChunk chunks[4];
} PkmBuffer;

struct BoxPkm {
    u32 pid;
    u16 sanityFlags;
    u16 checksum;
    PkmBuffer contentBuffer;
};

struct PartyPkm {
    BoxPkm base;
    u32 statusCond;
    u8 level;
    u8 unk8D;
    u16 nowHP;
    u16 maxHP;
    u16 atk;
    u16 def;
    u16 spe;
    u16 spa;
    u16 spd;
    MailData mail;
    u32 unkD4;
    u32 unkD8;
};

PokeParty *PokeParty_Create(HeapID heapId);
u32 PokeParty_GetSaveDataSize(void);
u32 PML_GenPID(u32 seed, u16 species, u16 form, u32 sex, u32 ability, u32 a5);
void PokeParty_CreatePkm(PartyPkm *pkm, u16 species, u16 level, u32 a3, u32 a4, s32 a5, u32 pid, u32 a7);
void PokeParty_SetHiddenAbil(PartyPkm *pkm, u32 species, u32 form);
void FriendshipManagerCalc(PartyPkm *pkm, u32 reason, u16 zoneId, u16 heapId);
void func_02020c8c(PartyPkm *pkm, u32 value, u16 zoneId, HeapID heapId);
// Whether a move's PP is below its maximum, and restoring amount of it
BOOL PokeParty_CheckPPNeedsReplenish(PartyPkm *pkm, u32 slot);
BOOL PokeParty_AddPP(PartyPkm *pkm, u32 slot, u32 amount);
void func_02020cf0(PokeParty *party, u16 zoneId, HeapID heapId);
// Read and write a field of a Pokémon, PKM_PARAM_*. Fields that are not numbers go through the buffer
// A field of a Pokémon, PKM_PARAM_*. The functions take it as an enum, swan's PkmField, and MWCC doesn't share a sum
// that makes one between two calls, as it would an integer
typedef enum {
    PKM_PARAM_COUNT = 0xb4,
} PkmField;

u32 PokeParty_GetParam(PartyPkm *pkm, PkmField param, void *buffer);
// A field that is not a number takes a pointer to its value
void PokeParty_SetParam(PartyPkm *pkm, PkmField param, u32 value);
u32 GetStatusCond(PartyPkm *pkm);
void PokeParty_SetStatusCond(PartyPkm *pkm, u32 status);
u32 PokeParty_GetSex(PartyPkm *pkm);
BOOL PokeParty_CheckAnyRibbon(PartyPkm *pkm);
BOOL PokeParty_IsRare(PartyPkm *pkm);
// Decrypt a Pokémon for a series of reads and writes, and return whether it was encrypted, which is what the
// encryption afterwards takes
BOOL PokeParty_DecryptPkm(PartyPkm *pkm);
void PokeParty_EncryptPkm(PartyPkm *pkm, BOOL wasEncrypted);
u32 PML_PkmGetParam(BoxPkm *pkm, u32 param, void *buffer);
BOOL PML_PkmDecrypt(BoxPkm *pkm);
u32 PML_PkmGetLevel(BoxPkm *pkm);
void PML_PkmChangeForme(BoxPkm *pkm, u32 forme);
BOOL hasPokemonChangedForm(BoxPkm *pkm);
void PML_PkmReEncrypt(BoxPkm *pkm, BOOL wasEncrypted);
BOOL PML_PkmIsRare(BoxPkm *pkm);
BoxPkm *func_0201d620(PartyPkm *pkm);
// The size of a Pokémon's data
u32 PokeParty_GetPkmRawSize(void);
void copyPartyPkm(const PartyPkm *src, PartyPkm *dest);
// Resets the nickname to the species' name
void setNicknameToNick(PartyPkm *pkm);
u32 PML_UtilDerivePkmSex(u16 species, u16 form, u32 pid);
void copyPkmIntoPartyBlk(PokeParty *party, u32 index, const PartyPkm *pkm);
// Changes a Pokémon into another species, as evolution does
void setChangedPkmSpecies(PartyPkm *pkm, u32 species);
// Hatches an egg, recording where and by whom
void hatchEgg(PartyPkm *pkm, PlayerInfo *playerInfo, u16 placeName, HeapID heapId);
void PokeParty_Init(PokeParty *party);
void PokeParty_Copy(const PokeParty *src, PokeParty *dest);
void PokeParty_InitCore(PokeParty *party, u32 capacity);
// An item's place in a list of 46 battle items, 0 if it isn't in it
u32 func_02035944(u16 item);
// Records how and where the Pokémon was met, with the player as its Trainer
void PokeParty_SetupMetData(PartyPkm *pkm, u32 a1, PlayerInfo *playerInfo, u16 placeName, HeapID heapId);
u32 func_02035cf8(PartyPkm *pkm, u32 arg1, PlayerInfo *playerInfo);
void PokeParty_ClearPkm(PartyPkm *pkm);
// Restores a Pokémon's HP and PP and cures its status
void PokeParty_Recover(PartyPkm *pkm);
void PokeParty_RecalcStats(PartyPkm *pkm);
u32 PokeParty_GetLevel(PartyPkm *pkm);
// Whether a Pokémon can learn the TM or HM of the number PML_ItemGetTMBitMask gives
BOOL canPkmLearnTM_Wrapper(PartyPkm *pkm, u8 tm);
void setLevel(PartyPkm *pkm, u32 level);
void setPkmBattleData(PartyPkm *pkm, u32 param, u32 value);
// A species with its form and sex in one u16
u16 func_02021204(u32 species, u32 form, u32 sex);
// A Pokémon icon's character file in its archive, and its palette
u32 PokeParty_GetIconIndex(u32 species, u32 form, u32 sex, BOOL egg);
u32 func_02021034(u32 species, u32 form, u32 sex, BOOL egg);
// The level, 0 to 4, of a Pokémon's Pokéstar fame
int func_0201f010(u8 fame);
PartyPkm *PokeParty_GetPkm(PokeParty *party, u32 index);
BoxPkm *func_0201d624(PartyPkm *pkm);
int PokeParty_GetPkmCount(PokeParty *party);
u32 PokeParty_GetFirstBattleReady(PokeParty *party);
u32 isEggInParty(PokeParty *party);
int howManyPartyPokesAreNotEggs(PokeParty *party);
int howManyPokesAreAbleToFight(PokeParty *party);
int countAllEggsInParty(PokeParty *party);
int countSanityEggsInParty(PokeParty *party);
int PokeParty_GetCapacity(PokeParty *party);
BOOL PokeParty_AddPkm(PokeParty *party, PartyPkm *pkm);
void PokeParty_SwapPkms(PokeParty *party, u32 indexA, u32 indexB, HeapID heapId);
void PokeParty_RemovePkm(PokeParty *party, u32 index);
void PokeParty_RecoverAll(PokeParty *party);
void PokeParty_ChangeForme(PartyPkm *pkm, u32 forme);
// The form of Arceus for a plate, and of Genesect for a drive
u16 _getTypeForPlate(u16 item);
u32 func_0201ef8c(u16 item);
// Teaches a move, and returns 0xffff when all four slots are full
u16 PokeParty_LearnMove(PartyPkm *pkm, u16 move);
// Replaces the last move
void PokeParty_SetLastMove(PartyPkm *pkm, u16 move);
void PML_PkmChangeRotomForme(PartyPkm *pkm, u32 moveSlot, u32 forme);
void PokeParty_SetMove(PartyPkm *pkm, u32 move, u8 slot);
// Learn a move, and set a move in a slot, as the move tutors teach them
u16 func_0201d268(PartyPkm *pkm, u16 move);
void func_0201d2d0(PartyPkm *pkm, u32 move, u8 slot);
u16 *PokeParty_GetRememberableMoves(PartyPkm *pkm, HeapID heapId);
BOOL doesPkmHaveLevelMoveToLearn(const u16 *moves);
// The next move that a Pokémon learns at its level, going on from *index: 0 once there are none left, 0xfffe for one
// it already knows, and the move with 0x8000 set when it has no free slot for it
u16 func_0201d358(PartyPkm *pkm, u32 *index, HeapID heapId);
#define LEARN_MOVE_KNOWN 0xfffe
#define LEARN_MOVE_NO_SLOT 0x8000
// Allocates a Pokémon that is not in a party. What the 64-bit argument sets is not known yet; 0 is one of the values
// that PML_CreatePkm treats specially
PartyPkm *PokeParty_NewTempPkm(u16 species, u16 level, u64 a2, HeapID heapId);
PartyPkm *PokeParty_NewPkm(u16 species, u16 level, u32 trainerId, u32 a3, s32 a4, u64 pid, HeapID heapId);
void TransformVsPokePartyBySeason(GameData *gameData, PokeParty *party, u8 season);
BOOL func_ov012_021643f0(GameData *gameData, PokeParty *party, RTCTime *time, u8 season);
u32 func_ov012_02164428(GameData *gameData, PokeParty *party);

BOOL IsTrainerOT(PartyPkm *pkm, PlayerInfo *player);

#endif // POKEBW2_PML_POKE_PARTY_H
