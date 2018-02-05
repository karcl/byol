#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
#include <editline/history.h>

#define VERSION "0.0.0.0.1"

// /* User input buffer */
// #define BUFFER_SIZE 2048
// static char input[BUFFER_SIZE];

int main(int argc, char* argv[])
{
  fprintf(stdout, "Byol Version %s\n", VERSION);
  fprintf(stdout, "Press Ctrl+d to Exit\n");

  while (1) {
    char* input = readline("byol> "); /* Show prompt and get user input */

    add_history(input); /* Remember input in history */

    fprintf(stdout, "You've entered: %s\n", input); /* Echo input back */

    if (input == NULL) { /* Terminate loop on EOF */
      break;
    }

    free(input); /* Free retrieved input */
  }

  return 0;
}
