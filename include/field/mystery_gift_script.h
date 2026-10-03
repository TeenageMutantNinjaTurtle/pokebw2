#ifndef POKEBW2_FIELD_MYSTERY_GIFT_SCRIPT_H
#define POKEBW2_FIELD_MYSTERY_GIFT_SCRIPT_H

#include "types.h"
#include "struct_decls.h"

extern const u8 data_ov033_0217c410[];
extern const u8 data_ov033_0217c414[];
extern const u8 data_ov033_0217c418[];
extern const u8 data_ov033_0217c41c[];
extern const u8 data_ov033_0217c420[];

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

#endif // POKEBW2_FIELD_MYSTERY_GIFT_SCRIPT_H
