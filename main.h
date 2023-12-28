#ifndef MAIN_H
#define MAIN_H

int delim_counter(char *str, char *delim);
char **token_parse(char *str, char *delim);
char *check_file(char **path_arr, char *filepath, int *flag);
void execute(char **args);

#endif
