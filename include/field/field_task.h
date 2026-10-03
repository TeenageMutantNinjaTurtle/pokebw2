#ifndef POKEBW2_FIELD_FIELD_TASK_H
#define POKEBW2_FIELD_FIELD_TASK_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "struct_decls.h"

// A task that the field runs each frame until its callback returns TRUE
typedef struct FieldTask FieldTask;

typedef BOOL (*FieldTaskCallback)(void *data);

// Allocates dataSize bytes of data for the task
FieldTask *FieldTask_Create(HeapID heapId, u32 dataSize, FieldTaskCallback callback);
void *FieldTask_GetData(FieldTask *task);
void FieldTaskManager_AddTask(FieldTaskManager *mgr, FieldTask *task, u32 a2);
FieldTask *FieldActorSpinTask_CreatePlayerAccel(Field *field, u32 duration, u32 direction);
FieldTask *FieldActorSpinTask_CreatePlayer(Field *field, u32 duration, u32 direction);
FieldTask *FieldActorMoveTask_CreatePlayer(Field *field, u32 duration, const VecFx32 *offset);

#endif // POKEBW2_FIELD_FIELD_TASK_H
