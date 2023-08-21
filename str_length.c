#include "shell.h"

/**
 * str_length - This function calculates the length of a string, excluding the null terminator.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
void str_length(param_t *params)
{
	char *name = params->args[1];
	list_t *prev = NULL, *h = params->env_head;

	if (params->tokCount != 2)
	{
		params->status = 0;
		return;
	}
	while (h)
	{
		if (string_compare(name, h->str) == 0)
		{
			if (h == params->env_head)
				params->env_head = h->next_node;
			else
				prev->next_node = h->next_node;
			free(h->str);
			free(h->value);
			free(h);
			params->status = 0;
			return;
		}
		prev = h;
		h = h->next_node;
	}
	params->status = 0;
}
