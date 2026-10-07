#ifndef POKEBW2_SYSTEM_CODEIN_PARAM_H
#define POKEBW2_SYSTEM_CODEIN_PARAM_H

#include "types.h"
#include "gfl/str.h"
#include "struct_decls.h"

// The parameters of the code input screen (codein_param.c), where the player types a number such as a Friend Code.
// Our names

// The groups the digits are shown in, the last one repeated after them
#define CODEIN_BLOCK_COUNT 3

struct CodeInParam {
    u32 mode;
    // How many digits the code has
    u32 length;
    int blocks[CODEIN_BLOCK_COUNT + 1];
    u32 unk18;
    u32 unk1C;
    // The code typed, length characters
    StrBuf *str;
};

// blocks holds the number of digits of each group
CodeInParam *CodeInParam_Create(u32 heapId, u32 mode, u32 a2, u32 length, const int *blocks);
void CodeInParam_Free(CodeInParam *param);

#endif // POKEBW2_SYSTEM_CODEIN_PARAM_H
