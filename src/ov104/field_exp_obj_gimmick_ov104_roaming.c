#include "field/encounter.h"
#include "field/field_exp_obj_gimmick_ov104.h"
#include "field/field_script.h"
#include "gfl/sound.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/version.h"

void func_ov104_021efb30(FieldExpObjGimmickOv104Work *work, FieldExpObjGimmickOv104ZoneList *list) {
    EncountSave *save;
    u32 version;
    u32 slot;
    u32 weather;
    u16 zone;

    save = SaveControl_GetEncountSave(GameData_GetSaveControl(work->gameData));
    func_ov104_021ef9f8(list);
    if (func_ov012_02159218(save)) {
        version = getGameVersion();
        switch (version) {
        case 0x16:
            slot = 0;
            break;
        case 0x17:
            slot = 1;
            break;
        }
        switch (slot) {
        case 0:
            weather = 6;
            break;
        case 1:
            weather = 7;
            break;
        }
        zone = EncountSave_GetRoamingPkmZone(save, (u8)slot);
        if (zone != 0xffff) {
            list->zones[0] = zone;
            list->weather[0] = weather;
        }
    }
}

BOOL func_ov104_021efb90(VM *vm, FieldScriptEnv *env) {
    ScriptWork *scriptWork;
    GameSystem *gsys;
    Field *field;
    u32 id;
    GameEvent *event;

    scriptWork = FieldScriptEnv_GetScriptWork(env);
    gsys = FieldScriptEnv_GetGameSystem(env);
    field = GSYS_GetField(gsys);
    id = ScriptReadAny(vm, env);
    GFL_SndSEPlay(0x547);
    event = func_ov104_021f02fc(gsys, field, id);
    ScriptWork_CallEvent(scriptWork, event);
    return TRUE;
}