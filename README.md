## Project 1: Shell[ing] out commands.
#### - by William Lu, Simon Tsui

1. **Features Implemented Successfully**
- Runs commands in child processes via `fork()` and `execvp()`
-  `>`, `>>`, and `<` for redirecting
- `|` for single pipe
- `;` allows multiple for multiple commands to be exeuted
- Allows multiple spaces between arguments
- Can `cd` and `exit`
- Recursive redirects, but limited to one or less pipe: even `bash < input.txt | cowsay > output.txt` works, WOW!
- If there is no command before ";", the shell does not crash. It prints an error statement instead.
- Ctrl + C interrupt does not exit the shell. This is similar to how Ctrl + C does not exit the bash.
- Whenever a command fails to execute, a string of errno is printed.
2. **Features Implemented Unsuccessfully**
- Recursive pipes: for example, `fortune | cowsay | wc` does not work.
3. **Bugs**
- After running each commands, current working directory is printed in order to best mimic bash. Therefore, if you test our shell using `make run < test_commands`, a number of current working directories will be printed at the end.
- Pressing tab while typing commands does not auto complete. Instead, a tab is taken as a delimiter (same as space) in `parse_args()`.
- Pressing up arrow key does not copy the previous command.
4. **Function Headers**

```
int execute(char** args);
  In most cases, the function calls my_exec() to execute the lines in the shell.
  However, with cases like cd and exit, they are called in the parent function.
  If any redirect symbol is present, corresponding redirect functions are called.
  returns specific numbers or errno.

int get_length(char** args);
  After the string of text has been broken down into array of arguments, get_length counts the number of arguments there are

char** rm_space(char** args);
  Removes blank spaces in arguments.
  Returns a pointer to head.

char** parse_args(char* line);
  Takes the initial line given and breaks it up using the strsep() function.
  Splits by spaces and tabs.
  Returns a pointer to head.

int my_exec(char** args);
  fork()
  execvp() in child
  wait() in parent
  returns either 0 or errno

int my_output(char ** args, char* file);
  Is invoked when a ">" sign is encountered in the input.
  Writes the output of the command into a file specified by the user
  returns what execute() returns

int my_output(char ** args, char* file);
  Is invoked when a "<" sign is encountered in the input.
  Redirects the content of the file into stdin.
  returns what execute() returns

int my_append(char ** args, char* file);
  Is invoked when a ">>" sign is encountered in the input.
  Runs the same way as my_output() but appends.
  returns what execute() returns

int my_pipe(char** in, char** out);
  Is invoked when a "|" sign is encountered in the input.
  Redirects stdout of in into stdin of out.
  returns what execute() returns
```
