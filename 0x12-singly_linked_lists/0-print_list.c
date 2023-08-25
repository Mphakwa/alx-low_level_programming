#include "lists.h"

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to the head of the linked list
 * Return: the number of nodes in the list
 */

size_t print_list(const list_t *h)
{
	unsigned int i = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (ni)\n");

		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}
		h = h->next;
		i++;
	}
	return (i);
}
