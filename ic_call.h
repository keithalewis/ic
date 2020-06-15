// ic_call.h - call C functions
#pragma once
#include "ic_type.h"

// call stack
void* ic_call_make(size_t);
void ic_call_free(void*);

void ic_call_push(void*, ic_type_enum, void*);
int ic_call(void*, void*);
