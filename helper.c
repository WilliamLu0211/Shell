#include "helper.h"

// int execute(char* input, char* dir){
//
//   execvp(args[0], args);
//   return 0;
// }

int cd(char* arg, char* dir){
  char ** new = parse_args(arg, "/");
  char ** old = parse_args(dir, "/");
}

char** parse_args(char* line, char* delim){
  char** args = calloc(16, sizeof(char*));
  int i = 0;
  while (line){
    args[i] = strsep(&line, delim);
    i ++;
  }
  args[i] = 0;
  return args;
}
