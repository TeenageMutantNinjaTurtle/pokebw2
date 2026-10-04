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
// Empties the mail
void ResetMailData(MailData *mail);
// The size of the save block of mail (func_02009790), and putting a mail in a slot of it
u32 func_020097a0(void);
void func_020097e0(void *block, u32 a1, int slot, MailData *mail);
// Sets the name of the mail's writer
void func_02009738(MailData *mail, const u16 *name);

#endif // POKEBW2_PML_MAIL_H
