#ifndef POKEBW2_FIELD_FESTIVAL_H
#define POKEBW2_FIELD_FESTIVAL_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

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
BOOL isFesMissionAvailable(void *missionCfg);
void func_02014774(LinkFestival *festival, u32 arg1);
void func_ov130_021eed98(GameSystem *gsys);
void func_ov130_021eedb4(GameSystem *gsys);
u32 GetTrainerCardTextMSGID(u32 type);
void *func_ov036_021b5b7c(GameSystem *gsys, HeapID heapId);
void func_ov036_021b5bfc(void *work);
void func_ov036_021b5c28(void *work);
void func_ov036_021b5c78(void *work);
void *FesGimmick_Create(GameSystem *gsys, Field *field, HeapID heapId);
void FesGimmick_Free(void *gimmick);
void FesGimmick_BindActorSystem(void *gimmick, MMSys *actorSystem);
void FesGimmick_BindPlayer(void *gimmick, void *effects, FieldPlayer *player);
void func_ov036_021b65d4(void *gimmick);
void func_ov036_021b6660(void *gimmick);

#endif // POKEBW2_FIELD_FESTIVAL_H
