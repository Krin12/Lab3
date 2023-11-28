#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t received = 0;

void sig_handler(int signo) {
    if (signo == SIGUSR1) {
        received = 1;
    }
}

int main() {

    pid_t pid;

    if (signal(SIGUSR1, sig_handler) == SIG_ERR) {
        perror("signal fail");
        exit(EXIT_FAILURE);
    }
    
    pid = fork();

    if (pid < 0) {
        perror("process fail");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("cjild: my PID=%d, parent PID=%d\n", getpid(), getppid());
        kill(getppid(), SIGUSR1);
        exit(EXIT_SUCCESS);
    } else {
        printf("parent: my PID=%d, child PID=%d\n", getpid(), pid);
        while (!received) {
            sleep(1);
        }
        printf("parent: Get signal.\n");
    }
    
    return 0;

}
