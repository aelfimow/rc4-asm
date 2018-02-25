#ifdef RC4FUNC_H
#error Already included
#else
#define RC4FUNC_H

extern "C" void rc4init(const void *key, size_t L, void *sbox);
extern "C" void rc4run(const void *buf_in, size_t len, void *buf_out, void *sbox);

#endif
