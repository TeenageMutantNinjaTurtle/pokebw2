#include "field/field_prop.h"

void FieldChunkPropHolder_Release(FieldPropSystem *system, FieldChunkPropHolder *holder) {
    holder->chunk = NULL;
    holder->savedResIndex = 0xffffffff;
    holder->propIndex = 0;
    holder->visible = 0;
    holder->instance = NULL;
}
