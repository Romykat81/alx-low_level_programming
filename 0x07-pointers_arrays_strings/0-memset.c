#include "main.h"
#include <stdio.h>

/**
 * _memset - funcion that fills memory with a constant byte
 * @s: first value
 * @b: second value
 * @n: third value 
 *
 * return: char
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
