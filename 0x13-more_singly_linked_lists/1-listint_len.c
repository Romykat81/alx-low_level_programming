#include "lists.h"

/*
* listint_len - no. of elem in ll
* @h: head
*
* return: no. of nodes
*/
size_t listint_len(const listint_t *h)
{
    size_t node = 0;
     
    while (h != NULL)
    {
        h = h->next;
        node++;
    }
    return (node);
}