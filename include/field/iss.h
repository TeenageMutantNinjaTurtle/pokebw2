#ifndef POKEBW2_FIELD_ISS_H
#define POKEBW2_FIELD_ISS_H

#include "types.h"
#include "struct_decls.h"

void ISSSwitchSys_ResetSwitches(ISSSwitchSys *switchSys);
void ISS_ChangeZone(ISS *iss, u16 zoneId);
ISSSwitchSys *ISS_GetSwitchSys(ISS *iss);

#endif // POKEBW2_FIELD_ISS_H
