#include "../process.h"
#include "../program.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

pid_t fork_to(void (*func)()) {
    pid_t p;
    p = fork();
    if(p<0) {
        throw_error("Couldn't fork to start external process");
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
        throw_error("Failed to open /dev/null");
        exit(1);
    }
    dup2(dev_null, STDOUT_FILENO);
    dup2(dev_null, STDERR_FILENO);
    close(dev_null);

}
