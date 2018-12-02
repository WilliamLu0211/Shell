## Project 1: Shell[ing] out commands.
#### - by William Lu, Simon Tsui

1. **Features Implemented Successfully**
- Runs commands in child processes via `fork()` and `execvp()`
-  `>`, `>>`, and `<` for redirecting
- `|` for single pipe
- `;` allows multiple for multiple commands to be exeuted
- can `cd` and `exit`
- recursive redirecting limited to one or less pipe: for example, `bash < input.txt | cowsay > output.txt` works
2. **Features Implemented Unsuccessfully**
- Recursive piping: for example, `fortune | cowsay | wc` does not work.
3. **Bugs**
- After running each commands, current working directory is printed in order to best mimic bash. Therefore, if you test our shell using `./a.out < test_commands`, a number of current working directories will be printed at the end.
-

4. **Function Headers**

```
int execute(char** args);
  In most cases, the function calls my_exec() to execute the lines in the shell.
  However, with cases like cd and exit, they are called in the parent function.
  If any redirect symbol is present, corresponding redirect functions are called.

int get_length(char** args);
  After the string of text has been broken down into array of arguments, get_length counts the number of arguments there are

char** rm_space(char** args);
  Removes blank spaces in arguments.
  Returns a pointer to head.

char** parse_args(char* line);
  Takes the initial line given and breaks it up using the strsep() function.
  Splits by spaces.
  Returns a pointer to head.

void my_exec(char** args);
  fork()
  execvp() in child
  wait() in parent

void my_output(char ** args, char* file);
  Is invoked when a ">" sign is encountered in the input.
  Writes the output of the command into a file specified by the user

void my_output(char ** args, char* file);
  Is invoked when a "<" sign is encountered in the input.
  Redirects the content of the file into stdin.

void my_append(char ** args, char* file);
  Is invoked when a ">>" sign is encountered in the input.
  Runs the same way as my_output() but appends.
  
void my_pipe(char** in, char** out);
  Is invoked when a "|" sign is encountered in the input.
  Redirects stdout of in into stdin of out.
```
