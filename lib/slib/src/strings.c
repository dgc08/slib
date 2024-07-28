#include "../strings.h"
#include <string.h>

size_t in_str_vec(const char* check, const char** vec, const size_t vec_len) {
    for (size_t i = 0; i < vec_len; i++) {
        if (strcmp(vec[i], check) == 0) {
            return i+1;
        }
    }
    return false;
}

bool starts_with(const char *restrict string, const char *restrict prefix) {
    while(*prefix) {
        if(*prefix++ != *string++)
            return false;
    }
    return true;
}
