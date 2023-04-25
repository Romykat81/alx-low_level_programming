#include <stdio.h>
#include "main.h"

/**
 *_islower - write a function that checks for lowercase character
 *@c: character to compare
 *Return: 1 or 0
 */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
