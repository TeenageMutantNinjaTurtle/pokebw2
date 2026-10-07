// The battle facilities' tools: their trainers, Pokémon and battles, for the Battle Subway and the Trial House.
// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)
//
// Not written yet: SetupTrialHouseBattle, func_ov012_02162068, BtlSetup_SetTrainerRental,
// BtlSetup_SetTrainerTrialHouse and func_ov012_02162394 need battle setup functions and a BtlSetupTrainer layout that
// battle/btl_setup.h does not have yet
#include "types.h"
#include "battle/btl_setup.h"
#include "constants/pokemon.h"
#include "field/battle_facility.h"
#include "field/bsubway_scr.h"
#include "gfl/arc.h"
#include "gfl/arc_util.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/random.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "nitro/math.h"
#include "pml/personal.h"
#include "pml/poke_party.h"

#define MOVE_FRUSTRATION 218

static void BtlSetup_SetTrialHouseParty(BtlSetup *setup, BSubwayTrainer *trainer, int client, u32 mode, int count,
                                        HeapID heapId);
static void func_ov012_02162394(u32 mode, u32 trainerId, BSubwayTrainer *trainer, BtlSetupTrainer *dest, u32 aiFlags,
                                BOOL clearWords, BOOL copyWords);
static void RestrictPlayerParty(PokeParty *src, PokeParty *dest, int count, u16 level, HeapID heapId);
static void LoadTrialHouseParty(BSubwayTrainer *trainer, PokeParty *party, u16 level, int count, HeapID heapId);
static void genSubwayBtlInstitutePoke(const BSubwayPokemon *src, PartyPkm *pkm, u16 level);
static void func_ov012_021627b0(u32 arcId, BSubwayPokemonData *data, u32 file);
static u16 func_ov012_021627d4(MATHRandContext32 *rand);
static u8 func_ov012_02162828(u32 trainerId);
static BOOL func_ov012_02162ae8(BSubwayTrainer *trainer);

// The items of the rental Pokémon
static const u16 data_ov012_0216d9ac[4] = {213, 157, 234, 217};

// What each trainer class gives
static const struct {
    u16 trainerClass;
    u16 value;
} data_ov012_0216d9b4[] = {
    {0x02, 0x0b}, {0x03, 0x0f}, {0x04, 0x0c}, {0x05, 0x10}, {0x29, 0x0d}, {0x2a, 0x11}, {0x0f, 0x99}, {0x0e, 0x9a},
    {0x1b, 0x30}, {0x1c, 0x31}, {0x08, 0x2a}, {0x09, 0x2b}, {0x3b, 0x18}, {0x3c, 0x1a}, {0x3d, 0x32}, {0x3e, 0x33},
    {0x5a, 0x26}, {0x5b, 0x27}, {0x4c, 0x2c}, {0x4b, 0x2d}, {0x11, 0x22}, {0x12, 0x23}, {0x34, 0x49}, {0x2e, 0x4a},
    {0x23, 0xb7}, {0x24, 0xb8}, {0x33, 0x2e}, {0x40, 0x2f}, {0x18, 0x24}, {0x19, 0x25}, {0x32, 0x1e}, {0x31, 0x1f},
    {0x46, 0x20}, {0x47, 0x21}, {0x1d, 0x3f}, {0x4a, 0x40}, {0x2c, 0x43}, {0x1a, 0x9b}, {0x20, 0x36}, {0x21, 0x1c},
    {0x56, 0x48}, {0x39, 0x3d}, {0x48, 0x3e}, {0x3a, 0x45}, {0x53, 0x44}, {0x2b, 0x47}, {0x42, 0x34}, {0x43, 0x34},
    {0x41, 0x54}, {0x22, 0x42}, {0x0d, 0x17}, {0x57, 0x41}, {0x30, 0x35},
};

static void BtlSetup_SetTrialHouseParty(BtlSetup *setup, BSubwayTrainer *trainer, int client, u32 mode, int count,
                                        HeapID heapId) {
    BtlSetupTrainer *dest = setup->trainers[client];
    BOOL clearWords, copyWords;

    switch (client) {
    case 1:
        clearWords = TRUE;
        copyWords = TRUE;
        break;
    case 3:
        clearWords = FALSE;
        copyWords = FALSE;
        break;
    case 2:
        clearWords = TRUE;
        copyWords = FALSE;
        break;
    }
    func_ov012_02162394(mode, trainer->unk00, trainer, dest, 0x87, clearWords, copyWords);
    LoadTrialHouseParty(trainer, setup->party[client], 50, count, heapId);
}

