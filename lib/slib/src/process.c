#include "../process.h"
#include "../program.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include "../exceptions.h"

// Function to check if a process with a given PID is still running
int is_process_running(pid_t pid) {
    // kill with signal 0 does not send a signal, but performs error checking
    if (kill(pid, 0) == 0) {
        return 1; // Process exists
    } else if (errno == ESRCH) {
        return 0; // Process does not exist
    } else {
        throw_exception("Failed to invoke kill(pid, 0)", SLIB_OSError);
        return -1; // Error occurred, check errno for details
    }
}

pid_t fork_to(void (*func)()) {
    pid_t p;
    p = fork();
    if(p<0) {
        throw_exception("Couldn't fork to start external process", SLIB_OSError);
        return -1;
    }
    else if ( p == 0) {
        func();
        exit(0);
    }

    return p;
}

void disable_process_output() {
        int dev_null = open("/dev/null", O_WRONLY);
    if (dev_null == -1) {
        throw_exception("Failed to open /dev/null", SLIB_OSError);
        return;
    }
    dup2(dev_null, STDOUT_FILENO);
    dup2(dev_null, STDERR_FILENO);
    close(dev_null);

}
