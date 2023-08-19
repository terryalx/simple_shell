#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * handle_malloc_error - Helper function to handle malloc errors
 *
 * This function is responsible for handling malloc errors that may occur
 * during the execution of the program. It prints an error message to stderr
 * and exits the program with a failure status.
 */
void handle_malloc_error(void)
{
	write(STDERR_FILENO, "cd target malloc error\n", 23);
	exit(-1); /* exit(EXIT_FAILURE); */
}
