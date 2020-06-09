// ic_type.h - C types
#pragma once
#include <stdint.h>

#define IC_TYPE(X)   \
    X(IC_CHAR, signed char) \
    X(IC_UCHAR, unsigned char) \
    X(IC_INT, signed int) \
    X(IC_UINT, unsigned int) \
    \
    X(IC_INT32, int32_t) \
    X(IC_UINT32, uint32_t) \
    X(IC_PTR, void*)
    // ...

#define X(a,b) a,
enum ic_type {
    IC_TYPE(X)
};
#undef X
