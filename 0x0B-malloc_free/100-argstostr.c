#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * argstostr - concatenates all arguments of program.
 * @ac: argument count
 * @av: pointer to argument vectors
 * Return: pointer to new buffer with all arguments as 1 string.
 */
char *argstostr(int ac, char **av)
{
	int i, j, k, buff;
	char *p;

	if (ac == 0)
		return (NULL);
	if (av == NULL)
		return (NULL);

	i = j = k = buff = 0;
	for (i = 0; av[i]; i++)
	{
		for (j = 0; av[i][j]; j++)
			k++;
	}
	p = (char *)malloc(k * sizeof(char) + ac + 1);
	if (p == NULL)
		return (NULL);
	for (i = 0; av[i]; i++)
	{
		for (j = 0; av[i][j]; j++, buff++)
			p[buff] = av[i][j];
		p[buff] = '\n';
		buff++;
	}
	p[buff] = '\0';
	return (p);
}
