#ifndef POKEBW2_FIELD_TRIAL_HOUSE_H
#define POKEBW2_FIELD_TRIAL_HOUSE_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/heap.h"
#include "system/game_event.h"
#include "struct_decls.h"

struct TrialHouseWork {
    u8 unk00[0x120];
    u16 heapId;
    u8 unk122[2];
    u32 capacity;
    PokeParty *party;
    u32 battleType;
    u32 selectionFlag;
    u8 unk134[0x18];
    void *saveBuffer;
    u32 initState;
};

struct TrialHouseEventData {
    u32 code;
    u8 flag4;
    u8 pad5;
    u16 id;
    u32 size;
    void *saveBuffer;
    u32 region;
    u32 mask;
    u8 pad18[0x60];
    u32 active;
    void *subwork;
    GameSystem *gsys;
    TrialHouseWork *work;
    u16 *result;
    s32 timeout;
};

struct TrialHouseEffectEvent {
    GameSystem *gsys;
    void *buffer;
    u32 mode;
    void *effect;
};

extern const char data_ov033_0217c630[];

struct TrialHouseWork *CreateTrialHouseWk(GameSystem *gsys);
void func_ov033_0217acd4(GameSystem *gsys, struct TrialHouseWork *work);
void TrialHouseWorkDelete(void *unused, struct TrialHouseWork **work);
void func_ov033_0217adbc(TrialHouseWork *work, u32 selectionFlag);
void func_ov033_0217adc4(GameSystem *gsys, TrialHouseWork *work, u32 mode);
void func_ov033_0217ade8(TrialHouseWork *work, u32 mode);
void func_ov033_0217ae5c(GameSystem *gsys, TrialHouseWork *work, u32 mode);
u32 func_ov033_0217aed0(TrialHouseWork *work);
GameEvent *func_ov033_0217aedc(GameSystem *gsys, TrialHouseWork *work, u32 actorId, u32 messageId);
GameEvent *func_ov033_0217aee8(GameSystem *gsys, TrialHouseWork *work, u32 arg);
GameEventReturnCode func_ov033_0217af5c(GameEvent *event, u32 *state, void *data);
GameEvent *func_ov012_02161e6c(GameSystem *gsys, TrialHouseWork *work, u32 actorId, u16 messageId);
void *func_ov012_02162864(TrialHouseWork *work, u16 value, u32 capacity, u32 arg3, u32 arg4, u32 arg5, u16 flag);
void *func_ov012_02152990(TrialHouseEventData *data);
BOOL func_ov012_02152b64(void *work);
void func_ov012_02152bec(void *work);
BOOL func_ov012_02152bb4(void *work);
BOOL func_ov012_02152bd4(void *work);
void func_ov012_02152bfc(void *work);
u8 func_ov033_0217b35c(void *save, u32 value);
void func_ov033_0217b384(void *save, u32 value);
u32 func_ov033_0217b2e4(u32 unused, TrialHouseWork *work);
GameEvent *func_ov033_0217b2ec(GameSystem *gsys, u32 unused, u32 mode);
u32 func_ov033_0217b32c(GameSystem *gsys);
GameEventReturnCode func_ov033_0217b3ac(GameEvent *event, u32 *state, void *data);

#endif // POKEBW2_FIELD_TRIAL_HOUSE_H
