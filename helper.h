#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

#define STR_LEN 256

int execute(char** args);
/* Description: Execute is the main function.  in most cases, the function forks and then calls execvp() to execute the lines inputed into the shell.
   However, with cases like cd and exit, they are called in the parent process.
   Input: Pointer to a string, coming from the command input
   Output: Executes result of the process in terminal, returns 0
*/


char** parse_args(char* line);
/* Description: Turns the user input's string into an array of distinct terminal commands. Splits string using strsep() by " ", space keys.
   Excess spaces are removed by invoking the rm_space function
   Input: A string, the same string as execute function's input.
   Output: Returns an array of terminal commands post space char removal.
*/


char** rm_space(char** args);
/* Description: Iterates through the args array to remove space characters from each of the array indices.
   Input: Array args, containing the terminal commands
   Output: Input array but with spaces removed
*/

int get_length(char** args);
/* Description: get_length iterates throught the args array. It finds the number of string pointers in the args array.
   Input: Array of pointers to strings. The strings contain phrases from the command line input
   Output: returns an integer which is the length of the array.
*/

int my_exec(char** args);
/* Description: Forks, executes command in child process, parent waits
   Input: command line arguments
   Output: Returns executued command args
*/

int my_input(char ** args, char* file);
/* Description: Swaps file descriptors of a given file and STDIN.
   Redirects STDIN to take the file's contents as execute input.
   Input: Array of terminal commands
   Output: Reads from and runs the contents of a given file. Processes executed in terminal
*/



int my_output(char ** args, char* file);
/* Description: Swaps the file descriptors of a given file and STDOUT.
   Results of commands executed in the terminal are written into a file instead of being displayed in terminal
   File will be overwritten
   Input: Array of terminal commands
   Output: A file whose contents contain the executed commands of args.
*/

int my_append(char ** args, char* file);
/* Description: Executes the command line arguments and stores these values in a file.
   Does NOT overwrite file, appends the results to the back of the file.
   Input: terminal commands, and file location to input into
   Output: File's contents have been enlargened
*/

int my_pipe(char ** in, char ** out);
/* Description: Makes STDOUT of one file command go into the STDIN of another file command.
   Results of the original command are inputted into the second file command.
   Input: command being inputted, command receiving the input
   Output: The IN command is processed by the OUT command.
*/
