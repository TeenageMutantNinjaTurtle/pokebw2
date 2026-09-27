#ifndef POKEBW2_FIELD_EVENT_WIFIBATTLEMATCH_H
#define POKEBW2_FIELD_EVENT_WIFIBATTLEMATCH_H

// Wi-Fi battles, started by the NetConnectWiFiBattle script command

#include "types.h"
#include "struct_decls.h"

typedef struct {
    Field *field;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} EventWifiBattleMatchArgs;

GameEvent *EventWifiBattleMatch_Create(GameSystem *gsys, Field *field, u32 unk10, u32 unk14, u32 unk18);
GameEvent *EventWifiBattleMatch_CreateFromArgs(GameSystem *gsys, void *args);

#endif // POKEBW2_FIELD_EVENT_WIFIBATTLEMATCH_H
