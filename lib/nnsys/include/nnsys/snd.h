#ifndef POKEBW2_NNSYS_SND_H
#define POKEBW2_NNSYS_SND_H

#include "types.h"

// NitroSystem's sound players (NNS_Snd)

// Sets a sound player's volume, 0 to 127. That it is NitroSystem's NNS_SndPlayerSetPlayerVolume is a guess from its
// code
void func_0206bd3c(int playerNo, int volume);

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

#endif // POKEBW2_NNSYS_SND_H
