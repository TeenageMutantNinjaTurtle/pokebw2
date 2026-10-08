#ifndef POKEBW2_NNSYS_G2D_H
#define POKEBW2_NNSYS_G2D_H

#include "types.h"
#include "nitro/fx.h"
#include "nitro/gx.h"

typedef struct {
    u32 format;
    u32 extendedPalette;
    u32 size;
    void *rawData;
} NNSG2dPaletteData;

typedef struct {
    u16 height;
    u16 width;
    u32 pixelFormat;
    u32 mappingType;
    u32 characterFormat;
    u32 size;
    void *rawData;
} NNSG2dCharacterData;

typedef struct {
    u16 width;
    u16 height;
    u16 colorMode;
    u16 format;
    u32 size;
    u32 rawData[1];
} NNSG2dScreenData;

// The palettes present in a palette file that holds only some of them
typedef struct {
    u16 numPalette;
    u16 pad;
    void *paletteIndexTable;
} NNSG2dPaletteCompressInfo;

// A block of a file's user extended data, found by its kind
typedef struct {
    u32 blkTypeID;
    u32 blkSize;
} NNSG2dUserExDataBlock;

// A G2D file: its header, then numBlocks blocks, each starting with its kind and its size with this header. These are
// the SDK's own types, though G3D's resource files have the same layout
typedef struct {
    u32 signature;
    u16 byteOrder;
    u16 version;
    u32 fileSize;
    u16 headerSize;
    u16 numBlocks;
} NNSG2dBinaryFileHeader;

typedef struct {
    u32 kind;
    u32 size;
} NNSG2dBinaryBlockHeader;

#define NNS_G2D_BINBLK_SIG_CHARDATA 0x43484152 // 'CHAR'
#define NNS_G2D_BINBLK_SIG_PALETTEDATA 0x504C5454 // 'PLTT'
#define NNS_G2D_BINBLK_SIG_PALETTECOMPRESSINFO 0x50434D50 // 'PCMP'
#define NNS_G2D_BINBLK_SIG_SCREENDATA 0x5343524E // 'SCRN'
#define NNS_G2D_BINBLK_SIG_MULTICELLBANK 0x4D43424B // 'MCBK'
#define NNS_G2D_BINBLK_SIG_CELLBANK 0x4345424B // 'CEBK'
#define NNS_G2D_BINBLK_SIG_ANIMBANK 0x41424E4B // 'ABNK'

#define NNS_G2D_USEREXDATA_CELLATTR 0x55434154
#define NNS_G2D_USEREXDATA_ANMATTR 0x55414154

static inline const NNSG2dUserExDataBlock *NNSi_G2dGetUserExDataBlkByID(const NNSG2dUserExDataBlock *blk, u32 id) {
    if (blk != NULL && blk->blkTypeID == id) {
        return blk;
    }
    return NULL;
}

// A cell, the OAMs that are drawn together, and the box or circle that holds them
typedef struct {
    s16 x;
    s16 y;
} NNSG2dSVec2;

typedef struct {
    NNSG2dSVec2 maxBounding;
    NNSG2dSVec2 minBounding;
} NNSG2dCellBoundingRectS16;

#define NNSi_G2D_CELLATTR_BOUNDINGSPHERE_MASK 0x3f
#define NNSi_G2D_CELLATTR_BOUNDINGRECT_SHIFT 11

typedef struct {
    u16 numOAMAttrs;
    u16 cellAttr;
    void *pOamAttrArray;
} NNSG2dCellData;

// A cell of a bank whose cells have bounding rects
typedef struct {
    NNSG2dCellData cellData;
    NNSG2dCellBoundingRectS16 boundingRect;
} NNSG2dCellDataWithBR;

static inline u8 NNSi_G2dGetCellBoundingSphereR(const NNSG2dCellData *cell) {
    u8 r = cell->cellAttr & NNSi_G2D_CELLATTR_BOUNDINGSPHERE_MASK;

    return r << 2;
}

