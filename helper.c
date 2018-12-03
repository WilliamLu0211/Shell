#include "helper.h"

int execute(char** args){
  if (!get_length(args)){
    printf("syntax error near unexpected token \";\"\n");
    return 2;
  }
  if(get_length(args) > 1){
    if (! strcmp(args[get_length(args)-2], ">" ) ){
      // printf("#");
      char* file = args[get_length(args)-1];
      args[get_length(args)-2] = 0;
      my_output(args, file);
      return 0;
    }
    if (! strcmp(args[get_length(args)-2], ">>") ){
      // printf("#");
      char* file = args[get_length(args)-1];
      args[get_length(args)-2] = 0;
      my_append(args, file);
      return 0;
    }
    if (! strcmp(args[get_length(args)-2], "<" ) ){
      // printf("#");
      char* file = args[get_length(args)-1];
      args[get_length(args)-2] = 0;
      my_input(args, file);
      return 0;
    }
    for (int i = get_length(args) - 1; i >= 0; i --)
      if (! strcmp(args[i], "|")){
        // printf("#");
        args[i] = NULL;
        char** out = args + i + 1;
        // printf("%s\n", out[0]);
        my_pipe(args, out);
        return 0;
      }
  }

  if ( !strcmp(args[0], "cd") )
    chdir(args[1]);

  else if ( !strcmp(args[0], "exit") )
    return 1;

  else
    my_exec(args);
  return 0;
}

int get_length(char** args){
  int length = 0;
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

void my_exec(char** args){
  int f, status;
  f = fork();
  if (!f)
    execvp(args[0], args);
  else
    wait(&status);
}

void my_output(char ** args, char* file){
  int ph = dup(STDOUT_FILENO);
  int fd = open(file, O_WRONLY | O_CREAT, 0777);
  dup2(fd, STDOUT_FILENO);
  execute(args);
  dup2(ph, STDOUT_FILENO);
  close(fd);
}

void my_append(char ** args, char* file){
  int ph = dup(STDOUT_FILENO);
  int fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0777);
  dup2(fd, STDOUT_FILENO);
  execute(args);
  dup2(ph, STDOUT_FILENO);
  close(fd);
}

void my_input(char ** args, char* file){
  int ph = dup(STDIN_FILENO);
  int fd = open(file, O_RDONLY);
  dup2(fd, STDIN_FILENO);
  execute(args);
  dup2(ph, STDIN_FILENO);
  close(fd);
}

void my_pipe(char** in, char** out){
  int fds[2];
  int ph;
  pipe(fds);

  ph = dup(STDOUT_FILENO);
  dup2(fds[1], STDOUT_FILENO);

  execute(in);
  dup2(ph, STDOUT_FILENO);
  close(fds[1]);
  ph = dup(STDIN_FILENO);
  dup2(fds[0], STDIN_FILENO);

  execute(out);
  dup2(ph, STDIN_FILENO);
}

char** parse_args(char* line){
  char** args = calloc(strlen(line), sizeof(char*));
  int i;
  for (i = 0; line; i ++)
    args[i] = strsep(&line, " \t");
  return rm_space(args);
}
