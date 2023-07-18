#include "main.h"

/**
 * print_number - prints a number with proper formatting
 * @number: the number to print
 */
void print_number(int number)
{
	if (number < 10)
	{
		_putchar(',');
		_putchar(' ');
		_putchar(' ');
		_putchar(' ');
		_putchar(number + '0');
	}
	else if (number >= 10 && number < 100)
	{
		_putchar(',');
		_putchar(' ');
		_putchar(' ');
		_putchar((number / 10) + '0');
		_putchar((number % 10) + '0');
	}
	else if (number >= 100)
	{
		_putchar(',');
		_putchar(' ');
		_putchar((number / 100) + '0');
		_putchar(((number / 10) % 10) + '0');
		_putchar((number % 10) + '0');
	}
}

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: number of the times table
 */
void print_times_table(int n)
{
	int i, j, k;

	if (n >= 0 && n <= 15)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				k = j * i;
				if (j == 0)
				{
					_putchar(k + '0');
				}
				else
				{
					print_number(k);
				}
			}
			_putchar('\n');
		}
	}
}