typedef struct {
    u32 szByteMax;
    void *pCellTransferDataArray;
} NNSG2dVramTransferData;

// A cell bank's attributes: whether its cells are NNSG2dCellDataWithBR
#define NNS_G2D_CELLBK_ATTR_CELLWITHBR 0x1

typedef struct NNSG2dCellDataBank {
    u16 numCells;
    u16 cellBankAttr;
    NNSG2dCellData *pCellDataArrayHead;
    u32 mappingMode;
    NNSG2dVramTransferData *pVramTransferData;
    void *pStringBank;
    NNSG2dUserExDataBlock *pExtendedData;
} NNSG2dCellDataBank;

static inline BOOL NNS_G2dCellDataBankHasVramTransferData(const NNSG2dCellDataBank *bank) {
    return bank->pVramTransferData != NULL;
}

// A multi-cell: its nodes, each a cell animation at a position
typedef struct {
    u16 animSequenceIdx;
    NNSG2dSVec2 pos;
    // The index of the node's cell animation in bits 8 to 15
    u16 nodeAttr;
} NNSG2dMultiCellHierarchyData;

typedef struct {
    u16 numNodes;
    u16 numCellAnim;
    NNSG2dMultiCellHierarchyData *pHierDataArray;
} NNSG2dMultiCellData;

typedef struct NNSG2dMultiCellDataBank {
    u16 numMultiCellData;
    u16 pad;
    NNSG2dMultiCellData *pMultiCellDataArray;
    void *pHierarchyDataArray;
    void *pStringBank;
    NNSG2dUserExDataBlock *pExtendedData;
} NNSG2dMultiCellDataBank;

// The user extended attributes of cells, numAttribute words each
typedef struct {
    u32 *pAttr;
} NNSG2dUserExCellAttr;

typedef struct {
    u16 numCells;
    u16 numAttribute;
    NNSG2dUserExCellAttr *pCellAttrArray;
} NNSG2dUserExCellAttrBank;

static inline const NNSG2dUserExCellAttrBank *NNS_G2dGetUserExCellAttrBankFromCellBank(const NNSG2dCellDataBank *bank) {
    const NNSG2dUserExDataBlock *blk = NNSi_G2dGetUserExDataBlkByID(bank->pExtendedData, NNS_G2D_USEREXDATA_CELLATTR);

    if (blk != NULL) {
        return (const NNSG2dUserExCellAttrBank *)(blk + 1);
    }
    return NULL;
}

static inline const NNSG2dUserExCellAttrBank *
NNS_G2dGetUserExCellAttrBankFromMCBank(const NNSG2dMultiCellDataBank *bank) {
    const NNSG2dUserExDataBlock *blk = NNSi_G2dGetUserExDataBlkByID(bank->pExtendedData, NNS_G2D_USEREXDATA_CELLATTR);

    if (blk != NULL) {
        return (const NNSG2dUserExCellAttrBank *)(blk + 1);
    }
    return NULL;
}

// Animations: banks of sequences of frames. A frame's content is an index, an NNSG2dAnimDataSRT or an
// NNSG2dAnimDataT, by the sequence's animType (its low 16 bits)
enum {
    NNS_G2D_ANIMELEM_INDEX,
    NNS_G2D_ANIMELEM_INDEX_SRT,
    NNS_G2D_ANIMELEM_INDEX_T,
};

typedef struct {
    u16 index;
    u16 rotZ;
    fx32 sx;
    fx32 sy;
    s16 px;
    s16 py;
} NNSG2dAnimDataSRT;

typedef struct {
    u16 index;
    u16 pad;
    s16 px;
    s16 py;
} NNSG2dAnimDataT;

typedef struct {
    void *pContent;
    u16 frames;
    u16 pad;
} NNSG2dAnimFrameData;

