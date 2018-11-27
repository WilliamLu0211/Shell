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
    if (!f)
      if(get_length(args) > 1){
        // printf("%s\n", args[1]);
        // printf("%d\n", strcmp(args[1], ">"));
        if (! strcmp(args[1], ">" ) ){
          my_input(args);
        }
        if (! strcmp(args[1], "<" ) ){
          my_output(args);
        }
        else{
          execvp(args[0], args);
        }
      }
      else{
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

int my_input(char ** args){
  int placeholder = dup(STDOUT_FILENO);
  FILE * fp;
  fp = fopen(args[2], "w");
  // printf("Phase 1\n");
  // printf("STDOUT: %d\n", STDOUT_FILENO);
  // printf("fp: %d\n", fileno(fp));
  dup2(fileno(fp), STDOUT_FILENO);
  args[1] = NULL;
  execvp(args[0], args);
  // printf("Phase 2\n");
  // printf("STDOUT: %d\n", placeholder);
  // printf("fp: %d\n", fileno(fp));

  // execvp(args[0], args);
  dup2(placeholder, STDOUT_FILENO);
  // printf("Phase 3 \n");
  // printf("STDOUT: %d\n", STDOUT_FILENO);
  // printf("fp: %d\n", fileno(fp));
  fclose(fp);
  return 0;
}

int my_output(char ** args){
  int placeholder = dup(STDIN_FILENO);
  FILE * fp;
  fp = fopen(args[2], "r");

}

char** parse_args(char* line){
  char** args = calloc(strlen(line), sizeof(char*)); // error aborted
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
