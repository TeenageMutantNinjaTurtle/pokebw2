#ifndef POKEBW2_DEMO_SHINKA_DEMO_VIEW_H
#define POKEBW2_DEMO_SHINKA_DEMO_VIEW_H

#include "types.h"

// Defined in shinka_demo_view.c

// Not referenced
extern const u32 SHINKA_DEMO_VIEW_UNK_774;
// The helix the pieces of the sprite gather into: its top, its height, and its distance from its axis at its ends and
// at its middle
extern const f32 SHINKA_DEMO_HELIX_TOP;
extern const f32 SHINKA_DEMO_HELIX_HEIGHT;
extern const f32 SHINKA_DEMO_HELIX_RADIUS_MAX;
extern const f32 SHINKA_DEMO_HELIX_RADIUS_MIN;

// Reconstructed, not known from the ROM. MWCC puts the constants above in the same section as the view's other data,
// as the original has them, only when some code reads them before their definitions, even code it never emits. These
// accessors are that code. Nothing calls them.
static inline u32 ShinkaDemoView_GetUnk774(void) {
    return SHINKA_DEMO_VIEW_UNK_774;
}

static inline f32 ShinkaDemoView_GetHelixTop(void) {
    return SHINKA_DEMO_HELIX_TOP;
}

static inline f32 ShinkaDemoView_GetHelixHeight(void) {
    return SHINKA_DEMO_HELIX_HEIGHT;
}

static inline f32 ShinkaDemoView_GetHelixRadiusMax(void) {
    return SHINKA_DEMO_HELIX_RADIUS_MAX;
}

static inline f32 ShinkaDemoView_GetHelixRadiusMin(void) {
    return SHINKA_DEMO_HELIX_RADIUS_MIN;
}

#endif // POKEBW2_DEMO_SHINKA_DEMO_VIEW_H
