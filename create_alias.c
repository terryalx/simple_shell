#include "shell.h"

/**
 * create_alias - Create a new alias and add it to the alias list.
 * @name: Name of the new alias.
 * @value: Value of the new alias.
 * @params: Pointer to the parameter structure.
 *
 * This function creates a new alias with the given name
 * and value and adds it to the alias list. If an alias
 * with the same name already exists, the value is updated.
 */
void create_alias(char *name, char *value, param_t *params)
{
	list_t *head = params->alias_head;

	while (head)
	{
		if (!string_compare(name, head->str))
		{
			free(head->value);
			head->value = value;
			head->value_length = _strlen(value);
			params->status = 0;
			return;
		}
		head = head->next_node;
	}

	params->alias_head = prepend_list_node(&
			(params->alias_head), name, value);
	free(value);
	params->status = 0;
}
