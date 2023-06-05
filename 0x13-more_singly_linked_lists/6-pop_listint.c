#include "lists.h"

/*
* pop_listint - deletes node head
* @head: head
* return: head node
*/
int pop_listint(listint_t **head)
{
    int node;
    listint_t *h;
    listint_t *i;

    if (*head == NULL)
        return (0);

    i = *head;

    node = i->n;

    h = i->next;

    free(i);

    *head = h;

    return (node);
}