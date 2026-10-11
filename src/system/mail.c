#include "types.h"
#include "pml/mail.h"
#include "gfl/heap.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "nitro/mi.h"
#include "save/player_info.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/pms_data.h"
#include "system/version.h"

// Mail: the author, the design and three Easy Chat sentences, and the save block of the mailbox that holds twenty of
// them. The file's name is the ROM's; the function names from swan are marked in mail.h, and the two statics are
// ours. Block 0x28.

#define SAVE_BLOCK_MAILBOX 0x28

static s32 getFreeMailSlot(MailData *mails, s32 count);
static MailData *getMailSlot(MailBox *mailbox, u32 box, s32 index);

void ResetMailData(MailData *mail) {
    s32 i;

    mail->trainerId = 0;
    mail->trainerGender = 0;
    mail->region = region;
    mail->gameVersion = game_version;
    mail->design = MAIL_DESIGN_NONE;
    sys_memset16(GFL_StrBufGetTerminator(), mail->trainerName, sizeof(mail->trainerName));
    mail->unk1E = 0xffff;
    for (i = 0; i < MAIL_SENTENCE_MAX; i++) {
        PMSData_Clear(&mail->sentences[i]);
    }
}

BOOL func_020096a8(MailData *mail) {
    // Written as the original compares it: func_02009754's `< MAIL_DESIGN_MAX` gives bhs here instead of bhi
    if (mail->design <= MAIL_DESIGN_MAX - 1) {
        return TRUE;
    }
    return FALSE;
}

MailData *CreateMailData(HeapID heapId) {
    MailData *mail = GFL_HeapAllocate(HEAPID_TAIL(heapId), sizeof(MailData), FALSE, "mail.c", 135);
    ResetMailData(mail);
    return mail;
}

void copyMailMsg(const MailData *src, MailData *dest) {
    sys_memcpy(src, dest, sizeof(MailData));
}

void func_020096f8(MailData *mail, u8 design, u32 unused, GameData *gameData) {
    PlayerInfo *info;

    ResetMailData(mail);
    mail->design = design;
    info = GetGameDataPlayerInfo(gameData);
    sys_memcpy(GetPlayerName(info), mail->trainerName, sizeof(mail->trainerName));
    mail->trainerGender = getTrainerGender(info);
    mail->trainerId = getIDAsUInt(info);
}

u32 func_02009730(MailData *mail) {
    return mail->trainerId;
}

u16 *func_02009734(MailData *mail) {
    return mail->trainerName;
}

void func_02009738(MailData *mail, const u16 *name) {
    sys_memcpy(name, mail->trainerName, sizeof(mail->trainerName));
}

u8 func_0200974c(MailData *mail) {
    return mail->trainerGender;
}

u8 func_02009750(MailData *mail) {
    return mail->design;
}

void func_02009754(MailData *mail, u32 design) {
    if (design < MAIL_DESIGN_MAX) {
        mail->design = design;
    }
}

u8 func_0200975c(MailData *mail) {
    return mail->region;
}

u8 func_02009760(MailData *mail) {
    return mail->gameVersion;
}

u16 func_02009764(MailData *mail) {
    return mail->unk1E;
}

void func_02009768(MailData *mail, u16 value) {
    mail->unk1E = value;
}

PMSData *func_0200976c(MailData *mail, u32 index) {
    if (index < MAIL_SENTENCE_MAX) {
        return &mail->sentences[index];
    }
    return &mail->sentences[0];
}

void func_0200977c(MailData *mail, const PMSData *sentence, u32 index) {
    if (index < MAIL_SENTENCE_MAX) {
        PMSData_Copy(&mail->sentences[index], sentence);
    }
}

MailBox *func_02009790(GameData *gameData) {
    return SaveControl_GetBlockPtr(GameData_GetSaveControl(gameData), SAVE_BLOCK_MAILBOX);
}

u32 func_020097a0(void) {
    return sizeof(MailBox);
}

void func_020097a8(MailBox *mailbox) {
    s32 i;

    for (i = 0; i < MAILBOX_MAIL_MAX; i++) {
        ResetMailData(&mailbox->mails[i]);
    }
}

s32 func_020097c4(MailBox *mailbox, u32 box) {
    return getFreeMailSlot(mailbox->mails, MAILBOX_MAIL_MAX);
}

void func_020097d0(MailBox *mailbox, u32 box, s32 index) {
    MailData *mail = getMailSlot(mailbox, box, index);
    if (mail != NULL) {
        ResetMailData(mail);
    }
}

void func_020097e0(MailBox *mailbox, u32 box, s32 index, const MailData *mail) {
    MailData *slot = getMailSlot(mailbox, box, index);
    if (slot != NULL) {
        copyMailMsg(mail, slot);
    }
}

MailData *func_020097f4(MailBox *mailbox, u32 box, s32 index, HeapID heapId) {
    MailData *slot = getMailSlot(mailbox, box, index);
    MailData *mail = CreateMailData(heapId);
    if (slot != NULL) {
        copyMailMsg(slot, mail);
    }
    return mail;
}

static s32 getFreeMailSlot(MailData *mails, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        if (!func_020096a8(&mails[i])) {
            return i;
        }
    }
    return -1;
}

static MailData *getMailSlot(MailBox *mailbox, u32 box, s32 index) {
    if (index < MAILBOX_MAIL_MAX) {
        return &mailbox->mails[index];
    }
    return NULL;
}
