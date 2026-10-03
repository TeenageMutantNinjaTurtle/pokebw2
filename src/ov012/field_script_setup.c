#include "field/event_data.h"
#include "field/field_script.h"
#include "field/field_script_plugin.h"
#include "field/field_script_event.h"
#include "field/field_script_supervisor.h"
#include "field/zone.h"
#include "gfl/std.h"
#include "save/event_work.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/vm.h"

void FieldScript_ResetMapLocalEvents(EventWork *eventWork) {
    EventWork_FlagResetRange(eventWork, 0, 0x63);
    EventWork_WorkResetRange(eventWork, 0x4000, 0x401f);
}

void FieldScript_CallPlayerInitSetup(GameSystem *gsys, u32 a1) {
    FieldScript_Run(gsys, NULL, 0x2580, 2);
}

void FieldScript_CallPlayerPostHOFSetup(GameSystem *gsys) {
    FieldScript_Run(gsys, NULL, 0x2581, 2);
}

void FieldScript_Run(GameSystem *gsys, ScriptWork *work, u16 scriptId, u32 featureLevel) {
    ScriptWork *owned;
    u16 zoneId;
    VM *vm;

    owned = NULL;
    if (work == NULL) {
        owned = ScriptWork_Create(4, gsys, NULL, scriptId, 0, featureLevel);
        work = owned;
    }
    zoneId = FieldScript_GetZoneIDFromGSys(gsys);
    vm = FieldScript_CreateVM(4, work, zoneId, scriptId, featureLevel);
    while (VM_Run(vm) == 1) {
    }
    FieldScript_FreeVM(vm);
    if (owned != NULL) {
        ScriptWork_Free(owned);
    }
}

u32 FieldScript_CallZoneInitCore(GameSystem *gsys, u32 arg1, u32 mode, u32 featureLevel) {
    GameData *gameData;
    EventData *eventData;
    const u8 *script;
    u16 scriptId;
    u32 result;

    result = 0;
    gameData = GSYS_GetGameData(gsys);
    eventData = GameData_GetEventData(gameData);
    script = GetZoneInitScrPointer(eventData);
    do {
        script = FieldScript_GetInitSCRID(script, mode, &scriptId);
        if (scriptId != 0xffff) {
            FieldScript_Run(gsys, NULL, scriptId, featureLevel);
            result = 1;
        }
    } while (scriptId != 0xffff);
    return result;
}

void FieldScript_CallOnZoneReload(GameSystem *gsys, u32 arg1) {
    FieldScript_CallZoneInitCore(gsys, arg1, 4, 1);
}

void FieldScript_CallOnZoneNewLoad(GameSystem *gsys, u32 arg1) {
    FieldScript_CallZoneInitCore(gsys, arg1, 3, 1);
}

void FieldScript_CallOnZoneInit(GameSystem *gsys, u32 arg1) {
    GameData *gameData;
    EventWork *eventWork;

    gameData = GSYS_GetGameData(gsys);
    eventWork = GameData_GetEventWork(gameData);
    FieldScript_ResetMapLocalEvents(eventWork);
    FieldScript_CallZoneInitCore(gsys, arg1, 2, 2);
}

GameEvent *FieldScript_CheckSceneChangeEvent(GameSystem *gsys, HeapID heapId) {
    GameData *gameData;
    EventData *eventData;
    u16 scriptId;

    gameData = GSYS_GetGameData(gsys);
    eventData = GameData_GetEventData(gameData);
    scriptId = FieldScript_GetSceneChangeSCRID(gameData, GetZoneInitScrPointer(eventData), 1);
    if (scriptId == 0xffff) {
        return NULL;
    }
    return EventScriptCall_Create(gsys, scriptId, NULL, heapId);
}

const u8 *FieldScript_GetInitSCRID(const u8 *script, u32 mode, u16 *scriptId) {
    u16 type;
    u16 value;

    while (TRUE) {
        type = script[0] + (script[1] << 8);
        if (type == 0) {
            *scriptId = 0xffff;
            return script;
        }
        if (mode == type) {
            value = script[2] + (script[3] << 8);
            *scriptId = value;
            return script + 6;
        }
        script += 6;
    }
}

