#include<stdio.h>
#include<main.h>

/**
 *main - print first 50 numbers of the fibonacci sequence
 *
 * return: 0
 */

int main(void)
{
	unsigned long count, f, i, b;

	f = 0;
	i = 1;

	for (count = 0; count < 50; count++)
	{
		b = f + i;
		f = i;
		i = b;
		printf ("%lu", b);

		if (count == 49)
		{
			putchar('\n');
		}
		else
		{
			printf(", ");
		}
	}
	return (0);
}
