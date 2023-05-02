#include "main.h"
#include "2-strlen.c" 
/**
 * print_array - prints array
 * @a: pointer
 * @n: how many times 
 */
void print array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i != n - 1)
			printf(", ");
	}
	printf("\n");
}
