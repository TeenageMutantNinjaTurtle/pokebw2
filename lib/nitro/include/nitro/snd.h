#ifndef POKEBW2_NITRO_SND_H
#define POKEBW2_NITRO_SND_H

#include "types.h"

// NitroSDK's sound driver interface (SND), which queues commands for the ARM7's sound driver

// Channels: SND_SetChannelVolume, SND_SetChannelPan and SND_SetupChannelPcm, under swan's names
#define SND_WAVE_FORMAT_PCM8 0
#define SND_WAVE_FORMAT_PCM16 1

#define SND_CHANNEL_LOOP_REPEAT 1

#define SND_CHANNEL_VOLUME_MAX 127
#define SND_CHANNEL_PAN_CENTER 64

void sndSetVolume(u32 chBitMask, int volume, int shift);
void sndSetPan(u32 chBitMask, int pan);
void sndQueuePacket_PlaySamples(int chNo, int format, const void *dataAddr, int loop, int loopStart, int loopLen,
                                int volume, int shift, int timer, int pan);

// Timers and alarms: NitroSDK's SND_StartTimer, SND_StopTimer and SND_SetupAlarm, by their code
typedef void (*SNDAlarmHandler)(void *arg);

void func_0207d3f4(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void func_0207d410(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void func_0207d450(int alarmNo, u32 tick, u32 period, SNDAlarmHandler handler, void *arg);

// Commands: NitroSDK's SND_FlushCommand and SND_WaitForCommandProc by their code, and SND_GetCurrentCommandTag under
// swan's name
#define SND_COMMAND_BLOCK 1

BOOL func_0207d864(u32 flags);
void func_0207d96c(u32 tag);
u32 sndGetSentPacketCount(void);

// NitroSDK's SND_CalcChannelVolume: a volume in decibels as a channel volume in the low byte and a data shift in the
// high one
#define SND_CHANNEL_VOLUME(v) ((u8)(v))
#define SND_CHANNEL_DATASHIFT(v) ((v) >> 8)

u16 func_0207dd2c(int dB);

// Sound data files: a sequence, a bank of instruments and a wave archive, each a binary file with one data block
typedef struct SNDBinaryFileHeader {
    char signature[4];
    u16 byteOrder;
    u16 version;
    u32 fileSize;
    u16 headerSize;
    u16 dataBlocks;
} SNDBinaryFileHeader;

typedef struct SNDBinaryBlockHeader {
    u32 kind;
    u32 size;
} SNDBinaryBlockHeader;

typedef struct SNDSequenceData {
    SNDBinaryFileHeader fileHeader;
    SNDBinaryBlockHeader blockHeader;
    u32 baseOffset;
    u32 data[];
} SNDSequenceData;

typedef struct SNDBankData SNDBankData;
typedef struct SNDWaveData SNDWaveData;

// A wave archive: its waves' offsets in the file. Loaded in the heap, the table holds the waves' addresses
typedef struct SNDWaveArc {
    SNDBinaryFileHeader fileHeader;
    SNDBinaryBlockHeader blockHeader;
    struct SNDWaveArcLink *topLink;
    u32 reserved[7];
    u32 waveCount;
    u32 offsetTable[];
} SNDWaveArc;

// An instrument of a bank, and where SND_GetNextInstData goes on from
#define SND_INST_PCM 1

typedef struct SNDInstParam {
    u16 wave[2];
    u8 original_key;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 pan;
} SNDInstParam;

typedef struct SNDInstData {
    u8 type;
    u8 padding_;
    SNDInstParam param;
} SNDInstData;

typedef struct SNDInstPos {
    u32 prgNo;
    u32 index;
} SNDInstPos;

// NitroSDK's SND_InvalidateSeqData, SND_InvalidateBankData and SND_InvalidateWaveData, which stop what plays from the
// range, then SND_AssignWaveArc, SND_DestroyBank, SND_DestroyWaveArc, SND_GetFirstInstDataPos, SND_GetNextInstData,
// SND_GetWaveDataCount, SND_SetWaveDataAddress and SND_GetWaveDataAddress, by their code
void func_0207d558(const void *start, const void *end);
void func_0207d570(const void *start, const void *end);
void func_0207d588(const void *start, const void *end);
void func_0207dd80(SNDBankData *bank, int index, SNDWaveArc *waveArc);
void func_0207ddfc(SNDBankData *bank);
void func_0207de50(SNDWaveArc *waveArc);
SNDInstPos func_0207de7c(const SNDBankData *bank);
BOOL func_0207de8c(const SNDBankData *bank, SNDInstData *inst, SNDInstPos *pos);
u32 func_0207df80(const SNDWaveArc *waveArc);
void func_0207df84(SNDWaveArc *waveArc, int index, const SNDWaveData *address);
const SNDWaveData *func_0207dfa4(const SNDWaveArc *waveArc, int index);

// The driver: NitroSDK's SND_Init, SND_RecvCommandReply, which returns the next command the ARM7 is done with or NULL,
// and SND_IsFinishedCommandTag, by their code
#define SND_COMMAND_NOBLOCK 0

typedef struct SNDCommand SNDCommand;

void func_0207d670(void);
SNDCommand *func_0207d73c(u32 flags);
BOOL func_0207d9d0(u32 tag);

// Sequences on a player: NitroSDK's SND_StopSeq, SND_PrepareSeq, SND_StartPreparedSeq, SND_PauseSeq,
// SND_SetPlayerTempoRatio, SND_SetPlayerVolume and SND_SetPlayerChannelPriority, by their code
void func_0207d300(int playerNo);
void func_0207d314(int playerNo, const void *seqBase, u32 seqOffset, const SNDBankData *bank);
void func_0207d330(int playerNo);
void func_0207d344(int playerNo, BOOL flag);
void func_0207d35c(int playerNo, int ratio);
void func_0207d36c(int playerNo, int volume);
void func_0207d37c(int playerNo, int prio);

// The tracks of a player: NitroSDK's SND_SetTrackVolume, SND_SetTrackPitch, SND_SetTrackPan, SND_SetTrackModDepth and
// SND_SetTrackModSpeed (the depth and speed of the track's LFO), then SND_SetTrackAllocatableChannel, SND_SetTrackMute
// and SND_SetTrackMuteEx, by their code
void func_0207d38c(int playerNo, u32 trackBitMask, int volume);
void func_0207d39c(int playerNo, u32 trackBitMask, int pitch);
void func_0207d3ac(int playerNo, u32 trackBitMask, int pan);
void func_0207d3bc(int playerNo, u32 trackBitMask, int depth);
void func_0207d3cc(int playerNo, u32 trackBitMask, int speed);
void func_0207d3dc(int playerNo, u32 trackBitMask, u32 chBitFlag);
void func_0207d474(int playerNo, u32 trackBitMask, BOOL flag);
void func_0207d494(int playerNo, u32 trackBitMask, int muteType);

// NitroSDK's SND_LockChannel and SND_UnlockChannel, by their code; SND_SetChannelTimer and SND_SetMasterVolume under
// swan's names; SND_SetOutputSelector, SND_SetMasterPan and SND_ResetMasterPan by their code
#define SND_CHANNEL_TIMER_MIN 0x10
#define SND_CHANNEL_TIMER_MAX 0xffff
#define SND_CHANNEL_LOOP_1SHOT 2
#define SND_CHANNEL_DATASHIFT_NONE 0
// The channels' timer clock, half the system clock
#define SND_TIMER_CLOCK 16756991

void func_0207d4ac(u32 chBitMask, u32 flags);
void func_0207d4c4(u32 chBitMask, u32 flags);
void sndSetRate(u32 chBitMask, int timer);
void sndSetMasterVolume(int volume);
void func_0207d5b4(int left, int right, int channel1, int channel3);
void func_0207d5d0(int pan);
void func_0207d5e4(void);

// What the driver reports: NitroSDK's SND_ReadDriverInfo, which copies the driver's state to info,
// SND_GetPlayerStatus and SND_GetChannelStatus, bit masks of the players and channels at work, and SND_ReadTrackInfo
// from a copied state, by their code, and SND_GetPlayerTickCounter. Only the size of the driver's state is used here
typedef struct SNDDriverInfo {
    u8 data[0x11e0];
} SNDDriverInfo;

typedef struct SNDTrackInfo SNDTrackInfo;

void func_0207d5f8(SNDDriverInfo *info);
u32 func_0207dbb8(void);
u32 func_0207dbd0(void);
u32 SND_GetPlayerTickCounter(int playerNo);
BOOL func_0207dc0c(const SNDDriverInfo *driverInfo, int playerNo, int trackNo, SNDTrackInfo *trackInfo);

// The volume in decibels, as a player or track takes it, of each linear volume 0 to 127. NitroSDK's
// SNDi_DecibelTable, under swan's name
extern const s16 VOLUME_DB_TABLE[128];

#endif // POKEBW2_NITRO_SND_H
