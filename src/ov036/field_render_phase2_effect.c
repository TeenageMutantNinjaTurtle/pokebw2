#include "field/encounter_effect.h"
#include "field/field_3d_ci.h"
#include "field/field_internal.h"
#include "field/field_render.h"
#include "gfl/graphics.h"

void FieldRenderPhase2_FieldEffect(Field *field) {
    gfxClearColor(0, 0, 0x7fff, 0, FALSE);
    func_ov036_021bb674();
    Fld3DCi_Draw(field->g3dCi);
}

void FieldRenderPhase2_EncountEffect(Field *field) {
    gfxClearColor(0x4210, 31, 0x7fff, 0, FALSE);
    EncEff_CallRenderFunc(field->encEff);
}
