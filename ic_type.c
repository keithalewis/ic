// ic_type.c
#include <stdlib.h>
#include <ffi.h>
#include "ic_type.h"

// ic type id to ffi_type
#define FFI_TYPE_TABLE(X) \
    X(SCHAR, schar) \
    X(UCHAR, uchar) \
    X(SINT, sint) \
    X(UINT, uint) \
    X(POINTER, pointer) \

#define X(a,b) [IC_TYPE_##a] = &ffi_type_##b,
static ffi_type* ic_ffi_type_map[] = {
    FFI_TYPE_TABLE(X)
};
#undef X

typedef struct {
    ffi_type type;
    char data[];
} ic_type_struct;

void* ic_type_make(ic_type_enum id)
{
	ffi_type* ptype = ic_ffi_type_map[id];

    ic_type_struct* type = malloc(sizeof(ic_type_struct) + ptype->size);
	if (type) {
		type->type = *ptype;
	}

    return type;
}
