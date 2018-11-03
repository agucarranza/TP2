//
// Created by agustin on 03/11/18.
//
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "ejecucion.h"

char* strerror();
void waitpid();

int executeCmd(char** params)
{
    // Fork process
    pid_t pid = fork();

    // Error
    if (pid == -1) {
        char* error = strerror(errno);
        printf("fork: %s\n", error);
        return 1;
    }

        // Child process
    else if (pid == 0) {
        // Execute command
        execvp(params[0], params);

        // Error occurred
        char* error = strerror(errno);
        printf("shell: %s: %s\n", params[0], error);
        return 0;
    }

        // Parent process
    else {
        // Wait for child process to finish
        int childStatus;
        waitpid(pid, &childStatus, 0);
        return 1;
    }
}
