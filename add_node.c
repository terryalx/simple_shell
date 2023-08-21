#include "shell.h"

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: start of list
 * @str: key
 * @val: value
 * Return: ptr to new head
 */

list_t *add_node(list_t **head, char *str, char *val)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = _strdup(str);
	new->len = _strlen(new->str);
	new->val = _strdup(val);
	new->val_len = _strlen(val);
	new->next = *head;
	*head = new;

	return (new);
}
