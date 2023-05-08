#include "main.h"
#include <stdio.h>

/**
 * _strstr - function that locates a substring.
 *@haystack: first value
 *@needle: second value
 *
 * Return: char with result
 */
char *_strstr(char *haystack, char *needle)
{
	int count = 0;
	int a = 0, j = 0, i = 0;
	int l, k;
	char *p;

	while (needle[count] != '\0')
	{
		count++;
	}
	while (haystack[i] != '\0')
	{
		i++;
	}
	if (count == 0)
		return (haystack);
	while (haystack[j] != '\0')
	{
		if (haystack[j] == needle[0])
		{
			p = &haystack[j];
			l = j;
			a = 0;

			for (k = 0; k < count; k++)
			{
				if (haystack[l] == needle[k])
					a++;
				l++;
			}
		}
		if (a == count)
		{
			return (p);
			j++;
		}
	}
	return ('\0');
}
