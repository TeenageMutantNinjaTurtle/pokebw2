#ifndef POKEBW2_NNSYS_SND_H
#define POKEBW2_NNSYS_SND_H

#include "types.h"

// NitroSystem's sound players (NNS_Snd)

// Sets a sound player's volume, 0 to 127. That it is NitroSystem's NNS_SndPlayerSetPlayerVolume is a guess from its
// code
void func_0206bd3c(int playerNo, int volume);
// Sets the master volume, 0 to 127, through sndSetMasterVolume; NitroSystem's NNS_SndSetMasterVolume by its code
void func_0206b954(int volume);

// NitroSystem's wave output, which plays raw samples on a channel of its own, under swan's names:
// NNS_SndWaveOutAllocChannel, NNS_SndWaveOutFreeChannel, NNS_SndWaveOutStart, NNS_SndWaveOutStop and
// NNS_SndWaveOutIsPlaying

typedef void *NNSSndWaveOutHandle;

#define NNS_SND_WAVE_FORMAT_PCM16 1

NNSSndWaveOutHandle sndLockChannel(int channel);
void sndReleaseChannel(NNSSndWaveOutHandle handle);
BOOL sndPlaySamples(NNSSndWaveOutHandle handle, int format, const void *data, BOOL loop, int loopStart, int samples,
                    int rate, int volume, int speed, int pan);
void sndStopChannel(NNSSndWaveOutHandle handle);
BOOL sndIsChannelPlaying(NNSSndWaveOutHandle handle);

// NitroSystem's sound archive (NNS_SndArc): the info of a sequence, a bank and a wave archive by number, and the
// address of a file of the archive if it is loaded, else NULL

#define NNS_SND_ARC_BANK_TO_WAVEARC_NUM 4
#define NNS_SND_ARC_INVALID_WAVEARC_NO 0xffff

typedef struct NNSSndSeqParam {
    u16 bankNo;
    u8 volume;
    u8 channelPrio;
    u8 playerPrio;
    u8 playerNo;
    u16 reserved;
} NNSSndSeqParam;

typedef struct NNSSndArcSeqInfo {
    u32 fileId;
    NNSSndSeqParam param;
} NNSSndArcSeqInfo;

typedef struct NNSSndArcBankInfo {
    u32 fileId;
    u16 waveArcNo[NNS_SND_ARC_BANK_TO_WAVEARC_NUM];
} NNSSndArcBankInfo;

typedef struct NNSSndArcWaveArcInfo {
    u32 fileId : 24;
    u32 flags : 8;
} NNSSndArcWaveArcInfo;

const NNSSndArcSeqInfo *NNS_SndArcGetSeqInfo(int seqNo);
const NNSSndArcBankInfo *NNS_SndArcGetBankInfo(int bankNo);
const NNSSndArcWaveArcInfo *NNS_SndArcGetWaveArcInfo(int waveArcNo);
const void *NNS_SndArcGetFileAddress(u32 fileId);

#endif // POKEBW2_NNSYS_SND_H
