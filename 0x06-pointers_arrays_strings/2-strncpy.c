#include "main.h"
#include <stdio.h>

/**
 * _strncpy - copies a string 
 * @dest: destination of pointer
 * @src: source of the pointer
 * @n: number of bytes
 * Return: pointer to destination
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; src[i] != '\0'' && i < n; i++)
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
