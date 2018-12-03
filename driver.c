
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

#include "helper.h"

static void sighandler(int signo){
   char cwd[STR_LEN];
   if(signo == SIGINT){
     getcwd(cwd, STR_LEN);
     printf("\n%s> ", cwd);
     fflush(stdout);
   }
}

int main(){
  char input[STR_LEN];
  char cwd[STR_LEN];
  char** args;
  char* piece;
  char* dummy;
  int s;

  signal(SIGINT, sighandler);
  while (1){

    getcwd(cwd, STR_LEN);
    printf("%s> ", cwd);
    scanf(" %[^\n]s", input);


    dummy = input;
    while (piece = strsep(&dummy, ";")){

      args = parse_args(piece);
      s = execute(args);
      if (s == 2)
        break;
      if (s == 1)
        return 0;
    }
  }

  return 0;
}
