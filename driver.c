
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

  while (1){

    getcwd(cwd, STR_LEN);
    printf("%s> ", cwd);
    scanf(" %[^\n]s", input);

    dummy = input;
    while (piece = strsep(&dummy, ";")){

      args = parse_args(piece);
      if (execute(args))
        return 0;
    }
  }

  return 0;
}
