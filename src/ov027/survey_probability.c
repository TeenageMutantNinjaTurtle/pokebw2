#include "types.h"
#include "field/survey.h"
#include "gfl/random.h"

void probabilityLoop(SurveyProbabilityState *state) {
    int i;
    for (i = 0; i < 6; i++) {
        state->probability[i] = 0;
        insideProbabilityLoop(state, i);
    }
}

void insideProbabilityLoop(SurveyProbabilityState *state, u32 selection) {
    s32 score = state->score + state->bonus;
    u32 i;
    for (i = 0; i < 0xe0; i++) {
        const SurveyProbabilityEntry *entry = &data_ov027_02170e40[i];
        if (selection == entry->selection && entry->requiredScore <= score && (entry->flags & 4)) {
            u32 probability = entry->probability;
            if (probability == 100 || probability >= GFL_RandomLC(101)) {
                state->selection[selection] = i;
                return;
            }
        }
    }
}
