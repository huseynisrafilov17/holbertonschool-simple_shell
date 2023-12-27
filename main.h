#ifndef MAIN_H
#define MAIN_H

int delim_counter(char *str, char *delim);
char **token_parse(char *str, char *delim);
int check_file(char *path, char *filepath);

#endif
