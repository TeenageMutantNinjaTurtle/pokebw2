#include "snd_internal.h"

// NitroSystem's wave output (NNS_SndWaveOut), which plays raw samples on a channel locked for it. The file name is a
// guess, from NitroSystem's names for its sound files. swan names NNS_SndWaveOutAllocChannel,
// NNS_SndWaveOutFreeChannel, NNS_SndWaveOutStart, NNS_SndWaveOutStop and NNS_SndWaveOutIsPlaying
// NNS_SndWaveOutAllocChannel, NNS_SndWaveOutFreeChannel, NNS_SndWaveOutStart, NNS_SndWaveOutStop and
// NNS_SndWaveOutIsPlaying, and NNS_SndWaveOutSetVolume and NNS_SndWaveOutSetSpeed NNS_SndWaveOutSetVolume and
// NNS_SndWaveOutSetSpeed

#define SND_CHANNEL_NUM 16

#define NNS_SND_WAVE_FORMAT_PCM8 0
#define NNS_SND_WAVE_FORMAT_ADPCM 2

// startFlag is set once the driver has started the channel, after the command tagged commandTag
typedef struct NNSSndWaveOut {
    int chNo;
    int sampleRate;
    BOOL playFlag;
    BOOL startFlag;
    u32 commandTag;
} NNSSndWaveOut;

static NNSSndWaveOut sWaveOut[SND_CHANNEL_NUM];

// The channel timer that plays sampleRate samples a second at speed, a ratio with 0x8000 for 1
static inline int CalcTimer(int sampleRate, int speed) {
    u64 timer = (u64)SND_TIMER_CLOCK * 0x8000 / sampleRate / speed;

    if (timer < SND_CHANNEL_TIMER_MIN) {
        timer = SND_CHANNEL_TIMER_MIN;
    } else if (timer > SND_CHANNEL_TIMER_MAX) {
        timer = SND_CHANNEL_TIMER_MAX;
    }
    return timer;
}

NNSSndWaveOutHandle NNS_SndWaveOutAllocChannel(int chNo) {
    NNSSndWaveOut *waveOut;

    if (!NNS_SndLockChannel(1 << chNo)) {
        return NULL;
    }
    waveOut = &sWaveOut[chNo];
    waveOut->chNo = chNo;
    waveOut->playFlag = FALSE;
    return waveOut;
}

void NNS_SndWaveOutFreeChannel(NNSSndWaveOutHandle handle) {
    NNSSndWaveOut *waveOut = handle;

    NNS_SndUnlockChannel(1 << waveOut->chNo);
}

BOOL NNS_SndWaveOutStart(NNSSndWaveOutHandle handle, int format, const void *data, BOOL loop, int loopStartSample,
                         int samples, int sampleRate, int volume, int speed, int pan) {
    NNSSndWaveOut *waveOut = handle;
    int loopStart;
    int loopLen;
    int timer;

    switch (format) {
    case NNS_SND_WAVE_FORMAT_PCM8:
        loopStart = loopStartSample >> 2;
        loopLen = (samples >> 2) - loopStart;
        break;
    case NNS_SND_WAVE_FORMAT_PCM16:
        loopStart = loopStartSample >> 1;
        loopLen = (samples >> 1) - loopStart;
        break;
    case NNS_SND_WAVE_FORMAT_ADPCM:
        loopStart = loopStartSample >> 3;
        loopLen = (samples >> 3) - loopStart;
        break;
    }

    timer = CalcTimer(sampleRate, speed);
    sndQueuePacket_PlaySamples(waveOut->chNo, format, data, loop ? SND_CHANNEL_LOOP_REPEAT : SND_CHANNEL_LOOP_1SHOT,
                               loopStart, loopLen, volume, SND_CHANNEL_DATASHIFT_NONE, timer, pan);
    func_0207d3f4(1 << waveOut->chNo, 0, 0, 0);

    waveOut->playFlag = TRUE;
    waveOut->startFlag = FALSE;
    waveOut->commandTag = sndGetSentPacketCount();
    waveOut->sampleRate = sampleRate;
    return TRUE;
}

void NNS_SndWaveOutStop(NNSSndWaveOutHandle handle) {
    NNSSndWaveOut *waveOut = handle;

    if (waveOut->playFlag) {
        func_0207d410(1 << waveOut->chNo, 0, 0, 0);
        waveOut->playFlag = FALSE;
    }
}

void NNS_SndWaveOutSetVolume(NNSSndWaveOutHandle handle, int volume) {
    NNSSndWaveOut *waveOut = handle;

    if (waveOut->playFlag) {
        sndSetVolume(1 << waveOut->chNo, volume, SND_CHANNEL_DATASHIFT_NONE);
    }
}

void NNS_SndWaveOutSetSpeed(NNSSndWaveOutHandle handle, int speed) {
    NNSSndWaveOut *waveOut = handle;

    if (waveOut->playFlag) {
        sndSetRate(1 << waveOut->chNo, CalcTimer(waveOut->sampleRate, speed));
    }
}

BOOL NNS_SndWaveOutIsPlaying(NNSSndWaveOutHandle handle) {
    NNSSndWaveOut *waveOut = handle;

    if (!waveOut->playFlag) {
        return FALSE;
    }
    if (!waveOut->startFlag) {
        if (!func_0207d9d0(waveOut->commandTag)) {
            return TRUE;
        }
        waveOut->startFlag = TRUE;
    }
    if (func_0207dbd0() & (1 << waveOut->chNo)) {
        return TRUE;
    }
    waveOut->playFlag = FALSE;
    return FALSE;
}

void NNS_SndWaveOutWaitForChannelStop(NNSSndWaveOutHandle handle) {
    NNSSndWaveOut *waveOut = handle;
    u32 tag;

    if (!waveOut->playFlag) {
        if (func_0207dbd0() & (1 << waveOut->chNo)) {
            tag = sndGetSentPacketCount();
            func_0207d864(SND_COMMAND_BLOCK);
            func_0207d96c(tag);
        }
        return;
    }
    if (!waveOut->startFlag) {
        func_0207d96c(waveOut->commandTag);
        waveOut->startFlag = TRUE;
    }
    while (func_0207dbd0() & (1 << waveOut->chNo)) {
    }
}
