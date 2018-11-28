#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

int execute(char* piece);

int get_length(char** args);

char** rm_space(char** args);

char** parse_args(char* line);

int my_input(char ** args);

int my_output(char ** args);

int my_append(char ** args);
