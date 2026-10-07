// Macro for the baby species in data/baby_species, archive a/0/2/0: one file per species record, as data/personal,
// with the species that hatches from an egg the species lays, its first evolution stage.

#include "constants/species.h"

    .macro BabySpecies species
    .2byte \species
    .endm
