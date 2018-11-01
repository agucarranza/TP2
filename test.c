//
// Created by agustin on 30/10/18.
//
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


int main() {

    char *argumentos[]= { "/bin/date", NULL };

    printf("antes de fork pid = %i\n", getpid());
    int pid = fork();
    // printf("pase por aca\n");
    //   printf("%i\n",s);
    if (pid == 0) {
        /*printf("hijo");*/
        //printf("pid nº %i, return del fork = %i, soy el hijo\n", getpid(), pid);

        while (1) {
            execv("/bin/date", argumentos ); //exit(1);
            sleep(1);
        }



    }


    else {

       // printf("pid nº %i, return del fork = %i, soy el padre\n", getpid(), pid);
        wait();
        printf("el hijo termino, entonces vuelve el padre\n"); sleep(1);
    }
}

