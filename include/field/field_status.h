#ifndef POKEBW2_FIELD_FIELD_STATUS_H
#define POKEBW2_FIELD_FIELD_STATUS_H

// Names, layouts and constants from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"

#define FLD_STATUS_BUSY_NONE 0x0
#define FLD_STATUS_BUSY_BATTLE 0x1
#define FLD_STATUS_BUSY_LOADING 0x2

#define FLD_FLASH_NONE 0x0
#define FLD_FLASH_ALLOW 0x1
#define FLD_FLASH_ACTIVE 0x2

BOOL FieldStatus_CheckFlashUsed(FieldStatus *status);
void FieldStatus_SetBusyFlag(FieldStatus *status, u32 flag);
void FieldStatus_SetContinueFlag(FieldStatus *status, BOOL flag);
void FieldStatus_SetFlashPerms(FieldStatus *status, u32 flags);
void FieldStatus_SetInLinkedWorld(FieldStatus *status, BOOL inLinkedWorld);
void FieldStatus_SetNewLoadFlag(FieldStatus *status, BOOL flag);

#endif // POKEBW2_FIELD_FIELD_STATUS_H
