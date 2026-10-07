#ifndef POKEBW2_STDDEF_H
#define POKEBW2_STDDEF_H

// The C library's stddef.h, as MWCC's library has it for ARM
typedef unsigned long size_t;

#define offsetof(type, member) ((size_t)&(((type *)0)->member))

#endif // POKEBW2_STDDEF_H
