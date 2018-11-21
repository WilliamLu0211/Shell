#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

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
  //rm_space(args);
  return rm_space(args);
}



int main(){
  char line[] = "ls   -a  -l";
  char ** args = parse_args( line, " " );
  //rm_space(args);
  // execvp(args[0], args);
  for (int i = 0; i < 6; i ++)
      printf("[%s]\n", args[i]);
  return 0;
}
