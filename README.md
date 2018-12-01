## Project 1: Shell[ing] out commands.
#### - by William Lu, Simon Tsui

1. **Features Implemented Successfully**
- Runs commands in child processes via forking.
- >, >>, and < for redirecting.
- | for piping
- ; allows multiple for multiple commands to be exeuted
- directory can be changed
- Can pipe into wc function
2. **Features Implemented Unsuccessfully**
-
-
-
3. **Bugs**
-
-

4. **Function Headers**

```
int execute(char* piece);
  in most cases, the function forks and then calls execvp() to execute the lines in the shell.
  However, with cases like cd and exit, they are called in the parent function

int get_length(char** args);
  After the string of text has been broken down to its respective arguments, get_length counts the number of arguments there are

char** rm_space(char** args);
  removes blank spaces in arguments

char** parse_args(char* line);
  Takes the initial line given and breaks it up using the strsep() function. Splits by spaces


int my_input(char ** args);
  Is invoked when a ">" sign is encountered in the input. Writes the output of the command into a file specified by the user

int my_output(char ** args);
  Is invoked when a "<" sign is encountered in the input. Runs the file specified by the user containing various command line prompts.

int my_append(char ** args);
  Is invoked when a ">>" sign is encountered in the input. Appends the output of the command into a target file
```
