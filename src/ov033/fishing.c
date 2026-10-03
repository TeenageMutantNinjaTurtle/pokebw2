#include "battle/btl_setup.h"
#include "field/encounter.h"
#include "field/event_fishing.h"
#include "field/event_wild_battle.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_player.h"
#include "field/field_script.h"
#include "field/field_visuals.h"
#include "field/funfest_scripts.h"
#include "gfl/input.h"
#include "gfl/random.h"
#include "gfl/sound.h"
#include "pml/poke_party.h"
#include "save/join_avenue.h"
#include "save/records.h"
#include "system/game_event.h"

GameEventReturnCode EventFieldFishing_Callback(GameEvent *event, u32 *state, void *data) {
    FishingEventWork *work;
    PokeParty *party;
    PartyPkm *pkm;
    GameEvent *next;
    u32 result;
    u32 species;
    u8 battleMode;

    work = data;
    switch (*state) {
    case 0:
        if (work->noFishing != 0) {
            *state = 8;
            break;
        }
        FieldPlayer_SetSpecialSeq(work->player, 0x200);
        ++*state;
    case 1:
        if (func_ov036_0219a580(work->player) == 1) {
            func_ov012_021670f4(work->actor, 0);
            func_ov012_02167564(work->actor, work->flag5B);
            GFL_SndSEPlay(0x684);
            ++*state;
        }
        break;
    case 2:
        if (func_ov033_021795a4(work, 15) != 0) {
            func_ov033_02179628(work);
            if (work->battleSetup == NULL) {
                *state = 5;
            } else {
                work->timer = GFL_RandomLCAlt(90) + 30;
                ++*state;
            }
        }
        break;
    case 3:
        result = func_ov033_021795bc(work, work->timer);
        if (result == 1) {
            *state = 6;
        } else if (result == 2) {
            func_ov033_021795e8(work);
            ++*state;
        }
        break;
    case 4:
        result = func_ov033_021795bc(work, 30);
        if (result != 0) {
            func_ov033_02179614(work);
            if (result == 1) {
                func_ov033_02179650(work);
                func_ov012_021670f4(work->actor, 3);
                party = BtlSetup_GetParty(work->battleSetup, 1);
                pkm = PokeParty_GetPkm(party, 0);
                species = PokeParty_GetParam(pkm, 5, NULL);
                func_ov012_0216063c(0x1c, species);
                EventScriptCall_Start(event, 0x2796, NULL, NULL, 0x15);
                *state = 10;
            } else if (result == 2) {
                RecordAddOne(work->records, 0x50);
                *state = 7;
            }
        }
        break;
    case 5:
        result = func_ov033_021795bc(work, 120);
        if (result != 2) {
            if (result == 1) {
                *state = 6;
            }
            break;
        }
    case 6:
    case 7:
        func_ov033_02179650(work);
        if (work->battleSetup != NULL) {
            if (work->isPhenomenon == 1) {
                EncountSystem_CancelPhenomenon(work->encountSystem);
            }
            BtlSetup_Free(work->battleSetup);
        }
        func_ov012_021670f4(work->actor, 1);
        EventScriptCall_Start(event, 0x2792 + *state, NULL, NULL, 0x15);
        *state = 8;
        break;
    case 8:
        FieldPlayer_SetSpecialSeq(work->player, 8);
        *state = 9;
    case 9:
        if (func_ov036_0219a580(work->player) != 1) {
            break;
        }
        func_ov012_02167564(work->actor, 0);
        return GAMEEVENT_DONE;
    case 10:
        RecordAddOne(work->records, 8);
        func_02038bc8(13);
        battleMode = work->isPhenomenon == 1 ? 1 : 4;
        next = func_ov011_021686b8(work->gsys, work->field, work->battleSetup, 0, battleMode);
        GameEvent_Replace(event, next);
        return GAMEEVENT_CONTINUE;
    }
    return GAMEEVENT_CONTINUE;
}

u32 func_ov033_021795a4(FishingEventWork *work, u32 value) {
    u32 elapsed;

    elapsed = work->elapsed++;
    if (elapsed < value) {
        return 0;
    }
    work->elapsed = 0;
    return 1;
}

u32 func_ov033_021795bc(FishingEventWork *work, u32 value) {
    u32 elapsed;

    elapsed = work->elapsed++;
    if (elapsed < value) {
        if (GCTX_HIDGetPressedKeys() & PAD_BUTTON_A) {
            work->elapsed = 0;
            return 1;
        }
    } else {
        work->elapsed = 0;
        return 2;
    }
    return 0;
}

void func_ov033_021795e8(FishingEventWork *work) {
    void *effects;

    effects = Field_GetFieldEffects(work->field);
    func_ov012_021670f4(work->actor, 2);
    work->effect2C = func_ov036_021b3f14(effects, work->actor, 0, 1);
    func_ov036_021a5968(work->effect30, 1);
}

void func_ov033_02179614(FishingEventWork *work) {
    if (work->effect2C != NULL) {
        func_ov036_021a3a70(work->effect2C);
        work->effect2C = NULL;
    }
}

void func_ov033_02179628(FishingEventWork *work) {
    void *effects;
    u32 sameHeight;

    effects = Field_GetFieldEffects(work->field);
    sameHeight = 1;
    if (work->fishingPos.y != work->playerPos.y) {
        sameHeight = 0;
    }
    work->effect30 = func_ov036_021a58e0(effects, &work->fishingPos, work->faceDirection, sameHeight);
}

void func_ov033_02179650(FishingEventWork *work) {
    if (work->effect30 != NULL) {
        func_ov036_021a3a70(work->effect30);
        work->effect30 = NULL;
    }
}