void func_ov012_021621d4(PokeParty *party, const BSubwayPokemon *pkms, u16 level, int count, HeapID heapId) {
    int i;
    PartyPkm *pkm;

    PokeParty_InitCore(party, 6);
    pkm = GFL_HeapAllocate(HEAPID_TAIL(heapId), PokeParty_GetPkmRawSize(), FALSE, "fld_btl_inst_tool.c", 796);
    for (i = 0; i < count; i++) {
        genSubwayBtlInstitutePoke(&pkms[i], pkm, level);
        PokeParty_AddPkm(party, pkm);
    }
    GFL_HeapFree(pkm);
}

static void RestrictPlayerParty(PokeParty *src, PokeParty *dest, int count, u16 level, HeapID heapId) {
    PartyPkm *pkm;
    PartyPkm *srcPkm;
    int i;

    PokeParty_InitCore(dest, 6);
    pkm = GFL_HeapAllocate(HEAPID_TAIL(heapId), PokeParty_GetPkmRawSize(), FALSE, "fld_btl_inst_tool.c", 921);
    PokeParty_ClearPkm(pkm);
    for (i = 0; i < count; i++) {
        srcPkm = PokeParty_GetPkm(src, i);
        copyPartyPkm(srcPkm, pkm);
        if (level != 0 && level != PokeParty_GetParam(srcPkm, PKM_PARAM_LEVEL, NULL)) {
            setLevel(pkm, level);
        }
        PokeParty_AddPkm(dest, pkm);
    }
    GFL_HeapFree(pkm);
}

static void LoadTrialHouseParty(BSubwayTrainer *trainer, PokeParty *party, u16 level, int count, HeapID heapId) {
    int i;
    PartyPkm *pkm;

    PokeParty_InitCore(party, 6);
    pkm = GFL_HeapAllocate(HEAPID_TAIL(heapId), PokeParty_GetPkmRawSize(), FALSE, "fld_btl_inst_tool.c", 1020);
    for (i = 0; i < count; i++) {
        genSubwayBtlInstitutePoke(&trainer->pokemon[i], pkm, level);
        PokeParty_AddPkm(party, pkm);
    }
    GFL_HeapFree(pkm);
}

u32 func_ov012_02162490(BSubwayPokemon *pkm, u32 arcId, u16 file, u32 id, u32 pid, u8 iv, u8 index, BOOL rentalItem,
                        HeapID heapId) {
    BSubwayPokemonData data;
    u32 personality;
    int i;
    int count;
    int ev;
    u8 happiness;
    u32 ability;
    MsgData *msgData;

    sys_memset(pkm, 0, sizeof(BSubwayPokemon));
    func_ov012_021627b0(arcId, &data, file);
    pkm->species = data.species;
    pkm->form = data.form;
    if (rentalItem) {
        pkm->item = data_ov012_0216d9ac[index];
    } else {
        pkm->item = data.item;
    }
    happiness = 0xff;
    for (i = 0; i < 4; i++) {
        pkm->moves[i] = data.moves[i];
        if (data.moves[i] == MOVE_FRUSTRATION) {
            happiness = 0;
        }
    }
    pkm->id = id;
    personality = pid;
    if (personality == 0) {
        personality = PML_GenPID(id, data.species, data.form, 2, 2, 0);
    }
    pkm->personality = personality;
    pkm->nature = data.nature;
    pkm->ivs.stat.hp = iv;
    pkm->ivs.stat.attack = iv;
    pkm->ivs.stat.defense = iv;
    pkm->ivs.stat.speed = iv;
    pkm->ivs.stat.spAttack = iv;
    pkm->ivs.stat.spDefense = iv;
    count = 0;
    for (i = 0; i < 6; i++) {
        if (data.evFlags & (1 << i)) {
            count++;
        }
    }
    ev = 510 / count;
    if (ev > 255) {
        ev = 255;
    }
    for (i = 0; i < 6; i++) {
        if (data.evFlags & (1 << i)) {
            pkm->evs[i] = ev;
        }
    }
    pkm->ppUps = 0;
    pkm->region = 0;
    ability = PML_PersonalGetParamSingle(pkm->species, 0, 0x1b);
    if (ability != 0) {
        if (pkm->personality & 1) {
        } else {
            ability = PML_PersonalGetParamSingle(pkm->species, 0, 0x1a);
        }
    } else {
        ability = PML_PersonalGetParamSingle(pkm->species, 0, 0x1a);
    }
    pkm->ability = ability;
    pkm->happiness = happiness;
    msgData = GFL_MsgSysLoadData(FALSE, 2, 0x5a, heapId);
    GFL_MsgDataLoadRawStr(msgData, pkm->species, pkm->nickname, NELEMS(pkm->nickname));
    GFL_MsgDataFree(msgData);
    return personality;
}

