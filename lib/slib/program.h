#ifndef SLIB_PROGRAM_H_
#define SLIB_PROGRAM_H_

#include "types.h"

size_t in_str_vec(const char* check, char** vec, size_t vec_len);

extern char** SLIB_args;
extern size_t SLIB_args_len;
void setup_slib_args(char** args, size_t args_len);
size_t got_flag(const char* check);
void get_pos_args(size_t start, char* pos_args[], size_t* len);


#endif // SLIB_PROGRAM_H_