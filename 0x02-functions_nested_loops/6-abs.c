#include <stdio.h>
#include <main.h>

/**
 *main - write a function that computes the abs value of an int
 *
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
