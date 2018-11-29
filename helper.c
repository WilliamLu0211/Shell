#include "helper.h"

int execute(char* piece){
  int f, status;

  char** args = parse_args(piece);
  // for (int i = 0; args[i]; i ++)
  //   printf("[%s]\n", args[i]);
  if ( !strcmp(args[0], "cd") )
    chdir(args[1]);

  else if ( !strcmp(args[0], "exit") )
    // exit(0);
    return 1;


  else {
    f = fork();
    if (!f){
      if(get_length(args) > 1){
        // printf("%d\n", !strcmp(args[get_length(args)-2], ">>"));
        // printf("sdfawefasdg");
        // printf("%s\n", args[1]);
        // printf("%d\n", strcmp(args[1], ">"));
        if (! strcmp(args[get_length(args)-2], ">" ) ){
          // printf("#");
          my_output(args);
        }
      	if (! strcmp(args[get_length(args)-2], ">>") ){
          // printf("#");
      	  my_append(args);
      	}
        if (! strcmp(args[get_length(args)-2], "<" ) ){
          // printf("#");
          my_input(args);
        }
      }
      execvp(args[0], args);
    }
      // return 0;
    wait(&status);
  }
  free(args);
  return 0;
}

int get_length(char** args){
  int length = 0;
  //printf("|%d|\n", dummy);
  while (args[length])
    length ++;
  return length;
}

char** rm_space(char** args){
  int length = get_length(args);
  int i, j;
  for (int i = 0; i < length; i ++)
    if ( !strcmp(args[i], "") ){
      for (j = i; j < length - 1; j ++)
        args[j] = args[j + 1];
      args[j] = 0;
      length --;
      i --;
    }
  return args;
}

int my_output(char ** args){
  // int ph = dup(STDOUT_FILENO);

  int fd = open(args[get_length(args)-1], O_WRONLY | O_CREAT, 0777);
  // printf("Phase 1\n");
  // printf("STDOUT: %d\n", STDOUT_FILENO);
  // printf("fp: %d\n", fileno(fp));
  dup2(fd, STDOUT_FILENO);
  args[get_length(args)-2] = NULL;
  execvp(args[0], args);
  // printf("Phase 2\n");
  // printf("STDOUT: %d\n", placeholder);
  // printf("fp: %d\n", fileno(fp));

  // execvp(args[0], args);
  // dup2(placeholder, STDOUT_FILENO);
  // printf("Phase 3 \n");
  // printf("STDOUT: %d\n", STDOUT_FILENO);
  // printf("fp: %d\n", fileno(fp));
  // close(fd);
  return 0;
}

int my_append(char ** args){
  // int ph = dup(STDOUT_FILENO);

  int fd = open(args[get_length(args)-1], O_WRONLY | O_APPEND | O_CREAT, 0777);
  // printf("Phase 1\n");
  // printf("STDOUT: %d\n", STDOUT_FILENO);
  // printf("fd: %d\n", fd);

  dup2(fd, STDOUT_FILENO);
  // printf("%s\n", strerror(errno));
  args[get_length(args)-2] = NULL;
  // printf("%s\n", args[0]);
  execvp(args[0], args);
  // printf("Phase 2\n");
  // printf("STDOUT: %d\n", placeholder);
  // printf("fp: %d\n", fileno(fp));

  // execvp(args[0], args);
  // dup2(placeholder, STDOUT_FILENO);
  // printf("Phase 3 \n");
  // printf("STDOUT: %d\n", STDOUT_FILENO);
  // printf("fp: %d\n", fileno(fp));
  // close(fd);
  return 0;
}

int my_input(char ** args){
  // int ph = dup(STDIN_FILENO);
  // printf("%s\n", args[get_length(args)-1]);
  int fd = open(args[get_length(args)-1], O_RDONLY);
  // printf("%s\n", strerror(errno));
  char s[1024];
  char cur[256];
  dup2(fd, STDIN_FILENO);
  while( fgets(cur, 256, stdin))
    strcat(s, cur);
  // fgets(s, 256, stdin);
  // printf("%s\n", s);
  args[get_length(args) - 2] = s;
  args[get_length(args) - 1] = NULL;
  execvp(args[0], args);
  // dup2(fd, STDIN_FILENO);
  // close(fd);

}

char** parse_args(char* line){
  char** args = calloc(strlen(line), sizeof(char*));
  // printf("%ld\n", strlen(line) * sizeof(char*));
  int i;
  for (i = 0; line; i ++)
    args[i] = strsep(&line, " ");
    if (args[i] == ">"){

    }
  //printf("%p\n", line);
  // args[i] = 0;
  return rm_space(args);
}
