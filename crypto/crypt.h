#ifndef CRYPT_H
#define CRYPT_H
#include "picohash.h"

static unsigned char * MD5(const unsigned char *d, unsigned long n, unsigned char *md);


static inline unsigned char * MD5(const unsigned char *key, unsigned long len, unsigned char *hash) {
    picohash_ctx_t ctx;
    picohash_init_md5(&ctx);
    picohash_update(&ctx, key, len);
    picohash_final(&ctx, hash);
    picohash_reset(&ctx);
    return hash;
}
#endif