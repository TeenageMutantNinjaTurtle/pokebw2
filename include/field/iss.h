#ifndef POKEBW2_FIELD_ISS_H
#define POKEBW2_FIELD_ISS_H

#include "types.h"
#include "struct_decls.h"

// A switch of the zone's music. The Battle Subway only fades in switches below ISS_SWITCH_COUNT
typedef enum {
    ISS_SWITCH_COUNT = 9,
} ISSSwitchIndex;

void ISSSwitchSys_ResetSwitches(ISSSwitchSys *switchSys);
void ISSSwitchSys_ReqSwitchFadeIn(ISSSwitchSys *switchSys, ISSSwitchIndex switchIndex);
// Mutes or unmutes a switch's tracks when the BGM is playing, or else when it next plays
void ISSSwitch_ReqSwitchMuteStateChange(ISSSwitchSys *switchSys, ISSSwitchIndex switchIndex, BOOL unmute, u32 bgm);
void ISSSwitchSys_ResetMuteStateChangeRequests(ISSSwitchSys *switchSys);
void ISS_ChangeZone(ISS *iss, u16 zoneId);
ISSSwitchSys *ISS_GetSwitchSys(ISS *iss);

#endif // POKEBW2_FIELD_ISS_H