// How a sequence plays: once or looping, forward or forward and then back
enum {
    NNS_G2D_ANIMATIONPLAYMODE_INVALID,
    NNS_G2D_ANIMATIONPLAYMODE_FORWARD,
    NNS_G2D_ANIMATIONPLAYMODE_FORWARD_LOOP,
    NNS_G2D_ANIMATIONPLAYMODE_REVERSE,
    NNS_G2D_ANIMATIONPLAYMODE_REVERSE_LOOP,
};

typedef struct {
    u16 numFrames;
    u16 loopStartFrameIdx;
    u32 animType;
    u32 playMode;
    NNSG2dAnimFrameData *pAnmFrameArray;
} NNSG2dAnimSequence;

typedef struct NNSG2dAnimBankData {
    u16 numSequences;
    u16 numTotalFrames;
    NNSG2dAnimSequence *pSequenceArrayHead;
    NNSG2dAnimFrameData *pFrameArray;
    void *pAnimationData;
    void *pStringBank;
    NNSG2dUserExDataBlock *pExtendedData;
} NNSG2dAnimBankData;

// The user extended attributes of animation sequences and their frames, numAttribute words each
typedef struct {
    u32 *pAttr;
} NNSG2dUserExAnimFrameAttr;

typedef struct {
    u16 numFrames;
    u16 pad;
    u32 *pAttr;
    NNSG2dUserExAnimFrameAttr *pAnmFrmAttrArray;
} NNSG2dUserExAnimSequenceAttr;

typedef struct {
    u16 numSequences;
    u16 numAttribute;
    NNSG2dUserExAnimSequenceAttr *pAnmSeqAttrArray;
} NNSG2dUserExAnimAttrBank;

static inline const NNSG2dUserExAnimAttrBank *NNS_G2dGetUserExAnimAttrBank(const NNSG2dAnimBankData *bank) {
    const NNSG2dUserExDataBlock *blk = NNSi_G2dGetUserExDataBlkByID(bank->pExtendedData, NNS_G2D_USEREXDATA_ANMATTR);

    if (blk != NULL) {
        return (const NNSG2dUserExAnimAttrBank *)(blk + 1);
    }
    return NULL;
}

static inline const NNSG2dUserExAnimSequenceAttr *NNS_G2dGetUserExAnimSequenceAttr(const NNSG2dUserExAnimAttrBank *bank,
                                                                                  u16 idx) {
    if (idx < bank->numSequences) {
        return &bank->pAnmSeqAttrArray[idx];
    }
    return NULL;
}

// Plays an animation sequence, with a callback at the last frame, at every frame or at one frame
enum {
    NNS_G2D_ANMCALLBACKTYPE_NONE,
    NNS_G2D_ANMCALLBACKTYPE_LAST_FRM,
    NNS_G2D_ANMCALLBACKTYPE_SPEC_FRM,
    NNS_G2D_ANMCALLBACKTYPE_EVER_FRM,
};

typedef void (*NNSG2dAnmCallBackPtr)(u32 param, fx32 currentFrame);

typedef struct {
    u32 type;
    u32 param;
    NNSG2dAnmCallBackPtr pFunc;
    u16 frameIdx;
} NNSG2dCallBackFunctor;

typedef struct {
    const NNSG2dAnimFrameData *pCurrent;
    const NNSG2dAnimFrameData *pActiveCurrent;
    BOOL bReverse;
    BOOL bActive;
    fx32 currentTime;
    fx32 speed;
    u32 overriddenPlayMode;
    const NNSG2dAnimSequence *pAnimSequence;
    NNSG2dCallBackFunctor callbackFunctor;
} NNSG2dAnimController;

// A cell animation, and a multi-cell one, which animates cell animations together
typedef struct {
    NNSG2dAnimController animCtrl;
    const NNSG2dCellData *pCurrentCell;
    const NNSG2dCellDataBank *pCellDataBank;
    u32 cellTransferStateHandle;
    u8 srtCtrl[0x1c];
} NNSG2dCellAnimation;

enum {
    NNS_G2D_MCTYPE_DONOT_SHARE_CELLANIM,
    NNS_G2D_MCTYPE_SHARE_CELLANIM,
};

