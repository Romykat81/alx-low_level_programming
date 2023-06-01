#include "main.h"
/*
* list_len - returns length of elements in a list
* @h: singly linked list
* return: no. of elements
*/
size_t list_len(const list_t *h)
{
    size_t e;

    e = 0;
    while (h != NULL)
    {
        h = h->next;
        e++;
    }
    return (e);
}