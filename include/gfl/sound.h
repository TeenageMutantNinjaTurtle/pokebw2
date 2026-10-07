#ifndef POKEBW2_GFL_SOUND_H
#define POKEBW2_GFL_SOUND_H

#include "types.h"
#include "gfl/heap.h"
#include "nnsys/snd.h"
#include "struct_decls.h"

void GFL_SndBGMFadeIn(u16 frames);
void GFL_SndBGMFadeOut(u16 frames);
u32 GFL_SndBGMGetID(void);
// Sets the volume of the BGM's tracks in trackMask
void GFL_SndBGMSetVolume(u16 trackMask, s32 volume);
// Sets the tempo ratio of the BGM (256 is normal), and the pitch and pan of its tracks in trackMask, each that is
// not -1
void GFL_SndBGMSetParams(u16 trackMask, s32 tempoRatio, s32 pitch, s32 pan);
// The sound handle that plays the BGM
NNSSndHandle *func_02005c94(void);
// The sound heap, which sounds loaded for a while are loaded into above a saved level
NNSSndHeapHandle func_02005ce4(void);
BOOL GFL_SndBGMIsFading(void);
// The tick count of the BGM's sequence player
u32 GFL_SndBGMGetTick(void);
BOOL GFL_SndBGMIsPlaying(void);
// Leaves every channel of the sequence enabled
#define SND_CHANNEL_MASK_ALL 0xffff
#define SND_VOLUME_MAX 127
#define SND_PLAYER_MASK_ALL 0x3f

void GFL_SndBGMPlay(u32 bgm, u32 channelMask);
void GFL_SndBGMStop(u32 bgm);
void GFL_SndBGMPop(void);
void GFL_SndBGMPush(void);
void GFL_SndBGMSetPaused(BOOL paused);
void GFL_SndDestroyHeap(void);
void GFL_SndInit(void);
// The player that plays a sequence
s32 GFL_SndSeqGetPlayerIndex(u32 seq);
BOOL GFL_SndPlayerIsActive(s32 player);
BOOL GFL_SndPlayerIsActiveAny(void);
void GFL_SndPlayerStop(s32 player);
void GFL_SndPlayerSetVolume(s32 player, s32 volume);
// Changes each value that is not -1
void GFL_SndPlayerSetParams(s32 player, s32 a1, s32 a2, s32 a3);
void GFL_SndPlayerSetVolumeEx(u32 volume, u32 playerMask);
void GFL_SndSEPlay(u32 se);
// Plays a sound effect at a volume below 128, or at the sequence's own volume
void GFL_SndSEPlayEx(u32 se, u32 volume);
void GFL_SEPlayKeepVol(u32 se, s32 player);
// Called once with start TRUE for a sequence, then each frame with FALSE until it returns TRUE
BOOL func_02006424(u32 seq, u32 *step, BOOL start);
void func_02005d8c(void);
// Sets the callback that says whether a sequence may play while the sound thread is loading
void GFL_SndSetSeqVerifyCallback(BOOL (*callback)(u32 seq));
BOOL GFL_SndIsPlaying(u32 seq);
void GFL_SndStop(void);
void GFL_SndSetVolumeControlCallbacks(void);
BOOL GFL_SndIsVolumeControlCallbackSet(void);
void GFL_SndPlayerSetMuteStateEx(u32 player, u32 state);
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

// The save's Chatot recording, which a cry of Chatot plays in place of its own
typedef struct {
    void *chatter;
} PokeVoiceChatterInfo;

void PokeVoice_CreateChatterInfo(PokeVoiceChatterInfo *info);

// Cries are played through handles
u32 PokeVoice_Load(u32 species, u32 form, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   const PokeVoiceChatterInfo *chatterInfo);
u32 PokeVoice_Play(u32 species, u32 form, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   const PokeVoiceChatterInfo *chatterInfo);
BOOL PokeVoice_StartPlayback(u32 handle);
BOOL PokeVoice_IsPlaying(u32 handle);
BOOL PokeVoice_IsPlayingAny(void);
void PokeVoice_ReleaseAll(void);
void PokeVoice_Release(u32 handle);
// What a handle plays: its volume, speed, samples, count of samples and sample rate
s8 PokeVoice_GetVolume(u32 handle);
int PokeVoice_GetSpeed(u32 handle);
const s8 *PokeVoice_GetSamples(u32 handle);
u32 PokeVoice_GetSampleCount(u32 handle);
int PokeVoice_GetSampleRate(u32 handle);
void PokeVoice_ResetMasterVolume(void);
void PokeVoice_SetMasterVolume(u32 volume);

// The microphone, which records Chatot's cry: set up, free, and record into a buffer, calling back when done
void setupMic(HeapID heapId);
void ampOffFreeBlocks(void);
void func_02006e0c(u32 a0);
BOOL func_02006e3c(void);
// 0 once the recording has started
u32 func_02006e80(void (*callback)(u32 result, u32 *done), u32 *done);
// Saves the recording as the Chatot's
void func_02006ec0(void *chatter);

// The BGM info archive: which interactive sound subsystem each BGM uses (ISS_SUBSYSTEM_*), or 0 for none
u8 BGMInfo_GetISSSubsystem(BGMInfo *info, u16 bgm);

#endif // POKEBW2_GFL_SOUND_H
