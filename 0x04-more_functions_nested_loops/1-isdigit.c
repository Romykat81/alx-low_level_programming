#include "main.h"
#include <stdio.h>

/**
 * _isdigit - determine if digit
 *
 * @c: character to determine
 *
 * Return: 1 or 0
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
