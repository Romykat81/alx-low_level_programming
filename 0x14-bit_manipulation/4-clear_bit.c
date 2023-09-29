#include "main.h"

/**
 * clear_bit - sets value of bit to 0.
 *
 * @n: ptr to unsigned long int
 * @index: index of bit
 *
 * return 1 or -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int j;

	if (index > 63)
		return (-1);

	j = 1 << index;

	if (*n & j)
		*n ^= j;

	return (1);
}
