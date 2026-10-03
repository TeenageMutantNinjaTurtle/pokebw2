#include "field/field_exp_obj.h"
#include "field/field_lens_flare.h"

void FieldLensFlare_RequestStart(FieldLensFlare *lensFlare) {
    if (lensFlare->data != NULL && lensFlare->effectId != 8) {
        lensFlare->requested = TRUE;
        lensFlare->active = FALSE;
        lensFlare->state = 0;
    }
}

void FieldLensFlare_GreenlightStart(FieldLensFlare *lensFlare) {
    if (lensFlare->data != NULL) {
        lensFlare->active = TRUE;
    }
}

void FieldLensFlare_Cancel(FieldLensFlare *lensFlare) {
    if (lensFlare->requested != FALSE) {
        FieldExpObj_SetActorHidden(lensFlare->expObjSys, 3, 0, TRUE);
        lensFlare->requested = FALSE;
        lensFlare->active = FALSE;
        lensFlare->state = 0;
    }
}
