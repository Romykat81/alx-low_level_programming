#include "lists.h"

/*
* print_listint - prints all elements
* @h: head
*
* return: no. of nodes
*/
size_t print_listint(const listint_t *h)
{
	size_t node = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		node++;
	}
	return (node);
}
