#ifndef POKEBW2_GFL_SOUND_H
#define POKEBW2_GFL_SOUND_H

#include "types.h"
#include "gfl/heap.h"

void GFL_SndBGMFadeIn(u16 frames);
void GFL_SndBGMFadeOut(u16 frames);
u32 GFL_SndBGMGetID(void);
BOOL GFL_SndBGMIsPlaying(void);
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
// The player that plays a sequence
s32 GFL_SndSeqGetPlayerIndex(u32 seq);
BOOL GFL_SndPlayerIsActiveAny(void);
void GFL_SndPlayerStop(s32 player);
void GFL_SndPlayerSetVolume(s32 player, s32 volume);
// Changes each value that is not -1
void GFL_SndPlayerSetParams(s32 player, s32 a1, s32 a2, s32 a3);
void GFL_SndPlayerSetVolumeEx(u32 volume, u32 playerMask);
void GFL_SndSEPlay(u32 se);
void GFL_SndSetVolumeControlCallbacks(void);
// Loads sound sequences ahead of time, and frees them
u32 func_02005af4(const u32 *seqs, u32 count);
void func_02005b60(u32 handle);

// A stream of music, which the title screen plays
void GFL_SndStreamInit(HeapID heapId);
void GFL_SndStreamFree(void);
void GFL_SndStreamUpdate(void);
void GFL_SndStreamPlay(u32 stream);
void GFL_SndStreamStop(void);
BOOL GFL_SndStreamIsPlaying(void);
void GFL_SndStreamFadeStop(u32 frames);

// Cries are played through handles
u32 PokeVoice_Load(u32 species, u32 form, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
u32 PokeVoice_Play(u32 species, u32 form, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
BOOL PokeVoice_StartPlayback(u32 handle);
BOOL PokeVoice_IsPlaying(u32 handle);
void PokeVoice_ResetMasterVolume(void);
void PokeVoice_SetMasterVolume(u32 volume);

#endif // POKEBW2_GFL_SOUND_H
