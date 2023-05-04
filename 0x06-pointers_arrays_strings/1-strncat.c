#include "main.h"
#include <stdio.h>
/**
 * _strncat - concats two strings
 *
 * @dest: destination
 * @src: source string
 * @n: num of bytes
 *
 * return: pointer to the dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	i = 0;

	for (j = 0; dest[j] != '\0'; j++)
		;
	while (src[i] != '\0' && i < n)
	{
		dest[j + i] = src[i];
		i++;
	}
	return (dest);
}
