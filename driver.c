
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#include "helper.h"

int main(){
  char* input;
  char* cwd;
  // char** args;
  char* piece;
  // int f, status;
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

    while (piece = strsep(&input, ";")){
    // printf("%s", args[0]);

        // }
      if (execute(piece))
        return 0;
    }
    // if (broke)
    //   break;

    // wait(&status);

    // break;
    free(input);
    free(cwd);
    free(piece);
    // free(args);
  }

  // sleep(1.5);

return 0;
}
