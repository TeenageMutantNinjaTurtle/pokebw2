#include "types.h"
#include "app/funfest_mission.h"
#include "app/name_entry.h"
#include "battle/btl_setup.h"
#include "demo/shinka_demo.h"
#include "field/battle_facility.h"
#include "field/bsubway_scr.h"
#include "field/encounter.h"
#include "field/encounter_effect.h"
#include "field/entree_forest.h"
#include "field/entree_scripts.h"
#include "field/event_abyssal_ruins.h"
#include "field/event_cgear_shutdown.h"
#include "field/event_chatot.h"
#include "field/event_dendou_machine.h"
#include "field/event_dive.h"
#include "field/event_field_trade.h"
#include "field/event_fishing.h"
#include "field/event_fly.h"
#include "field/event_funfest_mission.h"
#include "field/event_game_manual.h"
#include "field/event_mapchange.h"
#include "field/event_phrase_input.h"
#include "field/event_pokemon_center.h"
#include "field/event_sound.h"
#include "field/event_sweet_scent.h"
#include "field/event_wild_battle.h"
#include "field/festival.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_actor_animation.h"
#include "field/field_display_control.h"
#include "field/field_effects.h"
#include "field/field_environment.h"
#include "field/field_event.h"
#include "field/field_fog.h"
#include "field/field_lifecycle.h"
#include "field/field_map.h"
#include "field/field_money_window.h"
#include "field/field_move_scripts.h"
#include "field/field_move_tcb.h"
#include "field/field_party.h"
#include "field/field_player.h"
#include "field/field_prop.h"
#include "field/field_script.h"
#include "field/field_script_event.h"
#include "field/field_surf.h"
#include "field/field_task.h"
#include "field/field_visuals.h"
#include "field/fld_trade.h"
#include "field/funfest_scripts.h"
#include "field/mystery_gift_delivery.h"
#include "field/mystery_gift_script.h"
#include "field/ov131.h"
#include "field/pc_sound.h"
#include "field/player_state.h"
#include "field/subscreen.h"
#include "field/trial_house.h"
#include "field/unity_tower.h"
#include "field/zone.h"
#include "gfl/arc.h"
#include "gfl/bmpwin.h"
#include "gfl/fade.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/input.h"
#include "gfl/msg.h"
#include "gfl/net.h"
#include "gfl/overlay.h"
#include "gfl/random.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "pml/evolution.h"
#include "pml/poke_graphic.h"
#include "pml/poke_party.h"
#include "save/bag.h"
#include "save/box.h"
#include "save/bsubway_save.h"
#include "save/chatter.h"
#include "save/dream_world.h"
#include "save/high_link.h"
#include "save/join_avenue.h"
#include "save/mystery_gift.h"
#include "save/player_info.h"
#include "save/pokedex.h"
#include "save/records.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "save/trial_house.h"
#include "struct_decls.h"
#include "system/aeabi.h"
#include "system/game_comm.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/version.h"
#include "system/vm.h"

struct TrialHouseCopyBlock {
    u32 words[0x48];
};

struct TrialHouseSave {
    u8 flag0;
    u8 pad1[0x13];
    u8 flag14;
    u8 pad15[0x13];
    u8 bits[16];
};

struct TrialHouseWork *CreateTrialHouseWk(GameSystem *gsys) {
    u32 saveSize = func_0200ee20();
    GameData *gameData = GSYS_GetGameData(gsys);
    struct TrialHouseWork *work;

    GameData_GetSaveControl(gameData);
    work = GFL_HeapAllocate(HEAPID_TRIAL_HOUSE, sizeof(struct TrialHouseWork), TRUE, "trial_house.c", 0x5d);
    work->heapId = HEAPID_TRIAL_HOUSE;
    work->saveBuffer = GFL_HeapAllocate(HEAPID_TRIAL_HOUSE, saveSize, TRUE, "trial_house.c", 0x5f);
    func_ov033_0217acd4(gsys, work);
    work->party = PokeParty_Create(work->heapId);
    return work;
}

void func_ov033_0217acd4(GameSystem *gsys, TrialHouseWork *work) {
    u32 size;
    SaveControl *save;
    void *buffer;
    void *extraSave;
    BOOL check;

    save = GameData_GetSaveControl(GSYS_GetGameData(gsys));
    size = 0x800;
    buffer = GFL_HeapAllocate(0x8004, size, TRUE, "trial_house.c", 0x79);
    func_02007560(save, 5, 0x8004, buffer, size);
    extraSave = getAddressOfExtraSaveBlk(save, 5, 0);
    size = 0;
    if (func_0200ee38(extraSave)) {
        check = func_0200ee64(extraSave);
        size = 1;
        if (!check) {
            size = 2;
        }
    }
    freeIntermediateSaveExtraBlksAfterLoad2(save, 5);
    GFL_HeapFree(buffer);
    work->initState = size;
}

