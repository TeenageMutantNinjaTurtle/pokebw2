#include "field/field_exp_obj_gimmick_ov104.h"
#include "gfl/arc.h"
#include "gfl/heap.h"

void func_ov104_021ef114(FieldExpObjGimmickOv104Work *work) {
    s32 count;
    s32 i;

    if (work->resList == 0) {
        count = GFL_ArcSysGetDataMax(0xa4);
        work->resList = GFL_HeapAllocate(work->heapId, count * sizeof(struct FieldExpObjGimmickOv104ResEntry), FALSE,
                                         data_ov104_021f078c, 0x4b5);
        for (i = 0; i < count; i++) {
            func_ov104_021f0324(&work->resList[i], 0xa4, i);
        }
        work->resCount = count;
    }
}

void func_ov104_021ef168(FieldExpObjGimmickOv104Work *work) {
    if (work->resList != 0) {
        GFL_HeapFree(work->resList);
        work->resList = 0;
        work->resCount = 0;
    }
}
