#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int launcher(char **args, char **env);
int executor(char **args, char **env);
char *read_line_01(void);
char *read_line_02(void);
char **split_line(char *line);


#endif
