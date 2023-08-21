#include "shell.h"
/**
 * _clear - clears the terminal screen
 * @params: parameters
 *
 * Return: void
 */

void _clear(param_t *params)
{
	(void)params;
	my_printf("\033[2J\033[1;1H");
}
