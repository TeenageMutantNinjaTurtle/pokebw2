#ifndef POKEBW2_FIELD_FIELD_G3DOBJ_H
#define POKEBW2_FIELD_FIELD_G3DOBJ_H

// The field's 3D objects: groups of resources and objects made from them. Names and layouts from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "nitro/fx.h"
#include "struct_decls.h"

typedef struct FieldG3DObjSystem FieldG3DObjSystem;

// The archives and files of a resource group
typedef struct {
    ArcTool *mdlArc;
    ArcTool *texArc;
    ArcTool *anmArc;
    u16 mdlDatID;
    u16 texDatID;
    u16 anmDatIDs[8];
    u8 anmCount;
} FieldG3DObjResRequest;

u16 FieldG3DObjSystem_AddResGroup(FieldG3DObjSystem *sys, FieldG3DObjResRequest *req, BOOL preloadTextures);
void FieldG3DObjSystem_FreeResGroup(FieldG3DObjSystem *sys, u16 resGroupIdx);
u16 FieldG3DObjSystem_AddObj(FieldG3DObjSystem *sys, u32 resGroupIdx, u16 modelIdxInRes, VecFx32 *pos);
void FieldG3DObjSystem_FreeObj(FieldG3DObjSystem *sys, u16 objIdx);
// TRUE until the object's animation ends
BOOL FieldG3DObjSystem_StepObjAnm(FieldG3DObjSystem *sys, u16 objIdx, fx32 addend);
void FieldG3DObjResRequest_Clear(FieldG3DObjResRequest *req);
void FieldG3DObjResRequest_SetModel(FieldG3DObjResRequest *req, ArcTool *arc, u16 datId);
void FieldG3DObjResRequest_SetAnmArc(FieldG3DObjResRequest *req, ArcTool *arc);
void FieldG3DObjResRequest_AddAnm(FieldG3DObjResRequest *req, u16 datId);

#endif // POKEBW2_FIELD_FIELD_G3DOBJ_H
