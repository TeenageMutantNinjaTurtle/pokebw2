#ifndef POKEBW2_FIELD_STADIUM_SCRIPT_H
#define POKEBW2_FIELD_STADIUM_SCRIPT_H

#include "types.h"
#include "struct_decls.h"

struct StadiumTrainerEntry {
    u16 unk00;
    u16 unk02;
    u16 objCode;
    u16 trainerId;
};

BOOL s01E1_StadiumLoadTrainerTable(VM *vm, FieldScriptEnv *env);
BOOL s01E2_StadiumFreeTrainerTable(VM *vm, FieldScriptEnv *env);
BOOL s01E5_StadiumResetTrainerFlags(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_STADIUM_SCRIPT_H
