#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
  int fd = open("foo", O_WR | O_CREAT, 0777);
  // printf("Phase 1\n");
  // printf("STDOUT: %d\n", STDOUT_FILENO);
  // printf("fp: %d\n", fileno(fp));
  dup2(fd, STDOUT_FILENO);
  // args[get_length(args)-2] = NULL;
  // printf("%s\n", args[0]);
  char* args[2];
  args[1] = "fortune";
  args[2] = NULL;
  execvp(args[0], args);
  return 0;
}
