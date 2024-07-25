#ifndef SLIB_PROCESS_H_
#define SLIB_PROCESS_H_

#include <sys/types.h>

void disable_process_output();
pid_t fork_to(void (*func)());

#endif // SLIB_PROCESS_H_
