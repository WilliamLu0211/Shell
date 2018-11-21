#include "helper.h"

int execute(char* input, char* dir){
  char ** args = parse_args( input, " " );
  if ( !strcmp(args[0], "cd") )
    return chdir(args[1]);
  execvp(args[0], args);
  return 0;
}

char** parse_args(char* line, char* delim){
  char** args = calloc(1,6 * sizeof(char*));
  int i = 0;
  while (line){
    args[i] = strsep(&line, delim);
    i ++;
  }
  args[i] = 0;
  return args;
}
