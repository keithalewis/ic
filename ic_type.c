// ic_type.c
#include <stdlib.h>
#include <ffi.h>
#include "ic_type.h"

// ic type id to ffi_type
#define FFI_TYPE_TABLE(X) \
    X(CHAR, schar) \
    X(UHAR, uchar) \
    X(INT, sint) \
    X(UINT, uint) \
    X(POINTER, POINTER) \

#define X(a,b) [IC_TYPE_##a] = FFI_TYPE_##b,
static ic_ffi_type_map[] = {
    FFI_TYPE_TABLE(X)
};
#undef X

typedef struct {
    ffi_type type;
    char data[];
} ic_type_struct;

void* ic_type_make(ic_type_enum id)
{
    ic_type_struct* type = 0;

    if (id == IC_TYPE_INT) {
        type = malloc(sizeof(ic_type_struct) + sizeof(int));
        if (type) {
            type->type = ffi_type_sint;
        }
    }

    return type;
}
