
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#include "helper.h"

int main(){
  char* input;
  char* cwd;
  char** args;
  char* piece;
  int f, status;
  // char broke;

  while (1){

    input = malloc(256);
    cwd = malloc(256);
    piece = malloc(256);

    getcwd(cwd, 256);
    printf("%s> ", cwd);
    // fflush(stdin);
    scanf(" %[^\n]s", input);
    // printf("input: %p", input);
    // args = parse_args( input, " " );
    // broke = 0;

    while(piece = strsep(&input, ";")){
    // printf("%s", args[0]);
      args = parse_args(piece, " ");
      if (!strcmp(args[0], "cd"))
        chdir(args[1]);

      else{
        f = fork();
        if (!f)
          execvp(args[0], args);
          // return 0;
        // else{
        wait(&status);
        // }
      }
    }
    // if (broke)
    //   break;

    // wait(&status);

    // break;
    free(input);
    free(cwd);
    // free(args);
  }

  // sleep(1.5);

return 0;
}
