#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - Allocates a 2D array of integers with specified width and height
 * @width: Number of columns
 * @height: Number of rows
 *
 * Return: Pointer to the allocated 2D array, NULL on failure or invalid input
 */
int **alloc_grid(int width, int height)
{
	int **output;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	output = malloc(sizeof(int *) * height);
	if (output == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		output[i] = malloc(sizeof(int) * width);
		if (output[i] == NULL)
		{
			/* Free previously allocated rows */
			for (j = 0; j < i; j++)
				free(output[j]);

			/* Free the array of pointers */
			free(output);
			return (NULL);
		}

		for (j = 0; j < width; j++)
			output[i][j] = 0;
	}

	return (output);
}
