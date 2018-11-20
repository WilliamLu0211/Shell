#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#include "helper.h"

int main(){
  char* input = malloc(64);
  char* cwd = malloc(256);
  char** args;
  int f, status;
  // char broke;

  while (1){

    getcwd(cwd, 256);
    printf("%s> ", cwd);
    scanf("%[^\n]s", input);
    args = parse_args( input, " " );
    // broke = 0;

    if (!strcmp(args[0], "cd"))
      chdir(args[1]);

    else{
      f = fork();
      if (!f){
        execvp(args[0], args);
      }
      else{
        wait(&status);
      }
    }
    // if (broke)
    //   break;

    // wait(&status);

    free(input);
    free(cwd);
    // free(args);
  }

  // sleep(1.5);

  return 0;
}
