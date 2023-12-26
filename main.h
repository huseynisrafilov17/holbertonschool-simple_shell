#ifndef MAIN_H
#define MAIN_H

int delim_counter(char *str);
char **token_parse(char *str);
void free_tokens(char **strarr);

#endif
