#ifndef SLIB_PROCESS_H_
#define SLIB_PROCESS_H_

#include "types.h"

void disable_process_output();
pid_t fork_to(void (*func)());
int is_process_running(pid_t pid);

#endif // SLIB_PROCESS_H_
