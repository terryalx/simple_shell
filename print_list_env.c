#include "shell.h"

/**
 * print_list_env - prints environment variables
 * @head: pointer to the head of the environment list
 *
 * This function recursively prints the environment variables in the list.
 * Each variable is printed in the format "variable=value".
 */
void print_list_env(list_t *head)
{
	if (head)
	{
		/*print_list_env(head->next_node);*/
		if (head->str)
			_printf("%s=%s\n", head->str, head->value);
	}
}
