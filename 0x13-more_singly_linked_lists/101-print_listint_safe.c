#include "lists.h"

/*
* free-listp - free ll
* @head: head
* return: nothing
*/
void free_listp(listp_t **head)
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

/*
* print_listint_safe - print ll
* @head: head
* return: no. of nodes
*/
size_t print_listint_safe(const listint_t *head)
{
	size_t node = 0;
	listp_t *ptr; *n, *add;

	ptr = NULL;
	while (head != NULL)
	{
		new = malloc(sizeof(listp_t));

	if (n == NULL)
		exit(98);

	n->p = (void *)head;
	n->next =ptr;
	ptr = n;

	add = ptr;

	while (add->next != NULL)
	{
		add = add->next;
		if (head == add->p)
		{
			printf("->[%p] %d\n", (void *)head, head->n);
			free_listp(&ptr);
			return (node);
		}
	}
	printf("[%p] %d\n", (void *)head, head->n);
	head = head->next;
	node++;
	}
	free_listp(&ptr);
	return (node);
}