typedef struct {
    const void *pCurrentMultiCell;
    const void *pAnimDataBank;
    u32 mcType;
    void *pCellAnimArray;
} NNSG2dMultiCellInstance;

typedef struct {
    NNSG2dAnimController animCtrl;
    u32 unk30;
    NNSG2dMultiCellInstance multiCellInstance;
    const NNSG2dMultiCellDataBank *pMultiCellDataBank;
    u8 srtCtrl[0x1c];
} NNSG2dMultiCellAnimation;

// A cell animation of a multi-cell instance's array
typedef struct {
    NNSG2dCellAnimation cellAnim;
    u32 unk58;
} NNSG2dMCCellAnimation;

// Find the block of their kind in a loaded graphics file and turn its offsets into pointers in place, returning FALSE
// if the file has none. swan calls the first four NNS_G2DPrepareBGChar, NNS_G2DPrepareObjChar, NNS_G2DPrepareScreen
// and RelocatePaletteResGetDataPtr
BOOL NNS_G2dGetUnpackedBGCharacterData(void *file, NNSG2dCharacterData **character);
BOOL NNS_G2dGetUnpackedCharacterData(void *file, NNSG2dCharacterData **character);
BOOL NNS_G2dGetUnpackedScreenData(void *file, NNSG2dScreenData **screen);
BOOL NNS_G2dGetUnpackedPaletteData(void *file, NNSG2dPaletteData **palette);
BOOL NNS_G2dGetUnpackedPaletteCompressInfo(void *file, NNSG2dPaletteCompressInfo **info);
BOOL NNS_G2dGetUnpackedCellBank(void *file, NNSG2dCellDataBank **cells);
BOOL NNS_G2dGetUnpackedAnimBank(void *file, NNSG2dAnimBankData **anims);
BOOL NNS_G2dGetUnpackedMultiCellBank(void *file, NNSG2dMultiCellDataBank **cells);
BOOL NNS_G2dGetUnpackedMCAnimBank(void *file, NNSG2dAnimBankData **anims);

// The block of the given kind in a loaded G2D file, or NULL. swan calls it NNS_G2DFindDataBlock
NNSG2dBinaryBlockHeader *NNS_G2dFindBinaryBlock(NNSG2dBinaryFileHeader *file, u32 kind);

// Turn the offsets in a character, BG character or palette block into pointers, as the functions above do. swan calls
// them NNS_G2DRelocateObjChar, NNS_G2DRelocateBGChar and NNS_G2DRelocatePLTTHeader, and doesn't name
// NNSi_G2dUnpackNCLCmpInfo
void NNS_G2dUnpackNCG(NNSG2dCharacterData *character);
void NNS_G2dUnpackBGNCG(NNSG2dCharacterData *character);
void NNS_G2dUnpackNCL(NNSG2dPaletteData *palette);
void NNSi_G2dUnpackNCLCmpInfo(NNSG2dPaletteCompressInfo *info);

// Turn a cell or multi-cell bank's offsets into pointers, as NNS_G2dGetUnpackedCellBank and
// NNS_G2dGetUnpackedMultiCellBank do after finding it, and those of either's user extended cell attributes, which swan
// doesn't name
void NNS_G2dUnpackNCE(NNSG2dCellDataBank *bank);
void NNS_G2dUnpackNMC(NNSG2dMultiCellDataBank *bank);
void NNSi_G2dUnpackUserExCellAttrBank(NNSG2dUserExCellAttrBank *attrBank);
const NNSG2dCellData *NNS_G2dGetCellDataByIdx(const NNSG2dCellDataBank *bank, u16 idx);
const NNSG2dMultiCellData *NNS_G2dGetMultiCellDataByIdx(const NNSG2dMultiCellDataBank *bank, u16 idx);

// Turns an animation bank's offsets into pointers, as NNS_G2dGetUnpackedAnimBank does after finding it
void NNS_G2dUnpackNAN(NNSG2dAnimBankData *bank);

