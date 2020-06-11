// ic_type.h - C types
#pragma once
#include <stdint.h>
#include <string.h>

//    id,        C type,        printf/scanf code
#define IC_TYPE(X)                                                             \
  X(IC_CHAR, signed char, c)                                                   \
  X(IC_UCHAR, unsigned char, c)                                                \
  X(IC_INT, signed int, i)                                                     \
  X(IC_UINT, unsigned int, u)                                                  \
  X(IC_UINT32, uint32_t, u8) /* PRI/SCN */                                     \
  X(IC_PTR, void *, p)
// ...

#define X(a, b, c) a,
typedef enum { IC_TYPE(X) } ic_type_enum;
#undef X

// pointer to architecture specific bits
typedef void *ic_type;

// unique identifier
int ic_type_id(ic_type);

// size in bytes of type including alignment
size_t ic_type_size(ic_type);

// address of type data
void *ic_type_addr(ic_type);

//
// memory management
//

ic_type ic_type_make(ic_type_enum);

// copy src to dest and return dest
ic_type ic_type_copy(ic_type dest, const ic_type src);

void ic_type_free(ic_type);

// number of members if a struct
size_t ic_type_items(ic_type);

// offset of member in struct
size_t ic_type_offset(ic_type, size_t);

// struct members
static inline ic_type ic_type_item(ic_type t, size_t i) {
  return ic_type_addr(t) + ic_type_offset(t, i);
}
