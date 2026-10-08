#ifndef POKEBW2_NNSYS_G2DI_LOAD_H
#define POKEBW2_NNSYS_G2DI_LOAD_H

#include "nnsys/g2d.h"

// What G2D's file loaders share (the header's and the macro's names are ours): a loaded file stores its pointers as
// offsets from the start of the structure that holds them, or of another, and loading adds that base to each one in
// place
#define NNSi_G2dUnpackOffset(ptr, base) ((ptr) = (void *)((u32)(ptr) + (u32)(base)))

#endif // POKEBW2_NNSYS_G2DI_LOAD_H
