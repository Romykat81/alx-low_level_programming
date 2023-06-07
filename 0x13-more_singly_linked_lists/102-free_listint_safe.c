#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node
 *
 * Return: no. of elements
 */
size_t free_listint_safe(listint_t **h)
{
	size_t i = 0;
	int n;
	listint_t *tmp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		n = *h - (*h)->next;
		if (n > 0)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
			i++;
		}
		else
		{
			free(*h);
			*h = NULL;
			i++;
			break;
		}
	}
	*h = NULL;

	return (i);
}
