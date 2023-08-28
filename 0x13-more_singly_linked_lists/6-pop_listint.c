#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list and returns its data
 * @head: Pointer to a pointer to the head of the list
 *
 * Return: Data of the removed head node or 0 if the list is empty
 */

int pop_listint(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return (0);
	{
		listint_t *temp = *head;
		int data =temp->n;

		*head = (*head)->next;
		free(temp);

		return (data);
	}
}

