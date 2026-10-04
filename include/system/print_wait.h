#ifndef POKEBW2_SYSTEM_PRINT_WAIT_H
#define POKEBW2_SYSTEM_PRINT_WAIT_H

#include "types.h"
#include "system/printsys.h"

// Waiting on a print stream for a button or a touch at its pauses. The ROM doesn't name the file that holds these
typedef struct {
    u8 skipping;
    u32 flags;
} PrintWait;

void func_0202e678(PrintWait *wait, u32 flags);
// Steps the wait, and returns TRUE once the stream is done
BOOL func_0202e68c(PrintWait *wait, PrintStream *stream);

#endif // POKEBW2_SYSTEM_PRINT_WAIT_H
