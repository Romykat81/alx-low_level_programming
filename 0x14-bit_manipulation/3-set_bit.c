#include "main.h"

/**
* set_bit - sets a specific bit at spec pos
* @num: ptr to bit
* @index: index 
* return: 1 or -1
*/
int set_bit(unsigned long int *num, unsigned int index)
{
	unsigned long int i = 1;
	
	if (index > sizeof(unsigned long int) * 8 - 1))
		return (-1);
	
	i <<= index;
	*num = *num | i;
	return (1);
}
