#include <stdio.h>
#include "main.h"

/**
 *_abs - write a function that computes the abs value of an int
 *
 * @n: int variable
 *return: 0
 */

int _abs(int n)
{
	if (n > 0)
	{
		return (n);
	}
	else
	{
		n *= -1;
		return (n);
	}
}
