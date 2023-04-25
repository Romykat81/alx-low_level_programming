#include <stdio.h>
#include "main.h"

/**
 *_isalpha -write a function that checks or alphabetic character
 *@c: declaration variable
 *Return - 1 or 0
 */

int _isalpha(int c)
{
	if (c >= 65 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
