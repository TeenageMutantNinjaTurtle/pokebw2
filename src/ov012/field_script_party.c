#include "constants/pokemon.h"
#include "field/field_event.h"
#include "field/field_script.h"
#include "pml/poke_party.h"
#include "save/box.h"
#include "system/game_data.h"
#include "system/vm.h"

BOOL s02D2_FieldOpenRestoreLCD(VM *vm, FieldScriptEnv *env) {
    GameSystem *gsys = FieldScriptEnv_GetGameSystem(env);
    ScriptWork *work = FieldScriptEnv_GetScriptWork(env);
    ScriptWork_CallEvent(work, EventFieldOpenRestoreLCD_Create(gsys));
    return TRUE;
}

BOOL CheckGetPartyPokemon(FieldScriptEnv *env, u32 index, PartyPkm **pkm) {
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    BOOL found;

    if (index < PokeParty_GetPkmCount(party)) {
        found = TRUE;
    } else {
        found = FALSE;
        index = 0;
    }
    *pkm = PokeParty_GetPkm(party, index);
    return found;
}

u32 GetScrPokeStat(FieldScriptEnv *env, u32 index, u32 param) {
    PartyPkm *pkm;

    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        return PokeParty_GetParam(pkm, param, NULL);
    }
    return 0;
}

BOOL CheckPokeMoveLearned_NonEgg(PartyPkm *pkm, u16 move) {
    if (PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) != 0) {
        return FALSE;
    }
    if (PokeParty_GetParam(pkm, PKM_PARAM_MOVE1, NULL) == move ||
        PokeParty_GetParam(pkm, PKM_PARAM_MOVE1 + 1, NULL) == move ||
        PokeParty_GetParam(pkm, PKM_PARAM_MOVE1 + 2, NULL) == move ||
        PokeParty_GetParam(pkm, PKM_PARAM_MOVE1 + 3, NULL) == move) {
        return TRUE;
    }
    return FALSE;
}

BOOL s011B_PokePartyGetTypes(VM *vm, FieldScriptEnv *env) {
    u16 *type1 = ScriptReadVar(vm, env);
    u16 *type2 = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;

    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        *type1 = PokeParty_GetParam(pkm, PKM_PARAM_TYPE1, NULL);
        *type2 = PokeParty_GetParam(pkm, PKM_PARAM_TYPE2, NULL);
    } else {
        *type1 = 0;
        *type2 = 0;
    }
    return FALSE;
}

BOOL s0104_PokePartyRecoverAll(VM *vm, FieldScriptEnv *env) {
    PokeParty_RecoverAll(GameData_GetParty(FieldScriptEnv_GetGameData(env)));
    return FALSE;
}

BOOL s0112_PokePartyGetEVTotal(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;
    u16 total = 0;

    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        total += (u16)PokeParty_GetParam(pkm, PKM_PARAM_EV_HP, NULL);
        total += (u16)PokeParty_GetParam(pkm, PKM_PARAM_EV_HP + 1, NULL);
        total += (u16)PokeParty_GetParam(pkm, PKM_PARAM_EV_HP + 2, NULL);
        total += (u16)PokeParty_GetParam(pkm, PKM_PARAM_EV_HP + 3, NULL);
        total += (u16)PokeParty_GetParam(pkm, PKM_PARAM_EV_HP + 4, NULL);
        total += (u16)PokeParty_GetParam(pkm, PKM_PARAM_EV_HP + 5, NULL);
    }
    *result = total;
    return FALSE;
}

BOOL s0101_PokePartyIsFullHP(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;

    *result = FALSE;
    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        u16 hp = (u16)PokeParty_GetParam(pkm, PKM_PARAM_HP, NULL);
        u16 maxHp = (u16)PokeParty_GetParam(pkm, PKM_PARAM_HP + 1, NULL);
        if (hp == maxHp || PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == TRUE) {
            *result = TRUE;
        }
    }
    return FALSE;
}

