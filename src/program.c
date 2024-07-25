#include "../program.h"
#include "lib/slib/types.h"

#include <string.h>

/* String array handling */

int in_str_vec(const char* check, char** vec, size_t vec_len) {
    for (size_t i = 0; i < vec_len; i++) {
        if (strcmp(vec[i], check) == 0) {
            return i;
        }
    }
    return false;
}

/* Command line argument stuff */

char** SLIB_args;
size_t SLIB_args_len;

void setup_slib_args(char** args, size_t args_len) {
    SLIB_args = args;
    SLIB_args_len = args_len;
}

int got_flag(const char* check) {
    /* Check if a special flag is in the command line */
    return in_str_vec(check, SLIB_args, SLIB_args_len);
}

void get_pos_args(size_t start, char* pos_args[], byte* len) {
    /* Gets the first 255 positional arguments as array */
    *len = 0;
    while (start < SLIB_args_len && *len < 255) {
        if (SLIB_args[start][0] != '-') {
            pos_args[(*len)++] = SLIB_args[start];
        }
        start++;
    }
}

/* Error handling */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void throw_error_errno(char* error_msg) {
    fprintf(stderr, "Excpetion in program, Error: ");
    strerror(errno);
    fprintf(stderr, "Error Message by Caller: %s\n", error_msg);
    exit(1);
}
void throw_error(char* error_msg) {
    fprintf(stderr, "Exception in program\n");
    fprintf(stderr, "Error Message by Caller: %s\n", error_msg);
    exit(1);
}
