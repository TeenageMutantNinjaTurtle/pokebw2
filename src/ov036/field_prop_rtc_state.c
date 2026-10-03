#include "field/field_prop.h"
#include "system/rtc.h"

void FieldPropRTCState_Init(FieldPropRTCState *state, u8 season) {
    state->dayPeriod = 5;
    state->season = season;
    FieldPropRTCState_Update(state);
}

void FieldPropRTCState_Update(FieldPropRTCState *state) {
    state->previousDayPeriod = state->dayPeriod;
    state->dayPeriod = GetRealTimeDayPeriod(state->season);
    state->dayPartChanged = state->dayPeriod != state->previousDayPeriod;
    state->playAnmIndex = FIELD_PROP_ANM_IDX_FOR_DAY_PART[state->dayPeriod];
}

BOOL FieldPropRTCState_HasDayPartChanged(FieldPropRTCState *state) {
    return state->dayPartChanged;
}

u8 FieldPropRTCState_GetPlayAnmIndex(FieldPropRTCState *state) {
    return state->playAnmIndex;
}
