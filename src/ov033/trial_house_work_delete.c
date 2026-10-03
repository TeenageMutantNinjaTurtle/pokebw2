#include "field/trial_house.h"
#include "gfl/heap.h"

void TrialHouseWorkDelete(void *unused, struct TrialHouseWork **workPtr) {
    if (*workPtr != NULL) {
        GFL_HeapFree((*workPtr)->saveBuffer);
        GFL_HeapFree((*workPtr)->party);
        GFL_HeapFree(*workPtr);
        *workPtr = NULL;
    }
}
