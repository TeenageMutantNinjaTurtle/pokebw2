#include "field/field_surf.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_map.h"
#include "field/field_player.h"

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 tileType;
    fx32 height;
} SurfTerrain;

BOOL CreateSurfPos(void *context, Field *field, VecFx32 *position) {
    VecFx32 targetPosition;
    SurfTerrain terrain;
    VecFx32 actorPosition;
    G3DMapper *mapper;
    FieldPlayer *player;
    FieldActor *actor;
    u8 direction;
    fx32 heightDifference;

    mapper = Field_GetG3DMapper(field);
    player = Field_GetPlayer(field);
    actor = FieldPlayer_GetActor(player);
    direction = GetActorFaceDir(actor);
    FieldPlayer_GetWPosInDir(player, direction, &targetPosition);
    if (Field_GetResolvedControllerTypeID(field) == 1) {
        return FALSE;
    }
    if (FieldG3DMapper_GetTerrain(mapper, &targetPosition, &terrain) == FALSE) {
        return FALSE;
    }
    if (MapTile_IsSurfEdge(GetTileClass(terrain.tileType)) == TRUE) {
        ExpandVecInGridDir(direction, &targetPosition, 1 << 16);
        if (FieldG3DMapper_GetTerrain(mapper, &targetPosition, &terrain) == FALSE) {
            return FALSE;
        }
    }
    if (IsTileSurfWater(GetTileClass(terrain.tileType)) == FALSE) {
        return FALSE;
    }
    CopyActorWPos(actor, &actorPosition);
    heightDifference = actorPosition.y - terrain.height;
    if (heightDifference < 0 || heightDifference >= (5 << 14)) {
        return FALSE;
    }
    if (position != NULL) {
        position->x = targetPosition.x;
        position->y = terrain.height;
        position->z = targetPosition.z;
    }
    return TRUE;
}