// NNS_G2dGetAnimSequenceByIdx, and controlling an animation
const NNSG2dAnimSequence *NNS_G2dGetAnimSequenceByIdx(const NNSG2dAnimBankData *bank, u16 idx);
void *NNS_G2dGetAnimCtrlCurrentElement(const NNSG2dAnimController *animCtrl);
BOOL NNS_G2dTickAnimCtrl(NNSG2dAnimController *animCtrl, fx32 frames);
BOOL NNS_G2dSetAnimCtrlCurrentFrame(NNSG2dAnimController *animCtrl, u16 frameIdx);
u16 NNS_G2dGetAnimCtrlCurrentFrame(const NNSG2dAnimController *animCtrl);
void NNS_G2dInitAnimCtrl(NNSG2dAnimController *animCtrl);
void NNS_G2dInitAnimCallBackFunctor(NNSG2dCallBackFunctor *functor);
void NNS_G2dResetAnimCtrlState(NNSG2dAnimController *animCtrl);
void NNS_G2dBindAnimCtrl(NNSG2dAnimController *animCtrl, const NNSG2dAnimSequence *seq);
void NNS_G2dSetAnimCtrlCallBackFunctor(NNSG2dAnimController *animCtrl, u32 type, u32 param, NNSG2dAnmCallBackPtr pFunc);
void NNS_G2dSetAnimCtrlCallBackFunctorAtAnimFrame(NNSG2dAnimController *animCtrl, u32 param, NNSG2dAnmCallBackPtr pFunc,
                                                  u16 frameIdx);
BOOL NNSi_G2dIsAnimCtrlLoopAnim(const NNSG2dAnimController *animCtrl);

// Cell animations: NNS_G2dInitCellAnimationVramTransfered transfers each cell's characters to VRAM as it is shown
void NNS_G2dInitCellAnimation(NNSG2dCellAnimation *cellAnim, const NNSG2dAnimSequence *seq,
                              const NNSG2dCellDataBank *bank);
void NNS_G2dInitCellAnimationVramTransfered(NNSG2dCellAnimation *cellAnim, const NNSG2dAnimSequence *seq,
                                            const NNSG2dCellDataBank *bank, u32 vramStateHandle, u32 dstAddr3D,
                                            u32 dstAddr2DMain, u32 dstAddr2DSub, const void *pSrcNCGR,
                                            const void *pSrcNCBR, u32 szSrcData);
void NNS_G2dSetCellAnimationSequence(NNSG2dCellAnimation *cellAnim, const NNSG2dAnimSequence *seq);
void NNS_G2dTickCellAnimation(NNSG2dCellAnimation *cellAnim, fx32 frames);
void NNS_G2dSetCellAnimationCurrentFrame(NNSG2dCellAnimation *cellAnim, u16 frameIdx);
void NNS_G2dRestartCellAnimation(NNSG2dCellAnimation *cellAnim);
void NNS_G2dSetCellAnimationSpeed(NNSG2dCellAnimation *cellAnim, fx32 speed);

// Multi-cell animations, whose work is NNS_G2dGetMCWorkAreaSize bytes
u32 NNS_G2dGetMCWorkAreaSize(const NNSG2dMultiCellDataBank *bank, u32 mcType);
void NNS_G2dInitMCAnimationInstance(NNSG2dMultiCellAnimation *mcAnim, void *work, const NNSG2dAnimBankData *anims,
                                    const NNSG2dCellDataBank *cells, const NNSG2dMultiCellDataBank *mcBank,
                                    u32 mcType);
void NNS_G2dSetAnimSequenceToMCAnimation(NNSG2dMultiCellAnimation *mcAnim, const NNSG2dAnimSequence *seq);
void NNS_G2dTickMCAnimation(NNSG2dMultiCellAnimation *mcAnim, fx32 frames);
void NNS_G2dSetMCAnimationCurrentFrame(NNSG2dMultiCellAnimation *mcAnim, u16 frameIdx);
void NNS_G2dSetMCAnimationSpeed(NNSG2dMultiCellAnimation *mcAnim, fx32 speed);
// Restarts each cell animation of a multi-cell instance
void NNS_G2dRestartMCCellAnimations(NNSG2dMultiCellInstance *instance);

