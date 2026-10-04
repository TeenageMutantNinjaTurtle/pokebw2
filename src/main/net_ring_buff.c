#include "types.h"
#include "gfl/net.h"
#include "gfl/net_ring_buff.h"
#include "gfl/std.h"

static int func_0203e09c(NetRingBuff *ring, u8 *dest, int size, int max);
static int func_0203e120(NetRingBuff *ring, int pos);
static int func_0203e130(NetRingBuff *ring);

void func_0203dfc0(NetRingBuff *ring, u8 *pDataArea, int size) {
    ring->pDataArea = pDataArea;
    ring->size = (s16)size;
    ring->startPos = 0;
    ring->endPos = 0;
}

void func_0203dfd0(NetRingBuff *ring, const u8 *pDataArea, int size) {
    int i;
    int j;

    if (func_0203e130(ring) <= size) {
        func_02040158();
        return;
    }
    j = 0;
    for (i = ring->endPos; i < ring->endPos + size; i++, j++) {
        GFL_ASSERT(pDataArea);
        ring->pDataArea[func_0203e120(ring, i)] = pDataArea[j];
    }
    ring->endPos = func_0203e120(ring, i);
}

int func_0203e038(NetRingBuff *ring, u8 *dest, int size, int max) {
    int read = func_0203e09c(ring, dest, size, max);

    ring->startPos = func_0203e120(ring, ring->startPos + read);
    return read;
}

u8 func_0203e054(NetRingBuff *ring) {
    u8 byte;

    if (func_0203e038(ring, &byte, 1, 1) == 1) {
        return byte;
    }
    GFL_ASSERT(0);
    return 0;
}

u16 func_0203e080(NetRingBuff *ring) {
    u16 high = func_0203e054(ring) << 8;

    return high | func_0203e054(ring);
}

static int func_0203e09c(NetRingBuff *ring, u8 *dest, int size, int max) {
    int i;
    int j = 0;

    for (i = ring->startPos; i < ring->startPos + size; i++) {
        if (ring->endPos == func_0203e120(ring, i) || j == max) {
            return j;
        }
        dest[j] = ring->pDataArea[func_0203e120(ring, i)];
        j++;
    }
    return j;
}

// The bytes written but not read
int func_0203e0f4(NetRingBuff *ring) {
    if (ring->startPos > ring->endPos) {
        return ring->size + ring->endPos - ring->startPos;
    }
    return ring->endPos - ring->startPos;
}

// The bytes that can be written
int func_0203e110(NetRingBuff *ring) {
    return ring->size - func_0203e0f4(ring);
}

static int func_0203e120(NetRingBuff *ring, int pos) {
    return pos % ring->size;
}

static int func_0203e130(NetRingBuff *ring) {
    int end;

    if (ring->startPos > ring->endPos) {
        end = ring->size + ring->endPos;
    } else {
        end = ring->endPos;
    }
    end -= ring->startPos;
    return ring->size - end;
}

void func_0203e150(NetRingBuff *ring) {
}
