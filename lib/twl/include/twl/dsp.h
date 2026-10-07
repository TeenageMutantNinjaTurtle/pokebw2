#ifndef POKEBW2_TWL_DSP_H
#define POKEBW2_TWL_DSP_H

#include "types.h"
#include "nitro/fs.h"
#include "nitro/os.h"

// TwlSDK's DSP library, in the DSi's LTD autoload, which plays the camera's shutter and video sounds through the
// G.711 component. As with the camera, the SDK's inline functions only call it on a DSi, and its functions keep their
// default names until the LTD autoload is analyzed.

void func_027062c8(void);                               // stops the sound playing
BOOL func_02706174(const void *src, u32 length);        // DSP_PlayShutterSoundCore
BOOL func_02706324(void);                               // DSP_IsShutterSoundPlayingCore
BOOL func_0270723c(FSFile *file);                       // DSP_OpenStaticComponentG711Core
BOOL func_02707278(FSFile *file, int slotB, int slotC); // DSP_LoadG711Core
void func_027072e0(void);                               // DSP_UnloadG711Core

static inline void DSP_StopSound(void) {
    if (hw_isDSi()) {
        func_027062c8();
    }
}

static inline BOOL DSP_PlayShutterSound(const void *src, u32 length) {
    if (hw_isDSi()) {
        return func_02706174(src, length);
    }
    return FALSE;
}

static inline BOOL DSP_IsShutterSoundPlaying(void) {
    BOOL playing = FALSE;
    if (hw_isDSi()) {
        playing = func_02706324();
    }
    return playing;
}

static inline BOOL DSP_OpenStaticComponentG711(FSFile *file) {
    if (hw_isDSi()) {
        return func_0270723c(file);
    }
    return FALSE;
}

static inline BOOL DSP_LoadG711(FSFile *file, int slotB, int slotC) {
    if (hw_isDSi()) {
        return func_02707278(file, slotB, slotC);
    }
    return FALSE;
}

static inline void DSP_UnloadG711(void) {
    if (hw_isDSi()) {
        func_027072e0();
    }
}

#endif // POKEBW2_TWL_DSP_H
