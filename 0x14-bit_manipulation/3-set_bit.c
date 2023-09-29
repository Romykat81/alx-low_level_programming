#include "main.h"

/**
 * set_bit - sets the value of a bit to 1
 * @n: ptr to unsigned long int
 * @index: index of bit
 *
 * return: 1 or -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int j;

	if (index > 63)
		return (-1);

	j = 1 << index;
	*n = (*n | j);

	return (1);
}
