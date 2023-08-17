#include "shell.h"

#include <unistd.h>
#include <stdlib.h>

/**
 * handle_malloc_error - _cd helper
 */
void handle_malloc_error(void)
{
	write(STDERR_FILENO, "cd target malloc error\n", 23);
	exit(-1);
}
