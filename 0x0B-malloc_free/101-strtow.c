#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * wordcount - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int wordcount(char *s)
{
	int f, c, w;

	f = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			f = 0;
		else if (f == 0)
		{
			f = 1;
			w++;
		}
	}
	return (w);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **m, *t;
	int i, k = 0, l = 0, w, c = 0, st, e;

	while (*(str + l))
		l++;
	w = wordcount(str);
	if (w == 0)
		return (NULL);

	m = (char **)malloc(sizeof(char *) * (w + 1));
		if (m == NULL)
			return (NULL);

	for (i = 0; i <= l; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				e = i;
				t = (char *)malloc(sizeof(char) * (c + 1));
				if (t == NULL)
					return (NULL);
				while (st < e)
					*t++ = str[st++];
				*t = '\0';
				m[k] = t - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			st = i;
	}
	m[k] = NULL;
	return (m);
}
