#ifndef POKEBW2_FIELD_SCRCMD_NET_H
#define POKEBW2_FIELD_SCRCMD_NET_H

// Overlay 36's scrcmd_net.c: the script commands of the network. Names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"
#include "system/vm.h"

BOOL s013A_GameCommGetStatus(VM *vm, FieldScriptEnv *env);
BOOL func_ov036_021adc94(VM *vm, FieldScriptEnv *env);
BOOL func_ov036_021adcb4(VM *vm, FieldScriptEnv *env);
BOOL s015D_NetConnectWiFiClub(VM *vm, FieldScriptEnv *env);
BOOL s015E_NetConnectGTS(VM *vm, FieldScriptEnv *env);
BOOL s0162_NetConnectGTSNegotiation(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_SCRCMD_NET_H
