#include "field/field_script.h"
#include "save/box.h"
#include "system/game_data.h"

BOOL s0121_BoxGetCount(VM *vm, FieldScriptEnv *env) {
    u16 *result = ScriptReadVar(vm, env);
    u16 kind = ScriptReadAny(vm, env);
    GameData *gameData = FieldScriptEnv_GetGameData(env);
    BoxSaveAccessor *boxes = GameData_GetBoxSaveAccessor(gameData);
    GameData_GetParty(gameData);
    int count;

    switch (kind) {
    case 0:
        count = howManyTotalPokesAreInBoxes(boxes);
        break;
    case 1:
    case 2:
        count = howManyNormalPokesAreInAllBoxes(boxes);
        break;
    case 3:
        count = howManyTotalPokesAreInBoxes(boxes) - howManyNormalPokesAreInAllBoxes(boxes);
        break;
    case 5:
        count = howManyTotalPokesAreInBoxes(boxes);
        if (count > 720) {
            count = 0;
        } else {
            count = 720 - count;
        }
        break;
    default:
        count = 0;
        break;
    }
    *result = count;
    return FALSE;
}