static void genSubwayBtlInstitutePoke(const BSubwayPokemon *src, PartyPkm *pkm, u16 level) {
    StrBuf *strbuf;
    u16 nickname[11];
    int i;
    u16 terminator;

    PokeParty_ClearPkm(pkm);
    PokeParty_CreatePkm(pkm, src->species, level, -1, -1, src->ivs.all & 0x3fffffff, src->personality, 0);
    PokeParty_SetParam(pkm, PKM_PARAM_FORM, (u8)src->form);
    PokeParty_SetParam(pkm, PKM_PARAM_ITEM, src->item);
    for (i = 0; i < 4; i++) {
        PokeParty_SetParam(pkm, PKM_PARAM_MOVE1 + i, src->moves[i]);
        PokeParty_SetParam(pkm, PKM_PARAM_MOVE1_PP_UP + i, (u8)((src->ppUps >> (i * 2)) & 3));
        PokeParty_SetParam(pkm, PKM_PARAM_MOVE1_PP + i, (u8)PokeParty_GetParam(pkm, PKM_PARAM_MOVE1_MAX_PP + i, NULL));
    }
    PokeParty_SetParam(pkm, PKM_PARAM_ID, src->id);
    PokeParty_SetParam(pkm, PKM_PARAM_EV_HP, src->evs[0]);
    PokeParty_SetParam(pkm, PKM_PARAM_EV_HP + 1, src->evs[1]);
    PokeParty_SetParam(pkm, PKM_PARAM_EV_HP + 2, src->evs[2]);
    PokeParty_SetParam(pkm, PKM_PARAM_EV_HP + 3, src->evs[3]);
    PokeParty_SetParam(pkm, PKM_PARAM_EV_HP + 4, src->evs[4]);
    PokeParty_SetParam(pkm, PKM_PARAM_EV_HP + 5, src->evs[5]);
    PokeParty_SetParam(pkm, PKM_PARAM_ABILITY, src->ability);
    PokeParty_SetParam(pkm, PKM_PARAM_HAPPINESS, src->happiness);
    PokeParty_SetNature(pkm, src->nature);
    strbuf = GFL_StrBufCreate(NELEMS(nickname), HEAPID_GAMEEVENT);
    terminator = GFL_StrBufGetTerminator();
    for (i = 0; i < 11; i++) {
        nickname[i] = src->nickname[i];
    }
    nickname[i - 1] = terminator;
    GFL_StrBufLoadString(strbuf, nickname);
    PokeParty_SetParam(pkm, PKM_PARAM_NICKNAME, (u32)strbuf);
    GFL_StrBufFree(strbuf);
    PokeParty_SetParam(pkm, PKM_PARAM_REGION, src->region);
    PokeParty_SetParam(pkm, PKM_PARAM_LEVEL, PokeParty_GetLevel(pkm));
}

static void func_ov012_021627b0(u32 arcId, BSubwayPokemonData *data, u32 file) {
    GFL_ArcSysRead(data, arcId, file);
}

void *func_ov012_021627c0(u32 arcId, u16 file, HeapID heapId) {
    return GFL_ArcSysReadHeapNewLZ(arcId, (u16)(file + 1), FALSE, heapId);
}

static u16 func_ov012_021627d4(MATHRandContext32 *rand) {
    if (rand == NULL) {
        return GFL_RandomLC(0xffffffff) / (0xffffffff / 0x10000);
    }
    return MATH_Rand32(rand, 0xffffffff) / (0xffffffff / 0x10000);
}

static u8 func_ov012_02162828(u32 trainerId) {
    if (trainerId < 50) {
        return 3;
    }
    if (trainerId < 70) {
        return 6;
    }
    if (trainerId < 90) {
        return 9;
    }
    if (trainerId < 110) {
        return 12;
    }
    if (trainerId < 160) {
        return 15;
    }
    if (trainerId < 180) {
        return 18;
    }
    if (trainerId < 200) {
        return 21;
    }
    return 31;
}

BOOL func_ov012_02162864(BSubwayTrainer *trainer, u16 trainerId, u32 count, const u16 *species, const u16 *items,
                         BSubwayTeamConfig *config, HeapID heapId) {
    void *trainerData = func_ov012_021628c0(trainer, 0xd4, trainerId, 0xf, heapId);
    BOOL result = func_ov012_0216292c(trainerData, trainerId, trainer->pokemon, count, 0xd3, species, items, config,
                                      NULL, func_ov012_02162828(trainerId), heapId);

    GFL_HeapFree(trainerData);
    return result;
}

