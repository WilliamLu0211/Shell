#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int execute(char* piece);

int get_length(char** args);

char** rm_space(char** args);

char** parse_args(char* line, char* delim);
