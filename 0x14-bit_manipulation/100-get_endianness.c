#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 or 1
 */
int get_endianness(void)
{
	unsigned int i;
	char *j;

	i = 1;
	j = (char *) &i;

	return ((int)*j);
}