// Where an image or palette is in VRAM, for the 3D engine and each 2D engine, and loading one there
typedef enum {
    NNS_G2D_VRAM_TYPE_3DMAIN,
    NNS_G2D_VRAM_TYPE_2DMAIN,
    NNS_G2D_VRAM_TYPE_2DSUB,
    NNS_G2D_VRAM_TYPE_MAX,
} NNSG2dVRamType;

#define NNS_G2D_VRAM_ADDR_NONE 0xffffffff

typedef struct {
    u32 baseAddrOfVram[NNS_G2D_VRAM_TYPE_MAX];
} NNSG2dVRamLocation;

typedef struct {
    u32 sizeS;
    u32 sizeT;
    u32 fmt;
    BOOL bExtendedPlt;
    u32 plttUse;
    u32 mappingType;
} NNSG2dImageAttr;

typedef struct {
    NNSG2dVRamLocation vramLocation;
    NNSG2dImageAttr attr;
} NNSG2dImageProxy;

typedef struct {
    u32 fmt;
    BOOL bExtendedPlt;
    NNSG2dVRamLocation vramLocation;
} NNSG2dImagePaletteProxy;

void NNS_G2dInitImageProxy(NNSG2dImageProxy *proxy);
u32 NNS_G2dGetImageLocation(const NNSG2dImageProxy *proxy, NNSG2dVRamType type);
BOOL NNS_G2dIsImageReadyToUse(const NNSG2dImageProxy *proxy, NNSG2dVRamType type);
void NNS_G2dInitImagePaletteProxy(NNSG2dImagePaletteProxy *proxy);
u32 NNS_G2dGetImagePaletteLocation(const NNSG2dImagePaletteProxy *proxy, NNSG2dVRamType type);
BOOL NNS_G2dIsImagePaletteReadyToUse(const NNSG2dImagePaletteProxy *proxy, NNSG2dVRamType type);
void NNS_G2dLoadImage1DMapping(const NNSG2dCharacterData *data, u32 baseAddr, NNSG2dVRamType type,
                               NNSG2dImageProxy *proxy);
void NNS_G2dLoadImage2DMapping(const NNSG2dCharacterData *data, u32 baseAddr, NNSG2dVRamType type,
                               NNSG2dImageProxy *proxy);
void NNS_G2dLoadImageVramTransfer(const NNSG2dCharacterData *data, u32 baseAddr, NNSG2dVRamType type,
                                  NNSG2dImageProxy *proxy);
void NNS_G2dLoadPalette(const NNSG2dPaletteData *data, u32 addr, NNSG2dVRamType type, NNSG2dImagePaletteProxy *proxy);
void NNS_G2dLoadPaletteEx(const NNSG2dPaletteData *data, const NNSG2dPaletteCompressInfo *cmpInfo, u32 addr,
                          NNSG2dVRamType type, NNSG2dImagePaletteProxy *proxy);

// The OAM managers, each of a range of OAMs of an engine, which they fill each frame and send at the vertical blank
enum {
    NNS_G2D_OAMTYPE_MAIN,
    NNS_G2D_OAMTYPE_SUB,
    NNS_G2D_OAMTYPE_SOFTWAREEMULATION,
    NNS_G2D_OAMTYPE_MAX,
};

// The affine index of an OAM that uses no affine parameters, and what NNS_G2dEntryOamManagerAffine returns when full
#define NNS_G2D_OAM_AFFINE_IDX_NONE 0xfffe

// A range of OAMs or affine parameters that a manager owns, and the next one free
typedef struct {
    u16 fromIdx;
    u16 toIdx;
    u16 currentIdx;
} NNSG2dOamManagedRegion;

