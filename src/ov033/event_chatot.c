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
#include "field/pdw_postman.h"
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

GameEvent *func_ov033_02178ca8(GameSystem *gsys, Field *field, u8 partyIndex) {
    GameEvent *event;
    ChatotEventWork *work;
    PokeParty *party;

    event = GameEvent_Create(gsys, NULL, func_ov033_02178d10, sizeof(ChatotEventWork));
    work = GameEvent_GetData(event);
    sys_memset(work, 0, sizeof(ChatotEventWork));
    work->gsys = gsys;
    work->gameData = GSYS_GetGameData(gsys);
    work->chatter = getChatterBlockAddress(GameData_GetSaveControl(work->gameData));
    work->field = field;
    work->player = Field_GetPlayer(field);
    party = GameData_GetParty(work->gameData);
    work->pkm = PokeParty_GetPkm(party, partyIndex);
    work->msgBGSys = Field_GetMsgBGSys(work->field);
    work->partyIndex = partyIndex;
    work->unk54 = 0;
    return event;
}

void func_ov033_02178fcc(void *work, u32 *state) {
    *state = 1;
}

void func_ov033_02178fd4(ChatotEventWork *work) {
    DisableAllActorsMovement(Field_GetActorSystem(GSYS_GetField(work->gsys)));
}

void func_ov033_02178fe8(ChatotEventWork *work) {
    EnableAllActorsMovement(Field_GetActorSystem(GSYS_GetField(work->gsys)));
}

void func_ov033_02178ffc(ChatotEventWork *work) {
    BoxPkm *pkm;
    ArcTool *arc;
    BOOL encrypted;
    ClActorSetup setup;

    work->unit = func_0204bf1c(1, 0, 21);
    pkm = func_0201d620(work->pkm);
    arc = MakePokeGraArcHandle(21);
    encrypted = PML_PkmDecrypt(pkm);
    work->chars = func_02033f90(arc, pkm, 0, 0, 21);
    work->palette = func_02033f2c(arc, pkm, 0, 0, 0xc0, 21);
    work->cellAnims = func_02034000(pkm, 0, 1, 0, 21);
    PML_PkmReEncrypt(pkm, encrypted);
    GFL_ArcToolFree(arc);
    setup = data_ov033_0217c488;
    work->sprite = func_0204c040(work->unit, work->chars, work->palette, work->cellAnims, &setup, 0, 21);
}

void func_ov033_021790a0(ChatotEventWork *work) {
    func_0204c108(work->sprite);
    func_0204b98c(work->chars);
    func_0204bcd0(work->palette);
    func_0204be64(work->cellAnims);
    func_0204bf98(work->unit);
}

u32 func_ov033_021790c4(ChatotEventWork *work) {
    ClActorPos position;

    if (work->animFrame == 0) {
        work->animOffset = -4;
    }
    if (work->animOffset == -4) {
        work->animOffset = 3;
        work->animFrame++;
        if (work->animFrame == 3) {
            return 0;
        }
    }
    func_0204c178(work->sprite, &position, 0);
    position.y -= work->animOffset;
    func_0204c140(work->sprite, &position, 0);
    work->animOffset--;
    return 1;
}

void func_ov033_02179140(ChatotEventWork *work) {
    u32 paletteId;
    GFLBitmap *bitmap;

    paletteId = GetSysMsgBoxPaletteDatID(0);
    GFL_G2DIOLoadNCLR(5, paletteId, 0, 0, 0, 32, 21);
    work->window = BmpWin_CreateDynamic(1, 10, 3, 12, 12, 0, 1);
    bitmap = BmpWin_GetBitmap(work->window);
    GFL_BitmapFill(bitmap, 17);
    BmpWin_FlushChar(work->window);
    BmpWin_FlushMap(work->window);
    BmpWin_DrawFrame(work->window, 1, 1, 0);
    func_ov033_02178ffc(work);
}

void func_ov033_021791a8(ChatotEventWork *work) {
    func_ov033_021790a0(work);
    func_02024eec(work->window, 1);
    BmpWin_Free(work->window);
}
