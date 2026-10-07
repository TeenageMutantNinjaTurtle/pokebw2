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
void PokeParty_CreateTempPkm(PartyPkm *pkm, u16 species, u16 level, u64 id);
u32 PokeParty_GetSaveDataSize(void);
u32 PML_GenPID(u32 seed, u16 species, u16 form, u32 sex, u32 ability, u32 a5);
// Whether the personality is shiny for the trainer ID
BOOL PML_UtilPIDIsRare(u32 id, u32 pid);
u32 makeSpecialPID(u32 id, u16 species, u16 form, u8 sex, u8 a4, BOOL a5);
// Whether the gender ratio leaves no choice of sex
BOOL isGenderlessOrSetGender(u8 genderRatio);
// The trainer ID and the PID are 64-bit so that they can hold these values beside any 32-bit one. The trainer ID is
// random, or one with which the PID isn't shiny; the PID is random, or the trainer ID's value. ivs packs six 5-bit
// IVs, or is PKM_IVS_RANDOM
#define PKM_ID_RANDOM 0xffffffffffffffffULL
#define PKM_ID_NOT_SHINY 0xffffffff00000000ULL
#define PKM_PID_RANDOM 0xffffffff00000000ULL
#define PKM_PID_FROM_ID 0xffffffff00000001ULL
#define PKM_IVS_RANDOM -1
void PokeParty_CreatePkm(PartyPkm *pkm, u16 species, u16 level, u64 trainerId, s32 ivs, u64 pid);
void PokeParty_SetHiddenAbil(PartyPkm *pkm, u32 species, u32 form);
void PokeParty_SetDefaultMoves(PartyPkm *pkm);
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
u32 PokeParty_GetNature(PartyPkm *pkm);
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
// Whether the Pokémon's original trainer is someone other than the player
BOOL PML_UtilCheckForeignOT(BoxPkm *pkm, PlayerInfo *playerInfo);
void PML_PkmChangeForme(BoxPkm *pkm, u32 forme);
BOOL hasPokemonChangedForm(BoxPkm *pkm);
void PML_PkmReEncrypt(BoxPkm *pkm, BOOL wasEncrypted);
BOOL PML_PkmIsRare(BoxPkm *pkm);
// Whether the species and form are a fused Kyurem
BOOL isKyuremTransformed(u16 species, u8 form);
u32 PML_PkmGetNature(BoxPkm *pkm);
u8 PML_PkmGetSex(BoxPkm *pkm);
// Whether the Pokémon has Pokérus that hasn't run its course
BOOL doesPokerusHaveDuration(BoxPkm *pkm);
// Whether the Pokémon has had Pokérus
BOOL doesPokeHavePokerus(BoxPkm *pkm);
// The same two for a Pokémon of the party
BOOL pokerusDuration(PartyPkm *pkm);
BOOL pokeHasPkrs(PartyPkm *pkm);
BoxPkm *func_0201d620(PartyPkm *pkm);
// Puts a move in a slot with its full PP and no PP Ups
void PML_PkmSetMove(BoxPkm *pkm, u16 move, u32 slot);
// How a nature changes a stat, attack to special defense from 1: 1 raised, -1 lowered, 0 neither
s8 statAffectedByNature(u8 nature, u32 stat);
// Allocates a party Pokémon made from a boxed one
void PML_PkmSetParam(BoxPkm *pkm, u32 param, u32 value);
// The size of a Pokémon's data
u32 PokeParty_GetPkmRawSize(void);
// The size of a boxed Pokémon's data
u32 PML_GetPkmRawSize(void);
void PML_PkmInit(BoxPkm *pkm);
void PML_CreateTempPkm(BoxPkm *pkm, u16 species, u16 level, u64 id);
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
void PokeParty_ClearPkm(PartyPkm *pkm);
// Restores a Pokémon's HP and PP and cures its status
void PokeParty_Recover(PartyPkm *pkm);
void PokeParty_RecalcStats(PartyPkm *pkm);
u32 PokeParty_GetLevel(PartyPkm *pkm);
// Whether a Pokémon can learn the TM or HM of the number PML_ItemGetTMBitMask gives
BOOL canPkmLearnTM_Wrapper(PartyPkm *pkm, u8 tm);
void setLevel(PartyPkm *pkm, u32 level);
u32 PokeParty_GetLevel(PartyPkm *pkm);
// Counts down the Pokérus of the party's Pokémon by days
void pokerusDecay(PokeParty *party, s32 days);
void PokeParty_SetNature(PartyPkm *pkm, u32 nature);
void setPkmBattleData(PartyPkm *pkm, u32 param, u32 value);
// A Pokémon's icon in ARCID_POKEICON: its characters' file and its palette
u32 func_02020f40(BoxPkm *pkm);
u32 func_020210c0(BoxPkm *pkm);
// The files of the icons' palette, cells and animations in ARCID_POKEICON
u32 func_02021118(void);
u32 func_0202111c(void);
u32 getOBJTileMapping_MainEng(void);
// A species with its form and sex in one u16
// The palette of a Pokémon's icon
u32 func_020210c0(BoxPkm *pkm);
// The icons' palette and cell files, for the OBJ mapping in use
u32 func_02021114(void);
u32 func_02021154(void);
u32 getOBJTileMapping_MainEng(void);
u16 func_02021204(u32 species, u32 form, u32 sex);
// A Pokémon icon's character file in its archive, and its palette
u32 PokeParty_GetIconIndex(u32 species, u32 form, u32 sex, BOOL egg);
u32 func_02021034(u32 species, u32 form, u32 sex, BOOL egg);
// The level, 0 to 4, of a Pokémon's Pokéstar fame
int func_0201f010(u8 fame);
PartyPkm *PokeParty_GetPkm(PokeParty *party, u32 index);
// A flag of each slot, kept in the party
BOOL PokeParty_GetSlotExists(PokeParty *party, u32 slot);
void PokeParty_SetSlotExists(PokeParty *party, u32 slot, BOOL exists);
BoxPkm *func_0201d624(PartyPkm *pkm);
// A new party Pokémon made from a box Pokémon, with its stats calculated
PartyPkm *boxPkmRegenToPartyPkm(BoxPkm *pkm, HeapID heapId);
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
void PokeParty_SwapPkms(PokeParty *party, u32 index1, u32 index2, HeapID heapId);
// Reorders the party: order[i] is the index of the Pokémon that goes to position i
void func_0201fff8(PokeParty *party, u32 *order, HeapID heapId);
void PokeParty_RecoverAll(PokeParty *party);
// A Pokémon's icon in archive 7: its file, and the palette of the file func_02021114 returns that it uses. The cells
// and animations depend on the sub engine's OBJ VRAM mapping: func_02021154 and getOBJTileMapping_SubEng return them
u32 PokeParty_GetIconIndex(u32 species, u32 form, u32 sex, BOOL egg);
u32 func_02021034(u32 species, u32 form, u32 sex, BOOL egg);
u32 func_02021114(void);
u32 func_02021154(void);
u32 getOBJTileMapping_SubEng(void);
void PokeParty_ChangeForme(PartyPkm *pkm, u16 forme);
// The form of Arceus for a plate, and of Genesect for a drive
u16 _getTypeForPlate(u16 item);
u32 func_0201ef8c(u16 item);
// The form, or 0 when the species has no such form
u32 PML_PkmSanitizeForme(u16 species, u16 form);
// The form a sprite shows: 0 for the four species whose forms share one sprite
u32 func_0201efe4(u16 species, u8 form);
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
// Allocates a Pokémon that is not in a party, with random IVs and PID, through PokeParty_CreateTempPkm. trainerId
// is a 32-bit ID or one of the PKM_ID_ values
PartyPkm *PokeParty_NewTempPkm(u16 species, u16 level, u64 trainerId, HeapID heapId);
PartyPkm *boxPkmRegenToPartyPkm(BoxPkm *pkm, HeapID heapId);
// Whether the species is a legendary Pokémon of the national Pokédex
BOOL PML_PkmIsLegendNational(u16 species);
// Sets the nickname to the species name
void setNicknameToNick(PartyPkm *pkm);
// Whether the Pokémon is in a form that it changed into, which it would lose in a box
BOOL hasPokemonChangedForm(BoxPkm *pkm);
// The number of Pokémon in the party that can battle: not fainted and not eggs
int countActivePkms(PokeParty *party);
PartyPkm *PokeParty_NewPkm(u16 species, u16 level, u32 trainerId, u32 a3, s32 a4, u64 pid, HeapID heapId);
void TransformVsPokePartyBySeason(GameData *gameData, PokeParty *party, u8 season);

BOOL IsTrainerOT(PartyPkm *pkm, PlayerInfo *player);
// Whether a Pokémon's nature raises (1) or lowers (-1) a stat
s8 doesNatureAffectStat(PartyPkm *pkm, u32 stat);

u8 getHiddenPowerType(PartyPkm *pkm);
u32 getHiddenPowerBasePwr(PartyPkm *pkm);

#endif // POKEBW2_PML_POKE_PARTY_H
