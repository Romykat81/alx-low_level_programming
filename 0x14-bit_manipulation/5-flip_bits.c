#include "main.h"

/**
 * flip_bits - returns no. of bits you would need
 * to flip to get from one to another
 * @n: first no.
 * @m: second no.
 *
 * return: no. of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int nbits;

	for (n bits = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			nbits++;
	}

	return (nbits);
}
