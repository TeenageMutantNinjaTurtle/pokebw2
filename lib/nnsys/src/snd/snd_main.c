#include "snd_internal.h"
#include "nitro/os.h"

// NitroSystem's sound library setup and its work each frame (NNS_Snd), and the copy of the ARM7 driver's state that
// it reads the driver's info from. The file name is a guess, from NitroSystem's names for its sound files. swan names
// NNS_SndInit and NNS_SndMain sndInit and sndSync

// Two copies of the driver's state: one the library reads, the other the ARM7 writes. sCurDriverInfo is the one to
// read, or -1 before the first copy has arrived
static SNDDriverInfo sDriverInfo[2] ATTRIBUTE_ALIGN(32);
static s8 sCurDriverInfo;
static BOOL sDriverInfoFirstFlag;
static u32 sDriverInfoCommandTag;
static PMSleepCallbackInfo sPostSleepCallback;
static PMSleepCallbackInfo sPreSleepCallback;

static void BeginSleep(void *arg);
static void EndSleep(void *arg);

static inline const SNDDriverInfo *GetCurrentDriverInfo(void) {
    if (sCurDriverInfo < 0) {
        return NULL;
    }
    return &sDriverInfo[sCurDriverInfo];
}

void NNS_SndInit(void) {
    static BOOL initialized = FALSE;

    if (initialized) {
        return;
    }
    initialized = TRUE;

    func_0207d670();

    PM_SetSleepCallbackInfo(&sPreSleepCallback, BeginSleep, NULL);
    PM_SetSleepCallbackInfo(&sPostSleepCallback, EndSleep, NULL);
    func_0207f5e8(&sPreSleepCallback);
    func_0207f600(&sPostSleepCallback);

    NNSi_SndInitResourceMgr();
    NNSi_SndCaptureInit();
    NNSi_SndPlayerInit();

    sCurDriverInfo = -1;
    sDriverInfoFirstFlag = TRUE;
}

void NNS_SndMain(void) {
    while (func_0207d73c(SND_COMMAND_NOBLOCK)) {
    }

    NNSi_SndPlayerMain();
    NNSi_SndCaptureMain();
    func_0206ddac();

    func_0207d864(SND_COMMAND_NOBLOCK);
}

void func_0206b954(int volume) {
    sndSetMasterVolume(volume);
}

void NNS_SndSetMonoFlag(BOOL flag) {
    if (flag) {
        func_0207d5d0(SND_CHANNEL_PAN_CENTER);
    } else {
        func_0207d5e4();
    }
}

BOOL NNS_SndUpdateDriverInfo(void) {
    if (!sDriverInfoFirstFlag) {
        while (func_0207d73c(SND_COMMAND_NOBLOCK)) {
        }
        if (!func_0207d9d0(sDriverInfoCommandTag)) {
            return FALSE;
        }

        if (sCurDriverInfo < 0) {
            sCurDriverInfo = 1;
        }
        func_0207d5f8(&sDriverInfo[sCurDriverInfo]);
        sDriverInfoCommandTag = sndGetSentPacketCount();

        if (sCurDriverInfo == 0) {
            sCurDriverInfo = 1;
        } else {
            sCurDriverInfo = 0;
        }
        cp15_invalidateDC(&sDriverInfo[sCurDriverInfo], sizeof(SNDDriverInfo));

        func_0207d864(SND_COMMAND_NOBLOCK);
        return TRUE;
    }

    func_0207d5f8(&sDriverInfo[0]);
    sDriverInfoCommandTag = sndGetSentPacketCount();
    sDriverInfoFirstFlag = FALSE;
    return FALSE;
}

BOOL NNSi_SndReadDriverTrackInfo(int playerNo, int trackNo, SNDTrackInfo *trackInfo) {
    const SNDDriverInfo *driverInfo = GetCurrentDriverInfo();

    if (!driverInfo) {
        return FALSE;
    }
    return func_0207dc0c(driverInfo, playerNo, trackNo, trackInfo);
}

// Before sleep, the capture and every channel stop, and the commands are sent and waited for
static void BeginSleep(void *arg) {
    u32 tag;

    NNSi_SndCaptureBeginSleep();
    func_0207d410(0, 0, 0, 0);

    tag = sndGetSentPacketCount();
    func_0207d864(SND_COMMAND_BLOCK);
    func_0207d96c(tag);
}

static void EndSleep(void *arg) {
    NNSi_SndCaptureEndSleep();
}