void *func_ov012_021628c0(BSubwayTrainer *trainer, u32 arcId, u16 trainerId, u16 msgFile, HeapID heapId) {
    MsgData *msgData = GFL_MsgSysLoadData(FALSE, 2, msgFile, heapId);
    u16 *trainerData;
    StrBuf *name;

    sys_memset(trainer, 0, sizeof(BSubwayTrainer));
    trainerData = func_ov012_021627c0(arcId, trainerId, heapId);
    trainer->unk00 = trainerId + 1;
    trainer->message.sentenceType = 0xffff;
    trainer->message.sentenceId = trainerId * 3;
    trainer->trainerId = trainerData[0];
    name = GFL_MsgDataLoadStrbufNew(msgData, trainerId);
    // BUG: the size is in bytes, but GFL_StrBufStoreString counts characters
#ifdef BUGFIX
    GFL_StrBufStoreString(name, trainer->name, NELEMS(trainer->name));
#else
    GFL_StrBufStoreString(name, trainer->name, sizeof(trainer->name));
#endif
    GFL_StrBufFree(name);
    GFL_MsgDataFree(msgData);
    return trainerData;
}

BOOL func_ov012_0216292c(const u16 *trainerData, u16 trainerId, BSubwayPokemon *pkms, u8 count, u32 arcId,
                         const u16 *species, const u16 *items, BSubwayTeamConfig *config, MATHRandContext32 *rand,
                         u8 iv, HeapID heapId) {
    u32 files[4];
    u32 pids[4];
    BSubwayPokemonData other;
    BSubwayPokemonData data;
    u8 natures[4];
    u32 seed;
    u32 file;
    u8 index;
    int i;
    int n;
    int retries;
    BOOL failed;

    failed = FALSE;
    retries = 0;
    n = 0;
    while (n != count) {
        index = func_ov012_021627d4(rand) % trainerData[1];
        file = trainerData[2 + index];
        func_ov012_021627b0(arcId, &data, file);
        for (i = 0; i < n; i++) {
            func_ov012_021627b0(arcId, &other, files[i]);
            if (other.species == data.species) {
                break;
            }
        }
        if (i != n) {
            continue;
        }
        if (species != NULL) {
            for (i = 0; i < count; i++) {
                if (data.species == species[i]) {
                    break;
                }
            }
            if (i != count) {
                continue;
            }
        }
        if (retries < 50) {
            for (i = 0; i < n; i++) {
                func_ov012_021627b0(arcId, &other, files[i]);
                if (other.item != 0 && other.item == data.item) {
                    break;
                }
            }
            if (i != n) {
                retries++;
                continue;
            }
            if (items != NULL) {
                for (i = 0; i < count; i++) {
                    if (data.item == items[i] && items[i] != 0) {
                        break;
                    }
                }
                if (i != count) {
                    retries++;
                    continue;
                }
            }
        }
        files[n] = file;
        natures[n] = data.nature;
        n++;
    }
    seed = func_ov012_021627d4(rand) | (func_ov012_021627d4(rand) << 16);
    if (retries >= 50) {
        failed = TRUE;
    }
    for (i = 0; i < n; i++) {
        pids[i] = func_ov012_02162490(&pkms[i], arcId, files[i], seed, 0, iv, i, failed, heapId);
    }
    if (config == NULL) {
        return failed;
    }
    config->id = seed;
    for (i = 0; i < 2; i++) {
        config->files[i] = files[i];
        config->pids[i] = pids[i];
        config->natures[i] = natures[i];
    }
    return failed;
}

static BOOL func_ov012_02162ae8(BSubwayTrainer *trainer) {
    int i;

    for (i = 0; i < 4; i++) {
        if (trainer->winWords[i] != 0) {
            return TRUE;
        }
        if (trainer->loseWords[i] != 0) {
            return TRUE;
        }
    }
    return FALSE;
}

u32 func_ov012_02162b0c(u32 arcId, u16 file, HeapID heapId) {
    u16 *trainerData = func_ov012_021627c0(arcId, file, heapId);
    u32 value = func_ov012_02162b38(trainerData[0]);

    GFL_HeapFree(trainerData);
    return value;
}

u16 func_ov012_02162b28(u32 arcId, u16 file, HeapID heapId) {
    u16 *trainerData = func_ov012_021627c0(arcId, file, heapId);
    u16 trainerClass = trainerData[0];

    GFL_HeapFree(trainerData);
    return trainerClass;
}

u32 func_ov012_02162b38(u16 trainerClass) {
    u32 i;

    for (i = 0; i < NELEMS(data_ov012_0216d9b4); i++) {
        if (trainerClass == data_ov012_0216d9b4[i].trainerClass) {
            return data_ov012_0216d9b4[i].value;
        }
    }
    return 10;
}
