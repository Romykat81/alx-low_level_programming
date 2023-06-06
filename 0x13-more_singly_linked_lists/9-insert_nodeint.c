#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a node
 * @head: head
 * @idx: index of the list
 * @n: int
 *
 * Return: the addr of node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *h = *head;

	new = malloc(sizeof(listint_t));
	if (new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (i = 0; (h != NULL) && (i < idx); i++)
	{
		if (i == idx - 1)
		{
			new->next = h->next;
			h->next = new;
			return (new);
		}
		else
			h = h->next;
	}
	return (NULL);
}
