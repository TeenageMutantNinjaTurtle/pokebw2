#include "types.h"
#include "battle/btl_action.h"
#include "battle/btl_rec.h"
#include "gfl/heap.h"
#include "gfl/std.h"

// A recorded chunk's header byte
static inline u8 MakeHeader(u8 num, u8 type, u8 chapter) {
    return (num & 0xf) | ((chapter & 1) << 7) | ((type & 7) << 4);
}

// What a client records of the server's commands
struct BtlRecorder {
    u16 size;
    u8 overflow;
    // Not used here
    u32 unk04;
    u8 data[0xc00];
    u32 capacity;
};

BtlRecorder *func_ov167_021d45b0(HeapID heapId, u32 type) {
    BtlRecorder *recorder = GFL_HeapAllocate(heapId, sizeof(BtlRecorder), TRUE, "btl_rec.c", 0x67);
    if (type == 0) {
        recorder->capacity = sizeof(recorder->data);
    } else {
        recorder->capacity = 0x164;
    }
    return recorder;
}

void func_ov167_021d45e8(BtlRecorder *recorder) {
    GFL_HeapFree(recorder);
}

void func_ov167_021d45f0(BtlRecorder *recorder, const void *data, u32 size) {
    if (!recorder->overflow) {
        u32 end = recorder->size + (size - 1);
        if (end <= recorder->capacity) {
            sys_memcpy((const u8 *)data + 1, &recorder->data[recorder->size], size - 1);
            recorder->size = end;
        } else {
            recorder->overflow = TRUE;
        }
    }
}

u8 func_ov167_021d4624(const void *data) {
    return *(const u8 *)data;
}

void *func_ov167_021d4628(BtlRecorder *recorder, u32 *size) {
    *size = recorder->size;
    return recorder->data;
}

void func_ov167_021d4630(BtlRecReader *reader, const void *data, u32 size) {
    u32 i;

    reader->data = data;
    reader->size = size;
    reader->error = FALSE;
    for (i = 0; i < 4; i++) {
        reader->pos[i] = 0;
    }
}

void func_ov167_021d4660(BtlRecReader *reader) {
    u32 i;

    for (i = 0; i < 4; i++) {
        reader->pos[i] = 0;
    }
}

BOOL func_ov167_021d4674(BtlRecReader *reader, u8 clientId) {
    u8 header = reader->data[reader->pos[clientId]];
    int type = (header >> 4) & 7;
    u8 chapter = (header >> 7) & 1;

    if (type == 2) {
        reader->pos[clientId]++;
        return chapter;
    }
    return FALSE;
}

BattleAction *func_ov167_021d46a4(BtlRecReader *reader, u8 clientId, u8 *count, u8 *chapter) {
    u32 *pos;

    if (reader->error) {
        func_ov167_021bdc98(reader->actions[clientId]);
        *count = 1;
        *chapter = 0;
        return reader->actions[clientId];
    }

    pos = reader->pos;
    while (pos[clientId] < reader->size) {
        u8 header = reader->data[pos[clientId]];
        u8 num = header & 0xf;
        int type = (header >> 4) & 7;
        *chapter = (header >> 7) & 1;
        pos[clientId]++;
        if (pos[clientId] > reader->size) {
            break;
        }
        if (type == 1) {
            BattleAction *result = NULL;
            u32 i;
            if (num == 0 || num > 4) {
                break;
            }
            for (i = 0; i < num; i++) {
                u8 byte = reader->data[pos[clientId]++];
                u8 id = (byte >> 5) & 7;
                u8 n = byte & 0x1f;
                if (pos[clientId] >= reader->size) {
                    break;
                }
                if (id != clientId) {
                    pos[clientId] += n * sizeof(BattleAction);
                } else {
                    sys_memcpy(&reader->data[pos[clientId]], reader->actions[clientId], n * sizeof(BattleAction));
                    result = reader->actions[clientId];
                    pos[clientId] += n * sizeof(BattleAction);
                    *count = n;
                }
            }
            if (result != NULL) {
                return result;
            }
        } else if (type == 3) {
            func_ov167_021bdc84(reader->actions[clientId]);
            *count = 1;
            *chapter = 0;
            return reader->actions[clientId];
        } else if (type != 2) {
            break;
        }
        if (pos[clientId] >= reader->size) {
            break;
        }
    }

    reader->error = TRUE;
    func_ov167_021bdc98(reader->actions[clientId]);
    *count = 1;
    *chapter = 0;
    return reader->actions[clientId];
}

