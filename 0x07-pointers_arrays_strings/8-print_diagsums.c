#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - function that prints sum of two diagonals
 *@a: first value
 *@size: second value
 */
void print_diagsums(int *a, int size)
{
	int i, j, k;
	int sum = 0, sum2 = 0, l = 0;

	k = size - 1;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == j)
				sum += a[l];
			if (j == k)
				sum2 += a[l];
			l++;
		}
		k--;
	}
	printf("%i, %i\n", sum, sum2);
}
