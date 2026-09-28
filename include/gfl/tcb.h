#ifndef POKEBW2_GFL_TCB_H
#define POKEBW2_GFL_TCB_H

#include "types.h"

// Tasks that run every frame or every VBlank. Names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

typedef struct TCB TCB;

typedef void (*TCBFunc)(TCB *tcb, void *data);

TCB *GFL_VBlankTCBAdd(TCBFunc func, void *data, u32 priority);
BOOL GFL_TCBRemove(TCB *tcb);

#endif // POKEBW2_GFL_TCB_H
