#include "field/field_script.h"

GameEvent *ScriptWork_GetEvent(ScriptWork *work) {
    return work->event;
}

GameSystem *ScriptWork_GetGameSystem(ScriptWork *work) {
    return work->gsys;
}

void *ScriptWork_GetFieldWork(ScriptWork *work) {
    UpdateScriptFieldWk(work->fieldWork, work->gsys);
    return work->fieldWork;
}

void *ScriptWork_GetSubwork(ScriptWork *work) {
    return work->subwork;
}

WordSet *ScriptWork_GetWordSet(ScriptWork *work) {
    return work->wordSet;
}

StrBuf *ScriptWork_GetMainStrBuf(ScriptWork *work) {
    return work->mainStrBuf;
}

StrBuf *ScriptWork_GetAltStrBuf(ScriptWork *work) {
    return work->altStrBuf;
}
