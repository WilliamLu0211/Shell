#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
  FILE* wc = popen("wc", "r");
  FILE* ls = popen("ls", "w");
  return 0;
}