u32 func_ov167_021d481c(BtlRecReader *reader) {
    u32 pos, chapters;

    pos = 0;
    chapters = 0;
    while (pos < reader->size) {
        u8 header = reader->data[pos++];
        u8 num = header & 0xf;
        int type = (header >> 4) & 7;
        u8 chapter = (header >> 7) & 1;
        if (chapter) {
            chapters++;
        }
        if (pos >= reader->size) {
            break;
        }
        if (type != 1) {
            pos += num;
        } else {
            u32 i;
            for (i = 0; i < num; i++) {
                u8 n = reader->data[pos++] & 0x1f;
                pos += n * sizeof(BattleAction);
                if (pos >= reader->size) {
                    break;
                }
            }
        }
    }
    return chapters;
}

BOOL func_ov167_021d4880(BtlRecReader *reader, u8 clientId) {
    if (!reader->error) {
        u32 pos = reader->pos[clientId];
        if (pos == reader->size) {
            return TRUE;
        }
        return FALSE;
    }
    return TRUE;
}

void func_ov167_021d48a0(BtlRecTool *tool, BOOL chapter) {
    sys_memset(tool, 0, sizeof(BtlRecTool));
    tool->chapter = chapter;
}

void *func_ov167_021d48c4(BtlRecTool *tool, u32 *size, BOOL chapter) {
    tool->data[0] = 4;
    tool->data[1] = MakeHeader(0, 2, chapter);
    *size = 2;
    return tool->data;
}

void func_ov167_021d48e0(BtlRecTool *tool, u8 clientId, const void *actions, u8 count) {
    if (tool->size == 0) {
        tool->type = 1;
        tool->size = 2;
    }
    if (!(tool->clientFlags & (1 << clientId))) {
        u32 bytes = count * sizeof(BattleAction);
        u32 end = tool->size + (bytes + 1);
        if (end <= sizeof(tool->data)) {
            tool->clientFlags |= (1 << clientId);
            tool->numClients++;
            tool->data[tool->size] = (clientId << 5) | count;
            sys_memcpy(actions, &tool->data[tool->size + 1], bytes);
            tool->size = end;
        } else {
            tool->overflow = TRUE;
        }
    }
}

void *func_ov167_021d4958(BtlRecTool *tool, u8 value, u32 *size) {
    if (!tool->overflow) {
        tool->data[0] = value;
        tool->data[1] = MakeHeader(tool->numClients, tool->type, tool->chapter);
        *size = tool->size;
        return tool->data;
    }
    return NULL;
}

void *func_ov167_021d4990(BtlRecTool *tool, u32 *size) {
    tool->data[0] = 0;
    tool->data[1] = MakeHeader(0, 3, FALSE);
    *size = 2;
    return tool->data;
}

void func_ov167_021d49a0(BtlRecTool *tool, const void *data, u32 size) {
    sys_memcpy(data, tool->data, size);
    tool->size = size;
    tool->clientFlags = 0;
    tool->numClients = 0;
    tool->type = 0;
    tool->chapter = 0;
    tool->overflow = 0;
}

BOOL func_ov167_021d49d0(BtlRecTool *tool, u32 *pos, u8 *clientId, u8 *count, void *actions) {
    if (*pos == 0) {
        *pos = 2;
    }
    if (*pos < tool->size) {
        u8 byte = tool->data[*pos];
        u32 bytes;
        *clientId = (byte >> 5) & 7;
        *count = byte & 0x1f;
        bytes = *count * sizeof(BattleAction);
        (*pos)++;
        sys_memcpy(&tool->data[*pos], actions, bytes);
        *pos += bytes;
        return TRUE;
    }
    return FALSE;
}