BOOL s024E_PokePartyIsFullPP(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;
    u16 pp;
    u16 i;
    u32 full;

    *result = FALSE;
    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        full = TRUE;

        if (PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == TRUE || PokeParty_GetParam(pkm, 3, NULL) == TRUE) {
            *result = TRUE;
            return FALSE;
        }

        for (i = 0; i < 4; i++) {
            if ((u16)PokeParty_GetParam(pkm, PKM_PARAM_MOVE1 + i, NULL) == 0) {
                continue;
            }
            pp = (u16)PokeParty_GetParam(pkm, 0x3a + i, NULL);
            u16 maxPp = (u16)PokeParty_GetParam(pkm, 0x42 + i, NULL);
            if (pp != maxPp) {
                full = FALSE;
                break;
            }
        }
        *result = full;
    }
    return FALSE;
}

BOOL s0102_PokePartyIsEgg(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;

    *result = FALSE;
    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        if (PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == 0) {
            *result = FALSE;
        } else {
            *result = TRUE;
        }
    }
    return FALSE;
}

BOOL s00FC_PokePartyGetHappiness(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;

    *result = 0;
    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        if (PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == 0) {
            *result = PokeParty_GetParam(pkm, PKM_PARAM_HAPPINESS, NULL);
        }
    }
    return FALSE;
}

BOOL s00FD_PokePartyAdjustHappiness(VM *vm, FieldScriptEnv *env) {
    u16 index = ScriptReadAny(vm, env);
    u16 delta = ScriptReadAny(vm, env);
    u16 mode = VM_Read16(vm);
    PartyPkm *pkm = NULL;
    u8 happiness;

    if (!CheckGetPartyPokemon(env, index, &pkm)) {
        return FALSE;
    }
    if (PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == TRUE) {
        return FALSE;
    }
    happiness = (u8)PokeParty_GetParam(pkm, PKM_PARAM_HAPPINESS, NULL);
    switch (mode) {
    case 0:
        if (delta > 255) {
            happiness = 255;
        } else {
            happiness = (u8)delta;
        }
        break;
    case 1:
        if (happiness + delta > 255) {
            happiness = 255;
        } else {
            happiness += (u8)delta;
        }
        break;
    case 2:
        if (happiness < delta) {
            happiness = 0;
        } else {
            happiness -= (u8)delta;
        }
        break;
    }
    PokeParty_SetParam(pkm, PKM_PARAM_HAPPINESS, happiness);
    return FALSE;
}

BOOL s00FE_PokePartyGetSpecies(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);

    if (GetScrPokeStat(env, index, PKM_PARAM_IS_EGG) != 0) {
        *result = SPECIES_EGG;
    } else {
        *result = GetScrPokeStat(env, index, PKM_PARAM_SPECIES);
    }
    return FALSE;
}

BOOL s00FF_PokePartyGetForme(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 index = ScriptReadAny(vm, env);
    *result = GetScrPokeStat(env, index, PKM_PARAM_FORM);
    return FALSE;
}

