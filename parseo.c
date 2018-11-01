//
// Created by agustin on 01/11/18.
//

#include "parseo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void parsear(char path, char delim) {


    char str[] = "Geeks-for-Geeks";

    // Returns first token
    char *token = strtok(str, "-");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "-");
    }

}