u16 FieldScript_GetSceneChangeSCRID(GameData *gameData, const u8 *script, u32 mode) {
    EventWork *eventWork;
    u16 type;
    u16 workId;
    u16 value;
    u32 offset;

    while (TRUE) {
        type = script[0] + (script[1] << 8);
        if (type == 0) {
            return 0xffff;
        }
        if (mode == type) {
            offset = script[2] + (script[3] << 8) + (script[4] << 16) + (script[5] << 24);
            script += 6;
            break;
        }
        script += 6;
    }
    if (offset == 0) {
        return 0xffff;
    }
    script += offset;
    eventWork = GameData_GetEventWork(gameData);
    while (TRUE) {
        workId = script[0] + (script[1] << 8);
        if (workId == 0) {
            return 0xffff;
        }
        // The original parser checks the terminator again before reading the entry.
        if (workId == 0) {
            return 0xffff;
        }
        value = script[2] + (script[3] << 8);
        if (*EventWork_GetWkPtr(eventWork, workId) == value) {
            return script[4] + (script[5] << 8);
        }
        script += 6;
    }
}

VM *FieldScript_CreateVM(HeapID heapId, ScriptWork *work, u16 zoneId, u16 scriptId, u32 featureLevel) {
    FieldScriptEnvArgs args;
    VMInitParam param;
    FieldScriptEnv *env;
    GameSystem *gsys;
    GameData *gameData;
    VM *vm;
    u16 fileId;
    u16 msgArcId;
    u16 msgFileNo;
    u32 scriptOffset;
    u32 reduced;
    u32 workSize;

    reduced = FieldScript_IsVMFeatureSetReduced(featureLevel);
    args.zoneId = zoneId;
    args.unk02 = scriptId;
    args.featureLevel = featureLevel;
    args.reducedFeatureLevel = reduced;
    args.work = work;
    env = CreateFieldScriptEnv(&args, heapId);
    gsys = ScriptWork_GetGameSystem(work);
    gameData = GSYS_GetGameData(gsys);
    param.stackSize = 0x100;
    workSize = 0x40;
    param.workSize = workSize;
    param.commands = (const VMCommand *)EVCMD_TABLE;
    param.commandCount = EVCMD_MAX;
    param.extraCommands = (const VMCommand *)GetCurrentScrPluginTable(gameData);
    param.extraCommandCount = GetCurrentScrPluginCmdCount(gameData);
    param.extraCommandStart = 1000;
    vm = VM_Create(heapId, &param);
    VM_ChangeEnv(vm, env);
    scriptOffset = FieldScript_ResolveSCRID(zoneId, scriptId, &fileId, &msgArcId, &msgFileNo);
    vm->unk38 = (u32)FieldScript_LoadData(fileId, heapId);
    workSize -= 0x41;
    if (!reduced && msgFileNo != workSize) {
        SetFieldScriptEnvMsgData(env, msgArcId, msgFileNo);
    }
    VM_LoadScript(vm, (void *)vm->unk38);
    vm->pc += scriptOffset * 4;
    vm->pc += VM_Read32(vm);
    FieldScript_AttachOpcodeGuard(vm);
    return vm;
}

void FieldScript_FreeVM(VM *vm) {
    FieldScriptEnv *env;

    env = VM_GetEnv(vm);
    FreeFieldScriptEnv(env);
    GFL_HeapFree((void *)vm->unk38);
    VM_Free(vm);
}

u32 FieldScript_ResolveSCRID(u32 zoneId, u16 scriptId, u16 *fileId, u16 *msgArcId, u16 *msgFileNo) {
    u32 i;
    u16 zoneScriptFile;
    u16 zoneTextFile;
    register const GlobalScriptEntry *table;

    table = GLOBAL_SCRIPT_TABLE;
    for (i = 0; i < 60; i++) {
        if (scriptId >= table[i].start) {
            if (scriptId > table[i].end) {
                GFL_DebugAssertFailEx(data_ov012_0216e1a0, 0, data_ov012_0216e1a4, scriptId, table[i].end);
            }
            *fileId = table[i].fileId;
            *msgArcId = table[i].msgArcId;
            *msgFileNo = table[i].msgFileNo;
            return (u16)(scriptId - table[i].start);
        }
    }
    if (scriptId >= 1) {
        zoneScriptFile = ZoneData_GetScriptDatID(zoneId);
        zoneTextFile = ZoneData_GetTextDatID(zoneId);
        *fileId = zoneScriptFile;
        *msgArcId = 3;
        *msgFileNo = zoneTextFile;
        return (u16)(scriptId - 1);
    }
    *fileId = 0x4ce;
    *msgArcId = 3;
    *msgFileNo = 0xd0;
    return 0;
}
