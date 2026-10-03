#include "field/field_exp_obj.h"
#include "field/field_lens_flare.h"
#include "gfl/g3d.h"
#include "nitro/fx.h"

void FieldLensFlare_CalcPos(FieldLensFlare *lensFlare, G3DCamera *camera) {
    VecFx32 position;
    VecFx32 up;
    VecFx32 target;
    VecFx32 offset;
    SRTMatrix *matrix;

    GFL_G3DCameraGetLookatPos(camera, &position);
    GFL_G3DCameraGetLookatUpVector(camera, &up);
    GFL_G3DCameraGetLookatTarget(camera, &target);
    VEC_Subtract(&target, &position, &offset);
    vecfx_normalize(&offset, &offset);
    vecfx_muladd(0x3c000, &offset, &position, &offset);
    matrix = FieldExpObj_GetActorMatrixPtr(lensFlare->expObjSys, 3, 0);
    matrix->translation = offset;
}
