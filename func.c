//
// Created by agustin on 30/10/18.
//
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
#include <sys/stat.h>


void execute (char *path_absoluto) {

    puts(path_absoluto);
fork();
__pid_t pid;
pid = getpid();
    printf("pid = %i\n",pid);
execv("/bin/date","/bin/date");




}




