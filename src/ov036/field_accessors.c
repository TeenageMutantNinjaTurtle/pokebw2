#include "field/field.h"

// The fields used here; the rest of Field's layout is not yet known.
struct Field {
    u16 heapId;
    u16 unk2;
    GameSystem *gameSystem;
    u8 unk8[0x38];
    MMSys *actorSystem;
};

MMSys *Field_GetActorSystem(Field *field) {
    return field->actorSystem;
}

GameSystem *Field_GetGameSystem(Field *field) {
    return field->gameSystem;
}

u16 Field_GetHeapID(Field *field) {
    return field->heapId;
}
