#include "lists.h"

/*
* add_nodeint_end - add node at end
* @head: head of ll
* @n: new element
* return: addr of new elem
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new;
    listint_t *t;

    (void)t;

    new = malloc(sizeof(listint_t));

    if (new == NULL)
        return (NULL);

        new->n = n;
        new->next = NULL;
        t = *head;
        if (*head == NULL)
        {
            *head = new;
        }
        else
        {
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = new;
        }
        return (*head);
}