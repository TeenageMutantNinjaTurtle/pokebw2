#ifndef POKEBW2_FIELD_EVENT_PHRASE_INPUT_H
#define POKEBW2_FIELD_EVENT_PHRASE_INPUT_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "gfl/str.h"
#include "system/game_event.h"

struct EventPhraseInputData {
    GameSystem *gsys;
    GameData *gameData;
    TrainerGameInfoSave *trainerInfo;
    void *saveBlock;
    PlayerInfo *playerInfo;
    Field *field;
    void *unk18;
    u32 unk1C;
    u32 nameMode;
    u16 nameGender;
    u8 unk26[0x12];
    u32 maxLength;
    u8 unk3C[4];
    StrBuf *input;
    u8 unk44[4];
    TrainerGameInfoSave *trainerInfoForName;
    u32 unk4C;
    void *saveBlockForName;
    u8 unk54[4];
    u16 heapId;
    u16 unk5A;
    u32 mode;
};

GameEvent *EventPhraseInput_Create(GameSystem *gsys, Field *field, GameEvent *parent, u32 mode, u32 arg4);
GameEventReturnCode EventPhraseInput_Callback(GameEvent *event, u32 *state, void *data);
void func_ov033_02177734(struct EventPhraseInputData *data, void *nameEntryParams);

extern const u8 data_ov033_0217c400[];

#endif // POKEBW2_FIELD_EVENT_PHRASE_INPUT_H
