#ifndef SLIB_STRINGS_H_
#define SLIB_STRINGS_H_

#include "./types.h"

bool starts_with(const char *restrict string, const char *restrict prefix);
size_t in_str_vec(const char* check, const char** vec, const size_t vec_len);

#endif // SLIB_STRINGS_H_
