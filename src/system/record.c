#include "types.h"
#include "save/records.h"
#include "gfl/std.h"
#include "nitro/mi.h"
#include "nitro/os.h"
#include "save/save_control.h"

// The game's record counters: 0x47 that count to 999,999,999 and 0x60 that are u16, each capped by its class in
// sRecordClass. The block is encrypted whenever it is not being read, with a key drawn from the VBlank counter when
// a game begins. The ROM has no string for the file, so the name is a guess (swan's names are TrainerCardInfoBlk
// for the block and Record* for the counters). Block 0x26.

#define SAVE_BLOCK_RECORDS 0x26

#define RECORD_LARGE_MAX 0x47
#define RECORD_MAX (RECORD_LARGE_MAX + 0x60)
#define RECORD_CLASS_MAX 6

#define RECORD_TRIAL_HOUSE_RANK 0x7b
#define RECORD_TRIAL_HOUSE_POINTS 0x7c

// Both take the id of the record being touched and do nothing for record 0
static void EncryptRecordStorage(GameRecords *records, u32 id);
static void DecryptRecordStorage(GameRecords *records, u32 id);
static u32 GetRecordCounter(GameRecords *records, s32 id);
static u32 SetRecordCounter(GameRecords *records, s32 id, u32 value);
static u32 GetRecordCounterMax(s32 id);

// The best record and the current streak it is updated from, per pair
static const u16 sRecordStreaks[5][2] = {
    { 0x1a, 0x1b },
    { 0x51, 0x52 },
    { 0x53, 0x54 },
    { 0x55, 0x56 },
    { 0x57, 0x58 },
};

// The cap of each class of record
static const u32 nines[RECORD_CLASS_MAX] = { 999999999, 999999, 65535, 9999, 999, 6 };

// The class of each record
static u8 sRecordClass[RECORD_MAX] = {
    0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3,
    3, 3, 3, 3, 3, 3, 2, 3, 4, 3, 3, 5, 3, 3, 3, 3,
    3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2,
};

u32 func_020093d0(void) {
    return sizeof(GameRecords);
}

void initTrainerCardInfoBlk(GameRecords *records) {
    sys_memset32(0, records, sizeof(GameRecords));
    records->key = (OS_GetVBlankCount() << 8) | OS_GetVBlankCount();
    EncryptRecordStorage(records, 1);
}

GameRecords *getTrainerCardInfoBlkAddress(SaveControl *save) {
    return SaveControl_GetBlockPtr(save, SAVE_BLOCK_RECORDS);
}

static void EncryptRecordStorage(GameRecords *records, u32 id) {
    if (id) {
        records->checksum = addUpDataStream((const u8 *)&records->large[1], sizeof(GameRecords) - 8);
        decryptData(&records->large[1], sizeof(GameRecords) - 8, records->checksum + (records->key << 16));
    }
}

static void DecryptRecordStorage(GameRecords *records, u32 id) {
    if (id) {
        _decryptData(&records->large[1], sizeof(GameRecords) - 8, records->checksum + (records->key << 16));
    }
}

static u32 GetRecordCounter(GameRecords *records, s32 id) {
    if (id < RECORD_LARGE_MAX) {
        return records->large[id];
    }
    if (id < RECORD_MAX) {
        return records->small[id - RECORD_LARGE_MAX];
    }
    return 0;
}

static u32 SetRecordCounter(GameRecords *records, s32 id, u32 value) {
    if (id < RECORD_LARGE_MAX) {
        records->large[id] = value;
    } else if (id < RECORD_MAX) {
        records->small[id - RECORD_LARGE_MAX] = value;
    }
    return GetRecordCounter(records, id);
}

static u32 GetRecordCounterMax(s32 id) {
    s32 class;

    // BUG: the bound is checked on the class read from the table, not on the id, so an id of RECORD_MAX or more reads
    // past the table and the first check can never be true
#ifdef BUGFIX
    if (id >= RECORD_MAX) {
        return 0;
    }
    class = sRecordClass[id];
#else
    class = sRecordClass[id];
    if (class >= RECORD_MAX) {
        return 0;
    }
#endif
    if (class >= RECORD_CLASS_MAX) {
        return 0;
    }
    return nines[class];
}

u32 func_020094cc(GameRecords *records, u32 id, u32 value) {
    u32 max = GetRecordCounterMax(id);
    DecryptRecordStorage(records, id);
    if (value < max) {
        value = SetRecordCounter(records, id, value);
    } else {
        value = SetRecordCounter(records, id, max);
    }
    EncryptRecordStorage(records, id);
    return value;
}

u32 func_02009508(GameRecords *records, u32 id, u32 value) {
    u32 max = GetRecordCounterMax(id);
    u32 current;

    DecryptRecordStorage(records, id);
    current = GetRecordCounter(records, id);
    if (value > max) {
        value = max;
    }
    if (current < value) {
        current = SetRecordCounter(records, id, value);
    } else if (current > max) {
        current = SetRecordCounter(records, id, max);
    }
    EncryptRecordStorage(records, id);
    return current;
}

u32 RecordAdd(GameRecords *records, u32 id, u32 value) {
    u32 max = GetRecordCounterMax(id);
    u32 result;

    DecryptRecordStorage(records, id);
    result = GetRecordCounter(records, id);
    if (result + value < max) {
        result = SetRecordCounter(records, id, result + value);
    } else {
        result = SetRecordCounter(records, id, max);
    }
    EncryptRecordStorage(records, id);
    return result;
}

u32 RecordAddOne(GameRecords *records, u32 id) {
    return RecordAdd(records, id, 1);
}

u32 RecordGet(GameRecords *records, u32 id) {
    u32 max = GetRecordCounterMax(id);
    u32 value;

    DecryptRecordStorage(records, id);
    value = GetRecordCounter(records, id);
    EncryptRecordStorage(records, id);
    // The original compares the other way round: the value replaces the maximum when it is within it
    if (value <= max) {
        max = value;
    }
    return max;
}

void func_020095e0(GameRecords *records) {
    u32 i;
    u32 current;

    for (i = 0; i < 5; i++) {
        current = sRecordStreaks[i][1];
        func_02009508(records, sRecordStreaks[i][0], RecordGet(records, current));
        func_020094cc(records, current, 0);
    }
}

void func_02009618(GameRecords *records, u8 rank) {
    if (rank < 7) {
        func_02009508(records, RECORD_TRIAL_HOUSE_RANK, rank);
    }
}

u8 func_02009628(GameRecords *records) {
    return RecordGet(records, RECORD_TRIAL_HOUSE_RANK);
}

void func_02009638(GameRecords *records, u32 points) {
    if (points < 9999) {
        func_02009508(records, RECORD_TRIAL_HOUSE_POINTS, points);
    }
}

u32 func_02009650(GameRecords *records) {
    return RecordGet(records, RECORD_TRIAL_HOUSE_POINTS);
}
