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
void func_ov036_021b6690(void *gimmick);
u32 LinkFestival_GetNormalChangeBGMID(LinkFestival *festival);
void *GetFestMissionCfg(LinkFestival *festival);
u32 GetTrainerCardTextMSGID(u32 type);
FestivalText *getTextFileForFestMissions(HeapID heapId);

#endif // POKEBW2_FIELD_FESTIVAL_H
