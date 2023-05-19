#include "main.h"
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array of a certain number of elements
 * @nmem: The number of elements.
 * @size: The byte size of each array element.
 *
 * Return: pointer to the memory
 */
void *_calloc(unsigned int nmem, unsigned int size)
{
	void *mem;
	char *fill;
	unsigned int i;

	if (nmem == 0 || size == 0)
		return (NULL);

	mem = malloc(size * nmem);

	if (mem == NULL)
		return (NULL);

	fill = mem;

	for (i = 0; i < (size * nmem); i++)
		fill[i] = '\0';
	return (mem);
}
