// ic_type.h - C types
#pragma once
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// clang-format off
//    id,        C type,        printf/scanf code
// !}column -t -s,
#define IC_TYPE(X)                       \
  X(SCHAR,         signed char,     c)   \
  X(UCHAR,         unsigned char,   c)   \
  X(SSHORT,        signed short,    i)   \
  X(USHORT,        unsigned short,  u)   \
  X(SINT,          signed int,      i)   \
  X(UINT,          unsigned int,    u)   \
  X(SLONG,         signed long,     li)  \
  X(ULONG,         unsigned long,   lu)  \
  X(FLOAT,         float,           f)   \
  X(DOUBLE         double,          lf)  \
  X(SINT8,         int8_t,          i8)  \
  X(SINT8,         int8_t,          i8)  \
  X(SINT16,        int16_t,         i16) \
  X(UINT16,        uint16_t,        u16) \
  X(UINT32,        uint32_t,        u32) \
  X(UINT32,        uint32_t,        u32) \
  X(SINT64,        int64_t,         i64) \
  X(UINT64,        uint64_t,        u64) \
  X(POINTER,       void *,          p)   \
// ...
// clang-format on

#define X(a, b, c) IC_TYPE_##a,
typedef enum { IC_TYPE(X) } ic_type_enum;
#undef X

// pointer to architecture specific bits
typedef void *ic_data;

//
// memory management
//

ic_data ic_type_make(ic_type_enum);

// copy src to dest and return dest
ic_data ic_type_copy(ic_data dest, ic_type_enum, const ic_data src);

void ic_type_free(ic_data);

/*
// unique identifier
int ic_type_id(ic_type);

// size in bytes of type including alignment
size_t ic_type_size(ic_type);

// address of type data
void *ic_type_addr(ic_type);

// number of members if a struct
size_t ic_type_items(ic_type);

// offset of member in struct
size_t ic_type_offset(ic_type, size_t);

// struct members
static inline ic_type ic_type_item(ic_type t, size_t i) {
  return ic_type_addr(t) + ic_type_offset(t, i);
}

// print to FILE*
int ic_type_print(FILE *, ic_type);
// scan to FILE*
int ic_type_scan(FILE *, ic_type);
*/
