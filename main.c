#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
#include "func.h"
#include "parseo.h"


static void handler();

int main(int argc, char *argv[]) {

    int path_largo = 0;
    int var_path_largo = 0;
    signal(SIGINT, handler);
    char *str;
    char **path_array = NULL;
    char **word_array = NULL;
    char **var_path_array = NULL;
    char *env_path = getenv("PATH");

    //while (1)  {
    str = "./home/agustin/CLionProjects/TP2/cmake-build-debug/TP2 y tu abuelita tambien";

    //gets(str);

//        argc = string_parser(str, &word_array);
//        for (size_t i = 0; i < argc; i++) {
//            argv[i] = word_array[i];
//            printf("%s\n", word_array[i]);
//        }
//
//        path_largo = path_parser(word_array[0], &path_array);
//        for (size_t j = 0; j < path_largo; j++) {
//            printf("%s\n", path_array[j]);
//        }
//
//        var_path_largo = var_path_parser(env_path, &var_path_array);
//        for (size_t k = 0; k < var_path_largo; k++) {
//            printf("%s\n", var_path_array[k]);
//        }


//path_relativo(word_array[0]);

parsear(str, '-');

}

static void handler() {
    printf("\nEl usuario mando un Ctrl+C\n");
    exit(1);
}
