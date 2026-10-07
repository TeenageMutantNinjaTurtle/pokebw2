#ifndef POKEBW2_CONSTANTS_ARC_H
#define POKEBW2_CONSTANTS_ARC_H

// Names, layouts and constants from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0), except
// ARCID_WINFRAME, ARCID_TITLE, ARCID_STARTMENU, ARCID_SEASON_BANNER, ARCID_COPYRIGHT, ARCID_ZUKAN_GRA, ARCID_INTRO,
// ARCID_EGG_DEMO, ARCID_SHINKA_DEMO, ARCID_POKEICON, ARCID_BOX2, ARCID_TRAI_SCRIPT, ARCID_BMP_OAM, ARCID_INFOWIN,
// ARCID_APP_MENU_COMMON, ARCID_TPOKE, ARCID_P_STATUS and ARCID_PMSI

#define ARCID_SYSTEM_MESSAGE 2
#define ARCID_SCRIPT_MESSAGE 3
#define ARCID_POKEGRA 4
#define ARCID_WINFRAME 5
// The Pokémon icons
#define ARCID_POKEICON 7
#define ARCID_MAP_TERRAIN 8
#define ARCID_MAP_MATRIX 9
#define ARCID_ZONEDATA 12
#define ARCID_AREADATA 13
#define ARCID_AREA_MAP_TEX 14
#define ARCID_AREA_EDGE_COLOR_TABLES 15
#define ARCID_PERSONAL 16
#define ARCID_GROWTBL 17
#define ARCID_LEARNSETS 18
#define ARCID_EVOLUTIONS 19
#define ARCID_BABYMONS 20
#define ARCID_WAZAINFO 21
#define ARCID_FONT 23
#define ARCID_ITEMINFO 24
#define ARCID_ITEMGRA 25
// The boot logos and the title screen's 2D graphics
#define ARCID_TITLE 26
// The start menu's graphics
#define ARCID_STARTMENU 34
// The phrase input's graphics
#define ARCID_PMSI 42
#define ARCID_MMODEL_TBL 47
#define ARCID_MMODEL_GRA 48
#define ARCID_INFOWIN 49
// The cells and animations of bmp_oam.c's 32x16 actors, for each OBJ character mapping
#define ARCID_BMP_OAM 50
#define ARCID_EVENT_SCRIPT 56
#define ARCID_FIELD_CAMERA_DEFAULT 59
#define ARCID_LIGHTS_FIELD 60
#define ARCID_LIGHTS_BATTLE 61
#define ARCID_AREA_ANIME_SRT 68
#define ARCID_AREA_ANIME_PAT 69
#define ARCID_TRSPRITE_FRONT 71
#define ARCID_TRSPRITE_BACK 72
// The summary screen's graphics
#define ARCID_P_STATUS 77
#define ARCID_RAIL_HEADERS 78
// The graphics that the menus share (app_menu_common.c)
#define ARCID_APP_MENU_COMMON 82
// The trainers' messages as pairs of trainer ID and message type, in trainer order, and the offset of each trainer's
// first pair (tr_tool.c; not from swan)
#define ARCID_TRTBL 89
#define ARCID_TRTBLOFS 90
#define ARCID_TRDATA 91
#define ARCID_TRPOKE 92
// The Global Trade Station's 2D graphics (not from swan)
#define ARCID_WORLDTRADE 95
#define ARCID_CALENDAR 96
#define ARCID_GIMMICK_TBL 102
#define ARCID_FIELD_CAMERA_MAP_BOUNDARY 109
#define ARCID_RAIL_DATA 110
// The PC box's graphics
#define ARCID_BOX2 117
#define ARCID_ZONE_ENTITIES 126
#define ARCID_ENCOUNTDATA 127
#define ARCID_MAPEFF_SKILL_TBL 149
#define ARCID_SEASON_BANNER 150
#define ARCID_FIELD_CAMERA_MAP_PARAM 156
// The Pokédex's graphics
#define ARCID_ZUKAN_GRA 157
#define ARCID_DEMO3D_RESOURCE 158
// The copyright notice that the game shows when it starts. swan names this archive ARCID_FIELD_CAMERA_SCRIPT_PARAM,
// but it holds 2D graphics
#define ARCID_COPYRIGHT 162
// The intro's graphics
#define ARCID_INTRO 168
#define ARCID_EGG_DEMO 186
#define ARCID_TRAI_SCRIPT 169
#define ARCID_FIELD_BBD_COLOR 173
#define ARCID_AREA_BMTEX_EXT 174
#define ARCID_AREA_BMTEX_INT 175
// The evolution demo's graphics
#define ARCID_SHINKA_DEMO 179
// The walking Pokémon's object codes (tpoke_data.c)
#define ARCID_TPOKE 208
// The Research Radar's graphics. Our name, not swan's
#define ARCID_RESEARCH_RADAR 189
// The graphics that many apps share, such as the touch bar, which getUINarcIdx returns. Our name, not swan's
#define ARCID_APP_MENU_COMMON 82
#define ARCID_CDEMO_GFLOGO 220
#define ARCID_CDEMO_OPENINGWB 221
#define ARCID_CDEMO_OPENINGSW 222
#define ARCID_AREA_BMDATA_EXT 225
#define ARCID_AREA_BMDATA_INT 226
// Unova Link's graphics (not from swan)
#define ARCID_KEY_SYSTEM 277
#define ARCID_GIMMICK_EXPOBJ_MARINETUBE 295

#endif // POKEBW2_CONSTANTS_ARC_H
