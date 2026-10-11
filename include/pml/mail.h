#ifndef POKEBW2_PML_MAIL_H
#define POKEBW2_PML_MAIL_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"
#include "system/pms_data.h"

#define MAIL_DESIGN_MAX 12
#define MAIL_DESIGN_NONE 0xff
#define MAIL_SENTENCE_MAX 3
#define MAILBOX_MAIL_MAX 20

// Names from swan: MailData, CreateMailData, ResetMailData and copyMailMsg
typedef struct MailData {
    u32 trainerId;
    u8 trainerGender;
    u8 region;
    u8 gameVersion;
    // MAIL_DESIGN_NONE when the mail is empty
    u8 design;
    u16 trainerName[8];
    u16 unk18[3];
    u16 unk1E;
    PMSData sentences[MAIL_SENTENCE_MAX];
} MailData; // size: 0x38

// The save block of mail
struct MailBox {
    MailData mails[MAILBOX_MAIL_MAX];
}; // size: 0x460

// Allocates a blank mail
MailData *CreateMailData(HeapID heapId);
// Empties the mail
void ResetMailData(MailData *mail);
// Whether the mail has a design, so is not empty
BOOL func_020096a8(MailData *mail);
void copyMailMsg(const MailData *src, MailData *dest);
// Empties the mail and gives it the design and the player as its author
void func_020096f8(MailData *mail, u8 design, u32 unused, GameData *gameData);
u32 func_02009730(MailData *mail);
u16 *func_02009734(MailData *mail);
// Sets the mail's author's name
void func_02009738(MailData *mail, const u16 *name);
u8 func_0200974c(MailData *mail);
u8 func_02009750(MailData *mail);
void func_02009754(MailData *mail, u32 design);
u8 func_0200975c(MailData *mail);
u8 func_02009760(MailData *mail);
u16 func_02009764(MailData *mail);
void func_02009768(MailData *mail, u16 value);
// The mail's sentences, the first when the index is out of range
PMSData *func_0200976c(MailData *mail, u32 index);
void func_0200977c(MailData *mail, const PMSData *sentence, u32 index);
// The save block of mail, its size and its init
MailBox *func_02009790(GameData *gameData);
u32 func_020097a0(void);
void func_020097a8(MailBox *mailbox);
// The mail of the save's mailbox (box 0, which the functions ignore): the free slot, and clearing, copying and reading
// a slot's mail
s32 func_020097c4(MailBox *mailbox, u32 box);
void func_020097d0(MailBox *mailbox, u32 box, s32 index);
void func_020097e0(MailBox *mailbox, u32 box, s32 index, const MailData *mail);
MailData *func_020097f4(MailBox *mailbox, u32 box, s32 index, HeapID heapId);

#endif // POKEBW2_PML_MAIL_H
