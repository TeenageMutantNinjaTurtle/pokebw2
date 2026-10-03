#ifndef POKEBW2_FIELD_FESTIVAL_H
#define POKEBW2_FIELD_FESTIVAL_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

struct FestivalText {
    ArcTool *archive;
    MsgData *message;
};

extern const char data_ov027_021711e0[];

void func_ov030_02174108(u32 enabled);
void *Field_GetFesGimmick(Field *field);
BOOL FesGimmick_IsCurrent(void *gimmick, u32 type);
void DeleteFunfestActor(void *gimmick, u16 zoneId, u8 actorIndex);
void func_ov072_021e8d08(void *gimmick, FieldActor *actor, u16 arg0, u16 arg1, u16 *out0, u16 *out1);
void func_ov072_021e8d70(void *gimmick, FieldActor *actor, u16 *out0, u16 *out1);
void func_ov072_021e8ddc(void *gimmick, u16 *out0, u16 *out1, u16 *out2);
u16 func_ov072_021e8ee8(void *gimmick, u8 index);
u16 func_ov072_021e8ef4(void *gimmick, u8 index);
void func_ov036_021b6690(void *gimmick);
u32 LinkFestival_GetNormalChangeBGMID(LinkFestival *festival);
void *GetFestMissionCfg(LinkFestival *festival);
u32 GetTrainerCardTextMSGID(u32 type);
FestivalText *getTextFileForFestMissions(HeapID heapId);

#endif // POKEBW2_FIELD_FESTIVAL_H
