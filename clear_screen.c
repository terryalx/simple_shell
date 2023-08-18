#include "shell.h"

/**
 * clear_screen - Clears the terminal screen
 * @params: Unused parameter
 *
 * Return: void
 */
void clear_screen(param_t *params)
{
	(void)params;
	_printf("\033[2J\033[1;1H");
}
