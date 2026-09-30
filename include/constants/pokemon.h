#ifndef POKEBW2_CONSTANTS_POKEMON_H
#define POKEBW2_CONSTANTS_POKEMON_H

// Genders, as BATTLEMON_GENDER gives them. The AI scripts tell which is which
#define GENDER_MALE 0
#define GENDER_FEMALE 1

// The species ID of an egg, which follows the national Pokédex in the species names
#define SPECIES_EGG 650

// Fields of a Pokémon, which PokeParty_GetParam and PokeParty_SetParam read and write. Names from swan's PkmField
#define PKM_PARAM_SPECIES 0x5
#define PKM_PARAM_FORM 0x6f
// The nickname, copied to or from a StrBuf
#define PKM_PARAM_NICKNAME 0x73
// The species, or SPECIES_EGG for an egg
#define PKM_PARAM_LEGAL_SPECIES 0xab

#endif // POKEBW2_CONSTANTS_POKEMON_H
