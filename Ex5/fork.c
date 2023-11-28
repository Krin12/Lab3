#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t pid;
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Error\n");
        return 1;
    } else if (pid == 0) {
        printf("child: my PID=%d, parent PID=%d\n", getpid(), getppid());
        printf("child: Hello, parent! (child PID=%d)\n", getpid());
        exit(0);
    } else {
       printf("parent: my PID=%d, child PID=%d\n", getpid(), pid);
        wait(NULL);
        printf("parent: child is done.\n");
    }
    return 0;
}

