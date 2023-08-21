#include "shell.h"

/**
 * add_node - Add a new node at the beginning of a list.
 *
 * This function allocates memory for a new node and adds it to the beginning
 * of a linked list. It stores the provided string and value in the new node.
 *
 * @head: Pointer to the head of the list.
 * @str: The string to be stored in the new node.
 * @val: The value to be stored in the new node.
 *
 * Return: Pointer to the new head of the list (the newly added node).
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
