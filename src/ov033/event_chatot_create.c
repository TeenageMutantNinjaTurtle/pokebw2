#include "field/event_chatot.h"
#include "field/field.h"
#include "gfl/std.h"
#include "pml/poke_party.h"
#include "save/chatter.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

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
