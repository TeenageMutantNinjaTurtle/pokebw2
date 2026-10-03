#include "field/field_actor.h"
#include "field/field_map.h"

BOOL GetTerrainAtPosByActor(FieldActor *actor, const VecFx32 *position, FieldTerrain *terrain) {
    MMSys *system;
    G3DMapper *mapper;

    system = GetActorMModelSystem(actor);
    mapper = GetMMSysG3DMapper(system);
    return FieldG3DMapper_GetTerrain(mapper, position, terrain);
}
