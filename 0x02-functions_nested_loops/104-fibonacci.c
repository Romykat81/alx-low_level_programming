#include <stdio.h>
#include "main.h"

/**
 *main - print the first 98 numbers of the fibonacci seq from 1
 *
 *return: 0
 */

int main(void)
{
	int count;
	unsigned long a, b, c;
	unsigned long x, y, z, next;

	count = 0;
	a = 0;
	b = 1;

	for (count = 1; count <= 91; count++)
	{
		c = a + b;
		a = b;
		b = c;
		printf("%lu, ", c);
	}
	x = a % 1000;
	a = a / 1000;
	y = b % 1000;
	b = b / 1000;

	while (count <= 98)
	{
		next = (x + y) / 1000;
		z = (x + y) - next * 1000;
		c = (a + j) + next;
		x = y;
		y = z;
		a = b;
		b = c;

		if (z >= 100)
		{
			printf("%lu%lu", c, z);
		}
		else
		{
			printf("%lu0%lu", c, z);
		}
		if (count != 98)
		{
			printf(" ,");

			count++;
		}
		putchar('\n');
		return(0);
	}
}
