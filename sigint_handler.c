#include "main.h"
#include "shell.h"
#include "list.h"
#include <unistd.h>

/**
 * sigint_handler - handle terminate signal
 * @s: signal number
 */

void sigint_handler(int __attribute__((unused)) s)
{
	write(1, "\n($) ", 5);
}
