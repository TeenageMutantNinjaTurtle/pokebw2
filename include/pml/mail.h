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
// Sets the mail's author's name
void func_02009738(MailData *mail, const u16 *name);
// The size of the save block of mail (func_02009790)
u32 func_020097a0(void);
// The mail of the save's mailbox (a1 0) or of a Pokémon: the free slot, and clearing, copying and reading a slot's
// mail
s32 func_020097c4(void *mailbox, u32 box);
void func_020097d0(void *mailbox, u32 box, u32 index);
void func_020097e0(void *mailbox, u32 box, u32 index, MailData *mail);
MailData *func_020097f4(void *mailbox, u32 box, u32 index, HeapID heapId);

#endif // POKEBW2_PML_MAIL_H
