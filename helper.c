#include "helper.h"

int execute(char* piece){
  int f, status;
  char** args = parse_args(piece, " ");
  if ( !strcmp(args[0], "cd") )
    chdir(args[1]);

  else if ( !strcmp(args[0], "exit") )
    // exit(0);
    return 1;

  else{
    f = fork();
    if (!f)
      execvp(args[0], args);
      // return 0;
    // else{
    wait(&status);
  }
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
  char** args = calloc(strlen(line), sizeof(char*));
  int i = 0;
  while (line){
    args[i] = strsep(&line, delim);
    i ++;
  }
  //printf("%p\n", line);
  args[i] = 0;
  return rm_space(args);
}
