#include "main.h"
#include <stdio.h>

/**
 * print_times_table - prints the times table for n.
 * @n: The multiplication table requested.
 * Return: Nothing.
 */
void print_times_table(int n)
{
	int a, b, re;

	if (!(n > 15 || n < 0))
	{
		for (a = 0; a <= n; a++)
		{
			for (b = 0; b <= n; b++)
			{
				re = (a * b);
				if (b != 0)
				{
					_putchar(',');
					_putchar(' ');
				}
				if (re < 10 && b != 0)
				{
					_putchar(' ');
					_putchar(' ');
					_putchar((re % 10) + '0');
				}
				else if (re >= 10 && re < 100)
				{
					_putchar(' ');
					_putchar((re / 10) + '0');
					_putchar((re % 10) + '0');
				}
				else if (re >= 100 && b != 0)
				{
					_putchar((re / 100) + '0');
					_putchar((re / 10) % 10 + '0');
					_putchar((re % 10) + '0');
				}
				else
					_putchar((re % 10) + '0');
			}
			_putchar('\n');
		}
	}
}
