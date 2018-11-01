//
// Created by agustin on 30/10/18.
//


#ifndef TP2_FUNC_H
#define TP2_FUNC_H

int string_parser( const char *input, char ***word_array );
int path_parser( const char *input, char ***word_array );
int var_path_parser( const char *input, char ***word_array );

int iscolon(int);
int isbarra(int);
void path_relativo(char *path);
void path_absoluto(char *str[]);
void env_path();
void detector();


#endif //TP2_FUNC_H


