#include "types.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "pml/species_names.h"

// The species names' message data, which stays loaded. The file's name is a guess: the ROM has no string for it

// The original has this in .data, as an explicit zero
#pragma explicit_zero_data on
MsgData *g_PMLSpeciesNamesResident = NULL;
#pragma explicit_zero_data reset

void PML_SpeciesNamesResidentInit(HeapID heapId) {
    g_PMLSpeciesNamesResident = GFL_MsgSysLoadData(FALSE, 2, 0x5a, heapId);
}
