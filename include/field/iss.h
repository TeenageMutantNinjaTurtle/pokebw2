#ifndef POKEBW2_FIELD_ISS_H
#define POKEBW2_FIELD_ISS_H

#include "types.h"
#include "struct_decls.h"

void ISSSwitchSys_ResetSwitches(ISSSwitchSys *switchSys);
void ISSSwitchSys_ReqSwitchFadeIn(ISSSwitchSys *switchSys, u32 switchIndex);
// Mutes or unmutes a switch's tracks when the BGM is playing, or else when it next plays
void ISSSwitch_ReqSwitchMuteStateChange(ISSSwitchSys *switchSys, u32 switchIndex, BOOL unmute, u32 bgm);
void ISSSwitchSys_ResetMuteStateChangeRequests(ISSSwitchSys *switchSys);
void ISS_ChangeZone(ISS *iss, u16 zoneId);
ISSSwitchSys *ISS_GetSwitchSys(ISS *iss);

#endif // POKEBW2_FIELD_ISS_H
