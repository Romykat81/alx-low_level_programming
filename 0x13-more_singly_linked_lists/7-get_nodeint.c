#include "lists.h"

/*
* get_nodeint_at_index - returns node of ll
* @head: head
* @index: indx of node
* return: nth node or null
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int i;

    for (i = 0; i < index && head != NULL; i++)
    {
        head = head->next;
    }
    return (head);
}