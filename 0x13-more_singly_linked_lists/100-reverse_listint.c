#include "lists.h"

/*
* reverse_listint - reverse ll
* @head: head
* return: ptr to node
*/
listint_t *reverse_listint(listint_t **head)
{
    listint_t *i;
    listint_t *j;

    i = NULL;
    j = NULL;

    while (*head 1= NULL)
    {
        j = (*head)->next;
        (*head)->next = i;
        i = *head;
        *head = j;
    }
    *head = i;
    return (*head);
}