#ifndef POKEBW2_FIELD_TRAINER_SCRIPT_H
#define POKEBW2_FIELD_TRAINER_SCRIPT_H

#include "types.h"
#include "struct_decls.h"

struct TrainerClashSlot {
    struct {
        u32 words[6];
    } payload;
    u32 result;
};

extern const u16 data_ov012_0216c9a8[];

void SetupTrainerClashSlot(GameEvent *event, int index, const TrainerClashSlot *slot);
u16 GetNPCTrainerIDFromSCRID(u32 scriptId);
u16 GetNormalSCRIDFromTrainerID(u32 trainerId);
u16 GetPairMember2SCRIDFromTrainerID(u32 trainerId);
BOOL isTrainerScrIdDoublePair2(u32 scriptId);
BOOL isDoubleBattle(u32 trainerId);
u8 getBattleType(u32 trainerId);
BOOL TrainerFlagGet(EventWork *eventWork, u16 trainerId);
void setTrainerBattleFlag(EventWork *eventWork, u16 trainerId);
void clearTrainerBattleFlag(EventWork *eventWork, u16 trainerId);

#endif // POKEBW2_FIELD_TRAINER_SCRIPT_H
