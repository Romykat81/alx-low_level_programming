#include "main.h"
#include <stdio.h>

/**
 * _strchr - function that locates a char in a string
 *@s: first value
 *@c: second value
 *
 *  Return: char
 */
char *_strchr(char *s, char c)
{
	if (*s == '\0')
		return (s);
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
		return (s);
	return ('\0');
}
