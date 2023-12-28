#ifndef MAIN_H
#define MAIN_H

extern char **environ;

int delim_counter(char *str, char *delim);
char **token_parse(char *str, char *delim);
char *check_file(char **path_arr, char *filepath, int *flag);
int execute(char **args, char *filename);

#endif
