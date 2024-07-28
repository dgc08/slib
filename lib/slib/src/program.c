#include "../program.h"
#include "../types.h"
#include <stdio.h>
#include "../strings.h"

/* Command line argument stuff */

const char** SLIB_args;
size_t SLIB_args_len;

void setup_slib_args(char** args, const size_t args_len) {
    SLIB_args = (const char** )args;
    SLIB_args_len = args_len;
}

size_t got_flag(const char* check) {
    /* Check if a special flag is in the command line args */
    return in_str_vec(check, SLIB_args, SLIB_args_len);
}

void get_pos_args_full(size_t start, char* pos_args[], size_t* len) {
    size_t max_len = *len;
    *len = 0;

    while (start < SLIB_args_len && *len < max_len) {
        if (SLIB_args[start][0] != '-') {
            pos_args[(*len)++] = (char* )SLIB_args[start];
        }
        start++;
    }
}

void get_pos_args(size_t start, char* pos_args[], size_t* len) {
    /* Gets the first len positional arguments as array in pos_args,
     * which is initialised by the caller
     *
     * len will later on hold the length of the array
     *
     * Make sure to set the len to the allocated length of memory or -1 for practicall infinte space(UNSAFE)
     * */
    size_t has_double_dash = got_flag("--");
    start = has_double_dash ? has_double_dash : start;

    get_pos_args_full(start, pos_args, len);
}
