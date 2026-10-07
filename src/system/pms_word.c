#include "types.h"
#include "constants/arc.h"
#include "constants/language.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "save/save_control.h"
#include "system/pms_data.h"
#include "system/pms_word.h"

// The words that fill sentences, and the save block of sentences

#define PMS_SAVE_SENTENCE_COUNT 20

struct PMSWordBank {
    u32 heapId;
    MsgData *msgData[PMS_WORD_CATEGORY_COUNT];
};

struct PMSWordSave {
    u32 languageFlags;
    u32 unk4;
    PMSData sentences[PMS_SAVE_SENTENCE_COUNT];
};

typedef struct {
    u8 language;
    // The language's bit in the flags
    u8 flag;
} PMSLanguageFlag;

// Groups of words that count as the same word
typedef struct {
    const u16 *words;
    int count;
} PMSWordGroup;

// The number of words in each category
static const u16 sCategoryWordCounts[PMS_WORD_CATEGORY_COUNT] = {
    0x28c, 0x230, 0x11, 0xa5, 0x2c, 0x26, 0x30, 0x67, 0x2f, 0x20, 0x1a, 0xa, 0x3d,
};

// The message file of each category
static const u16 sCategoryMsgFiles[PMS_WORD_CATEGORY_COUNT] = {
    0x1e6, 0x1e8, 0x1e9, 0x1e7, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa1, 0xa9,
};

static const u16 sWordGroup0[] = { 0x5b3, 0x5a0 };
static const u16 sWordGroup1[] = { 0x5c2, 0x59f, 0x5bf, 0x5c3 };
static const u16 sWordGroup2[] = { 0x5be, 0x5b5 };
static const u16 sWordGroup3[] = { 0x704, 0x6dd };
static const u16 sWordGroup4[] = { 0x708, 0x6d8 };
static const u16 sWordGroup5[] = { 0x5d4, 0x5f2 };
static const u16 sWordGroup6[] = { 0x5cb, 0x5c5 };
static const u16 sWordGroup7[] = { 0x4c9, 0x2ea };
static const u16 sWordGroup8[] = { 0x664, 0x523 };
static const u16 sWordGroup9[] = { 0x685, 0x5ef };
static const u16 sWordGroup10[] = { 0x688, 0x538 };
static const u16 sWordGroup11[] = { 0x6d1, 0x6f2 };
static const u16 sWordGroup12[] = { 0x6e2, 0x6fb };

static const PMSWordGroup sWordGroups[] = {
    { sWordGroup0, NELEMS(sWordGroup0) },   { sWordGroup1, NELEMS(sWordGroup1) },
    { sWordGroup2, NELEMS(sWordGroup2) },   { sWordGroup3, NELEMS(sWordGroup3) },
    { sWordGroup4, NELEMS(sWordGroup4) },   { sWordGroup5, NELEMS(sWordGroup5) },
    { sWordGroup6, NELEMS(sWordGroup6) },   { sWordGroup7, NELEMS(sWordGroup7) },
    { sWordGroup8, NELEMS(sWordGroup8) },   { sWordGroup9, NELEMS(sWordGroup9) },
    { sWordGroup10, NELEMS(sWordGroup10) }, { sWordGroup11, NELEMS(sWordGroup11) },
    { sWordGroup12, NELEMS(sWordGroup12) },
};

static const PMSLanguageFlag sLanguageFlags[] = {
    { LANGUAGE_JAPANESE, 0 }, { LANGUAGE_ENGLISH, 1 }, { LANGUAGE_FRENCH, 2 }, { LANGUAGE_ITALIAN, 3 },
    { LANGUAGE_GERMAN, 4 },   { LANGUAGE_SPANISH, 5 }, { LANGUAGE_KOREAN, 6 },
};

PMSWordBank *PMSWordBank_Create(u32 heapId) {
    int i;
    PMSWordBank *bank = GFL_HeapAllocate(heapId, sizeof(PMSWordBank), FALSE, "pms_word.c", 50);

    for (i = 0; i < PMS_WORD_CATEGORY_COUNT; i++) {
        bank->heapId = heapId;
        bank->msgData[i] = GFL_MsgSysLoadData(FALSE, ARCID_SYSTEM_MESSAGE, sCategoryMsgFiles[i], heapId);
    }
    return bank;
}