void TrialHouseWorkDelete(void *unused, struct TrialHouseWork **workPtr) {
    if (*workPtr != NULL) {
        GFL_HeapFree((*workPtr)->saveBuffer);
        GFL_HeapFree((*workPtr)->party);
        GFL_HeapFree(*workPtr);
        *workPtr = NULL;
    }
}

void func_ov033_0217ad78(TrialHouseWork *work, u32 mode) {
    u32 capacity;
    u32 battleType;

    if (work != NULL) {
        if (mode <= 1) {
            if (mode == 0) {
                battleType = 0;
                capacity = 3;
            } else {
                battleType = 1;
                capacity = 4;
            }
            work->capacity = capacity;
            ((u32 *)work)[0x4b] = battleType;
        } else {
            work->battleType = 0;
            work->capacity = 3;
        }
        PokeParty_InitCore(work->party, work->capacity);
    }
}

void func_ov033_0217adbc(TrialHouseWork *work, u32 selectionFlag) {
    work->selectionFlag = selectionFlag;
}

void func_ov033_0217adc4(GameSystem *gsys, TrialHouseWork *work, u32 mode) {
    if (work->selectionFlag != 0) {
        func_ov033_0217ae5c(gsys, work, mode);
    } else {
        func_ov033_0217ade8(work, mode);
    }
    func_ov033_0217aed0(work);
}

void func_ov033_0217ade8(TrialHouseWork *work, u32 mode) {
    u32 base;
    u32 range;
    u32 value;
    u16 flag;
    u32 zero;

    switch (mode) {
    case 0:
        base = 0x32;
        range = 0x14;
        break;
    case 1:
        base = 0x6e;
        range = 0x32;
        break;
    case 2:
        base = 0xa0;
        range = 0x14;
        break;
    case 3:
        base = 0xf0;
        range = 0x1e;
        break;
    case 4:
        base = 0x10e;
        range = 0x1e;
        break;
    default:
        base = 0x32;
        range = 0x14;
        break;
    }
    value = base + GFL_RandomLC(range);
    zero = 0;
    flag = (work->heapId & 0x7fff) | 0x8000;
    func_ov012_02162864(work, value, work->capacity, zero, zero, zero, flag);
}

void func_ov033_0217ae5c(GameSystem *gsys, TrialHouseWork *work, u32 mode) {
    SaveControl *save;
    void *buffer;
    void *extra;
    TrialHouseCopyBlock *source;
    u32 size;

    save = GameData_GetSaveControl(GSYS_GetGameData(gsys));
    size = 0x800;
    buffer = GFL_HeapAllocate(0x8004, size, TRUE, "trial_house.c", 0x14c);
    if (func_02007560(save, 5, 0x8004, buffer, size) == 1) {
        extra = getAddressOfExtraSaveBlk(save, 5, 0);
        source = func_0200ee90(extra, mode);
        *(TrialHouseCopyBlock *)work = *source;
    }
    freeIntermediateSaveExtraBlksAfterLoad2(save, 5);
    GFL_HeapFree(buffer);
}

u32 func_ov033_0217aed0(TrialHouseWork *work) {
    return func_ov012_02162b38(*(u16 *)((u8 *)work + 4));
}

GameEvent *func_ov033_0217aedc(GameSystem *gsys, TrialHouseWork *work, u32 actorId, u32 messageId) {
    return func_ov012_02161e6c(gsys, work, actorId, (u16)messageId);
}

GameEvent *func_ov033_0217aee8(GameSystem *gsys, TrialHouseWork *work, u32 arg) {
    GameEvent *event;
    struct TrialHouseEventData *data;

    event = GameEvent_Create(gsys, NULL, func_ov033_0217af5c, sizeof(struct TrialHouseEventData));
    data = GameEvent_GetData(event);
    data->gsys = gsys;
    data->result = (u16 *)arg;
    data->work = work;
    data->timeout = 0;
    data->code = 0x2e;
    data->size = func_0200ee20();
    data->saveBuffer = work->saveBuffer;
    data->region = region;
#ifdef BLACK2
    data->mask = 0x800000;
#else
    data->mask = 0x400000;
#endif
    data->active = 1;
    data->flag4 = 0;
    data->id = 0x8015;
    return event;
}

