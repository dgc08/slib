#ifndef SLIB_EXCEPTIONS_H_
#define SLIB_EXCEPTIONS_H_

typedef enum {
    SLIB_NoError,
    SLIB_OSError,
} Exception;

void throw_error(char* error_msg);
void throw_error_errno(char* error_msg);
void throw_exception(char* error_msg, Exception exception);

void SLIB_try();
Exception SLIB_except();
char* SLIB_get_error_message();

#endif // SLIB_EXCEPTIONS_H_
