#ifndef POKEBW2_GFL_SOUND_H
#define POKEBW2_GFL_SOUND_H

#include "types.h"

void GFL_SndBGMFadeIn(u32 frames);
void GFL_SndBGMFadeOut(u32 frames);
u32 GFL_SndBGMGetID(void);
// Leaves every channel of the sequence enabled
#define SND_CHANNEL_MASK_ALL 0xffff
#define SND_VOLUME_MAX 127
#define SND_PLAYER_MASK_ALL 0x3f

void GFL_SndBGMPlay(u32 bgm, u32 channelMask);
void GFL_SndBGMPop(void);
void GFL_SndBGMPush(void);
void GFL_SndBGMSetPaused(BOOL paused);
void GFL_SndDestroyHeap(void);
void GFL_SndInit(void);
void GFL_SndPlayerSetVolumeEx(u32 volume, u32 playerMask);
void GFL_SndSEPlay(u16 se);
void GFL_SndSetVolumeControlCallbacks(void);
void PokeVoice_ResetMasterVolume(void);
void PokeVoice_SetMasterVolume(u32 volume);

#endif // POKEBW2_GFL_SOUND_H
