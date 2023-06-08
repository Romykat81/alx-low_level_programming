#include "main.h"

/**
 * get_bit - returns the value of a bit
 * @num: number
 * @index: index
 *
 * Return: bit or -1
 */
int get_bit(unsigned long int num, unsigned int index)
{
	int bit;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	bit = (num >> index) & 1;

	return (bit);
}
