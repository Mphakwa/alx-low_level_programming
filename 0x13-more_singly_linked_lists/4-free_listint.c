#include "lists.h"

/**
 * free_listint - Frees a listint_t list by deallocating memory
 * @head: Pointer to the head of the list
 */

void free_listint(listint_t *head)
{
	listint_t *current = head;

	while (current != NULL)
	{
		listint_t *next_node = current->next;
		free(current);
		current = next_node;
	}
}
