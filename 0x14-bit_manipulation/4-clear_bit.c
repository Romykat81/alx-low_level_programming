#include "main.h"

/**
 * clear_bit - set opp bit
 * @num: no. to set
 * @index: pos
 * Return: 1 or -1
 */
int clear_bit(unsigned long int *num, unsigned int index)
{
	unsigned long int i;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	i <<= index;
	*num &= ~i;

	return (1);
}
