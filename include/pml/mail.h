#ifndef POKEBW2_PML_MAIL_H
#define POKEBW2_PML_MAIL_H

#include "types.h"
#include "gfl/heap.h"

typedef struct MailData MailData;

// Allocates a blank mail
MailData *CreateMailData(HeapID heapId);

#endif // POKEBW2_PML_MAIL_H
