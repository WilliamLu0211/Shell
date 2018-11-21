#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int execute(char* input, char* dir);

char** parse_args(char* line, char* delim);
