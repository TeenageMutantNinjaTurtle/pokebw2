#include "g2di_load.h"
#include "nnsys/g2d.h"

// NitroSystem's g2d_NMC_load.c: finds the multi-cell bank in a loaded NMCR file and turns its offsets into pointers in
// place

static void UnpackExtendedData_(NNSG2dUserExDataBlock *blk);

BOOL NNS_G2dGetUnpackedMultiCellBank(void *file, NNSG2dMultiCellDataBank **cells) {
    NNSG2dBinaryBlockHeader *blk = NNS_G2dFindBinaryBlock(file, NNS_G2D_BINBLK_SIG_MULTICELLBANK);

    if (blk != NULL) {
        NNS_G2dUnpackNMC((NNSG2dMultiCellDataBank *)(blk + 1));
        *cells = (NNSG2dMultiCellDataBank *)(blk + 1);
        return TRUE;
    }
    *cells = NULL;
    return FALSE;
}

static void UnpackExtendedData_(NNSG2dUserExDataBlock *blk) {
    NNSi_G2dUnpackUserExCellAttrBank((NNSG2dUserExCellAttrBank *)(blk + 1));
}

void NNS_G2dUnpackNMC(NNSG2dMultiCellDataBank *bank) {
    u16 i;
    NNSG2dMultiCellData *cellArray;

    NNSi_G2dUnpackOffset(bank->pMultiCellDataArray, bank);
    NNSi_G2dUnpackOffset(bank->pHierarchyDataArray, bank);

    cellArray = bank->pMultiCellDataArray;
    for (i = 0; i < bank->numMultiCellData; i++) {
        NNSi_G2dUnpackOffset(cellArray[i].pHierDataArray, bank->pHierarchyDataArray);
    }

    if (bank->pExtendedData != NULL) {
        NNSi_G2dUnpackOffset(bank->pExtendedData, bank);
        UnpackExtendedData_(bank->pExtendedData);
    }
}

const NNSG2dMultiCellData *NNS_G2dGetMultiCellDataByIdx(const NNSG2dMultiCellDataBank *bank, u16 idx) {
    if (idx < bank->numMultiCellData) {
        return &bank->pMultiCellDataArray[idx];
    }
    return NULL;
}
