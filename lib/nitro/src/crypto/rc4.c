// NitroSDK's RC4 (libcrypto's rc4.c), linked at the end of the game's own code in ARM9 main. The names are the SDK's;
// CRYPTO_RC4Encrypt was hand-written assembly in the original (an odd register list, stores through the advanced
// context pointer, loads scheduled across iterations), so its C here doesn't match.
#include "nitro/crypto/rc4.h"

// The longest key used: the rest of a longer one is ignored
#define RC4_KEY_LEN_MAX 16

void CRYPTO_RC4Init(CRYPTORC4Context *context, const void *key, u32 key_len) {
    const u8 *keyBytes = key;
    u8 *s;
    int i;
    u8 k;
    u8 j;

    if (key_len > RC4_KEY_LEN_MAX) {
        key_len = RC4_KEY_LEN_MAX;
    }
    context->i = 0;
    context->j = 0;
    s = context->s;
    for (i = 0; i < 256; i++) {
        s[i] = i;
    }
    j = 0;
    k = 0;
    for (i = 0; i < 256; i++) {
        u8 t = s[i];

        j = j + (t + keyBytes[k]);
        k++;
        if (k == (u8)key_len) {
            k = 0;
        }
        s[i] = s[j];
        s[j] = t;
    }
}

void CRYPTO_RC4Encrypt(CRYPTORC4Context *context, const void *in, u32 length, void *out) {
    const u8 *src = in;
    u8 *dst = out;
    u8 *s = context->s;
    u8 i = context->i;
    u8 j = context->j;

    while (length-- != 0) {
        u8 x;
        u8 y;

        i++;
        x = s[i];
        j += x;
        y = s[j];
        s[i] = y;
        s[j] = x;
        *dst++ = *src++ ^ s[(u8)(x + y)];
    }
    context->i = i;
    context->j = j;
}
