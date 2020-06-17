// ic_dict.h - dictionary
#pragma once

typedef void* ic_dict;

ic_dict ic_dict_make(size_t);
void ic_dict_free(ic_dict);

// push value of key at back of current or next dictionary
void* ic_dict_put(ic_dict dict, const char* key, const void* data, size_t size);
// find value of key in current or next dictionary
const void* ic_dict_get(ic_dict dict, const char* key, size_t* size);

// push new dict on top of stack
ic_dict ic_dict_push(ic_dict);
// pop dict off top of stack
ic_dict ic_dict_pop(ic_dict);

ic_dict ic_dict_prev(ic_dict);
ic_dict ic_dict_prev_add(ic_dict);
ic_dict ic_dict_prev_del(ic_dict);

ic_dict ic_dict_next(ic_dict);
ic_dict ic_dict_next_add(ic_dict);
ic_dict ic_dict_next_del(ic_dict);
