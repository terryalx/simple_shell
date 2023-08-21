#include "shell.h"

/**
 * clear_terminal_screen - Clears the terminal screen
 * @params: Parameters (not used in this function).
 *
 * Clears the terminal screen by sending ANSI escape codes.
 *
 * Return: void
 */
void clear_terminal_screen(param_t *params)
{
    (void)params;
    my_printf("\033[2J\033[1;1H");
}
