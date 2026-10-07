// Macro for the zone headers in data/zones, archive a/0/1/2: a single file of 615 headers, one per zone in order,
// 0x30 bytes each, which ZoneData_GetHeader returns and the ZoneData_ and GetZone functions read. The arguments are
// keywords; the ones left out take the value most zones have.

#include "constants/sound.h"

    // map_type: GetZoneMapType. npc_cache: the NPC info cache index. area: the area (textures, buildings). matrix: the
    // map matrix. scripts and text: the zone's script file and script message file; init_scripts is always the script
    // file after it and nothing reads it. bgm_spring to bgm_winter: the music of each season (SEQ_*), or bgm for all
    // four. encounters: the wild encounter table, 0x1fff for none; enc_slot: the zone's 3-bit slot in a save word,
    // 6 for none. entities: the zone's entities file. parent: the zone it belongs to. place: the place name (system
    // message file 109); place_display: how it is shown. weather, projection (ZoneData_GetObjectProjectionMatrixType)
    // and camera: the defaults. transition: the effect of entering the map. battle_bg: the battle background. cycling,
    // escape_rope, fly_from, cycle_surf_bgm and entralink_warp: what the zone allows; flag11 has no reader and is
    // always set. cam_bound: the camera boundary, 0xffff for none. name_icon: the icon of the place name.
    // easy_level: the level adjustment of Easy Mode. fly_x, fly_y and fly_z: where flying lands, a grid position, or
    // a rail position (component, front and side) for a zone with rails
    // (GNU as can't continue a line, so the arguments are on one)
    .macro ZoneHeader map_type=0, npc_cache=0, area=0, matrix=0, scripts=0, init_scripts=-1, text=0, bgm=0, bgm_spring=-1, bgm_summer=-1, bgm_autumn=-1, bgm_winter=-1, encounters=0x1fff, enc_slot=0, entities=0, parent=0, place=0, place_display=0, weather=0, projection=0, camera=0, transition=0, battle_bg=0, cycling=0, flag11=1, escape_rope=0, fly_from=0, cycle_surf_bgm=0, entralink_warp=0, cam_bound=0xffff, name_icon=0, easy_level=0, fly_x=0, fly_y=0, fly_z=0
    .byte \map_type, \npc_cache
    .2byte \area, \matrix, \scripts
    .if \init_scripts == -1
    .2byte \scripts + 1
    .else
    .2byte \init_scripts
    .endif
    .2byte \text
    .irp season, \bgm_spring, \bgm_summer, \bgm_autumn, \bgm_winter
    .if \season == -1
    .2byte \bgm
    .else
    .2byte \season
    .endif
    .endr
    .2byte \encounters | (\enc_slot << 13)
    .2byte \entities, \parent
    .2byte \place | (\place_display << 10)
    .2byte \weather | (\projection << 6) | (\camera << 9)
    .set _zone_flags, \transition | (\battle_bg << 5) | (\cycling << 10) | (\flag11 << 11) | (\escape_rope << 12)
    .2byte _zone_flags | (\fly_from << 13) | (\cycle_surf_bgm << 14) | (\entralink_warp << 15)
    .2byte \cam_bound
    .2byte \name_icon | (\easy_level << 13)
    .4byte \fly_x, \fly_y, \fly_z
    .endm