typedef struct {
    u32 type;
    NNSG2dOamManagedRegion managedAttrRegion;
    NNSG2dOamManagedRegion managedAffineRegion;
    u16 managerID;
    BOOL bFastTransferMode;
    fx32 spriteZoffsetStep;
} NNSG2dOamManagerInstance;

void NNS_G2dInitOamManagerModule(void);
BOOL NNS_G2dGetNewOamManagerInstanceAsFastTransferMode(NNSG2dOamManagerInstance *man, u16 from, u16 num, u32 type);
BOOL NNS_G2dEntryOamManagerOamWithAffineIdx(NNSG2dOamManagerInstance *man, const GXOamAttr *oam, u16 affineIdx);
u16 NNS_G2dEntryOamManagerAffine(NNSG2dOamManagerInstance *man, const MtxFx22 *mtx);
// Sends the manager's OAMs and affine parameters to the hardware. swan calls it NNS_G2dApplyAndResetOamManagerBuffer
void NNS_G2dApplyOamManagerToHW(NNSG2dOamManagerInstance *man);
void NNS_G2dResetOamManagerBuffer(NNSG2dOamManagerInstance *man);

// The renderer, which draws cells to the surfaces of the screens
typedef struct {
    fx32 x;
    fx32 y;
} NNSG2dFVec2;

typedef struct {
    NNSG2dFVec2 posTopLeft;
    NNSG2dFVec2 sizeView;
} NNSG2dViewRect;

enum {
    NNS_G2D_SURFACETYPE_MAIN3D,
    NNS_G2D_SURFACETYPE_MAIN2D,
    NNS_G2D_SURFACETYPE_SUB2D,
};

typedef BOOL (*NNSG2dOamRegisterFunction)(const GXOamAttr *oam, u16 affineIdx, BOOL doubleAffine);
typedef u16 (*NNSG2dAffineRegisterFunction)(const MtxFx22 *mtx);
typedef BOOL (*NNSG2dRndCellCullingFunction)(const NNSG2dCellData *cell, const MtxFx32 *mtx,
                                             const NNSG2dViewRect *view);

typedef struct NNSG2dRenderSurface {
    NNSG2dViewRect viewRect;
    BOOL bActive;
    u32 type;
    u8 unk18[0x10];
    NNSG2dOamRegisterFunction pFuncOamRegister;
    NNSG2dAffineRegisterFunction pFuncOamAffineRegister;
    void *unk30;
    NNSG2dRndCellCullingFunction pFuncVisibilityCulling;
    u8 unk38[8];
    void *unk40;
    struct NNSG2dRenderSurface *pNextSurface;
} NNSG2dRenderSurface;

typedef struct {
    u8 unk0[0x30];
    BOOL unk30;
    u8 unk34[0x4c];
    u32 unk80;
    u8 unk84[0x14];
} NNSG2dRendererInstance;

void NNS_G2dInitRenderer(NNSG2dRendererInstance *rend);
void NNS_G2dAddRendererTargetSurface(NNSG2dRendererInstance *rend, NNSG2dRenderSurface *surface);
void NNS_G2dInitRenderSurface(NNSG2dRenderSurface *surface);

// The cell transfer state manager, which transfers the characters of cell animations made with
// NNS_G2dInitCellAnimationVramTransfered through a callback
typedef struct {
    u8 data[0x30];
} NNSG2dCellTransferState;

typedef BOOL (*NNSG2dDmaCallBack)(u32 type, u32 dstAddr, void *pSrc, u32 szByte);

void NNS_G2dInitCellTransferStateManager(NNSG2dCellTransferState *states, u32 numCellState, NNSG2dDmaCallBack callback);
void NNS_G2dUpdateCellTransferStateManager(void);
u32 NNS_G2dGetNewCellTransferStateHandle(void);
void NNS_G2dFreeCellTransferStateHandle(u32 handle);

#endif // POKEBW2_NNSYS_G2D_H
