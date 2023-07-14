#include <stdio.h>

/**
 * main - Prints all possible combinations of two two-digit numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j;

	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (i < j)
			{
				putchar((i / 10) + '0'); /* Prints tens digit of i */
				putchar((i % 10) + '0'); /* Prints ones digit of i */
				putchar(' ');
				putchar((j / 10) + '0'); /* Prints tens digit of j */
				putchar((j % 10) + '0'); /* Prints ones digit of j */
				if (i != 98 || j != 99)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
