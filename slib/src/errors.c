/* Error handling */
#include "../program.h"
#include "../exceptions.h"

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include <string.h>

bool in_try = false;
Exception catched_error = SLIB_NoError;
char* err_msg = NULL;

void throw_error(char* error_msg) {
    fprintf(stderr, "Exception in program\n");
    fprintf(stderr, "Error Message by Caller: %s\n", error_msg);
    exit(1);
}

void throw_error_errno(char* error_msg) {
    fprintf(stderr, "Excpetion in program, Error: ");
    strerror(errno);
    fprintf(stderr, "Error Message by Caller: %s\n", error_msg);
    exit(1);
}

void throw_exception(char* error_msg, Exception exception) {
    if (in_try) {
        catched_error = exception;
        err_msg = error_msg;
    }
    else {
        throw_error(error_msg);
    }
}

void SLIB_try() {
    in_try = true;
    catched_error = SLIB_NoError;
    err_msg = NULL;
}

Exception SLIB_except() {
    in_try = false;
    return catched_error;
}

char* SLIB_get_error_message() {
    return err_msg;
}
