#include "lists.h"

/**
* free_listint - frees a linked list
* @head: head
* return: nothing
*/
void free_listint(listint_t *head)
{
	listint_t *t;

	while ((t = head) != NULL)
	{
		head = head->next;
		free(t);
	}
}
