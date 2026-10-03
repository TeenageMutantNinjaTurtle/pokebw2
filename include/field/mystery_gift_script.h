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

#endif // POKEBW2_FIELD_MYSTERY_GIFT_SCRIPT_H
