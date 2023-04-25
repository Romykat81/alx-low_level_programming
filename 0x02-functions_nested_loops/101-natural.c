#include <stdio.h>
#include <main.h>

/**
 *main - compute the sum of all multiples of 3 or 5 below 1024
 *
 *return:0
 */
int main(void)
{
	int a, b;

	for(a = 0; a < 1024; a++)
	{
		if (a % 3 == 0 || a % 5 == 0)
		{
			b += a;
		}
		printf("%d\n", b);
		return (0);
	}
}