BOOL s010D_PokePartyGetMemberByType(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 kind = ScriptReadAny(vm, env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    u16 index;

    switch (kind) {
    case 2:
        index = PokeParty_GetFirstBattleReady(party);
        break;
    case 1:
        index = isEggInParty(party);
        break;
    default:
        index = 0;
        break;
    }
    *result = index;
    return FALSE;
}

BOOL s0103_PokePartyGetCount(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 kind = ScriptReadAny(vm, env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    int count;

    switch (kind) {
    case 0:
        count = PokeParty_GetPkmCount(party);
        break;
    case 1:
        count = howManyPartyPokesAreNotEggs(party);
        break;
    case 2:
        count = howManyPokesAreAbleToFight(party);
        break;
    case 3:
        count = countAllEggsInParty(party);
        break;
    case 4:
        count = countSanityEggsInParty(party);
        break;
    case 5:
        count = PokeParty_GetCapacity(party);
        int partyCount = PokeParty_GetPkmCount(party);
        if (count < partyCount) {
            count = 0;
        } else {
            count -= partyCount;
        }
        break;
    default:
        count = 0;
        break;
    }
    *result = count;
    return FALSE;
}

BOOL s0114_PokePartyGetCountBySpecies(VM *vm, FieldScriptEnv *env) {
    u16 species = ScriptReadAny(vm, env);
    u16 *result = ScriptReadVar(vm, env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    u16 partyCount = PokeParty_GetPkmCount(party);
    u16 count = 0;
    int i;

    if (species != 0 && species <= SPECIES_EGG - 1) {
        for (i = 0; i < partyCount; i++) {
            PartyPkm *pkm = PokeParty_GetPkm(party, i);
            if (pkm != NULL && PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == 0) {
                u16 foundSpecies = (u16)PokeParty_GetParam(pkm, PKM_PARAM_SPECIES, NULL);
                if (foundSpecies == species) {
                    count++;
                }
            }
        }
        *result = count;
    } else {
        *result = 0;
    }
    return FALSE;
}

BOOL s0121_BoxGetCount(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 kind = ScriptReadAny(vm, env);
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    BoxSaveAccessor *boxes = GameData_GetBoxSaveAccessor(gameData);
    GameData_GetParty(gameData);
    int count;

    switch (kind) {
    case 0:
        count = howManyTotalPokesAreInBoxes(boxes);
        break;
    case 1:
    case 2:
        count = howManyNormalPokesAreInAllBoxes(boxes);
        break;
    case 3:
        count = howManyTotalPokesAreInBoxes(boxes) - howManyNormalPokesAreInAllBoxes(boxes);
        break;
    case 5:
        count = howManyTotalPokesAreInBoxes(boxes);
        if (count > 720) {
            count = 0;
        } else {
            count = 720 - count;
        }
        break;
    default:
        count = 0;
        break;
    }
    *result = count;
    return FALSE;
}

BOOL s0118_PokePartyFindBySpecies(VM *vm, FieldScriptEnv *env) {
    u16 species = ScriptReadAny(vm, env);
    u16 *found = ScriptReadVar(vm, env);
    u16 *indexOut = ScriptReadVar(vm, env);
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    u16 count = PokeParty_GetPkmCount(party);
    int i;

    if (species != 0 && species <= SPECIES_EGG - 1) {
        for (i = 0; i < count; i++) {
            PartyPkm *pkm = PokeParty_GetPkm(party, i);
            if (pkm != NULL && PokeParty_GetParam(pkm, PKM_PARAM_IS_EGG, NULL) == 0) {
                u16 pkmSpecies = (u16)PokeParty_GetParam(pkm, PKM_PARAM_SPECIES, NULL);
                if (pkmSpecies == species) {
                    break;
                }
            }
        }
        if (i < count) {
            *found = TRUE;
            *indexOut = i;
        } else {
            *found = FALSE;
        }
    } else {
        *found = FALSE;
    }
    return FALSE;
}

BOOL s0115_PokePartyHasMove(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 move = ScriptReadAny(vm, env);
    u16 index = ScriptReadAny(vm, env);
    PartyPkm *pkm;

    *result = FALSE;
    if (CheckGetPartyPokemon(env, index, &pkm) == TRUE) {
        if (CheckPokeMoveLearned_NonEgg(pkm, move) == TRUE) {
            *result = TRUE;
        }
    }
    return FALSE;
}

BOOL s0116_PokePartyHasMoveAny(VM *vm, FieldScriptEnv *env) {
    PokeParty *party = GameData_GetParty(FieldScriptEnv_GetGameData(env));
    u16 *result = ScriptReadVar(vm, env);
    u16 move = ScriptReadAny(vm, env);
    int i;
    int count = PokeParty_GetPkmCount(party);

    *result = 6;
    for (i = 0; i < count; i++) {
        PartyPkm *pkm = PokeParty_GetPkm(party, i);
        if (CheckPokeMoveLearned_NonEgg(pkm, move) == TRUE) {
            *result = i;
            break;
        }
    }
    return FALSE;
}