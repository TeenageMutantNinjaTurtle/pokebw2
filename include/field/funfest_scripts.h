#ifndef POKEBW2_FIELD_FUNFEST_SCRIPTS_H
#define POKEBW2_FIELD_FUNFEST_SCRIPTS_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"

BOOL s0279_FunfestBGMReturn(VM *vm, FieldScriptEnv *env);
BOOL s0274_FunfestMissionStart(VM *vm, FieldScriptEnv *env);
BOOL s0276_FunfestMissionBroadcast(VM *vm, FieldScriptEnv *env);
BOOL s0277_FunfestActorDelete(VM *vm, FieldScriptEnv *env);
BOOL s027A_FunfestGetGenericInfo(VM *vm, FieldScriptEnv *env);
BOOL s027B_FunfestGetItemExchangeInfo(VM *vm, FieldScriptEnv *env);
BOOL s027C_FunfestGetItemSaleInfo(VM *vm, FieldScriptEnv *env);
BOOL s027D_FunfestGetPokemonQuizInfo(VM *vm, FieldScriptEnv *env);
BOOL s027E_FunfestGetPokemonQuizSpecies(VM *vm, FieldScriptEnv *env);
BOOL s027F_FunfestGetPokemonQuizBogusSpecies(VM *vm, FieldScriptEnv *env);

void func_ov012_0216063c(u8 type, u16 value);

#endif // POKEBW2_FIELD_FUNFEST_SCRIPTS_H
