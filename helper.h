#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

#define STR_LEN 256

int execute(char* piece);
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
/* Description
*/

int get_length(char** args);
/* Description: get_length iterates throught the args array. It finds the number of string pointers in the args array. 
   Input: Array of pointers to strings. Each string originally came from
   Output: returns an integer which is the length of the array.
*/

int my_input(char ** args);

int my_output(char ** args);

int my_append(char ** args);
