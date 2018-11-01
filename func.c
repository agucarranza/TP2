//
// Created by agustin on 30/10/18.
//
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
#include <sys/stat.h>

int string_parser( const char *input, char ***word_array)
{
    int n = 0;
    const char *p = input;

    while ( *p )
    {
        while ( isspace( ( unsigned char )*p ) ) ++p;
        n += *p != '\0';
        while ( *p && !isspace( ( unsigned char )*p ) ) ++p;
    }

    if ( n )
    {
        size_t i = 0;

        *word_array = malloc( n * sizeof( char * ) );

        p = input;

        while ( *p )
        {
            while ( isspace( ( unsigned char )*p ) ) ++p;
            if ( *p )
            {
                const char *q = p;
                while ( *p && !isspace( ( unsigned char )*p ) ) ++p;

                size_t length = p - q;

                ( *word_array )[i] = ( char * )malloc( length + 1 );

                strncpy( ( *word_array )[i], q, length );
                ( *word_array )[i][length] = '\0';

                ++i;
            }
        }
    }

    return n;
}

int path_parser( const char *input, char ***word_array)
{
    int n = 0;
    const char *p = input;

    while ( *p )
    {
        while ( isbarra( ( unsigned char )*p ) ) ++p; //cambiar que corte con los dos puntos
        n += *p != '\0';
        while ( *p && !isbarra( ( unsigned char )*p ) ) ++p;
    }

    if ( n )
    {
        size_t i = 0;

        *word_array = malloc( n * sizeof( char * ) );

        p = input;

        while ( *p )
        {
            while ( isbarra( ( unsigned char )*p ) ) ++p;
            if ( *p )
            {
                const char *q = p;
                while ( *p && !isbarra( ( unsigned char )*p ) ) ++p;

                size_t length = p - q;

                ( *word_array )[i] = ( char * )malloc( length + 1 );

                strncpy( ( *word_array )[i], q, length );
                ( *word_array )[i][length] = '\0';

                ++i;
            }
        }
    }

    return n;
}

int var_path_parser( const char *input, char ***word_array)
{
    int n = 0;
    const char *p = input;

    while ( *p )
    {
        while ( iscolon( ( unsigned char )*p ) ) ++p; //cambiar que corte con los dos puntos
        n += *p != '\0';
        while ( *p && !iscolon( ( unsigned char )*p ) ) ++p;
    }

    if ( n )
    {
        size_t i = 0;

        *word_array = malloc( n * sizeof( char * ) );

        p = input;

        while ( *p )
        {
            while ( iscolon( ( unsigned char )*p ) ) ++p;
            if ( *p )
            {
                const char *q = p;
                while ( *p && !iscolon( ( unsigned char )*p ) ) ++p;

                size_t length = p - q;

                ( *word_array )[i] = ( char * )malloc( length + 1 );

                strncpy( ( *word_array )[i], q, length );
                ( *word_array )[i][length] = '\0';

                ++i;
            }
        }
    }

    return n;
}

int isbarra(int c) {
    return c != 47 ? 0 : 1;
}

int iscolon(int c) {
    return c != 58 ? 0 : 1;
}

void path_absoluto(char *str[]) {  //el path de execv tiene que terminar en null

    printf("%s",str);

    pid_t pid;
    char *const parmList[] = {"/bin/ls", "-l", "/u/userid/dirname", NULL};

    if ((pid = fork()) == -1)
        perror("fork error");
    else if (pid == 0) {
        execv("/bin/ls", parmList);
        printf("Return not expected. Must be an execv error.n");
    }

}

//esta funcion tiene que devolver el path armado como si fuera
//absoluto. el absoluto como está y asi

void path_relativo(char *path) {

    char *buffer;

    strcpy(&buffer,&path);

    //printf("el path es: %s\n",path);

   // strcpy(&buffer,&path);

   // printf("el buffer es: %s\n",buffer);

    //encontrar el primer caracter de la cadena
 //   ret = strpbrk(buffer,"./~");





    //printf("el archivo exite? Resp = %i\n",access (path, F_OK));




          // getcwd()sizeof()




    }


