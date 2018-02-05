#include <stdio.h>

#define VERSION "0.0.0.0.1"

/* User input buffer */
#define BUFFER_SIZE 2048
static char input[BUFFER_SIZE];

int main(int argc, char* argv[])
{
  fprintf(stdout, "Byol Version %s\n", VERSION);
  fprintf(stdout, "Press Ctrl+d to Exit\n");

  while (1) {
    fprintf(stdout, "byol> "); /* Show prompt */

    fgets(input, BUFFER_SIZE, stdin); /* Get user input */

    fprintf(stdout, "You've entered: %s", input); /* Echo input back */

    if (feof(stdin)) { /* Terminate loop on EOF */
      break;
    }
  }

  return 0;
}
