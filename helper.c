#include "helper.h"

int execute(char** args){
  int f, status;
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
        for (int i = get_length(args) - 1; i >= 0; i --)
          if (! strcmp(args[i], "|")){
            // printf("#");
            args[i] = NULL;
            char** out = args + i + 1;
            // printf("%s\n", out[0]);
            my_pipe(args, out);
          }
      }
      // printf("#");
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

  int fd = open(args[get_length(args)-1], O_WRONLY | O_CREAT, 0777);
  dup2(fd, STDOUT_FILENO);
  args[get_length(args)-2] = NULL;
  execvp(args[0], args);

  return 0;
}

int my_append(char ** args){

  int fd = open(args[get_length(args)-1], O_WRONLY | O_APPEND | O_CREAT, 0777);


  dup2(fd, STDOUT_FILENO);

  args[get_length(args)-2] = NULL;

  execvp(args[0], args);

  return 0;
}

int my_input(char ** args){

  int fd = open(args[get_length(args)-1], O_RDONLY);
  char s[1024];
  char cur[256];
  dup2(fd, STDIN_FILENO);
  while( fgets(cur, 256, stdin))
    strcat(s, cur);

  args[get_length(args) - 2] = s;
  args[get_length(args) - 1] = NULL;
  execvp(args[0], args);

}

int my_pipe(char** args, char** out){
  int fds[2];
  pipe(fds);
  int f = fork();
  if (!f){
    // close(fd[1]);
    // printf("#");
    dup2(fds[1], STDOUT_FILENO);
    execvp(args[0], args);
    //execute(args);
    // write(fds[1], "lmfao", 7);
  } else {
    // dup2(fds[0], STDIN_FILENO);
    char s[1024];
    // char cur[256];
    // dup2(fd, STDIN_FILENO);
    // while( fgets(cur, 256, stdin)){
    //   strcat(s, cur);
    //   // strcat(s, "\n");
    // }
    //
    // while(scanf(" %[^\n]s", cur) != EOF){
    //   strcat(s, cur);
    // }
    dup2(fds[0], STDIN_FILENO);
    int size = read(STDIN_FILENO, s, sizeof(s));
    //s[size] = 0;
    // fgets(s, 1024, stdin);
    // printf("[%s]\n", s);
    //int i;
    //for (i = 0; out[i]; i ++);
    //out[i] = s;
    printf("%s\n", s);
    execvp(out[0], out);
    // popen(out[0], "r");
    // read(fds[0], s, 7);
    // printf("%s\n", s);
  }
}

char** parse_args(char* line){
  char** args = calloc(strlen(line), sizeof(char*));
  // printf("%ld\n", strlen(line) * sizeof(char*));
  int i;
  for (i = 0; line; i ++)
    args[i] = strsep(&line, " ");
  //printf("%p\n", line);
  // args[i] = 0;
  return rm_space(args);
}
