#include "helper.h"

char** parse_args(char* line){
  char** args = calloc(6, sizeof(char*));
  int i = 0;
  while (line){
    args[i] = strsep(&line, " ");
    i ++;
  }
  args[i] = 0;
  return args;
}
