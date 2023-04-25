#include <stdio.h>
#include <main.h>

/**
 *main-print all numbers from n to 98 followed by a new line
 *
 *return:0
 */

void print_to_98(int n)
{
	if (n < 98)
	{
		for (n = n; n < 98; n++)
		{
			printf("%d, ", n);
			printf("%d\n", 98);
		}
		else
		{
			for (n = n; n > 98; n--)
			{
				printf("%d, ", n);
				printf("%d\n", 98);
			}
		}
	}
	return (0);
}
