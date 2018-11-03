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
/*

int runcmd(char *cmd)
{
    char* argv[MAX_ARGS];
    pid_t child_pid;
    int child_status;

    parsecmd(cmd,argv);
    child_pid = fork();
    if(child_pid == 0) {
        */
/* This is done by the child process. *//*


        execv(argv[0], argv);

        */
/* If execv returns, it must have failed. *//*


        printf("Unknown command\n");
        exit(0);
    }
    else {
        */
/* This is run by the parent.  Wait for the child
           to terminate. *//*


        do {
            pid_t tpid = wait(&child_status);
            if(tpid != child_pid) process_terminated(tpid);
        } while(tpid != child_pid);

        return child_status;
    }
}
*/
