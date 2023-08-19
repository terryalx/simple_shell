#include "shell.h"

/**
 * print_list_env - prins environment variables
 * @head: pointer -> head of the environment list
*/

void print_list_env(list_t *head)
{
	if (head)
	{
		print_list_env(head->next);
		if (head->str)
			_printf("%s=%s\n", head->str, head->val);
	}
}
