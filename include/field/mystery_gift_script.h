#ifndef POKEBW2_FIELD_MYSTERY_GIFT_SCRIPT_H
#define POKEBW2_FIELD_MYSTERY_GIFT_SCRIPT_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "struct_decls.h"

extern const u8 data_ov033_0217c410[];
extern const u8 data_ov033_0217c414[];
extern const u8 data_ov033_0217c418[];
extern const u8 data_ov033_0217c41c[];
extern const u8 data_ov033_0217c420[];
extern const u8 data_ov033_0217c404[];

u32 func_ov033_02177ed0(u32 index, u32 arg1, u32 arg2, u32 arg3);
u32 func_ov033_02177ef4(u32 index, u32 arg1, FieldScriptEnv *env);
u32 func_ov033_02177f28(u32 index, u32 arg1, FieldScriptEnv *env);
BOOL func_ov033_02177f5c(u32 index, u32 arg1, u32 arg2, u32 arg3);
u32 func_ov033_02177f84(u32 index, u32 arg1, u32 arg2, u32 arg3);
PartyPkm *func_ov033_021780d8(FieldScriptEnv *env, void *gift);
void func_ov033_02178110(FieldScriptEnv *env, GameData *gameData, void *gift);
u32 func_ov033_02178154(FieldScriptEnv *env, GameData *gameData, void *gift);
u32 func_ov033_02178180(WordSet *wordSet, void *gift, FieldScriptEnv *env);
u32 func_ov033_021781e0(void);
u32 func_ov033_021781e4(void);
BOOL func_ov033_02178074(void *gift, u32 kind);
u32 func_ov033_021780a4(FieldScriptEnv *env, void *gift, u32 kind);
PartyPkm *func_ov012_02153160(void *gift, HeapID heapId, GameData *gameData);
void func_ov033_021781e8(FieldScriptEnv *env, GameData *gameData, void *gift);
u32 func_ov033_02178218(u32 arg0, u32 arg1, void *gift);
u32 func_ov033_02178230(WordSet *wordSet, void *gift, FieldScriptEnv *env);
u32 func_ov033_02178260(WordSet *wordSet, void *gift);
u32 func_ov033_02178274(void);
u32 func_ov033_02178278(u32 arg0, GameData *gameData, void *gift);
u32 func_ov033_02178290(void);
u32 func_ov033_02178294(WordSet *wordSet, void *gift, FieldScriptEnv *env);
u32 func_ov033_021782cc(void);
u32 func_ov033_021782d0(void *gift);
u32 func_ov033_021782f0(void);
void func_ov033_021782f4(u32 arg0, GameData *gameData, void *gift);
u32 func_ov033_02178334(void);
u32 func_ov033_02178338(WordSet *wordSet, void *gift, FieldScriptEnv *env);
u32 func_ov033_02178374(WordSet *wordSet, void *gift, FieldScriptEnv *env);
void *func_ov033_021783a8(void *save, u32 slot, void *gift);
void *func_ov033_021783f8(void *save, u32 *slot, void *gift);
void func_ov033_02178420(void *save, u32 slot);
u32 func_ov033_02178428(void *save);

#endif // POKEBW2_FIELD_MYSTERY_GIFT_SCRIPT_H
