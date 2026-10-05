#ifndef POKEBW2_SAVE_MEDAL_BOX_H
#define POKEBW2_SAVE_MEDAL_BOX_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"

// The Medal Rally's medals, save block 0x44

#define MEDAL_COUNT 255

// What the player knows of a medal
enum {
    MEDAL_STATUS_UNKNOWN,
    MEDAL_STATUS_1,
    // Shown as a hint
    MEDAL_STATUS_DISCOVERED,
    // Earned, but Mr. Medal hasn't handed it over yet
    MEDAL_STATUS_EARNED,
    MEDAL_STATUS_OBTAINED,
};

MedalBox *SaveControl_GetMedalBox(SaveControl *save);
u8 MedalBox_GetMedalStatus(MedalBox *box, u16 medal);
void MedalBox_GiveMedal(MedalBox *box, u16 medal);
void MedalBox_DiscoverMedal(MedalBox *box, u16 medal);
void MedalBox_DiscoverInitialMedal(MedalBox *box, u16 medal, u8 year, u8 month, u8 day);
void MedalBox_AcknowledgeMedal(MedalBox *box, u16 medal, u8 year, u8 month, u8 day);
u32 MedalBox_GetObtainedCount(MedalBox *box, u32 a1);
u8 MedalBox_GetRank(MedalBox *box);
// The medal obtained last, or 0xff
u8 func_0200fa44(MedalBox *box);
void MedalBox_GetMedalDate(MedalBox *box, u16 medal, u8 *year, u8 *month, u8 *day);
// The number of medals needed for the next rank
u32 MedalBox_GetNextRankRequirement(MedalBox *box);
void MedalBox_IncrementRank(MedalBox *box);

#endif // POKEBW2_SAVE_MEDAL_BOX_H
