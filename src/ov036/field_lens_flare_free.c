#include "field/field_exp_obj.h"
#include "field/field_lens_flare.h"
#include "gfl/heap.h"

void FieldLensFlare_Free(FieldLensFlare *lensFlare) {
    if (lensFlare->effectId != 8) {
        FieldExpObj_FreeScene(lensFlare->expObjSys, 3);
    }
    FieldLensFlareData_Free(lensFlare->ownedData);
    GFL_HeapFree(lensFlare);
}
