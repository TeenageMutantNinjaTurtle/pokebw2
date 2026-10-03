#include "types.h"
#include "battle/btlv.h"

// Function names from swan.
void Btlv_StringParam_Setup(BtlvStringParam *param, u32 type, u16 message) {
    u32 i;

    for (i = 0; i < 9; i++) {
        param->args[i] = 0;
    }
    param->count = 0;
    param->message = message;
    param->type = type;
    param->mode = 0x50;
}

void Btlv_StringParam_AddArg(BtlvStringParam *param, u32 arg) {
    u8 count;

    count = param->count;
    if (count < 9) {
        param->count = count + 1;
        param->args[count] = arg;
    }
}
