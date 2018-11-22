#include "helper.h"

int execute(char* piece){
  int f, status;

  char** args = parse_args(piece);
  // for (int i = 0; args[i]; i ++)
  //   printf("[%s]\n", args[i]);
  if ( !strcmp(args[0], "cd") )
    chdir(args[1]);

  else if ( !strcmp(args[0], "exit") )
    // exit(0);
    return 1;

  else {
    f = fork();
    if (!f)
      execvp(args[0], args);
      // return 0;
    wait(&status);
  }
  free(args);
  return 0;
}

int get_length(char** args){
  int length = 0;
  //printf("|%d|\n", dummy);
  while (args[length])
    length ++;
  return length;
}

char** rm_space(char** args){
  int length = get_length(args);
  int i, j;
  for (int i = 0; i < length; i ++)
    if ( !strcmp(args[i], "") ){
      for (j = i; j < length - 1; j ++)
        args[j] = args[j + 1];
      args[j] = 0;
      length --;
      i --;
    }
  return args;
}

char** parse_args(char* line){
  char** args = calloc(strlen(line), sizeof(char*)); // error aborted
  // printf("%ld\n", strlen(line) * sizeof(char*));
  int i;
  for (i = 0; line; i ++)
    args[i] = strsep(&line, " ");
  //printf("%p\n", line);
  // args[i] = 0;
  return rm_space(args);
}
