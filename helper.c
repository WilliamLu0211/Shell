#include "helper.h"

int execute(char* input, char* dir){
  char ** args = parse_args( input, " " );
  if ( !strcmp(args[0], "cd") )
    return chdir(args[1]);
  execvp(args[0], args);
  return 0;
}

int get_length(char** args){
  int length = 0;
  char* dummy = args[0];
  //printf("|%d|\n", dummy);
  while (dummy){
    length ++;
    dummy = args[length];
  }
  return length;
}

char** rm_space(char** args){
  int length = get_length(args);
  //printf("%d\n", length);
  char** new_args = calloc(length, sizeof(char*));
  int i, j = 0;
  for (i = 0; i < length; i ++)
    if ( strcmp(args[i], "") ){
      //printf("$");
      new_args[j] = args[i];
      j ++;
    }

  return new_args;
}

char** parse_args(char* line, char* delim){
  char** args = calloc(16, sizeof(char*));
  int i = 0;
  while (line){
    args[i] = strsep(&line, delim);
    i ++;
  }
  //printf("%p\n", line);
  args[i] = 0;
  return rm_space(args);
}

