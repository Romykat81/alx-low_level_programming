#include "lists.h"

/**
 * free_listp2 - frees a linked list
 * @head: head of a list.
 *
 * Return: no return.
 */
void free_listp2(listp_t **head)
{
	listp_t *tmp;
	listp_t *n;

	if (head != NULL)
	{
		n = *head;
	while ((tmp = n) != NULL)
	{
		n = n->next;
		free(tmp);
	}
		*head = NULL;
	}
}

/**
 * free_listint_safe - frees a linked list.
 * @h: head of a list.
 *
 * Return: size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t node = 0;
	listpt_t *ptr, *n, *add;
	listint_t *i;

	ptr = NULL;
	while (*h != NULL)
	{
		n = malloc(sizeof(listp_t));

		if (n = NULL)
			exit (98);

		n->p = (void *)*h;
		n->next = ptr;
		ptr = n;

		add = ptr;

		while (add->next != NULL)
		{
			add = add->next;
			if (*h == add->p)
			{
				*h = NULL;
				free_listp2(&ptr);
				return (node);
			}
		}

		i = *h;
		*h = (*h)->next;
		free(i);
		node++;
	}

	*h = NULL;
	free_listp2(&ptr);
	return (node);
}
