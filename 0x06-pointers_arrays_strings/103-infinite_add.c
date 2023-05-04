#include "main.h"
#include <stdio.h>
/**
 * infinite_add - Adds two numbers
 * @n1: first input string
 * @n2: second input string
 * @r: pointer to buffer where result is stored
 * @size_r: requested size for the buffer
 * Return: pointer to buffer where result is stored
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, op, bg, dr1, dr2, add = 0;

	while(*(n1 + i) != '\0')
		i++;
	while (*(n2 + j) != '\0')
		j++;

	if (i >= j)
		bg = i;
	else
		bg = j;

	if (size_r <= bg + 1)
		return (0);
	r[bg + 1] = '\0';
	i--, j--, size_r--;

	dr1 = *(n1 + i) - 48, dr2 = *(n2 + j) - 48;

	while (bg >= 0)
	{
		op = dr1 + dr2 + add;
		if (op >= 10)
			add = op / 10;
		else
			add = 0;
		if (op > 0)
			*(r + bg) = (op % 10) + 48;
		else
			*(r + bg) = '0';
		if (i > 0)
			i--, dr1 = *(n1 + i) - 48;
		else
			dr 1 = 0;
		if (j > 0)
			j--, dr2 = *(n2 + j) - 48;
		else
			dr2 = 0;
		bg--, size_r--;
	}
	if (*(r) == '0')
		return (r + 1);
	else
		return (r);
}
