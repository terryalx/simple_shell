#include "shell.h"

/**
 * add_node - adds a new node at the beginning of a list.
 * @head: pointer to the head of the list
 * @str: string to be stored in the new node
 * @val: value to be stored in the new node
 *
 * Return: pointer to the new head of the list
 */
list_t *add_node(list_t **head, char *str, char *val)
{
	list_t *new_node;

	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->str = str_duplicate(str);
	new_node->length = _strlen(new_node->str);
	new_node->value = str_duplicate(val);
	new_node->value_length = _strlen(val);
	new_node->next_node = *head;
	*head = new_node;

	return (new_node);
}