GameEventReturnCode func_ov033_0217af5c(GameEvent *event, u32 *state, void *arg) {
    TrialHouseEventData *data;
    GameSystem *gsys;
    GameData *gameData;
    void *save;
    void *saveBuffer;
    u32 a;
    u32 b;
    u32 c;

    data = arg;
    gsys = data->gsys;
    switch (*state) {
    case 0:
        data->subwork = func_ov012_02152990(data);
        if (func_ov012_02152b64(data->subwork) == 0) {
            *data->result = 0;
            *state = 4;
        } else {
            *state = 1;
        }
        break;
    case 1:
        if (GCTX_HIDGetPressedKeys() == 2) {
            *data->result = 3;
            *state = 4;
            break;
        }
        func_ov012_02152bec(data->subwork);
        data->timeout++;
        if (data->timeout > 120) {
            *state = 2;
        }
        break;
    case 2:
        if (GCTX_HIDGetPressedKeys() == 2) {
            *data->result = 3;
            *state = 4;
            break;
        }
        func_ov012_02152bec(data->subwork);
        if (func_ov012_02152bb4(data->subwork)) {
            *state = 3;
        } else {
            *data->result = 0;
            *state = 4;
        }
        break;
    case 3:
        if (GCTX_HIDGetPressedKeys() == 2) {
            *data->result = 3;
            *state = 4;
            break;
        }
        func_ov012_02152bec(data->subwork);
        if (!func_ov012_02152bd4(data->subwork)) {
            break;
        }
        gameData = GSYS_GetGameData(gsys);
        save = func_0200f1b8(GameData_GetSaveControl(gameData));
        saveBuffer = data->work->saveBuffer;
        a = func_0200ee7c(saveBuffer);
        b = func_0200ee38(saveBuffer);
        c = func_ov033_0217b35c(save, a);
        if (b != 0 && (c == 0 || a == 0)) {
            func_ov033_0217b384(save, a);
            func_0200eea0(gameData, data->work->saveBuffer, 0x8004);
            *data->result = 1;
        } else if (c != 0) {
            *data->result = 2;
        } else {
            *data->result = 0;
        }
        *state = 4;
        break;
    case 4:
        func_ov012_02152bfc(data->subwork);
        *state = 5;
        break;
    case 5:
        if (func_02042ab8()) {
            *state = 6;
        }
        break;
    case 6:
        func_ov033_0217acd4(gsys, data->work);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

u32 func_ov033_0217b2e4(u32 unused, TrialHouseWork *work) {
    return work->initState;
}

GameEvent *func_ov033_0217b2ec(GameSystem *gsys, u32 unused, u32 mode) {
    GameEvent *event;
    TrialHouseEffectEvent *data;

    event = GameEvent_Create(gsys, NULL, func_ov033_0217b3ac, sizeof(TrialHouseEffectEvent));
    data = GameEvent_GetData(event);
    data->gsys = gsys;
    data->buffer = NULL;
    data->mode = mode;
    data->effect = func_ov036_021c6cc8(0x8015, GSYS_GetField(gsys));
    func_ov036_021c6d14(data->effect);
    return event;
}

u32 func_ov033_0217b32c(GameSystem *gsys) {
    TrialHouseSave *save;

    save = func_0200f1b8(GameData_GetSaveControl(GSYS_GetGameData(gsys)));
    if (save->flag0) {
        if (save->flag14) {
            return 3;
        }
        return 1;
    }
    if (save->flag14) {
        return 2;
    }
    return 0;
}

u8 func_ov033_0217b35c(void *savePtr, u32 index) {
    TrialHouseSave *save;
    u8 byte;
    u8 bit;

    save = savePtr;
    if (index < 128) {
        byte = save->bits[(u8)(index >> 3)];
        bit = index & 7;
        return (byte >> bit) & 1;
    }
    return TRUE;
}

void func_ov033_0217b384(void *savePtr, u32 index) {
    TrialHouseSave *save;
    u8 byteIndex;
    u8 bit;
    u8 mask;

    save = savePtr;
    if (index < 128) {
        byteIndex = index >> 3;
        bit = index & 7;
        mask = 1 << bit;
        save->bits[byteIndex] |= mask;
    }
}

GameEventReturnCode func_ov033_0217b3ac(GameEvent *event, u32 *state, void *arg) {
    TrialHouseEffectEvent *data;
    GameData *gameData;
    SaveControl *save;
    void *extraSave;

    data = arg;
    gameData = GSYS_GetGameData(data->gsys);
    save = GameData_GetSaveControl(gameData);
    switch (*state) {
    case 0:
        data->buffer = GFL_HeapAllocate(0x8004, 0x800, FALSE, "trial_house.c", 0x34c);
        func_02007560(save, 5, 0x8004, data->buffer, 0x800);
        extraSave = getAddressOfExtraSaveBlk(save, 5, 0);
        if (data->mode == 1) {
            func_0200ef1c(extraSave);
        } else {
            sys_memset(extraSave, 0, func_0200ee20());
        }
        func_020178c4(gameData, 5);
        (*state)++;
        break;
    case 1:
        if (func_020178f4(gameData, 5) == 2) {
            freeIntermediateSaveExtraBlksAfterLoad2(save, 5);
            GFL_HeapFree(data->buffer);
            func_ov036_021c6d3c(data->effect);
            func_ov036_021c6cf8(data->effect);
            return GAMEEVENT_DONE;
        }
        break;
    }
    return GAMEEVENT_CONTINUE;
}
