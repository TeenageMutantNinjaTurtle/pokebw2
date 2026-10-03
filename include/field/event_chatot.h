#ifndef POKEBW2_FIELD_EVENT_CHATOT_H
#define POKEBW2_FIELD_EVENT_CHATOT_H

#include "gfl/bmpwin.h"
#include "gfl/clact.h"
#include "system/game_event.h"

struct ChatotEventWork {
    void *chatter;
    GameSystem *gsys;
    GameData *gameData;
    Field *field;
    FieldPlayer *player;
    PartyPkm *pkm;
    u32 unk18;
    void *msgBGSys;
    u8 unk20[0x10];
    BmpWin *window;
    u32 unk34;
    ClActUnit *unit;
    ClActor *sprite;
    u32 chars;
    u32 palette;
    u32 cellAnims;
    u8 animFrame;
    s8 animOffset;
    u8 partyIndex;
    u8 unk4F[5];
    u32 unk54;
};

GameEvent *func_ov033_02178ca8(GameSystem *gsys, Field *field, u8 partyIndex);
GameEventReturnCode func_ov033_02178d10(GameEvent *event, u32 *state, void *data);
void func_ov033_02178fcc(void *work, u32 *state);
void func_ov033_02178fd4(ChatotEventWork *work);
void func_ov033_02178fe8(ChatotEventWork *work);
void func_ov033_021790a0(ChatotEventWork *work);
void func_ov033_021791a8(ChatotEventWork *work);

#endif // POKEBW2_FIELD_EVENT_CHATOT_H
