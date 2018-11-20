#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "helper.h"

int main(){
  int f, status;
  char* input = malloc(64);
  while (1){
    f = fork();
    if (!f)
      break;
    wait(&status);
    free(input);
  }
  scanf("%[^\n]s", input);
  char ** args = parse_args( input );
  execvp(args[0], args);
  return 0;
}
