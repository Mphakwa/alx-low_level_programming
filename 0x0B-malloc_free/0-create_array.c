#include <stdlib.h>
#include "main.h"

/**
 * create_array - creates array
 * @size: size of array
 * @c: character to store in arrays
 * Return: pointer to the array, or NULL if size is 0 or if malloc fails
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *arr;

	if (size == 0)
		return (NULL);

	arr = malloc(sizeof(char) * size);

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = c;

	return (arr);
}
