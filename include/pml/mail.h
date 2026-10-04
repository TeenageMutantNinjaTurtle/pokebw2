#ifndef POKEBW2_PML_MAIL_H
#define POKEBW2_PML_MAIL_H

#include "types.h"
#include "gfl/heap.h"

// Names from swan
typedef struct MailData {
    u32 trainerId;
    u8 trainerGender;
    u8 region;
    u8 gameVersion;
    u8 unk07;
    u16 trainerName[8];
    u16 unk18[4];
    u32 unk20[6];
} MailData;

// Allocates a blank mail
MailData *CreateMailData(HeapID heapId);
// Sets the name of the mail's writer
void func_02009738(MailData *mail, const u16 *name);

#endif // POKEBW2_PML_MAIL_H
