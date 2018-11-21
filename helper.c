#include "helper.h"

// int execute(char* input, char* dir){
//
//   execvp(args[0], args);
//   return 0;
// }

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
