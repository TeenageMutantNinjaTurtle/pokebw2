#ifndef POKEBW2_PML_MOVE_REMINDER_H
#define POKEBW2_PML_MOVE_REMINDER_H

#include "types.h"
#include "struct_decls.h"

struct MoveReminderProcessData {
    PartyPkm *pkm;
    PlayerInfo *playerInfo;
    void *unk08;
    GameSystem *gsys;
    u16 *moves;
    u8 unk14[5];
    u8 unk19;
    u8 status;
    u8 unk1B;
};

MoveReminderProcessData *func_ov012_02169c7c(HeapID heapId);
void func_ov012_02169ca4(MoveReminderProcessData *data);

#endif // POKEBW2_PML_MOVE_REMINDER_H
