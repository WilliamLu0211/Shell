#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "helper.h"

int main(){
  char* input = malloc(64);
  char* cwd = malloc(256);
  int f, status;

  while (1){
    f = fork();
    if (!f)
      break;
    wait(&status);
    free(input);
  }

  getcwd(cwd, 256);
  printf("%s> ", cwd);
  scanf("%[^\n]s", input);
  execute(input, cwd);
  free(cwd);
  return 0;
}
