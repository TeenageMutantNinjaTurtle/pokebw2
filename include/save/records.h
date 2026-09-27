#ifndef POKEBW2_SAVE_RECORDS_H
#define POKEBW2_SAVE_RECORDS_H

#include "types.h"
#include "struct_decls.h"

// Clears the flag that is set, with the console's MAC address and the time, while a match is in progress

void RecordSave_ClearMatchInProgress(RecordSave *record);

#endif // POKEBW2_SAVE_RECORDS_H
