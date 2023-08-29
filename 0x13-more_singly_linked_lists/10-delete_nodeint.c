#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index
 * * @head: Pointer to a pointer to the head of the list
 * @index: Index of the node that should be deleted(starting at 0)
 *
 * Return: 1if succeeded, -1 if failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current = *head;
	listint_t *previous = NULL;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		listint_t *temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	for (i = 0; i < index && current != NULL; i++)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
		return (-1);

	previous->next = current->next;
	free(current);

	return (1);
}
