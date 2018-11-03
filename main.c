#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
#include <linux/limits.h>
#include "func.h"
#include "ejecucion.h"

static void handler();

int main(int argc, char *argv[]) {

    char *buf = NULL;
    size_t size = PATH_MAX;
    signal(SIGINT, handler);
    char *command = strdup(argv[1]);
    char *path_absoluto = "HUBO UN ERROR";
    char *current_path = getcwd(buf, size);
    char *parent_dir = dirname(strdup(current_path));
    char *argumento_relativo;
    char *tipo_camino;
    char *env_var = strdup(getenv("PATH"));
    char *home_path = getenv("HOME");
    free(buf);

    //while (1)  {
  //  printf("%s@%s:%s$", getenv("USER"),gethostname(),getenv("PWD"));

    for (int i = 0; i < argc; i++) {
        printf("argv[%i] = %s\n", i, argv[i]);
    }
    if (*argv[1] == '/') {
        path_absoluto = argv[1];
        puts("ES UN CAMINO ABSOLUTO");
    } else {

        argumento_relativo = strtok(command, "/");
        tipo_camino = argumento_relativo;
        argumento_relativo = strtok(NULL, "");
        printf("el tipo de camino sera %s\n", tipo_camino);
        printf("argumento relativo: %s\n", argumento_relativo);

        if (!strcmp(tipo_camino, "..")) {

            path_absoluto = strcat(strcat(parent_dir, "/"), argumento_relativo);
            printf("Revisando el path relativo ..\n");
        } else if (!strcmp(tipo_camino, ".")) {
            printf("Revisando el path relativo .\n");
            path_absoluto = strcat(strcat(current_path, "/"), argumento_relativo);
        } else if (!strcmp(tipo_camino, "~")) {
            printf("Revisando el path relativo ~\n");
            path_absoluto = strcat(strcat(home_path, "/"), argumento_relativo);
        } else if ((*argv[1] != '/') && argumento_relativo == NULL) {
            buf = "\0";
            char *token;
            command = strcat(strdup("/"), command);
            token = strtok(env_var, ":");
            path_absoluto = strcat(strdup(token), command);
            printf("%s\n", path_absoluto);
            buf = strcat(strdup(buf), token);
            while (token = strtok(0, ":")) {
                path_absoluto = strcat(strdup(token), command);
                printf("%s\n", path_absoluto);
            }

        }

        printf("path abs = %s\n", path_absoluto);
    }
    fork();
    execv(argv[1],argv);
    //if (getpid());

    //execute(path_absoluto);
}

static void handler() {
    printf("\nEl usuario mando un Ctrl+C\n");
    exit(1);
}