void PMSWordBank_Free(PMSWordBank *bank) {
    int i;

    for (i = 0; i < PMS_WORD_CATEGORY_COUNT; i++) {
        GFL_MsgDataFree(bank->msgData[i]);
    }
    GFL_HeapFree(bank);
}

void PMSWordBank_LoadWord(PMSWordBank *bank, u16 word, StrBuf *strbuf) {
    u32 category;
    u32 index;

    PMSWord_GetMessage(word, &category, &index);
    GFL_MsgDataLoadStrbuf(bank->msgData[category], index, strbuf);
}

void loadSayingToString(u16 saying, StrBuf *strbuf, HeapID heapId) {
    u32 fileId;
    u32 index;
    MsgData *msgData;

    if (saying != PMS_WORD_NULL) {
        PMSWord_GetMessage(saying, &fileId, &index);
        // The category becomes its message file in place: a separate variable doesn't match
        fileId = sCategoryMsgFiles[fileId];
        msgData = GFL_MsgSysLoadData(FALSE, ARCID_SYSTEM_MESSAGE, fileId, heapId);
        GFL_MsgDataLoadStrbuf(msgData, index, strbuf);
        GFL_MsgDataFree(msgData);
    } else {
        GFL_StrBufClear(strbuf);
    }
}

u16 PMSWord_FromMessage(u16 fileId, u16 index) {
    u32 i;
    u16 base;
    u16 j;

    for (i = 0; i < PMS_WORD_CATEGORY_COUNT; i++) {
        if (fileId == sCategoryMsgFiles[i]) {
            for (j = 0, base = 0; j < i; j++) {
                base += sCategoryWordCounts[j];
            }
            return base + index;
        }
    }
    return PMS_WORD_NULL;
}

BOOL PMSWord_GetMessage(u32 word, u32 *category, u32 *index) {
    u32 i;
    u32 end;

    word &= PMS_WORD_INDEX_MASK;
    end = 0;
    for (i = 0; i < PMS_WORD_CATEGORY_COUNT; i++) {
        end += sCategoryWordCounts[i];
        if (word < end) {
            *category = i;
            *index = word - (end - sCategoryWordCounts[i]);
            return TRUE;
        }
    }
    return FALSE;
}

PMSData *PMSWordSave_GetSentence(PMSWordSave *save, int index) {
    return &save->sentences[index];
}

void PMSWordSave_SetSentence(PMSWordSave *save, int index, const PMSData *sentence) {
    if (index >= 0 && index < PMS_SAVE_SENTENCE_COUNT) {
        sys_memcpy(sentence, &save->sentences[index], sizeof(PMSData));
    }
}

u32 PMSWordSave_GetSize(void) {
    return sizeof(PMSWordSave);
}

void PMSWordSave_Init(PMSWordSave *save) {
    int i;
    int j;

    save->languageFlags = 0;
    save->unk4 = 0;
    for (i = 0; i < PMS_SAVE_SENTENCE_COUNT; i++) {
        for (j = 0; j < PMS_SENTENCE_WORD_MAX; j++) {
            save->sentences[i].words[j] = PMS_WORD_NULL;
        }
    }
    for (i = 0; i < NELEMS(sLanguageFlags); i++) {
        if (sLanguageFlags[i].language == GAME_LANGUAGE) {
            PMSWordSave_SetLanguageFlag(save, sLanguageFlags[i].flag);
            break;
        }
    }
}

PMSWordSave *getDexBlkAddress(SaveControl *save) {
    return SaveControl_GetBlockPtr(save, SAVE_BLOCK_PMS);
}

BOOL PMSWordSave_GetLanguageFlag(PMSWordSave *save, u32 bit) {
    return (save->languageFlags >> bit) & 1;
}

void PMSWordSave_SetLanguageFlag(PMSWordSave *save, u32 bit) {
    save->languageFlags |= 1 << bit;
}

BOOL PMSWord_AreEquivalent(u16 word, u16 other) {
    u32 i;
    int j;
    int k;

    if (word == other) {
        return TRUE;
    }
    for (i = 0; i < NELEMS(sWordGroups); i++) {
        for (j = 0; j < sWordGroups[i].count; j++) {
            if (word == sWordGroups[i].words[j]) {
                for (k = 0; k < sWordGroups[i].count; k++) {
                    if (other == sWordGroups[i].words[k]) {
                        return TRUE;
                    }
                }
                return FALSE;
            }
        }
    }
    return FALSE;
}
