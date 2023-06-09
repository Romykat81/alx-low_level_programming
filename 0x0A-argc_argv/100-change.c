#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to
 * make change for an amount of money
 * @argc: number of arguments
 * @argv: an array of arguments
 *
 * Return: 0 for success
 */
int main(int argc, char *argv[])
{
	int i, j, k = 0;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	i = atoi(argv[1]);

	if (i < 0)
	{
		printf("0\n");
		return (0);
	}
	for (j = 0; j < 5 && i >= 0; j++)
	{
		while (i >= coins[j])
		{
			k++;
			i -= coins[j];
		}
	}
	printf("%d\n", k);
	return (0);
}
