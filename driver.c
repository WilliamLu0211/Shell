
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#include "helper.h"

int main(){
  char input[STR_LEN];
  char cwd[STR_LEN];
  char** args;
  char* piece;
  char* dummy;
  // int f, status;
  // char broke;

  while (1){

    // input = malloc(STR_LEN);
    // cwd = malloc(STR_LEN);
    // piece = malloc(256);

    getcwd(cwd, STR_LEN);
    printf("%s> ", cwd);
    // fflush(stdin);
    scanf(" %[^\n]s", input);
    // printf("input: %p", input);
    // args = parse_args( input, " " );
    // broke = 0;

    dummy = input;
    while (piece = strsep(&dummy, ";")){
    // printf("%s", args[0]);
      // printf("[%s]\n", piece);
      // printf("[%s]\n", dummy);
      // printf("[%s]\n", input);
        // }
      args = parse_args(piece);
      if (execute(args))
        return 0;
      // free(piece);
    }
    // if (broke)
    //   break;

    // wait(&status);

    // break;
    // free(input);
    // free(cwd);
    // free(piece);
    // free(args);
  }

  // sleep(1.5);

  return 0;
}
