#include "field/field_prop.h"

void FieldPropAnmController_Dynamic_ExecCommand(FieldPropResInstance *instance, u32 animation, u32 command) {
    switch (command) {
    case 0:
        FieldPropResInstance_AnmStopAll(instance);
        FieldPropResInstance_AnmSetPlay(instance, animation);
        break;
    case 1:
        FieldPropResInstance_AnmStopAll(instance);
        FieldPropResInstance_AnmSetPlayInv(instance, animation);
        break;
    case 2:
        FieldPropResInstance_AnmStopAll(instance);
        FieldPropResInstance_AnmSetPlayLoop(instance, animation);
        break;
    case 3:
        FieldPropResInstance_AnmSetPause(instance, animation);
        break;
    case 4:
        FieldPropResInstance_AnmStopAll(instance);
        break;
    }
}
