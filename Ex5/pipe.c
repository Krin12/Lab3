#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 256

int main() {

    int pipe_fd[2];
    pid_t pid;
    char message[] = "Hello, child!";

    if (pipe(pipe_fd) == -1) {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("prcess fail");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        close(pipe_fd[1]);
        char buffer[BUFSIZE];
        read(pipe_fd[0], buffer, sizeof(buffer));
        printf("child: get message - %s\n", buffer);
        close(pipe_fd[0]);
        exit(EXIT_SUCCESS);

    } else {
        close(pipe_fd[0]);
        write(pipe_fd[1], message, strlen(message) + 1);
        close(pipe_fd[1]);
        wait(NULL);
    }

    return 0;

}
