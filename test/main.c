#include "slib/exceptions.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    SLIB_try();
    throw_exception("hey", SLIB_OSError);
    int e = SLIB_except();
    printf("First: %d %s \n", e, SLIB_get_error_message());

    SLIB_try();
    puts("woohoo");
    e = SLIB_except();
    printf("Second: %d %s \n", e, SLIB_get_error_message());
}
