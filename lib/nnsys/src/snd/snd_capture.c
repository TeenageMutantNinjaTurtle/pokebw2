#include "snd_internal.h"
#include "nitro/mi.h"
#include "nitro/os.h"

// NitroSystem's capture (NNSi_SndCapture), which records the mixer's output into a buffer and plays it back on
// channels of its own, for reverb and effects. Only what the sound library's main loop and sleep callbacks call is
// left in the game; the functions that start a capture were stripped. The file name is a guess, from NitroSystem's
// names for its sound files

#define CAPTURE_MSG_NUM 8

static void StopCapture(void);
static void InitMessageQueue(void);

static BOOL sCaptureThreadFlag;
// Read only by code the linker dropped, in a function of it that MWCC doesn't emit, to keep them in the file's .bss
u32 sCaptureReserved;
static OSMessageQueue sMsgQ;
OSMessage sCaptureMsgBuf[CAPTURE_MSG_NUM];

// A stand-in for the code the linker dropped that set the message queue up
static void InitMessageQueue(void) {
    OS_InitMessageQueue(&sMsgQ, sCaptureMsgBuf, CAPTURE_MSG_NUM);
    sCaptureReserved = 0;
}

void NNSi_SndCaptureInit(void) {
    sCaptureThreadFlag = FALSE;
    NNSi_SndCaptureInfo.active = FALSE;
}

void NNSi_SndCaptureMain(void) {
    NNSiSndCaptureInfo *info = &NNSi_SndCaptureInfo;
    NNSSndFader *fader;
    int volume;

    if (!info->active) {
        return;
    }
    if (info->type != NNSi_SND_CAPTURE_TYPE_REVERB) {
        return;
    }

    fader = &info->fader;
    NNSi_SndFaderUpdate(fader);
    if (info->fadeStopFlag && NNSi_SndFaderIsFinished(fader)) {
        StopCapture();
        return;
    }

    volume = NNSi_SndFaderGet(fader) >> 8;
    if (volume != info->volume) {
        sndSetVolume(info->chBitMask, volume, SND_CHANNEL_DATASHIFT_NONE);
        info->volume = volume;
    }
}

static void StopCapture(void) {
    NNSiSndCaptureInfo *info = &NNSi_SndCaptureInfo;
    BOOL alarmFlag;
    u32 tag;

    if (!info->active) {
        return;
    }

    alarmFlag = info->alarmNo >= 0 ? TRUE : FALSE;
    func_0207d410(info->chBitMask, info->capBitMask, alarmFlag ? 1 << info->alarmNo : 0, 0);
    if (alarmFlag) {
        tag = sndGetSentPacketCount();
        func_0207d864(SND_COMMAND_BLOCK);
        func_0207d96c(tag);
        while (OS_ReceiveMessage(&sMsgQ, NULL, OS_MESSAGE_NOBLOCK)) {
        }
    }

    if (info->capBitMask) {
        NNS_SndUnlockCapture(info->capBitMask);
    }
    if (info->lockChBitFlag) {
        sndDisableChannels(info->lockChBitFlag);
    }
    if (alarmFlag) {
        func_0206baf8(info->alarmNo);
    }
    if (info->type == NNSi_SND_CAPTURE_TYPE_EFFECT) {
        func_0207d5b4(0, 0, 0, 0);
    }
    info->active = FALSE;
}

void NNSi_SndCaptureBeginSleep(void) {
    NNSiSndCaptureInfo *info = &NNSi_SndCaptureInfo;
    u32 tag;

    if (!info->active) {
        return;
    }
    func_0207d410(info->chBitMask, info->capBitMask, info->alarmNo >= 0 ? 1 << info->alarmNo : 0, 0);

    tag = sndGetSentPacketCount();
    func_0207d864(SND_COMMAND_BLOCK);
    func_0207d96c(tag);
}

void NNSi_SndCaptureEndSleep(void) {
    NNSiSndCaptureInfo *info = &NNSi_SndCaptureInfo;

    if (!info->active) {
        return;
    }
    info->bufPos = 0;
    MI_CpuClear32(info->bufL, info->bufSize);
    MI_CpuClear32(info->bufR, info->bufSize);
    cp15_flushDC(info->bufL, info->bufSize);
    cp15_flushDC(info->bufR, info->bufSize);

    func_0207d3f4(info->chBitMask, info->capBitMask, info->alarmNo >= 0 ? 1 << info->alarmNo : 0, 0);
}
