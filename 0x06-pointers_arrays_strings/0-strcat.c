#include "main.h"
#include <stdio.h>
/**
 * _strcat - concats 2 arrays
 *
 * @dest: destination
 * @src: source
 *
 * Return: char
 */
char *strcat(char *dest, char *src)
{
	int i, j;

	for (j = 0; dest[j] != '\0'; j++)
	{
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[j + i] = src[i];

	}
	dest[j + i] = '\0';

	return (dest);
}
