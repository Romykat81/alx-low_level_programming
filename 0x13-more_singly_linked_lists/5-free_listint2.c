#include "lists.h"

/**
* free_listint2 - free ll
* @head: head
* return: nothing
*/
void free_listint2(listint_t **head)
{
	listint_t *t;
	listint_t *i;

	if (head != NULL)
	{
		i = *head;
	while ((t = i) != NULL)
	{
		i = i->next;
		free(t);
	}
		*head = NULL;
	}
}
