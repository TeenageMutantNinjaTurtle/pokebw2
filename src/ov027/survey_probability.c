#include "types.h"
#include "gfl/random.h"

typedef struct {
    u8 selection[6];
    u8 probability[6];
    u16 score;
    u16 bonus;
} SurveyProbabilityState;

typedef struct {
    u8 selection;
    u8 requiredScore;
    u8 probability;
    u8 flags;
} SurveyProbabilityEntry;

extern const SurveyProbabilityEntry data_ov027_02170e40[];

void probabilityLoop(SurveyProbabilityState *state);
void insideProbabilityLoop(SurveyProbabilityState *state, u32 selection);

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
