#ifndef POKEBW2_CONSTANTS_POKEMON_H
#define POKEBW2_CONSTANTS_POKEMON_H

// Genders, as BATTLEMON_GENDER gives them. The AI scripts tell which is which
#define GENDER_MALE 0
#define GENDER_FEMALE 1

// The species ID of an egg, which follows the national Pokédex in the species names
#define SPECIES_EGG 650

// Fields of a Pokémon, which PokeParty_GetParam and PokeParty_SetParam read and write. Names from swan's PkmField
#define PKM_PARAM_SPECIES 0x5
#define PKM_PARAM_ITEM 0x6
#define PKM_PARAM_MARKINGS 0xb
// The first ribbon of each group of ribbons, each followed by the field after the group
#define PKM_PARAM_RIBBON_CHAMPION_SINNOH 0x19
#define PKM_PARAM_MOVE1 0x36
#define PKM_PARAM_RIBBON_G3_COOL 0x4d
#define PKM_PARAM_FATEFUL_ENCOUNTER 0x6d
#define PKM_PARAM_FORM 0x6f
// The nickname, copied to or from a StrBuf
#define PKM_PARAM_NICKNAME 0x73
#define PKM_PARAM_RIBBON_G4_COOL 0x78
#define PKM_PARAM_OT_NAME 0x8d
#define PKM_PARAM_POKEBALL 0x98
#define PKM_PARAM_STATUS 0x9d
// The mail the Pokémon holds, copied from a MailData
#define PKM_PARAM_MAIL 0xa7
// The species, or SPECIES_EGG for an egg
#define PKM_PARAM_LEGAL_SPECIES 0xab
#define PKM_PARAM_POKESTAR_FAME 0xb3

// How a Pokémon evolves, the method of its species' evolution table. These are the methods the evolution demo treats
// differently: it removes the held item for the held item methods, makes a Shedinja, and doesn't let an evolution by
// item be stopped. The names are the usual ones for the values of the evolution tables
#define EVO_METHOD_TRADE_WITH_ITEM 6
#define EVO_METHOD_ITEM 8
// Evolving makes a Shedinja as well, with a free party slot and a Poké Ball
#define EVO_METHOD_SHEDINJA 14
#define EVO_METHOD_ITEM_MALE 17
#define EVO_METHOD_ITEM_FEMALE 18
#define EVO_METHOD_HELD_ITEM_DAY 19
#define EVO_METHOD_HELD_ITEM_NIGHT 20

#endif // POKEBW2_CONSTANTS_POKEMON_H
