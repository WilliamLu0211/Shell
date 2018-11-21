#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void rm_space(char** args){
  int length = 6;//sizeof(args) / sizeof(args[0]);
  for (int i = 0; i < length; i ++)
    if ( args[i] == 0 ){
      for (int j = i; i < length - 1; j ++)
        args[j] = args[j + 1];
      i --;
    }
}

char** parse_args(char* line, char* delim){
  char** args = calloc(16, sizeof(char*));
  int i = 0;
  while (line){
    args[i] = strsep(&line, delim);
    i ++;
  }
  args[i] = 0;
  rm_space(args);
  return args;
}



int main(){
  char line[] = "ls   -a  -l";
  char ** args = parse_args( line, " " );
  // execvp(args[0], args);
  for (int i = 0; i < 10; i ++)
      printf("[%s]\n", args[i]);
  return 0;
}
