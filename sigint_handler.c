#include "shell.h"

/**
 * sigint_handler - Handle the terminate signal
 * @s: Signal number
 *
 * Description:
 *     This function is responsible for handling the terminate signal.
 *     It writes the prompt string to the standard output and waits for the user input.
 *
 * Parameters:
 *     s: The signal number (unused)
 *
 * Return:
 *     None
 */
void sigint_handler(int __attribute__((unused)) s)
{
	char prompt[] = "\n($) ";
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}
