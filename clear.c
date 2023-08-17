#include "shell.h"

/**
 * _clear - clear terminal screen
 * @params: parameters
 * Return: void
 */
void _clear(param_t *params)
{
	(void)params;
	_printf("\033[2J\033[1;1H");
}
